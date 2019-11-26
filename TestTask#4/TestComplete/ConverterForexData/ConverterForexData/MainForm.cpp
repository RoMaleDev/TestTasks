#include "MainForm.h"
#include "ForexData.h"

using namespace ConverterForexData;
using namespace System::Data::Common;
using namespace System::IO;

void MarshalString(System::String^ s, std::string& os) {
	using namespace Runtime::InteropServices;
	const char* chars =
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
}

Void MainForm::checkStateconvertDataButton() {
	if ( isDataPresentSourceFoldersGridView && isDataPresentDestinationFolderTextBox ) {
		convertDataButton->Enabled = true;
	}
	else {
		convertDataButton->Enabled = false;
	}
}

Void MainForm::setDestinationFolderTextBox() {
	String^ cellData = brokerGridView->CurrentCell->Value->ToString();
	String^ sql = "Select DestinationFolderName from Brokers where Name = @parameter";
	String^ parameterName = "parameter";

	isDataPresentDestinationFolderTextBox = 
		query->querySelectData(sql, parameterName, cellData, destinationFolderTextBox);
	checkStateconvertDataButton();
}

Void MainForm::setSourceFoldersGridView() {
	String^ cellData = brokerGridView->CurrentCell->Value->ToString();
	String^ sql = "Select SourceFolders.Name from SourceFolders" +
		" inner join Brokers " +
		"on SourceFolders.BrokersCode = Brokers.ID" +
		" where Brokers.Name = @parameter";
	String^ parameterName = "parameter";

	isDataPresentSourceFoldersGridView = 
		query->querySelectData(sql, parameterName, cellData, sourceFoldersGridView);
	checkStateconvertDataButton();
}

void MainForm::ShowTable(String^ sql) {
	SqlConnection^ conn = SqlConn::DBUtils::GetDBConnection();

	conn->Open();
	try {
		DataTable^ DT = gcnew DataTable();
	
		SqlDataAdapter^ dataAdapter = gcnew SqlDataAdapter(sql, conn);
		dataAdapter->Fill(DT);	
		brokerGridView->DataSource = DT;
		this->brokerGridView->Columns[0]->HeaderText = "Брокеры:";
		brokerGridView->Update();
		delete DT;
		DT = nullptr;

	}
	catch (Exception ^ e) {
		Console::WriteLine("Error: " + e);
		Console::WriteLine(e->StackTrace);
	}
	finally {
		conn->Close();
		delete conn;
		conn = nullptr;
	}
}

System::Void MainForm::textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	String^ sql = "Select Name from Brokers where Name like @letter";
	SqlConnection^ conn = SqlConn::DBUtils::GetDBConnection();

	conn->Open();
	try {
		SqlCommand^ cmd = gcnew SqlCommand();

		cmd->Connection = conn;
		cmd->CommandText = sql;
		cmd->Parameters->Add("letter", SqlDbType::Text)->Value = brokerTextBox->Text + "%";
		
		addBrokerButton->Enabled = !query->setDataGridView(cmd, brokerGridView);
		
	//	this->dataGridView1->Columns[0]->HeaderText = "Брокеры:";
		brokerGridView->Refresh();//->Update();
		
		delete cmd;
		cmd = nullptr;
	}
	catch (Exception ^ e) {
		MessageBox::Show(e->Message, "Error");
		MessageBox::Show(e->StackTrace, "Error: " + e);
	}
	finally {
		conn->Close();
		delete conn;
		conn = nullptr;
	}
	
}

Void MainForm::brokerGridView_CurrentCellChanged(System::Object^ sender, System::EventArgs^ e) {
	if ( brokerGridView->CurrentCell == nullptr ) {
		sourceFolderTextBox->Enabled = false;
		addSourceFolderButton->Enabled = false;
		destinationFolderTextBox->Enabled = false;
		addDestinationFolderButton->Enabled = false;
		ArrayList^ Empty = gcnew ArrayList();
		sourceFoldersGridView->DataSource = Empty;
		sourceFoldersGridView->Refresh();
		destinationFolderTextBox->Text = "";
		delete Empty;
		isDataPresentSourceFoldersGridView = false;
		isDataPresentDestinationFolderTextBox = false;
		checkStateconvertDataButton();
		return;
	}
	if ( sourceFolderTextBox->Enabled == false ) {
		sourceFolderTextBox->Enabled = true;
		addSourceFolderButton->Enabled = true;
		destinationFolderTextBox->Enabled = true;
		addDestinationFolderButton->Enabled = true;
	}

	setDestinationFolderTextBox();

	setSourceFoldersGridView();
}

System::Void MainForm::addBrokerButton_Click(System::Object^ sender, System::EventArgs^ e) {
	auto name = brokerTextBox->Text;
	
	String^ sql = "Insert into Brokers (Name, DestinationFolderName) values (@name, @destinationFolderName)";

	query->queryModifyData(sql, "name", name, "destinationFolderName", "");
	textBox1_TextChanged(sender, e);

	brokerTextBox->Text = "";
}
	
Void MainForm::addSourceFolderButton_Click(System::Object^ sender, System::EventArgs^ e) {
	if ( sourceFolderTextBox->Text == "" ) {
		return;
	}
	
	auto sourceFolder = sourceFolderTextBox->Text;
	String^ brokerName = brokerGridView->CurrentCell->Value->ToString();

	String^ sql = "Insert into SourceFolders (Name, BrokersCode) " +
		"values (@sourceFolder, (Select ID from Brokers " +
		"where Brokers.Name = @brokerName))";

	query->queryModifyData(sql, "sourceFolder", sourceFolder, "brokerName", brokerName);
	
	sourceFolderTextBox->Text = "";

	setSourceFoldersGridView();
}

Void MainForm::addDestinationFolderButton_Click(System::Object^ sender, System::EventArgs^ e) {
	if ( destinationFolderTextBox->Text == "" ) {
		return;
	}
	auto destinationFolder = destinationFolderTextBox->Text;
	String^ brokerName = brokerGridView->CurrentCell->Value->ToString();

	String^ sql = "Update Brokers set DestinationFolderName = @destinationFolder" +
		" where Brokers.Name = @brokerName";

	query->queryModifyData(sql, "destinationFolder", destinationFolder, "brokerName", brokerName);

	destinationFolderTextBox->Text = "";

	setDestinationFolderTextBox();
}

Void MainForm::convertDataButton_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string pathToConvert;
	std::string pathFromTable;
	std::vector<std::string> pathToFiles;
	auto pathDataFromTable = sourceFoldersGridView->Rows;

	MarshalString(destinationFolderTextBox->Text, pathToConvert);

	for (std::size_t i = 0; i < pathDataFromTable->Count; i++) {
		try {
			array<String^, 1>^ allFoundFiles =
				Directory::GetFiles(static_cast<String^>(pathDataFromTable[i]->Cells[0]->Value),
					"*.tck", SearchOption::AllDirectories);
		
			for (std::size_t j = 0; j < allFoundFiles->Length; j++) {
				MarshalString(allFoundFiles[j], pathFromTable);
				pathToFiles.push_back(pathFromTable);
			}
		}
		catch (Exception ^ e) {
			MessageBox::Show(e->Message, "Error");
			MessageBox::Show(e->StackTrace, "Error: " + e);
		}
	}
	if (pathToFiles.size() == 0) {
		MessageBox::Show("Файлы для конвертирования не найдены!", "Error");
		return;
	}
	for (const auto& elem : pathToFiles) {

		ForexData fd(elem, pathToConvert);
		fd.read_data();
		fd.convert_data();
		fd.write_to_file();
		fd.delete_oldFile();
	}
	
}

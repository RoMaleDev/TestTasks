#include "MainForm.h"

void MarshalString(String ^ s, std::string& os) {
	using namespace Runtime::InteropServices;
	const char* chars =
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
}

void ConverterSAintoTable::MainForm::ShowTable() {
	dataGridView1->RowCount = fData->ShRow();
	dataGridView1->ColumnCount = fData->ShCol();
	//this->dataGridView1->TopLeftHeaderCell->Value = "hhhjhghggg";
	for (size_t i = 0; i < fData->ShCol(); i++) {
		this->dataGridView1->Columns[i]->HeaderText = "[" + System::Convert::ToString(i) + "]";
		this->dataGridView1->Columns[i]->SortMode = DataGridViewColumnSortMode::NotSortable;
		this->dataGridView1->Columns[i]->HeaderCell->SortGlyphDirection = System::Windows::Forms::SortOrder::None;
	}
	size_t index = 1;
	for (int i = 0; i < fData->ShRow(); i++) {
		dataGridView1->Rows[i]->HeaderCell->Value = "[" + System::Convert::ToString(i) + "]";
		for (int j = 0; j < fData->ShCol(); j++) {
			String^ strS = gcnew String((fData->ShString(index)).c_str());
			dataGridView1->Rows[i]->Cells[j]->Value = strS;
			index += 2;
			delete strS;
		}
	}
	
}

void ConverterSAintoTable::MainForm::loadDataIntoFile(Stream^ fStream) {
	char sumbol;
	Stream^ fileStream = fStream;
	
		StreamReader^ fRead = gcnew StreamReader(fileStream, System::Text::Encoding::Default);

		while (sumbol = fRead->Read(), sumbol != EOF)
		{
			fData->push_back(sumbol);
		}

		fRead->Close();
		fileStream->Close();
	
	fData->markArray();
	if (!fData->searchData()) {
		MessageBox::Show("������ ��� ����������� �� ������!",
			"ConverterSAintoTable", MessageBoxButtons::OK, MessageBoxIcon::Error);
		
		fData->clearData();
		return;
	}
	fData->moveDataToTable();
	ShowTable();
	this->������������ToolStripMenuItem->Enabled = true;
	this->�������ToolStripMenuItem->Enabled = true;
	this->�������ToolStripMenuItem->Enabled = true;
}

void ConverterSAintoTable::MainForm::saveDataToFile(Stream^ fStream) {
	Stream^ fileStream = fStream;
	
	if (���������ToolStripMenuItem->Enabled) {
		this->fData->readyToSave();
	}
	
	StreamWriter^ tWrite = gcnew StreamWriter(fileStream);
	std::size_t it_index = 0;
	
	for (; it_index < fData->sizeString(); it_index++)
	{
		String^ strS = gcnew String((fData->ShString(it_index)).c_str());
		tWrite->Write(strS);
	}

	tWrite->Close();
	fileStream->Close();
}

void ConverterSAintoTable::MainForm::setSelectionMode(int colIndex, int rowIndex) {
	this->col_index = colIndex;
	this->row_index = rowIndex;

	if (colIndex < 0 && rowIndex < 0) {
	MessageBox::Show("��������� ������� �� �������������!",
				"ConverterSAintoTable", MessageBoxButtons::OK, MessageBoxIcon::Error);
		this->col_index = colIndex = 0;
		this->row_index = rowIndex = 0;
	}

	if ((colIndex >= 0) && (rowIndex >= 0))
	{
		if ((dataGridView1->SelectedCells->Count == 1) && (colIndex == dataGridView1->SelectedCells[0]->ColumnIndex)
			&& (rowIndex == dataGridView1->SelectedCells[0]->RowIndex))
		{
			return;
		}
		dataGridView1->EndEdit();
		dataGridView1->ClearSelection();
		dataGridView1->SelectionMode = DataGridViewSelectionMode::CellSelect;
		dataGridView1->Rows[rowIndex]->Cells[colIndex]->Selected = true;

		this->��������������������ToolStripMenuItem->Enabled = true;
		this->���������������������ToolStripMenuItem->Enabled = true;
		this->��������������ToolStripMenuItem->Enabled = true;
		this->������������������ToolStripMenuItem->Enabled = true;
		this->������������������ToolStripMenuItem->Enabled = true;
		this->�������������ToolStripMenuItem->Enabled = true;
		for (std::size_t index = 0; index < 7; index++) {
			this->contextMenuStrip1->Items[index]->Visible = true;
		}
	}
	else if (colIndex >= 0)
	{
		dataGridView1->EndEdit();
		dataGridView1->ClearSelection();
		dataGridView1->SelectionMode = DataGridViewSelectionMode::FullColumnSelect;
		dataGridView1->Columns[colIndex]->Selected = true;

		this->��������������������ToolStripMenuItem->Enabled = true;
		this->���������������������ToolStripMenuItem->Enabled = true;
		this->��������������ToolStripMenuItem->Enabled = true;
		this->������������������ToolStripMenuItem->Enabled = false;
		this->������������������ToolStripMenuItem->Enabled = false;
		this->�������������ToolStripMenuItem->Enabled = false;
		this->contextMenuStrip1->Items[0]->Visible = false;
		this->contextMenuStrip1->Items[1]->Visible = false;
		this->contextMenuStrip1->Items[2]->Visible = false;
		this->contextMenuStrip1->Items[3]->Visible = false;
		this->contextMenuStrip1->Items[4]->Visible = true;
		this->contextMenuStrip1->Items[5]->Visible = true;
		this->contextMenuStrip1->Items[6]->Visible = true;
	}
	else if (rowIndex >= 0)
	{
		dataGridView1->EndEdit();
		dataGridView1->ClearSelection();
		dataGridView1->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
		dataGridView1->Rows[rowIndex]->Selected = true;

		this->��������������������ToolStripMenuItem->Enabled = false;
		this->���������������������ToolStripMenuItem->Enabled = false;
		this->��������������ToolStripMenuItem->Enabled = false;
		this->������������������ToolStripMenuItem->Enabled = true;
		this->������������������ToolStripMenuItem->Enabled = true;
		this->�������������ToolStripMenuItem->Enabled = true;
		this->contextMenuStrip1->Items[0]->Visible = true;
		this->contextMenuStrip1->Items[1]->Visible = true;
		this->contextMenuStrip1->Items[2]->Visible = true;
		this->contextMenuStrip1->Items[3]->Visible = false;
		this->contextMenuStrip1->Items[4]->Visible = false;
		this->contextMenuStrip1->Items[5]->Visible = false;
		this->contextMenuStrip1->Items[6]->Visible = false;
	}
}

System::Void ConverterSAintoTable::MainForm::�������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	
	if (���������ToolStripMenuItem->Enabled) {
		if (::DialogResult::Yes ==
			MessageBox::Show("��������� ��������� � ����� \'" + openFileDialog1->FileName->ToString() +"\'", 
			"ConverterSAintoTable", MessageBoxButtons::YesNo, MessageBoxIcon::Question)) {
			Stream^ myStream;
			saveFileDialog1->InitialDirectory = openFileDialog1->InitialDirectory;
			saveFileDialog1->FileName = openFileDialog1->FileName;
			saveFileDialog1->Filter = "�++ ����� (*.cpp)|*.cpp|�++ ����� (*.c)| *.c|�++ ����� (*.cc)|*.cc|�++ ����� (*.h)|*.h|�++ ����� (*.hpp)|*.hpp|��� ����� (*.*)|*.*";
			if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				if ((myStream = saveFileDialog1->OpenFile()) != nullptr)
				{
					saveDataToFile(saveFileDialog1->OpenFile());
				}
			}
		}
	}
	if (fData->sizeString()) {
		fData->clearData();
	}
	Stream^ myStream;
	openFileDialog1->InitialDirectory = "%HOMEPATH%";
	openFileDialog1->Filter = "�++ ����� (*.cpp; *.c; *.cc; *.h; *.hpp)|*.cpp; *.c; *.cc; *.h; *.hpp|��� ����� (*.*)|*.*";
	openFileDialog1->FilterIndex = 1;
	openFileDialog1->RestoreDirectory = true;

	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		if ((myStream = openFileDialog1->OpenFile()) != nullptr)
		{
			loadDataIntoFile(openFileDialog1->OpenFile());
//////////////////////////////////////////////////////////////////////////////////////////
		}

	}
	
}

System::Void ConverterSAintoTable::MainForm::dataGridView1_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
	setSelectionMode(e->ColumnIndex, e->RowIndex);
}

System::Void ConverterSAintoTable::MainForm::dataGridView1_CellMouseClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^ e) {
	if (e->Button == System::Windows::Forms::MouseButtons::Right) {
		setSelectionMode(e->ColumnIndex, e->RowIndex);
		contextMenuStrip1->Show(MousePosition, ToolStripDropDownDirection::Default);
	}
}

System::Void ConverterSAintoTable::MainForm::dataGridView1_CellEndEdit(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
	std::string data;
	if (dataGridView1[e->ColumnIndex, e->RowIndex]->Value != nullptr) {
		MarshalString(dataGridView1[e->ColumnIndex, e->RowIndex]->Value->ToString(), data);
		fData->replaceData(e->ColumnIndex, e->RowIndex, data);
	}
	else {
		fData->replaceData(e->ColumnIndex, e->RowIndex, "");
	}
	ShowTable();
	���������ToolStripMenuItem->Enabled = true;
}

System::Void ConverterSAintoTable::MainForm::�������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	fData->insertRow(0);
	ShowTable();
	setSelectionMode(-1, 0);
	���������ToolStripMenuItem->Enabled = true;
}

System::Void ConverterSAintoTable::MainForm::��������������������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	fData->insertRow(fData->ShRow());
	ShowTable();
	setSelectionMode(-1, fData->ShRow() - 1);
	���������ToolStripMenuItem->Enabled = true;
}

System::Void ConverterSAintoTable::MainForm::������������������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	fData->insertRow(this->row_index);
	ShowTable();
	setSelectionMode(-1, this->row_index);
	���������ToolStripMenuItem->Enabled = true;
}

System::Void ConverterSAintoTable::MainForm::������������������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	fData->insertRow(this->row_index+1);
	ShowTable();
	setSelectionMode(-1, this->row_index+1);
	���������ToolStripMenuItem->Enabled = true;
}

System::Void ConverterSAintoTable::MainForm::�������������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	if (fData->ShRow() == 1) {
		MessageBox::Show("�������� ��������� ������ �� �������������!",
			"ConverterSAintoTable", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	fData->deleteRow(this->row_index);
	ShowTable();
	if (this->row_index == fData->ShRow()) {
		this->row_index -= 1;
	}
	setSelectionMode(-1, this->row_index);
	���������ToolStripMenuItem->Enabled = true;
}

System::Void ConverterSAintoTable::MainForm::����������������������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	fData->insertColumn(0);
	dataGridView1->SelectionMode = DataGridViewSelectionMode::CellSelect;
	ShowTable();
	setSelectionMode(0, -1);
	���������ToolStripMenuItem->Enabled = true;
}

System::Void ConverterSAintoTable::MainForm::���������������������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	fData->insertColumn(fData->ShCol());
	dataGridView1->SelectionMode = DataGridViewSelectionMode::CellSelect;
	ShowTable();
	setSelectionMode(fData->ShCol() - 1, -1);
	���������ToolStripMenuItem->Enabled = true;
}

System::Void ConverterSAintoTable::MainForm::��������������������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	fData->insertColumn(this->col_index);
	dataGridView1->SelectionMode = DataGridViewSelectionMode::CellSelect;
	ShowTable();
	setSelectionMode(col_index, -1);
	���������ToolStripMenuItem->Enabled = true;
}

System::Void ConverterSAintoTable::MainForm::���������������������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	fData->insertColumn(this->col_index+1);
	dataGridView1->SelectionMode = DataGridViewSelectionMode::CellSelect;
	ShowTable();
	setSelectionMode(col_index+1, -1);
	���������ToolStripMenuItem->Enabled = true;
}

System::Void ConverterSAintoTable::MainForm::��������������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	if (fData->ShCol() == 1) {
		MessageBox::Show("�������� ���������� ������� �� �������������!",
			"ConverterSAintoTable", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	fData->deleteColumn(this->col_index);
	dataGridView1->SelectionMode = DataGridViewSelectionMode::CellSelect;
	ShowTable();
	if (this->col_index == fData->ShCol()) {
		this->col_index -= 1;
	}
	setSelectionMode(this->col_index, -1);
	���������ToolStripMenuItem->Enabled = true;
}

System::Void ConverterSAintoTable::MainForm::��������������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	fData->insertRow(this->row_index);
	ShowTable();
	setSelectionMode(-1, this->row_index);
	���������ToolStripMenuItem->Enabled = true;
}
// ��������! �������� ������� ������������� ������ ��������
System::Void ConverterSAintoTable::MainForm::���������������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	fData->insertRow(this->row_index+1);
	ShowTable();
	setSelectionMode(-1, this->row_index+1);
	���������ToolStripMenuItem->Enabled = true;
}

System::Void ConverterSAintoTable::MainForm::�������������ToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
	if (fData->ShRow() == 1) {
		MessageBox::Show("�������� ��������� ������ �� �������������!",
			"ConverterSAintoTable", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
	}
	fData->deleteRow(this->row_index);
	ShowTable();
	if (this->row_index == fData->ShRow()) {
		this->row_index -= 1;
	}
	setSelectionMode(-1, this->row_index);
	���������ToolStripMenuItem->Enabled = true;
}

System::Void ConverterSAintoTable::MainForm::��������������������ToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
	fData->insertColumn(this->col_index);
	dataGridView1->SelectionMode = DataGridViewSelectionMode::CellSelect;
	ShowTable();
	setSelectionMode(this->col_index, -1);
	���������ToolStripMenuItem->Enabled = true;
}

System::Void ConverterSAintoTable::MainForm::���������������������ToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
	fData->insertColumn(this->col_index+1);
	dataGridView1->SelectionMode = DataGridViewSelectionMode::CellSelect;
	ShowTable();
	setSelectionMode(this->col_index+1, -1);
	���������ToolStripMenuItem->Enabled = true;
}

System::Void ConverterSAintoTable::MainForm::��������������ToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
	if (fData->ShCol() == 1) {
		MessageBox::Show("�������� ���������� ������� �� �������������!",
			"ConverterSAintoTable", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
	}
	fData->deleteColumn(this->col_index);
	dataGridView1->SelectionMode = DataGridViewSelectionMode::CellSelect;
	ShowTable();
	if (this->col_index == fData->ShCol()) {
		this->col_index -= 1;
	}
	setSelectionMode(this->col_index, -1);
	���������ToolStripMenuItem->Enabled = true;
}

System::Void ConverterSAintoTable::MainForm::���������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	Stream^ myStream;
	saveFileDialog1->InitialDirectory = openFileDialog1->InitialDirectory;
	saveFileDialog1->FileName = openFileDialog1->FileName;
	myStream = saveFileDialog1->OpenFile();
	saveDataToFile(myStream);
	���������ToolStripMenuItem->Enabled = false;
}

System::Void ConverterSAintoTable::MainForm::������������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	Stream^ myStream;
	saveFileDialog1->InitialDirectory = openFileDialog1->InitialDirectory;
	saveFileDialog1->FileName = openFileDialog1->FileName;
	saveFileDialog1->Filter = "�++ ����� (*.cpp)|*.cpp|�++ ����� (*.c)| *.c|�++ ����� (*.cc)|*.cc|�++ ����� (*.h)|*.h|�++ ����� (*.hpp)|*.hpp|��� ����� (*.*)|*.*";
	saveFileDialog1->RestoreDirectory = true;
	if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		if ((myStream = saveFileDialog1->OpenFile()) != nullptr)
		{
			saveDataToFile(myStream);
		}
	}
	fData->clearData();
	dataGridView1->Rows->Clear();
	dataGridView1->Columns->Clear();
	���������ToolStripMenuItem->Enabled = false;

	openFileDialog1->InitialDirectory = saveFileDialog1->InitialDirectory;
	openFileDialog1->FileName = saveFileDialog1->FileName;

	if (openFileDialog1->OpenFile() != nullptr)
	{
		loadDataIntoFile(openFileDialog1->OpenFile());
	}
}

System::Void ConverterSAintoTable::MainForm::�������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	if (���������ToolStripMenuItem->Enabled) {
		if (::DialogResult::Yes ==
			MessageBox::Show("��������� ��������� � ����� \'" + openFileDialog1->FileName->ToString() + "\'",
			"ConverterSAintoTable", MessageBoxButtons::YesNo, MessageBoxIcon::Question)) {
			Stream^ myStream;
			saveFileDialog1->InitialDirectory = openFileDialog1->InitialDirectory;
			saveFileDialog1->FileName = openFileDialog1->FileName;
			saveFileDialog1->Filter = "�++ ����� (*.cpp)|*.cpp|�++ ����� (*.c)| *.c|�++ ����� (*.cc)|*.cc|�++ ����� (*.h)|*.h|�++ ����� (*.hpp)|*.hpp|��� ����� (*.*)|*.*";
			if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				if ((myStream = saveFileDialog1->OpenFile()) != nullptr)
				{
					saveDataToFile(myStream);
				}
			}
		}
	}
	this->�������ToolStripMenuItem->Enabled = false;
	���������ToolStripMenuItem->Enabled = false;
	this->�������ToolStripMenuItem->Enabled = false;
	������������ToolStripMenuItem->Enabled = false;
	fData->clearData();
	dataGridView1->Rows->Clear();
	dataGridView1->Columns->Clear();
}

System::Void ConverterSAintoTable::MainForm::�����ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Close();
}

System::Void ConverterSAintoTable::MainForm::MainForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
	if (���������ToolStripMenuItem->Enabled) {
		if (::DialogResult::Yes ==
			MessageBox::Show("��������� ��������� � ����� \'" + openFileDialog1->FileName->ToString() + "\'",
			"ConverterSAintoTable", MessageBoxButtons::YesNo, MessageBoxIcon::Question)) {
			Stream^ myStream;
			saveFileDialog1->InitialDirectory = openFileDialog1->InitialDirectory;
			saveFileDialog1->FileName = openFileDialog1->FileName;
			saveFileDialog1->Filter = "�++ ����� (*.cpp)|*.cpp|�++ ����� (*.c)| *.c|�++ ����� (*.cc)|*.cc|�++ ����� (*.h)|*.h|�++ ����� (*.hpp)|*.hpp|��� ����� (*.*)|*.*";
			if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				if ((myStream = saveFileDialog1->OpenFile()) != nullptr)
				{
					saveDataToFile(myStream);
				}
			}
		}
	}
}

System::Void ConverterSAintoTable::MainForm::����������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	MessageBox::Show("��������� - �������� �������\n\n��������� ������������� ��� �������������\n���������� ���������� ������� �++ ����� �\n���� �������.\n\n����������: RoMaleDev\n������:          0.0.100500");
}
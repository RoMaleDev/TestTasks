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
		MessageBox::Show("Массив для отображения не найден!",
			"ConverterSAintoTable", MessageBoxButtons::OK, MessageBoxIcon::Error);
		
		fData->clearData();
		return;
	}
	fData->moveDataToTable();
	ShowTable();
	this->сохранитьКакToolStripMenuItem->Enabled = true;
	this->таблицаToolStripMenuItem->Enabled = true;
	this->закрытьToolStripMenuItem->Enabled = true;
}

void ConverterSAintoTable::MainForm::saveDataToFile(Stream^ fStream) {
	Stream^ fileStream = fStream;
	
	if (сохранитьToolStripMenuItem->Enabled) {
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
	MessageBox::Show("Выделение таблицы не предусмотрено!",
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

		this->вставитьСтолбецСлеваToolStripMenuItem->Enabled = true;
		this->вставитьСтолбецСправаToolStripMenuItem->Enabled = true;
		this->удалитьСтолбецToolStripMenuItem->Enabled = true;
		this->вставитьСтрокуНижеToolStripMenuItem->Enabled = true;
		this->вставитьСтрокуВышеToolStripMenuItem->Enabled = true;
		this->удалитьСтрокуToolStripMenuItem->Enabled = true;
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

		this->вставитьСтолбецСлеваToolStripMenuItem->Enabled = true;
		this->вставитьСтолбецСправаToolStripMenuItem->Enabled = true;
		this->удалитьСтолбецToolStripMenuItem->Enabled = true;
		this->вставитьСтрокуНижеToolStripMenuItem->Enabled = false;
		this->вставитьСтрокуВышеToolStripMenuItem->Enabled = false;
		this->удалитьСтрокуToolStripMenuItem->Enabled = false;
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

		this->вставитьСтолбецСлеваToolStripMenuItem->Enabled = false;
		this->вставитьСтолбецСправаToolStripMenuItem->Enabled = false;
		this->удалитьСтолбецToolStripMenuItem->Enabled = false;
		this->вставитьСтрокуНижеToolStripMenuItem->Enabled = true;
		this->вставитьСтрокуВышеToolStripMenuItem->Enabled = true;
		this->удалитьСтрокуToolStripMenuItem->Enabled = true;
		this->contextMenuStrip1->Items[0]->Visible = true;
		this->contextMenuStrip1->Items[1]->Visible = true;
		this->contextMenuStrip1->Items[2]->Visible = true;
		this->contextMenuStrip1->Items[3]->Visible = false;
		this->contextMenuStrip1->Items[4]->Visible = false;
		this->contextMenuStrip1->Items[5]->Visible = false;
		this->contextMenuStrip1->Items[6]->Visible = false;
	}
}

System::Void ConverterSAintoTable::MainForm::открытьToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	
	if (сохранитьToolStripMenuItem->Enabled) {
		if (::DialogResult::Yes ==
			MessageBox::Show("Сохранить изменения в файле \'" + openFileDialog1->FileName->ToString() +"\'", 
			"ConverterSAintoTable", MessageBoxButtons::YesNo, MessageBoxIcon::Question)) {
			Stream^ myStream;
			saveFileDialog1->InitialDirectory = openFileDialog1->InitialDirectory;
			saveFileDialog1->FileName = openFileDialog1->FileName;
			saveFileDialog1->Filter = "С++ файлы (*.cpp)|*.cpp|С++ файлы (*.c)| *.c|С++ файлы (*.cc)|*.cc|С++ файлы (*.h)|*.h|С++ файлы (*.hpp)|*.hpp|Все файлы (*.*)|*.*";
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
	openFileDialog1->Filter = "С++ файлы (*.cpp; *.c; *.cc; *.h; *.hpp)|*.cpp; *.c; *.cc; *.h; *.hpp|Все файлы (*.*)|*.*";
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
	сохранитьToolStripMenuItem->Enabled = true;
}

System::Void ConverterSAintoTable::MainForm::втавитьToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	fData->insertRow(0);
	ShowTable();
	setSelectionMode(-1, 0);
	сохранитьToolStripMenuItem->Enabled = true;
}

System::Void ConverterSAintoTable::MainForm::вставитьСтрокуВКонецToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	fData->insertRow(fData->ShRow());
	ShowTable();
	setSelectionMode(-1, fData->ShRow() - 1);
	сохранитьToolStripMenuItem->Enabled = true;
}

System::Void ConverterSAintoTable::MainForm::вставитьСтрокуВышеToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	fData->insertRow(this->row_index);
	ShowTable();
	setSelectionMode(-1, this->row_index);
	сохранитьToolStripMenuItem->Enabled = true;
}

System::Void ConverterSAintoTable::MainForm::вставитьСтрокуНижеToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	fData->insertRow(this->row_index+1);
	ShowTable();
	setSelectionMode(-1, this->row_index+1);
	сохранитьToolStripMenuItem->Enabled = true;
}

System::Void ConverterSAintoTable::MainForm::удалитьСтрокуToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	if (fData->ShRow() == 1) {
		MessageBox::Show("Удаление последней строки не предусмотрено!",
			"ConverterSAintoTable", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	fData->deleteRow(this->row_index);
	ShowTable();
	if (this->row_index == fData->ShRow()) {
		this->row_index -= 1;
	}
	setSelectionMode(-1, this->row_index);
	сохранитьToolStripMenuItem->Enabled = true;
}

System::Void ConverterSAintoTable::MainForm::вставитьСтолбецВНачалоToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	fData->insertColumn(0);
	dataGridView1->SelectionMode = DataGridViewSelectionMode::CellSelect;
	ShowTable();
	setSelectionMode(0, -1);
	сохранитьToolStripMenuItem->Enabled = true;
}

System::Void ConverterSAintoTable::MainForm::вставитьСтолбецВКонецToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	fData->insertColumn(fData->ShCol());
	dataGridView1->SelectionMode = DataGridViewSelectionMode::CellSelect;
	ShowTable();
	setSelectionMode(fData->ShCol() - 1, -1);
	сохранитьToolStripMenuItem->Enabled = true;
}

System::Void ConverterSAintoTable::MainForm::вставитьСтолбецСлеваToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	fData->insertColumn(this->col_index);
	dataGridView1->SelectionMode = DataGridViewSelectionMode::CellSelect;
	ShowTable();
	setSelectionMode(col_index, -1);
	сохранитьToolStripMenuItem->Enabled = true;
}

System::Void ConverterSAintoTable::MainForm::вставитьСтолбецСправаToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	fData->insertColumn(this->col_index+1);
	dataGridView1->SelectionMode = DataGridViewSelectionMode::CellSelect;
	ShowTable();
	setSelectionMode(col_index+1, -1);
	сохранитьToolStripMenuItem->Enabled = true;
}

System::Void ConverterSAintoTable::MainForm::удалитьСтолбецToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	if (fData->ShCol() == 1) {
		MessageBox::Show("Удаление последнего столбца не предусмотрено!",
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
	сохранитьToolStripMenuItem->Enabled = true;
}

System::Void ConverterSAintoTable::MainForm::вставитьСтрокуToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	fData->insertRow(this->row_index);
	ShowTable();
	setSelectionMode(-1, this->row_index);
	сохранитьToolStripMenuItem->Enabled = true;
}
// Внимание! Ошибочно названа конструктором строка столбцом
System::Void ConverterSAintoTable::MainForm::вставитьСтолбецToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	fData->insertRow(this->row_index+1);
	ShowTable();
	setSelectionMode(-1, this->row_index+1);
	сохранитьToolStripMenuItem->Enabled = true;
}

System::Void ConverterSAintoTable::MainForm::удалитьСтрокуToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
	if (fData->ShRow() == 1) {
		MessageBox::Show("Удаление последней строки не предусмотрено!",
			"ConverterSAintoTable", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
	}
	fData->deleteRow(this->row_index);
	ShowTable();
	if (this->row_index == fData->ShRow()) {
		this->row_index -= 1;
	}
	setSelectionMode(-1, this->row_index);
	сохранитьToolStripMenuItem->Enabled = true;
}

System::Void ConverterSAintoTable::MainForm::вставитьСтолбецСлеваToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
	fData->insertColumn(this->col_index);
	dataGridView1->SelectionMode = DataGridViewSelectionMode::CellSelect;
	ShowTable();
	setSelectionMode(this->col_index, -1);
	сохранитьToolStripMenuItem->Enabled = true;
}

System::Void ConverterSAintoTable::MainForm::вставитьСтолбецСправаToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
	fData->insertColumn(this->col_index+1);
	dataGridView1->SelectionMode = DataGridViewSelectionMode::CellSelect;
	ShowTable();
	setSelectionMode(this->col_index+1, -1);
	сохранитьToolStripMenuItem->Enabled = true;
}

System::Void ConverterSAintoTable::MainForm::удалитьСтолбецToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
	if (fData->ShCol() == 1) {
		MessageBox::Show("Удаление последнего столбца не предусмотрено!",
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
	сохранитьToolStripMenuItem->Enabled = true;
}

System::Void ConverterSAintoTable::MainForm::сохранитьToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	Stream^ myStream;
	saveFileDialog1->InitialDirectory = openFileDialog1->InitialDirectory;
	saveFileDialog1->FileName = openFileDialog1->FileName;
	myStream = saveFileDialog1->OpenFile();
	saveDataToFile(myStream);
	сохранитьToolStripMenuItem->Enabled = false;
}

System::Void ConverterSAintoTable::MainForm::сохранитьКакToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	Stream^ myStream;
	saveFileDialog1->InitialDirectory = openFileDialog1->InitialDirectory;
	saveFileDialog1->FileName = openFileDialog1->FileName;
	saveFileDialog1->Filter = "С++ файлы (*.cpp)|*.cpp|С++ файлы (*.c)| *.c|С++ файлы (*.cc)|*.cc|С++ файлы (*.h)|*.h|С++ файлы (*.hpp)|*.hpp|Все файлы (*.*)|*.*";
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
	сохранитьToolStripMenuItem->Enabled = false;

	openFileDialog1->InitialDirectory = saveFileDialog1->InitialDirectory;
	openFileDialog1->FileName = saveFileDialog1->FileName;

	if (openFileDialog1->OpenFile() != nullptr)
	{
		loadDataIntoFile(openFileDialog1->OpenFile());
	}
}

System::Void ConverterSAintoTable::MainForm::закрытьToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	if (сохранитьToolStripMenuItem->Enabled) {
		if (::DialogResult::Yes ==
			MessageBox::Show("Сохранить изменения в файле \'" + openFileDialog1->FileName->ToString() + "\'",
			"ConverterSAintoTable", MessageBoxButtons::YesNo, MessageBoxIcon::Question)) {
			Stream^ myStream;
			saveFileDialog1->InitialDirectory = openFileDialog1->InitialDirectory;
			saveFileDialog1->FileName = openFileDialog1->FileName;
			saveFileDialog1->Filter = "С++ файлы (*.cpp)|*.cpp|С++ файлы (*.c)| *.c|С++ файлы (*.cc)|*.cc|С++ файлы (*.h)|*.h|С++ файлы (*.hpp)|*.hpp|Все файлы (*.*)|*.*";
			if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				if ((myStream = saveFileDialog1->OpenFile()) != nullptr)
				{
					saveDataToFile(myStream);
				}
			}
		}
	}
	this->таблицаToolStripMenuItem->Enabled = false;
	сохранитьToolStripMenuItem->Enabled = false;
	this->закрытьToolStripMenuItem->Enabled = false;
	сохранитьКакToolStripMenuItem->Enabled = false;
	fData->clearData();
	dataGridView1->Rows->Clear();
	dataGridView1->Columns->Clear();
}

System::Void ConverterSAintoTable::MainForm::выходToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Close();
}

System::Void ConverterSAintoTable::MainForm::MainForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
	if (сохранитьToolStripMenuItem->Enabled) {
		if (::DialogResult::Yes ==
			MessageBox::Show("Сохранить изменения в файле \'" + openFileDialog1->FileName->ToString() + "\'",
			"ConverterSAintoTable", MessageBoxButtons::YesNo, MessageBoxIcon::Question)) {
			Stream^ myStream;
			saveFileDialog1->InitialDirectory = openFileDialog1->InitialDirectory;
			saveFileDialog1->FileName = openFileDialog1->FileName;
			saveFileDialog1->Filter = "С++ файлы (*.cpp)|*.cpp|С++ файлы (*.c)| *.c|С++ файлы (*.cc)|*.cc|С++ файлы (*.h)|*.h|С++ файлы (*.hpp)|*.hpp|Все файлы (*.*)|*.*";
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

System::Void ConverterSAintoTable::MainForm::оПрограммеToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	MessageBox::Show("Программа - Тестовое задание\n\nПрограмма предназначена для представления\nнайденного строкового массива С++ файла в\nвиде таблицы.\n\nРазработал: RoMaleDev\nВерсия:          0.0.100500");
}
#include "Query.h"

using namespace System::Data::Common;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;

Query::Query(SqlConnection^ conn) {
	this->connection = conn;
}

bool Query::setDataGridView(SqlCommand^ cmd, Object^ setDataFromDB) {
	DataTable^ dataTable = gcnew DataTable();
	SqlDataReader^ reader = cmd->ExecuteReader();
	bool hasRows;

	try {
		if (hasRows = reader->HasRows) {
			dataTable->Load(reader);
			if (setDataFromDB->GetType()->Name == "DataGridView") {
				static_cast<DataGridView^>(setDataFromDB)->DataSource = dataTable;
				static_cast<DataGridView^>(setDataFromDB)->Refresh();
			}
			else if (setDataFromDB->GetType()->Name == "TextBox") {
				static_cast<TextBox^>(setDataFromDB)->Text = static_cast<String^>(dataTable->Rows[0]->ItemArray[0]);
			}
		}
		else {
			if (setDataFromDB->GetType()->Name == "DataGridView") {
				ArrayList^ Empty = gcnew ArrayList();
				static_cast<DataGridView^>(setDataFromDB)->DataSource = Empty;
				static_cast<DataGridView^>(setDataFromDB)->Refresh();
				delete Empty;
			}
			else if (setDataFromDB->GetType()->Name == "TextBox") {
				static_cast<TextBox^>(setDataFromDB)->Text = "";
			}
		}

	}
	finally {
		reader->Close();
		delete dataTable;
		delete reader;
		dataTable = nullptr;
		reader = nullptr;
	}
	return hasRows;
}

bool Query::querySelectData(String^ sql, String^ parameterName, String^ Parameter, Object^ setDataFromDB) {
	bool result = false;
	connection->Open();
	try {
		SqlCommand^ cmd = gcnew SqlCommand();

		cmd->Connection = connection;
		cmd->CommandText = sql;
		cmd->Parameters->Add(parameterName, SqlDbType::NVarChar)->Value = Parameter;

		result = setDataGridView(cmd, setDataFromDB);

		delete cmd;
		cmd = nullptr;
	}
	catch (Exception ^ e) {
		MessageBox::Show(e->Message, "Error");
	}
	finally {
		connection->Close();
	}
	return result;
}

Void Query::queryModifyData(String^ sql, String^ parameterName, String^ Parameter) {

	connection->Open();
	try
	{
		SqlCommand^ cmd = connection->CreateCommand();
		cmd->CommandText = sql;

		cmd->Parameters->Add(parameterName, SqlDbType::NVarChar)->Value = Parameter;

		cmd->ExecuteNonQuery();

		delete cmd;
		cmd = nullptr;
	}
	catch (Exception ^ e) {
		MessageBox::Show(e->Message, "Error");
		MessageBox::Show(e->StackTrace, "Error: " + e);
	}
	finally {
		connection->Close();
	}
}

Void Query::queryModifyData(String^ sql, String^ parameterName1, String^ Parameter1,
	String^ parameterName2, String^ Parameter2) {

	connection->Open();
	try
	{
		SqlCommand^ cmd = connection->CreateCommand();
		cmd->CommandText = sql;

		cmd->Parameters->Add(parameterName1, SqlDbType::NVarChar)->Value = Parameter1;
		cmd->Parameters->Add(parameterName2, SqlDbType::NVarChar)->Value = Parameter2;

		cmd->ExecuteNonQuery();

		delete cmd;
		cmd = nullptr;
	}
	catch (Exception ^ e) {
		MessageBox::Show(e->Message, "Error");
		MessageBox::Show(e->StackTrace, "Error: " + e);
	}
	finally {
		connection->Close();
	}
}
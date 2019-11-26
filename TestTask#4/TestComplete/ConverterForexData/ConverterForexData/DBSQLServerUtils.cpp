#include "DBSQLServerUtils.h"

using namespace SqlConn;

SqlConnection^ DBSQLServerUtils::GetDBConnection(String^ datasource, String^ database, String^ username, String^ password)
{
	//
	// Data Source=TRAN-VMWARE\SQLEXPRESS;Initial Catalog=simplehr;Persist Security Info=True;User ID=sa;Password=12345
	//
	String^ connString = "Data Source = " + datasource + "; Initial Catalog = "
		+ database + ";Persist Security Info=True;User ID=" + username + ";Password=" + password;

	SqlConnection^ conn = gcnew SqlConnection(connString);

	return conn;
}
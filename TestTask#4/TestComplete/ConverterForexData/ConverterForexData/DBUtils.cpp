#include "DBUtils.h"

using namespace SqlConn;

SqlConnection^ DBUtils::GetDBConnection() {
	String^ datasource = "(localdb)\\MSSQLLocalDB";//"192.168.205.135\\SQLEXPRESS";
	String^ database = "MSdBase";
	String^ username = "";// "sa";
	String^ password = "";// "1234";

	return DBSQLServerUtils::GetDBConnection(datasource, database, username, password);
}
#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Data::Linq;
using namespace System::Text;
using namespace System::Threading::Tasks;
using namespace System::Data::SqlClient;

namespace SqlConn {

	ref class DBSQLServerUtils {
	public:
		static SqlConnection^ GetDBConnection(String^ datasource, String^ database, String^ username, String^ password);
	};

}
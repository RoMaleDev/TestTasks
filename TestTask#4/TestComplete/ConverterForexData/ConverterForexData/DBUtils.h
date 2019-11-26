#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Data::Linq;
using namespace System::Text;
using namespace System::Threading::Tasks;
using namespace System::Data::SqlClient;

#include "DBSQLServerUtils.h"

namespace SqlConn {

	ref class DBUtils {
	public:
		static SqlConnection^ GetDBConnection();
	};

}


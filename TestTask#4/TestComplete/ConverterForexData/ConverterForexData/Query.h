#pragma once

#include "DBUtils.h"

using namespace System;


ref class Query
{
	SqlConnection^ connection;
public:
	Query(SqlConnection^ conn);
	bool setDataGridView(SqlCommand^ cmd, Object^ setDataFromDB);
	bool querySelectData(String^ sql, String^ parameterName, String^ Parameter, Object^ setDataFromDB);
	Void queryModifyData(String^ sql, String^ parameterName, String^ Parameter);
	Void queryModifyData(String^ sql, String^ parameterName1, String^ Parameter1,
		String^ parameterName2, String^ Parameter2);

};

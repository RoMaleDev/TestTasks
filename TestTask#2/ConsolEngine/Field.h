// Copyright 2018 RoMaleDev. All Rights Reserved.

#pragma once

const int COLUMNS = 20;
const int ROW = 10;

class Field
{
private:
	bool field[COLUMNS][ROW];

public:
	Field();
	~Field();
	void clear();
	bool read(int col, int row) const;
	void write(int col, int row, bool data);
	void deleteRow(int col);
};

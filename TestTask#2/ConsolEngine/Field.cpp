// Copyright 2018 RoMaleDev. All Rights Reserved.

#include "Field.h"

Field::Field()
{
	clear();
}

Field::~Field()
{
}

void Field::clear() {
	for ( int c = 0; c < COLUMNS; c++ ) {
		for ( int r = 0; r < ROW; r++ ) {
			field[c][r] = false;
		}
	}
}

bool Field::read(int col, int row) const {
	return field[col][row];
 }

void Field::write(int col, int row, bool data) {
	field[col][row] = data;
}

void Field::deleteRow(int col) {
	for ( int column = col; col > 0; col-- ) {
		for ( int row = 0; row < ROW; row++ ) {
			write(col, row, read(col - 1, row));
		}
	}
	for (int row = 0; row < ROW; row++) {
		write(0, row, false);
	}
}

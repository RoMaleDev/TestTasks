// Copyright 2018 RoMaleDev. All Rights Reserved.

#include "Figure.h"

const SchemeFigure Figure::stFigure[DIMENSION] = { { 1, 4, { true, true, true, true } }, { 2, 2, { true, true, true, true } },
{ 2, 3, { true, true, true, false, false, true } }, { 2, 3, { true, true, true, false, true, false } },
{ 2, 3, { true, true, true, true, false, false } }, { 2, 3, { true, true, false, false, true, true } },
{ 2, 3, { false, true, true, true, true, false } } };

Figure::Figure()
{
	figure = new SchemeFigure;
	std::srand(std::time(NULL));
	randomF();
	newFigure();
}

Figure::Figure(const Figure& fig) {
	this->figure = new SchemeFigure;
	this->random = fig.random;
	this->figure->X = fig.figure->X;
	this->figure->Y = fig.figure->Y;

	for ( int index = 0; index < DIMENSION; index++ ) {
		this->figure->data[index] = fig.figure->data[index];
	}
}

Figure::~Figure()
{
	delete figure;
}

void Figure::randomF() {
	this->random = rand() % DIMENSION;
}

void Figure::newFigure() {	
	figure->X = stFigure[random].X;
	figure->Y = stFigure[random].Y;

	for ( int index = 0; index < DIMENSION; index++ ) {
		figure->data[index] = stFigure[random].data[index];
	}
}

int Figure::readX(bool stat) const {
	return stat ? Figure::stFigure[random].X : this->figure->X;
}

int Figure::readY(bool stat) const {
	return stat ? Figure::stFigure[random].Y : this->figure->Y;
}

int Figure::readRandom() const {
	return this->random;
}

bool Figure::readData(int x, int y, bool stat) const {
	return stat ? Figure::stFigure[random].data[x * Figure::stFigure[random].Y + y] : this->figure->data[x * this->figure->Y + y];
}

void Figure::rotate() {
	SchemeFigure *newPosition = new SchemeFigure;
	int sizeR = this->figure->X - 1;
	int sizeC = this->figure->Y;
	bool target[DIMENSION][DIMENSION];
	
	for ( int row = sizeR, inx = 0; row > -1; row-- ) {
		for ( int col = 0;  col < sizeC; col++ ) {
			target[col][row] = this->figure->data[inx];
			inx += 1;
		}
	}

	newPosition->X = this->figure->Y;
	newPosition->Y = this->figure->X;

	for ( int col = 0, inx = 0; col < newPosition->X; col++ ) {
		for ( int row = 0; row < newPosition->Y; row++ ) {
			newPosition->data[inx++] = target[col][row];
		}
	}
	delete this->figure;
	this->figure = newPosition;
}

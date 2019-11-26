// Copyright 2018 RoMaleDev. All Rights Reserved.

#pragma once

#include <cstdlib>
#include <ctime>

const int DIMENSION = 7;

typedef struct {
	int X : DIMENSION;
	int Y : DIMENSION;
	bool data[DIMENSION];
} SchemeFigure;

class Figure
{
private:
	const static SchemeFigure stFigure[DIMENSION];
	int random;
	SchemeFigure *figure;
	
public:
	Figure();
    Figure(const Figure& fig);
	~Figure();
	void randomF();
	int readX(bool stat = false) const;
	int readY(bool stat = false) const;
	int readRandom() const;
	bool readData(int x, int y, bool stat = false) const;
	void newFigure();
	void rotate();
};


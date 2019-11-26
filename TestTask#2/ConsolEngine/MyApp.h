// Copyright 2009-2014 Blam Games, Inc. All Rights Reserved.
// Modified 2018 RoMaleDev.

#pragma once

#include <queue>
#include "BaseApp.h"
#include "Figure.h"
#include "Field.h"

class MyApp : public BaseApp
{
	typedef BaseApp Parent;

private:
	const int X_START;
	const int Y_START;
	const int X_LIMIT;
	const int Y_LIMIT;
	const int SPEED;
	int speed;
	int mObj1XOld;
	int mObj1YOld;
	int mObj1X;
	int mObj1Y;

	int mObj2X;
	int mObj2Y;

	bool game_over;
	bool toggle_harvest;
	int toggle2_harvest;
	int cycle;
	int counter;
	int cycle_harvest;
	int score_Int;
	wchar_t score_Wt[10];

	void MakeWindow();
	Figure *figure;
	Field *field;
	std::queue<int> *harvest;

public:
	MyApp();
	void SetText(int x, int y, wchar_t* text);
	void SetFigure(int x, int y, wchar_t text, bool stat = 0);
	void SetField(int start_col, int delta_col, wchar_t text);
	void SetField(int start_col, wchar_t text);
	virtual void KeyPressed(int btnCode);
	virtual void UpdateF(float deltaTime);
	void start_mov_fig();
	bool Obstacles(int X_Obj, int Y_Obj, const Figure& subject);
	bool outOfVerge(int X_Obj, int Y_Obj, const Figure& subject);
	void writeState(int X_Obj, int Y_Obj);
	void markHarvest(int Y_Obj);
};

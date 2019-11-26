// Copyright 2009-2014 Blam Games, Inc. All Rights Reserved.
// Modified 2018 RoMaleDev.

#include <conio.h>
#include "MyApp.h"

void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

MyApp::MyApp() : Parent(50, 25), X_START(2), Y_START(3), X_LIMIT(11), Y_LIMIT(23), SPEED(80), cycle(0), cycle_harvest(0), score_Int(0)
{
	game_over = true;
	toggle_harvest = true;
	toggle2_harvest = 0;
	speed = SPEED;
	figure = new Figure();
	field = new Field();
	this->harvest = new std::queue<int>();
	MakeWindow();
}

void MyApp::SetText(int x, int y, wchar_t* text) {
	for ( int i = 0; text[i]; ) {
		SetChar(i + x, y, text[i++]);
	}
}

void MyApp::SetFigure(int xObj, int yObj, wchar_t text, bool stat) {
	xObj = xObj - figure->readY(stat) / 2;
	yObj = yObj - figure->readX(stat) / 2;
	for ( int x = 0; x < figure->readX(stat); x++ ) {
		for ( int y = 0; y < figure->readY(stat); y++ ) {
			if (figure->readData(x, y, stat)) {
				SetChar(xObj + y, yObj + x, text);
			}
		}
	}
}

void MyApp::SetField(int start_col, int delta_col, wchar_t text) {
	int finish_col = start_col - delta_col;

	for ( int col = start_col; col > finish_col; col-- ) {
		for ( int row = 0; row < ROW; row++ ) {
			wchar_t tex = text * (true & field->read(col, row));
			SetChar(X_START + row, Y_START + col, tex);
		}
	}
}

void MyApp::SetField(int start_col, wchar_t tex) {
	SetField(start_col, start_col + 1, tex);
}

void MyApp::MakeWindow() {
	SetText(1, 1, L"Т Е Т Р И С");
	
	SetChar(1, 2, L'\x2554');
	SetChar(1, 23, L'\x255A');
	SetChar(12, 2, L'\x2557');
	SetChar(12, 23, L'\x255D');

	for ( int i = 3; i < 23; i++ ) {
		SetChar(1, i, L'\x2551');
		SetChar(12, i, L'\x2551');
	}

	for ( int i = 2; i < 12; i++ ) {
		SetChar(i, 2, L'\x2550');
		SetChar(i, 23, L'\x2550');
	}

	SetText(13, 3, L"ОЧКИ:");
	_itow(score_Int, score_Wt, 10);
	SetText(19, 3, score_Wt);
	SetText(13, 5, L"След. фигура");

	SetChar(16, 6, L'\x250C');
	SetChar(16, 11, L'\x2514');
	SetChar(23, 6, L'\x2510');
	SetChar(23, 11, L'\x2518');

	for ( int i = 7; i < 11; i++ ) {
		SetChar(16, i, L'\x2502');
		SetChar(23, i, L'\x2502');
	}

	for ( int i = 17; i < 23; i++ ) {
		SetChar(i, 6, L'\x2500');
		SetChar(i, 11, L'\x2500');
	}

	SetText(19, 13, L"Управление:");
	SetText(13, 14, L"\"s\" - старт");
	SetText(13, 15, L"\"p\" - пауза");
	SetText(13, 16, L"\"a\" - о программе...");
	SetText(13, 17, L"\"\x2190\" - перемещение влево");
	SetText(13, 18, L"\"\x2192\" - перемещение вправо");
	SetText(13, 19, L"\"\x2191\" - поворот по час. стр. на 90\x00B0");
	SetText(13, 20, L"\"\x2193\" - ускорение.");
	SetText(13, 21, L"Для более комфортной игры,");
	SetText(13, 22, L"рекомендую в свойствах \"Окна\"");
	SetText(13, 23, L"установить шрифт 12х16.");
}

void MyApp::start_mov_fig() {
	mObj2X = 20;
	mObj2Y = 9;
	figure->newFigure();
	mObj1XOld = mObj1X = X_START + (X_LIMIT - X_START) / 2;
	mObj1YOld = mObj1Y = Y_START + figure->readX() / 2;
	SetFigure(mObj2X, mObj2Y, L' ', true);
	figure->randomF();
	SetFigure(mObj2X, mObj2Y, L'\x25D8', true);
}

bool MyApp::Obstacles(int X_Obj, int Y_Obj, const Figure& subject) {
    bool toggle = true;
	X_Obj = X_Obj - subject.readY() / 2;
	Y_Obj = Y_Obj - subject.readX() / 2;

	if ( (Y_Obj + subject.readX() - 1) < Y_LIMIT ) {
		toggle = false;

		for ( int x = 0; x < subject.readX() && !toggle; x++ ) {
			for ( int y = 0; y < subject.readY() && !toggle; y++ ) {
				toggle = field->read(Y_Obj - Y_START + x, X_Obj - X_START + y) & subject.readData(x, y);
			}
		} 
	}
	return toggle;
}

bool MyApp::outOfVerge(int X_Obj, int Y_Obj, const Figure& subject) {
	bool toggle = false;
	X_Obj = X_Obj - subject.readY() / 2;
	Y_Obj = Y_Obj - subject.readX() / 2;

	if ( X_Obj < X_START || (X_Obj + subject.readY() - 1) > X_LIMIT || Y_Obj < Y_START ) {
		toggle = true;
	}
	return toggle;
}

void MyApp::KeyPressed(int btnCode)
{
	if ( btnCode == 72 ) // Стрелка вверх
	{
		Figure *fig = new Figure(*figure);	
		fig->rotate();
		if ( Obstacles(mObj1X, mObj1Y, *fig) == 0 && outOfVerge(mObj1X, mObj1Y, *fig) == 0 ) {
			SetFigure(mObj1X, mObj1Y, L' ');
			delete figure;
			figure = fig;
		}
	}
	else if ( btnCode == 80 ) {// Стрелка вниз
		mObj1Y++;
		mObj1Y -= Obstacles(mObj1X, mObj1Y, *figure);
	}
	else if ( btnCode == 75 ) { // Стрелка влево
		mObj1X--;
		mObj1X += outOfVerge(mObj1X, mObj1Y, *figure); 
		mObj1X += Obstacles(mObj1X, mObj1Y, *figure);
	}
	else if ( btnCode == 77 ) { // Стрелка вправо
		mObj1X++;
		mObj1X -= outOfVerge(mObj1X, mObj1Y, *figure);
		mObj1X -= Obstacles(mObj1X, mObj1Y, *figure);
	} 
	else if ( btnCode == 115 ) {//s
		if (game_over) {
			counter = 0;
			score_Int = 0;
			_itow(score_Int, score_Wt, 10);
			SetText(19, 3, L"          ");
			SetText(19, 3, score_Wt);
			speed = SPEED;
			field->clear();
			SetField(19, L' ');
			start_mov_fig();
		}
		game_over = false;
	}
	else if ( btnCode == 112 ) {//p
		gotoxy(4, 12);
		cputs("PAUSE!");
		
		for ( ; getch() != 112; ) ;	
	}
	else if ( btnCode == 97 ) {//a
		MessageBox(NULL, L"Программа - Тестовое задание\n         для Blam Games, Inc.\n\nПрограмма: T E T R I S\n\nРазработал: RoMaleDev\nВерсия:          0.0.100500", L"O Программе...", MB_OK);
	}
}

void MyApp::UpdateF(float deltaTime)
{
	if ( !game_over ) {
		SetFigure(mObj1XOld, mObj1YOld, L' ');
		if ( cycle == speed ) {
			mObj1Y += 1;

			if ( Obstacles(mObj1X, mObj1Y, *figure) ) {
				mObj1Y -= 1;
				SetFigure(mObj1X, mObj1Y, L'\x25D8');
				writeState(mObj1X, mObj1Y);
				markHarvest(mObj1Y);
				start_mov_fig();
				if ( Obstacles(mObj1X, mObj1Y, *figure) ) {
					SetText(1, 12, L"GAME OVER!");
					game_over = true;
				}
			}
			cycle = 0;
		}

		if ( harvest->size() > 0 ) {
			if ( toggle_harvest ) {
				SetField(harvest->front() + toggle2_harvest, 1, L'\x2022');
				field->deleteRow(harvest->front() + toggle2_harvest);
				toggle_harvest = false;
			}
			if ( cycle_harvest == 5 ){
				SetField(harvest->front() + toggle2_harvest, L'\x25D8');
				score_Int += 10;
				counter += 1;
				if ( counter == 10 ) {
					speed -= 5;
					counter = 0;
				}
				_itow(score_Int, score_Wt, 10);
				SetText(19, 3, score_Wt);
				toggle2_harvest += 1;
				harvest->pop();
				if ( harvest->size() == 0 ) {
					toggle2_harvest = 0;
				}
				cycle_harvest = 0;
				toggle_harvest = true;
			}
			cycle_harvest += 1;
		}

		SetFigure(mObj1X, mObj1Y, L'\x25D8');

		mObj1XOld = mObj1X;
		mObj1YOld = mObj1Y;
		cycle += 1;
		Sleep(5);
	}
}

void MyApp::writeState(int X_Obj, int Y_Obj) {
	X_Obj = X_Obj - figure->readY() / 2;
	Y_Obj = Y_Obj - figure->readX() / 2;

	for ( int x = 0; x < figure->readX(); x++ ) {
		for ( int y = 0; y < figure->readY(); y++ ) {
			field->write(Y_Obj - Y_START + x, X_Obj - X_START + y, (field->read(Y_Obj - Y_START + x, X_Obj - X_START + y) ^ figure->readData(x, y)));
		}
	}
}

void MyApp::markHarvest(int Y_Obj){
	int Y_s = Y_Obj - figure->readX() / 2 - Y_START;
	int Y_f = Y_s + figure->readX() - 1;
	int total = 0;

	for ( int y = Y_f; y >= Y_s; y-- ) {
		for ( int x = 0; x < ROW; x++ ) {
			total += field->read(y, x);
		}
		if ( total == ROW ) {
			harvest->push(y);
		}
		total = 0;
	}
}
#pragma once
#include"mylib.h"



#include <iostream>
#include <windows.h>
using namespace std;

void resize() {
	HWND console = GetConsoleWindow();
	RECT ConsoleRect;
	GetWindowRect(console, &ConsoleRect);

	MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 1200, 650, TRUE);

	//system("pause");
}
// ---- ve khung ------
void veTuong() 
{
	int x = 10, y = 1;
	while (x < 110) { // tuong tren
		gotoxy(x, y);
		cout << ".";
		x++;
		Sleep(10);

	}
	while (y < 28) { // tuong ben phai
		gotoxy(x, y);
		cout << ".";
		y++;
		Sleep(10);

	}
	while (x > 9) {// tuong ben duoi
		gotoxy(x, y);
		cout << ".";
		x--;
		Sleep(10);

	}
	while (y > 0) { // tuong ben trai
		gotoxy(x, y);
		cout << ".";
		y--;
		Sleep(10);

	}


}


// xoa con tro
void xoacontro()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

// Hightlight
void HightLight() {
	SetColor(15);
	SetBGColor(2);
}

// normal 
void Normal() {
	SetColor(15);
	SetBGColor(0);
}

void menu() {
	const int dong = 20;
	const int cot = 0;
	string mang[4] = { "1. Nhap ten doc gia", "2. Xoa the doc gia" };
	Normal();
	system("cls");

	int lua_chon = 0;
	// in lua chon ra
	for (int i = 0; i < 4; i++) {
		gotoxy(20, cot + i);
		cout << mang[i] << endl;
	}
	HightLight();
	gotoxy(dong, lua_chon);
	cout << mang[lua_chon];

}
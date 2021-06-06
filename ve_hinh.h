#pragma once

#include"mylib.h"
#include<iostream>
#include"Variable_Global.h"
#include"fstream"

using namespace std;

// xoa con tro
void xoacontro()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

void resize() {
	HWND console = GetConsoleWindow();
	RECT ConsoleRect;
	GetWindowRect(console, &ConsoleRect);

	MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 1200, 650, TRUE);

	//system("pause");
}

// Hightlight
void HightLight_pink() {
	SetColor(15);
	SetBGColor(12);
}
void HightLight_YELLOW() {
	SetColor(15);
	SetBGColor(6);
}
void HightLight() {
	SetColor(15);
	SetBGColor(2);
}
void HightLightDong(int x)
{
	SetColor(15);
	SetBGColor(x);
}
//
void Hight_text_pink()
{
	SetColor(12);
	SetBGColor(0);
}
void Hight_text_yellow()
{
	SetColor(14);
	SetBGColor(0);
}
void Hight_text_red()
{
	SetColor(20);
	SetBGColor(0);
}
void Hight_text_dong(int color)
{
	SetColor(color);
	SetBGColor(0);
}
//
// normal 
void Normal() {
	SetColor(15);
	SetBGColor(0);
}


////// ---- ve khung basic ------
void ve_khung_basic()
{
	int cot = 3, dong = 3;
	while (cot < 141) { // tuong tren
		gotoxy(cot, dong);
		HightLight();

		cout << " ";
		cot++;
	}
	while (dong < 35) { // tuong ben phai
		gotoxy(cot, dong);
		HightLight();

		cout << " ";
		dong++;

	}
	while (cot >= 3) {// tuong ben duoi
		gotoxy(cot, dong);
		HightLight();

		cout << " ";
		cot--;

	}
	while (dong >= 3) { // tuong ben trai
		gotoxy(cot, dong);
		HightLight();

		cout << " ";
		dong--;

	}
}

////// ---- ve khung basic ------
void ve_khung_basic_dong(int& cot, int& dong, int& x1, int& x2, int& y1, int& y2, string kt1, string kt2, int color)
{
	// cot = 55, dong = 13
	// x1 = 55+40; y1 = 13+10
	while (cot < x1) { // tuong tren
		gotoxy(cot, dong);
		HightLightDong(color);

		cout << kt1;
		cot++;
	}
	while (dong < y1) { // tuong ben phai
		gotoxy(cot, dong);
		HightLightDong(color);

		cout << kt2;
		dong++;

	}
	while (cot >= x2) {// tuong ben duoi
		gotoxy(cot, dong);
		HightLightDong(color);

		cout << kt1;
		cot--;

	}
	while (dong >= y2) { // tuong ben trai
		gotoxy(cot, dong);
		HightLightDong(color);

		cout << kt2;
		dong--;

	}
}


void ve_khung_basic_pink()
{
	//x cot - y dong
	int x = 3, y = 3;
	while (x < 141) { // tuong tren
		gotoxy(x, y);
		HightLight_pink();

		cout << " ";
		x++;
	}
	while (y < 35) { // tuong ben phai
		gotoxy(x, y);
		HightLight_pink();

		cout << " ";
		y++;

	}
	while (x >= 4) {// tuong ben duoi
		gotoxy(x, y);
		HightLight_pink();

		cout << " ";
		x--;

	}
	while (y >= 3) { // tuong ben trai
		gotoxy(x, y);
		HightLight_pink();

		cout << " ";
		y--;

	}
}

void ve_khung_basic_yellow()
{
	//x cot - y dong
	int x = 3, y = 3;
	while (x < 141) { // tuong tren
		gotoxy(x, y);
		HightLight_YELLOW();

		cout << " ";
		x++;
	}
	while (y < 35) { // tuong ben phai
		gotoxy(x, y);
		HightLight_YELLOW();

		cout << " ";
		y++;

	}
	while (x >= 4) {// tuong ben duoi
		gotoxy(x, y);
		HightLight_YELLOW();

		cout << " ";
		x--;

	}
	while (y >= 3) { // tuong ben trai
		gotoxy(x, y);
		HightLight_YELLOW();

		cout << " ";
		y--;

	}
}


// ve khung menu gioi thieu
void veTuong_Menu_Chinh()
{
	//x cot - y dong
	int x = 0, y = 0;
	while (x < 144) { // tuong tren
		gotoxy(x, y);
		HightLightDong(20);

		cout << " ";
		x++;
	}
	while (y < 38) { // tuong ben phai
		gotoxy(x, y);
		HightLightDong(20);

		cout << " ";
		y++;

	}
	while (x >= 1) {// tuong ben duoi
		gotoxy(x, y);
		HightLightDong(20);

		cout << " ";
		x--;

	}
	while (y >= 0) { // tuong ben trai
		gotoxy(x, y);
		HightLightDong(20);

		cout << " ";
		y--;

	}

	// ----
	//y = 0;
	//x = 45;
	//while (y < 38)
	//{

	//	gotoxy(x, y);
	//	HightLightDong(20);

	//	cout << " ";
	//	y++;
	//}
}

void Intro()
{
	int cot = 60, dong = 20;
	gotoxy(cot, dong);
	Normal();
	cout << "HO TEN : " << "NGO VAN VIET";
	gotoxy(cot, dong+2);
	Normal();
	cout << "LOP    : " << "D15CQDT02N";
	gotoxy(cot, dong+4);
	Normal();
	cout << "MSSV   : " << "N15DCDT080";
	gotoxy(63, dong + 15);
	HightLight_pink();
	cout << "   ENTER   ";
	Normal();
}
void Ten_De_Tai()
{
	fstream f;
	f.open("QuanLyThuVien.txt", ios::in);
	string data;
	if (f.fail() == true)
	{
		cout << "file not exis";
	}
	else
	{
		int i = 8;
		while (f.eof() != true)
		{
			gotoxy(30, i);
			//Hight_text_pink();
			SetColor(i);
			getline(f, data);
			cout << data;
			i++;
		}
		xoacontro();
		f.close();
	}
	}

int INTRODUCE()
{
	system("cls");
	resize();
	veTuong_Menu_Chinh();
	Intro();
	Ten_De_Tai();
	char kytu;
	bool check = true;
	do
	{
		kytu = _getch();
		if (kytu == -32)
		{
			kytu = _getch();
		}
		switch (kytu)
		{
			case Enterr:
			{
				check = false;
				break;
			}		
		}  
	} while (check);
	return 0;
}
// chon menu chinh => hightlight green

// bam nut de exit
void Bam_Nut_Exit()
{
	char kytu;
	bool check = true;
	do
	{
		kytu = _getch();
		if (kytu == -32)
		{
			kytu = _getch();
		}
		switch (kytu)
		{
		case Enterr:
		{
			check = false;
			break;
		}
		}
	} while (check);
}

int MENU_main()
{
	Normal();
	system("cls");
	ve_khung_basic();
	//
	int cot_ = 53; // star tuong tren
	int x1 = 53 + 35; // cd tuong tren

	int dong_ = 15; // star tuong phai
	int y1 = 9 + 15; // cd ben phai

	int x2 = 53; // cd tuong duoi
	int y2 = 15;  //  cd ben trai
	ve_khung_basic_dong(cot_, dong_, x1, x2, y1, y2, " ", " ", 5);
	//
	Normal();
	int chon_menu_main = 0;
	int cot = 60;
	int dong = 18;
	for (int i = 0; i < So_item_MENU; i++)
	{
		gotoxy(cot, dong + i);
		cout << MENU[i];
	}
	HightLight();
	gotoxy(cot, dong + chon_menu_main);
	cout << MENU[chon_menu_main];

	 //kiem tra phim nhan
	char kytu;
	do 
	{
		kytu = _getch();
		if (kytu == -32) kytu = _getch();
		switch (kytu) {
		case Up:
		{
			if (chon_menu_main > 0)
			{
				Normal();
				gotoxy(cot, dong + chon_menu_main);
				cout << MENU[chon_menu_main];
				chon_menu_main--;
				HightLight();
				gotoxy(cot, dong + chon_menu_main);
				cout << MENU[chon_menu_main];
			}
			break;
		}
		case Down:
		{
			if (chon_menu_main + 1 < So_item_MENU)
			{
				Normal();
				gotoxy(cot, dong + chon_menu_main);
				cout << MENU[chon_menu_main];
				chon_menu_main++;
				HightLight();
				gotoxy(cot, dong + chon_menu_main);
				cout << MENU[chon_menu_main];
			}
			break;
		}
		case Enterr: 
		{
			return chon_menu_main;
		}
		}  // end switch
	} while (1);
	/*return 0;*/
}


// -----......................        chon menu the doc gia => hight pink        -----...............
int MENU_tdg()
{
	Normal();
	system("cls");
	ve_khung_basic_pink();
	int chon_menu = 0;
	int cot = 53; // star tuong tren
	int x1 = 53+42; // cd tuong tren

	int dong = 11; // star tuong phai
	int y1 = 13+11; // cd ben phai

	int x2 = 53; // cd tuong duoi
	int y2 = 11;  //  cd ben trai

	// ve khung
	Normal();
	ve_khung_basic_dong(cot, dong, x1, x2, y1, y2," "," ",5);

	 cot = 55;
	 dong = 13;
	for (int i = 0; i < So_item_MENU_DG; i++)
	{
		gotoxy(cot, dong + i);
		Normal();
		cout << MENU_DG[i];
	}



	HightLight_pink();
	gotoxy(cot, dong + chon_menu);
	cout << MENU_DG[chon_menu];

	//kiem tra phim nhan
	char kytu;
	do
	{
		kytu = _getch();
		if (kytu == -32) kytu = _getch();
		switch (kytu) {
		case Up:
		{
			if (chon_menu > 0)
			{
				Normal();
				gotoxy(cot, dong + chon_menu);
				cout << MENU_DG[chon_menu];
				chon_menu--;
				HightLight_pink();
				gotoxy(cot, dong + chon_menu);
				cout << MENU_DG[chon_menu];
			}
			break;
		}
		case Down:
		{
			if (chon_menu + 1 < So_item_MENU_DG)
			{
				Normal();
				gotoxy(cot, dong + chon_menu);
				cout << MENU_DG[chon_menu];
				chon_menu++;
				HightLight_pink();
				gotoxy(cot, dong + chon_menu);
				cout << MENU_DG[chon_menu];
			}
			break;
		}
		case Enterr:
		{
			return chon_menu;
		}
		}  // end switch
	} while (1);
	//return 0;
}

// tu trai qua
int Ve_Duong_Thang_Ngang(int cot_1,int dong_1,int cot_2, string kitu, int color)
{
	while (cot_1 < cot_2) { // tuong tren
		gotoxy(cot_1, dong_1);
		//Hight_text_pink();
		Hight_text_dong(color);
		cout << kitu;
		cot_1++;
	}
	return 0;
}

// tu tren xuong
int Ve_Duong_Thang_Doc(int dong_1, int cot_1, int dong_2, string kitu, int color)
{
	while (dong_1 < dong_2) { // tuong tren
		gotoxy(cot_1, dong_1);
		Hight_text_dong(color);

		cout << kitu;
		dong_1++;
	}
	return 0;
}

void Ve_Khung_Xuat_TDG()
{
	Normal();
	system("cls");
	ve_khung_basic_pink();
	//ve tuong ngang
	int c1 = 4, d1=6,c2=141;
	Ve_Duong_Thang_Ngang(c1, d1, c2, "_", 12);
	Ve_Duong_Thang_Ngang(c1, d1 + 25, c2, "_", 12);

	// ve tuong doc
	int d = 4, d2 = 32;
	Ve_Duong_Thang_Doc(d,c1 + 20,d2,"|",12);
	Ve_Duong_Thang_Doc(d, c1 + 45, d2, "|",12);
	Ve_Duong_Thang_Doc(d, c1 + 85, d2, "|",12);
	Ve_Duong_Thang_Doc(d, c1 + 110, d2, "|",12);

	//
	// ma the
	Hight_text_red();
	int cot_1 = 10, dong_1 = 5;
	gotoxy(cot_1, dong_1);
	cout << "MA THE";
	//pre
	//gotoxy(cot_1, dong_1+28);
	////Normal();
	//cout << "   PRE   ";
	Hight_text_red();

	// ho
	gotoxy(cot_1 + 26 , dong_1);
	cout << "HO";
	// ten
	gotoxy(cot_1 + 57, dong_1);
	cout << "TEN";
	// exit
	//gotoxy(cot_1 + 57, dong_1 + 28);
	//HightLight_pink();
	//cout << "   EXIT   ";

	Hight_text_red();
	// phai
	gotoxy(cot_1 + 90, dong_1);
	cout << "PHAI";
	//trang thai
	gotoxy(cot_1 + 113, dong_1);
	cout << "TRANG THAI";
	//
	//NEXT
	//gotoxy(cot_1 + 113, dong_1 + 28);
	//Hight_text_red();
	//cout << "   NEXT   ";
}

// check left right cho nhap the doc gia
int Check_Left_Right(int& check)
{
	int cot = 40, dong = 8;
	char kytu;
	do
	{
		kytu = _getch();
		if (kytu == -32) kytu = _getch();
		switch (kytu) {
		case Left:
		{
			check = 0;
			//
			gotoxy(cot + 10, dong + 20);
			HightLight_pink();
			cout << "   tiep tuc   ";
			//
			gotoxy(cot + 40, dong + 20);
			Normal();
			cout << "    thoat     ";
			break;
		}
		case Right:
		{
			check = 1;
			//
			gotoxy(cot + 10, dong + 20);
			Normal();
			cout << "   tiep tuc   ";
			//
			gotoxy(cot + 40, dong + 20);
			HightLight_pink();
			cout << "    thoat     ";
			break;
		}
		case Enterr:
		{
			return check;
		}
		}  // end switch
	} while (1);
}

int Check_Left_Right_MUONSACH(int& check)
{
	int cot = 40, dong = 8;
	char kytu;
	do
	{
		kytu = _getch();
		if (kytu == -32) kytu = _getch();
		switch (kytu) {
		case Left:
		{
			check = 0;
			//
			gotoxy(cot + 10, dong + 25);
			HightLight_pink();
			cout << "   MUON SACH   ";
			//
			gotoxy(cot + 40, dong + 25);
			Normal();
			cout << "    THOAT     ";
			break;
		}
		case Right:
		{
			check = 1;
			//
			gotoxy(cot + 10, dong + 25);
			Normal();
			cout << "   MUON SACH   ";
			//
			gotoxy(cot + 40, dong + 25);
			HightLight_pink();
			cout << "    THOAT     ";
			break;
		}
		case Enterr:
		{
			return check;
		}
		}  // end switch
	} while (1);
}
int Check_Left_Mid_Right(int& check)
{
	int cot_1 = 10, dong_1 = 5+28;
	char kytu;
	const int so_pt = 3;
	string mang[so_pt] =
	{
		"   PRE   ",
		"   EXIT   ",
		"   NEXT   "
	};
	int mang_cot[so_pt] = { cot_1, cot_1 + 57, cot_1 + 113 };

	// ghi thuong cac lua chon
	for (int i = 0; i < so_pt; i++)
	{
		gotoxy(mang_cot[i], dong_1);
		Hight_text_red();
		cout << mang[i];
	}
	// hightlight nut exit - gia tri check ban dau = 1
	HightLight_pink();
	gotoxy(mang_cot[check], dong_1);
	cout << mang[check];
	do
	{
		// fist : dang o nut exit
		//fflush(stdin)
		kytu = _getch();
		if (kytu == -32) kytu = _getch();
		switch (kytu) {
		case Left: // nut pre sang
		{
			if (check > 0)
			{
				// bo hightligt vi tri ban dau
				gotoxy(mang_cot[check], dong_1);
				Hight_text_red();
				cout << mang[check];
				// hight light vi tri chon moi
				check--;
				gotoxy(mang_cot[check], dong_1);
				HightLight_pink();
				cout << mang[check];
			}
			break;
		}
		case Right:
		{
			if (check < so_pt-1)
			{
				// bo hightligt vi tri ban dau
				gotoxy(mang_cot[check], dong_1);
				Hight_text_red();
				cout << mang[check];
				// hight light vi tri chon moi
				check++;
				gotoxy(mang_cot[check], dong_1);
				HightLight_pink();
				cout << mang[check];
			}
			break;
		}
		case Enterr:
		{
			return check;
		}
		}  // end switch
	} while (1);
}
// dong bo vi tri voi ham CHECK LMR
int Check_Left_Right_TEXT_DONG(int& check, string txt1, string txt2)
{
	int cot = 10, dong = 5 + 28;
	char kytu;
	do
	{
		kytu = _getch();
		if (kytu == -32) kytu = _getch();
		switch (kytu) {
		case Left:
		{
			check = 0;
			//
			gotoxy(cot, dong);
			HightLight_pink();
			cout << txt1;
			//
			gotoxy(cot + 113, dong);
			Normal();
			cout << txt2;
			break;
		}
		case Right:
		{
			check = 2;
			//
			gotoxy(cot, dong);
			Normal();
			cout << txt1;
			//
			gotoxy(cot+113, dong);
			HightLight_pink();
			cout << txt2;
			break;
		}
		case Enterr:
		{
			return check;
		}
		}  // end switch
	} while (1);
}

void Ve_Khung_Xuat_Mot_Doc_Gia(int color)
{
	Normal();
	system("cls");
	ve_khung_basic_pink();
	//ve tuong ngang
	int c1 = 4, d1 = 6, c2 = 141;
	Ve_Duong_Thang_Ngang(c1, d1, c2, "_", color);
	Ve_Duong_Thang_Ngang(c1, d1 + 3, c2, "_", color);

	// ve tuong doc
	int d = 4, d2 = 10;
	Ve_Duong_Thang_Doc(d, c1 + 20, d2, "|", color);
	Ve_Duong_Thang_Doc(d, c1 + 45, d2, "|", color);
	Ve_Duong_Thang_Doc(d, c1 + 85, d2, "|", color);
	Ve_Duong_Thang_Doc(d, c1 + 110, d2, "|", color);

	//
	// ma the
	Hight_text_red();
	int cot_1 = 10, dong_1 = 5;
	gotoxy(cot_1, dong_1);
	cout << "MA THE";
	//pre
	//gotoxy(cot_1, dong_1+28);
	////Normal();
	//cout << "   PRE   ";
	Hight_text_red();

	// ho
	gotoxy(cot_1 + 26, dong_1);
	cout << "HO";
	// ten
	gotoxy(cot_1 + 57, dong_1);
	cout << "TEN";
	// exit
	//gotoxy(cot_1 + 57, dong_1 + 28);
	//HightLight_pink();
	//cout << "   EXIT   ";

	Hight_text_red();
	// phai
	gotoxy(cot_1 + 90, dong_1);
	cout << "PHAI";
	//trang thai
	gotoxy(cot_1 + 113, dong_1);
	cout << "TRANG THAI";
	//
	//NEXT
	//gotoxy(cot_1 + 113, dong_1 + 28);
	//Hight_text_red();
	//cout << "   NEXT   ";
}

void Ve_Khung_Xuat_Doc_Gia_Muon_Qua_Han(int color)
{
	Normal();
	system("cls");
	ve_khung_basic_pink();
	//ve tuong ngang
	int c1 = 4, d1 = 6, c2 = 141;
	Ve_Duong_Thang_Ngang(c1, d1, c2, "_", color);
	Ve_Duong_Thang_Ngang(c1, d1 + 25, c2, "_", color);

	// ve tuong doc
	int d = 4, d2 = 32;
	Ve_Duong_Thang_Doc(d, c1 + 13, d2, "|", color);
	Ve_Duong_Thang_Doc(d, c1 + 30, d2, "|", color);
	Ve_Duong_Thang_Doc(d, c1 + 55, d2, "|", color);
	Ve_Duong_Thang_Doc(d, c1 + 65, d2, "|", color);
	Ve_Duong_Thang_Doc(d, c1 + 95, d2, "|", color);
	Ve_Duong_Thang_Doc(d, c1 + 125, d2, "|", color);

	//
	// ma the
	Hight_text_red();
	int cot_1 = 7, dong_1 = 5;
	gotoxy(cot_1, dong_1);
	cout << "MA THE";
	//pre
	//gotoxy(cot_1, dong_1+28);
	////Normal();
	//cout << "   PRE   ";
	Hight_text_red();

	// ho
	gotoxy(cot_1 + 17, dong_1);
	cout << "HO";
	// ten
	gotoxy(cot_1 + 37, dong_1);
	cout << "TEN";
	// exit


	Hight_text_red();
	// phai
	gotoxy(cot_1 + 54, dong_1);
	cout << "MA SACH";
	//trang thai
	gotoxy(cot_1 + 73, dong_1);
	cout << "TEN SACH";
	gotoxy(cot_1 + 103, dong_1);
	cout << "NGAY MUON";
	gotoxy(cot_1 + 125, dong_1);
	cout << "SO NGAY";
	//

}
// danh sach muon tra cua doc gia
void Ve_Khung_Xuat_Danh_Sach_MT_Cua_Mot_DG()
{
	// khung 1 dau sach cua danh muc sach
	Ve_Khung_Xuat_Mot_Doc_Gia(12);

	// khung cua danh muc sach 
	Normal();
	//system("cls");
	ve_khung_basic_pink();
	//ve tuong ngang
	int c1 = 4, d1 = 12, c2 = 141;
	Ve_Duong_Thang_Ngang(c1, d1, c2, "_", 12);
	Ve_Duong_Thang_Ngang(c1, d1 + 3, c2, "_", 12);
	Ve_Duong_Thang_Ngang(c1, d1 + 19, c2, "_", 12);


	// ve tuong doc
	// ve tuong doc
	int d = 13, d2 = 32;
	Ve_Duong_Thang_Doc(d, c1 + 15, d2, "|", 12);
	Ve_Duong_Thang_Doc(d, c1 + 30, d2, "|", 12);
	Ve_Duong_Thang_Doc(d, c1 + 48, d2, "|", 12);
	Ve_Duong_Thang_Doc(d, c1 + 73, d2, "|", 12);
	Ve_Duong_Thang_Doc(d, c1 + 110, d2, "|", 12);


	// ghi tieu de
	// ma ISBN
	Hight_text_dong(6);
	int cot_1 = 9, dong_1 = 14;
	gotoxy(cot_1, dong_1);
	cout << "MA TDG";

	// MA SACH
	gotoxy(cot_1 + 14, dong_1);
	cout << "MA ISBN";

	gotoxy(cot_1 + 30, dong_1);
	cout << "MA SACH";

	gotoxy(cot_1 + 51, dong_1);
	cout << "TRANG THAI";

	gotoxy(cot_1 + 83, dong_1);
	cout << "NGAY MUON";
	gotoxy(cot_1 + 115, dong_1);
	cout << "NGAY TRA";
}
//----------------------------------------------------------------------------------------------
// ...............  chon menu dau sach .......................
int MENU_ds()
{
	Normal();
	system("cls");
	ve_khung_basic_yellow();
	int cot_ = 53; // star tuong tren
	int x1 = 53 + 35; // cd tuong tren

	int dong_ = 11; // star tuong phai
	int y1 = 12 + 11; // cd ben phai

	int x2 = 53; // cd tuong duoi
	int y2 = 11;  //  cd ben trai
	ve_khung_basic_dong(cot_, dong_, x1, x2, y1, y2, " ", " ",5);

	Normal();
	int chon_menu = 0;
	int cot = 55;
	int dong = 13;
	for (int i = 0; i < So_item_MENU_DS; i++)
	{
		gotoxy(cot, dong + i);
		cout << MENU_DS[i];
	}
	HightLight_YELLOW();
	gotoxy(cot, dong + chon_menu);
	cout << MENU_DS[chon_menu];

	//kiem tra phim nhan
	char kytu;
	do
	{
		kytu = _getch();
		if (kytu == -32) kytu = _getch();
		switch (kytu) {
		case Up:
		{
			if (chon_menu > 0)
			{
				Normal();
				gotoxy(cot, dong + chon_menu);
				cout << MENU_DS[chon_menu];
				chon_menu--;
				HightLight_YELLOW();
				gotoxy(cot, dong + chon_menu);
				cout << MENU_DS[chon_menu];
			}
			break;
		}
		case Down:
		{
			if (chon_menu + 1 < So_item_MENU_DS)
			{
				Normal();
				gotoxy(cot, dong + chon_menu);
				cout << MENU_DS[chon_menu];
				chon_menu++;
				HightLight_YELLOW();
				gotoxy(cot, dong + chon_menu);
				cout << MENU_DS[chon_menu];
			}
			break;
		}
		case Enterr:
		{
			return chon_menu;
		}
		}  // end switch
	} while (1);
	return 0;
}

void Ve_Khung_Xuat_Dau_Sach()
{
	Normal();
	system("cls");
	ve_khung_basic_yellow();
	//ve tuong ngang
	int c1 = 4, d1 = 6, c2 = 141;
	Ve_Duong_Thang_Ngang(c1, d1, c2, "_",6);
	Ve_Duong_Thang_Ngang(c1, d1 + 25, c2, "_",6);

	// ve tuong doc
	int d = 4, d2 = 32;
	Ve_Duong_Thang_Doc(d, c1 + 15, d2, "|",6);
	Ve_Duong_Thang_Doc(d, c1 + 50, d2, "|",6);
	Ve_Duong_Thang_Doc(d, c1 + 65, d2, "|",6);
	Ve_Duong_Thang_Doc(d, c1 + 95, d2, "|",6);
	Ve_Duong_Thang_Doc(d, c1 + 120, d2, "|",6);


	//
	// ma ISBN
	Hight_text_dong(6);
	int cot_1 = 9, dong_1 = 5;
	gotoxy(cot_1, dong_1);
	cout << "ISBN";

	// ho
	gotoxy(cot_1 + 24, dong_1);
	cout << "TEN SACH";
	// ten
	gotoxy(cot_1 + 49, dong_1);
	cout << "SO TRANG";

	// phai
	gotoxy(cot_1 + 72, dong_1);
	cout << "TAC GIA";
	//trang thai
	gotoxy(cot_1 + 99, dong_1);
	cout << "THE LOAI";
//
	gotoxy(cot_1 + 122, dong_1);
	cout << "NXB";
}

// danh muc sach
void Ve_Khung_Xuat_Mot_Dau_Sach()
{
	Normal();
	system("cls");
	ve_khung_basic_yellow();
	//ve tuong ngang
	int c1 = 4, d1 = 6, c2 = 141;
	Ve_Duong_Thang_Ngang(c1, d1, c2, "_", 6);
	Ve_Duong_Thang_Ngang(c1, d1 + 4, c2, "_", 6);

	// ve tuong doc
	int d = 4, d2 = 11;
	Ve_Duong_Thang_Doc(d, c1 + 15, d2, "|", 6);
	Ve_Duong_Thang_Doc(d, c1 + 50, d2, "|", 6);
	Ve_Duong_Thang_Doc(d, c1 + 65, d2, "|", 6);
	Ve_Duong_Thang_Doc(d, c1 + 95, d2, "|", 6);
	Ve_Duong_Thang_Doc(d, c1 + 120, d2, "|", 6);


	//
	// ma ISBN
	Hight_text_dong(6);
	int cot_1 = 9, dong_1 = 5;
	gotoxy(cot_1, dong_1);
	cout << "ISBN";

	// ho
	gotoxy(cot_1 + 24, dong_1);
	cout << "TEN SACH";
	// ten
	gotoxy(cot_1 + 49, dong_1);
	cout << "SO TRANG";

	// phai
	gotoxy(cot_1 + 72, dong_1);
	cout << "TAC GIA";
	//trang thai
	gotoxy(cot_1 + 99, dong_1);
	cout << "THE LOAI";
	//
	gotoxy(cot_1 + 122, dong_1);
	cout << "NXB";
}

void Ve_Khung_Xuat_Danh_Muc_Sach_Cua_Dau_Sach()
{
	// khung 1 dau sach cua danh muc sach
	Ve_Khung_Xuat_Mot_Dau_Sach();

	// khung cua danh muc sach 
	Normal();
	//system("cls");
	ve_khung_basic_yellow();
	//ve tuong ngang
	int c1 = 4, d1 = 12, c2 = 141;
	Ve_Duong_Thang_Ngang(c1, d1, c2, "_", 6);
	Ve_Duong_Thang_Ngang(c1, d1+3, c2, "_", 6);
	Ve_Duong_Thang_Ngang(c1, d1 + 19, c2, "_", 6);


	// ve tuong doc
	int  d2 = 32;
	Ve_Duong_Thang_Doc(d1+1, c1 + 15, d2, "|", 6);
	Ve_Duong_Thang_Doc(d1+1, c1 + 35, d2, "|", 6);
	Ve_Duong_Thang_Doc(d1+1, c1 + 65, d2, "|", 6);


	// ghi tieu de
	// ma ISBN
	Hight_text_dong(6);
	int cot_1 = 9, dong_1 = 14;
	gotoxy(cot_1, dong_1);
	cout << "ISBN";

	// MA SACH
	gotoxy(cot_1 + 17, dong_1);
	cout << "MA SACH";
	// TRANG THAI
	gotoxy(cot_1 + 40, dong_1);
	cout << "TRANG THAI";

	// VI TRI
	gotoxy(cot_1 + 92, dong_1);
	cout << "VI TRI";	
}
//--------------------------------------------------------------------------
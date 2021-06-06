#pragma once
#include<string>
#include<iostream>

using namespace std;
// corlor 
//5- tim
//2 - mau xanh la
//6 - mau vang
//7-mau rang
//20 - mau do
//12-pink


// dau sach
const int Up = 72;
const int Down = 80;
const int Left = 75;
const int Right = 77;

const int Enterr = 13;
const int So_item_MENU = 3;
const int So_item_MENU_DG = 10;
const int So_item_MENU_DS = 9;


//const int dong = 1;
//const int cot = 0;



string MENU[So_item_MENU] = 
{
	"   QUAN LY DOC GIA    ",
	"   QUAN LY DAU SACH   ",
	"   EXIT               "
};
string MENU_DG[So_item_MENU_DG] = 
{	//ngang = 38 ; doc = 10
	// the doc gia
	"   THEM THE DOC GIA                   ",
	"   XOA THE DOC GIA                    ",
	"   HIEU CHINH THE DOC GIA             ",
	"   IN THE DOC GIA THEO MA TANG DAN    ",
	"   IN THE DOC GIA THEO TEN TANG DAN   ",
	// danh sach muon tra
	"   IN CAC SACH DA MUON CUA DOC GIA    ",
	"   IN THE DOC GIA MUON SACH QUA HAN   ",
	"   MUON SACH                          ",
	"   TRA SACH                           ",
	"   EXIT                               "
};

string MENU_DS[So_item_MENU_DS] = {
	// dau sach
	"   THEM DAU SACH               ",
	"   TIM THONG TIN DAU SACH      ",
	"   IN DAU SACH THEO THE LOAI   ",
	"   XOA DAU SACH                ",
	"   SUA THONG TIN DAU SACH      ",

	// danh muc sach
	"   THEM DANH MUC SACH          ",
	"   XUAT DANH MUC SACH          ",
	"   XOA MA SACH                 ",
	"   EXIT                        "
};
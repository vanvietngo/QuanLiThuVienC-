#pragma once

#include<iostream>
#include<string>
#include <windows.h>
#include <sstream>
#include<fstream>

using namespace std;

// ----------------------------------- DANH MUC SACH --------------------------------------
//- Danh mục sách : danh sách liên kết đơn(Mã sách, trạng thái, vị trí).
//				  Mỗi cuốn sách chỉ có 1 mã duy nhất; 
//				  trạng thái của sách bao gồm : 0 : cho mượn được, 
//												1 : đã có độc giả mượn, 
//	
struct d_m_s {
	string Ma_Sach;
	int Trang_Thai = 0;
	string Vi_Tri;
	// con tro pnext;
	d_m_s* pNext = NULL;
};
typedef struct d_m_s* DMS;

struct ds_d_m_s {
	int So_Luong = 0;
	DMS pHead = NULL; // con tro dms
};
typedef struct ds_d_m_s DS_DMS;



//-------------------------------------------------------------------------------------------


// ------------------------------  DAU SACH -------------------------------------
const int Max = 100;

//- Đầu sách : danh sách tuyến tính là 1 mảng con trỏ(ISBN(C6), 
//			Tên sách, 
//			Số trang, 
//			Tác giả, 
//			năm xuất bản, 
//			thể loại, 
//			con trỏ dms) : con trỏ sẽ trỏ đến các sách thuộc đầu sách tương ứng


struct dau_sach {
	string ISBN;
	string Ten_Sach;
	int So_Trang;
	string Tac_Gia;
	int Nam_Xuat_Ban;
	string The_Loai;
	//con tro dms;
	DS_DMS Danh_Muc_Sach;
};
typedef struct dau_sach* DAU_SACH;


struct mang_dau_sach {
	int So_Luong = 0;
	DAU_SACH Dau_Sach[Max];
};
typedef struct mang_dau_sach MANG_DAU_SACH;


// ------------------------ cac ham xu li ve danh muc sach -------------------------------------
int check_lap_ISBN(string a, MANG_DAU_SACH mds);

int check_lap(string a, MANG_DAU_SACH mds);
// tao ma sach auto 
string Tao_ma_Sach(MANG_DAU_SACH mds);

//add node dslk don -- da tesst . oke
void Add_Node_DMS(DS_DMS& dms, DMS temp);
void Them_Danh_Muc_Sach_Cho_Dau_Sach(MANG_DAU_SACH& mds);
void Xuat_DMS(MANG_DAU_SACH mds);



// ------------------------- Cac ham xu li ve dau sach ------------------------------------

void Add_Dau_Sach(MANG_DAU_SACH& mds, DAU_SACH temp);
void Nhap_Info_Dau_Sach(MANG_DAU_SACH& mds);
void Xuat_Mang_Dau_Sach(MANG_DAU_SACH mds);

void Doc_File_Dau_Sach(MANG_DAU_SACH& mds);

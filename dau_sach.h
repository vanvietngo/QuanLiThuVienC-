#pragma once
//#include"Variable_Global.h"
#include<iostream>
#include<string>
#include <windows.h>
#include <sstream>
#include<fstream>
#include<ctime>
//#include"ve_hinh.h"
const int Max = 100;
using namespace std;

// ----------------------------------- DANH MUC SACH --------------------------------------
//- Danh mục sách : danh sách liên kết đơn(Mã sách, trạng thái, vị trí).
//				  Mỗi cuốn sách chỉ có 1 mã duy nhất; 
//				  trạng thái của sách bao gồm : 0 : cho mượn được, 
//												1 : đã có độc giả mượn, 
//												2: sách đã thanh lý 
struct d_m_s {
	string ISBN; // them vao de biet ma sach nay thuoc DAU SACH nao.
	int Ma_Sach;
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

	int so_lan_muon=0;
	//con tro dms;
	DS_DMS Danh_Muc_Sach;
};
typedef struct dau_sach* DAU_SACH;


struct mang_dau_sach {
	int So_Luong = 0;
	DAU_SACH Dau_Sach[Max];
};
typedef struct mang_dau_sach MANG_DAU_SACH;

// ham tra ve time hien tai
//tm* Time_Now();
// chuan hoa ki tu
void Chuan_Hoa_Chu(string& kitu);
// ------------------------ cac ham xu li ve danh muc sach -------------------------------------
int check_lap_ISBN(string a, MANG_DAU_SACH mds); 
// -1 => ko co isbn trong mang; i: co -> vi tri i trong mang

int check_lap_Ma_Sach(int a, DAU_SACH DS); 
// -1 => trng ; 1 => ko trung


int check_lap_ISBN_1_DS(string a, DAU_SACH ds); 
// -1 trung; 1 ko trung
// tao ma sach auto 
int Tao_ma_Sach(MANG_DAU_SACH mds, string ma_ISBN);
void Add_Node_DSLKD(DS_DMS& dms, DMS temp); 
void Them_Danh_Muc_Sach_Cho_Dau_Sach(MANG_DAU_SACH& mds);
int check_lap_Ma_Sach_Va_Trang_Thai(int a, DAU_SACH DS);
void Xoa_Danh_Muc_Sach(MANG_DAU_SACH& mds);
void Xuat_DMS(MANG_DAU_SACH mds);
//--------------------------------------------------------------------------------------------


// -   ---------------------- Cac ham xu li ve dau sach ------------------------------------

//c. Nhập thông tin đầu sách và đánh mã sách tự động. 
//Chương trình cho phép xóa 1 mã sách nếu mã sách này chưa cho độc giả mượn; 

void Add_Node_Dau_Sach(MANG_DAU_SACH& mds, DAU_SACH temp);
void Nhap_Info_Dau_Sach(MANG_DAU_SACH& mds);
//void Sua_Infor_Dau_Sach(MANG_DAU_SACH& mds);
void Xuat_Mang_Dau_Sach(MANG_DAU_SACH mds);
//d.In danh sách các đầu sách trong thư viện theo từng thể loại, 
//trong từng thể loại thì in theo thứ tự tên sách tăng dần.
void Xap_Xep_Mang(DAU_SACH & ds_A, DAU_SACH& ds_B);
void Xuat_Mang_Dau_Sach_Theo_The_Loai(MANG_DAU_SACH mds);

//e. Tìm thông tin sách dựa vào tên sách : 
		//in ra các thông tin mã ISBN, tên sách, tác giả, năm xuất bản, 
			//thể loại, các mã sách , trạng thái mã sách trong thư viện.
void Tim_Sach(MANG_DAU_SACH mds);
void Xoa_Dau_Sach(MANG_DAU_SACH& mds);
void Sua_Thong_Tin_Dau_Sach(MANG_DAU_SACH& mds);

// -------- Xu li file DAU SACH --------------
void Doc_File_Dau_Sach(MANG_DAU_SACH& mds);
void Update_File_Them_Dau_Sach(DAU_SACH DS);
void Update_File_Xoa_Dau_Sach(MANG_DAU_SACH DS);
// - file dms
void Load_File_DMS(MANG_DAU_SACH& mds);
void Update_File_Them_DMS(DMS dms);
void Update_File_Xoa_DMS(MANG_DAU_SACH mds);


#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include"dau_sach.h"
// thu vien random
#include<cstdlib> // rand(); srand();   rand()% (b -a + 1) + a => [a;b]
#include<ctime> // xoa data random cu khi khoi dong
using namespace std;

//- Danh sách MUONTRA : danh sách liên kết kép(
//						MASACH, 
//						NgayMuon, 
//						NgayTra, 
//						trạng thái) : trạng thái = 0 là sách đang mượn(chưa trả), =1 là đã trả, =2 : làm mất sách
//#include"dohoa.h"

struct muon_tra
{
	string ISBN;
	int Ma_Sach;
	time_t Ngay_Muon = NULL;
	time_t Ngay_Tra = NULL;
	int Trang_Thai;

	// con tro pNext
	muon_tra* pNext = NULL;
	muon_tra* pPre = NULL;
};
typedef struct muon_tra* MUON_TRA;

struct ds_muon_tra 
{
	int So_Luong = 0;
	MUON_TRA pHead = NULL;
};
typedef struct ds_muon_tra DS_MUON_TRA;

// -----------------------------------------------------------------------------------------
//- Danh sách thẻ độc giả : cây nhị phân tìm kiếm(
//							MATHE(số nguyên ngẫu nhiên tự động), 
//							Ho, 
//							Ten, 
//							Phai, 
//							trạng thái của thẻ, 
//							con trỏ) : con trỏ sẽ trỏ đến danh sách các cuốn sách đã và đang mượn.

struct the_doc_gia 
{
	int Ma_The;
	string Ho;
	string Ten;
	string Phai;
	int Trang_Thai_The = 1;
	// con tro ds muon tra
	DS_MUON_TRA ds_Muon_Tra;  //<==== chua xu li
	// 
	the_doc_gia* pLeft = NULL;
	the_doc_gia* pRight = NULL;
};
typedef struct the_doc_gia* TDG; // node tdg 

struct ds_tdg 
{
	int So_Luong = 0;
	TDG The_Doc_Gia = NULL;
};
typedef struct ds_tdg DS_TDG;  // node cay tdg. co so luong


// ---------------------------------------------       Ham xu li       ------------------------------------------------

//a.Nhập thẻ độc giả : 
//						thêm / xóa / hiệu chỉnh thông tin thẻ độc giả.
//						Mã thẻ độc giả được chương trình tự động lấy ngẫu nhiên và không trùng với các mã thẻ độc giả cũ; 
//						Phái chỉ nhận ‘Nam’ hoặc ‘Nữ’; 
//						trạng thái thẻ = 0 khi thẻ bị khóa, trạng thái thẻ = 1 khi thẻ  đang hoạt động(được quyền mượn sách).

//------------------------------------------------------------------------------------------------------------------


// ---------- Cac ham xu li THE DOC GIA -------------

tm Doi_So_Giay_Thanh_DMY(time_t now);
// 1: qua han ;  0: chua qua han
int Check_Qua_Han_Muon_Sach(time_t time_Ngay_Muon, time_t now);

// --------------- Them THE DOC GIA --------------------
// Kiem tra Ma TDG da ton tai chua
//0: chua co; 1: co roi
int Check_Ma_TDG(TDG tdg, int Ma_The);

// check ma tdg de them vao ds muon tra
void Tim_TDG_Trung_Mathe_De_Them(TDG& tdg, int Ma_The, MUON_TRA tempMT);

// Tao Ma The tu dong
int Tao_Ma_TDG(TDG tdg);

// Thêm node độc giả
void Them_Node_Cay_Nhi_Phan(TDG& ds_tdg, TDG tdg);

// Nhap thong tin the doc gia vao Danh sach TDG
void Nhap_TDG(DS_TDG& ds_tdg);
//-------------------------------------------------------

//-------------  Xoa 1 node the doc gia --------------
//Xóa 1 node bất kì trong cây nhị phân tìm kiếm
//Node X là node cần xóa :
//Nếu X :
//1. Node lá : xóa bình thường - bởi vì lúc này node x đang là node tự do
//(không tồn tại cây con trái và cây con phải)
//2. Node có 1 con : trước khi xóa node x - chúng ta phải cập nhật mối liên kết
//giữa node cha của node x với node con(con trái hoặc con phải) của node x
//3. Node có 2 con : trước khi hủy thì ta phải đi tìm 1 cái node thế mạng cho node cần xóa
//- tìm node thế mạng phải đảm bảo quy tắc cây nhị phân tìm kiếm
//+ Tìm node trái nhất của cây con phải(cây con phải của cái node cần xóa)
//+ Tìm node phải nhất của cây con trái(cây con trái của cái node cần xóa)

void Tim_Node_The_Mang(TDG& tdg_pright, TDG& X);
int Xoa_1_Node_Cay_Nhi_Phan(TDG& tree, int ma_the);
void Xoa_TDG(DS_TDG& ds_tdg);
// ---------------------------------------------------------------------------------------------
int Sua_Infor_Node_tree(TDG& node, int mathe);
// Chinh sua thong tin the doc gia
void Sua_Thong_Tin_TDG(DS_TDG& tgd, TDG Mang[]);
// Xuat thong tin the doc gia
void Xuat_TDG_Tang_Dan_Theo_Mathe(TDG ds_tdg);// xap xep theo Ma the tang dan .
//-------------------------------  xap xep TDG theo ho + ten ------------------------------------- :
// Chuyen node TDG vao mang de xap xep
//int stt_mang = 0;
void Chuyen_Node_Vao_Mang(TDG tree, TDG Mang[], int& stt);
void Chuyen_Node_Vao_Mang_Tang_Dan_Ma_The(TDG tree, TDG Mang[], int& stt);

// Xap xep mang node TDG theo Ten - Ho - Ma The
void Xap_Xep_TDG(TDG& node_a, TDG& node_b);
void In_Mang_TDG_Tang_Dan_Theo_Ten(TDG Mang[], DS_TDG sl);

void In_Mang_TDG(TDG Mang[], DS_TDG sl);





// ----------- Cac ham xu li DANH SACH MUON TRA -------------
// them danh sach Muon tra

int Tim_TDG_Muon_Sach(int Ma_The, TDG tdg_tree, TDG& tempTDG_muonsach);
// return 1 -> thay  --; -1 : ko thay

int Tim_Dau_Sach_DG_Muon(string a, MANG_DAU_SACH mds, DAU_SACH& temp);
// return 1: thấy ds muon -- 0: ko co


int Kiem_Tra_Dieu_Kien_Muon(TDG tempTDG, DAU_SACH tempDS, MUON_TRA& tempMT);
// return 1 : muon dc ;  -1: komuon dc
//int Tim_Ma_Sach_Cua_Dau_Sach_Cho_Muon_Dc(DMS& temp, MUON_TRA& tempMT);
void Them_Node_Muon_Tra_Cua_1_Doc_Gia(TDG tdg, MUON_TRA temp_TDG);
void Them_DS_Muon_Tra(DS_TDG& ds_tdg, MANG_DAU_SACH& mds);
// xuat danh sach muon tra
void Xuat_DS_MT(TDG ds_tdg);

void Xuat_DSMT_Mot_Doc_Gia(TDG ds_tdg); // ham xu li phu

// -------------------------- Tra sach  --------------------------------------
// 1: co muon ; 0: ko muon dau sach nay
int Check_Sach_Da_Muon(TDG tdg, string maisbn);

void Xoa_DSLK_Kep(TDG tdg_muonsach, DAU_SACH dausach_muon);

void Tra_Sach(DS_TDG ds_tdg, MANG_DAU_SACH mds, TDG Mang[]);

// --------------------------------------------------------------------------
// ------------  liet ke cac sach ma 1 doc gia muon ----------------
// cau h
void Xuat_DSMT_1_Doc_Gia_cau_h(DS_TDG ds_tdg);

//cau i
void In_TDG_Muon_Qua_Han_Giam_Dan(DS_TDG tdg, int& stt1);


//--------------------- file -----------------------

void Load_File_thedocgia(DS_TDG& ds_tdg);

void Load_File_Danh_Sach_Muon_Tra(DS_TDG& ds_tdg); // bug
//void Load_File_Danh_Sach_Muon_Tra(DS_TDG& ds_tdg,);

void Update_File_Them_thedocgia(TDG node);

void Update_File_Xoa_thedocgia(DS_TDG& tree, TDG Mang[]);

void Update_File_Them_MT(TDG node, MUON_TRA p);

void Update_File_Xoa_MT(DS_TDG tree,TDG Mang[]);

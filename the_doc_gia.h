#pragma once

//- Danh sách MUONTRA : danh sách liên kết kép(
//						MASACH, 
//						NgayMuon, 
//						NgayTra, 
//						trạng thái) : trạng thái = 0 là sách đang mượn(chưa trả), =1 là đã trả, =2 : làm mất sách

#include<iostream>
#include<string>

// thu vien random
#include<cstdlib> // rand(); srand();   rand()% (b -a + 1) + a => [a;b]
#include<ctime> // xoa data random cu khi khoi dong
using namespace std;


struct muon_tra {
	string Ma_Sach;
	string Ngay_Muon;
	string Ngay_Tra;
	int Trang_Thai;

	// con tro pNext
	muon_tra* pNext = NULL;
	muon_tra* pPre = NULL;
};
typedef struct muon_tra MUON_TRA;


struct ds_muon_tra {
	int So_Luong = 0;
	muon_tra* pHead = NULL;
};
typedef struct ds_muon_tra DS_MUON_TRA;






// --------------------------------------

//- Danh sách thẻ độc giả : cây nhị phân tìm kiếm(
//							MATHE(số nguyên ngẫu nhiên tự động), 
//							Ho, 
//							Ten, 
//							Phai, 
//							trạng thái của thẻ, 
//							con trỏ) : con trỏ sẽ trỏ đến danh sách các cuốn sách đã và đang mượn.










struct the_doc_gia {
	int Ma_The;
	string Ho;
	string Ten;
	string Phai;
	int Trang_Thai_The;
	// con tro ds muon tra
	DS_MUON_TRA ds_Muon_Tra;  //<==== chua xu li
	// 
	the_doc_gia* pLeft = NULL;
	the_doc_gia* pRight = NULL;
};
typedef struct the_doc_gia* TDG; // node tdg 

struct ds_tdg {
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

// ----------- Cac ham xu li DANH SACH MUON TRA -------------




// ---------- Cac ham xu li THE DOC GIA -------------
void Doc_File(DS_TDG& ds_tdg);

// chuan hoa ki tu
void Chuan_Hoa_Chu(string &kitu);

// --------------------------------------------------------------------------------------------
// Kiem tra trung Ma TDG
int Check_Ma_TDG(TDG tdg, int Ma_The);

// Tao Ma The tu dong
int Tao_Ma_TDG(TDG tdg);

// TẠO 1 the doc gia
TDG Tao_Node_TDG();

// Thêm độc giả
void Them_The_Doc_Gia(TDG& ds_tdg, TDG tdg);

// Nhap thong tin the doc gia vao Danh sach TDG
void Nhap_TDG(DS_TDG& ds_tdg);

// Xoa 1 node the doc gia

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

void Xoa_1_Node_TDG(TDG& tgd, int ma_the);

void Xoa_TDG(DS_TDG& ds_tdg);
// ---------------------------------------------------------------------------------------------

// Chinh sua thong tin the doc gia
void Sua_Thong_Tin_TDG(TDG& ds_tgd, int ma_the);

// Xuat thong tin the doc gia
void Xuat_TDG(TDG ds_tdg, int& n_, DS_TDG sl);// xap xep theo Ma the tang dan .

//-------------------------------  xap xep TDG theo ho + ten ------------------------------------- :
// Chuyen node TDG vao mang de xap xep
//int stt_mang = 0;
void Chuyen_Node_Vao_Mang(TDG tree, TDG Mang[], int& stt);


// Xap xep mang node TDG theo Ten - Ho - Ma The
void Swap_2_Node(TDG& node_a, TDG& node_b);
void Xap_Xep_TDG(TDG Mang[], DS_TDG tdg);
void In_Mang_TDG(TDG Mang[], DS_TDG sl);
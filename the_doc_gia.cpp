#include"the_doc_gia.h"
#include<fstream>

// Load file

// doc data tu file vao bien ds_tdg ;
void Doc_File(DS_TDG& ds_tdg) {
		ifstream filein_TDG;
		filein_TDG.open("thedocgia.txt", ios_base::in);
		if (filein_TDG.fail()) {
			cout << "file not exist" << endl;
		}
		else {
			cout << " doc file thedocgia.txt thanh cong" << endl;
			while (filein_TDG.eof() != true) 
			{
				TDG tdg = Tao_Node_TDG();	
				filein_TDG >> tdg->Ma_The;
				filein_TDG.ignore();
				getline(filein_TDG, tdg->Ho, ',');
				getline(filein_TDG, tdg->Ten, ',');
				getline(filein_TDG, tdg->Phai, ',');
				//getline(filein_TDG, tdg->Trang_Thai_The, ',');
				filein_TDG >> tdg->Trang_Thai_The;
				filein_TDG.ignore();
				Them_The_Doc_Gia(ds_tdg.The_Doc_Gia, tdg);
				ds_tdg.So_Luong++;
			}

			filein_TDG.close();
		}

}

// ghi file

//-----------------------------------

// cHUAN HÓA CHỮ
void Chuan_Hoa_Chu(string &kitu)
{
	// xoa ki tu dau va cuoi
		while (kitu[0] == ' ') {
			kitu.erase(0,1);
		}
		while (kitu[kitu.length() - 1] == ' ') {
			kitu.erase(kitu.length() - 1, 1);
		}

	// xoa ki tu giua
		//if (kitu.length() >= 3) {
		//	for (int i = 0; i < kitu.length() - 2; i++) {
		//		if (kitu[i] == ' ') {
		//			if (kitu[i + 1] == ' ') {
		//				kitu.erase(i, 1);
		//				i--;
		//			}
		//		}
		//	}
		//}


	// upper key
	/*	for (int i = 0; i <= (kitu.length()-1); i++) {
			if (97 <= kitu[i] && kitu[i]<= 122) {
				kitu[i] = kitu[i] - 32;
			}
		}*/

}

// Kiem tra trung Ma TDG
int Check_Ma_TDG(TDG tdg, int Ma_The)
{
	if (tdg == NULL) {
		return 0; // chua co
	}
	else 
	{
		if (tdg->Ma_The == Ma_The)
		{
			return 1; // da co ma the nay roi ( tim thay the can sua )
		}
		else if (tdg->Ma_The > Ma_The)
		{
			Check_Ma_TDG(tdg->pRight, Ma_The);
		}
		else if (tdg->Ma_The < Ma_The)
		{
			Check_Ma_TDG(tdg->pLeft, Ma_The);
		}
	}
}

// Tao Ma The tu dong
int Tao_Ma_TDG(TDG tdg) {
	int Ma_The;
	do
	{
		Ma_The = rand() % (999 - 100 + 1) + 100;
	} while (Check_Ma_TDG(tdg, Ma_The));
	return Ma_The;

}

// TẠO 1 the doc gia
TDG Tao_Node_TDG() {
	TDG tdg = new the_doc_gia;
	tdg->pLeft = NULL;
	tdg->pRight = NULL;
	return tdg;
}

// Thêm độc giả
void Them_The_Doc_Gia(TDG& ds_tdg, TDG tdg) { // ds_tdg -> node cay ; tdg -> node can them
	if (ds_tdg == NULL) {
		ds_tdg = tdg;
	}
	else {
		if (ds_tdg->Ma_The > tdg->Ma_The) {
			Them_The_Doc_Gia(ds_tdg->pLeft, tdg);
		}
		else if (ds_tdg->Ma_The < tdg->Ma_The) {
			Them_The_Doc_Gia(ds_tdg->pRight, tdg);
		}
	}
}

// Nhap tong tin the doc gia
void Nhap_TDG(DS_TDG& ds_tdg) {
	TDG tdg;
	tdg = Tao_Node_TDG();
	cout << "Ma TDG da duoc tao tu dong !!!" << endl;
	tdg->Ma_The = Tao_Ma_TDG(ds_tdg.The_Doc_Gia);

	cout << "Nhap Ho doc gia: ";
	cin.ignore();
	getline(cin, tdg->Ho);
	Chuan_Hoa_Chu(tdg->Ho);

	cout << "Nhap Ten doc gia: ";
	//cin.ignore();
	getline(cin, tdg->Ten);
	Chuan_Hoa_Chu(tdg->Ten);

	cout << "Nhap Phai doc gia: ";
	//cin.ignore();
	getline(cin, tdg->Phai);
	Chuan_Hoa_Chu(tdg->Phai);

	tdg->Trang_Thai_The = 1;

	Them_The_Doc_Gia(ds_tdg.The_Doc_Gia, tdg);
	ds_tdg.So_Luong++;
}

void Tim_Node_The_Mang(TDG& tdg_pright, TDG& X) 
// tdg_pright : hien tai co gia tri la node ben phai gia tri can xoa, x la ban sao cua gia tri can xoa
{
	// c1: tim not trai cung
	if (tdg_pright->pLeft != NULL)
	{
		Tim_Node_The_Mang(tdg_pright->pLeft, X);
	}
	else // Tìm dược node thế mạng rồi  ==> tdg_pright bay gio la not trai cung
	{
		// chuyen data node the mang qua cho X (X la ban sao node can xoa ban dau)
		X->Ho = tdg_pright->Ho;
		X->Ma_The = tdg_pright->Ma_The;
		X->Phai = tdg_pright->Phai;
		//xong r thi cho x tro toi node the mang roi xoa
		X = tdg_pright; // node_del ko tro toi node xoa nua ma bay h tro ts node the mang
		tdg_pright = tdg_pright->pLeft; // cho gia tri cua no = NULL
	}

}

void Xoa_1_Node_TDG(TDG& ds_tdg, int ma_the)  // ds_tdg hien tai la node root tree
{
	if (ds_tdg == NULL) // cay rong
	{
		return ;
	}
	else
	{
		if (ma_the < ds_tdg->Ma_The)  // duyet qua trai de tim
		{
			Xoa_1_Node_TDG(ds_tdg->pLeft, ma_the);
		}
		else if (ma_the > ds_tdg->Ma_The) // duyet qua phai de tim
		{
			Xoa_1_Node_TDG(ds_tdg->pRight, ma_the);
		}
		else // ds_tdg - > Ma_The = ma_the  => thấy node can xoa
		{
			TDG x = ds_tdg; // tao node thế mạng ; =========>  ds_tdg BAY gio dang o gia tri can xoa
			// TH1: X là node 1 nhanh :
			if (ds_tdg->pLeft == NULL)
			{
				// chuyen data qua nut muon xoa
				ds_tdg = ds_tdg->pRight;
			}
			else if (ds_tdg->pRight == NULL)
			{
				ds_tdg = ds_tdg->pLeft;
			}
			else
			{
				// c1: tim node trai nhat cua cay con phai
				//ds_tdg = ds_tdg->pRight;
				Tim_Node_The_Mang(ds_tdg->pRight, x);

				// C2: Tim node phai nhat cua cay con trai
			}
			delete x;
		}
	}
}

void Xoa_TDG(DS_TDG& ds_tdg)
{
	int mathe;
	cout << "nhap ma the can xoa: ";
	cin >> mathe;
	Xoa_1_Node_TDG(ds_tdg.The_Doc_Gia, mathe);
	cout << "da xoa thanh cong"<<endl;
	ds_tdg.So_Luong--;
}

void Sua_Thong_Tin_TDG(TDG& tdg, int ma_the) {
	//int ck_mt;
	//do
	//{
	//	
	//	cout << "Nhap ma the doc gia can sua: ";
	//	cin >> ma_the;
	//	ck_mt = Check_Ma_TDG(ds_tdg.The_Doc_Gia, ma_the);
	//	if (ck_mt == 0) {
	//		cout << " Ma the khong hop le. Vui long nhap lai !!" << endl;
	//	}
	//} while (ck_mt != 1);
	// --- xu li sua
	if (tdg->Ma_The == ma_the)
	{
		// tim toi diem can sua
		cout << "Nhap ho can doi: ";
		cin >> tdg->Ho;
		cout << "Nhap ten can doi: ";
		cin >> tdg->Ten;
	}
	else if (tdg->Ma_The > ma_the)
	{
		Sua_Thong_Tin_TDG(tdg->pRight, ma_the);
	}
	else if (tdg->Ma_The < ma_the)
	{
		Sua_Thong_Tin_TDG(tdg->pLeft, ma_the);
	}
}


void Xuat_TDG(TDG ds_tdg, int& n_, DS_TDG sl)
{
	
	if (ds_tdg != NULL) {
		Xuat_TDG(ds_tdg->pLeft, n_, sl);

		cout << endl;
		cout << "thong tin the doc gia thu " << ": " << endl;
		cout<<"Ma the: "<< ds_tdg->Ma_The << endl;
		cout << "Ho: " << ds_tdg->Ho << endl;
		cout << "Ten: " << ds_tdg->Ten<<endl;
		cout << "Phai: " << ds_tdg->Phai<<endl;
		cout << "Trang thai: " << ds_tdg->Trang_Thai_The << endl;
		//n_ += 1;
		cout << "so luon ssau khi xoa la: " << sl.So_Luong<<endl;
		Xuat_TDG(ds_tdg->pRight, n_ ,sl);
	}
}


//-------------------------------------------------------------------
// Chuyen node TDG vao mang de xap xep
//int stt_mang = 0;
void Chuyen_Node_Vao_Mang(TDG tree, TDG Mang[], int& stt)
{
	// duyet node :
	if (tree != NULL)
	{
		Mang[stt] = new the_doc_gia;
		// day data vao mang;
		
		Mang[stt]->Ma_The = tree->Ma_The;
		Mang[stt]->Ho = tree->Ho;
		Mang[stt]->Ten = tree->Ten;
		Mang[stt]->Phai = tree->Phai;
		Mang[stt]->Trang_Thai_The = tree->Trang_Thai_The;
		stt++;

		Chuyen_Node_Vao_Mang(tree->pLeft, Mang, stt);
		Chuyen_Node_Vao_Mang(tree->pRight, Mang, stt);
	}
}

// xap xep cac phan tu trong mang
void Swap_2_Node(TDG& node_a, TDG& node_b)
{
	// chuyen data qua node temp
	TDG node_temp = new the_doc_gia;
	node_temp->Ho = node_a->Ho;
	node_temp->Ma_The = node_a->Ma_The;
	node_temp->Phai = node_a->Phai;
	node_temp->Ten = node_a->Ten;
	node_temp->Trang_Thai_The = node_a->Trang_Thai_The;
	node_temp->ds_Muon_Tra = node_a->ds_Muon_Tra;


	//node_a = node_b;
	node_a->Ho = node_b->Ho;
	node_a->Ma_The = node_b->Ma_The;
	node_a->Phai = node_b->Phai;
	node_a->Ten = node_b->Ten;
	node_a->Trang_Thai_The = node_b->Trang_Thai_The;
	node_a->ds_Muon_Tra = node_b->ds_Muon_Tra;

	//node_b = node_temp;
	node_b->Ho = node_temp->Ho;
	node_b->Ma_The = node_temp->Ma_The;
	node_b->Phai = node_temp->Phai;
	node_b->Ten = node_temp->Ten;
	node_b->Trang_Thai_The = node_temp->Trang_Thai_The;
	node_b->ds_Muon_Tra = node_temp->ds_Muon_Tra;	
}

// xap xep mang TDG tang dan theo Ten -> Ho
void Xap_Xep_TDG(TDG Mang[], DS_TDG tdg)
{
	for (int i = 0; i < tdg.So_Luong - 1; i++)
	{
		for (int j = i + 1; j < tdg.So_Luong; j++)
		{
			if (Mang[i]->Ten > Mang[j]->Ten)
			{
				Swap_2_Node(Mang[i], Mang[j]);
			}
			else if (Mang[i]->Ten == Mang[j]->Ten)
			{
				if (Mang[i]->Ho > Mang[j]->Ho)
				{
					Swap_2_Node(Mang[i], Mang[j]);
				}
			}
		}
	}
}

// In mang The doc gia
void In_Mang_TDG(TDG Mang[], DS_TDG sl)
{
	for (int i = 0; i < sl.So_Luong; i++)
	{
		cout << endl;
		cout << "thong tin the doc gia thu " << i+1 << ": " << endl;
		cout << "Ma the: " << Mang[i]->Ma_The << endl;
		cout << "Ho: " << Mang[i]->Ho << endl;
		cout << "Ten: " << Mang[i]->Ten << endl;
		cout << "Phai: " << Mang[i]->Phai << endl;
		cout << "Trang thai: " << Mang[i]->Trang_Thai_The << endl;
	}
}
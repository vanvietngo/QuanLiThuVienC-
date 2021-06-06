#include"the_doc_gia.h"

tm Doi_So_Giay_Thanh_DMY(time_t now)
{
	tm ltime;
	localtime_s(&ltime, &now);
	// print various components of tm structure.
	//cout << "Year: " << 1900 + ltime.tm_year << endl;
	//cout << "Month: " << 1 + ltime.tm_mon << endl;
	//cout << "Day: " << ltime.tm_mday << endl;
	//cout << "Time: " << ltime.tm_hour << ":";
	//cout << ltime.tm_min << ":";
	//cout << ltime.tm_sec << endl;
	return ltime;
}

int Check_Qua_Han_Muon_Sach(time_t time_Ngay_Muon, time_t now)
{
	if (now - time_Ngay_Muon > 86400)
	{
		return 1; // qua han
	}
	return 0; // chua qua han
}

// Kiem tra Ma TDG da ton tai chua
int Check_Ma_TDG(TDG tdg, int Ma_The)
{
	//string str_mathe = to_string(Ma_The);
	//for (int i = 0; i < str_mathe.length(); i++)
	//{
	//	// 48 -57 -> ascii cua 0- -> 9
	//	if ((str_mathe[i] >= 48) && (str_mathe[i]<=57))
	//	{
	//		return 0;
	//	}
	//}

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
			Check_Ma_TDG(tdg->pLeft, Ma_The);
		}
		else if (tdg->Ma_The < Ma_The)
		{
			Check_Ma_TDG(tdg->pRight, Ma_The);
		}
	}
}

void Tim_TDG_Trung_Mathe_De_Them(TDG& tree, int Ma_The, MUON_TRA tempMT) // bugggggggggggggggggggggggggggggg
{
		if (tree->Ma_The == Ma_The)
		{
				time_t timeNow = time(0);
				if (Check_Qua_Han_Muon_Sach(tempMT->Ngay_Muon, timeNow) == 1)// qua han
				{
					// thay doi trang thai hoat dong cua tdg
					tree->Trang_Thai_The = 0; // khoa
					Them_Node_Muon_Tra_Cua_1_Doc_Gia(tree, tempMT);
				}
				else
				{
					Them_Node_Muon_Tra_Cua_1_Doc_Gia(tree, tempMT);
				}
		}
		else if (tree->Ma_The > Ma_The)
		{
			Tim_TDG_Trung_Mathe_De_Them(tree->pLeft, Ma_The, tempMT);
		}
		else if (tree->Ma_The < Ma_The)
		{
			Tim_TDG_Trung_Mathe_De_Them(tree->pRight, Ma_The, tempMT);
		}
}

// Tao Ma The tu dong
int Tao_Ma_TDG(TDG tdg) {
	int Ma_The;
	do
	{
		// random [a - b]=> (b - a + 1) + a  - cong thuc
		Ma_The = rand() % (999 - 100 + 1) + 100;
	} 
	while (Check_Ma_TDG(tdg, Ma_The) == 1);
	return Ma_The;
}

// Thêm độc giả
void Them_Node_Cay_Nhi_Phan(TDG& ds_tdg, TDG tdg) { // ds_tdg -> node cay ; tdg -> node can them
	if (ds_tdg == NULL) {
		ds_tdg = tdg;
	}
	else {
		if (ds_tdg->Ma_The > tdg->Ma_The) {
			Them_Node_Cay_Nhi_Phan(ds_tdg->pLeft, tdg);
		}
		else if (ds_tdg->Ma_The < tdg->Ma_The) {
			Them_Node_Cay_Nhi_Phan(ds_tdg->pRight, tdg);
		}
	}
}

// Nhap tong tin the doc gia
void Nhap_TDG(DS_TDG& ds_tdg) 
{
	if (ds_tdg.So_Luong >= 100)
	{
		cout << "so luon the doc gia da day(>=100). Khong the them" << endl;
	}
	else
	{
		TDG tdg = new the_doc_gia;

		tdg->Ma_The = Tao_Ma_TDG(ds_tdg.The_Doc_Gia);
		tdg->Trang_Thai_The = 1; // tao moi auto hoat dong

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

		if (tdg->Phai == "NAM" )
		{
			Them_Node_Cay_Nhi_Phan(ds_tdg.The_Doc_Gia, tdg);
			ds_tdg.So_Luong++;
			// 
			Update_File_Them_thedocgia(tdg);
		}
		else if (tdg->Phai == "NU")
		{
			Them_Node_Cay_Nhi_Phan(ds_tdg.The_Doc_Gia, tdg);
			ds_tdg.So_Luong++;
			// 
			Update_File_Them_thedocgia(tdg);
		}
		else
		{
			cout << "Phai chi nhan nam hoac nu" << endl;
		}


	}
	
}

void Tim_Node_The_Mang(TDG& tdg_pright, TDG& X)
// tdg_pright : hien tai co gia tri la node con ben phai gia tri can xoa, x la ban sao cua gia tri can xoa
// => X la ban sao cha cua node tdg_pright
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
		X->Ten = tdg_pright->Ten;
		X->Ma_The = tdg_pright->Ma_The;
		X->Phai = tdg_pright->Phai;
		X->Trang_Thai_The = tdg_pright->Trang_Thai_The;
		X->ds_Muon_Tra = tdg_pright->ds_Muon_Tra;

		//xong r thi cho x tro toi node the mang roi xoa
		X = tdg_pright; // node_del ko tro toi node xoa nua ma bay h tro ts node the mang
		tdg_pright = NULL; // cho gia tri cua no = NULL
		// return 0;
	}

}

int Xoa_1_Node_Cay_Nhi_Phan(TDG& tree, int ma_the)  
{
	//if (tree == NULL) // cay rong
	//{
	//	return 0;
	//}
	//else
	//{
		if (ma_the < tree->Ma_The)  // duyet qua trai de tim
		{
			Xoa_1_Node_Cay_Nhi_Phan(tree->pLeft, ma_the);
		}
		else if (ma_the > tree->Ma_The) // duyet qua phai de tim
		{
			Xoa_1_Node_Cay_Nhi_Phan(tree->pRight, ma_the);
		}
		else // tree - > Ma_The = ma_the  => thấy node can xoa
		{
			if (tree->ds_Muon_Tra.So_Luong != 0)
			{
				//cout << "Doc gia da muon sach. Khong xoa duoc" << endl;
				return -1;
			}
			else
			{
				TDG x_themang = tree; // tao node thế mạng ; =========>  tree BAY gio la ban sao node can xoa
				// TH1: x_themang là node 1 nhanh :
				if (tree->pLeft == NULL)
				{
					// chuyen data qua nut muon xoa
					tree = tree->pRight;
				}
				else if (tree->pRight == NULL)
				{
					tree = tree->pLeft;
				}
				else
				{
					// c1: tim node trai nhat cua cay con phai
					//ds_tdg = ds_tdg->pRight;
					Tim_Node_The_Mang(tree->pRight, x_themang);

					// C2: Tim node phai nhat cua cay con trai
				}
				// complete
				delete x_themang;
				return 1;
			}
			
		}
	//}
}

void Xoa_TDG(DS_TDG& ds_tdg)
{
	int mathe;
	cout << "nhap ma the can xoa: ";
	cin >> mathe;
	if (Check_Ma_TDG(ds_tdg.The_Doc_Gia, mathe) == 0)
	{
		cout << "khong co the doc gia ma: " << mathe << endl;
	}
	else
	{
		if (Xoa_1_Node_Cay_Nhi_Phan(ds_tdg.The_Doc_Gia, mathe) == 1)
		{
			cout << "da xoa thanh cong" << endl;
			ds_tdg.So_Luong--;
		}
	}
}

int Sua_Infor_Node_tree(TDG& node, int mathe)
{
	// --- xu li sua
	if (node->Ma_The == mathe)
	{
		cin.ignore();
		string Ho, Ten, Phai;
		// tim toi diem can sua
		cout << "Nhap ho can doi: ";
		getline(cin, Ho);
		Chuan_Hoa_Chu(Ho);
		cout << "Nhap ten can doi: ";
		getline(cin, Ten);
		Chuan_Hoa_Chu(Ten);
		cout << "Nhap phai can doi: ";
		getline(cin, Phai);
		Chuan_Hoa_Chu(Phai);
		if (Phai == "NAM" || Phai == "NU")
		{
			node->Ten = Ten;
			node->Ho = Ho;
			node->Phai = Phai;
			cout << "complete!" << endl;
			return 1;
		}
		else
		{
			cout << "phai khong hop le" << endl;
			return 0;
		}
	}
	else if (node->Ma_The > mathe)
	{
		Sua_Infor_Node_tree(node->pLeft, mathe);
	}
	else if (node->Ma_The < mathe)
	{
		Sua_Infor_Node_tree(node->pRight, mathe);
	}
}

void Sua_Thong_Tin_TDG(DS_TDG& tdg, TDG Mang[])
{
	int mathe;
	cout << "Nhap ma the doc gia can sua: ";
	cin >> mathe;
	if (Check_Ma_TDG(tdg.The_Doc_Gia, mathe) == 0)
	{
		cout << " Ma the khong ton tai !" << endl;
	}
	else
	{
		if (Sua_Infor_Node_tree(tdg.The_Doc_Gia, mathe) == 1)
		{
			Update_File_Xoa_thedocgia(tdg, Mang);
		}
	}	
}

void Xuat_TDG_Tang_Dan_Theo_Mathe(TDG ds_tdg)
{
	if (ds_tdg != NULL) {
		Xuat_TDG_Tang_Dan_Theo_Mathe(ds_tdg->pLeft);
		cout << endl;
		cout << "Ma the: " << ds_tdg->Ma_The << endl;
		cout << "Ho: " << ds_tdg->Ho << endl;
		cout << "Ten: " << ds_tdg->Ten << endl;
		cout << "Phai: " << ds_tdg->Phai << endl;
		cout << "Trang thai: ";
		if (ds_tdg->Trang_Thai_The == 0)
		{
			cout << "Bi khoa" << endl;
		}
		else
		{
			cout << "Hoat dong" << endl;
		}
		Xuat_TDG_Tang_Dan_Theo_Mathe(ds_tdg->pRight);
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
		Mang[stt] = tree;

		stt++;

		Chuyen_Node_Vao_Mang(tree->pLeft, Mang, stt);
		Chuyen_Node_Vao_Mang(tree->pRight, Mang, stt);
	}
}

// 
void Chuyen_Node_Vao_Mang_Tang_Dan_Ma_The(TDG tree, TDG Mang[], int& stt)
{
	// duyet node :
	if (tree != NULL)
	{
		Chuyen_Node_Vao_Mang_Tang_Dan_Ma_The(tree->pLeft, Mang, stt);
		Mang[stt] = new the_doc_gia;
		// day data vao mang;
		Mang[stt] = tree;

		stt++;

		Chuyen_Node_Vao_Mang_Tang_Dan_Ma_The(tree->pRight, Mang, stt);
	}
}
// xap xep cac phan tu trong mang theo ten
void Xap_Xep_TDG(TDG& node_a, TDG& node_b)
{
	if (node_a->Ten[0] > node_b->Ten[0])
	{
		// chuyen data qua node temp
		TDG node_temp = new the_doc_gia;
		node_temp = node_a;
		node_a = node_b;
		node_b = node_temp;
	}
	else if (node_a->Ten[0] == node_b->Ten[0])
	{
		if (node_a->Ten.length() > node_b->Ten.length())
		{
			// chuyen data qua node temp
			TDG node_temp = new the_doc_gia;
			node_temp = node_a;
			node_a = node_b;
			node_b = node_temp;
		}
	}
}

// In mang The doc gia
void In_Mang_TDG_Tang_Dan_Theo_Ten(TDG Mang[], DS_TDG tdg)
{
	for (int i = 0; i < tdg.So_Luong - 1; i++)
	{
		for (int j = i + 1; j < tdg.So_Luong; j++)
		{
			Xap_Xep_TDG(Mang[i], Mang[j]);
		}
	}
	In_Mang_TDG(Mang, tdg);
}

void In_Mang_TDG(TDG Mang[], DS_TDG sl)
{
	//Xap_Xep_TDG(Mang, sl);
	for (int i = 0; i < sl.So_Luong; i++)
	{
		cout << "Ma the: " << Mang[i]->Ma_The << endl;
		cout << "Ho: " << Mang[i]->Ho << endl;
		cout << "Ten: " << Mang[i]->Ten << endl;
		cout << "Phai: " << Mang[i]->Phai << endl;
		cout << "Trang thai: " << Mang[i]->Trang_Thai_The;
		if (Mang[i]->Trang_Thai_The == 0)
		{
			cout << "   Bi khoa" << endl;
		}
		else
		{
			cout << "   Hoat dong" << endl;
		}
	}
}

// -1: ko co ma the, 1: co ma the
int Tim_TDG_Muon_Sach(int Ma_The, TDG tdg_tree, TDG& tempTDG_muonsach)
{
	// khi tim thay tdg muon sach thi lay infor vao temp luon
	if (tdg_tree == NULL) {
		//cout << " Khong co the doc gia nao" << endl;// chua co
		return -1;
	}
	else
	{
		if (tdg_tree->Ma_The == Ma_The)
		{
			tempTDG_muonsach = tdg_tree; // da co ma the nay roi ( tim thay the can sua )
			return 1;
		}
		else if (tdg_tree->Ma_The > Ma_The)
		{
			Tim_TDG_Muon_Sach(Ma_The, tdg_tree->pLeft, tempTDG_muonsach);
		}
		else if (tdg_tree->Ma_The < Ma_The)
		{
			Tim_TDG_Muon_Sach(Ma_The, tdg_tree->pRight, tempTDG_muonsach);
		}
	}

}

// tim ISBN cua dau sach -> neu thay thi truyen ifor cho team_dausach_muon
int Tim_Dau_Sach_DG_Muon(string a, MANG_DAU_SACH mds, DAU_SACH& team_dausach_muon)
{
	for (int i = 0; i < mds.So_Luong; i++)
	{
		if (mds.Dau_Sach[i]->ISBN[0] == a[0])
		{
			if (mds.Dau_Sach[i]->ISBN[1] == a[1])
			{
				if (mds.Dau_Sach[i]->ISBN[2] == a[2])
				{
					if (mds.Dau_Sach[i]->ISBN[3] == a[3])
					{
						// tim thay dau sach can muon
						team_dausach_muon = mds.Dau_Sach[i];
						return 1;
					}
				}
			}

		}

	}

	return 0;
}

int Kiem_Tra_Dieu_Kien_Muon(TDG tempTDG, DAU_SACH tempDS, MUON_TRA& tempMT) // -------------- bug 
{
	// 		// muon sach co thuoc cung 1 dau sach khong

	// kiem tra so luong sach muon da 3 cuon chua
	if (tempTDG->ds_Muon_Tra.So_Luong <3)
	{
		
		tempMT->Ngay_Muon = time(0);
		// th1: tdg chua muon cuon sach nao het
		if (tempTDG->ds_Muon_Tra.pHead == NULL)
		{
			// chua muon cuon nao -> cho phep muon
						//=> tien hanh tim masach cho muon
			DMS p;
			p = tempDS->Danh_Muc_Sach.pHead;
			while (p != NULL)
			{
				if (p->Trang_Thai == 0) { // muon duoc sach
					//cap nhat trang thai cua masach va tempMT
					p->Trang_Thai = 1;
					tempMT->Ma_Sach = p->Ma_Sach;
					tempMT->ISBN = p->ISBN;
					tempMT->Trang_Thai = 1;
					tempDS->so_lan_muon++;
					//cout << "Muon thanh cong" << endl;
					return 1;
				}
				p = p->pNext;
			}
			// khong muon duoc sach -> ko co sach nao cho muon dc
			//cout << "chua muon cuon nao" << endl;
			//cout << "cac sach da duoc muon het !!!" << endl;
			return -1;
		}
		// the doc gia da muon sach
		else 
		{		//kiem tra co trung cac sach da muon khong ;
			MUON_TRA q = tempTDG->ds_Muon_Tra.pHead;
			while (q != NULL)
			{
				// kiem tra dau sach nay da muon chua thong qua ISBN
				if (check_lap_ISBN_1_DS(q->ISBN, tempDS) == -1) // -1 trung
				{
					//cout<<"sach nay da muon roi"<<endl;
					return -2;
				}
				else //kiem tra co sach nao qua han khong
				{
					if (Check_Qua_Han_Muon_Sach(q->Ngay_Muon, tempMT->Ngay_Muon) == 1)
					{
						//cout << "co sach da muon qua han. K hong muon dduoc sach" << endl;
						return -3;
					}
				}
				q = q->pNext;
			}

			//---------------------------------

							// DAUSACH nay chua muon va chua co sach nao qua han
			//=> tien hanh tim masach cho muon
			DMS p;
			p = tempDS->Danh_Muc_Sach.pHead;
			while (p != NULL)
			{
				if (p->Trang_Thai == 0) { // muon duoc sach
					p->Trang_Thai = 1;
					tempMT->Ma_Sach = p->Ma_Sach;
					tempMT->ISBN = p->ISBN;
					tempMT->Trang_Thai = 1;
					//cout << "Muon sach thanh cong" << endl;
					return 1;
				}
				p = p->pNext;
			}
			// khong muon duoc sach -> ko co sach nao cho muon dc
			//cout << "cac sach da duoc muon het !!!" << endl;
			return -1;
		}	
	}
	// the doc gia da muon  3 cuon sach
	else
	{
		//cout << "Doc gia da muon 3 cuon sach roi. Khong muon duoc nua" << endl;
		return -4;
	}
}

void Them_Node_Muon_Tra_Cua_1_Doc_Gia(TDG tdg, MUON_TRA temp_TDG) // them node dslk kep
{
	if (tdg->ds_Muon_Tra.pHead == NULL)
	{
		tdg->ds_Muon_Tra.pHead = temp_TDG;
		tdg->ds_Muon_Tra.So_Luong++;
	}
	else
	{
		MUON_TRA p = tdg->ds_Muon_Tra.pHead;

		while (p->pNext != NULL)
		{
			p = p->pNext;
		}
		p->pNext = temp_TDG;
		temp_TDG->pPre = p;
		temp_TDG->pNext = NULL;

		tdg->ds_Muon_Tra.So_Luong++;
	}
}

// them chinh ---------- muon sach ---------
void Them_DS_Muon_Tra(DS_TDG& ds_tdg, MANG_DAU_SACH& mds)
{
	int mathe;
	TDG tempTDG; // TDG muon sach
	//cout << " nhap ma the doc gia 100 - 999 : ";
	cin >> mathe;
	if (Tim_TDG_Muon_Sach(mathe, ds_tdg.The_Doc_Gia, tempTDG) == -1)
	{
		// ko ton tai mathe doc gia
		//cout << "Ma the doc gia khong hop le " << endl;
	}
	else
	{
		//xuat cac sach doc gia da muon
		//cout << "cac sach ma doc gia da muon: " << endl;
		Xuat_DSMT_Mot_Doc_Gia(tempTDG);
		cout << endl;
		// tim dc TDG muon sach
		// =>  tim dau sach can muon
		string Ma_ISBN;
		DAU_SACH tempDS;
		//cout << " Nhap ma ISBN cua DAU SACH de muon sach: (4 ki tu) ";
		cin >> Ma_ISBN;
		Chuan_Hoa_Chu(Ma_ISBN);
		if (Tim_Dau_Sach_DG_Muon(Ma_ISBN, mds, tempDS) == 0)
		{
			//cout << "Khong co dau sach can muon" << endl;
		}
		else// tim thay dau sach can muon
		{
			// sau khi cos tdg can muon sach va dau sach can muon roi
			MUON_TRA tempMT = new muon_tra;
			if (Kiem_Tra_Dieu_Kien_Muon(tempTDG, tempDS, tempMT) == 1)
			{
				Them_Node_Muon_Tra_Cua_1_Doc_Gia(tempTDG, tempMT);
				Update_File_Them_MT(tempTDG, tempMT);
				Update_File_Xoa_DMS(mds); // update trang thai moi ma sach cua dau sach
			}
		}
	}
}

void Xuat_DS_MT(TDG tree)
{
	if (tree != NULL) { // xet tung tdg trong cay nhi phan
		if (tree->ds_Muon_Tra.pHead != NULL) // xet tung danh sach muon tra dslk kep cua doc gia
		{
			cout << endl;
			cout << endl;
			cout << "***   Doc gia : " << tree->Ma_The << "  ***"<<endl;
			cout << "So sach da muon: " << tree->ds_Muon_Tra.So_Luong << endl<<endl;
			MUON_TRA p = tree->ds_Muon_Tra.pHead;
			tm DMY_TRA = Doi_So_Giay_Thanh_DMY(p->Ngay_Tra);
			while (p != NULL) 
			{
				cout << "Ma ISBN cua sach: " << p->ISBN << endl;
				cout << "ma sach muon = " << p->Ma_Sach << endl;
				cout << "trang thai: " << p->Trang_Thai<<endl;
				tm DMY = Doi_So_Giay_Thanh_DMY(p->Ngay_Muon);
				cout << "Ngay muon: " << DMY.tm_hour << ":" << DMY.tm_min << ":" << DMY.tm_sec
					<< " - " << DMY.tm_mday << "/" << 1 + DMY.tm_mon << "/" << 1900 + DMY.tm_year << endl;
				if (p->Ngay_Tra != NULL)
				{
					cout << "Ngay tra: " << DMY_TRA.tm_hour << ":" << DMY_TRA.tm_min << ":" << DMY_TRA.tm_sec
						<< " - " << DMY_TRA.tm_mday << "/" << 1 + DMY_TRA.tm_mon << "/" << 1900 + DMY_TRA.tm_year << endl;
				}
				else
				{
					cout << "Ngay tra: chua tra sach" << endl;
				}			
				cout << endl;
				p = p->pNext;
			}
		}
		Xuat_DS_MT(tree->pLeft);
		Xuat_DS_MT(tree->pRight);
	}
}

void Xuat_DSMT_Mot_Doc_Gia(TDG tdg) // co tdg can xuat ra roi
{
	//if (ds_tdg != NULL && ds_tdg->Ma_The==mathe) {
		if (tdg->ds_Muon_Tra.pHead != NULL)
		{
			cout << endl;
			cout << endl;
			MUON_TRA p = tdg->ds_Muon_Tra.pHead;
			while (p != NULL) {
				cout << "Ma ISBN cua sach: " << p->ISBN << endl;
				cout << "ma sach muon = " << p->Ma_Sach << endl;
				cout << "trang thai: " << p->Trang_Thai << endl;
				tm DMY_MUON = Doi_So_Giay_Thanh_DMY(p->Ngay_Muon);
				tm DMY_TRA = Doi_So_Giay_Thanh_DMY(p->Ngay_Tra);
				cout << "Ngay muon: " << DMY_MUON.tm_hour << ":" << DMY_MUON.tm_min << ":" << DMY_MUON.tm_sec
					<< " - " << DMY_MUON.tm_mday << "/" << 1 + DMY_MUON.tm_mon << "/" << 1900 + DMY_MUON.tm_year << endl;
				if (p->Ngay_Tra != NULL)
				{
					cout << "Ngay tra: " << DMY_TRA.tm_hour << ":" << DMY_TRA.tm_min << ":" << DMY_TRA.tm_sec
						<< " - " << DMY_TRA.tm_mday << "/" << 1 + DMY_TRA.tm_mon << "/" << 1900 + DMY_TRA.tm_year << endl;
				}
				else
				{
					cout << "Ngay tra: chua tra sach" << endl;
				}
				cout << endl;
				p = p->pNext;
			}
		}
}

int Check_Sach_Da_Muon(TDG tdg, string ma_isbn)
{
	MUON_TRA p = tdg->ds_Muon_Tra.pHead;
	while (p != NULL)
	{
		if (p->ISBN == ma_isbn)
		{
			// doc gia co muon dau sach nay
			return 1;
		}
		p = p->pNext;
	}
	return 0; // doc gia khong muon dau sach nay
}

void Xoa_DSLK_Kep(TDG tdg_muonsach, DAU_SACH dausach_muon)
{
	//if (tdg_muonsach->ds_Muon_Tra.pHead != NULL)
	//{
		MUON_TRA p = tdg_muonsach->ds_Muon_Tra.pHead;
		MUON_TRA p_re = new muon_tra;
		DMS s = dausach_muon->Danh_Muc_Sach.pHead;// dau sach chua sach muon
		// xoa node dau
		if (tdg_muonsach->ds_Muon_Tra.pHead->ISBN == dausach_muon->ISBN)
		{
			// update trang thai sach cua dau sach chua ma sach tra
			while (s != NULL)
			{
				if (s->Ma_Sach == tdg_muonsach->ds_Muon_Tra.pHead->Ma_Sach)
				{
					s->Trang_Thai = 0;
					break;
				}
				s = s->pNext;
			}
			//----------------
			tdg_muonsach->ds_Muon_Tra.pHead = tdg_muonsach->ds_Muon_Tra.pHead->pNext;
			//tdg_muonsach->ds_Muon_Tra.pHead->pPre = NULL;
			delete p;
			tdg_muonsach->ds_Muon_Tra.So_Luong--;
		}
		else
		{
			// xoa not bat ki ko phai node dau
			while (p != NULL)
			{
				// xoa node cuoi
				if (p->ISBN == dausach_muon->ISBN && p->pNext == NULL)
				{
					// update trang thai sach cua dau sach chua ma sach tra
					while (s != NULL)
					{
						if (s->Ma_Sach == p->Ma_Sach)
						{
							s->Trang_Thai = 0;
							break;
						}
						s = s->pNext;
					}
					//-------
					//p = NULL;
					p_re->pNext = NULL;
					delete p;
					tdg_muonsach->ds_Muon_Tra.So_Luong--;
					break;
				}
				else
				{
					// khong phai node cuoi
					if (p->ISBN == dausach_muon->ISBN && p->pNext != NULL)
					{
						// update trang thai sach cua dau sach chua ma sach tra
						while (s != NULL)
						{
							if (s->Ma_Sach == p->Ma_Sach)
							{
								s->Trang_Thai = 0;
								break;
							}
							s = s->pNext;
						}
						//----------------
						// tien hanh xoa.
						p_re->pNext = p->pNext;
						p->pNext->pPre = p_re;
						//p = NULL;
						delete p;

						tdg_muonsach->ds_Muon_Tra.So_Luong--;
						break;
					}
				}	
				p_re = p;
				p = p->pNext;
			}
		}
	//}
}

void Tra_Sach(DS_TDG ds_tdg, MANG_DAU_SACH mds, TDG Mang[])
{
	int mathe;
	TDG tempTDG = new the_doc_gia; // day la tdg muon sach
	cout << "Nhap ma the doc gia: ";
	cin >> mathe;

	if (Check_Ma_TDG(ds_tdg.The_Doc_Gia, mathe) == 0)
	{
		cout << "Ma the khong ton tai" << endl;
	}
	else
	{
		if (Tim_TDG_Muon_Sach(mathe, ds_tdg.The_Doc_Gia, tempTDG) == -1)
		{
			cout << "Ma the khong ton tai" << endl;
		}
		else
		{
			string maISBN;
			DAU_SACH tempDS = new dau_sach; // day la dausach duoc muon 
			cout << "Nhap ma ISBN sach muon: ";
			cin >> maISBN;
			Chuan_Hoa_Chu(maISBN);
			if (maISBN.length() != 4)
			{
				cout << "ma ISBN khong hop le" << endl;
			}
			else
			{
				if (Tim_Dau_Sach_DG_Muon(maISBN, mds, tempDS) == 0)
				{
					cout << " Dau sach khong ton tai";
				}
				else
					// da co tdg muon sach va dau sach  co ton tai
				{
					// kiem tra doc gia co muon cuon sach nay khong
					if (Check_Sach_Da_Muon(tempTDG, maISBN) == 0)
					{
						cout << "Doc gia khong muon sach nay" << endl;
					}
					else
					{
						// doc gia co muon sach nay
						// tien hanh tra sach
						Xoa_DSLK_Kep(tempTDG, tempDS);
						// sau khi tra sach update lai file
						tempTDG->Trang_Thai_The = 1;
						cout << "complete !" << endl;
						Update_File_Xoa_thedocgia(ds_tdg, Mang);
						Update_File_Xoa_DMS(mds);
						Update_File_Xoa_MT(ds_tdg, Mang);
					}
				}
			}

		}
	}

}

// ------------  liet ke cac sach ma 1 doc gia muon ----------------
// cau h
void Xuat_DSMT_1_Doc_Gia_cau_h(DS_TDG ds_tdg)
{
	TDG tempTDG;
	int mathe;
	cout << "Nhap ma the doc gia: ";
	cin >> mathe;
	if (Tim_TDG_Muon_Sach(mathe, ds_tdg.The_Doc_Gia, tempTDG) == -1)
	{
		cout << "ma the khong ton tai" << endl;
	}
	else
	{
		// co duoc ma the doc gia muon sach roi.
		Xuat_DSMT_Mot_Doc_Gia(tempTDG);
	}
}

void In_TDG_Muon_Qua_Han_Giam_Dan(DS_TDG tdg,int& stt1)
{
	int st = 0;
	int sl = tdg.So_Luong;
	TDG mang[100];
	TDG mangQUAHAN[100];
	time_t songayquahan[100];
	time_t manggiay[100];
	Chuyen_Node_Vao_Mang(tdg.The_Doc_Gia,mang, stt1);

	// lay cac doc gia qua han vao mangquahan;
	for (int i = 0; i < tdg.So_Luong; i++)
	{
		if (mang[i]->ds_Muon_Tra.So_Luong != 0) // mang[i] cac the doc gia
		{
			MUON_TRA p = mang[i]->ds_Muon_Tra.pHead;
			while (p != NULL)
			{
				time_t now = time(0);
				if (Check_Qua_Han_Muon_Sach(p->Ngay_Muon, now) == 1)
				{
					mangQUAHAN[st] = new the_doc_gia;
					mangQUAHAN[st] = mang[i];
					songayquahan[st] = (now - p->Ngay_Muon) / 86400;
					manggiay[st] = p->Ngay_Muon;
					st++;
					break;
				}
				p = p->pNext;
			}
		}
	}
	//xap xep tang dan;
	for (int x = 0; x < st-1; x++)
	{
		for (int c = x + 1; c < st; c++)
		{
			if (songayquahan[x] < songayquahan[c])
			{
				// mang so ngay qua han
				time_t temp;
				temp = songayquahan[x];
				songayquahan[x] = songayquahan[c];
				songayquahan[c] = temp;
				// mang tdg
				TDG temTDG = new the_doc_gia;
				temTDG = mangQUAHAN[x];
				mangQUAHAN[x] = mangQUAHAN[c];
				mangQUAHAN[c] = temTDG;
				// mang ngay muon
				time_t te;
				te = manggiay[x];
				manggiay[x] = manggiay[c];
				manggiay[c] = te;

			}
		}
	}

	// in ra
	for (int z = 0; z < st; z++)
	{
		tm DMY_MUON = Doi_So_Giay_Thanh_DMY(manggiay[z]);

		cout << "cac doc gia muon sach qua han: " << endl;
		cout << "ma the: " << mangQUAHAN[z]->Ma_The << endl;
		cout << "Ho: " << mangQUAHAN[z]->Ho << endl;
		cout << "Ten: " << mangQUAHAN[z]->Ten << endl;
		cout << "Ngay muon: " << DMY_MUON.tm_hour << ":" << DMY_MUON.tm_min << ":" << DMY_MUON.tm_sec
			<< " - " << DMY_MUON.tm_mday << "/" << 1 + DMY_MUON.tm_mon << "/" << 1900 + DMY_MUON.tm_year << endl;
		cout << "so ngay qua han: " << songayquahan[z] << endl<<endl;
	}
}

// ghi file
//-----------------------------------
void Load_File_Danh_Sach_Muon_Tra(DS_TDG& ds_tdg) // bug
{

	int t = 0;
	ifstream file_in_DSMT;
	file_in_DSMT.open("danhsachmuontra.txt", ios_base::in);
	if (file_in_DSMT.fail())
	{
		cout << "file danhsachmuontra.txt not exist" << endl;
	}
	else
	{
		while (file_in_DSMT.eof() != true)
		{
			if (t == 0)
			{
				//cout << "bo qua dong dau tien file danhmucsach.txt" << endl;
				file_in_DSMT.ignore(256, '\n');
				t++;
			}
			else
			{
				MUON_TRA ds = new muon_tra;
				
				int mathe;
				file_in_DSMT>>mathe;
				file_in_DSMT.ignore(256, ',');
				getline(file_in_DSMT, ds->ISBN, ',');
				file_in_DSMT >> ds->Ma_Sach;
				file_in_DSMT.ignore(256, ',');
				file_in_DSMT >> ds->Trang_Thai;
				file_in_DSMT.ignore(256, ',');
				file_in_DSMT >> ds->Ngay_Muon;
				file_in_DSMT.ignore(256, ',');
				file_in_DSMT >> ds->Ngay_Tra;
				file_in_DSMT.ignore();

				Chuan_Hoa_Chu(ds->ISBN);

				// co duoc node muon tr roi => ds
				// tim tdg trung vs ma the de them vao ds muon tra
				Tim_TDG_Trung_Mathe_De_Them(ds_tdg.The_Doc_Gia, mathe, ds);
			}
		}
		
		file_in_DSMT.close();
	}
}

// doc data tu file vao bien ds_tdg ;
void Load_File_thedocgia(DS_TDG& ds_tdg)
{
	int t = 0;
	ifstream filein_TDG;
	filein_TDG.open("thedocgia.txt", ios_base::in);
	if (filein_TDG.fail()) 
	{
		cout << "file not exist" << endl;
	}
	else 
	{
		while (filein_TDG.eof() != true)
		{
			if (t == 0)
			{
				filein_TDG.ignore(256, '\n');
				t++;
			}
			else
			{
				TDG tdg = new the_doc_gia;
				
				filein_TDG >> tdg->Ma_The;
				filein_TDG.ignore(256, ',');
				getline(filein_TDG, tdg->Ho, ',');
				getline(filein_TDG, tdg->Ten, ',');
				getline(filein_TDG, tdg->Phai, ',');
				filein_TDG >> tdg->Trang_Thai_The;
				filein_TDG.ignore();
				
				Chuan_Hoa_Chu(tdg->Ho);
				Chuan_Hoa_Chu(tdg->Phai);
				Chuan_Hoa_Chu(tdg->Ten);

				Them_Node_Cay_Nhi_Phan(ds_tdg.The_Doc_Gia, tdg);
				
				ds_tdg.So_Luong++;
			}
		}
		filein_TDG.close();
	}
}

void Update_File_Them_thedocgia(TDG node) // update them
{

		fstream f;
		f.open("thedocgia.txt", ios_base::out|ios_base::app);


	if (f.fail())
	{
		cout << "file not exis" << endl;
	}
	else 
	{
		// 3. Ghi dữ liệu vào file, trường hợp này ta có data là dữ liệu
		//string data = "Site: www.stdio.vn\nHo Ten: La Kien Vinh\nCong Viec: Dao Tao Lap Trinh Vien";
		//f << data;
		f << endl;
		f << node->Ma_The << "  ,";
		f << node->Ho;
		for (int i = 0; i < (20 - node->Ho.length()); i++)
		{
			f << " ";
		}
		f << ",";
		
		f << node->Ten;
		for (int j = 0; j < (20 - node->Ten.length()); j++)
		{
			f << " ";
		}
		f<< ",";
		f << node->Phai;
		for (int k = 0; k < (5 - node->Phai.length()); k++)
		{
			f << " ";
		}
		f<< ",";
		f << node->Trang_Thai_The;
	}
	// 4. Đóng file
	f.close();
}

void Update_File_Xoa_thedocgia(DS_TDG& tree, TDG Mang[])
{
	fstream f;
	f.open("thedocgia.txt", ios_base::out);

		// 3. Ghi dữ liệu vào file, trường hợp này ta có data là dữ liệu
		//string data = "Site: www.stdio.vn\nHo Ten: La Kien Vinh\nCong Viec: Dao Tao Lap Trinh Vien";
		//f << data;
	f << "mathe  -  ho -           ten -                 phai - trang thai the";
	for (int i = 0; i < tree.So_Luong; i++)
	{
		f << endl;
		f << Mang[i]->Ma_The << "  ,";
		f << Mang[i]->Ho;
		for (int q = 0; q < (20 - Mang[i]->Ho.length()); q++)
		{
			f << " ";
		}
		f << ",";

		f << Mang[i]->Ten;
		for (int j = 0; j < (20 - Mang[i]->Ten.length()); j++)
		{
			f << " ";
		}
		f << ",";
		f << Mang[i]->Phai;
		for (int k = 0; k < (5 - Mang[i]->Phai.length()); k++)
		{
			f << " ";
		}
		f << ",";
		f << Mang[i]->Trang_Thai_The;
	}	
	f.close();
}

void Update_File_Them_MT(TDG node, MUON_TRA p)
{

	fstream f;
	f.open("danhsachmuontra.txt", ios_base::out | ios_base::app);


	if (f.fail())
	{
		cout << "file not exis" << endl;
	}
	else
	{
		// 3. Ghi dữ liệu vào file, trường hợp này ta có data là dữ liệu
		//string data = "Site: www.stdio.vn\nHo Ten: La Kien Vinh\nCong Viec: Dao Tao Lap Trinh Vien";
		//f << data;
		f << endl;
		f << node->Ma_The << "  ,";
		f << p->ISBN<<" ,";

		f << p->Ma_Sach;
		string masach = to_string(p->Ma_Sach);
		if (masach.length() == 1)
		{
			f << "  ,";
		}
		else
		{
			f << " ,";
		}
		f << p->Trang_Thai<<" ,";
		f << p->Ngay_Muon << " ,";
		if (p->Ngay_Tra != NULL)
		{
			f << p->Ngay_Tra;
		}
		else
		{
			f << 0;
		}
	}
	// 4. Đóng file
	f.close();
}

void Update_File_Xoa_MT(DS_TDG tree,TDG Mang[])
{
	fstream f;
	f.open("danhsachmuontra.txt", ios_base::out);


	if (f.fail())
	{
		cout << "file not exis" << endl;
	}
	else
	{
		// 3. Ghi dữ liệu vào file, trường hợp này ta có data là dữ liệu
		//string data = "Site: www.stdio.vn\nHo Ten: La Kien Vinh\nCong Viec: Dao Tao Lap Trinh Vien";
		//f << data;
		f << "ma the doc gia - isbn - ma sach - trang thai - NGAY MUON - NGAY TRA";
		for (int i = 0; i < tree.So_Luong; i++)
		{
			if (Mang[i]->ds_Muon_Tra.So_Luong != 0)
			{
				MUON_TRA p = Mang[i]->ds_Muon_Tra.pHead;
				while (p != NULL)
				{
					f << endl;
					f << Mang[i]->Ma_The << "  ,";
					f << p->ISBN << " ,";

					f << p->Ma_Sach;
					string masach = to_string(p->Ma_Sach);
					if (masach.length() == 1)
					{
						f << "  ,";
					}
					else
					{
						f << " ,";
					}
					f << p->Trang_Thai << " ,";
					f << p->Ngay_Muon << " ,";
					if (p->Ngay_Tra != NULL)
					{
						f << p->Ngay_Tra;
					}
					else
					{
						f << 0;
					}
					p = p->pNext;
				}

			}
		}

	}
	// 4. Đóng file
	f.close();
}

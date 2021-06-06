#include"dau_sach.h"


//tm* Time_Now()
//{
//	time_t now = time(0);
//	cout << "Number of sec since January 1,1970:" << now << endl;
//	tm* ltm = localtime(&now);
//	return ltm;
//}

// cHUAN HÓA CHỮ
void Chuan_Hoa_Chu(string& kitu)
{
	if (kitu.length() > 0)
	{
		// xoa ki tu space dau va cuoi
		while (kitu[0] == ' ')
		{
			kitu.erase(0, 1);
		}
		while (kitu[kitu.length() - 1] == ' ')
		{
			kitu.erase(kitu.length() - 1, 1);
		}
		// xoa ki tu space giua
		for (int i = 0; i < kitu.length(); i++)
		{
			if (kitu[i] == ' ')
			{
				if (i + 1 < kitu.length())
				{
					if (kitu[i + 1] == ' ')
					{
						kitu.erase(i, 1);
						i--;
					}
				}

			}
		}
		// upper key
		for (int i = 0; i < kitu.length(); i++)
		{
			if (97 <= kitu[i] && kitu[i] <= 122)
			{
				kitu[i] = kitu[i] - 32;
			}
		}
	}
}

// ham kiem tra ma ISBN cua 1 mang DAUSACH co khong
int check_lap_ISBN(string a, MANG_DAU_SACH mds)
{
	//if (a.length() != 4)
	//{
	//	return -1;
	//}
	//else
	//{
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
							return i; // 
						}
					}
				}
			}
		}
		return -1; // KO CO ISBN trong mang
	//}

}

// cac ham xua li danh muc sach => 1 phan cua dau sach


// kiem tra ma sach cua 1 dau sach -- BUG SS THEM MA isbn
int check_lap_Ma_Sach(int a, DAU_SACH DS) { // kt lap khi tao ma sach auto cho danh muc sach	
		DMS p = DS->Danh_Muc_Sach.pHead;
		while (p != NULL)
		{
			if (a == p->Ma_Sach)
			{		
			return -1;		// trung			
			}
			p = p->pNext;		
		}
	return 1; // khong trung
}





// ham kiem tra ma ISBN cua 1 DAUSACH co khong
int check_lap_ISBN_1_DS(string a, DAU_SACH ds)
{
		if (ds->ISBN[0] == a[0])
		{
			if (ds->ISBN[1] == a[1])
			{
				if (ds->ISBN[2] == a[2])
				{
					if (ds->ISBN[3] == a[3])
					{
						return -1;
					}
				}
			}
		}	
	return 1;
}

int Tao_ma_Sach(MANG_DAU_SACH mds, string ma_ISBN)
{
	int mathe;

	DMS temp = mds.Dau_Sach[check_lap_ISBN(ma_ISBN, mds)]->Danh_Muc_Sach.pHead;
	// mang dms trong
	if (temp == NULL)
	{
		//cout << "mang dms trong" << endl;
		//cout << "So_Luong = " << mds.Dau_Sach[check_lap_ISBN(ma_ISBN, mds)]->Danh_Muc_Sach.So_Luong << endl;
		// tao ma sach moi = so luong dms
		//mathe = rand() % (99 - 10 + 1) + 10;
		//mathe[i] = rand() % (b - a + 1) + a; -> (a-b)	
		mathe = mds.Dau_Sach[check_lap_ISBN(ma_ISBN, mds)]->Danh_Muc_Sach.So_Luong;
		return mathe;
	}
	// danh muc sach khong = null
	else
	{
		//cout << "danh muc sach ko trong !!!" << endl;
		// kiem tra ma sach node cuoi co = so luong ko
		// neu = so luog -> chua sach nao bi xoa
		// ko = so luong , lo lo trong trong ma sach
		DMS max = new d_m_s;
		max = temp;
		while (temp != NULL)
		{
			if (max->Ma_Sach < temp->Ma_Sach)
			{
				max = temp;
			}
			if (temp->pNext == NULL) // tim toi node cuoi
			{
				//cout << "da tim toi node cuoi" << endl;
				if (max->Ma_Sach == mds.Dau_Sach[check_lap_ISBN(ma_ISBN, mds)]->Danh_Muc_Sach.So_Luong - 1)
				{
					//cout << "ma the dms ko bi lung lo" << endl;
					//cout << "So_Luong = " << mds.Dau_Sach[check_lap_ISBN(ma_ISBN, mds)]->Danh_Muc_Sach.So_Luong << endl;

					// ma sach cuoi = so luong. them binh thuong
					//cout << "them binh thuong" << endl;
					mathe = mds.Dau_Sach[check_lap_ISBN(ma_ISBN, mds)]->Danh_Muc_Sach.So_Luong;
					return mathe;
				}
				else // ma sach node cuoi ko bang so luong:
				{
					//cout << "ma the dms bi lung lo" << endl;
					//cout << "So_Luong = " << mds.Dau_Sach[check_lap_ISBN(ma_ISBN, mds)]->Danh_Muc_Sach.So_Luong << endl;
					//cout << "max = " << max->Ma_Sach << endl;
					for (int i = 0; i < max->Ma_Sach; i++)
					{
						if (check_lap_Ma_Sach(i, mds.Dau_Sach[check_lap_ISBN(ma_ISBN, mds)]) == 1)
						{
							// neu ko trung -> chua co ma sach nay
							//cout << "i = " << i << endl;
							mathe = i;
							return mathe;
						}
					}
				}
			}
			temp = temp->pNext;
		}
	}
}

// Ham xu li tam them danh muc sach

void Add_Node_DSLKD(DS_DMS& dms, DMS temp)
{
	if (dms.pHead == NULL)
	{
		//temp->Ma_Sach = teo;
		dms.pHead = temp;
		dms.So_Luong++;
	}
	else
	{
		DMS p;
		p = dms.pHead;
		while (p->pNext != NULL)
		{
			p = p->pNext;
		}
		p->pNext = temp;
		dms.So_Luong++;
	}
}

// Ham them danh muc sach chinh
void Them_Danh_Muc_Sach_Cho_Dau_Sach(MANG_DAU_SACH& mds)
{
	// Nhap ma ISBN cua dau sach de tim dau sach can them danh muc sach !!!
	string tim_DS;
	//int k = 0;

		//if (k == 0) 
		//{
		//	cin.ignore();
		//}
		//k++;
		cout << " Nhap ma ISBN cua DAU SACH de them danh muc sach: (4 ki tu) ";
		getline(cin, tim_DS);
		Chuan_Hoa_Chu(tim_DS);
		if (tim_DS.length()!= 4)
		{
			cout << "do dai ma ISBN chi co 4 ki tu !!!  ";
			cout << endl;
		}
		else
			if (check_lap_ISBN(tim_DS, mds) == -1)
			{
				cout << "Ma ISBN khong ton tai !"<<endl;
			}
			else
			{
				cout << "Ma ISBN hop le !!!" << endl;
				DMS temp = new d_m_s;
				// tao ma sach tu dong 
				//cin.ignore();
				cout << "Ma sach duoc tao tu dong !!" << endl;
				temp->Ma_Sach = Tao_ma_Sach(mds, tim_DS);
				temp->ISBN = tim_DS;
				cout << "Nhap vi tri : ";
				getline(cin, temp->Vi_Tri);
				Chuan_Hoa_Chu(temp->Vi_Tri);
				Add_Node_DSLKD(mds.Dau_Sach[check_lap_ISBN(tim_DS, mds)]->Danh_Muc_Sach, temp);
				//cout<<"so luong = "<< mds.Dau_Sach[check_lap_ISBN(tim_DS, mds)]->Danh_Muc_Sach.So_Luong<<endl;

				//mds.Dau_Sach[check_lap_ISBN(tim_DS, mds)]->Danh_Muc_Sach.So_Luong++;
				//cout << "so luong = " << mds.Dau_Sach[check_lap_ISBN(tim_DS, mds)]->Danh_Muc_Sach.So_Luong << endl;

				Update_File_Them_DMS(temp);
			}

	
}

int check_lap_Ma_Sach_Va_Trang_Thai(int a, DAU_SACH DS)
{
	DMS p = DS->Danh_Muc_Sach.pHead;
	while (p != NULL)
	{
		if (a == p->Ma_Sach)
		{
			if (p->Trang_Thai != 1)
			{
				return -1;		// trung	va chua muon
			}
			//cout << "sach da duoc muon ko duoc xoa" << endl;
			return 1; // trung nhung da muon 
		}
		p = p->pNext;
	}
	//cout << "ko co ma sach can xoa" << endl;
	return 2; // khong trung
}

void Xoa_Danh_Muc_Sach(MANG_DAU_SACH& mds)
{
	string ma_isbn;
	cout << "nhap ma ISBN cua ma sach can xoa: ";
	cin >> ma_isbn;
	Chuan_Hoa_Chu(ma_isbn);
	if (ma_isbn.length() != 4)
	{
		cout << "do dai ISBN phai = 4" << endl;
	}
	else
		if (check_lap_ISBN(ma_isbn, mds) == -1)
		{
			cout << "Ma ISBN khong ton tai !" << endl;
		}
		else
		{
			int masach;
			cout << "nhap ma sach can xoa: ";
			cin >> masach;
			if (check_lap_Ma_Sach_Va_Trang_Thai(masach, mds.Dau_Sach[check_lap_ISBN(ma_isbn, mds)]) == 1)
			{
				cout << "";
			}
			else
			{
			// co ma sach xoa 
				if (masach == mds.Dau_Sach[check_lap_ISBN(ma_isbn, mds)]->Danh_Muc_Sach.pHead->Ma_Sach)
				{
					// xoa node dau
					DMS p = mds.Dau_Sach[check_lap_ISBN(ma_isbn, mds)]->Danh_Muc_Sach.pHead;
					mds.Dau_Sach[check_lap_ISBN(ma_isbn, mds)]->Danh_Muc_Sach.pHead = mds.Dau_Sach[check_lap_ISBN(ma_isbn, mds)]->Danh_Muc_Sach.pHead->pNext;
					delete p;
					mds.Dau_Sach[check_lap_ISBN(ma_isbn, mds)]->Danh_Muc_Sach.So_Luong--;
					Update_File_Xoa_DMS(mds);
					cout << "xoa thanh cong" << endl;
				}
				else
				{
					// masach la node bat ki:
					DMS temp = new d_m_s;
					DMS p = mds.Dau_Sach[check_lap_ISBN(ma_isbn, mds)]->Danh_Muc_Sach.pHead;
					while (p != NULL)
					{
						if (p->Ma_Sach == masach)
						{
							temp->pNext = p->pNext;
							delete p;
							mds.Dau_Sach[check_lap_ISBN(ma_isbn, mds)]->Danh_Muc_Sach.So_Luong--;
							Update_File_Xoa_DMS(mds);
							cout << "xoa thanh cong" << endl;
							break;
						}
						temp = p;
						p = p->pNext;
					}
				}
			



			}

		}
}

// Ham xuat danh sach danh muc sach
void Xuat_DMS(MANG_DAU_SACH mds)
{
	for (int i = 0; i < mds.So_Luong; i++)
	{
		DMS	p = mds.Dau_Sach[i]->Danh_Muc_Sach.pHead;
		if (p == NULL) 
		{
			cout << "Ma ISBN: " << mds.Dau_Sach[i]->ISBN;
			cout << "ds trong" << endl;
		}
		else
		{
			//int i = 0;
			cout << "------------  Ma ISBN: " << mds.Dau_Sach[i]->ISBN <<"------------"<< endl;

			while (p != NULL)
			{
				cout << "ma sach :  " << p->Ma_Sach << endl;
				cout <<"vi tri: "<< p->Vi_Tri << endl;
				cout << "Trang thai: " << p->Trang_Thai << " => ";
				if (p->Trang_Thai == 1)
				{
					cout << " da muon ";
				}
				else
					if (p->Trang_Thai == 0)
					{
						cout << " chua muon";
					}
					else // == 2
					{
						cout << "da thanh li";
					}
				cout<< endl << endl << endl;
;
				p = p->pNext;
			}
		}
	}
}


//-----------------


// ------------------------- CAC ham xu li dau sach ------------------------------------

void Add_Node_Dau_Sach(MANG_DAU_SACH& mds, DAU_SACH temp)
{
	mds.Dau_Sach[mds.So_Luong] = new dau_sach;

	mds.Dau_Sach[mds.So_Luong]->ISBN = temp->ISBN;
	mds.Dau_Sach[mds.So_Luong]->Nam_Xuat_Ban = temp->Nam_Xuat_Ban;
	mds.Dau_Sach[mds.So_Luong]->So_Trang = temp->So_Trang;
	mds.Dau_Sach[mds.So_Luong]->Tac_Gia = temp->Tac_Gia;
	mds.Dau_Sach[mds.So_Luong]->Ten_Sach = temp->Ten_Sach;
	mds.Dau_Sach[mds.So_Luong]->The_Loai = temp->The_Loai;
	mds.So_Luong++;
}


// nhap thong tin dau sach
void Nhap_Info_Dau_Sach(MANG_DAU_SACH& mds)
{
	if (mds.So_Luong >= 100)
	{
		cout << "so luong dau sach day >= 100" << endl;
	}
	else
	{
		DAU_SACH temp = new dau_sach;

		cin.ignore();
		cout << "Nhap thong tin ISBN: ";
		getline(cin, temp->ISBN);
		Chuan_Hoa_Chu(temp->ISBN);
		if (temp->ISBN.length() != 4)
		{
			cout << "Ma ISBN co 4 ki tu !! " << endl;
		}
		else if (check_lap_ISBN(temp->ISBN, mds) != -1)
		{
			cout << "da ton tai ma ISBN nay roi ";
		}
		else
		{
			cout << "Nhap thong tin ten sach: ";
			getline(cin, temp->Ten_Sach);
			Chuan_Hoa_Chu(temp->Ten_Sach);
			cout << "Nhap so trang: ";
			cin >> temp->So_Trang;
			cin.ignore();
			//
			cout << "Nhap tac gia: ";
			getline(cin, temp->Tac_Gia);
			Chuan_Hoa_Chu(temp->Tac_Gia);
			cout << "Nhap nam xuat ban: ";
			// kiem tra nam xb =))
			cin >> temp->Nam_Xuat_Ban;
			if ((temp->Nam_Xuat_Ban > 2020) || (temp->Nam_Xuat_Ban < 100))
			{
				cout << "nam khong hop le 100 < nam =< 2020" << endl;
			}
			else
			{
				cin.ignore();
				cout << "Nhap the loai: ";
				getline(cin, temp->The_Loai);
				Chuan_Hoa_Chu(temp->The_Loai);
				// add vao mang
				Add_Node_Dau_Sach(mds, temp);
				cout << " ** da add ** " << endl;
				Update_File_Them_Dau_Sach(temp);
				//Update_File_Xoa_Dau_Sach(mds);
			}

		}
	}
}


void Xuat_Mang_Dau_Sach(MANG_DAU_SACH mds)
{
	for (int i = 0; i < mds.So_Luong; i++) 
	{
		cout << "ISBN: " << mds.Dau_Sach[i]->ISBN << "  "<<endl;
		cout << "Ten sach: " << mds.Dau_Sach[i]->Ten_Sach << "  " << endl;
		cout << "so trang: " << mds.Dau_Sach[i]->So_Trang << " " << endl;
		cout << "tac gia: " << mds.Dau_Sach[i]->Tac_Gia << " " << endl;
		cout << "nam xuat ban: " << mds.Dau_Sach[i]->Nam_Xuat_Ban << " " << endl;
		cout << "the loai: " << mds.Dau_Sach[i]->The_Loai << " " << endl << endl;
	}
}

void Xap_Xep_Mang(DAU_SACH& ds_A, DAU_SACH& ds_B)
{
	if (ds_B->Ten_Sach[0] < ds_A->Ten_Sach[0])
	{
		DAU_SACH temp = new dau_sach;
		temp = ds_A;
		ds_A = ds_B;
		ds_B = temp;
	}
	else
	{
		if (ds_B->Ten_Sach[0] == ds_A->Ten_Sach[0])
		{
			if (ds_B->Ten_Sach.length() < ds_A->Ten_Sach.length())
			{
				DAU_SACH temp = new dau_sach;
				temp = ds_A;
				ds_A = ds_B;
				ds_B = temp;
			}
		}
	}
}

void Xuat_Mang_Dau_Sach_Theo_The_Loai(MANG_DAU_SACH mds)
{
	int pos_1 = 0; //-> vi tri cuoi cua 1 the loai dau; di tu dau den cuoi
	int count = mds.So_Luong;
	int t = 0;
	int* mang_theloai = new int[count]; // mang chua toi da = so luong dau sach


	while (pos_1 != mds.So_Luong) // dau sach ko trong or cuoi cung
	{
		//duyet het mang dau sach
		for (int i = pos_1 + 1; i < mds.So_Luong; i++)
		{
			// neu 2 dau sach ke nhau cung the loai -> bo qua
			if ((mds.Dau_Sach[pos_1]->The_Loai == mds.Dau_Sach[i]->The_Loai) && pos_1 == i + 1)
			{
				pos_1++;
			}
			else
			{
				// neu 2 dau sach ke nhau ko cung the loai -> pass . sau do gap dau sach cung the loai
				if ((mds.Dau_Sach[pos_1]->The_Loai == mds.Dau_Sach[i]->The_Loai) && pos_1 != i + 1)
				{
					DAU_SACH p = new dau_sach;
					p = mds.Dau_Sach[pos_1 + 1]; // pos_1 + 1 la dau sach ko cung the loai
					mds.Dau_Sach[pos_1 + 1] = mds.Dau_Sach[i]; // i la dau sach cung the loai
					mds.Dau_Sach[i] = p;
					pos_1++;
				}
			}
		}
		pos_1++;
		//cout << "so lan the loai khac nhau" << endl;
		mang_theloai[t] = pos_1; // t la vi tri danh dau so the loai khac nhau
		t++; // so luong the loai khac nhau
	}
	//for (int xx = 0; xx < t; xx++)
	//{
	//	cout << "---" << endl;
	//	cout << mang_theloai[xx] << endl;
	//}

	//  -------------
			// ------- xap xep thu tu tang dan theo ten sach cua tung the loai

	for (int j = 0; j < t; j++) // tung phan tu trong mang_theloai;
	{
		if (j == 0)	// phan tu fist trong mang theloai la so luong dau sach cung 1 the loai
		{// xap xep complete;
			for (int k = 0; k < mang_theloai[j] -1; k++) 
			{
				for (int l = k + 1; l < mang_theloai[j]; l++)
				{
					Xap_Xep_Mang(mds.Dau_Sach[k], mds.Dau_Sach[l]); // xap xep tang dan
				}
			}
		}
		else // cac phan tu sau so luon bang [j]- [j - 1];
		{// sau khi qua phan tu dau tien trong mang theloai
			for (int m = mang_theloai[j-1]; m < mang_theloai[j] - 1; m++)
			{
				for (int n = m + 1; n < mang_theloai[j]; n++)
				{
					Xap_Xep_Mang(mds.Dau_Sach[m], mds.Dau_Sach[n]); // xap xep tang dan
				}
			}
		}
	}
	Xuat_Mang_Dau_Sach(mds);
}
void Tim_Sach(MANG_DAU_SACH mds)
{
	int check = 0;
	string tensach;
	cin.ignore();
	cout << "Nhap thong tin ten sach can tim: ";
	getline(cin, tensach);
	Chuan_Hoa_Chu(tensach);
	for (int i = 0; i < mds.So_Luong; i ++ )
	{
		if (mds.Dau_Sach[i]->Ten_Sach == tensach)
		{
			check ++ ;
			cout << endl<<endl<<"tim thay sach" << endl;
			cout << "ma ISBN:  " << mds.Dau_Sach[i]->ISBN << endl;
			cout << "Ten sach: " << mds.Dau_Sach[i]->Ten_Sach << endl;
			cout << "Tac gia: " << mds.Dau_Sach[i]->Tac_Gia << endl;
			cout << "Nam xuat ban: " << mds.Dau_Sach[i]->Nam_Xuat_Ban << endl;
			cout << "The loai: " << mds.Dau_Sach[i]->The_Loai << endl;
			cout << "Cac ma sach: " << endl;
			if (mds.Dau_Sach[i]->Danh_Muc_Sach.pHead == NULL)
			{
				cout << "Ma sach trong." << endl;
			}
			else
			{
				DMS p = mds.Dau_Sach[i]->Danh_Muc_Sach.pHead;
				while (p != NULL)
				{
					cout << "Ma sach: " << p->Ma_Sach << endl;
					cout << "Vi tri: " << p->Vi_Tri << endl;
					cout << "Trang thai: " << p->Trang_Thai;
					if (p->Trang_Thai == 0)
					{
						cout << "chua muon" << endl << endl;
					}
					else
					{
						if (p->Trang_Thai == 1)
						{
							cout << "da muon" << endl << endl;
						}
						else
						{
							if (p->Trang_Thai == 2)
							{
								cout << "da thanh li" << endl << endl;
							}
						}
					}
					p = p->pNext;
				}
			}
		}
	}
	if (check == 0)
	{
		cout << "Khong co Ten sach trong dau sach." << endl;
	}
}

// XOA DAU SACH 
void Xoa_Dau_Sach(MANG_DAU_SACH& mds)
{
	string ISBN;
	cout << "Nhap ma ISBN cua dau sach can xoa: ";
	cin >> ISBN;
	Chuan_Hoa_Chu(ISBN);
	if (ISBN.length() != 4)
	{
		cout << "Ma ISBN co do dai = 4" << endl;
	}
	else
	{
		if (check_lap_ISBN(ISBN, mds) == -1)
		{
			cout << "Ma ISBN khong ton tai" << endl;
		}
		else
		{
			// dau sach khong co ma sach moi dc phep xoa
			if (mds.Dau_Sach[check_lap_ISBN(ISBN, mds)]->Danh_Muc_Sach.So_Luong == 0)
			{
				// tien hanh xoa sach
				for (int i = check_lap_ISBN(ISBN, mds); i < mds.So_Luong - 1; i++)
				{
					mds.Dau_Sach[i] = mds.Dau_Sach[i + 1];
				}
				mds.Dau_Sach[mds.So_Luong] = NULL;
				mds.So_Luong--;
				Update_File_Xoa_Dau_Sach(mds);
				cout << "complete" << endl;
			}
			else
			{
				cout << "Dau sach co ma sach nen khong xoa duoc" << endl;
			}
		}
	}

}

void Sua_Thong_Tin_Dau_Sach(MANG_DAU_SACH& mds)
{
	string ma_isbn;
	cin.ignore();
	cout << "Nhap thong tin isbn cua sach can sua: ";
	getline(cin, ma_isbn);
	Chuan_Hoa_Chu(ma_isbn);
	if (check_lap_ISBN(ma_isbn, mds) == -1)
	{
		cout << "Ma ISBN khong ton tai" << endl;
	}
	else
	{
		string tensach;
		string tacgia;
		string theloai;
		int sotrang;
		int namxuatban;

		cout << "Nhap ten sach moi: ";
		getline(cin, tensach);
		Chuan_Hoa_Chu(tensach);
		cout << "Nhap tac gia: ";
		getline(cin, tacgia);
		Chuan_Hoa_Chu(tacgia);
		cout << "Nhap the loai: ";
		getline(cin, theloai);
		Chuan_Hoa_Chu(theloai);
		cout << "Nhap so trang: ";
		cin >> sotrang;
		cout << "Nhap nam xuat ban: ";
		cin >> namxuatban;
		if (namxuatban > 2020 || namxuatban < 100)
		{
			cout << "Nam xuat ban khong hop le . 100 < < 2020" << endl;
		}
		else
		{
			mds.Dau_Sach[check_lap_ISBN(ma_isbn, mds)]->Ten_Sach = tensach;
			mds.Dau_Sach[check_lap_ISBN(ma_isbn, mds)]->Tac_Gia = tacgia;
			mds.Dau_Sach[check_lap_ISBN(ma_isbn, mds)]->The_Loai = theloai;
			mds.Dau_Sach[check_lap_ISBN(ma_isbn, mds)]->So_Trang = sotrang;
			mds.Dau_Sach[check_lap_ISBN(ma_isbn, mds)]->Nam_Xuat_Ban = namxuatban;
			Update_File_Xoa_Dau_Sach(mds);
			cout << "complete" << endl;
		}
	}
}

// load file dau sach
// doc data tu filee vao bien mds ;
void Doc_File_Dau_Sach(MANG_DAU_SACH& mds)
{
	int t = 0;
	ifstream file_in_MDS;
	file_in_MDS.open("dausach.txt", ios_base::in);
	if (file_in_MDS.fail())
	{
		cout << "file dausach.txt not exist" << endl;
	}
	else
	{
		//cout << "open file dausach.txt thanh cong" << endl;
		while (file_in_MDS.eof() != true)
		{
			if (t == 0)
			{
				//cout << "bo qua dong dau tien" << endl;
				file_in_MDS.ignore(256, '\n');
				t++;
			}
			else
			{
				DAU_SACH ds = new dau_sach;
				getline(file_in_MDS, ds->ISBN, ',');
				Chuan_Hoa_Chu(ds->ISBN);
				getline(file_in_MDS, ds->Ten_Sach, ',');
				Chuan_Hoa_Chu(ds->Ten_Sach);
				file_in_MDS >> ds->So_Trang;
				file_in_MDS.ignore(256, ',');
				getline(file_in_MDS, ds->Tac_Gia, ',');
				Chuan_Hoa_Chu(ds->Tac_Gia);
				file_in_MDS >> ds->Nam_Xuat_Ban;
				file_in_MDS.ignore(256,',');
				getline(file_in_MDS, ds->The_Loai);
				Chuan_Hoa_Chu(ds->The_Loai);
				Add_Node_Dau_Sach(mds, ds);
			}
		}
		file_in_MDS.close();
	}
}

void Load_File_DMS(MANG_DAU_SACH& mds)
{

	int t = 0;
	ifstream file_in_DMS;
	file_in_DMS.open("danhmucsach.txt", ios_base::in);
	if (file_in_DMS.fail())
	{
		cout << "file danhmucsach.txt not exist" << endl;
	}
	else
	{
		while (file_in_DMS.eof() != true)
		{
			if (t == 0)
			{
				//cout << "bo qua dong dau tien file danhmucsach.txt" << endl;
				file_in_DMS.ignore(256, '\n');
				t++;
			}
			else
			{
				DMS ds = new d_m_s;
				string ma_ISBN;
				getline(file_in_DMS, ma_ISBN, ',');
				Chuan_Hoa_Chu(ma_ISBN);
				ds->ISBN = ma_ISBN;
				file_in_DMS >> ds->Ma_Sach;
				//Chuan_Hoa_Chu(ds->Ma_Sach);
				file_in_DMS.ignore(256, ',');
				file_in_DMS >> ds->Trang_Thai;
				file_in_DMS.ignore(256, ',');
				getline(file_in_DMS, ds->Vi_Tri);
				Chuan_Hoa_Chu(ds->Vi_Tri);

				Add_Node_DSLKD(mds.Dau_Sach[check_lap_ISBN(ma_ISBN, mds)]->Danh_Muc_Sach, ds);
			}
		}
		file_in_DMS.close();
	}
}

void Update_File_Them_Dau_Sach(DAU_SACH DS)
{
	fstream f;
	f.open("dausach.txt", ios_base::out | ios_base::app);


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
		f << DS->ISBN << " ,";
		f << DS->Ten_Sach;
		for (int i = 0; i < (30 - DS->Ten_Sach.length()); i++)
		{
			f << " ";
		}
		f << ",";

		f << DS->So_Trang;
		string So_Trang = to_string(DS->So_Trang);
		for (int j = 0; j < (9 - So_Trang.length()); j++)
		{
			f << " ";
		}
		f << ",";
		f << DS->Tac_Gia;
		for (int k = 0; k < (21 - DS->Tac_Gia.length()); k++)
		{
			f << " ";
		}
		f << ",";
		f << DS->Nam_Xuat_Ban;
		string nxb = to_string(DS->Nam_Xuat_Ban);
		for (int l = 0; l < (9 - nxb.length()); l++)
		{
			f << " ";
		}
		f << ",";
		f << DS->The_Loai;
	}
	// 4. Đóng file
	f.close();
}

void Update_File_Xoa_Dau_Sach(MANG_DAU_SACH DS)
{
	fstream f;
	f.open("dausach.txt", ios_base::out);


	if (f.fail())
	{
		cout << "file not exis" << endl;
	}
	else
	{
		// 3. Ghi dữ liệu vào file, trường hợp này ta có data là dữ liệu
		//string data = "Site: www.stdio.vn\nHo Ten: La Kien Vinh\nCong Viec: Dao Tao Lap Trinh Vien";
		//f << data;
		for (int i = 0; i < DS.So_Luong; i++)
		{
			if (i == 0)
			{
				f << "5-ISBN    30-TEN SACH             9-so strang     21-tac gia         9-nam xb    the loai";
			}
			f << endl;
			f << DS.Dau_Sach[i]->ISBN << " ,";
			f << DS.Dau_Sach[i]->Ten_Sach;
			for (int t = 0; t < (30 - DS.Dau_Sach[i]->Ten_Sach.length()); t++)
			{
				f << " ";
			}
			f << ",";

			f << DS.Dau_Sach[i]->So_Trang;
			string So_Trang = to_string(DS.Dau_Sach[i]->So_Trang);
			for (int j = 0; j < (9 - So_Trang.length()); j++)
			{
				f << " ";
			}
			f << ",";
			f << DS.Dau_Sach[i]->Tac_Gia;
			for (int k = 0; k < (21 - DS.Dau_Sach[i]->Tac_Gia.length()); k++)
			{
				f << " ";
			}
			f << ",";
			f << DS.Dau_Sach[i]->Nam_Xuat_Ban;
			string nxb = to_string(DS.Dau_Sach[i]->Nam_Xuat_Ban);
			for (int l = 0; l < (9 - nxb.length()); l++)
			{
				f << " ";
			}
			f << ",";
			f << DS.Dau_Sach[i]->The_Loai;
		}	
	}

	// 4. Đóng file
	f.close();
}

void Update_File_Them_DMS(DMS dms)
{
	fstream f;
	f.open("danhmucsach.txt", ios_base::out | ios_base::app);
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
		f << dms->ISBN << " ,";
		f << dms->Ma_Sach;
		string masach = to_string(dms->Ma_Sach);
		if (masach.length() == 1)
		{
			f << "  ,";
		}
		else
		{
			f << " ,";
		}
		

		f << dms->Trang_Thai;
		f << "  ,";
		f << dms->Vi_Tri;

	}
	// 4. Đóng file
	f.close();
}

void Update_File_Xoa_DMS(MANG_DAU_SACH mds)
{
	fstream f;
	f.open("danhmucsach.txt", ios_base::out);
	if (f.fail())
	{
		cout << "file not exis" << endl;
	}
	else
	{
		// duyet tung thang dau sach
		for (int i = 0; i < mds.So_Luong; i++)
		{
			if (i == 0)
			{
				f << "//ma ISBN - ma sach - trang thai - vi tri";
			}
			if (mds.Dau_Sach[i]->Danh_Muc_Sach.pHead != NULL)
			{
				DMS p = mds.Dau_Sach[i]->Danh_Muc_Sach.pHead;
				while (p != NULL)
				{
					// ghi sach dong dau tien => chu thich
						f << endl;
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
						f << p->Trang_Thai;
						f << "  ,";
						f << p->Vi_Tri;

					p = p->pNext;
				}
			}
		}
	}
	f.close();
}

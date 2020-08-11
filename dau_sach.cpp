#include"dau_sach.h"




// ham kiem tra ma ISBN cua DAUSACH co khong
int check_lap_ISBN(string a, MANG_DAU_SACH mds)
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
						return i;
					}
				}
			}

		}

	}
	return -1;

}

// cac ham xua li danh muc sach => 1 phan cua dau sach


int check_lap(string a, MANG_DAU_SACH mds) { // kt lap khi tao ma sach auto
	for (int i = 0; i < mds.So_Luong; i++)
	{
		DMS p = mds.Dau_Sach[i]->Danh_Muc_Sach.pHead;
		while (p != NULL)
		{
			if (a[0] == p->Ma_Sach[0])
			{
				if (a[1] == p->Ma_Sach[1])
				{
					if (a[2] == p->Ma_Sach[2])
					{
						if (a[3] == p->Ma_Sach[3]) {
							return i;
						}
					}
				}
			}
			else
			{
				p = p->pNext;

			}
		}
	}
	return -1;
}

string Tao_ma_Sach(MANG_DAU_SACH mds)
{
	string mathe = "XXXX";
	do
	{
		for (int i = 0; i < 4; i++) {
			mathe[i] = rand() % (90 - 65 + 1) + 65;
			//mathe[i] = rand() % (b - a + 1) + a; -> (a-b)
		}
	} while (check_lap(mathe, mds) != -1);
	return mathe;
}









// Ham xu li tam them danh muc sach
void Add_Node_DMS(DS_DMS& dms, DMS temp)
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
	int k = 0;
	do
	{
		if (k == 0) {
			cin.ignore();
		}
		k++;


		cout << " Nhap ma ISBN cua DAU SACH de them danh muc sach: (4 ki tu) ";

		getline(cin, tim_DS);
		while (tim_DS.length()!= 4)
		{
			cout << "do dai ma ISBN chi co 4 ki tu !!!  Vui long nhap lai: ";
			getline(cin, tim_DS);
		}
	} while (check_lap_ISBN(tim_DS, mds) == -1);

	cout << "Ma ISBN hop le !!!" << endl;
	DMS temp = new d_m_s;
	// tao ma sach tu dong 
	//cin.ignore();

	cout << "Ma sach duoc tao tu dong !!" << endl;
	temp->Ma_Sach = Tao_ma_Sach(mds);
	cout << "Nhap vi tri : ";
	getline(cin, temp->Vi_Tri);
	//mds[check_lap_ISBN()]
	Add_Node_DMS(mds.Dau_Sach[check_lap_ISBN(tim_DS, mds)]->Danh_Muc_Sach, temp);
}

// Ham xuat danh sach danh muc sach
void Xuat_DMS(MANG_DAU_SACH mds)
{
	for (int i = 0; i < mds.So_Luong; i++)
	{
		DMS	p = mds.Dau_Sach[i]->Danh_Muc_Sach.pHead;
		if (p == NULL) 
		{
			cout << "ds trong" << endl;
		}
		else
		{
			int i = 1;
			while (p != NULL)
			{
				cout << "ds_dms thu " << i << " : ";
				cout <<"vi tri: "<< p->Vi_Tri << endl;
				cout << "ma sach :  " << p->Ma_Sach<<endl;
				cout << "Trang thai: " << p->Trang_Thai << endl;
				i++;
				Sleep(100);
				p = p->pNext;
			}
		}
	}
}


//-----------------

// ------------------------- CAC ham xu li dau sach ------------------------------------

void Add_Dau_Sach(MANG_DAU_SACH& mds, DAU_SACH temp)
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
//
void Nhap_Info_Dau_Sach(MANG_DAU_SACH& mds)
{
	DAU_SACH temp = new dau_sach;

	cin.ignore();
	cout << "Nhap thong tin ISBN: ";
	getline(cin, temp->ISBN);
	while (temp->ISBN.length() != 4)
	{
		cout << "Ma ISBN co 4 ki tu !! Nhap lai ISBN: ";
		getline(cin, temp->ISBN);
	}
	cout << "Nhap thong tin ten sach: ";
	getline(cin, temp->Ten_Sach);
	cout << "Nhap so trang: ";
	cin >> temp->So_Trang;
	cin.ignore();
//
	cout << "Nhap tac gia: ";
	getline(cin, temp->Tac_Gia);
	cout << "Nhap nam xuat ban: ";
	// kiem tra nam xb =))
	cin >> temp->Nam_Xuat_Ban;
	cin.ignore();

	cout << "Nhap the loai: ";
	getline(cin, temp->The_Loai);

	// add vao mang
	Add_Dau_Sach(mds, temp);
//	 //giai phong temp
//	/*temp = NULL;
//	delete temp;*/
}

void Xuat_Mang_Dau_Sach(MANG_DAU_SACH mds)
{
	for (int i = 0; i < mds.So_Luong; i++) 
	{
		cout << "********* ***** **********" << endl;
		cout << "ISBN: " << mds.Dau_Sach[i]->ISBN << endl;
		cout << "Ten sach: " << mds.Dau_Sach[i]->Ten_Sach << endl;
		cout << "so trang: " << mds.Dau_Sach[i]->So_Trang << endl;
		cout << "tac gia: " << mds.Dau_Sach[i]->Tac_Gia << endl;
		cout << "nam xuat ban: " << mds.Dau_Sach[i]->Nam_Xuat_Ban << endl;
		cout << "the loai: " << mds.Dau_Sach[i]->The_Loai << endl;

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
		cout << "open file dausach.txt thanh cong" << endl;
		while (file_in_MDS.eof() != true)
		{
			if (t == 0)
			{
				cout << "bo qua dong dau tien" << endl;
				file_in_MDS.ignore(256, '\n');
				t++;
			}
			else
			{
				DAU_SACH ds = new dau_sach;
				cout << "da doc data file " << endl;
				getline(file_in_MDS, ds->ISBN, ',');
				getline(file_in_MDS, ds->Ten_Sach, ',');
				file_in_MDS >> ds->So_Trang;
				file_in_MDS.ignore(256, ',');
				getline(file_in_MDS, ds->Tac_Gia, ',');
				file_in_MDS >> ds->Nam_Xuat_Ban;
				file_in_MDS.ignore(256,',');
				getline(file_in_MDS, ds->The_Loai);
				//file_in_MDS.ignore();
				cout << "doc xong data file" << endl;
				//Sleep(1000);
				Add_Dau_Sach(mds, ds);
	/*			cout << " data cua con tro ds: " << endl;
				cout << ds->ISBN << endl;
				cout << ds->Ten_Sach << endl;
				cout << ds->So_Trang << endl;
				cout << ds->Tac_Gia << endl;
				cout << ds->Nam_Xuat_Ban << endl;

				cout << ds->The_Loai << endl;*/
			}
		}
		file_in_MDS.close();
	}
}
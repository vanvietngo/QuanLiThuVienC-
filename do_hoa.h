#pragma once
#include"the_doc_gia.h"
#include"ve_hinh.h"

// ----  khai bao ham phu -----
int Sua_Node_Cay_Nhi_Phan(TDG& node, int mathe);
void Ghi_Data_TDG(TDG node, int mang[]);
void Ghi_Data_DAUSACH(DAU_SACH ds, int  mang_toa_do[]);
void Ghi_Data_Danh_Muc_Sach_Cua_1_Dau_Sach(DMS node, int mang_toa_do[]);
void Ghi_Data_DSMT(TDG node_tdg, MUON_TRA node, int mang_toa_do[]);
void Ghi_Data_TDG_Muon_Qua_Han(TDG node, time_t so_ngay, MUON_TRA MT, MANG_DAU_SACH mds, int mang[]);


//------------------------------------

// ------------  Ham xu li chinh co do hoa --------------
// ---------------- quan li the doc gia -------------------
int THEM_THE_DOC_GIA(DS_TDG& ds_tdg, TDG Mang[]) 
{
	Normal();
	system("cls");
	ve_khung_basic_pink();

	if (ds_tdg.So_Luong > 100)
	{
		int cot = 45, dong = 18;
		string rep = "so luong the doc gia da day(>=100). Khong the them";
		gotoxy(cot, dong);
		Normal();
		SetColor(12);
		cout << rep;
		gotoxy(cot + 20, dong + 3);
		HightLight_pink();
		cout << "   EXIT   ";
		Bam_Nut_Exit();
	}
	else
	{
		int cot = 40, dong = 8;
		TDG tdg = new the_doc_gia;

		tdg->Ma_The = Tao_Ma_TDG(ds_tdg.The_Doc_Gia);
		tdg->Trang_Thai_The = 1; // tao moi auto hoat dong

		// nhap ho
		Hight_text_pink();
		gotoxy(cot, dong);
		cout << "Nhap Ho doc gia : ";
		//cin.ignore();
		Normal();
		getline(cin, tdg->Ho);
		Chuan_Hoa_Chu(tdg->Ho);
		// check ho = null
		if (tdg->Ho.length() == NULL)
		{
			int check = 0;
			//
			gotoxy(cot + 17, dong + 16);
			Hight_text_pink();
			cout << "  __ CHUA NHAP HO DOC GIA __  ";
			//
			gotoxy(cot + 10, dong + 20);
			HightLight_pink();
			cout << "   tiep tuc   ";
			//
			gotoxy(cot + 40, dong + 20);
			Normal();
			cout << "    thoat     ";
			Check_Left_Right(check);
			if (check == 0)
			{
				THEM_THE_DOC_GIA(ds_tdg, Mang);
				int stt = 0;
				Chuyen_Node_Vao_Mang(ds_tdg.The_Doc_Gia, Mang, stt);
				return 0;
			}
			else
			{
				return 0;
			}
		}

		// nhap ten
		Hight_text_pink();
		gotoxy(cot, dong+2);
		cout << "Nhap Ten doc gia : ";
		//cin.ignore();
		Normal();
		getline(cin, tdg->Ten);
		Chuan_Hoa_Chu(tdg->Ten);
		// check ten = null
		if (tdg->Ten.length() == NULL)
		{
			int check = 0;
			//
			gotoxy(cot + 17, dong + 16);
			Hight_text_pink();
			cout << "  __ CHUA NHAP TEN DOC GIA __  ";
			//
			gotoxy(cot + 10, dong + 20);
			HightLight_pink();
			cout << "   tiep tuc   ";
			//
			gotoxy(cot + 40, dong + 20);
			Normal();
			cout << "    thoat     ";
			Check_Left_Right(check);
			if (check == 0)
			{
				THEM_THE_DOC_GIA(ds_tdg, Mang);
				int stt = 0;
				Chuyen_Node_Vao_Mang(ds_tdg.The_Doc_Gia, Mang, stt);
				return 0;
			}
			else
			{
				return 0;
			}
		}

		// nhap phai
		Hight_text_pink();
		gotoxy(cot, dong + 4);
		cout << "Nhap Phai doc gia: ";
		//cin.ignore();
		Normal();
		getline(cin, tdg->Phai);
		Chuan_Hoa_Chu(tdg->Phai);

		if (tdg->Phai == "NAM" || tdg->Phai == "NU")
		{
			Them_Node_Cay_Nhi_Phan(ds_tdg.The_Doc_Gia, tdg);
			ds_tdg.So_Luong++;
			// 
			Update_File_Them_thedocgia(tdg);
			gotoxy(cot + 25, dong + 20);
			HightLight_pink();
			cout << "   complete   ";
			Bam_Nut_Exit();
		}
		else
		{
				int check = 0;
				//
				gotoxy(cot + 17, dong + 16);
				Hight_text_pink();
				cout << "  __ PHAI DOC GIA KHONG HOP LE __  ";
				//
				gotoxy(cot + 10, dong + 20);
				HightLight_pink();
				cout << "   tiep tuc   ";
				//
				gotoxy(cot + 40, dong + 20);
				Normal();
				cout << "    thoat     ";
				Check_Left_Right(check);
				if (check == 0)
				{
					THEM_THE_DOC_GIA(ds_tdg, Mang);
					return 0;
				}
				else
				{
					return 0;
				}
			
		}


	}
	return 0;
}

int XOA_THE_DOC_GIA(DS_TDG& ds_tdg, TDG Mang[])
{
	int cot = 40, dong = 8;
	int mathe;
	Normal();
	system("cls");
	ve_khung_basic_pink();

	// nhap ho
	Hight_text_pink();
	gotoxy(cot, dong);
	cout << "NHAP MA THE CAN XOA : ";
	//cin.ignore();
	Normal();
	cin >> mathe;
	// check ma the = true

	if (Check_Ma_TDG(ds_tdg.The_Doc_Gia, mathe) == 0)
	{
		int check = 0;
		//
		Hight_text_pink();
		gotoxy(cot + 17, dong + 16);
		cout << "  __ MA THE KHONG TON TAI __  ";
		//
		HightLight_pink();
		gotoxy(cot + 10, dong + 20);
		cout << "   tiep tuc   ";
		//
		gotoxy(cot + 40, dong + 20);
		Normal();
		cout << "    thoat     ";
		Check_Left_Right(check);
		if (check == 0)
		{
			XOA_THE_DOC_GIA(ds_tdg, Mang);
			return 0;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		//xoa thanh cong
		if (Xoa_1_Node_Cay_Nhi_Phan(ds_tdg.The_Doc_Gia, mathe) == 1)
		{
			//  
			//Update_File_Them_thedocgia(tdg);
			gotoxy(cot + 25, dong + 20);
			HightLight_pink();
			ds_tdg.So_Luong--;
			int stt = 0;
			Chuyen_Node_Vao_Mang(ds_tdg.The_Doc_Gia, Mang, stt);
			Update_File_Xoa_thedocgia(ds_tdg, Mang);
			cout << "   complete   ";
			Bam_Nut_Exit();
			return 0;
		}
		else
		{
			// doc gia muon sach ko duoc xoa
			if (Xoa_1_Node_Cay_Nhi_Phan(ds_tdg.The_Doc_Gia, mathe) == -1)
			{
				int check = 0;
				//
				Hight_text_pink();
				gotoxy(cot + 17, dong + 16);
				cout << "  __ DOC GIA DA MUON SACH __  ";
				//
				HightLight_pink();
				gotoxy(cot + 10, dong + 20);
				cout << "   tiep tuc   ";
				//
				gotoxy(cot + 40, dong + 20);
				Normal();
				cout << "    thoat     ";
				Check_Left_Right(check);
				if (check == 0)
				{
					XOA_THE_DOC_GIA(ds_tdg, Mang);
					return 0;
				}
				else
				{
					return 0;
				}
			}
		}
	}
	return 0;
}

int HIEU_CHINH_THE_DOC_GIA(DS_TDG& ds_tdg, TDG Mang[])
{
	//
	int cot = 40, dong = 8;
	int mathe;
	Normal();
	system("cls");
	ve_khung_basic_pink();

	//
		// nhap ho
	Hight_text_pink();
	gotoxy(cot, dong);
	cout << "NHAP MA THE CAN SUA : ";
	Normal();
	cin >> mathe;
	// check ma the = true
	if (Check_Ma_TDG(ds_tdg.The_Doc_Gia, mathe) == 0)
	{
		int check = 0;
		//
		Hight_text_pink();
		gotoxy(cot + 17, dong + 16);
		cout << "  __ MA THE KHONG TON TAI __  ";
		//
		HightLight_pink();
		gotoxy(cot + 10, dong + 20);
		cout << "   tiep tuc   ";
		//
		gotoxy(cot + 40, dong + 20);
		Normal();
		cout << "    thoat     ";
		Check_Left_Right(check);
		if (check == 0)
		{
			HIEU_CHINH_THE_DOC_GIA(ds_tdg, Mang);
			return 0;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		if (Sua_Node_Cay_Nhi_Phan(ds_tdg.The_Doc_Gia, mathe) == 1)
		{
			int stt = 0;
			Chuyen_Node_Vao_Mang(ds_tdg.The_Doc_Gia, Mang, stt);
			Update_File_Xoa_thedocgia(ds_tdg, Mang);
			// cout<<"complete
			return 0;
		}
	}
	return 0;
}

int IN_TDG_THEO_MATHE_TANG_DAN(DS_TDG ds_tdg)
{
	TDG MANG[Max];
	int stt = 0;
	Chuyen_Node_Vao_Mang_Tang_Dan_Ma_The(ds_tdg.The_Doc_Gia, MANG, stt);
	Ve_Khung_Xuat_TDG();
	//
	int cot_1 = 10;
	int	dong_1 = 5 + 3;
	int	cot_mathe = cot_1;
	int cot_ho = cot_1 + 23;
	int cot_ten = cot_1 + 52;
	int cot_phai = cot_1 + 90;
	int cot_trangthai = cot_1 + 113;
	int soluong_node = ds_tdg.So_Luong;
	int check = 1;
	//
	int mang_toado[7] =
	{
	 cot_1,
	 dong_1,
	 cot_mathe,
	 cot_ho,
	 cot_ten ,
	 cot_phai,
	 cot_trangthai
	};
	int k = 0;
	int tam = 0;

	// in mang
	while (k < (ds_tdg.So_Luong) ) // k la so phan tu trong 1 trang
	{
		
		Ghi_Data_TDG(MANG[k], mang_toado);
		k = k + 1;

		// trang dau tien
		if ((k == 12) && (k != ds_tdg.So_Luong))
		{
			// 
			Normal();
			gotoxy(10, 5 + 28);
			cout << "   EXIT   ";
			gotoxy(10 + 113, 5 + 28);
			cout << "   NEXT   ";
			//
			Check_Left_Right_TEXT_DONG(check, "   EXIT   ", "   NEXT   "); //0: exit - 2 next
			// exit
			if (check == 0)// exit
			{
				return 0;
			}
			// next
			if (check == 2)// next
			{
				tam = 12;
				Ve_Khung_Xuat_TDG(); // xoa data 
				mang_toado[1] = 8;
			}
		}

		//// cac trang o giua

		if ((k > 12) && (k % 12 == 0) && (k != ds_tdg.So_Luong))
		{
			check = 1;
			Check_Left_Mid_Right(check);
			// exit
			if (check == 1)
			{
				return 0;
			}
			// next
			if (check == 2)
			{
				tam = tam + 12;
				Ve_Khung_Xuat_TDG(); // xoa data 
				mang_toado[1] = 8;
			}
			if (check == 0) // pre
			{
				tam = tam - 12;
				Ve_Khung_Xuat_TDG(); // xoa data 
				mang_toado[1] = 8;
				k = k - 24;
			}
		}

		//// trang cuoi cung co trang giua
		if (k == ds_tdg.So_Luong &&(k > 24))
		{
			// 
			Normal();
			gotoxy(10, 5 + 28);
			cout << "   PRE   ";
			gotoxy(10 + 113, 5 + 28);
			cout << "   EXIT   ";
			//
			Check_Left_Right_TEXT_DONG(check, "   PRE   ", "   EXIT   ");
			// exit
			if (check == 2)
			{
				return 0;
			}
			//pre
			if (check == 0)
			{
				Ve_Khung_Xuat_TDG();
				mang_toado[1] = 8;
				if (k % 12 == 0) // k la cuoi trang full
				{
					k = k - 24;
				}
				else // k la cuoi trang nhung ko full
				{
					k = k - tam + 12;
				}

			}
		}
		// trang dau cung la trang cuoi
		if ((k == ds_tdg.So_Luong) && (k <= 12))
		{


			gotoxy(cot_1 + 57, dong_1 + 25);
			HightLight_pink();
			cout << "   EXIT   ";
			Bam_Nut_Exit();
			return 0;
		}
		// trang cuoi cung ko co trang giua
		if ((k == ds_tdg.So_Luong) && (k <= 24))
		{
			// 
			Normal();
			gotoxy(10, 5 + 28);
			cout << "   PRE   ";
			gotoxy(10 + 113, 5 + 28);
			cout << "   EXIT   ";
			//
			Check_Left_Right_TEXT_DONG(check, "   PRE   ", "   EXIT   ");
			if (check == 2) // exit
			{
				return 0;
			}
			//pre
			if (check == 0)
			{
				Ve_Khung_Xuat_TDG();
				mang_toado[1] = 8;
				k = 0;
			}
		}
	}
		return 0;
}

int IN_TDG_THEO_TEN_TANG_DAN(DS_TDG ds_tdg)
{
	TDG MANG[Max];
	int stt = 0;
	Chuyen_Node_Vao_Mang(ds_tdg.The_Doc_Gia, MANG, stt);
	//XAP XEP MANG
	for (int i = 0; i < ds_tdg.So_Luong - 1; i++)
	{
		for (int j = i + 1; j < ds_tdg.So_Luong; j++)
		{
			Xap_Xep_TDG(MANG[i], MANG[j]);
		}
	}

	Ve_Khung_Xuat_TDG();
	//
	int cot_1 = 10;
	int	dong_1 = 5 + 3;
	int	cot_mathe = cot_1;
	int cot_ho = cot_1 + 23;
	int cot_ten = cot_1 + 52;
	int cot_phai = cot_1 + 90;
	int cot_trangthai = cot_1 + 113;
	int soluong_node = ds_tdg.So_Luong;
	int check = 1;
	//
	int mang_toado[7] =
	{
	 cot_1,
	 dong_1,
	 cot_mathe,
	 cot_ho,
	 cot_ten ,
	 cot_phai,
	 cot_trangthai
	};
	int k = 0;
	int tam = 0;

	// in mang
	while (k < (ds_tdg.So_Luong)) // k la so phan tu trong 1 trang
	{

		Ghi_Data_TDG(MANG[k], mang_toado);
		k = k + 1;

		// trang dau tien
		if ((k == 12) && (k != ds_tdg.So_Luong))
		{
			// 
			Normal();
			gotoxy(10, 5 + 28);
			cout << "   EXIT   ";
			gotoxy(10 + 113, 5 + 28);
			cout << "   NEXT   ";
			//
			Check_Left_Right_TEXT_DONG(check, "   EXIT   ", "   NEXT   "); //0: exit - 2 next
			// exit
			if (check == 0)// exit
			{
				return 0;
			}
			// next
			if (check == 2)// next
			{
				tam = 12;
				Ve_Khung_Xuat_TDG(); // xoa data 
				mang_toado[1] = 8;
			}
		}

		//// cac trang o giua

		if ((k > 12) && (k % 12 == 0) && (k != ds_tdg.So_Luong))
		{
			check = 1;
			Check_Left_Mid_Right(check);
			// exit
			if (check == 1)
			{
				return 0;
			}
			// next
			if (check == 2)
			{
				tam = tam + 12;
				Ve_Khung_Xuat_TDG(); // xoa data 
				mang_toado[1] = 8;
			}
			if (check == 0) // pre
			{
				tam = tam - 12;
				Ve_Khung_Xuat_TDG(); // xoa data 
				mang_toado[1] = 8;
				k = k - 24;
			}
		}

		//// trang cuoi cung co trang giua
		if (k == ds_tdg.So_Luong && (k > 24))
		{
			// 
			Normal();
			gotoxy(10, 5 + 28);
			cout << "   PRE   ";
			gotoxy(10 + 113, 5 + 28);
			cout << "   EXIT   ";
			//
			Check_Left_Right_TEXT_DONG(check, "   PRE   ", "   EXIT   ");
			// exit
			if (check == 2)
			{
				return 0;
			}
			//pre
			if (check == 0)
			{
				Ve_Khung_Xuat_TDG();
				mang_toado[1] = 8;
				if (k % 12 == 0) // k la cuoi trang full
				{
					k = k - 24;
				}
				else // k la cuoi trang nhung ko full
				{
					k = k - tam + 12;
				}

			}
		}
		// trang dau cung la trang cuoi
		if ((k == ds_tdg.So_Luong) && (k <= 12))
		{


			gotoxy(cot_1 + 57, dong_1 + 25);
			HightLight_pink();
			cout << "   EXIT   ";
			Bam_Nut_Exit();
			return 0;
		}
		// trang cuoi cung ko co trang giua
		if ((k == ds_tdg.So_Luong) && (k <= 24))
		{
			// 
			Normal();
			gotoxy(10, 5 + 28);
			cout << "   PRE   ";
			gotoxy(10 + 113, 5 + 28);
			cout << "   EXIT   ";
			//
			Check_Left_Right_TEXT_DONG(check, "   PRE   ", "   EXIT   ");
			if (check == 2) // exit
			{
				return 0;
			}
			//pre
			if (check == 0)
			{
				Ve_Khung_Xuat_TDG();
				mang_toado[1] = 8;
				k = 0;
			}
		}
	}

	return 0;
}

int IN_CAC_SACH_DA_MUON_CUA_MOT_DOC_GIA(DS_TDG ds_tdg)
{
	int cot = 40, dong = 8;
	int mathe;
	Normal();
	system("cls");
	ve_khung_basic_pink();

	// nhap ho
	Hight_text_pink();
	gotoxy(cot, dong);
	cout << "NHAP MA THE CAN XEM : ";
	Normal();
	cin >> mathe;
	// check ma the = false
	TDG Temtdg;
	if (Tim_TDG_Muon_Sach(mathe,ds_tdg.The_Doc_Gia, Temtdg)==-1)
	{
		int chon = 0;
		//
		Hight_text_pink();
		gotoxy(cot + 17, dong + 16);
		//
		cin.ignore();
		cout << "  __ MA THE KHONG TON TAI __  ";
		//
		HightLight_pink();
		gotoxy(cot + 10, dong + 20);
		cout << "   tiep tuc   ";
		//
		gotoxy(cot + 40, dong + 20);
		Normal();
		cout << "    thoat     ";
		Check_Left_Right(chon);
		if (chon == 0)
		{
			IN_CAC_SACH_DA_MUON_CUA_MOT_DOC_GIA(ds_tdg);
		}
		else
		{
			return 0;
		}
	}
	else
	{
		// ma the hop le roi
		// ve khung xuat thong tin tdg - dsmt
		Ve_Khung_Xuat_Danh_Sach_MT_Cua_Mot_DG();
		// dien thong tin the doc gia muon sach
			//
		int cot_1 = 10;
		int	dong_1 = 5 + 3;
		int	cot_mathe = cot_1;
		int cot_ho = cot_1 + 23;
		int cot_ten = cot_1 + 52;
		int cot_phai = cot_1 + 90;
		int cot_trangthai = cot_1 + 113;
		int soluong_node = ds_tdg.So_Luong;
		int check = 1;
		//
		int mang_toado_DG[7] =
		{
		 cot_1,
		 dong_1,
		 cot_mathe,
		 cot_ho,
		 cot_ten ,
		 cot_phai,
		 cot_trangthai
		};
		Ghi_Data_TDG(Temtdg, mang_toado_DG);

		
		// ghi data danh sach muon tra
		int d_1 = 17;
		int c_1 = 9;
		int c_ma_tdg = c_1;
		int c_isbn = c_1 + 14;
		int c_ms = c_1 + 30;
		int c_tt = c_1 + 51;
		int c_muon = c_1+ 76;
		int c_tra = c_1 + 115;
		int mang_toa_do_dsmt[8] =
		{
		 d_1,
		 c_1,
		 c_ma_tdg,
		 c_isbn,
		 c_ms,
		 c_tt,
		 c_muon,
		 c_tra
		};
		MUON_TRA p = Temtdg->ds_Muon_Tra.pHead;

		while (p != NULL)
		{
			Ghi_Data_DSMT(Temtdg, p, mang_toa_do_dsmt);
			p = p->pNext;
			mang_toa_do_dsmt[1]++;

		}
		//Ghi_Data_Danh_Muc_Sach_Cua_1_Dau_Sach(Temtdg, Temtdg, mang_toado_DG);
		gotoxy(cot_1 + 57, dong_1 + 25);
		HightLight_pink();
		cout << "   EXIT   ";
		Bam_Nut_Exit();
		return 0;
		Bam_Nut_Exit();
		//Ghi_Data_TDG()
	}

	return 0;
}

int IN_THE_DOC_GIA_MUON_SACH_QUA_HAN_GIAM_DAN(DS_TDG ds_tdg, MANG_DAU_SACH mds)
{
	Ve_Khung_Xuat_Doc_Gia_Muon_Qua_Han(12);
	//
	int st = 0; // so luong phan tu trong mang
	int sl = ds_tdg.So_Luong;
	int stt1 = 0;
	TDG mang[100];			// mang tdg
	TDG mangQUAHAN[100];	// mang tdg qua han ++ khi co ma sach qua han
	MUON_TRA muontra[100];  // chua gia tri ngay muon cua tdg qua han

	time_t songayquahan[100];
	Chuyen_Node_Vao_Mang(ds_tdg.The_Doc_Gia, mang, stt1);

	// lay cac doc gia qua han vao mangquahan;
	for (int i = 0; i < ds_tdg.So_Luong; i++)
	{
		if (mang[i]->ds_Muon_Tra.So_Luong != 0) // mang[i] cac the doc gia
		{
			//cout << "so luong muon sach = " << mang[i]->ds_Muon_Tra.So_Luong << endl;
			MUON_TRA p = mang[i]->ds_Muon_Tra.pHead;
			while (p != NULL)
			{
				time_t now = time(0);
				if (Check_Qua_Han_Muon_Sach(p->Ngay_Muon, now) == 1)
				{
					mangQUAHAN[st] = new the_doc_gia;
					mangQUAHAN[st] = mang[i];
					songayquahan[st] = (now - p->Ngay_Muon) / 86400;
					muontra[st] = p;
					st++;
					//break;
				}
				p = p->pNext;
			}
		}
	}
	//xap xep tang dan;
	for (int x = 0; x < st - 1; x++)
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
				MUON_TRA te;
				te = muontra[x];
				muontra[x] = muontra[c];
				muontra[c] = te;

			}
		}
	}
	//
	int cot_1 = 8;
	int	dong_1 = 5 + 3;
	int	cot_mathe = cot_1+1;
	int cot_ho = cot_1 + 13;
	int cot_ten = cot_1 + 30;
	int cot_MS = cot_1 + 56;
	int cot_TENSACH = cot_1 + 65;
	int cot_NGAYMUON = cot_1 + 95;
	int cot_SONGAY = cot_1 + 125;


	int soluong_node = st;
	int check = 1;
	//
	int mang_toado[9] =
	{
	 cot_1,
	 dong_1,
	 cot_mathe,
	 cot_ho,
	 cot_ten ,
	 cot_MS,
	 cot_TENSACH,
	 cot_NGAYMUON,
	 cot_SONGAY
	};
	int k = 0;
	int tam = 0;

	//
		// in ra
	//for (int z = 0; z < st; z++)
	//{
	//	tm DMY_MUON = Doi_So_Giay_Thanh_DMY(muontra[z]->Ngay_Muon);
	//	
	//	cout << "ma the: " << mangQUAHAN[z]->Ma_The << endl;
	//	cout << "Ho: " << mangQUAHAN[z]->Ho << endl;
	//	cout << "Ten: " << mangQUAHAN[z]->Ten << endl;
	//	cout << "Ten sach: " << mds.Dau_Sach[check_lap_ISBN(muontra[z]->ISBN, mds)]->Ten_Sach << endl;
	//	cout << "Ma sach: " << muontra[z]->Ma_Sach << endl;

	//	cout << "Ngay muon: " << DMY_MUON.tm_hour << ":" << DMY_MUON.tm_min << ":" << DMY_MUON.tm_sec
	//		<< " - " << DMY_MUON.tm_mday << "/" << 1 + DMY_MUON.tm_mon << "/" << 1900 + DMY_MUON.tm_year << endl;
	//	cout << "so ngay qua han: " << songayquahan[z] << endl << endl;
	//	//
	//}
	while (k < st)
	{
		Ghi_Data_TDG_Muon_Qua_Han(mangQUAHAN[k], songayquahan[k],muontra[k],mds, mang_toado);
		k = k + 1;

		// trang dau tien co sl > 12
		if ((k == 12) && (k != mds.So_Luong))
		{
			// 
			Normal();
			gotoxy(10, 5 + 28);
			cout << "   EXIT   ";
			gotoxy(10 + 113, 5 + 28);
			cout << "   NEXT   ";
			//
			Check_Left_Right_TEXT_DONG(check, "   EXIT   ", "   NEXT   "); //0: exit - 2 next
			// exit
			if (check == 0)// exit
			{
				return 0;
			}
			// next
			if (check == 2)// next
			{
				tam = 12;
				Ve_Khung_Xuat_Dau_Sach(); // xoa data 
				mang_toado[1] = 8;
			}
		}

		//// cac trang o giua

		if ((k > 12) && (k % 12 == 0) && (k != mds.So_Luong))
		{
			check = 1;
			Check_Left_Mid_Right(check);
			// exit
			if (check == 1)
			{
				return 0;
			}
			// next
			if (check == 2)
			{
				tam = tam + 12;
				Ve_Khung_Xuat_Dau_Sach(); // xoa data 
				mang_toado[1] = 8;
			}
			if (check == 0) // pre
			{
				tam = tam - 12;
				Ve_Khung_Xuat_Dau_Sach(); // xoa data 
				mang_toado[1] = 8;
				k = k - 24;
			}
		}

		//// trang cuoi cung - cos trang gia
		if ((k == mds.So_Luong) && (k > 24))
		{
			// 
			Normal();
			gotoxy(10, 5 + 28);
			cout << "   PRE   ";
			gotoxy(10 + 113, 5 + 28);
			cout << "   EXIT   ";
			//
			Check_Left_Right_TEXT_DONG(check, "   PRE   ", "   EXIT   ");
			// exit
			if (check == 2)
			{
				return 0;
			}
			//pre
			if (check == 0)
			{
				Ve_Khung_Xuat_Dau_Sach();
				mang_toado[1] = 8;
				if (k % 12 == 0)
				{
					k = k - 24;
				}
				else
				{
					k = k - tam + 12;
				}

			}
		}
		// trang cuoi cung nhung cung la trang dau tien
		if ((k == mds.So_Luong) && (k <= 12))
		{


			gotoxy(cot_1 + 57, dong_1 + 25);
			HightLight_pink();
			cout << "   EXIT   ";
			Bam_Nut_Exit();
			return 0;
		}
		// trang cuoi cung koco trang giua
				// trang cuoi cung ko co trang giua
		if ((k == mds.So_Luong) && (k <= 24))
		{
			// 
			Normal();
			gotoxy(10, 5 + 28);
			cout << "   PRE   ";
			gotoxy(10 + 113, 5 + 28);
			cout << "   EXIT   ";
			//
			Check_Left_Right_TEXT_DONG(check, "   PRE   ", "   EXIT   ");
			if (check == 2) // exit
			{
				return 0;
			}
			//pre
			if (check == 0)
			{
				Ve_Khung_Xuat_Dau_Sach();
				mang_toado[1] = 8;
				k = 0;
			}
		}
	
	}
	Bam_Nut_Exit();
	return 0;
}

int MUON_SACH(DS_TDG& ds_tdg, MANG_DAU_SACH mds)
{
	// kt ma the hop le
	int cot = 40, dong = 8;
	int mathe;
	TDG tempTDG; // day la tdg muon sach

	Normal();
	system("cls");
	ve_khung_basic_pink();
	//
		// nhap ma the
	Hight_text_pink();
	gotoxy(cot, dong);
	cout << "NHAP MA THE DOC GIA : ";
	//cin.ignore();
	Normal();
	cin >> mathe;
	// check ma the = true

	if (Tim_TDG_Muon_Sach(mathe, ds_tdg.The_Doc_Gia, tempTDG) == -1) // ko co mathe
	{
		int check = 0;
		//
		Hight_text_pink();
		gotoxy(cot + 17, dong + 16);
		cout << "  __ MA THE KHONG TON TAI __  ";
		//
		HightLight_pink();
		gotoxy(cot + 10, dong + 20);
		cout << "   tiep tuc   ";
		//
		gotoxy(cot + 40, dong + 20);
		Normal();
		cout << "    thoat     ";
		Check_Left_Right(check);
		if (check == 0)
		{
			MUON_SACH(ds_tdg,mds);
			return 0;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		// da co ma the doc gia -- in cac sach da muon
		Ve_Khung_Xuat_Danh_Sach_MT_Cua_Mot_DG();
		// dien thong tin the doc gia muon sach
			//
		int cot_1 = 10;
		int	dong_1 = 5 + 3;
		int	cot_mathe = cot_1;
		int cot_ho = cot_1 + 23;
		int cot_ten = cot_1 + 52;
		int cot_phai = cot_1 + 90;
		int cot_trangthai = cot_1 + 113;
		int soluong_node = ds_tdg.So_Luong;
		int check = 1;
		//
		int mang_toado_DG[7] =
		{
		 cot_1,
		 dong_1,
		 cot_mathe,
		 cot_ho,
		 cot_ten ,
		 cot_phai,
		 cot_trangthai
		};
		Ghi_Data_TDG(tempTDG, mang_toado_DG);

		//
				// ghi data danh sach muon tra
		int d_1 = 17;
		int c_1 = 9;
		int c_ma_tdg = c_1;
		int c_isbn = c_1 + 14;
		int c_ms = c_1 + 30;
		int c_tt = c_1 + 51;
		int c_muon = c_1 + 76;
		int c_tra = c_1 + 115;
		int mang_toa_do_dsmt[8] =
		{
		 d_1,
		 c_1,
		 c_ma_tdg,
		 c_isbn,
		 c_ms,
		 c_tt,
		 c_muon,
		 c_tra
		};
		MUON_TRA p = tempTDG->ds_Muon_Tra.pHead;

		while (p != NULL)
		{
			Ghi_Data_DSMT(tempTDG, p, mang_toa_do_dsmt);
			p = p->pNext;
			mang_toa_do_dsmt[1]++;

		}
		//
		//tien hanh muon sach
		int chon = 0;
		//
		//
		HightLight_pink();
		gotoxy(cot + 10, dong + 25);
		cout << "   MUON SACH   ";
		//
		gotoxy(cot + 40, dong + 25);
		Normal();
		cout << "    THOAT     ";
		Check_Left_Right_MUONSACH(chon);
		if (chon == 0) // tien hanh muon
		{
			//
			Normal();
			system("cls");
			ve_khung_basic_pink();
			//
			string Ma_ISBN;
			DAU_SACH tempDS;
			// nhap ma isbn

			Hight_text_pink();
			gotoxy(cot, dong);
			cout << "NHAP MA ISBN MUON : ";
			cin.ignore();
			Normal();
			getline(cin, Ma_ISBN);
			Chuan_Hoa_Chu(Ma_ISBN);

			// check isbn = null
			if (Ma_ISBN.length() != 4)
			{
				check = 0;
				//
				gotoxy(cot + 17, dong + 16);
				Hight_text_pink();
				cout << "  __ MA ISBN KHONG HOP LE __  ";
				//
				gotoxy(cot + 10, dong + 20);
				HightLight_pink();
				cout << "   tiep tuc   ";
				//
				gotoxy(cot + 40, dong + 20);
				Normal();
				cout << "    thoat     ";
				Check_Left_Right(check);
				if (check == 0) // tiep tuc
				{
					MUON_SACH(ds_tdg, mds);
				}
				else
				{
					return 0;
				}
			}											// check isbn trung isbn cu~
			else if (Tim_Dau_Sach_DG_Muon(Ma_ISBN, mds, tempDS) == 0)
			{
				check = 0;
				//
				gotoxy(cot + 17, dong + 16);
				Hight_text_pink();
				cout << "  __ MA ISBN KHONG TON TAI __  ";
				//
				gotoxy(cot + 10, dong + 20);
				HightLight_pink();
				cout << "   tiep tuc   ";
				//
				gotoxy(cot + 40, dong + 20);
				Normal();
				cout << "    thoat     ";
				Check_Left_Right(check);
				if (check == 0) // tiep tuc
				{
					MUON_SACH(ds_tdg, mds);					
				}
				else
				{
					return 0;
				}
			}
			else
			{
				// co isbn roi
				//kiem tra dieu kien muon
				//1: thang cong ;
				//-1:cac sach da dc muon het;
				//-2: da muon sach nay r
				//-3: co sach muon qua han
				//-4: da muon 3 cuon r
				MUON_TRA tempMT = new muon_tra;

				if ((Kiem_Tra_Dieu_Kien_Muon(tempTDG, tempDS,tempMT)) == 1)// complete
				{
					Them_Node_Muon_Tra_Cua_1_Doc_Gia(tempTDG, tempMT);
					Update_File_Them_MT(tempTDG, tempMT);
					Update_File_Xoa_DMS(mds); // update trang thai moi ma sach cua dau sach

					gotoxy(cot + 25, dong + 20);
					HightLight_pink();
					cout << "... complete ....";
					Bam_Nut_Exit();
					return 0;
				}
				else if ((Kiem_Tra_Dieu_Kien_Muon(tempTDG, tempDS, tempMT)) == -1)
				{
					gotoxy(cot + 17, dong + 16);
					Hight_text_pink();
					cout << "  __ CAC SACH DA MUON HET __  ";
					
					gotoxy(cot + 25, dong + 20);
					HightLight_pink();
					cout << "... EXIT ....";
					Bam_Nut_Exit();
					return 0;
				}
				else if ((Kiem_Tra_Dieu_Kien_Muon(tempTDG, tempDS, tempMT)) == -2)
				{
					gotoxy(cot + 17, dong + 16);
					Hight_text_pink();
					cout << "  __ DA MUON SACH NAY ROI __  ";

					gotoxy(cot + 25, dong + 20);
					HightLight_pink();
					cout << "... EXIT ....";
					Bam_Nut_Exit();
					return 0;
				}
				else if ((Kiem_Tra_Dieu_Kien_Muon(tempTDG, tempDS, tempMT)) == -3)
				{
					gotoxy(cot + 17, dong + 16);
					Hight_text_pink();
					cout << "  __ CO SACH DA MUON QUA HAN __  ";

					gotoxy(cot + 25, dong + 20);
					HightLight_pink();
					cout << "... EXIT ....";
					Bam_Nut_Exit();
					return 0;
				}
				else if ((Kiem_Tra_Dieu_Kien_Muon(tempTDG, tempDS, tempMT)) == -4)
				{
					gotoxy(cot + 17, dong + 16);
					Hight_text_pink();
					cout << "  __ DA MUON 3 CUON SACH ROI __  ";

					gotoxy(cot + 25, dong + 20);
					HightLight_pink();
					cout << "... EXIT ....";
					Bam_Nut_Exit();
					return 0;
				}
			}	
		}
	}
	return 0;
} // chua xu li giao dien

int TRA_SACH(DS_TDG& ds_tdg, MANG_DAU_SACH mds, TDG Mang[])
{
	// kt ma the hop le
	int cot = 40, dong = 8;
	int mathe;
	TDG tempTDG = new the_doc_gia; // day la tdg muon sach

	Normal();
	system("cls");
	ve_khung_basic_pink();
	//
		// nhap ma the
	Hight_text_pink();
	gotoxy(cot, dong);
	cout << "NHAP MA THE DOC GIA : ";
	//cin.ignore();
	Normal();
	cin >> mathe;
	// check ma the = true

	if (Tim_TDG_Muon_Sach(mathe, ds_tdg.The_Doc_Gia, tempTDG) == -1) // ko co mathe
	{
		int check = 0;
		//
		Hight_text_pink();
		gotoxy(cot + 17, dong + 16);
		cout << "  __ MA THE KHONG TON TAI __  ";
		//
		HightLight_pink();
		gotoxy(cot + 10, dong + 20);
		cout << "   tiep tuc   ";
		//
		gotoxy(cot + 40, dong + 20);
		Normal();
		cout << "    thoat     ";
		Check_Left_Right(check);
		if (check == 0)
		{
			TRA_SACH(ds_tdg,mds ,Mang);
			return 0;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		// node da co tdg muon sach
		// di tim DAU SACH ma doc gia kia muon
		string maISBN;
		DAU_SACH tempDS = new dau_sach; // day la dausach duoc muon
		//
				// nhap ma the
		Hight_text_pink();
		gotoxy(cot, dong+2);
		cout << "NHAP DAU SACH TRA : ";
		//cin.ignore();
		Normal();
		cin.ignore();
		getline(cin, maISBN);		// check ma isbn = true
		Chuan_Hoa_Chu(maISBN);
		if (Tim_Dau_Sach_DG_Muon(maISBN, mds, tempDS) == 0) // ko co dau sach
		{
			int check = 0;
			//
			Hight_text_pink();
			gotoxy(cot + 14, dong + 16);
			cout << "  __ MA ISBN KHONG TON TAI __  ";
			//
			HightLight_pink();
			gotoxy(cot + 10, dong + 20);
			cout << "   tiep tuc   ";
			//
			gotoxy(cot + 40, dong + 20);
			Normal();
			cout << "    thoat     ";
			Check_Left_Right(check);
			if (check == 0)
			{
				TRA_SACH(ds_tdg, mds, Mang);
				return 0;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			// da co TDG muon sach va DAU SACH duoc muon
			if (Check_Sach_Da_Muon(tempTDG, maISBN) == 0)
			{
				Hight_text_pink();
				gotoxy(cot + 12, dong + 16);
				cout << "  __ DOC GIA KHONG MUON SACH NAY __  ";
				gotoxy(cot + 25, dong + 20);
				HightLight_pink();
				cout << "   EXIT   ";
				Bam_Nut_Exit();
				return 0;
			}
			else
			{
				Xoa_DSLK_Kep(tempTDG, tempDS);
				tempTDG->Trang_Thai_The = 1;
				Update_File_Xoa_thedocgia(ds_tdg, Mang);
				Update_File_Xoa_DMS(mds);
				Update_File_Xoa_MT(ds_tdg, Mang);

				gotoxy(cot + 25, dong + 20);
				HightLight_pink();
				cout << "   complete   ";
				Bam_Nut_Exit();
			}
		}
		//
	}
	//

	return 0;
}
//------------------------------------------------------------


// ------------------- quan li dau sach ----------------------

int THEM_DAU_SACH(MANG_DAU_SACH& mds)
{
	int check;
	Normal();
	system("cls");
	ve_khung_basic_yellow();


	//
	if (mds.So_Luong >= 100)
	{

		int cot = 45, dong = 18;
		string rep = "SO LUONG DAY. KHONG THE THEM";
		gotoxy(cot, dong);
		Normal();
		SetColor(12);
		cout << rep;
		gotoxy(cot + 20, dong + 3);
		HightLight_pink();
		cout << "   EXIT   ";
		Bam_Nut_Exit();
		return 0;
	}
	else
	{
		// mang dau sach con them duoc
		int cot = 40, dong = 8;
		DAU_SACH temp = new dau_sach;


																		// nhap ISBN
		Hight_text_pink();
		gotoxy(cot, dong);
		cout << "NHAP MA ISBN : ";
		Normal();
		getline(cin, temp->ISBN);
		Chuan_Hoa_Chu(temp->ISBN);
		// check isbn = null
		if (temp->ISBN.length() != 4)
		{
			check = 0;
			//
			gotoxy(cot + 17, dong + 16);
			Hight_text_pink();
			cout << "  __ MA ISBN KHONG HOP LE __  ";
			//
			gotoxy(cot + 10, dong + 20);
			HightLight_pink();
			cout << "   tiep tuc   ";
			//
			gotoxy(cot + 40, dong + 20);
			Normal();
			cout << "    thoat     ";
			Check_Left_Right(check);
			if (check == 0) // tiep tuc
			{
				THEM_DAU_SACH(mds);
				return 0;
			}
			else
			{
				return 0;
			}
		}											// check isbn trung isbn cu~
		else if (check_lap_ISBN(temp->ISBN, mds) != -1)
		{
			check = 0;
			//
			gotoxy(cot + 17, dong + 16);
			Hight_text_pink();
			cout << "  __ MA ISBN DA TON TAI __  ";
			//
			gotoxy(cot + 10, dong + 20);
			HightLight_pink();
			cout << "   tiep tuc   ";
			//
			gotoxy(cot + 40, dong + 20);
			Normal();
			cout << "    thoat     ";
			Check_Left_Right(check);
			if (check == 0) // tiep tuc
			{
				THEM_DAU_SACH(mds);
				return 0;
			}
			else
			{
				return 0;
			}
		}
		else 										// ISBN da hop le
		{
													// nhap ten sach
			Hight_text_pink();
			gotoxy(cot, dong + 2);
			cout << "NHAP TEN DAU SACH : ";
			Normal();
			getline(cin, temp->Ten_Sach);
			Chuan_Hoa_Chu(temp->Ten_Sach);
			// check ten = null
			if (temp->Ten_Sach.length() == NULL)
			{
				int check = 0;
				//
				gotoxy(cot + 17, dong + 16);
				Hight_text_pink();
				cout << "  __ CHUA NHAP TEN DAU SACH __  ";
				//
				gotoxy(cot + 10, dong + 20);
				HightLight_pink();
				cout << "   tiep tuc   ";
				//
				gotoxy(cot + 40, dong + 20);
				Normal();
				cout << "    thoat     ";
				Check_Left_Right(check);
				if (check == 0)
				{
					THEM_DAU_SACH(mds);
				}
				else
				{
					return 0;
				}
			}
																		// ten sach hop le roi
			else														
			{
																		//nhap tac gia
				Hight_text_pink();
				gotoxy(cot, dong + 4);
				cout << "NHAP TAC GIA : ";
				Normal();
				getline(cin, temp->Tac_Gia);
				Chuan_Hoa_Chu(temp->Tac_Gia);
														// check THE LOAI = null
				if (temp->Tac_Gia.length() == NULL)
				{
					int check = 0;
					//
					gotoxy(cot + 17, dong + 16);
					Hight_text_pink();
					cout << "  __ CHUA NHAP TAC GIA __  ";
					//
					gotoxy(cot + 10, dong + 20);
					HightLight_pink();
					cout << "   tiep tuc   ";
					//
					gotoxy(cot + 40, dong + 20);
					Normal();
					cout << "    thoat     ";
					Check_Left_Right(check);
					if (check == 0)
					{
						THEM_DAU_SACH(mds);
					}
					else
					{
						return 0;
					}
				}
				else
				{
																//tac gia hop le roi
																// nhap so trang 						
					Hight_text_pink();
					gotoxy(cot, dong + 6);
					cout << "NHAP SO TRANG : ";
					Normal();
					cin >> temp->So_Trang;

																			// nhap nam xb
					Hight_text_pink();
					gotoxy(cot, dong + 8);
					cout << "NHAP NAM XUAT BAN : ";
					Normal();
					cin >> temp->Nam_Xuat_Ban;

					if ((temp->Nam_Xuat_Ban > 2020) || (temp->Nam_Xuat_Ban < 100))
					{
						check = 0;
						//
						gotoxy(cot + 17, dong + 16);
						Hight_text_pink();
						cout << "  __ NAM XUAT BAN KHONG HOP LE __  ";
						//
						gotoxy(cot + 10, dong + 20);
						HightLight_pink();
						cout << "   tiep tuc   ";
						//
						gotoxy(cot + 40, dong + 20);
						Normal();
						cout << "    thoat     ";
						Check_Left_Right(check);
						if (check == 0) // tiep tuc
						{
							THEM_DAU_SACH(mds);
							return 0;
						}
						else
						{
							return 0;
						}
					}
					else			// so trang va nam xb hop le, xoa bo dem de nhap string the loai
					{
																			// nhap the loai						
						Hight_text_pink();
						gotoxy(cot, dong + 10);
						//cin.ignore();
						cout << "NHAP THE LOAI : ";
						Normal();
						cin.ignore();
						getline(cin, temp->The_Loai);
						Chuan_Hoa_Chu(temp->The_Loai);
						// check THE LOAI = null
						if (temp->The_Loai.length() == NULL)
						{
							int check = 0;
							//
							gotoxy(cot + 17, dong + 16);
							Hight_text_pink();
							cout << "  __ CHUA NHAP THE LOAI __  ";
							//
							gotoxy(cot + 10, dong + 20);
							HightLight_pink();
							cout << "   tiep tuc   ";
							//
							gotoxy(cot + 40, dong + 20);
							Normal();
							cout << "    thoat     ";
							Check_Left_Right(check);
							if (check == 0)
							{
								THEM_DAU_SACH(mds);
							}
							else
							{
								return 0;
							}
						}
																		// the loai hop le roi
						else
						{
							Add_Node_Dau_Sach(mds, temp);
							Update_File_Them_Dau_Sach(temp);
							gotoxy(cot + 25, dong + 20);
							HightLight_pink();
							cout << "   complete   ";
							Bam_Nut_Exit();
						}
					}
				}
			}
		}
	}
	return 0;
}

int TIM_THONG_TIN_DAU_SACH(MANG_DAU_SACH mds)
{
	// tim dau sach can xuat thong tin
	int chon;
	Normal();
	system("cls");
	ve_khung_basic_yellow();
	// 
	int cot = 40, dong = 8;
	string ma_isbn;

	// nhap ISBN de xuat ra danh muc sach
	Hight_text_pink();
	gotoxy(cot, dong);
	cout << "NHAP MA ISBN : ";
	Normal();
	getline(cin, ma_isbn);
	Chuan_Hoa_Chu(ma_isbn);
	// check isbn = null
	if (ma_isbn.length() != 4)
	{
		chon = 0;
		//
		gotoxy(cot + 17, dong + 16);
		Hight_text_pink();
		cout << "  __ MA ISBN KHONG HOP LE __  ";
		//
		gotoxy(cot + 10, dong + 20);
		HightLight_pink();
		cout << "   tiep tuc   ";
		//
		gotoxy(cot + 40, dong + 20);
		Normal();
		cout << "    thoat     ";
		Check_Left_Right(chon);
		if (chon == 0) // tiep tuc
		{
			TIM_THONG_TIN_DAU_SACH(mds);
			return 0;
		}
		else
		{
			return 0;
		}
	}
		// check isbn co trong mds khong
	else if (check_lap_ISBN(ma_isbn, mds) == -1)
	{
		chon = 0;
		//
		gotoxy(cot + 17, dong + 16);
		Hight_text_pink();
		cout << "  __ MA ISBN KHONG TON TAI __  ";
		//
		gotoxy(cot + 10, dong + 20);
		HightLight_pink();
		cout << "   tiep tuc   ";
		//
		gotoxy(cot + 40, dong + 20);
		Normal();
		cout << "    thoat     ";
		Check_Left_Right(chon);
		if (chon == 0) // tiep tuc
		{
			TIM_THONG_TIN_DAU_SACH(mds);
			return 0;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		// ma ISBN da hop le
			// set up khung
		Ve_Khung_Xuat_Danh_Muc_Sach_Cua_Dau_Sach();

		// .............. in thong tin dau sach ...................
			// mang toa do cua DAU SACH
		int cot_1 = 9;
		int	dong_1 = 5 + 3;
		int	cot_isbn = cot_1;
		int cot_tensach = cot_1 + 9 + 5;
		int cot_sotrang = cot_1 + 50;
		int cot_tacgia = cot_1 + 64;
		int cot_theloai = cot_1 + 96;
		int cot_nxb = cot_1 + 121;

		//
		int mang_toado_DS[8] =
		{
		 cot_1,
		 dong_1,
		 cot_isbn,
		 cot_tensach,
		 cot_sotrang ,
		 cot_tacgia,
		 cot_theloai,
		 cot_nxb
		};
		Ghi_Data_DAUSACH(mds.Dau_Sach[check_lap_ISBN(ma_isbn, mds)], mang_toado_DS);

		// ghi data cac danh muc sach
		DAU_SACH temDS = mds.Dau_Sach[check_lap_ISBN(ma_isbn, mds)];
		int soluong_node_DMS = temDS->Danh_Muc_Sach.So_Luong;
		int check = 1;
		int k = 0;
		int tam = 0;

		int cot_dms = 9;
		int dong_dms = 17;
		int cot_isbn_dms = cot_dms;
		int cot_masach_dms = cot_dms + 17;
		int cot_trangthai_dms = cot_dms+40;
		int cot_vitri_dms = cot_dms+92;


		int mang_toado_dms[7] =
		{
		 cot_dms,
		 dong_dms,
		 cot_isbn_dms,
		 cot_masach_dms,
		 cot_trangthai_dms ,
		 cot_vitri_dms,
		 soluong_node_DMS
		};
			// chuyen danh sach dms vao mang
		//DMS mang = new d_m_s[soluong_node_DMS];
		DMS Mang_DMS[50]; //-> max = 50 moi dau sach
		DMS p = temDS->Danh_Muc_Sach.pHead;
		int stt = 0;
		while (p != NULL)
		{
			Mang_DMS[stt] = new d_m_s;
			Mang_DMS[stt] = p;
			p = p->pNext;
			stt++;
		}
		// co mang dms roi
			// in mang danh muc sach
		while (k < soluong_node_DMS) // k la so phan tu trong 1 trang
		{
			// moi trang 7 phan tu
			Ghi_Data_Danh_Muc_Sach_Cua_1_Dau_Sach(Mang_DMS[k] ,mang_toado_dms);
			k = k + 1;

			// trang dau tien co sl > 7
			if ((k == 7) && (k != soluong_node_DMS))
			{
				//cout << "// trang dau tien co sl > 7";
				// 
				Normal();
				gotoxy(10, 5 + 28);
				cout << "   EXIT   ";
				gotoxy(10 + 113, 5 + 28);
				cout << "   NEXT   ";
				//
				Check_Left_Right_TEXT_DONG(check, "   EXIT   ", "   NEXT   "); //0: exit - 2 next
				// exit
				if (check == 0)// exit
				{
					return 0;
				}
				// next
				if (check == 2)// next
				{
					tam = 7;
					Ve_Khung_Xuat_Danh_Muc_Sach_Cua_Dau_Sach(); // xoa data 
					mang_toado_DS[1] = 8;
					// ghi data dau sach
					Ghi_Data_DAUSACH(mds.Dau_Sach[check_lap_ISBN(ma_isbn, mds)], mang_toado_DS);
					mang_toado_dms[1] = 17; // reset noi ghi data ve ban dau
				}
			}

			//// cac trang o giua

			if ((k > 7) && (k % 7 == 0) && (k != soluong_node_DMS))
			{
				//cout << "cac trang o giua";
				check = 1;
				Check_Left_Mid_Right(check);
				// exit
				if (check == 1)
				{
					return 0;
				}
				// next
				if (check == 2)
				{
					tam = tam + 7;
					Ve_Khung_Xuat_Danh_Muc_Sach_Cua_Dau_Sach(); // xoa data 
					mang_toado_dms[1] = 17;
				}
				if (check == 0) // pre
				{
					tam = tam - 7;
					Ve_Khung_Xuat_Danh_Muc_Sach_Cua_Dau_Sach(); // xoa data 
					mang_toado_DS[1] = 8;
					Ghi_Data_DAUSACH(mds.Dau_Sach[check_lap_ISBN(ma_isbn, mds)], mang_toado_DS);
					mang_toado_dms[1] = 17;
					k = k - 14;
				}
			}

			//// trang cuoi cung - > co trang giua
			if ((k == soluong_node_DMS) && (k > 14))
			{
				// 
				//cout << "trang cuoi co trang giua";
				Normal();
				gotoxy(10, 5 + 28);
				cout << "   PRE   ";
				gotoxy(10 + 113, 5 + 28);
				cout << "   EXIT   ";
				//
				Check_Left_Right_TEXT_DONG(check, "   PRE   ", "   EXIT   ");
				// exit
				if (check == 2)
				{
					return 0;
				}
				//pre
				if (check == 0)
				{
					Ve_Khung_Xuat_Danh_Muc_Sach_Cua_Dau_Sach();
					mang_toado_DS[1] = 8;
					Ghi_Data_DAUSACH(mds.Dau_Sach[check_lap_ISBN(ma_isbn, mds)], mang_toado_DS);

					mang_toado_dms[1] = 17;
					if (k % 7 == 0) // trang cuoi = 7
					{
						k = k - 14;
					}
					else
					{
						k = k - tam + 7;
					}

				}
			}
			// trang cuoi cung nhung cung la trang dau tien
			if ((k == soluong_node_DMS) && (k <= 7))
			{
				//cout << "trang cuoi la trang 1";
				gotoxy(cot_1 + 57, dong_1 + 25);
				HightLight_pink();
				cout << "   EXIT   ";
				Bam_Nut_Exit();
				return 0;
			}
			// trang cuoi nhung khong co trang giua
			if ((k == soluong_node_DMS) && (k <= 14))
			{
				//cout<<"			// trang cuoi nhung khong co trang giua";
				// 
				Normal();
				gotoxy(10, 5 + 28);
				cout << "   PRE   ";
				gotoxy(10 + 113, 5 + 28);
				cout << "   EXIT   ";
				//
				Check_Left_Right_TEXT_DONG(check, "   PRE   ", "   EXIT   ");
				// exit
				if (check == 2)
				{
					return 0;
				}
				//pre
				if (check == 0)
				{
					Ve_Khung_Xuat_Danh_Muc_Sach_Cua_Dau_Sach();
					mang_toado_DS[1] = 8;
					Ghi_Data_DAUSACH(mds.Dau_Sach[check_lap_ISBN(ma_isbn, mds)], mang_toado_DS);
					mang_toado_dms[1] = 17;
					k = 0;
				}
			}
		}
		//Bam_Nut_Exit();	
	}
	return 0;
}

int IN_DAU_SACH_THEO_THE_LOAI_(MANG_DAU_SACH mds)
{
	Ve_Khung_Xuat_Dau_Sach();

	// XU LI XAP XEP TANG DAN THEO THE LOAI
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
			for (int k = 0; k < mang_theloai[j] - 1; k++)
			{
				for (int l = k + 1; l < mang_theloai[j]; l++)
				{
					Xap_Xep_Mang(mds.Dau_Sach[k], mds.Dau_Sach[l]); // xap xep tang dan
				}
			}
		}
		else // cac phan tu sau so luon bang [j]- [j - 1];
		{// sau khi qua phan tu dau tien trong mang theloai
			for (int m = mang_theloai[j - 1]; m < mang_theloai[j] - 1; m++)
			{
				for (int n = m + 1; n < mang_theloai[j]; n++)
				{
					Xap_Xep_Mang(mds.Dau_Sach[m], mds.Dau_Sach[n]); // xap xep tang dan
				}
			}
		}
	}
	// XUAT MANG 
		//
	int cot_1 = 9;
	int	dong_1 = 5 + 3;
	int	cot_isbn = cot_1;
	int cot_tensach = cot_1 + 9 + 5;
	int cot_sotrang = cot_1 + 50;
	int cot_tacgia = cot_1 + 64;
	int cot_theloai = cot_1 + 96;
	int cot_nxb = cot_1 + 121;
	int soluong_node = mds.So_Luong;
	int check = 1;
	//
	int mang_toado[9] =
	{
	 cot_1,
	 dong_1,
	 cot_isbn,
	 cot_tensach,
	 cot_sotrang ,
	 cot_tacgia,
	 cot_theloai,
	 cot_nxb,
	 soluong_node
	};
	int k = 0;
	int tam = 0;

	// in mang
	while (k < (mds.So_Luong)) // k la so phan tu trong 1 trang
	{

		Ghi_Data_DAUSACH(mds.Dau_Sach[k], mang_toado);
		k = k + 1;

		// trang dau tien co sl > 12
		if ((k == 12) && (k != mds.So_Luong))
		{
			// 
			Normal();
			gotoxy(10, 5 + 28);
			cout << "   EXIT   ";
			gotoxy(10 + 113, 5 + 28);
			cout << "   NEXT   ";
			//
			Check_Left_Right_TEXT_DONG(check, "   EXIT   ", "   NEXT   "); //0: exit - 2 next
			// exit
			if (check == 0)// exit
			{
				return 0;
			}
			// next
			if (check == 2)// next
			{
				tam = 12;
				Ve_Khung_Xuat_Dau_Sach(); // xoa data 
				mang_toado[1] = 8;
			}
		}

		//// cac trang o giua

		if ((k > 12) && (k % 12 == 0) && (k != mds.So_Luong))
		{
			check = 1;
			Check_Left_Mid_Right(check);
			// exit
			if (check == 1)
			{
				return 0;
			}
			// next
			if (check == 2)
			{
				tam = tam + 12;
				Ve_Khung_Xuat_Dau_Sach(); // xoa data 
				mang_toado[1] = 8;
			}
			if (check == 0) // pre
			{
				tam = tam - 12;
				Ve_Khung_Xuat_Dau_Sach(); // xoa data 
				mang_toado[1] = 8;
				k = k - 24;
			}
		}

		//// trang cuoi cung - cos trang gia
		if ((k == mds.So_Luong) && (k>24) )
		{
			// 
			Normal();
			gotoxy(10, 5 + 28);
			cout << "   PRE   ";
			gotoxy(10 + 113, 5 + 28);
			cout << "   EXIT   ";
			//
			Check_Left_Right_TEXT_DONG(check, "   PRE   ", "   EXIT   ");
			// exit
			if (check == 2)
			{
				return 0;
			}
			//pre
			if (check == 0)
			{
				Ve_Khung_Xuat_Dau_Sach();
				mang_toado[1] = 8;
				if (k % 12 == 0)
				{
					k = k - 24;
				}
				else
				{
					k = k - tam + 12;
				}

			}
		}
		// trang cuoi cung nhung cung la trang dau tien
		if ((k == mds.So_Luong) && (k <= 12))
		{


			gotoxy(cot_1 + 57, dong_1 + 25);
			HightLight_pink();
			cout << "   EXIT   ";
			Bam_Nut_Exit();
			return 0;
		}
		// trang cuoi cung koco trang giua
				// trang cuoi cung ko co trang giua
		if ((k == mds.So_Luong) && (k <= 24))
		{
			// 
			Normal();
			gotoxy(10, 5 + 28);
			cout << "   PRE   ";
			gotoxy(10 + 113, 5 + 28);
			cout << "   EXIT   ";
			//
			Check_Left_Right_TEXT_DONG(check, "   PRE   ", "   EXIT   ");
			if (check == 2) // exit
			{
				return 0;
			}
			//pre
			if (check == 0)
			{
				Ve_Khung_Xuat_Dau_Sach();
				mang_toado[1] = 8;
				k = 0;
			}
		}
	}

	return 0;
}

int XOA_DAU_SACH(MANG_DAU_SACH& mds)
{
	int check;
	Normal();
	system("cls");
	ve_khung_basic_yellow();
	//
	int chon;
	Normal();
	system("cls");
	ve_khung_basic_yellow();
	// 
	int cot = 40, dong = 8;
	string ma_isbn;

	// nhap ISBN de xuat ra danh muc sach
	Hight_text_pink();
	gotoxy(cot, dong);
	cout << "NHAP MA ISBN : ";
	Normal();
	getline(cin, ma_isbn);
	Chuan_Hoa_Chu(ma_isbn);
	// check isbn = null
	if (ma_isbn.length() != 4)
	{
		chon = 0;
		//
		gotoxy(cot + 17, dong + 16);
		Hight_text_pink();
		cout << "  __ MA ISBN KHONG HOP LE __  ";
		//
		gotoxy(cot + 10, dong + 20);
		HightLight_pink();
		cout << "   tiep tuc   ";
		//
		gotoxy(cot + 40, dong + 20);
		Normal();
		cout << "    thoat     ";
		Check_Left_Right(chon);
		if (chon == 0) // tiep tuc
		{
			XOA_DAU_SACH(mds);
			return 0;
		}
		else
		{
			return 0;
		}
	}
	// check isbn co trong mds khong
	else if (check_lap_ISBN(ma_isbn, mds) == -1)
	{
		chon = 0;
		//
		gotoxy(cot + 17, dong + 16);
		Hight_text_pink();
		cout << "  __ MA ISBN KHONG TON TAI __  ";
		//
		gotoxy(cot + 10, dong + 20);
		HightLight_pink();
		cout << "   tiep tuc   ";
		//
		gotoxy(cot + 40, dong + 20);
		Normal();
		cout << "    thoat     ";
		Check_Left_Right(chon);
		if (chon == 0) // tiep tuc
		{
			XOA_DAU_SACH(mds);
		}
		else
		{
			return 0;
		}
	}
	// ma isbn hop le
	else
	{
		if (mds.Dau_Sach[check_lap_ISBN(ma_isbn, mds)]->Danh_Muc_Sach.So_Luong == 0)
		{
			// tien hanh xoa sach
			for (int i = check_lap_ISBN(ma_isbn, mds); i < mds.So_Luong - 1; i++)
			{
				mds.Dau_Sach[i] = mds.Dau_Sach[i + 1]; // xoa 1 phan tu mang
			}
			mds.Dau_Sach[mds.So_Luong] = NULL;
			mds.So_Luong--;
			Update_File_Xoa_Dau_Sach(mds);
			gotoxy(cot + 25, dong + 20);
			HightLight_pink();
			cout << "   complete   ";
			Bam_Nut_Exit();
		}
		else
		{
			gotoxy(cot + 10, dong + 16);
			Hight_text_pink();
			cout << "  __ DAU SACH CO MA SACH KHONG DUOC XOA __  ";
			gotoxy(cot + 25, dong + 20);
			HightLight_pink();
			cout << "   EXIT   ";
			Bam_Nut_Exit();
		}
	}
}

// ko can tham chieu vi truya cap den tro **
int SUA_THONG_TIN_DAU_SACH(MANG_DAU_SACH mds)
{
	int check;
	Normal();
	system("cls");
	ve_khung_basic_yellow();
	//
	int cot = 40, dong = 8;

	DAU_SACH temp = new dau_sach;
	// nhap ISBN
	Hight_text_pink();
	gotoxy(cot, dong);
	//cin.ignore();
	cout << "NHAP MA ISBN : ";
	Normal();
	getline(cin, temp->ISBN);
	Chuan_Hoa_Chu(temp->ISBN);
	// check isbn = null
	if (temp->ISBN.length() != 4)
	{
		check = 0;
		//
		gotoxy(cot + 17, dong + 16);
		Hight_text_pink();
		cout << "  __ MA ISBN KHONG HOP LE __  ";
		//
		gotoxy(cot + 10, dong + 20);
		HightLight_pink();
		cout << "   tiep tuc   ";
		//
		gotoxy(cot + 40, dong + 20);
		Normal();
		cout << "    thoat     ";
		Check_Left_Right(check);
		if (check == 0) // tiep tuc
		{
			SUA_THONG_TIN_DAU_SACH(mds);
			return 0;
		}
		else
		{
			return 0;
		}
	}											// check isbn trung isbn cu~
	else if (check_lap_ISBN(temp->ISBN, mds) == -1)
	{
		check = 0;
		//
		gotoxy(cot + 17, dong + 16);
		Hight_text_pink();
		cout << "  __ MA ISBN KHONG TON TAI __  ";
		//
		gotoxy(cot + 10, dong + 20);
		HightLight_pink();
		cout << "   tiep tuc   ";
		//
		gotoxy(cot + 40, dong + 20);
		Normal();
		cout << "    thoat     ";
		Check_Left_Right(check);
		if (check == 0) // tiep tuc
		{
			SUA_THONG_TIN_DAU_SACH(mds);
			return 0;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		// isbn hop le

		int cot = 40, dong = 8;

		// nhap ten sach moi
		Hight_text_pink();
		gotoxy(cot, dong + 2);
		cout << "NHAP TEN DAU SACH MOI : ";
		Normal();
		getline(cin, temp->Ten_Sach);
		Chuan_Hoa_Chu(temp->Ten_Sach);
		// check ten = null
		if (temp->Ten_Sach.length() == NULL)
		{
			int check = 0;
			//
			gotoxy(cot + 17, dong + 16);
			Hight_text_pink();
			cout << "  __ CHUA NHAP TEN DAU SACH __  ";
			//
			gotoxy(cot + 10, dong + 20);
			HightLight_pink();
			cout << "   tiep tuc   ";
			//
			gotoxy(cot + 40, dong + 20);
			Normal();
			cout << "    thoat     ";
			Check_Left_Right(check);
			if (check == 0)
			{
				SUA_THONG_TIN_DAU_SACH(mds);
			}
			else
			{
				return 0;
			}
		}
		// ten sach hop le roi
		else
		{
			//nhap tac gia
			Hight_text_pink();
			gotoxy(cot, dong + 4);
			cout << "NHAP TAC GIA : ";
			Normal();
			getline(cin, temp->Tac_Gia);
			Chuan_Hoa_Chu(temp->Tac_Gia);
			// check THE LOAI = null
			if (temp->Tac_Gia.length() == NULL)
			{
				int check = 0;
				//
				gotoxy(cot + 17, dong + 16);
				Hight_text_pink();
				cout << "  __ CHUA NHAP TAC GIA __  ";
				//
				gotoxy(cot + 10, dong + 20);
				HightLight_pink();
				cout << "   tiep tuc   ";
				//
				gotoxy(cot + 40, dong + 20);
				Normal();
				cout << "    thoat     ";
				Check_Left_Right(check);
				if (check == 0)
				{
					SUA_THONG_TIN_DAU_SACH(mds);
				}
				else
				{
					return 0;
				}
			}
			else
			{
				//tac gia hop le roi
				// nhap so trang 						
				Hight_text_pink();
				gotoxy(cot, dong + 6);
				cout << "NHAP SO TRANG : ";
				Normal();
				cin >> temp->So_Trang;

				// nhap nam xb
				Hight_text_pink();
				gotoxy(cot, dong + 8);
				cout << "NHAP NAM XUAT BAN : ";
				Normal();
				cin >> temp->Nam_Xuat_Ban;

				if ((temp->Nam_Xuat_Ban > 2020) || (temp->Nam_Xuat_Ban < 100))
				{
					check = 0;
					//
					gotoxy(cot + 12, dong + 16);
					Hight_text_pink();
					cout << "  __ NAM XUAT BAN KHONG HOP LE (100 < > 2020) __  ";
					//
					gotoxy(cot + 10, dong + 20);
					HightLight_pink();
					cout << "   tiep tuc   ";
					//
					gotoxy(cot + 40, dong + 20);
					Normal();
					cout << "    thoat     ";
					Check_Left_Right(check);
					if (check == 0) // tiep tuc
					{
						SUA_THONG_TIN_DAU_SACH(mds);
						return 0;
					}
					else
					{
						return 0;
					}
				}
				else			// so trang va nam xb hop le, xoa bo dem de nhap string the loai
				{
					// nhap the loai						
					Hight_text_pink();
					gotoxy(cot, dong + 10);
					//cin.ignore();
					cout << "NHAP THE LOAI : ";
					Normal();
					cin.ignore();
					getline(cin, temp->The_Loai);
					Chuan_Hoa_Chu(temp->The_Loai);
					// check THE LOAI = null
					if (temp->The_Loai.length() == NULL)
					{
						int check = 0;
						//
						gotoxy(cot + 17, dong + 16);
						Hight_text_pink();
						cout << "  __ CHUA NHAP THE LOAI __  ";
						//
						gotoxy(cot + 10, dong + 20);
						HightLight_pink();
						cout << "   tiep tuc   ";
						//
						gotoxy(cot + 40, dong + 20);
						Normal();
						cout << "    thoat     ";
						Check_Left_Right(check);
						if (check == 0)
						{
							SUA_THONG_TIN_DAU_SACH(mds);
						}
						else
						{
							return 0;
						}
					}
					else
					{
						mds.Dau_Sach[check_lap_ISBN(temp->ISBN, mds)]->Ten_Sach = temp->Ten_Sach;
						mds.Dau_Sach[check_lap_ISBN(temp->ISBN, mds)]->Tac_Gia = temp->Tac_Gia;
						mds.Dau_Sach[check_lap_ISBN(temp->ISBN, mds)]->The_Loai = temp->The_Loai;
						mds.Dau_Sach[check_lap_ISBN(temp->ISBN, mds)]->So_Trang = temp->So_Trang;
						mds.Dau_Sach[check_lap_ISBN(temp->ISBN, mds)]->Nam_Xuat_Ban = temp->Nam_Xuat_Ban;
						Update_File_Xoa_Dau_Sach(mds);
						gotoxy(cot + 25, dong + 20);
						HightLight_pink();
						cout << "   complete   ";
						Bam_Nut_Exit();
					}

				}
			}
		}
	}
}

int THEM_DANH_MUC_SACH(MANG_DAU_SACH& mds)
{
	string tim_DS; // isbn
	int check;
	Normal();
	system("cls");
	ve_khung_basic_yellow();
	//check isbn


	// nhap ISBN
	int cot = 40, dong = 8;

	Hight_text_pink();
	gotoxy(cot, dong);
	cout << "NHAP MA ISBN : ";
	Normal();
	getline(cin, tim_DS);
	Chuan_Hoa_Chu(tim_DS);
	// check isbn = null
	if (tim_DS.length() != 4)
	{
		check = 0;
		//
		gotoxy(cot + 17, dong + 16);
		Hight_text_pink();
		cout << "  __ MA ISBN KHONG HOP LE __  ";
		//
		gotoxy(cot + 10, dong + 20);
		HightLight_pink();
		cout << "   tiep tuc   ";
		//
		gotoxy(cot + 40, dong + 20);
		Normal();
		cout << "    thoat     ";
		Check_Left_Right(check);
		if (check == 0) // tiep tuc
		{
			THEM_DANH_MUC_SACH(mds);
			return 0;
		}
		else
		{
			return 0;
		}
	}											// check isbn trung isbn cu~
	else if (check_lap_ISBN(tim_DS, mds) == -1)
	{
		check = 0;
		//
		gotoxy(cot + 17, dong + 16);
		Hight_text_pink();
		cout << "  __ MA ISBN KHONG TON TAI __  ";
		//
		gotoxy(cot + 10, dong + 20);
		HightLight_pink();
		cout << "   tiep tuc   ";
		//
		gotoxy(cot + 40, dong + 20);
		Normal();
		cout << "    thoat     ";
		Check_Left_Right(check);
		if (check == 0) // tiep tuc
		{
			THEM_DANH_MUC_SACH(mds);
			return 0;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		// isbn da hop le
		DMS temp = new d_m_s;
		temp->Ma_Sach = Tao_ma_Sach(mds, tim_DS);
		temp->ISBN = tim_DS;
		//getline(cin, temp->Vi_Tri);
		//Chuan_Hoa_Chu(temp->Vi_Tri);
			
		// check vi tri
		Hight_text_pink();
		gotoxy(cot, dong+2);
		cout << "NHAP VI TRI : ";
		Normal();
		getline(cin, temp->Vi_Tri);
		Chuan_Hoa_Chu(temp->Vi_Tri);
		// check isbn = null
		if (temp->Vi_Tri.length() == NULL)
		{
			check = 0;
			//
			gotoxy(cot + 17, dong + 16);
			Hight_text_pink();
			cout << "  __ CHUA NHAP VI TRI __  ";
			//
			gotoxy(cot + 10, dong + 20);
			HightLight_pink();
			cout << "   tiep tuc   ";
			//
			gotoxy(cot + 40, dong + 20);
			Normal();
			cout << "    thoat     ";
			Check_Left_Right(check);
			if (check == 0) // tiep tuc
			{
				THEM_DANH_MUC_SACH(mds);
				return 0;
			}
			else
			{
				return 0;
			}
		}		
		else
		{
			Add_Node_DSLKD(mds.Dau_Sach[check_lap_ISBN(tim_DS, mds)]->Danh_Muc_Sach, temp);
			Update_File_Them_DMS(temp);
			gotoxy(cot + 25, dong + 20);
			HightLight_pink();
			cout << "... complete ....";
			Bam_Nut_Exit();
		}

	}

}

int XOA_MA_SACH(MANG_DAU_SACH& mds)
{
	string tim_DS;
	int check;
	Normal();
	system("cls");
	ve_khung_basic_yellow();
	//check isbn
	//
		// nhap ISBN
	int cot = 40, dong = 8;

	Hight_text_pink();
	gotoxy(cot, dong);
	cout << "NHAP MA ISBN : ";
	Normal();
	getline(cin, tim_DS);
	Chuan_Hoa_Chu(tim_DS);
	// check isbn = null
	if (tim_DS.length() != 4)
	{
		check = 0;
		//
		gotoxy(cot + 17, dong + 16);
		Hight_text_pink();
		cout << "  __ MA ISBN KHONG HOP LE __  ";
		//
		gotoxy(cot + 10, dong + 20);
		HightLight_pink();
		cout << "   tiep tuc   ";
		//
		gotoxy(cot + 40, dong + 20);
		Normal();
		cout << "    thoat     ";
		Check_Left_Right(check);
		if (check == 0) // tiep tuc
		{
			THEM_DANH_MUC_SACH(mds);
			return 0;
		}
		else
		{
			return 0;
		}
	}											// check isbn trung isbn cu~
	else if (check_lap_ISBN(tim_DS, mds) == -1)
	{
		check = 0;
		//
		gotoxy(cot + 17, dong + 16);
		Hight_text_pink();
		cout << "  __ MA ISBN KHONG TON TAI __  ";
		//
		gotoxy(cot + 10, dong + 20);
		HightLight_pink();
		cout << "   tiep tuc   ";
		//
		gotoxy(cot + 40, dong + 20);
		Normal();
		cout << "    thoat     ";
		Check_Left_Right(check);
		if (check == 0) // tiep tuc
		{
			THEM_DANH_MUC_SACH(mds);
			return 0;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		int masach;
		// nhap ma sach can xoa
				// check vi tri
		Hight_text_pink();
		gotoxy(cot, dong + 2);
		cout << "NHAP MA SACH CAN XOA : ";
		Normal();
		cin>> masach;
		// check ma sach hop le khong
		if (check_lap_Ma_Sach_Va_Trang_Thai(masach, mds.Dau_Sach[check_lap_ISBN(tim_DS, mds)]) == 1)
		{
			// da muon
			gotoxy(cot + 17, dong + 16);
			Hight_text_pink();
			cout << "  __ MA SACH DA MUON __  ";
			//
			gotoxy(cot + 25, dong + 20);
			HightLight_pink();
			cout << "... EXIT ....";
			Bam_Nut_Exit();
		}
		else if (check_lap_Ma_Sach_Va_Trang_Thai(masach, mds.Dau_Sach[check_lap_ISBN(tim_DS, mds)]) == 2)
		{
			//  ko co
			gotoxy(cot + 17, dong + 16);
			Hight_text_pink();
			cout << "  __ KHONG CO MA SACH __  ";
			//
			gotoxy(cot + 25, dong + 20);
			HightLight_pink();
			cout << "... EXIT ....";
			Bam_Nut_Exit();
		}
		else
		{
			// co ma sach xoa 
			if (masach == mds.Dau_Sach[check_lap_ISBN(tim_DS, mds)]->Danh_Muc_Sach.pHead->Ma_Sach)
			{
				// xoa node dau
				DMS p = mds.Dau_Sach[check_lap_ISBN(tim_DS, mds)]->Danh_Muc_Sach.pHead;
				mds.Dau_Sach[check_lap_ISBN(tim_DS, mds)]->Danh_Muc_Sach.pHead = mds.Dau_Sach[check_lap_ISBN(tim_DS, mds)]->Danh_Muc_Sach.pHead->pNext;
				delete p;
				mds.Dau_Sach[check_lap_ISBN(tim_DS, mds)]->Danh_Muc_Sach.So_Luong--;

				Update_File_Xoa_DMS(mds);
				
				gotoxy(cot + 25, dong + 20);
				HightLight_pink();
				cout << "... complete ....";
				Bam_Nut_Exit();
			}
			else
			{
				// masach la node bat ki:
				DMS temp = new d_m_s;
				DMS p = mds.Dau_Sach[check_lap_ISBN(tim_DS, mds)]->Danh_Muc_Sach.pHead;
				while (p != NULL)
				{
					if (p->Ma_Sach == masach)
					{
						temp->pNext = p->pNext;
						delete p;
						mds.Dau_Sach[check_lap_ISBN(tim_DS, mds)]->Danh_Muc_Sach.So_Luong--;

						Update_File_Xoa_DMS(mds);

						gotoxy(cot + 25, dong + 20);
						HightLight_pink();
						cout << "... complete ....";
						Bam_Nut_Exit();
						break;
					}
					temp = p;
					p = p->pNext;
				}
			}
		}
	}

	return 0;
}
//------------------------------------------------------------


//-------------------- ham phu ----------------------------------------
///  ---------------- tdg -------------------
int Sua_Node_Cay_Nhi_Phan(TDG& node, int mathe)
{
	int cot = 40, dong = 8;
	// --- xu li sua
	if (node->Ma_The == mathe)
	{
		string Ho, Ten, Phai;
		// tim toi diem can sua
		// NHAP HO
		Hight_text_pink();
		cin.ignore();
		gotoxy(cot, dong + 2);
		cout << "NHAP HO CAN DOI: ";
		Normal();
		getline(cin, Ho);
		Chuan_Hoa_Chu(Ho);
		//
		// check ho = null
		if (Ho.length() == NULL)
		{
			int check = 0;
			//
			gotoxy(cot + 17, dong + 16);
			Hight_text_pink();
			cout << "  __ CHUA NHAP HO DOC GIA __  ";
			//
			gotoxy(cot + 10, dong + 20);
			HightLight_pink();
			cout << "   tiep tuc   ";
			//
			gotoxy(cot + 40, dong + 20);
			Normal();
			cout << "    thoat     ";
			Check_Left_Right(check);
			if (check == 0)
			{
				Sua_Node_Cay_Nhi_Phan(node, mathe);
			}
			else
			{
				return 0;
			}
		}
		//
		// NHAP TEN
		Hight_text_pink();
		gotoxy(cot, dong+4);
		cout << "NHAP TEN CAN DOI: ";
		Normal();
		getline(cin, Ten);
		Chuan_Hoa_Chu(Ten);
		//
		// check TEN = null
		if (Ten.length() == NULL)
		{
			int check = 0;
			//
			gotoxy(cot + 17, dong + 16);
			Hight_text_pink();
			cout << "  __ CHUA NHAP HO DOC GIA __  ";
			//
			gotoxy(cot + 10, dong + 20);
			HightLight_pink();
			cout << "   tiep tuc   ";
			//
			gotoxy(cot + 40, dong + 20);
			Normal();
			cout << "    thoat     ";
			Check_Left_Right(check);
			if (check == 0)
			{
				Sua_Node_Cay_Nhi_Phan(node, mathe);
			}
			else
			{
				return 0;
			}
		}

		//
// NHAP PHAI
		// nhap phai
		Hight_text_pink();
		gotoxy(cot, dong + 6);
		cout << "Nhap Phai doc gia: ";
		//cin.ignore();
		Normal();
		getline(cin, Phai);
		Chuan_Hoa_Chu(Phai);
		// check phai
		if (Phai == "NAM" || Phai == "NU")
		{
			node->Ten = Ten;
			node->Ho = Ho;
			node->Phai = Phai;
			//
			gotoxy(cot + 25, dong + 20);
			HightLight_pink();
			cout << "   complete   ";
			Bam_Nut_Exit();
			return 1;
		}
		else
		{
			int check = 0;
			//
			gotoxy(cot + 17, dong + 16);
			Hight_text_pink();
			cout << "  __ PHAI DOC GIA KHONG HOP LE __  ";
			//
			gotoxy(cot + 10, dong + 20);
			HightLight_pink();
			cout << "   tiep tuc   ";
			//
			gotoxy(cot + 40, dong + 20);
			Normal();
			cout << "    thoat     ";
			Check_Left_Right(check);
			if (check == 0)
			{
				Sua_Node_Cay_Nhi_Phan(node, mathe);
				return 0;
			}
			else
			{
				return 0;
			}

		}
		//
	}
	else if (node->Ma_The > mathe)
	{
	Sua_Node_Cay_Nhi_Phan(node->pLeft, mathe);
	}
	else if (node->Ma_The < mathe)
	{
	Sua_Node_Cay_Nhi_Phan(node->pRight, mathe);
	}
}

void Ghi_Data_TDG(TDG node, int mang[])
{
	Normal();
	SetColor(14);
	// ma the
	gotoxy(mang[2], mang[1]);
	cout << node->Ma_The;
	//
	gotoxy(mang[3], mang[1]);
	cout << node->Ho;
	//
	gotoxy(mang[4], mang[1]);
	cout << node->Ten;
	//
	gotoxy(mang[5], mang[1]);
	cout << node->Phai;
	//		
	if (node->Trang_Thai_The == 0)
	{
		gotoxy(mang[6], mang[1]);
		cout << "BI KHOA";
	}
	else
	{
		gotoxy(mang[6], mang[1]);
		cout << "HOAT DONG";
	}
	mang[1] += 2;
	//return 0;
}

void Ghi_Data_DAUSACH(DAU_SACH node,int  mang_toa_do[])
{
	// ghi THONG TIN DAU SACH
	Normal();
	SetColor(14);
	// ma isbn
	gotoxy(mang_toa_do[2], mang_toa_do[1]);
	cout << node->ISBN;
	//
	gotoxy(mang_toa_do[3], mang_toa_do[1]);
	cout << node->Ten_Sach;
	//
	gotoxy(mang_toa_do[4], mang_toa_do[1]);
	cout << node->So_Trang;
	//
	gotoxy(mang_toa_do[5], mang_toa_do[1]);
	cout << node->Tac_Gia;
	//
	gotoxy(mang_toa_do[6], mang_toa_do[1]);
	cout << node->The_Loai;
	//
	gotoxy(mang_toa_do[7], mang_toa_do[1]);
	cout << node->Nam_Xuat_Ban;
	//

	mang_toa_do[1] += 2;
}

void Ghi_Data_DSMT(TDG node_tdg, MUON_TRA node, int mang_toa_do[])
{
	Normal();
	SetColor(14);
	// ma isbn
	gotoxy(mang_toa_do[2], mang_toa_do[0]);
	cout << node_tdg->Ma_The;
	//
	gotoxy(mang_toa_do[3], mang_toa_do[0]);
	cout << node->ISBN;
	//
	gotoxy(mang_toa_do[4], mang_toa_do[0]);
	cout << node->Ma_Sach;
	//
	gotoxy(mang_toa_do[5], mang_toa_do[0]);
	if (node->Trang_Thai == 0)
	{
		cout << "CHUA MUON";
	}
	else if (node->Trang_Thai == 1)
	{
		cout << "DA MUON";
	}

	//
	gotoxy(mang_toa_do[6], mang_toa_do[0]);
	tm DMY_MUON = Doi_So_Giay_Thanh_DMY(node->Ngay_Muon);

	cout << DMY_MUON.tm_hour << ":" << DMY_MUON.tm_min << ":" << DMY_MUON.tm_sec
		<< " - " << DMY_MUON.tm_mday << "/" << 1 + DMY_MUON.tm_mon << "/" << 1900 + DMY_MUON.tm_year << endl;	//
		//
	gotoxy(mang_toa_do[7], mang_toa_do[0]);
	//cout << node->Ngay_Tra;
	cout << "CHUA TRA";


	mang_toa_do[0] += 2;
}
//
void Ghi_Data_TDG_Muon_Qua_Han(TDG node, time_t so_ngay, MUON_TRA MT,MANG_DAU_SACH mds, int mang[])
{
	Normal();
	SetColor(14);
	// ma the
	gotoxy(mang[2], mang[1]);
	cout << node->Ma_The;
	//
	gotoxy(mang[3], mang[1]);
	cout << node->Ho;
	//
	gotoxy(mang[4], mang[1]);
	cout << node->Ten;
	//
	gotoxy(mang[5], mang[1]);
	cout << MT->Ma_Sach;
	//ma sach
	gotoxy(mang[6], mang[1]);
	cout << mds.Dau_Sach[check_lap_ISBN(MT->ISBN, mds)]->Ten_Sach; // ten sach
	// ngay muon
	tm DMY_MUON = Doi_So_Giay_Thanh_DMY(MT->Ngay_Muon);
	gotoxy(mang[7], mang[1]);
	cout <<  DMY_MUON.tm_hour << ":" << DMY_MUON.tm_min << ":" << DMY_MUON.tm_sec
		<< " - " << DMY_MUON.tm_mday << "/" << 1 + DMY_MUON.tm_mon << "/" << 1900 + DMY_MUON.tm_year << endl;
	// SO NGAY QUA HAN
	gotoxy(mang[8], mang[1]);
	cout << so_ngay ;
	
	mang[1] += 2;
	//return 0;
}
//// ----------------- dau sach ---------------

void Ghi_Data_Danh_Muc_Sach_Cua_1_Dau_Sach(DMS node, int mang_toa_do[])
{
	Normal();
	SetColor(14);
	// ma isbn
	gotoxy(mang_toa_do[2], mang_toa_do[1]);
	cout << node->ISBN;
	//
	gotoxy(mang_toa_do[3], mang_toa_do[1]);
	cout << node->Ma_Sach;

	//
	gotoxy(mang_toa_do[4], mang_toa_do[1]);
	if (node->Trang_Thai == 0)
	{
		cout << "CHUA MUON";
	}
	else if (node->Trang_Thai == 1)
	{
		cout << "DA MUON";
	}

	//
	gotoxy(mang_toa_do[5], mang_toa_do[1]);
	cout << node->Vi_Tri;
	//



	mang_toa_do[1] += 2;
}
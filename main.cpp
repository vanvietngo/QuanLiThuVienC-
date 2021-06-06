#include"the_doc_gia.h"
#include"ve_hinh.h"
#include"do_hoa.h"


int main()
{

	// ---------------------------  tao random  ------------------------------
	/*-----*/ srand(time(NULL));
	// ---------------------------  Tao bien    ------------------------------
	/*-----*/ MANG_DAU_SACH mds;                                     /*-----*/
	/*-----*/ DS_TDG ds_tdg;                                         /*-----*/
	/*-----*/ TDG Mang[100];                                         /*-----*/
	// ---------------------------  load file   ------------------------------
	/*-----*/ Load_File_thedocgia(ds_tdg);                           /*-----*/
	/*-----*/ Doc_File_Dau_Sach(mds);                                /*-----*/
	/*-----*/ Load_File_DMS(mds);                                    /*-----*/
	/*-----*/ Load_File_Danh_Sach_Muon_Tra(ds_tdg);                  /*-----*/
	/*-----*/ int sttxx = 0;                                         /*-----*/
	/*-----*/ Chuyen_Node_Vao_Mang(ds_tdg.The_Doc_Gia, Mang, sttxx); /*-----*/
	/*-----*/ Update_File_Xoa_thedocgia(ds_tdg, Mang);               /*-----*/

	// -----------------------       LUA CHON XU LI       --------------------
	///*
	INTRODUCE();
	int lua_chon;
	while (1)
	{
		lua_chon = MENU_main();
		switch (lua_chon)
		{
			case 0:// QUAN LY DOC GIA
			{
				int chon_menu_tdg = MENU_tdg();
				switch (chon_menu_tdg)
				{
					case 0: // them the doc gia
					{
						THEM_THE_DOC_GIA(ds_tdg, Mang);
						break;
					}
					case 1: // xoa the doc gia
					{
						XOA_THE_DOC_GIA(ds_tdg, Mang);
						break;
					}
					case 2:// hieu chinh the doc gia
					{
						HIEU_CHINH_THE_DOC_GIA(ds_tdg, Mang);
						break;
					}
					case 3://IN THE DOC GIA THEO MA TANG DAN
					{
						IN_TDG_THEO_MATHE_TANG_DAN(ds_tdg);
						break;
					}
					case 4://IN THE DOC GIA THEO TEN TANG DAN
					{
						IN_TDG_THEO_TEN_TANG_DAN(ds_tdg);
						break;
					}
					case 5://IN CAC SACH DA MUON CUA DOC GIA 
					{
						IN_CAC_SACH_DA_MUON_CUA_MOT_DOC_GIA(ds_tdg);
						break;
					}
					case 6://IN THE DOC GIA MUON SACH QUA HAN
					{
						IN_THE_DOC_GIA_MUON_SACH_QUA_HAN_GIAM_DAN(ds_tdg, mds);
						break;
					}
					case 7://MUON SACH
					{
						MUON_SACH(ds_tdg,mds);
						break;
					}
					case 8://TRA SACH   
					{
						TRA_SACH(ds_tdg, mds, Mang);
						break;
					}
					case 9://EXIT   
					{

						break;
					}

				}
				break;
			}
			case 1: // .............  QUAN LY DAU SACH  ..................
			{
				int chon_menu_dausach = MENU_ds();
				switch (chon_menu_dausach)
				{
					case 0:
					{
						THEM_DAU_SACH(mds);
						break;
					}
					case 1:
					{
						TIM_THONG_TIN_DAU_SACH(mds);
						break;
					}
					case 2:
					{
						IN_DAU_SACH_THEO_THE_LOAI_(mds);
						break;
					}
					case 3:
					{
						XOA_DAU_SACH(mds);
						break;
					}
					case 4:
					{
						SUA_THONG_TIN_DAU_SACH(mds);
						break;
					}
					//   ----  danh muc sach   ------
					case 5:
					{
						THEM_DANH_MUC_SACH(mds);
						break;
					}
					case 6:
					{
						TIM_THONG_TIN_DAU_SACH(mds); //=> tim sach
						break;						
					}
					case 7:
					{
						XOA_MA_SACH(mds);
						break;
					}
					case 8:
					{
						// EXIT
						break;
					}
				}
				break;
			}
			case 2: // ve lai trang gioi thieu
			{
				Normal();
				INTRODUCE();
				break;
			}
		}
	}
	//*/




/*
	
	 //                           XU LI KHONG CO GIAO DIEN

		//---------------------------------- Tao menu -------------------------------------
		int choice;
		bool kt_choice = true;
		system("cls");

		while (kt_choice) {


			cout << endl << endl << endl;

			cout << "*** ** **** **** **** ****** **** *** ****" << endl;
			cout << "* Nhap lua chon xu li:                   *" << endl;
			//--------------------------------------
			cout << "* 0: exit                                *" << endl;

			cout << "* 1: nhap thong tin the doc gia          *" << endl;
			cout << "* 2: xoa thong tin the doc gia           *" << endl;
			cout << "* 3: xuat thong tin the doc gia          *" << endl;
			cout << "* 4: In mang TDG tang dan theo ten + ho  *" << endl;
			//-----------------------------------
			cout << "* 5: nhap thong tin dau sach             *" << endl;
			cout << "* 6: xuat thong tin mang dau sach        *" << endl;

			cout << "* 7:Them_Danh_Muc_Sach_Cho_Dau_Sach      *" << endl;
			cout << "* 8: Xuat_DMS                            *" << endl;
			cout << "* 9: Muon sach                           *" << endl;
			cout << "* 10: Xoa 1 danh muc sach                *" << endl;
			cout << "* 11: Muon sach                          *" << endl;
			cout << "* 12: Cac sach da muon                   *" << endl;
			cout << "* 13: Xuat_Mang_Dau_Sach_Theo_The_Loai   *" << endl;
			
			cout << "* Nhap lua chon:                      ";
			cin >> choice;
			cout << endl;
			cout << "****** ******* ******** ******* *** ******" << endl;
			cout << endl << endl << endl;

			switch (choice)
			{
			case 1:
			{
				Nhap_TDG(ds_tdg);
				break;
			}
			case 2:
			{
				int stt = 0;
				Xoa_TDG(ds_tdg);
				Chuyen_Node_Vao_Mang(ds_tdg.The_Doc_Gia, Mang, stt);
				Update_File_Xoa_thedocgia(ds_tdg, Mang);
				break;
			}
			case 3:
			{
				cout << "---- xuat thong tin the doc gia tang dan theo Ma the -------" << endl;
				Xuat_TDG_Tang_Dan_Theo_Mathe(ds_tdg.The_Doc_Gia);
				break;
			}
			case 0:
			{
				kt_choice = false;
				break;
			}
			case 4:// in danh sach tdg tang dan theo ten - ho
			{
			int stt2 = 0;
				Chuyen_Node_Vao_Mang(ds_tdg.The_Doc_Gia, Mang, stt2);
				In_Mang_TDG(Mang, ds_tdg);
				break;
			}
			case 5:
			{
				Nhap_Info_Dau_Sach(mds);
				break;
			}
			case 6:
			{
				Xuat_Mang_Dau_Sach(mds);
				break;
			}
			case 7:
			{
				Them_Danh_Muc_Sach_Cho_Dau_Sach(mds);
				break;
			}
			case 8:
			{
				Xuat_DMS(mds);
				break;
			}
			case 9: // Sua thong tin the doc gia - bug
			{
				Sua_Thong_Tin_TDG(ds_tdg, Mang);
				break;
			}
			case 10:
			{
				Xoa_Danh_Muc_Sach(mds);
				break;
			}

			case 11:
			{
				Them_DS_Muon_Tra(ds_tdg, mds);
				break;
			}
			case 12:
			{
				Xuat_DS_MT(ds_tdg.The_Doc_Gia);
				break;
			}
			case 13:
			{
				Xuat_Mang_Dau_Sach_Theo_The_Loai(mds);
				break;
			}
			case 14:
			{
				Tim_Sach(mds);
				break;
			}
			case 15:
			{
				Tra_Sach(ds_tdg, mds, Mang);
				break;
			}
			case 16:
			{
				In_Mang_TDG_Tang_Dan_Theo_Ten(Mang, ds_tdg);
				break;
			}
			case 17:
			{
				Xuat_DSMT_1_Doc_Gia_cau_h(ds_tdg);
				break;
			}
			case 18:
			{
				int stt1 = 0;
				In_TDG_Muon_Qua_Han_Giam_Dan(ds_tdg, stt1);
				break;
			}
			case 19:
			{
				Xoa_Dau_Sach(mds);
				break;
			}
			case 20:
				Sua_Thong_Tin_Dau_Sach(mds);
				break;
			}
		}
		
		*/

		return 0;	
}

#include"the_doc_gia.h"
#include"dohoa.h"
#include"dau_sach.h"

int main() {
	srand(time(NULL));


	// -----------------------------  Tao bien --------------------------------
	// ----- BIEN THE DOC GIA -------
	DS_TDG ds_tdg;
	int stt = 0;
	int n_ = 0;

	TDG Mang[100];

	// ---- BIEN DAU SACH ----
	MANG_DAU_SACH mds;


	// load file
	Doc_File(ds_tdg);
	Doc_File_Dau_Sach(mds);
	// --- dms ---
	DS_DMS ds_dms;
	//------------------------------- test funtion ---------------------------
	//SetBGColor(1);

	//resize();




	//
	////veTuong();
	//HightLight();
	//cout << "hello" << endl;
	//Normal();
	//cout << "hi" << endl;

	//menu();
	////HightLight();
	//xoacontro();
	////SetBGColor(1);
	//while (1) {

	//}
	//---------------------------------- Tao menu -------------------------------------
	int choice;
	bool kt_choice = true;
	//system("cls");

	while (kt_choice) {


		cout << endl << endl << endl;

		cout << "*** ** **** **** **** ****** **** *** ****" << endl;
		cout << "* Nhap lua chon xu li:                   *" << endl;
		//--------------------------------------
		cout << "* 0: exit" << endl;

		cout << "* 1: nhap thong tin the doc gia          *" << endl;
		cout << "* 2: xoa thong tin the doc gia           *" << endl;
		cout << "* 3: xuat thong tin the doc gia          *" << endl;
		cout << "* 4: In mang TDG tang dan theo ten + ho  *" << endl;
		//-----------------------------------
		cout << "* 5: nhap thong tin dau sach             *" << endl;
		cout << "* 6: xuat thong tin mang dau sach        *" << endl;
		cout << "* 7:Them_Danh_Muc_Sach_Cho_Dau_Sach      *" << endl;
		cout << "* 8: Xuat_DMS                            *" << endl;
		cout << "* Nhap lua chon:                      ";
		cin >> choice;
		//cout<< '\n'<<flush<<" *";
	/*	cin.ignore();
		cin.clear();*/
		
		//cout << " *";
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
			//int mathe;
			//cout << "nhap ma TDG can xoa: ";
			//cin >> mathe;
			Xoa_TDG(ds_tdg);
			break;
		}
		case 3:
		{
			n_ = 0;
			cout << "---- xuat thong tin the doc gia tang dan theo Ma the -------" << endl;
			Xuat_TDG(ds_tdg.The_Doc_Gia, n_, ds_tdg);
			break;
		}
		case 0:
		{
			kt_choice = false;
			break;
		}
		case 4:
		{
			stt = 0;
			cout << "In mang TDG tang dan theo ten + ho" << endl;
			Chuyen_Node_Vao_Mang(ds_tdg.The_Doc_Gia, Mang, stt);
			In_Mang_TDG(Mang, ds_tdg);
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
		// testt dms 
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
		}
	}
	// ---------------------------------------------------------------------
	return 0;
}

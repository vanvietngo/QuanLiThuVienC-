#pragma once

#include"dau_sach.h"
#include<iostream>
#include"string"
using namespace std;
void Chuan_Hoa_Chuoi(string& kitu)
{
	// xoa ki tu dau va cuoi
	while (kitu[0] == ' ') {
		kitu.erase(0, 1);
	}
	while (kitu[kitu.length() - 1] == ' ') {
		kitu.erase(kitu.length() - 1, 1);
	}

}

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

				//cout << "da doc data file " << endl;

				getline(file_in_MDS, ds->ISBN, ',');
				Chuan_Hoa_Chuoi(ds->ISBN);
				getline(file_in_MDS, ds->Ten_Sach, ',');
				Chuan_Hoa_Chuoi(ds->Ten_Sach);
				file_in_MDS >> ds->So_Trang;
				file_in_MDS.ignore(256, ',');
				getline(file_in_MDS, ds->Tac_Gia, ',');
				Chuan_Hoa_Chuoi(ds->Tac_Gia);
				file_in_MDS >> ds->Nam_Xuat_Ban;
				file_in_MDS.ignore(256, ',');
				getline(file_in_MDS, ds->The_Loai);
				Chuan_Hoa_Chuoi(ds->The_Loai);
				//file_in_MDS.ignore();
				//cout << "doc xong data file" << endl;
				//Sleep(1000);
				Add_Node_Dau_Sach(mds, ds);
			}
		}
		file_in_MDS.close();
	}
}
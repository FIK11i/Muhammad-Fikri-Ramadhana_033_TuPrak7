//Tugas Membuat Progam Penghasil Nota Pembelian Barang Pada Supermarket !
#include <conio.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#define maks 5
using namespace std;
struct jenis_barang
{
	int harga_barang,jumlah_barang;
	double harjum_barang,total_barang;
	char nama_barang[35];
};

main ()
{
	jenis_barang belanja[maks];
	int i,j=0;
	char lagi,nmr[20];
	do
	{
		cout<<"Pembelian barang ke="<<j+1<<endl;
		cout<<"======================"<<endl;
		cout<<"Nama barang	: ";
		cin.get(belanja[j].nama_barang,30);
		cout<<"Harga Satuan	: ";
		cin>>belanja[j].harga_barang;
		cout<<"Jumlah yang dibeli	: ";
		cin>>belanja[j].jumlah_barang;
		cout<<"\nAda barang lain lagi yang dibeli--maks 5--(Y/N)? ";
		cin>>lagi;
		cin.ignore();
		cout<<endl<<endl;
		j++;
		i=j;		
	}
	while((lagi=='y'||lagi=='Y')&&j<5);
	
	cout<<"Nama File Nota	: ";
	cin>>nmr;
	ofstream struk(nmr,ios::out);
	struk<<"						NOTA BELANJA					"<<endl;
	struk<<"					TOKO BUKU GRALEKTROMEDIA			"<<endl;
	struk<<"======================================================================"<<endl;
	struk<<"| no | nama barang |  harga satuan	|  jumlah  | total harga |"<<endl;
	struk<<"======================================================================"<<endl;
	for(j=0; j<i; j++)
	{
		belanja[j].harjum_barang=belanja[j].harga_barang*belanja[j].jumlah_barang;
		struk<<"|"<<setw(3)<<j+1<<setw(2);
		struk<<"|"<<setw(13)<<belanja[j].nama_barang<<setw(3);
		struk<<"|"<<setw(13)<<belanja[j].harga_barang<<setw(2);
		struk<<"|"<<setw(7)<<belanja[j].jumlah_barang<<setw(2);
		struk<<"|"<<setw(14)<<belanja[j].harjum_barang<<setw(3)<<"|"<<endl;
		belanja[maks].total_barang=belanja[0].harjum_barang+belanja[1].harjum_barang+belanja[2].harjum_barang+belanja[3].harjum_barang+belanja[4].harjum_barang+belanja[5].harjum_barang;
	}
	struk<<"=============================================================="<<endl;
	struk<<"total belanja (Rp"<<setw(28)<<"|"<<setw(14);
	struk<<belanja[maks].total_barang<<setw(3)<<"|"<<endl;
	struk<<"=============================================================="<<endl;
	getch();
}


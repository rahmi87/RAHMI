#include<stdio.h>
#include<string.h>
#include<ctype.h>

int Kembalian(char ,int , int ,int, int );//prototype
int main(){
	int pilihan,i,pesan,jumlah,total=0,uang,sisa=0,sisa1,kembalian;
	char jawab,jawab1,jawaban;
	char *urutan[6]={"Pizza","Mie Bakso","Nasi Goreng","Martabak Telur","Aneka Jus"};
	int harga[6]={15000,13000,10000,8000,5000};
void tabel(){//fungsi untuk menampilkan daftar produk
	printf("\n------------------------------------------\n");
	printf("+\t|\t\t\t\t\t    +\n");
	printf("|  No   |   Makanan \t\t Harga\t    |\n");
	printf("+\t|\t\t\t\t\t    +\n");
    printf("---------------------------------------------\n");
	
}

int Kembalian(char jawab,int tot,int money,int back,int back1){//fungsi untuk menghitung uang kembalian
	if(tolower(jawab)=='n'){
		printf("Total Pembayaran \t:Rp.%d\n",tot);
		printf("Bayar \t:Rp.");
		scanf("%d",&money);
		
		if(money<tot){//Syarat jika uang yang diberikan kurang dari total pesanan
			
			do{	
				back=tot-money;
				printf("Jumlah uang kurang \t:Rp.%d\n",back);	
				printf("Masukkan uang tambahan  :Rp.");
				scanf("%d",&back1);
				if(back1<back){
					tot=back;
					money=back1;	
				}
			}
			while(back1<back);
			
			int kembalian=back1-back;
			back=kembalian;	
		}
		else if(tot<money){//syarat jika total pesanan kurang dari uang di masukkan
			back=money-tot;
		}
		
		printf("Kembali \t\t:Rp.%d",back);			
		getchar();
		getchar();
	}	
}


typedef struct y{//perintah untuk memberikan nama alias dari tipe data
	char *urutan1;
	int cost;
	}pesanan;

	pesanan struk[5];
	for(i=0;i<5;i++){
	
		struk[i].urutan1=urutan[i];
		struk[i].cost=harga[i];
	}
	
	printf("\nSelamat Datang di Warung Sederhana\n");

	printf("1.Daftar Makanan\n2.Pesanan Saya\n3.Keluar\n");//menampilkan pilihan
	
	printf("\nPilih Kategori: ");
	scanf("%d",&pilihan);
	
	while(pilihan>3 || pilihan<1){//ketika inputan pilihan>3 atau <1
		printf("\nMaaf, input Anda tidak sesuai!\n");
		printf("Pilih Kategori: ");
		scanf("%d",&pilihan);
	}
	
	switch(pilihan){//percabangan switch
		case 1://jika inputan memilih angka 1, maka akan menampilkan daftar makanan
			tabel();

			for(i=0;i<5;i++){
				printf("|  %i.   |   %s \t\t %d\t   |\n",i+1,struk[i].urutan1,struk[i].cost);//menampilkan daftar produk
			}
			
			printf("--------------------------------------------\n");
			getchar();
			
			printf("Tekan Enter untuk melanjutkan...\n ");
			getchar();
			do{
			printf("\nKunjungi Warung?(y/n)\n=> ");
			scanf("%c",&jawab);
	
			jawaban=tolower(jawab);
		
			if(jawaban == 'n'){//syarat jika inputan memberi input 'n'
				printf("\nTerima kasih atas kunjungan Anda.");
				break;
			}else if(jawab>=0&&jawab<=9){
				printf("\ninput anda salah\n");
				getchar();
				continue;
			}else if((tolower(jawaban)>='a'&& tolower(jawaban)<='z')&&jawaban!='y'){
				printf("\ninput anda salah\n");
				getchar();
				}
			}
			while(jawaban!='n'&& jawaban!='y');
			if(jawaban == 'n'){
				break;
			}
		case 2://jika menginput 2 , maka dijalankan program pembelian
			do{
				do{
				printf("\nInput nomor pesanan: ");
				getchar();
				scanf("%d",&pesan);
			
				if(pesan>=7||pesan<=0){
					printf("inputan anda salah\n");
				}else if(pesan>='A'&&pesan <='z'){
					printf("inputan anda salah\n");
				}
				
				}while((pesan<=0||pesan>=7)||(pesan>='A'&&pesan <='z'));//melakukan looping jika pesan <0 atau >7
				
				printf("\nJumlah makanan: ");
				scanf("%d",&jumlah);
				
				total= total+struk[pesan-1].cost*jumlah;
				
				printf("\nTotal pesanan %d\n",total);
				getchar();
			
				printf("\nLihat Lainnya?(y/n)\n=>");
				scanf("%c",&jawab1);
				
			
				while(tolower(jawab1)!='n'&&tolower(jawab1)!='y'){
				
					printf("\ninput anda salah\n");
					printf("\nLihat Lainnya?(y/n)\n=>");
					getchar();
					scanf("%c",&jawab1);
				}
			}while(tolower(jawab1)=='y');
			
			Kembalian(jawab1,total,uang,sisa,sisa1);
				
		case 3://program berakhir saat user menginput 3
			printf("\nTerima Kasih Atas Kujungan Anda.\n");
		}
	return 0;
	}
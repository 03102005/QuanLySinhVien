#include<stdio.h>
#include<time.h>
#include<string.h>


struct date
{
	int ngay, thang, nam;
};

struct sinhVien
{
	char id[15];
	char ten[50];
	char gioiTinh[4];
	date ngaySinh;
	int tuoi;
	char maLop[15];
	float diemMon1, diemMon2, diemMon3;
	float diemTB;
	char hocLuc[15];
};
typedef sinhVien SV;

void xoaXuongDong(char x[])
{
	size_t doDai = strlen(x);
	if(x[doDai-1] == '\n')
		x[doDai-1] = '\0';
}

void nhapSV(SV *sv)
{
	printf("MSSV: "); fgets(sv->id, sizeof(sv->id), stdin); xoaXuongDong(sv->id);
	printf("Ho va ten: "); fgets(sv->ten, sizeof(sv->ten), stdin); xoaXuongDong(sv->ten);
	printf("Gioi tinh: "); fgets(sv->gioiTinh, sizeof(sv->gioiTinh), stdin); xoaXuongDong(sv->gioiTinh);
	printf("Ngay sinh: "); scanf("%d %d %d", &sv->ngaySinh.ngay, &sv->ngaySinh.thang, &sv->ngaySinh.nam); getchar();
	printf("Ma lop: "); fgets(sv->maLop, sizeof(sv->maLop), stdin); xoaXuongDong(sv->maLop);
	printf("Diem mon 1 = "); scanf("%f", &sv->diemMon1); getchar(); fflush(stdin);
	printf("Diem mon 2 = "); scanf("%f", &sv->diemMon2); getchar(); fflush(stdin);
	printf("Diem mon 3 = "); scanf("%f", &sv->diemMon3); getchar(); fflush(stdin);

}


void dsSV(SV ds[], int size)
{
	for(int i = 1; i <= size; i++)
	{
		printf("Nhap sinh vien thu %d\n", i);
		nhapSV(&ds[i]);
	}
}

void xuatSV(SV sv[], int size)
{
	for(int i = 1; i <= size; i++)
		printf("%5s \t %5s \t %5s \t %5d/%d/%d \t %5s \t %5.2f \t %5.2f \t %5.2f \t \n", sv[i].id, sv[i].ten, sv[i].gioiTinh, sv[i].ngaySinh.ngay, sv[i].ngaySinh.thang, sv[i].ngaySinh.nam, sv[i].maLop, sv[i].diemMon1, sv[i].diemMon2, sv[i].diemMon3);
		
}

int main()
{
	SV sv[100];
	int size;
	printf("Nhap so luong sinh vien: "); scanf("%d", &size); getchar();
	dsSV(sv, size);
	printf("%5s \t %5s \t %5s \t %5s \t %5s \t %5s \t %5s \t %5s", "MSSV", "Ho va ten", "Gioi Tinh", "Ngay sinh", "Ma Lop", "Diem 1", "Diem 2", "Diem 3");
	printf("\n");
	xuatSV(sv, size);
}
	
	
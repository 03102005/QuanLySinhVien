#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

struct SinhVien {
	char MSSV[11];
	char HoTen[50];
	char DiaChi[50];
	int Tuoi;
	float DiemSo;
};
typedef SinhVien SV;

void XoaXuongDong(char x[]) {
	size_t size = strlen(x);
	if(x[size - 1] == '\n')
		x[size - 1] = '\0';
}

void NhapThongTinMotSinhVien (SV *sv) {
	printf("Nhap MSSV: "); 
	fgets(sv->MSSV, sizeof(sv->MSSV), stdin); XoaXuongDong(sv->MSSV);
	printf("Nhap ho ten sinh vien: ");
	fgets(sv->HoTen, sizeof(sv->HoTen), stdin); XoaXuongDong(sv->HoTen);
	printf("Nhap dia chi: ");
	fgets(sv->DiaChi, sizeof(sv->DiaChi), stdin); XoaXuongDong(sv->DiaChi);
	printf("Nhap tuoi: "); scanf("%d", &sv->Tuoi); getchar();
	printf("Nhap diem so: "); scanf("%f", &sv->DiemSo); getchar();
}

void NhapDanhSachSinhVien(SV *sv, int *SoLuongSinhVien) {
	for (int i = 0; i < *SoLuongSinhVien; i++) {
		printf("-----------------------------------------\n");
		printf("Nhap thong tin sinh vien thu %d\n", i+1);
		NhapThongTinMotSinhVien(sv+i);
	}
}

void XuatThongTinMotSinhVien (SV *sv) {
	printf("MSSV: %s", sv->MSSV); 
	printf("\tHo va ten: %s", sv->HoTen); 
	printf("\tDia chi: %s", sv->DiaChi); 
	printf("\tTuoi: %d", sv->Tuoi);
	printf("\tDiem so: %.2f", sv->DiemSo); 
}

void XuatDanhSachSinhVien(SV *sv, int *SoLuongSinhVien) {
	for (int i = 0; i < *SoLuongSinhVien; i++) {
		printf("-----------------------------------------\n");
		printf("Thong tin sinh vien thu %d\n", i+1);
		XuatThongTinMotSinhVien(sv+i);
		printf("\n");
	}
}

void SapXepDanhSachSinhVienTheoSoTuoiTangDan(SV *sv, int *SoLuongSinhVien) {
	for (int i = 0; i < *SoLuongSinhVien - 1; i++) {
		for (int j = i+1; j < *SoLuongSinhVien; j++) {
			if ((sv+i)->Tuoi > (sv+j)->Tuoi) {
				SV temp = *(sv+i);
				*(sv+i) = *(sv+j);
				*(sv+j) = temp;
			}
		}
	}
}

void TimSinhVienCoDiemThapNhat(SV *sv, int SoLuongSinhVien) {
	int min = (sv+0)->DiemSo;
	int temp = 0;
	for (int i = 1; i < SoLuongSinhVien; i++) {
		if (min > (sv+i)->DiemSo) {
			min = (sv+i)->DiemSo;
			temp = i;
		}
	}
	printf("Sinh vien co diem thap nhat la: %s", (sv+temp)->HoTen);
}

void ThemSinhVien(SV *sv, int *SoLuongSinhVien) {
	int ViTriThemSV;
	printf("Nhap vi tri can them sinh vien: "); 
	scanf("%d", &ViTriThemSV); getchar();
	sv = (SV *) realloc(sv, ++*SoLuongSinhVien);
	for(int i = 0; i < *SoLuongSinhVien; i++) {
		if(i >= ViTriThemSV-1) {
			*(sv+i+1) = *(sv+i);
		}
	}
	NhapThongTinMotSinhVien(sv+ViTriThemSV-1);
	printf("Them sinh vien thanh cong !");
}

void XoaSinhvienTheoMSSV(SV *sv, int *SoLuongSinhVien) {
	char ID[11];
	int temp = -1;
	printf("Nhap MSSV cua sinh vien can xoa: ");
	fgets(ID, sizeof(ID), stdin); XoaXuongDong(ID);
	for(int i = 0; i < *SoLuongSinhVien; i++) {
		if(strcmp(ID, (sv+i)->MSSV) == 0) 
			temp = i;
	}
	for(int i = temp; i < *SoLuongSinhVien-1; i++)
		*(sv + i) = *(sv + i + 1);
	sv = (SV *) realloc(sv, --*SoLuongSinhVien);
	printf("Xoa sinh vien thanh cong !");
}

void ThayDoiThongTinSinhVien(SV *sv, int *SoLuongSinhVien) {
	char ID[11];
	int temp = -1;
	printf("Nhap MSSV cua sinh vien can thay doi thong tin: ");
	fgets(ID, sizeof(ID), stdin); XoaXuongDong(ID);
	for(int i = 0; i < *SoLuongSinhVien; i++) {
		if(strcmp(ID, (sv+i)->MSSV) == 0)
			temp = i;
	}
	NhapThongTinMotSinhVien(sv+temp);
	printf("Thay doi thong tin sinh vien thanh cong !");
}

int main() {
	int SoLuongSinhVien;
	printf("Nhap so luong sinh vien: "); scanf("%d", &SoLuongSinhVien); getchar();
	SV sv;
	SV *ptr = &sv;
	ptr = (SV *) malloc(SoLuongSinhVien * sizeof(SV));
	NhapDanhSachSinhVien(ptr, &SoLuongSinhVien);
	while(true) {
		printf("\n===================== M E N U =======================");
		printf("\n|  1. Xuat danh sach sinh vien                      |");
		printf("\n|  2. Sap xep sinh vien theo so tuoi tang dan       |");
		printf("\n|  3. Tim sinh vien co diem thap nhat               |");
		printf("\n|  4. Them sinh vien                                |");
		printf("\n|  5. Xoa sinh vien                                 |");
		printf("\n|  6. Thay doi thong tin sinh vien                  |");
		printf("\n|  7. Xoa man hinh                                  |");
		printf("\n|  8. Thoat chuong trinh                            |");
		printf("\n=====================================================");
		int Choose;
		printf("\nVui long nhap lua chon: ");
		scanf("%d", &Choose); getchar();

		switch(Choose) {
			case 1: 
				XuatDanhSachSinhVien(ptr, &SoLuongSinhVien);
				break;
			case 2: 
				printf("\n=========================================\n");
				printf("Sap xep sinh vien theo so tuoi tang dan\n");
				SapXepDanhSachSinhVienTheoSoTuoiTangDan(ptr, &SoLuongSinhVien);
				XuatDanhSachSinhVien(ptr, &SoLuongSinhVien);
				break;
			case 3: 
				printf("\n");
				TimSinhVienCoDiemThapNhat(ptr, SoLuongSinhVien);
				break;
			case 4:
				printf("\n");
				ThemSinhVien(ptr, &SoLuongSinhVien);
				break;
			case 5:
				XoaSinhvienTheoMSSV(ptr, &SoLuongSinhVien);
				break;
			case 6:
				ThayDoiThongTinSinhVien(ptr, &SoLuongSinhVien);
				break;
			case 7:
				system("cls");
				break;
			case 8: 
				return 0;
		}
	}
	free(ptr);
}

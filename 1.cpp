
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

struct SinhVien {
	char MSSV[15];
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

int main() {
	int SoLuongSinhVien;
	printf("Nhap so luong sinh vien: "); scanf("%d", &SoLuongSinhVien); getchar();
	SV sv;
	SV *ptr = &sv;
	ptr = (SV *) malloc(SoLuongSinhVien * sizeof(SV));
	NhapDanhSachSinhVien(ptr, &SoLuongSinhVien);
	XuatDanhSachSinhVien(ptr, &SoLuongSinhVien);
	printf("\n=========================================\n");
	printf("Sap xep sinh vien theo so tuoi tang dan\n");
	SapXepDanhSachSinhVienTheoSoTuoiTangDan(ptr, &SoLuongSinhVien);
	XuatDanhSachSinhVien(ptr, &SoLuongSinhVien);
	printf("\n\n");
	TimSinhVienCoDiemThapNhat(ptr, SoLuongSinhVien);
	free(ptr);
}
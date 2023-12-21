#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
	


struct SinhVien {
	char MSSV[12];
	char HoTen[25];
	char DiaChi[25];
	int Tuoi;
	float DiemSo;
};
typedef SinhVien SV;

void TextColor(int x)//X là mã màu
{
 //Các hàm này là hàm thao tác API với windows bạn cứ coppy thôi không cần phải hiểu quá sâu
    HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, x);
}

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
	printf("| %-11s ", sv->MSSV); 
	printf("| %-25s ", sv->HoTen); 
	printf("| %-25s ", sv->DiaChi); 
	printf("| %-5d ", sv->Tuoi);
	printf("| %-5.2f |", sv->DiemSo); 
}

void XuatDanhSachSinhVien(SV *sv, int *SoLuongSinhVien) {
	printf("=============================================================================================\n");
	printf("| %-3s | %-11s | %-25s | %-25s | %-5s | %-5s |", "STT", "MSSV", "Ho va ten", "Dia chi", "Tuoi", "Diem");
	printf("\n=============================================================================================\n");
	for (int i = 0; i < *SoLuongSinhVien; i++) {
		//XuatThongTinMotSinhVien(sv+i);
		printf("| %-3d ", i+1);
		printf("| %-11s ", (sv+i)->MSSV); 
		printf("| %-25s ", (sv+i)->HoTen); 
		printf("| %-25s ", (sv+i)->DiaChi); 
		printf("| %-5d ", (sv+i)->Tuoi);
		printf("| %-5.2f |", (sv+i)->DiemSo); 
		printf("\n---------------------------------------------------------------------------------------------\n");
	}
}

void GhiThongTinSinhVienVaoFile(SV *sv, int *SoLuongSinhVien, char nameFile[]) {
	FILE *fptr;
	fptr = fopen(nameFile, "w");
	if(fptr == NULL) {
		printf("Error !");
		exit(1);
	}
	fprintf(fptr, "=============================================================================================\n");
	fprintf(fptr, "| %-3s | %-11s | %-25s | %-25s | %-5s | %-5s |", "STT", "MSSV", "Ho va ten", "Dia chi", "Tuoi", "Diem");
	fprintf(fptr, "\n=============================================================================================\n");
	for (int i = 0; i < *SoLuongSinhVien; i++) {
		fprintf(fptr, "| %-3d ", i+1);
		fprintf(fptr, "| %-11s ", (sv+i)->MSSV); 
		fprintf(fptr, "| %-25s ", (sv+i)->HoTen); 
		fprintf(fptr, "| %-25s ", (sv+i)->DiaChi); 
		fprintf(fptr, "| %-5d ", (sv+i)->Tuoi);
		fprintf(fptr, "| %-5.2f |", (sv+i)->DiemSo); 
		fprintf(fptr,"\n---------------------------------------------------------------------------------------------\n");
	}
	fclose(fptr);
}

void DocThongTinSinhVienTuFile(SV *sv, int *SoLuongSinhVien, char nameFile[]) {
	FILE *fptr;
	fptr = fopen(nameFile, "r");
	if(fptr == NULL) {
		printf("Error !");
		exit(1);
	}
	for(int i = 0; i < *SoLuongSinhVien; i++) {
		fgets((sv+i)->MSSV, sizeof((sv+i)->MSSV), fptr); XoaXuongDong((sv+i)->MSSV);
		fgets((sv+i)->HoTen, sizeof((sv+i)->HoTen), fptr); XoaXuongDong((sv+i)->HoTen);
		fgets((sv+i)->DiaChi, sizeof((sv+i)->DiaChi), fptr); XoaXuongDong((sv+i)->DiaChi);
		fscanf(fptr, "%d", &(sv+i)->Tuoi); getchar();
		fscanf(fptr, "%f", &(sv+i)->DiemSo); getchar();
	}
	fclose(fptr);
}

void SapXepSinhVienTheoMSSV(SV *sv, int *SoLuongSinhVien) {
	for (int i = 0; i < *SoLuongSinhVien; i++) {
		for (int j = i+1; j < *SoLuongSinhVien; j++) {
			if (strcmp((sv+i)->MSSV, (sv+j)->MSSV) > 0) {
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
	for(int i = *SoLuongSinhVien-2; i >= ViTriThemSV-1; i--) {
			*(sv+i+1) = *(sv+i);
	}
	NhapThongTinMotSinhVien(sv+ViTriThemSV-1);
	*(sv+ViTriThemSV-1) = *(sv+ViTriThemSV-1);
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
	if(temp == -1) {
		printf("MSSV khong hop le !");
		return;
	}
	for(int i = temp; i < *SoLuongSinhVien-1; i++)
		*(sv + i) = *(sv + i + 1);
	sv = (SV *) realloc(sv, --*SoLuongSinhVien);
	printf("Xoa sinh vien thanh cong !");
}

void ThayDoiThongTinSinhVien(SV *sv, int *SoLuongSinhVien) {
	char ID[12];
	int temp = -1;
	printf("Nhap MSSV cua sinh vien can thay doi thong tin: ");
	fgets(ID, sizeof(ID), stdin); XoaXuongDong(ID);
	for(int i = 0; i < *SoLuongSinhVien; i++) {
		if(strcmp(ID, (sv+i)->MSSV) == 0)
			temp = i;
	}
	if(temp == -1) {
		printf("MSSV khong hop le !");
		return;
	}
	NhapThongTinMotSinhVien(sv+temp);
	printf("Thay doi thong tin sinh vien thanh cong !");
}

int main() {
	TextColor(5);
	char nameFile[] = "Quanlysinhvien";
	int SoLuongSinhVien;
	printf("Nhap so luong sinh vien: "); scanf("%d", &SoLuongSinhVien); getchar();
	SV sv;
	SV *ptr = &sv;
	ptr = (SV *) malloc(SoLuongSinhVien * sizeof(SV));
	NhapDanhSachSinhVien(ptr, &SoLuongSinhVien);
	while(true) {
		printf("\n===================== M E N U =======================");
		printf("\n|  1. Xuat danh sach sinh vien                      |");
		printf("\n|  2. Sap xep sinh vien theo ma so sinh vien        |");
		printf("\n|  3. Tim sinh vien co diem thap nhat               |");
		printf("\n|  4. Them sinh vien                                |");
		printf("\n|  5. Xoa sinh vien                                 |");
		printf("\n|  6. Thay doi thong tin sinh vien                  |");
		printf("\n|  7. Ghi thong tin sinh vien vao file              |");
		printf("\n|  8. Doc thong tin sinh vien tu file               |");
		printf("\n|  9. Xoa man hinh                                  |");
		printf("\n|  10. Thoat chuong trinh                           |");
		printf("\n=====================================================");
		int Choose;
		printf("\nVui long nhap lua chon: ");
		scanf("%d", &Choose); getchar();

		switch(Choose) {
			case 1: 
				XuatDanhSachSinhVien(ptr, &SoLuongSinhVien);
				break;
			case 2: 
				SapXepSinhVienTheoMSSV(ptr, &SoLuongSinhVien);
				XuatDanhSachSinhVien(ptr, &SoLuongSinhVien);
				break;
			case 3:
				TimSinhVienCoDiemThapNhat(ptr, SoLuongSinhVien);
				break;
			case 4:
				ThemSinhVien(ptr, &SoLuongSinhVien);
				break;
			case 5:
				XoaSinhvienTheoMSSV(ptr, &SoLuongSinhVien);
				break;
			case 6:
				ThayDoiThongTinSinhVien(ptr, &SoLuongSinhVien);
				break;
			case 7:
				GhiThongTinSinhVienVaoFile(ptr, &SoLuongSinhVien, nameFile);
				break;
			case 8: 
				DocThongTinSinhVienTuFile(ptr, &SoLuongSinhVien, nameFile);
				break;
			case 9:
				system("cls");
				break;
			case 10: 
				return 0;
		}
	}
	free(ptr);
}

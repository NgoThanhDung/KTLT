#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEN 100

// Cau truc thong tin sinh vien
typedef struct {
	int soThuTu;
	char maSo[20];
	char hoTen[MAX_TEN];
	float diemTieuLuan;
	float diemThi;
} SinhVien;

float diemTongKet(const SinhVien *sv) {
    return (sv->diemTieuLuan * 0.3) + (sv->diemThi * 0.7);
}
float timDiemCaoNhat(const SinhVien *sv, int n){
	float diemCaoNhat = 0.0;
	int i;
	for(i = 0; i < n; i++){
		float diem = diemTongKet(&sv[i]);
		if(diem>diemCaoNhat){
			diemCaoNhat = diem;
		}
	}
	return diemCaoNhat;
}
float timDiemThapNhat(const SinhVien *sv, int n){
	float diemThapNhat = diemTongKet(&sv[0]);
	int i;
	for(i = 0; i < n; i++){
		float diem = diemTongKet(&sv[i]);
		if(diem<diemThapNhat){
			diemThapNhat = diem;
		}
	}
	return diemThapNhat;
}

void ketQuaHocTap(const SinhVien *sv,int n){
	int dat = 0;
	int khongdat = 0;
	int i;
	for(i = 0; i < n; i++){
		if(diemTongKet(&sv[i])> 4){
			dat++;
		}else{
			khongdat++;
		}
	}
	printf("So sinh vien dat la: %d\n",dat);
	printf("So sinh vien khong dat la: %d\n",khongdat);
}

float quyDoiDiemHe4(float diemso){
	return (diemso*4)/10;
	
}

void sapXepTangDan(SinhVien *sv, int n){
	int i, j;
	
	for(i = 0; i< n-1; i++){
		for(j = i+1; j< n; j++){
			if(diemTongKet(&sv[i])>diemTongKet(&sv[j])){
				SinhVien temp = sv[i];
				sv[i] = sv[j];
				sv[j] = temp;
			}
		}
	}
}

void sapXepGiamDan(SinhVien *sv, int n){
	int i, j;
	
	for(i = 0; i< n-1; i++){
		for(j = i+1; j< n; j++){
			if(diemTongKet(&sv[i])<diemTongKet(&sv[j])){
				SinhVien temp = sv[i];
				sv[i] = sv[j];
				sv[j] = temp;
			}
		}
	}
}

float diemTB(SinhVien *sv, int n){
	float diem = 0;
	int i;
	for(i = 0; i<n; i++){
		diem += diemTongKet(&sv[i]);
	}
	float trungbinh = diem/n;
	return trungbinh;
}

// Ham ghi danh sach sinh vien tu file
void ghiDanhSachSinhVienRaFile(const SinhVien *sv, int n, const char *tenFile) {
	FILE *file = fopen(tenFile, "w");
	int i;
    if (file == NULL) {
        printf("Khong the mo file de ghi.\n");
        return;
    }
    for (i = 0; i < n; i++) {
        fprintf(file, "%d\n%s\n%s\n%.2f\n%.2f\n", sv[i].soThuTu, sv[i].maSo, sv[i].hoTen, sv[i].diemTieuLuan, sv[i].diemThi);
    }
    fclose(file);
    printf("Danh sach sinh vien da duoc ghi vao file %s.\n", tenFile);
}

// Ham doc danh sach sinh vien tu file
void docDanhSachSinhVienTuFile(SinhVien *sv, int *n, const char *tenFile) {
	FILE *file = fopen(tenFile, "r");
    if (file == NULL) {
        printf("Khong the mo file de doc.\n");
        return;
    }
    int i = 0;
    while (fscanf(file, "%d\n", &sv[i].soThuTu) == 1) {
    	fscanf(file, "%s\n", sv[i].maSo);
        fgets(sv[i].hoTen, MAX_TEN, file);
        size_t len = strlen(sv[i].hoTen);
        if (len > 0 && sv[i].hoTen[len - 1] == '\n') {
        	sv[i].hoTen[len - 1] = '\0';  
        }
        fscanf(file, "%f\n", &sv[i].diemTieuLuan);
        fscanf(file, "%f\n", &sv[i].diemThi);
        i++;
        }

    *n = i;
    fclose(file);
    printf("Danh sach sinh vien da duoc doc tu file %s.\n", tenFile);
}

void nhapThongTinSinhVien(SinhVien *sv, int thuTu) {
	sv->soThuTu = thuTu;
	printf("Nhap ma so sinh vien: ");
    scanf("%s", sv->maSo);
    printf("Nhap ho ten sinh vien: ");
    getchar();
    fgets(sv->hoTen, MAX_TEN, stdin);
    size_t len = strlen(sv->hoTen);
    if (len > 0 && sv->hoTen[len - 1] == '\n') {
    	 sv->hoTen[len - 1] = '\0';
    }
    printf("Nhap diem tieu luan: ");
    scanf("%f", &sv->diemTieuLuan);
    printf("Nhap diem thi ket thuc mon: ");
    scanf("%f", &sv->diemThi);
}

void xuatThongTinSinhVien(const SinhVien *sv) {
	float diemTongKetHe10 = diemTongKet(sv);
	printf("\nSo thu tu: %d\n", sv->soThuTu);
    printf("Ma so sinh vien: %s\n", sv->maSo);
    printf("Ho ten sinh vien: %s\n", sv->hoTen);
    printf("Diem tieu luan: %.2f\n", sv->diemTieuLuan);
    printf("Diem thi ket thuc mon: %.2f\n", sv->diemThi);
    printf("Diem tong ket he 10: %.2f\n", diemTongKet(sv)); 
	printf("Diem tong ket he 4: %.2f\n", quyDoiDiemHe4(diemTongKetHe10));   
}

void nhapDanhSachSinhVien(SinhVien *dsSinhVien, int n) {
	int i;
    for (i = 0; i < n; i++) {
    	 printf("\nNhap thong tin cho sinh vien thu %d:\n", i + 1);
        nhapThongTinSinhVien(&dsSinhVien[i], i + 1);
    }
}

void xuatDanhSachSinhVien(const SinhVien *dsSinhVien, int n) {
	int i;
    for (i = 0; i < n; i++) {
        printf("\nThong tin sinh vien thu %d:\n", i + 1);
        xuatThongTinSinhVien(&dsSinhVien[i]);
    }
}

int main(){
	int n;
 	SinhVien *sv = NULL;
    int danhSachNhapXong = 0;
    
     while (1) {
     	int luaChon;
     	printf("\n--- MENU ---\n");
        printf("1. Nhap danh sach sinh vien\n");
        printf("2. Xuat danh sach sinh vien\n");
        printf("3. Sap xep danh sach sinh vien tang dan theo diem tong ket\n");
        printf("4. Sap xep danh sach sinh vien giam dan theo diem tong ket\n");
        printf("5. Tim diem tong ket cao nhat\n");
        printf("6. Tim diem tong ket thap nhat\n");
        printf("7. Tim diem trung binh cua tat ca sinh vien\n");
        printf("8. Ghi danh sach sinh vien ra file\n");
        printf("9. Doc danh sach sinh vien tu file\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &luaChon);
        
        switch (luaChon) {
        	case 1:
                // Nhap so luong sinh vien
                printf("Nhap so luong sinh vien: ");
                while (scanf("%d", &n) != 1 || n <= 0) {
                printf("Gia tri khong hop le. Vui long nhap lai so luong sinh vien: ");
                while (getchar() != '\n'); 
                }
                // Cap phat bo nho
                sv = (SinhVien *)malloc(n * sizeof(SinhVien));
                if (sv == NULL) {
                printf("Khong du bo nho.\n");
                return 1;
                }
                 // Nhap danh sach sinh vien
                nhapDanhSachSinhVien(sv, n);
                danhSachNhapXong = 1;  // Danh dau danh sach da duoc nhap
                break;
            case 2:
                if (danhSachNhapXong) {
                    // Xuat danh sach sinh vien
                    xuatDanhSachSinhVien(sv, n);
                } else {
                    printf("Danh sach sinh vien chua duoc nhap.\n");
                }
                break;
            case 3:
                if (danhSachNhapXong) {
                    // Sap xep danh sach sinh vien tang dan
                    sapXepTangDan(sv, n);
                    printf("Danh sach sinh vien da duoc sap xep tang dan theo diem tong ket.\n");
                    xuatDanhSachSinhVien(sv, n);
                } else {
                    printf("Danh sach sinh vien chua duoc nhap.\n");
                }
                break;
            case 4:
                if (danhSachNhapXong) {
                    // Sap xep danh sach sinh vien giam dan
                    sapXepGiamDan(sv, n);
                    printf("Danh sach sinh vien da duoc sap xep giam dan theo diem tong ket.\n");
                    xuatDanhSachSinhVien(sv, n);
                } else {
                    printf("Danh sach sinh vien chua duoc nhap.\n");
                }
                break;
            case 5:
                if (danhSachNhapXong) {
                    // Tim diem tong ket cao nhat
                    float diemCaoNhat = timDiemCaoNhat(sv, n);
                    printf("\nDiem tong ket cao nhat (He 10): %.2f\n", diemCaoNhat);
                    printf("Diem tong ket cao nhat (He 4): %.2f\n", quyDoiDiemHe4(diemCaoNhat));
                } else {
                    printf("Danh sach sinh vien chua duoc nhap.\n");
                }
                break;
            case 6:
                if (danhSachNhapXong) {
                    // Tim diem tong ket thap nhat
                    float diemThapNhat = timDiemThapNhat(sv, n);
                    printf("\nDiem tong ket thap nhat (He 10): %.2f\n", diemThapNhat);
                    printf("Diem tong ket thap nhat (He 4): %.2f\n", quyDoiDiemHe4(diemThapNhat));
                } else {
                    printf("Danh sach sinh vien chua duoc nhap.\n");
                }
                break;
            case 7:
            	if (danhSachNhapXong) {
                    // Diem trung binh cua tat ca sinh vien
                    float diem = diemTB(sv, n);
                    printf("\nDiem trung binh cua tat ca sinh vien (He 10): %.2f\n", diem);
                    printf("Diem trung binh cua tat ca sinh vien (He 4): %.2f\n", quyDoiDiemHe4(diem));
                } else {
                    printf("Danh sach sinh vien chua duoc nhap.\n");
                }
                break;
            case 8:
                if (danhSachNhapXong) {
                    // Ghi danh sach sinh vien ra file
                    ghiDanhSachSinhVienRaFile(sv, n, "danh_sach_sinh_vien.txt");
                } else {
                    printf("Danh sach sinh vien chua duoc nhap.\n");
                }
                break;
            case 9:
                
                free(sv);  
                printf("Nhap ten file de doc danh sach sinh vien: ");
                char tenFile[MAX_TEN];
                getchar();  
                fgets(tenFile, MAX_TEN, stdin);
                size_t len = strlen(tenFile);
                if (len > 0 && tenFile[len - 1] == '\n') {
                    tenFile[len - 1] = '\0';  
                }
                
                sv = (SinhVien *)malloc(100 * sizeof(SinhVien));  
                if (sv == NULL) {
                    printf("Khong du bo nho.\n");
                    return 1;
                }
                
                int soLuongSinhVien;
                docDanhSachSinhVienTuFile(sv, &soLuongSinhVien, tenFile);
                n = soLuongSinhVien;
                danhSachNhapXong = 1;
                break;
            case 0:
                // Thoat
                free(sv);
                printf("Thoat chuong trinh.\n");
                return 0;
                
            default:
                printf("Lua chon khong hop le. Vui long nhap lai.\n");
                break;
		}
		}
    return 0;
}


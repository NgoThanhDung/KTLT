#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Định nghĩa số lượng tối đa cho mảng sinh viên và môn học
#define MAX_SINH_VIEN 100
#define MAX_MON_HOC 5

// Cấu trúc mô tả thông tin môn học
typedef struct {
    char maMon[10];
    char tenMon[50];
    int soTinChi;
    float diem;
} MonHoc;

// Cấu trúc mô tả thông tin sinh viên
typedef struct {
    char maSV[10];
    char hoTen[50];
    MonHoc monHoc[MAX_MON_HOC];
    float diemTrungBinh;
    int soMonDaHoc;
} SinhVien;

// Hàm tính điểm trung bình cho một sinh viên
float tinhDiemTrungBinh(SinhVien sv) {
    float tongDiem = 0;
    int tongTinChi = 0;
    for (int i = 0; i < sv.soMonDaHoc; i++) {
        tongDiem += sv.monHoc[i].diem * sv.monHoc[i].soTinChi;
        tongTinChi += sv.monHoc[i].soTinChi;
    }
    if (tongTinChi == 0) return 0;
    return tongDiem / tongTinChi;
}

// Hàm nhập thông tin sinh viên
void nhapSinhVien(SinhVien *sv) {
    printf("Nhap ma so sinh vien: ");
    scanf("%s", sv->maSV);
    printf("Nhap ho ten sinh vien: ");
    getchar();  // Xóa ký tự newline khỏi bộ nhớ đệm
    fgets(sv->hoTen, sizeof(sv->hoTen), stdin);
    sv->hoTen[strcspn(sv->hoTen, "\n")] = 0;  // Xóa ký tự xuống dòng

    printf("Nhap so mon da hoc: ");
    scanf("%d", &sv->soMonDaHoc);

    for (int i = 0; i < sv->soMonDaHoc; i++) {
        printf("Nhap thong tin mon hoc thu %d\n", i + 1);
        printf("  Ma mon: ");
        scanf("%s", sv->monHoc[i].maMon);
        printf("  Ten mon: ");
        getchar();  // Xóa ký tự newline khỏi bộ nhớ đệm
        fgets(sv->monHoc[i].tenMon, sizeof(sv->monHoc[i].tenMon), stdin);
        sv->monHoc[i].tenMon[strcspn(sv->monHoc[i].tenMon, "\n")] = 0;  // Xóa ký tự xuống dòng
        printf("  So tin chi: ");
        scanf("%d", &sv->monHoc[i].soTinChi);
        printf("  Diem: ");
        scanf("%f", &sv->monHoc[i].diem);
    }

    sv->diemTrungBinh = tinhDiemTrungBinh(*sv);
}

// Hàm xuất thông tin sinh viên
void xuatSinhVien(SinhVien sv) {
    printf("Ma so sinh vien: %s\n", sv.maSV);
    printf("Ho ten sinh vien: %s\n", sv.hoTen);
    printf("Diem trung binh: %.2f\n", sv.diemTrungBinh);
    printf("Danh sach mon hoc:\n");
    for (int i = 0; i < sv.soMonDaHoc; i++) {
        printf("  Ma mon: %s\n", sv.monHoc[i].maMon);
        printf("  Ten mon: %s\n", sv.monHoc[i].tenMon);
        printf("  So tin chi: %d\n", sv.monHoc[i].soTinChi);
        printf("  Diem: %.2f\n", sv.monHoc[i].diem);
    }
}

// Hàm nhập danh sách sinh viên
void nhapDanhSachSinhVien(SinhVien ds[], int *n) {
    printf("Nhap so luong sinh vien: ");
    scanf("%d", n);
    for (int i = 0; i < *n; i++) {
        printf("\nNhap thong tin cho sinh vien thu %d\n", i + 1);
        nhapSinhVien(&ds[i]);
    }
}

// Hàm xuất danh sách sinh viên
void xuatDanhSachSinhVien(SinhVien ds[], int n) {
    printf("\nDanh sach sinh vien:\n");
    for (int i = 0; i < n; i++) {
        printf("\nThong tin sinh vien thu %d\n", i + 1);
        xuatSinhVien(ds[i]);
    }
}

// Hàm tìm sinh viên thông qua mã số sinh viên
void timSinhVienTheoMa(SinhVien ds[], int n, char *maSV) {
    for (int i = 0; i < n; i++) {
        if (strcmp(ds[i].maSV, maSV) == 0) {
            printf("\nTim thay sinh vien:\n");
            xuatSinhVien(ds[i]);
            return;
        }
    }
    printf("Khong tim thay sinh vien voi ma so %s\n", maSV);
}

// Hàm tìm sinh viên có điểm trung bình cao nhất
SinhVien timSinhVienDiemTrungBinhCaoNhat(SinhVien ds[], int n) {
    SinhVien svMax = ds[0];
    for (int i = 1; i < n; i++) {
        if (ds[i].diemTrungBinh > svMax.diemTrungBinh) {
            svMax = ds[i];
        }
    }
    return svMax;
}

// Hàm thêm một sinh viên vào danh sách
void themSinhVien(SinhVien ds[], int *n) {
    if (*n >= MAX_SINH_VIEN) {
        printf("Khong the them sinh vien. Danh sach da day.\n");
        return;
    }
    printf("\nNhap thong tin sinh vien can them:\n");
    nhapSinhVien(&ds[*n]);
    (*n)++;
}

// Hàm xóa một sinh viên ra khỏi danh sách thông qua mã số sinh viên
void xoaSinhVien(SinhVien ds[], int *n, char *maSV) {
    for (int i = 0; i < *n; i++) {
        if (strcmp(ds[i].maSV, maSV) == 0) {
            for (int j = i; j < *n - 1; j++) {
                ds[j] = ds[j + 1];
            }
            (*n)--;
            printf("Da xoa sinh vien co ma so %s\n", maSV);
            return;
        }
    }
    printf("Khong tim thay sinh vien voi ma so %s\n", maSV);
}

// Hàm sắp xếp danh sách sinh viên theo điểm trung bình (tăng dần)
void sapXepTangTheoDiemTrungBinh(SinhVien ds[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].diemTrungBinh > ds[j].diemTrungBinh) {
                SinhVien temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
}

// Hàm sắp xếp danh sách sinh viên theo điểm trung bình (giảm dần)
void sapXepGiamTheoDiemTrungBinh(SinhVien ds[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].diemTrungBinh < ds[j].diemTrungBinh) {
                SinhVien temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
}

// Hàm xếp loại học tập của sinh viên
void xepLoaiHocTap(SinhVien ds[], int n) {
    printf("\nXep loai hoc tap cua sinh vien:\n");
    for (int i = 0; i < n; i++) {
        printf("%s - %s: ", ds[i].maSV, ds[i].hoTen);
        if (ds[i].diemTrungBinh >= 9) {
            printf("Xuat sac\n");
        } else if (ds[i].diemTrungBinh >= 8) {
            printf("Gioi\n");
        } else if (ds[i].diemTrungBinh >= 6.5) {
            printf("Kha\n");
        } else if (ds[i].diemTrungBinh >= 5) {
            printf("Trung binh\n");
        } else {
            printf("Yeu\n");
        }
    }
}

// Hàm thống kê số môn đậu/rớt của sinh viên
void thongKeMonDauRot(SinhVien ds[], int n) {
    printf("\nThong ke mon dau/rot cua sinh vien:\n");
    for (int i = 0; i < n; i++) {
        int soMonDau = 0;
        int soMonRot = 0;
        for (int j = 0; j < ds[i].soMonDaHoc; j++) {
            if (ds[i].monHoc[j].diem >= 5.0) {
                soMonDau++;
            } else {
                soMonRot++;
            }
        }
        printf("%s - %s: %d mon dau, %d mon rot\n", ds[i].maSV, ds[i].hoTen, soMonDau, soMonRot);
    }
}

int main() {
    SinhVien danhSachSV[MAX_SINH_VIEN];
    int n = 0;
    int chon;
    char maSV[10];

    do {
        printf("\n========== MENU ==========\n");
        printf("1. Nhap danh sach sinh vien\n");
        printf("2. Xuat danh sach sinh vien\n");
        printf("3. Tim sinh vien theo ma so\n");
        printf("4. Tim sinh vien co diem trung binh cao nhat\n");
        printf("5. Them sinh vien\n");
        printf("6. Xoa sinh vien\n");
        printf("7. Sap xep danh sach sinh vien tang theo diem trung binh\n");
        printf("8. Sap xep danh sach sinh vien giam theo diem trung binh\n");
        printf("9. Xep loai hoc tap cua sinh vien\n");
        printf("10. Thong ke so mon dau/rot cua sinh vien\n");
        printf("0. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &chon);

        switch (chon) {
            case 1:
                nhapDanhSachSinhVien(danhSachSV, &n);
                break;
            case 2:
                xuatDanhSachSinhVien(danhSachSV, n);
                break;
            case 3:
                printf("Nhap ma so sinh vien can tim: ");
                scanf("%s", maSV);
                timSinhVienTheoMa(danhSachSV, n, maSV);
                break;
            case 4: {
                SinhVien svMax = timSinhVienDiemTrungBinhCaoNhat(danhSachSV, n);
                printf("Sinh vien co diem trung binh cao nhat:\n");
                xuatSinhVien(svMax);
                break;
            }
            case 5:
                themSinhVien(danhSachSV, &n);
                break;
            case 6:
                printf("Nhap ma so sinh vien can xoa: ");
                scanf("%s", maSV);
                xoaSinhVien(danhSachSV, &n, maSV);
                break;
            case 7:
                sapXepTangTheoDiemTrungBinh(danhSachSV, n);
                printf("Danh sach sinh vien sau khi sap xep tang dan:\n");
                xuatDanhSachSinhVien(danhSachSV, n);
                break;
            case 8:
                sapXepGiamTheoDiemTrungBinh(danhSachSV, n);
                printf("Danh sach sinh vien sau khi sap xep giam dan:\n");
                xuatDanhSachSinhVien(danhSachSV, n);
                break;
            case 9:
                xepLoaiHocTap(danhSachSV, n);
                break;
            case 10:
                thongKeMonDauRot(danhSachSV, n);
                break;
            case 0:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long nhap lai.\n");
        }
    } while (chon != 0);

    return 0;
}

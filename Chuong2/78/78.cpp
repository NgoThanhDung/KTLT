#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// Hàm kiểm tra xem chữ số đầu của một số có phải là số lẻ hay không
bool laChuSoDauLe(int x) {
    x = abs(x); // Lấy giá trị tuyệt đối của số
    while (x >= 10) {
        x /= 10;
    }
    return x % 2 != 0;
}

// Hàm tính tổng các phần tử có chữ số đầu là chữ số lẻ
int tongChuSoDauLe(int a[][100], int m, int n) {
    int tong = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (laChuSoDauLe(a[i][j])) {
                tong += a[i][j];
            }
        }
    }
    return tong;
}

// Hàm kiểm tra xem một số có phải là số hoàn thiện hay không
bool laSoHoanThien(int x) {
    if (x <= 0) return false; // Số hoàn thiện phải là số dương

    int tongUoc = 0;
    for (int i = 1; i <= x / 2; i++) {
        if (x % i == 0) {
            tongUoc += i;
        }
    }
    return tongUoc == x;
}

// Hàm liệt kê các số hoàn thiện trong ma trận
void lietKeSoHoanThien(int a[][100], int m, int n) {
    printf("Cac so hoan thien trong ma tran:\n");
    bool coSoHoanThien = false;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (laSoHoanThien(a[i][j])) {
                printf("%d ", a[i][j]);
                coSoHoanThien = true;
            }
        }
    }
    if (!coSoHoanThien) {
        printf("Khong co so hoan thien trong ma tran.\n");
    }
}

// Hàm tính tổng các phần tử lớn hơn trị tuyệt đối của phần tử liền sau nó
int tongLonHonTriTuyetDoiLienSau(int a[][100], int m, int n) {
    int tong = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - 1; j++) { // Kiểm tra từ cột đầu đến cột áp cuối
            if (a[i][j] > abs(a[i][j + 1])) {
                tong += a[i][j];
            }
        }
    }
    return tong;
}

// Hàm tính tổng giá trị trên dòng k của ma trận
int tongTrenDongK(int a[][100], int n, int k) {
    int tong = 0;
    for (int j = 0; j < n; j++) {
        tong += a[k][j];
    }
    return tong;
}

// Hàm tính tổng các giá trị nằm trên biên của ma trận
int tongTrenBienMaTran(int a[][100], int m, int n) {
    int tong = 0;

    // Tổng dòng đầu và dòng cuối
    for (int j = 0; j < n; j++) {
        tong += a[0][j] + a[m - 1][j];
    }

    // Tổng cột đầu và cột cuối, trừ các phần tử đã tính
    for (int i = 1; i < m - 1; i++) {
        tong += a[i][0] + a[i][n - 1];
    }

    return tong;
}

// Hàm đếm tần suất xuất hiện của một giá trị x trong ma trận
int demTanSuat(int a[][100], int m, int n, int x) {
    int dem = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == x) {
                dem++;
            }
        }
    }
    return dem;
}

// Hàm kiểm tra xem một số có phải là số nguyên tố hay không
bool laSoNguyenTo(int x) {
    if (x < 2) return false;
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) return false;
    }
    return true;
}

// Hàm đếm số lượng phần tử theo các loại: số chẵn, số lẻ, số âm, số dương, số nguyên tố
void demSoLuongPhanTu(int a[][100], int m, int n, int *chan, int *le, int *am, int *duong, int *nguyenTo) {
    *chan = *le = *am = *duong = *nguyenTo = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] % 2 == 0) (*chan)++;
            else (*le)++;

            if (a[i][j] < 0) (*am)++;
            if (a[i][j] > 0) (*duong)++;

            if (laSoNguyenTo(a[i][j])) (*nguyenTo)++;
        }
    }
}

// Hàm nhập ma trận
void nhapMaTran(int a[][100], int *m, int *n) {
    printf("Nhap so hang cua ma tran: ");
    scanf("%d", m);
    printf("Nhap so cot cua ma tran: ");
    scanf("%d", n);
    for (int i = 0; i < *m; i++) {
        for (int j = 0; j < *n; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}

// Hàm xuất ma trận
void xuatMaTran(int a[][100], int m, int n) {
    printf("Ma tran:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%5d ", a[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int a[100][100];
    int m, n, k, x;
    int chan, le, am, duong, nguyenTo;

    // Nhập ma trận
    nhapMaTran(a, &m, &n);
    xuatMaTran(a, m, n);

    // Bài 1: Tính tổng các phần tử có chữ số đầu là chữ số lẻ
    printf("\nTong cac phan tu co chu so dau la chu so le: %d\n", tongChuSoDauLe(a, m, n));

    // Bài 2: Liệt kê các số hoàn thiện trong ma trận
    lietKeSoHoanThien(a, m, n);

    // Bài 3: Tính tổng các phần tử lớn hơn trị tuyệt đối của phần tử liền sau nó
    printf("\nTong cac phan tu lon hon tri tuyet doi cua phan tu lien sau: %d\n", tongLonHonTriTuyetDoiLienSau(a, m, n));

    // Bài 4: Tính tổng giá trị trên dòng k của ma trận
    printf("Nhap dong k de tinh tong: ");
    scanf("%d", &k);
    if (k >= 0 && k < m) {
        printf("Tong tren dong %d: %d\n", k, tongTrenDongK(a, n, k));
    } else {
        printf("Dong k khong hop le.\n");
    }

    // Bài 5: Tính tổng các giá trị nằm trên biên của ma trận
    printf("Tong cac gia tri tren bien cua ma tran: %d\n", tongTrenBienMaTran(a, m, n));

    // Bài 6: Đếm tần suất xuất hiện của 1 giá trị x trong ma trận
    printf("Nhap gia tri x de dem tan suat xuat hien: ");
    scanf("%d", &x);
    printf("Gia tri %d xuat hien %d lan trong ma tran.\n", x, demTanSuat(a, m, n, x));

    // Bài 7: Đếm số lượng các phần tử là số chẵn, số lẻ, số âm, số dương, số nguyên tố
    demSoLuongPhanTu(a, m, n, &chan, &le, &am, &duong, &nguyenTo);
    printf("\nSo chan: %d\n", chan);
    printf("So le: %d\n", le);
    printf("So am: %d\n", am);
    printf("So duong: %d\n", duong);
    printf("So nguyen to: %d\n", nguyenTo);

    return 0;
}

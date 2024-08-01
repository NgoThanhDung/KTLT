#include <stdio.h>
#include <stdlib.h>

// Cấu trúc phân số
typedef struct {
    int tu;
    int mau;
} PhanSo;

// Hàm nhập danh sách các phân số
void nhapDanhSachPhanSo(PhanSo arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhap tu so cua phan so thu %d: ", i + 1);
        scanf("%d", &arr[i].tu);
        printf("Nhap mau so cua phan so thu %d (khac 0): ", i + 1);
        do {
            scanf("%d", &arr[i].mau);
            if (arr[i].mau == 0) {
                printf("Mau so phai khac 0. Nhap lai: ");
            }
        } while (arr[i].mau == 0);
    }
}

// Hàm xuất danh sách các phân số
void xuatDanhSachPhanSo(PhanSo arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d/%d ", arr[i].tu, arr[i].mau);
    }
    printf("\n");
}

// Hàm so sánh hai phân số, trả về giá trị phân số 1 lớn hơn phân số 2 thì trả về 1, nhỏ hơn trả về -1, bằng trả về 0
int soSanhPhanSo(PhanSo ps1, PhanSo ps2) {
    int t1 = ps1.tu * ps2.mau;
    int t2 = ps2.tu * ps1.mau;
    if (t1 > t2) return 1;
    if (t1 < t2) return -1;
    return 0;
}

// Hàm tìm phân số có giá trị lớn nhất
PhanSo timPhanSoLonNhat(PhanSo arr[], int n) {
    PhanSo max = arr[0];
    for (int i = 1; i < n; i++) {
        if (soSanhPhanSo(arr[i], max) > 0) {
            max = arr[i];
        }
    }
    return max;
}

// Hàm tìm phân số có giá trị nhỏ nhất
PhanSo timPhanSoNhoNhat(PhanSo arr[], int n) {
    PhanSo min = arr[0];
    for (int i = 1; i < n; i++) {
        if (soSanhPhanSo(arr[i], min) < 0) {
            min = arr[i];
        }
    }
    return min;
}

// Hàm tính tổng các phân số
PhanSo tongPhanSo(PhanSo arr[], int n) {
    PhanSo sum = {0, 1}; // Khởi tạo tổng là 0
    for (int i = 0; i < n; i++) {
        sum.tu = sum.tu * arr[i].mau + arr[i].tu * sum.mau;
        sum.mau = sum.mau * arr[i].mau;
    }
    return sum;
}

// Hàm tính tích các phân số
PhanSo tichPhanSo(PhanSo arr[], int n) {
    PhanSo product = {1, 1}; // Khởi tạo tích là 1
    for (int i = 0; i < n; i++) {
        product.tu *= arr[i].tu;
        product.mau *= arr[i].mau;
    }
    return product;
}

// Hàm xuất nghịch đảo giá trị các phân số trong mảng
void nghichDaoPhanSo(PhanSo arr[], int n) {
    printf("Nghich dao cua cac phan so trong mang: ");
    for (int i = 0; i < n; i++) {
        if (arr[i].tu != 0) { // Nếu tử số khác 0, nghịch đảo phân số
            printf("%d/%d ", arr[i].mau, arr[i].tu);
        } else {
            printf("Khong co nghich dao ");
        }
    }
    printf("\n");
}

// Hàm sắp xếp mảng tăng dần theo phương pháp Interchange Sort
void sapXepTangDan(PhanSo arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (soSanhPhanSo(arr[i], arr[j]) > 0) { // Nếu arr[i] lớn hơn arr[j] thì hoán đổi
                PhanSo temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Hàm sắp xếp mảng giảm dần theo phương pháp Interchange Sort
void sapXepGiamDan(PhanSo arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (soSanhPhanSo(arr[i], arr[j]) < 0) { // Nếu arr[i] nhỏ hơn arr[j] thì hoán đổi
                PhanSo temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Hàm tìm ước chung lớn nhất (gcd)
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Hàm tối giản phân số
PhanSo toiGianPhanSo(PhanSo ps) {
    int gcdValue = gcd(abs(ps.tu), abs(ps.mau));
    ps.tu /= gcdValue;
    ps.mau /= gcdValue;
    // Đảm bảo mẫu số luôn dương
    if (ps.mau < 0) {
        ps.tu = -ps.tu;
        ps.mau = -ps.mau;
    }
    return ps;
}

// Hàm hiển thị phân số
void hienThiPhanSo(PhanSo ps) {
    ps = toiGianPhanSo(ps);
    if (ps.mau == 1) {
        printf("%d", ps.tu);
    } else {
        printf("%d/%d", ps.tu, ps.mau);
    }
}

int main() {
    int n;

    // Nhập số lượng phân số
    do {
        printf("Nhap so luong phan so (toi da 50): ");
        scanf("%d", &n);
        if (n < 1 || n > 50) {
            printf("So luong phan so khong hop le. Vui long nhap lai.\n");
        }
    } while (n < 1 || n > 50);

    PhanSo arr[50];

    // Nhập danh sách phân số
    nhapDanhSachPhanSo(arr, n);

    // Xuất danh sách phân số
    printf("Danh sach phan so:\n");
    xuatDanhSachPhanSo(arr, n);

    // Tìm phân số lớn nhất và nhỏ nhất
    PhanSo max = timPhanSoLonNhat(arr, n);
    PhanSo min = timPhanSoNhoNhat(arr, n);
    printf("Phan so lon nhat la: ");
    hienThiPhanSo(max);
    printf("\nPhan so nho nhat la: ");
    hienThiPhanSo(min);
    printf("\n");

    // Tính tổng và tích các phân số
    PhanSo sum = tongPhanSo(arr, n);
    PhanSo product = tichPhanSo(arr, n);
    printf("Tong cac phan so: ");
    hienThiPhanSo(sum);
    printf("\nTich cac phan so: ");
    hienThiPhanSo(product);
    printf("\n");

    // Xuất nghịch đảo các phân số
    nghichDaoPhanSo(arr, n);

    // Sắp xếp mảng tăng dần và xuất
    sapXepTangDan(arr, n);
    printf("Mang sau khi sap xep tang dan:\n");
    xuatDanhSachPhanSo(arr, n);

    // Sắp xếp mảng giảm dần và xuất
    sapXepGiamDan(arr, n);
    printf("Mang sau khi sap xep giam dan:\n");
    xuatDanhSachPhanSo(arr, n);

    return 0;
}

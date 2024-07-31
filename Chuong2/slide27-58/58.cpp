#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Hàm kiểm tra số nguyên tố
bool kiemTraSoNguyenTo(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Hàm đếm số phần tử có giá trị là số nguyên tố
int demSoNguyenTo(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (kiemTraSoNguyenTo(arr[i])) {
            count++;
        }
    }
    return count;
}

// Hàm kiểm tra từng chữ số của số có phải là số lẻ
bool kiemTraChuSoLe(int n) {
    while (n > 0) {
        int digit = n % 10;
        if (digit % 2 == 0) {
            return false;
        }
        n /= 10;
    }
    return true;
}

// Hàm xuất các phần tử mà từng chữ số của nó là số lẻ
void xuatPhanTuChuSoLe(int arr[], int n) {
    printf("Cac phan tu ma tung chu so cua no la so le: ");
    bool found = false; // Cờ để kiểm tra nếu có phần tử thỏa mãn điều kiện
    for (int i = 0; i < n; i++) {
        if (kiemTraChuSoLe(arr[i])) {
            printf("%d ", arr[i]);
            found = true;
        }
    }
    if (!found) {
        printf("Khong co phan tu nao thoa man.");
    }
    printf("\n");
}

// Hàm tìm vị trí số lớn nhất (cuối cùng)
int timViTriSoLonNhatCuoiCung(int arr[], int n) {
    int max = arr[0];
    int viTri = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] >= max) { // Tìm phần tử lớn nhất và lấy vị trí cuối cùng
            max = arr[i];
            viTri = i;
        }
    }
    return viTri;
}

// Hàm kiểm tra mảng có toàn là số chẵn không
bool kiemTraMangToanChan(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0) { // Nếu có số lẻ, mảng không toàn chẵn
            return false;
        }
    }
    return true;
}

// Hàm kiểm tra mảng có phải là dãy số chẵn lẻ xen kẽ không
bool kiemTraDayChanLeXenKe(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if ((arr[i] % 2 == 0 && arr[i + 1] % 2 == 0) || (arr[i] % 2 != 0 && arr[i + 1] % 2 != 0)) {
            return false; // Nếu có hai số chẵn hoặc lẻ liên tiếp, không phải là dãy xen kẽ
        }
    }
    return true;
}

int main() {
    // Khai báo mảng
    int arr[] = {3, 11, 13, 15, 23, 44, 99, 8, 10, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Đếm số phần tử là số nguyên tố
    int soLuongSoNguyenTo = demSoNguyenTo(arr, n);
    printf("So luong phan tu la so nguyen to trong mang: %d\n", soLuongSoNguyenTo);

    // Xuất các phần tử mà từng chữ số của nó là số lẻ
    xuatPhanTuChuSoLe(arr, n);

    // Tìm vị trí số lớn nhất (cuối cùng)
    int viTriSoLonNhatCuoiCung = timViTriSoLonNhatCuoiCung(arr, n);
    printf("Vi tri so lon nhat (cuoi cung) trong mang: %d\n", viTriSoLonNhatCuoiCung);

    // Kiểm tra mảng có toàn là số chẵn không
    if (kiemTraMangToanChan(arr, n)) {
        printf("Mang co toan la so chan.\n");
    } else {
        printf("Mang khong toan la so chan.\n");
    }

    // Kiểm tra mảng có phải là dãy số chẵn lẻ xen kẽ không
    if (kiemTraDayChanLeXenKe(arr, n)) {
        printf("Mang la day chan le xen ke.\n");
    } else {
        printf("Mang khong phai la day chan le xen ke.\n");
    }

    return 0;
}

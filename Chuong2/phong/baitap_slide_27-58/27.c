#include <stdio.h>
#include <string.h>

// Hàm sắp xếp mảng số nguyên tăng dần
void sapXepTangNguyen(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Hàm sắp xếp mảng số nguyên giảm dần
void sapXepGiamNguyen(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Hàm sắp xếp mảng số thực tăng dần
void sapXepTangThuc(float arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                float temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Hàm sắp xếp mảng số thực giảm dần
void sapXepGiamThuc(float arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                float temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Hàm sắp xếp mảng ký tự tăng dần
void sapXepTangKyTu(char arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                char temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Hàm sắp xếp mảng ký tự giảm dần
void sapXepGiamKyTu(char arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                char temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Hàm sắp xếp mảng chuỗi ký tự tăng dần
void sapXepTangChuoi(char arr[][100], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(arr[i], arr[j]) > 0) {
                char temp[100];
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }
}

// Hàm sắp xếp mảng chuỗi ký tự giảm dần
void sapXepGiamChuoi(char arr[][100], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(arr[i], arr[j]) < 0) {
                char temp[100];
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }
}

// Hàm hiển thị mảng số nguyên
void hienThiNguyen(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Hàm hiển thị mảng số thực
void hienThiThuc(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

// Hàm hiển thị mảng ký tự
void hienThiKyTu(char arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%c ", arr[i]);
    }
    printf("\n");
}

// Hàm hiển thị mảng chuỗi ký tự
void hienThiChuoi(char arr[][100], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Mảng số nguyên
    int arrNguyen[] = {5, 3, 8, 1, 2};
    int nNguyen = sizeof(arrNguyen) / sizeof(arrNguyen[0]);

    // Mảng số thực
    float arrThuc[] = {2.5, 3.1, 1.8, 4.0, 2.2};
    int nThuc = sizeof(arrThuc) / sizeof(arrThuc[0]);

    // Mảng ký tự
    char arrKyTu[] = {'e', 'a', 'd', 'b', 'c'};
    int nKyTu = sizeof(arrKyTu) / sizeof(arrKyTu[0]);

    // Mảng chuỗi ký tự
    char arrChuoi[][100] = {"apple", "banana", "cherry", "date", "elderberry"};
    int nChuoi = sizeof(arrChuoi) / sizeof(arrChuoi[0]);

    // Sắp xếp tăng dần và hiển thị
    printf("Mang so nguyen ban dau: ");
    hienThiNguyen(arrNguyen, nNguyen);
    sapXepTangNguyen(arrNguyen, nNguyen);
    printf("Mang so nguyen sau khi sap xep tang: ");
    hienThiNguyen(arrNguyen, nNguyen);

    printf("\nMang so thuc ban dau: ");
    hienThiThuc(arrThuc, nThuc);
    sapXepTangThuc(arrThuc, nThuc);
    printf("Mang so thuc sau khi sap xep tang: ");
    hienThiThuc(arrThuc, nThuc);

    printf("\nMang ky tu ban dau: ");
    hienThiKyTu(arrKyTu, nKyTu);
    sapXepTangKyTu(arrKyTu, nKyTu);
    printf("Mang ky tu sau khi sap xep tang: ");
    hienThiKyTu(arrKyTu, nKyTu);

    printf("\nMang chuoi ky tu ban dau: ");
    hienThiChuoi(arrChuoi, nChuoi);
    sapXepTangChuoi(arrChuoi, nChuoi);
    printf("Mang chuoi ky tu sau khi sap xep tang: ");
    hienThiChuoi(arrChuoi, nChuoi);

    // Sắp xếp giảm dần và hiển thị
    printf("\nMang so nguyen ban dau: ");
    hienThiNguyen(arrNguyen, nNguyen);
    sapXepGiamNguyen(arrNguyen, nNguyen);
    printf("Mang so nguyen sau khi sap xep giam: ");
    hienThiNguyen(arrNguyen, nNguyen);

    printf("\nMang so thuc ban dau: ");
    hienThiThuc(arrThuc, nThuc);
    sapXepGiamThuc(arrThuc, nThuc);
    printf("Mang so thuc sau khi sap xep giam: ");
    hienThiThuc(arrThuc, nThuc);

    printf("\nMang ky tu ban dau: ");
    hienThiKyTu(arrKyTu, nKyTu);
    sapXepGiamKyTu(arrKyTu, nKyTu);
    printf("Mang ky tu sau khi sap xep giam: ");
    hienThiKyTu(arrKyTu, nKyTu);

    printf("\nMang chuoi ky tu ban dau: ");
    hienThiChuoi(arrChuoi, nChuoi);
    sapXepGiamChuoi(arrChuoi, nChuoi);
    printf("Mang chuoi ky tu sau khi sap xep giam: ");
    hienThiChuoi(arrChuoi, nChuoi);

    return 0;
}

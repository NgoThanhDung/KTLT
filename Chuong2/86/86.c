#include <stdio.h>
#include <stdlib.h>

// Hàm hoán đổi hai số nguyên
void hoanDoi(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm sắp xếp dòng chẵn tăng, dòng lẻ giảm
void sapXepDongChanTangLeGiam(int a[][100], int n, int m) {
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) { // Dòng chẵn: sắp xếp tăng dần
            for (int j = 0; j < m - 1; j++) {
                for (int k = j + 1; k < m; k++) {
                    if (a[i][j] > a[i][k]) {
                        hoanDoi(&a[i][j], &a[i][k]);
                    }
                }
            }
        } else { // Dòng lẻ: sắp xếp giảm dần
            for (int j = 0; j < m - 1; j++) {
                for (int k = j + 1; k < m; k++) {
                    if (a[i][j] < a[i][k]) {
                        hoanDoi(&a[i][j], &a[i][k]);
                    }
                }
            }
        }
    }
}

// Hàm sắp xếp cột chẵn tăng, cột lẻ giảm
void sapXepCotChanTangLeGiam(int a[][100], int n, int m) {
    for (int j = 0; j < m; j++) {
        if (j % 2 == 0) { // Cột chẵn: sắp xếp tăng dần
            for (int i = 0; i < n - 1; i++) {
                for (int k = i + 1; k < n; k++) {
                    if (a[i][j] > a[k][j]) {
                        hoanDoi(&a[i][j], &a[k][j]);
                    }
                }
            }
        } else { // Cột lẻ: sắp xếp giảm dần
            for (int i = 0; i < n - 1; i++) {
                for (int k = i + 1; k < n; k++) {
                    if (a[i][j] < a[k][j]) {
                        hoanDoi(&a[i][j], &a[k][j]);
                    }
                }
            }
        }
    }
}

// Hàm sắp xếp zic-zac
void sapXepZicZac(int a[][100], int n, int m, int tangDan) {
    int len = n * m;
    int temp[10000];
    int index = 0;

    // Chuyển ma trận 2D thành mảng 1D
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            temp[index++] = a[i][j];
        }
    }

    // Sắp xếp mảng 1D tăng dần
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if ((tangDan && temp[i] > temp[j]) || (!tangDan && temp[i] < temp[j])) {
                hoanDoi(&temp[i], &temp[j]);
            }
        }
    }

    // Chuyển mảng 1D đã sắp xếp về ma trận 2D zic-zac
    index = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) { // Dòng chẵn: zic-zac theo chiều xuôi
            for (int j = 0; j < m; j++) {
                a[i][j] = temp[index++];
            }
        } else { // Dòng lẻ: zic-zac theo chiều ngược
            for (int j = m - 1; j >= 0; j--) {
                a[i][j] = temp[index++];
            }
        }
    }
}

// Hàm nhập ma trận
void nhapMaTran(int a[][100], int *n, int *m) {
    printf("Nhap so hang cua ma tran: ");
    scanf("%d", n);
    printf("Nhap so cot cua ma tran: ");
    scanf("%d", m);
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *m; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}

// Hàm xuất ma trận
void xuatMaTran(int a[][100], int n, int m) {
    printf("Ma tran:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%5d ", a[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int a[100][100];
    int n, m;

    // Nhập ma trận
    nhapMaTran(a, &n, &m);
    printf("Ma tran ban dau:\n");
    xuatMaTran(a, n, m);

    // Bài 1: Sắp xếp các phần tử trong ma trận sao cho dòng chẵn tăng dòng lẻ giảm
    sapXepDongChanTangLeGiam(a, n, m);
    printf("\nMa tran sau khi sap xep dong chan tang dong le giam:\n");
    xuatMaTran(a, n, m);

    // Bài 2: Sắp xếp các phần tử trong ma trận sao cho cột chẵn tăng cột lẻ giảm
    sapXepCotChanTangLeGiam(a, n, m);
    printf("\nMa tran sau khi sap xep cot chan tang cot le giam:\n");
    xuatMaTran(a, n, m);

    // Bài 3: Sắp xếp ma trận tăng dần theo zic-zac
    sapXepZicZac(a, n, m, 1);
    printf("\nMa tran sau khi sap xep tang dan theo zic-zac:\n");
    xuatMaTran(a, n, m);

    // Bài 3: Sắp xếp ma trận giảm dần theo zic-zac
    sapXepZicZac(a, n, m, 0);
    printf("\nMa tran sau khi sap xep giam dan theo zic-zac:\n");
    xuatMaTran(a, n, m);

    return 0;
}

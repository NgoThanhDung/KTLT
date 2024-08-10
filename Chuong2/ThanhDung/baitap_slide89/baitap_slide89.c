#include <stdio.h>
#include <conio.h>

// Ham de tao ma tran vuong kich thuoc n x n
int** taoMaTran(int n) {
    int** maTran = (int**)malloc(n * sizeof(int*)); // Cap phat bo nho cho cac hang
    int i;

    for (i = 0; i < n; i++) {
        maTran[i] = (int*)malloc(n * sizeof(int)); // Cap phat bo nho cho cac cot
    }
    return maTran;
}

// Ham de giai phong bo nho cua ma tran
void giaiPhongMaTran(int** maTran, int n) {
    int i;

    for (i = 0; i < n; i++) {
        free(maTran[i]); // Giai phong bo nho cho tung hang
    }
    free(maTran); // Giai phong bo nho cho mang con tro
}

// Ham de nhap du lieu vao ma tran
void nhapDuLieu(int** maTran, int n) {
    int i, j;

    printf("Nhap cac phan tu cua ma tran:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("maTran[%d][%d] = ", i, j);
            scanf("%d", &maTran[i][j]);
        }
    }
}

// Ham de in ma tran ra man hinh
void inMaTran(int** maTran, int n) {
    int i, j;

    printf("Ma tran da nhap la:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", maTran[i][j]);
        }
        printf("\n");
    }
}

// Ham de tinh tong cac phan tu tren duong cheo chinh
int tinhTongDuongCheoChinh(int** maTran, int n) {
    int i;
    int tong = 0;

    for (i = 0; i < n; i++) {
        tong += maTran[i][i]; // Cong tong cac phan tu tren duong cheo chinh
    }

    return tong;
}

// Ham de tinh tong cac phan tu tren duong cheo phu
int tinhTongDuongCheoPhu(int** maTran, int n) {
    int i;
    int tong = 0;

    for (i = 0; i < n; i++) {
        tong += maTran[i][n-i-1]; // Cong tong cac phan tu tren duong cheo phu
    }

    return tong;
}

// Ham de tinh tong cac phan tu nam phia tren duong cheo chinh
int tinhTongTrenDuongCheoChinh(int** maTran, int n) {
    int i, j;
    int tong = 0;

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            tong += maTran[i][j]; // Cong tong cac phan tu nam phia tren duong cheo chinh
        }
    }

    return tong;
}

// Ham de tinh tong cac phan tu nam phia tren duong cheo phu
int tinhTongTrenDuongCheoPhu(int** maTran, int n) {
    int i, j;
    int tong = 0;

    for (i = 0; i < n; i++) {
        for (j = n - i; j < n; j++) {
            tong += maTran[i][j]; // Cong tong cac phan tu nam phia tren duong cheo phu
        }
    }

    return tong;
}
int main(){
	
	int n;
    int** maTran = NULL;
    int luaChon;
    int tong;

	do {
        // Hien thi menu
        printf("\n===== MENU =====\n");
        printf("1. Tao ma tran moi\n");
        printf("2. Nhap du lieu vao ma tran\n");
        printf("3. In ma tran ra man hinh\n");
        printf("4. Tinh tong duong cheo chinh\n");
        printf("5. Tinh tong duong cheo phu\n");
        printf("6. Tinh tong cac phan tu nam phia tren duong cheo chinh\n");
        printf("7. Tinh tong cac phan tu nam phia tren duong cheo phu\n");
        printf("0. Thoat\n");
          
        printf("Lua chon cua ban (0-4): ");
        scanf("%d", &luaChon);
         switch (luaChon) {
            case 1:
                // Nhap kich thuoc ma tran
                printf("Nhap kich thuoc ma tran vuong n x n: ");
                scanf("%d", &n);

                // Giai phong ma tran cu neu co
                if (maTran != NULL) {
                    giaiPhongMaTran(maTran, n);
                }

                // Tao ma tran moi
                maTran = taoMaTran(n);
                printf("Ma tran moi da duoc tao!\n");
                break;

            case 2:
                if (maTran == NULL) {
                    printf("Chua co ma tran, vui long tao ma tran truoc!\n");
                } else {
                    // Nhap du lieu vao ma tran
                    nhapDuLieu(maTran, n);
                }
                break;

            case 3:
                if (maTran == NULL) {
                    printf("Chua co ma tran, vui long tao ma tran truoc!\n");
                } else {
                    // In ma tran ra man hinh
                    inMaTran(maTran, n);
                }
                break;
            case 4:
                if (maTran == NULL) {
                    printf("Chua co ma tran, vui long tao ma tran truoc!\n");
                } else {
                    // Tinh tong duong cheo chinh
                    tong = tinhTongDuongCheoChinh(maTran, n);
                    printf("Tong cac phan tu tren duong cheo chinh la: %d\n", tong);
                }
                break;
            case 5:
                if (maTran == NULL) {
                    printf("Chua co ma tran, vui long tao ma tran truoc!\n");
                } else {
                    // Tinh tong duong cheo phu
                    tong = tinhTongDuongCheoPhu(maTran, n);
                    printf("Tong cac phan tu tren duong cheo phu la: %d\n", tong);
                }
                break;
            case 6:
                if (maTran == NULL) {
                    printf("Chua co ma tran, vui long tao ma tran truoc!\n");
                } else {
                    // Tinh tong cac phan tu nam phia tren duong cheo chinh
                    tong = tinhTongTrenDuongCheoChinh(maTran, n);
                    printf("Tong cac phan tu nam phia tren duong cheo chinh la: %d\n", tong);
                }
                break;
			case 7:
                if (maTran == NULL) {
                    printf("Chua co ma tran, vui long tao ma tran truoc!\n");
                } else {
                    // Tinh tong cac phan tu nam phia tren duong cheo phu
                    tong = tinhTongTrenDuongCheoPhu(maTran, n);
                    printf("Tong cac phan tu nam phia tren duong cheo phu la: %d\n", tong);
                }
                break;

            case 0:
                // Thoat chuong trinh
                if (maTran != NULL) {
                    giaiPhongMaTran(maTran, n);
                }
                printf("Thoat chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le, vui long chon tu 1 den 4.\n");
                break;
        }

    } while (luaChon != 0);

    return 0;

}


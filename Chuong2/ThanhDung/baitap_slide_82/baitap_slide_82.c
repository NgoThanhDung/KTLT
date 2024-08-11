#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void nhapMaTran(int** maTran, int soDong, int soCot) {
	 int i, j;
	 printf("Nhap cac phan tu cua ma tran (%dx%d):\n", soDong, soCot);
	 for (i = 0; i < soDong; ++i) {
	 	 for (j = 0; j < soCot; ++j) {
	 	 	printf("Nhap phan tu tai [%d][%d]: ", i, j);
            scanf("%d", &maTran[i][j]);
        }
    }
}
void inMaTran(int **maTran, int soDong, int soCot) {
	int i, j;
    printf("Ma tran:\n");
    for (i = 0; i < soDong; ++i) {
    	for (j = 0; j < soCot; ++j) {
            printf("%d ", maTran[i][j]);
        }
        printf("\n");
    }
}

// Tinh tong cot
void tinhTongCot(int **maTran, int soDong, int soCot, int *tongCot) {
	int i,j;
    for (j = 0; j < soCot; ++j) {
        tongCot[j] = 0;
        for (i = 0; i < soDong; ++i) {
            tongCot[j] += maTran[i][j];
        }
    }
}

void lietKeCotTongNhoNhat(int *tongCot, int soCot) {
	int j;
    int tongNhoNhat = tongCot[0];
    
    // Tim tong nho nhat
    for (j = 1; j < soCot; ++j) {
        if (tongCot[j] < tongNhoNhat) {
            tongNhoNhat = tongCot[j];
        }
    }
    
    printf("Cac cot co tong nho nhat gia tri la: %d:\n", tongNhoNhat);
    for (j = 0; j < soCot; ++j) {
        if (tongCot[j] == tongNhoNhat) {
            printf("Cot %d\n", j);
        }
    }
}
// Ham kiem tra so nguyen to
bool laSoNguyenTo(int n) {
	int i;
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

// Ham tinh so luong so nguyen to trong tung dong
void tinhSoNguyenToTheoDong(int **maTran, int soDong, int soCot, int *soNguyenToTheoDong) {
    int i, j; 
    for (i = 0; i < soDong; ++i) {
        soNguyenToTheoDong[i] = 0;
        for (j = 0; j < soCot; ++j) {
            if (laSoNguyenTo(maTran[i][j])) {
                soNguyenToTheoDong[i]++;
            }
        }
    }
}

// Ham liet ke cac dong co so luong so nguyen to nhieu nhat
void lietKeDongSoNguyenToNhieuNhat(int *soNguyenToTheoDong, int soDong) {
    int i; 
    int soNguyenToMax = soNguyenToTheoDong[0];
    
    // Tim so luong so nguyen to nhieu nhat
    for (i = 1; i < soDong; ++i) {
        if (soNguyenToTheoDong[i] > soNguyenToMax) {
            soNguyenToMax = soNguyenToTheoDong[i];
        }
    }
    
    printf("Cac dong co so luong so nguyen to nhieu nhat la %d so:\n", soNguyenToMax);
    for (i = 0; i < soDong; ++i) {
        if (soNguyenToTheoDong[i] == soNguyenToMax) {
            printf("Dong %d\n", i);
        }
    }
}

// Ham kiem tra so chan
bool laSoChan(int n) {
    return n % 2 == 0;
}

// Ham liet ke cac dong chua toan so chan
void lietKeDongToanSoChan(int **maTran, int soDong, int soCot) {
    int i, j;  
    bool toanSoChan;
    
    printf("Cac dong chua toan so chan:\n");
    for (i = 0; i < soDong; ++i) {
        toanSoChan = true;
        for (j = 0; j < soCot; ++j) {
            if (!laSoChan(maTran[i][j])) {
                toanSoChan = false;
                break;
            }
        }
        if (toanSoChan) {
        	printf("Dong %d: ", i);
           // In ra gia tri chan cua dong do
            for (j = 0; j < soCot; ++j) {
                printf("%d ", maTran[i][j]);
            }
            printf("\n");
        }
    }
    if(!toanSoChan){
    	 printf("Khong co dong nao chua toan so chan\n");
    }
}

// Ham tim gia tri xuat hien nhieu nhat trong ma tran
void timGiaTriXuatHienNhieuNhat(int **maTran, int soDong, int soCot) {
    int i, j;  
    int maxCount = 0;
    int maxValue = 0;
    
    // Gia tri toi da co the la so phan tu cua ma tran
    int *demGiaTri = (int *)malloc(10 * sizeof(int));  // Gia su cac gia tri <= 1000
    
    // Khoi tao dem gia tri
    for (i = 0; i < 10; ++i) {
        demGiaTri[i] = 0;
    }
    
    // Dem so lan xuat hien cua moi gia tri
    for (i = 0; i < soDong; ++i) {
        for (j = 0; j < soCot; ++j) {
            int giaTri = maTran[i][j];
            if (giaTri >= 0 && giaTri < 10) {  // Gioi han gia tri
                demGiaTri[giaTri]++;
                if (demGiaTri[giaTri] > maxCount) {
                    maxCount = demGiaTri[giaTri];
                    maxValue = giaTri;
                }
            }
        }
    }
    
    printf("Gia tri xuat hien nhieu nhat: %d, xuat hien %d lan\n", maxValue, maxCount);
    
    free(demGiaTri);
}

// Ham tim so nguyen to nho nhat trong ma tran
void timSoNguyenToNhoNhat(int **maTran, int soDong, int soCot) {
    int i, j;  
    int soNguyenToNhoNhat = -1; // -1 de danh dau chua tim thay so nguyen to
    
    // Duyet qua ma tran
    for (i = 0; i < soDong; ++i) {
        for (j = 0; j < soCot; ++j) {
            if (laSoNguyenTo(maTran[i][j])) {
                if (soNguyenToNhoNhat == -1 || maTran[i][j] < soNguyenToNhoNhat) {
                    soNguyenToNhoNhat = maTran[i][j];
                }
            }
        }
    }
    
    if (soNguyenToNhoNhat != -1) {
        printf("So nguyen to nho nhat trong ma tran: %d\n", soNguyenToNhoNhat);
    } else {
        printf("Khong co so nguyen to trong ma tran.\n");
    }
}

// Ham tim phan tu lon nhat va nho nhat trong dong thu k
void timPhanTuLonNhatNhoNhatTrongDongK(int **maTran, int soCot, int k) {
    int j;  
    int phanTuLonNhat = maTran[k][0];
    int phanTuNhoNhat = maTran[k][0];
    
    for (j = 1; j < soCot; ++j) {
        if (maTran[k][j] > phanTuLonNhat) {
            phanTuLonNhat = maTran[k][j];
        }
        if (maTran[k][j] < phanTuNhoNhat) {
            phanTuNhoNhat = maTran[k][j];
        }
    }
    
    printf("Dong %d: Phan tu lon nhat: %d\n", k, phanTuLonNhat);
    printf("Dong %d: Phan tu nho nhat: %d\n", k, phanTuNhoNhat);
}

// Ham tim phan tu lon nhat va nho nhat trong cot thu k
void timPhanTuLonNhatNhoNhatTrongCotK(int **maTran, int soDong, int k) {
    int i;  // Khai bao i o ngoai for
    int phanTuLonNhat = maTran[0][k];
    int phanTuNhoNhat = maTran[0][k];
    
    for (i = 1; i < soDong; ++i) {
        if (maTran[i][k] > phanTuLonNhat) {
            phanTuLonNhat = maTran[i][k];
        }
        if (maTran[i][k] < phanTuNhoNhat) {
            phanTuNhoNhat = maTran[i][k];
        }
    }
    
    printf("Cot %d: Phan tu lon nhat: %d\n", k, phanTuLonNhat);
    printf("Cot %d: Phan tu nho nhat: %d\n", k, phanTuNhoNhat);
}
int main(){
	int soDong, soCot, i;
	int chucNang;
    
    printf("Nhap so dong: ");
    scanf("%d", &soDong);
    printf("Nhap so cot: ");
    scanf("%d", &soCot);
    
    // Cap phat bo nho cho ma tran
    int **maTran = (int **)malloc(soDong * sizeof(int *));
    for (i = 0; i < soDong; ++i) {
        maTran[i] = (int *)malloc(soCot * sizeof(int));
    }
   
    int *tongCot = (int *)malloc(soCot * sizeof(int));
    
    // Mang luu so luong so nguyen to trong tung dong
    int *soNguyenToTheoDong = (int *)malloc(soDong * sizeof(int));
    
   do {
        printf("\n--- MENU ---\n");
        printf("1. Nhap ma tran\n");
        printf("2. Xuat ma tran\n");
        printf("3. Liet ke cac cot co tong nho nhat\n");
        printf("4. Liet ke cac dong co so luong so nguyen to nhieu nhat\n");
        printf("5. Liet ke cac dong chua toan so chan\n");
        printf("6. Tim gia tri xuat hien nhieu nhat\n");
        printf("7. Tim so nguyen to nho nhat\n");
        printf("8. Tim phan tu lon nhat va nho nhat trong dong thu k\n");
        printf("9. Tim phan tu lon nhat va nho nhat trong cot thu k\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &chucNang);
        switch (chucNang) {
            case 1:
                nhapMaTran(maTran, soDong, soCot);
                break;
            case 2:
                inMaTran(maTran, soDong, soCot);
                break;
            case 3:
                tinhTongCot(maTran, soDong, soCot, tongCot);
                lietKeCotTongNhoNhat(tongCot, soCot);
                break;
            case 4:
                tinhSoNguyenToTheoDong(maTran, soDong, soCot, soNguyenToTheoDong);
                lietKeDongSoNguyenToNhieuNhat(soNguyenToTheoDong, soDong);
                break;
            case 5:
                lietKeDongToanSoChan(maTran, soDong, soCot);
                break;
            case 6:
                timGiaTriXuatHienNhieuNhat(maTran, soDong, soCot);
                break;
            case 7:
                timSoNguyenToNhoNhat(maTran, soDong, soCot);
                break;
            case 8:
                {
                    int k;
                    printf("Nhap chi so dong k: ");
                    scanf("%d", &k);
                    if (k >= 0 && k < soDong) {
                        timPhanTuLonNhatNhoNhatTrongDongK(maTran, soCot, k);
                    } else {
                        printf("Chi so dong k khong hop le.\n");
                    }
                }
                break;
            case 9:
                {
                    int k;
                    printf("Nhap chi so cot k: ");
                    scanf("%d", &k);
                    if (k >= 0 && k < soCot) {
                        timPhanTuLonNhatNhoNhatTrongCotK(maTran, soDong, k);
                    } else {
                        printf("Chi so cot k khong hop le.\n");
                    }
                }
                break;
            case 0:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (chucNang != 0);
    
     // Giai phong bo nho
    for (i = 0; i < soDong; ++i) {
        free(maTran[i]);
    }
    free(maTran);
    free(tongCot);
    
    return 0;

}


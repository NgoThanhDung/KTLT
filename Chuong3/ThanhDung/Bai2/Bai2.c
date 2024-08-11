#include <stdio.h>
#include <string.h>

// Ham dem so luong dau cach trong chuoi
int demKhoangTrang(const char *chuoi) {
    int soLuong = 0;
    int doDai = strlen(chuoi);
	int i;
    // Duyet qua tung ky tu trong chuoi
    for (i = 0; i < doDai; i++) {
        // Kiem tra neu ky tu la dau cach
        if (chuoi[i] == ' ') {
            soLuong++;
        }
    }
    return soLuong;
}

int main() {
    // Khai bao chuoi can kiem tra
    char vanBan[] = "This is a test string with some spaces.";

    // Goi ham va in ket qua
    int ketQua = demKhoangTrang(vanBan);
    printf("So luong dau cach trong chuoi: %d\n", ketQua);

    return 0;
}


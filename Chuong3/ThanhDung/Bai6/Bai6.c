#include <stdio.h>
#include <string.h>

// Ham cat chuoi ho ten thanh chuoi ho lot va chuoi ten
void tachHoTen(const char *hoTenDayDu, char *hoLot, char *ten) {
    // Tim vi tri cua khoang trang cuoi cung
    char *khoangTrangCuoi = strrchr(hoTenDayDu, ' ');

    if (khoangTrangCuoi != NULL) {
        // Tao chuoi ho lot
        size_t doDaiHoLot = khoangTrangCuoi - hoTenDayDu;
        strncpy(hoLot, hoTenDayDu, doDaiHoLot);
        hoLot[doDaiHoLot] = '\0';

        // Tao chuoi ten
        strcpy(ten, khoangTrangCuoi + 1);
    } else {
        // Neu khong co khoang trang, toan bo chuoi la ten
        strcpy(ten, hoTenDayDu);
        hoLot[0] = '\0'; // Ho lot la rong
    }
}

int main() {
    char hoTenDayDu[100];
    char hoLot[100];
    char ten[50];

    // Nhap chuoi ho ten tu nguoi dung
    printf("Nhap vao ho ten: ");
    fgets(hoTenDayDu, sizeof(hoTenDayDu), stdin);

    // Xoa ky tu xuong dong (neu co) o cuoi chuoi do fgets them vao
    size_t doDai = strlen(hoTenDayDu);
    if (doDai > 0 && hoTenDayDu[doDai - 1] == '\n') {
        hoTenDayDu[doDai - 1] = '\0';
    }

    // Cat chuoi ho ten thanh chuoi ho lot va chuoi ten
    tachHoTen(hoTenDayDu, hoLot, ten);

    // In ket qua
    printf("Chuoi ho lot: '%s'\n", hoLot);
    printf("Chuoi ten: '%s'\n", ten);

    return 0;
}


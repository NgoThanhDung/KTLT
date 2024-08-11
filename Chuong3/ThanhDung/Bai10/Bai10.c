#include <stdio.h>
#include <string.h>

#define MAX_CHARS 256 // Kich thuoc mang dem cho tat ca ky tu ASCII

// Ham tim ky tu xuat hien nhieu nhat
char timKyTuXuatHienNhieuNhat(const char *str, int *soLanXuatHienNhieuNhat) {
    int dem[MAX_CHARS] = {0}; // Mang dem so lan xuat hien cua moi ky tu
    int i;
    char kyTuXuatHienNhieuNhat = '\0';
    *soLanXuatHienNhieuNhat = 0;

    // Dem so lan xuat hien cua moi ky tu
    for (i = 0; str[i] != '\0'; i++) {
        dem[(unsigned char)str[i]]++;
    }

    // Tim ky tu xuat hien nhieu nhat
    for (i = 0; i < MAX_CHARS; i++) {
        if (dem[i] > *soLanXuatHienNhieuNhat) {
            *soLanXuatHienNhieuNhat = dem[i];
            kyTuXuatHienNhieuNhat = i;
        }
    }

    return kyTuXuatHienNhieuNhat;
}

int main() {
    char str[1000];
    int soLanXuatHienNhieuNhat;
    char kyTuXuatHienNhieuNhat;

    // Nhap chuoi tu nguoi dung
    printf("Nhap vao chuoi: ");
    fgets(str, sizeof(str), stdin);
    // Xoa ky tu xuong dong (neu co) o cuoi chuoi do fgets them vao
    size_t doDai = strlen(str);
    if (doDai > 0 && str[doDai - 1] == '\n') {
        str[doDai - 1] = '\0';
    }

    // Tim ky tu xuat hien nhieu nhat
    kyTuXuatHienNhieuNhat = timKyTuXuatHienNhieuNhat(str, &soLanXuatHienNhieuNhat);

    // In ket qua
    printf("Ky tu xuat hien nhieu nhat: '%c' (xuat hien %d lan)\n", kyTuXuatHienNhieuNhat, soLanXuatHienNhieuNhat);

    return 0;
}


#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Ham xoa mot tu khoi chuoi va loai bo khoang trang du thua
void xoaTu(char *vanBan, const char *tu) {
    char *viTri;
    size_t doDaiTu = strlen(tu);

    while ((viTri = strstr(vanBan, tu)) != NULL) {
        // Xoa tu bang cach di chuyen phan sau tu
        memmove(viTri, viTri + doDaiTu, strlen(viTri + doDaiTu) + 1);
        
        // Xoa khoang trang du thua o dau va cuoi chuoi
        char *batDau = vanBan;
        char *ketThuc = vanBan + strlen(vanBan) - 1;

        // Xoa khoang trang o dau chuoi
        while (*batDau == ' ') batDau++;
        
        // Xoa khoang trang o cuoi chuoi
        while (ketThuc > batDau && *ketThuc == ' ') ketThuc--;
        
        *(ketThuc + 1) = '\0'; // Ket thuc chuoi
        
        // Di chuyen phan con lai ve dau chuoi
        memmove(vanBan, batDau, strlen(batDau) + 1);
    }
}

int main() {
    char vanBan[100];
    char tu[50];

    // Nhap chuoi van ban tu nguoi dung
    printf("Nhap vao chuoi: ");
    fgets(vanBan, sizeof(vanBan), stdin);
    // Xoa ky tu xuong dong (neu co) o cuoi chuoi do fgets them vao
    size_t doDai = strlen(vanBan);
    if (doDai > 0 && vanBan[doDai - 1] == '\n') {
        vanBan[doDai - 1] = '\0';
    }

    // Nhap tu can xoa
    printf("Nhap vao tu can xoa: ");
    fgets(tu, sizeof(tu), stdin);
    // Xoa ky tu xuong dong (neu co) o cuoi chuoi do fgets them vao
    doDai = strlen(tu);
    if (doDai > 0 && tu[doDai - 1] == '\n') {
        tu[doDai - 1] = '\0';
    }

    // Xoa tu khoi chuoi van ban
    xoaTu(vanBan, tu);

    // In ket qua
    printf("Chuoi sau khi xoa: '%s'\n", vanBan);

    return 0;
}


#include <stdio.h>
#include <ctype.h>  // Thu vien cho ham tolower() va toupper()
#include <string.h> // Thu vien cho ham strlen()

void vietHoaChuCaiDau(char *str) {
    int length = strlen(str);
    int laTuMoi = 1;  // Danh dau xem co phai la tu moi hay khong
	int i;
    for (i = 0; i < length; i++) {
        if (isspace(str[i])) {  // Neu la khoang trang
            laTuMoi = 1;        // Danh dau tu moi se bat dau sau khoang trang
        } else {
            if (laTuMoi) {
                str[i] = toupper(str[i]);  // Doi ky tu dau tien thanh chu in hoa
                laTuMoi = 0;               // Reset co tu moi
            } else {
                str[i] = tolower(str[i]);  // Doi cac ky tu con lai thanh chu thuong
            }
        }
    }
}

int main() {
    char str[] = "Ngo THaNh DunG";
    printf("Chuoi ban dau: %s\n", str);
    
    vietHoaChuCaiDau(str);

    printf("Chuoi sau khi doi: %s\n", str);

    return 0;
}


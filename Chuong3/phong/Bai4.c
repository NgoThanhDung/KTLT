#include <stdio.h>
#include <ctype.h>  // Thư viện cho hàm tolower() và toupper()
#include <string.h> // Thư viện cho hàm strlen()

void capitalizeWords(char *str) {
    int length = strlen(str);
    int isNewWord = 1;  // Đánh dấu xem có phải là từ mới hay không

    for (int i = 0; i < length; i++) {
        if (isspace(str[i])) {  // Nếu là khoảng trắng
            isNewWord = 1;      // Đánh dấu từ mới sẽ bắt đầu sau khoảng trắng
        } else {
            if (isNewWord) {
                str[i] = toupper(str[i]);  // Đổi ký tự đầu tiên thành chữ in hoa
                isNewWord = 0;             // Reset cờ từ mới
            } else {
                str[i] = tolower(str[i]);  // Đổi các ký tự còn lại thành chữ thường
            }
        }
    }
}

int main() {
    char str[] = "hOa hOng, nHo Nhat la Ngay duoc ben em.";
    printf("Chuoi ban dau: %s\n", str);
    
    capitalizeWords(str);

    printf("Chuoi sau khi doi: %s\n", str);

    return 0;
}

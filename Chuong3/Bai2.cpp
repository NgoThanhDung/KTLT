#include <stdio.h>
#include <string.h>

// Hàm đếm số lượng khoảng trắng trong chuỗi
int countSpaces(const char *str) {
    int count = 0;
    int length = strlen(str);

    // Duyệt qua từng ký tự trong chuỗi
    for (int i = 0; i < length; i++) {
        // Kiểm tra nếu ký tự là khoảng trắng
        if (str[i] == ' ') {
            count++;
        }
    }
    return count;
}

int main() {
    // Khai báo chuỗi cần kiểm tra
    char input[] = "This is a test string with some spaces.";

    // Gọi hàm và in kết quả
    int numberOfSpaces = countSpaces(input);
    printf("So luong khoang trang trong chuoi: %d\n", numberOfSpaces);

    return 0;
}

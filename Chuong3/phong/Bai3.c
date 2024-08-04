#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Hàm xóa khoảng trắng thừa trong chuỗi
void removeExtraSpaces(char *str) {
    int length = strlen(str);
    char result[length + 1]; // Tạo một chuỗi kết quả
    int index = 0; // Chỉ số cho chuỗi kết quả

    // Bỏ qua các khoảng trắng ở đầu chuỗi
    int start = 0;
    while (str[start] == ' ') {
        start++;
    }

    // Duyệt qua từng ký tự trong chuỗi
    for (int i = start; i < length; i++) {
        // Nếu ký tự không phải là khoảng trắng, thêm vào chuỗi kết quả
        if (str[i] != ' ') {
            result[index++] = str[i];
        }
        // Nếu ký tự là khoảng trắng và ký tự trước đó không phải là khoảng trắng
        else if (i > 0 && str[i - 1] != ' ') {
            result[index++] = ' ';
        }
    }

    // Loại bỏ khoảng trắng cuối chuỗi
    if (index > 0 && result[index - 1] == ' ') {
        index--;
    }

    // Thêm ký tự kết thúc chuỗi
    result[index] = '\0';

    // Sao chép kết quả vào chuỗi gốc
    strcpy(str, result);
}

int main() {
    char input[100];

    // Nhập chuỗi từ người dùng
    printf("Nhap vao mot chuoi: ");
    fgets(input, sizeof(input), stdin);

    // Xóa ký tự xuống dòng (nếu có) ở cuối chuỗi do fgets thêm vào
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    // Gọi hàm xóa khoảng trắng thừa
    removeExtraSpaces(input);

    // In chuỗi sau khi xóa khoảng trắng thừa
    printf("Chuoi sau khi xoa khoang trang thua: '%s'\n", input);

    return 0;
}

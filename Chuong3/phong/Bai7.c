#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1000

// Hàm chèn một từ vào chuỗi văn bản tại vị trí chỉ định
void insertWord(char *text, const char *word, int position) {
    int textLength = strlen(text);
    int wordLength = strlen(word);

    // Kiểm tra vị trí chèn hợp lệ
    if (position < 0 || position > textLength) {
        printf("Vi tri chen khong hop le.\n");
        return;
    }

    // Tạo mảng tạm để chứa chuỗi kết quả
    char temp[MAX_SIZE];

    // Sao chép phần chuỗi trước vị trí chèn
    strncpy(temp, text, position);
    temp[position] = '\0'; // Đặt ký tự kết thúc chuỗi

    // Nối từ vào phần chuỗi trước vị trí chèn
    strcat(temp, word);

    // Nối phần chuỗi sau vị trí chèn
    strcat(temp, text + position);

    // Sao chép chuỗi kết quả trở lại vào biến gốc
    strcpy(text, temp);
}

int main() {
    char text[MAX_SIZE];
    char word[MAX_SIZE];
    int position;

    // Nhập chuỗi văn bản từ người dùng
    printf("Nhap vao chuoi van ban: ");
    fgets(text, sizeof(text), stdin);
    // Xóa ký tự xuống dòng (nếu có) ở cuối chuỗi do fgets thêm vào
    size_t len = strlen(text);
    if (len > 0 && text[len - 1] == '\n') {
        text[len - 1] = '\0';
    }

    // Nhập từ cần chèn
    printf("Nhap vao tu can chen: ");
    fgets(word, sizeof(word), stdin);
    // Xóa ký tự xuống dòng (nếu có) ở cuối chuỗi do fgets thêm vào
    len = strlen(word);
    if (len > 0 && word[len - 1] == '\n') {
        word[len - 1] = '\0';
    }

    // Nhập vị trí chèn
    printf("Nhap vao vi tri chen: ");
    scanf("%d", &position);

    // Chèn từ vào chuỗi văn bản tại vị trí chỉ định
    insertWord(text, word, position);

    // In kết quả
    printf("Chuoi sau khi chen: %s\n", text);

    return 0;
}

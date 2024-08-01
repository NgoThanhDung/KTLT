#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Hàm xóa một từ khỏi chuỗi và loại bỏ khoảng trắng dư thừa
void removeWord(char *text, const char *word) {
    char *pos;
    size_t wordLen = strlen(word);

    while ((pos = strstr(text, word)) != NULL) {
        // Xóa từ bằng cách di chuyển phần sau từ
        memmove(pos, pos + wordLen, strlen(pos + wordLen) + 1);
        
        // Xóa khoảng trắng dư thừa ở đầu và cuối chuỗi
        char *start = text;
        char *end = text + strlen(text) - 1;

        // Xóa khoảng trắng ở đầu chuỗi
        while (*start == ' ') start++;
        
        // Xóa khoảng trắng ở cuối chuỗi
        while (end > start && *end == ' ') end--;
        
        *(end + 1) = '\0'; // Kết thúc chuỗi
        
        // Di chuyển phần còn lại về đầu chuỗi
        memmove(text, start, strlen(start) + 1);
    }
}

int main() {
    char text[100];
    char word[50];

    // Nhập chuỗi văn bản từ người dùng
    printf("Nhap vao chuoi: ");
    fgets(text, sizeof(text), stdin);
    // Xóa ký tự xuống dòng (nếu có) ở cuối chuỗi do fgets thêm vào
    size_t len = strlen(text);
    if (len > 0 && text[len - 1] == '\n') {
        text[len - 1] = '\0';
    }

    // Nhập từ cần xóa
    printf("Nhap vao tu can xoa: ");
    fgets(word, sizeof(word), stdin);
    // Xóa ký tự xuống dòng (nếu có) ở cuối chuỗi do fgets thêm vào
    len = strlen(word);
    if (len > 0 && word[len - 1] == '\n') {
        word[len - 1] = '\0';
    }

    // Xóa từ khỏi chuỗi văn bản
    removeWord(text, word);

    // In kết quả
    printf("Chuoi sau khi xoa: '%s'\n", text);

    return 0;
}

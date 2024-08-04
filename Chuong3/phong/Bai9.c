#include <stdio.h>
#include <string.h>

#define MAX_CHARS 256 // Kích thước mảng đếm cho tất cả ký tự ASCII

// Hàm liệt kê số lần xuất hiện của mỗi ký tự trong chuỗi
void countCharacters(const char *str) {
    int count[MAX_CHARS] = {0}; // Mảng đếm số lần xuất hiện của mỗi ký tự
    int i;
    
    // Đếm số lần xuất hiện của mỗi ký tự
    for (i = 0; str[i] != '\0'; i++) {
        count[(unsigned char)str[i]]++;
    }
    
    // In kết quả
    printf("So lan xuat hien cua moi ky tu:\n");
    for (i = 0; i < MAX_CHARS; i++) {
        if (count[i] > 0) {
            printf("'%c': %d\n", i, count[i]);
        }
    }
}

int main() {
    char str[1000];

    // Nhập chuỗi từ người dùng
    printf("Nhap vao chuoi: ");
    fgets(str, sizeof(str), stdin);
    // Xóa ký tự xuống dòng (nếu có) ở cuối chuỗi do fgets thêm vào
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    // Liệt kê số lần xuất hiện của mỗi ký tự trong chuỗi
    countCharacters(str);

    return 0;
}

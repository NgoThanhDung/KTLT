#include <stdio.h>
#include <string.h>

int main() {
    // Khai báo và khởi tạo chuỗi
    char s1[20] = "Truong DHCT", s2[10] = "Tp.HCM", input[30], s3[10];

    // Sao chép chuỗi s1 vào input
    strcpy(input, s1);

    // Khởi tạo chuỗi s3 chứa các nguyên âm
    strcpy(s3, "aeiou");

    // Nối chuỗi s2 vào cuối chuỗi input
    strcat(input, s2);

    // Tính độ dài chuỗi input và khởi tạo biến đếm nguyên âm
    int n = strlen(input), k = 0;

    // In ra chuỗi kết quả sau khi nối
    printf("Chuoi: %s", input);

    // Duyệt qua từng ký tự trong chuỗi input
    for (int i = 0; i < n; i++) {
        // Kiểm tra nếu ký tự là nguyên âm
        if (strchr(s3, input[i])) {
            k++;
        }
    }

    // In ra kết quả đếm số nguyên âm
    printf("\nKet qua: %d", k);

    return 0;
}

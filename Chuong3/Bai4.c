#include <stdio.h>
#include <string.h>

// Hàm cắt chuỗi họ tên thành chuỗi họ lót và chuỗi tên
void splitFullName(const char *fullName, char *lastName, char *firstName) {
    // Tìm vị trí của khoảng trắng cuối cùng
    char *lastSpace = strrchr(fullName, ' ');

    if (lastSpace != NULL) {
        // Tạo chuỗi họ lót
        size_t lastNameLength = lastSpace - fullName;
        strncpy(lastName, fullName, lastNameLength);
        lastName[lastNameLength] = '\0';

        // Tạo chuỗi tên
        strcpy(firstName, lastSpace + 1);
    } else {
        // Nếu không có khoảng trắng, toàn bộ chuỗi là tên
        strcpy(firstName, fullName);
        lastName[0] = '\0'; // Họ lót là rỗng
    }
}

int main() {
    char fullName[100];
    char lastName[100];
    char firstName[50];

    // Nhập chuỗi họ tên từ người dùng
    printf("Nhap vao ho ten: ");
    fgets(fullName, sizeof(fullName), stdin);

    // Xóa ký tự xuống dòng (nếu có) ở cuối chuỗi do fgets thêm vào
    size_t len = strlen(fullName);
    if (len > 0 && fullName[len - 1] == '\n') {
        fullName[len - 1] = '\0';
    }

    // Cắt chuỗi họ tên thành chuỗi họ lót và chuỗi tên
    splitFullName(fullName, lastName, firstName);

    // In kết quả
    printf("Chuoi ho lot: '%s'\n", lastName);
    printf("Chuoi ten: '%s'\n", firstName);

    return 0;
}

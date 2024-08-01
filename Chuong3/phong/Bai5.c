#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Hàm chuyển đổi chuỗi thành chữ thường
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Hàm tìm kiếm tên trong chuỗi họ tên (không phân biệt chữ hoa, chữ thường)
int searchName(const char *fullName, const char *name) {
    char lowerFullName[100];
    char lowerName[50];

    // Sao chép và chuyển đổi chuỗi họ tên và tên cần tìm thành chữ thường
    strcpy(lowerFullName, fullName);
    strcpy(lowerName, name);
    toLowerCase(lowerFullName);
    toLowerCase(lowerName);

    // Sử dụng hàm strstr để tìm tên trong chuỗi họ tên
    char *position = strstr(lowerFullName, lowerName);

    // Kiểm tra nếu tìm thấy và ký tự liền trước hoặc sau nó không phải chữ cái
    while (position != NULL) {
        // Kiểm tra xem tên có phải là một từ riêng biệt không
        if ((position == lowerFullName || !isalpha(*(position - 1))) &&
            (*(position + strlen(lowerName)) == '\0' || !isalpha(*(position + strlen(lowerName))))) {
            return 1; // Tìm thấy tên
        }

        // Tìm vị trí tiếp theo của tên trong chuỗi
        position = strstr(position + 1, lowerName);
    }

    return 0; // Không tìm thấy tên
}

int main() {
    char fullName[100];
    char name[50];

    // Nhập chuỗi họ tên từ người dùng
    printf("Nhap vao ho ten: ");
    fgets(fullName, sizeof(fullName), stdin);

    // Xóa ký tự xuống dòng (nếu có) ở cuối chuỗi do fgets thêm vào
    size_t len = strlen(fullName);
    if (len > 0 && fullName[len - 1] == '\n') {
        fullName[len - 1] = '\0';
    }

    // Nhập tên cần tìm kiếm
    printf("Nhap vao ten can tim: ");
    fgets(name, sizeof(name), stdin);

    // Xóa ký tự xuống dòng (nếu có) ở cuối chuỗi do fgets thêm vào
    len = strlen(name);
    if (len > 0 && name[len - 1] == '\n') {
        name[len - 1] = '\0';
    }

    // Tìm kiếm tên trong chuỗi họ tên
    if (searchName(fullName, name)) {
        printf("Ten '%s' da nhap dung trong ho ten.\n", name);
    } else {
        printf("Ten '%s' da nhap sai trong ho ten.\n", name);
    }

    return 0;
}

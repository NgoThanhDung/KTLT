#include <stdio.h>
#include <string.h>

#define MAX_CHARS 256 // Kích thước mảng đếm cho tất cả ký tự ASCII

// Hàm tìm ký tự xuất hiện nhiều nhất
char findMostFrequentChar(const char *str, int *maxCount) {
	int count[MAX_CHARS] = {0}; // Mảng đếm số lần xuất hiện của mỗi ký tự
	int i;
	char mostFrequentChar = '\0';
	*maxCount = 0;

	// Đếm số lần xuất hiện của mỗi ký tự
	for (i = 0; str[i] != '\0'; i++) {
		count[(unsigned char)str[i]]++;
	}

	// Tìm ký tự xuất hiện nhiều nhất
	for (i = 0; i < MAX_CHARS; i++) {
		if (count[i] > *maxCount) {
			*maxCount = count[i];
			mostFrequentChar = i;
		}
	}

	return mostFrequentChar;
}

int main() {
	char str[1000];
	int maxCount;
	char mostFrequentChar;

	// Nhập chuỗi từ người dùng
	printf("Nhap vao chuoi: ");
	fgets(str, sizeof(str), stdin);
	// Xóa ký tự xuống dòng (nếu có) ở cuối chuỗi do fgets thêm vào
	size_t len = strlen(str);
	if (len > 0 && str[len - 1] == '\n') {
		str[len - 1] = '\0';
	}

	// Tìm ký tự xuất hiện nhiều nhất
	mostFrequentChar = findMostFrequentChar(str, &maxCount);

	// In kết quả
	printf("Ky tu xuat hien nhieu nhat: '%c' (xuat hien %d lan)\n", mostFrequentChar, maxCount);

	return 0;
}

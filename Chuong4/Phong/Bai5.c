#include <stdio.h>

// Hàm đệ quy tính phần tử thứ n của cấp số nhân
int capSoNhan(int a, int q, int n) {
    if (n == 1)
        return a; // Phần tử đầu tiên là a
    return q * capSoNhan(a, q, n - 1); // Gọi đệ quy cho n-1 và nhân với q
}

int main() {
    int a, q, n;
    printf("Nhap so hang dau a, cong boi q va so thu tu n: ");
    scanf("%d %d %d", &a, &q, &n);
    printf("Phan tu thu %d cua cap so nhan la: %d\n", n, capSoNhan(a, q, n));
    return 0;
}

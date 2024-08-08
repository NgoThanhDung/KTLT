#include <stdio.h>

int tinhYn_dequy(int n) {
    // Điều kiện dừng
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (n == 3) return 3;

    // Công thức truy hồi
    return tinhYn_dequy(n-1) + 2*tinhYn_dequy(n-2) + 3*tinhYn_dequy(n-3);
}

int main() {
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    printf("Yn = %d\n", tinhYn_dequy(n));
    return 0;
}

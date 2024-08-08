#include <stdio.h>

// Hàm đệ quy tính dãy A_n theo công thức 1
int An_1(int n) {
    if (n == 0) return 1;
    if (n == 1) return 0;
    if (n == 2) return -1;
    return 2 * An_1(n-1) - 3 * An_1(n-2) - An_1(n-3); // Gọi đệ quy theo công thức
}

int main() {
    int n;
    printf("Nhap gia tri n: ");
    scanf("%d", &n);
    printf("Gia tri cua A_%d theo cong thuc 1 la: %d\n", n, An_1(n));
    return 0;
}

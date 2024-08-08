#include <stdio.h>

// Hàm đệ quy tính UCLN
int UCLN(int a, int b) {
    if (b == 0)
        return a; // Nếu b = 0, UCLN là a
    return UCLN(b, a % b); // Gọi đệ quy với b và a % b
}

int main() {
    int a, b;
    printf("Nhap hai so nguyen duong a va b: ");
    scanf("%d %d", &a, &b);
    printf("UCLN cua %d va %d la: %d\n", a, b, UCLN(a, b));
    return 0;
}

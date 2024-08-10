#include <stdio.h>

int tinhXn(int n) {
    if (n == 0) {
        return 1;
    } else {
        return tinhXn(n-1) + tinhYn(n-1);
    }
}

int tinhYn(int n) {
    if (n == 0) {
        return 0;
    } else {
        return 3 * tinhXn(n-1) + 2 * tinhYn(n-1);
    }
}

int main() {
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    printf("Xn = %d\n", tinhXn(n));
    printf("Yn = %d\n", tinhYn(n));
    return 0;
}

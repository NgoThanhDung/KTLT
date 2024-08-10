#include <stdio.h>

int findUn(int a, int r, int n) {
    if (n == 1)
        return a;
    return findUn(a, r, n - 1) + r;
}

int main() {
    int a, r, n;
    printf("Nhap a, r va n: ");
    scanf("%d %d %d", &a, &r, &n);
    printf("U%d = %d\n", n, findUn(a, r, n));
    return 0;
}


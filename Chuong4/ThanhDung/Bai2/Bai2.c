#include <stdio.h>

int power(int m, int n) {
    if (n == 0)
        return 1;
    return m * power(m, n - 1);
}

int main() {
    int m, n;
    printf("Nhap m va n: ");
    scanf("%d %d", &m, &n);
    printf("%d^%d = %d\n", m, n, power(m, n));
    return 0;
}


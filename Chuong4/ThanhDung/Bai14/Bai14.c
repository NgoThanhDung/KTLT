#include <stdio.h>

int An(int n) {
    if (n == 1)
        return 1;
    return n * (An(n - 1) + 1);
}

int main() {
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    printf("A_%d = %d\n", n, An(n));
    return 0;
}


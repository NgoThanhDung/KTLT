#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int findMaxFib(int n) {
    int i = 0;
    while (fibonacci(i) < n)
        i++;
    return fibonacci(i - 1);
}

int main() {
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    printf("So Fibonacci lon nhat nho hon %d la %d\n", n, findMaxFib(n));
    return 0;
}


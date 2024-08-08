#include <stdio.h>

// Hàm đệ quy tính Fibonacci
int Fibonacci(int n) {
    if (n <= 2)
        return 1; // Nếu n <= 2, giá trị là 1
    return Fibonacci(n-1) + Fibonacci(n-2); // Gọi đệ quy cho F(n-1) và F(n-2)
}

int main() {
    int n;
    printf("Nhap so n: ");
    scanf("%d", &n);

    printf("Day Fibonacci co %d so: ", n);
    for (int i = 1; i <= n; i++) {
        printf("%d ", Fibonacci(i)); // In từng số Fibonacci
    }
    printf("\n");
    return 0;
}

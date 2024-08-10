#include <stdio.h>

// Cach 1
int Xn_recursive(int n) {
    if (n == 1 || n == 2)
        return 1;
    return (n - 1) * Xn_recursive(n - 1) + Xn_recursive(n - 2);
}

// Cach 2
int Xn_iterative(int n) {
	int i;
    if (n == 1 || n == 2)
        return 1;
    int prev2 = 1, prev1 = 1, curr;
    for (i = 3; i <= n; i++) {
        curr = (i - 1) * prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}

int main() {
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);

    // Tinh Xn bang de quy
    printf("X_%d (De quy) = %d\n", n, Xn_recursive(n));

    // Tinh Xn bang khu de quy
    printf("X_%d (Khong de quy) = %d\n", n, Xn_iterative(n));

    return 0;
}


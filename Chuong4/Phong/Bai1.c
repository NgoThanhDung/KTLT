#include <stdio.h>
#include <math.h>

int sum1(int n) {
    if (n == 1) return 1;
    return sum1(n - 1) + n;
}

int sum1_iterative(int n) {
    return n * (n + 1) / 2;
}

double sum2(int n) {
    if (n == 1) return sqrt(2);
    return sqrt(2 + sum2(n - 1));
}

double sum2_iterative(int n) {
    double result = 0;
    for (int i = 0; i < n; i++) {
        result = sqrt(2 + result);
    }
    return result;
}

double sum3(int n) {
    if (n == 1) return 0.5;
    return sum3(n - 1) + (double)n / (n + 1);
}

double sum3_iterative(int n) {
    double result = 0;
    for (int i = 1; i <= n; i++) {
        result += (double)i / (i + 1);
    }
    return result;
}

double sum4(int n) {
    if (n == 0) return 1.0;
    return sum4(n - 1) + 1.0 / (2 * n + 1);
}

double sum4_iterative(int n) {
    double result = 0;
    for (int i = 0; i <= n; i++) {
        result += 1.0 / (2 * i + 1);
    }
    return result;
}

int sum5(int n) {
    if (n == 1) return 1 * 2;
    return sum5(n - 1) + n * (n + 1);
}

int sum5_iterative(int n) {
    int result = 0;
    for (int i = 1; i <= n; i++) {
        result += i * (i + 1);
    }
    return result;
}

double sum6(int n) {
    if (n == 1) return 1.0 / (1 * 2 * 3);
    return sum6(n - 1) + 1.0 / (n * (n + 1) * (n + 2));
}

double sum6_iterative(int n) {
    double result = 0;
    for (int i = 1; i <= n; i++) {
        result += 1.0 / (i * (i + 1) * (i + 2));
    }
    return result;
}

int sum7(int n) {
    if (n == 1) return 1;
    return sum7(n - 1) + n * n;
}

int sum7_iterative(int n) {
    int result = 0;
    for (int i = 1; i <= n; i++) {
        result += i * i;
    }
    return result;
}

int sum8(int n) {
    if (n == 1) return 1;
    return sum8(n - 1) + n * (n + 1) / 2;
}

int sum8_iterative(int n) {
    int result = 0;
    for (int i = 1; i <= n; i++) {
        result += i * (i + 1) / 2;
    }
    return result;
}

double sum9(int n) {
    if (n == 1) return -(1 + 2) / 2.0;
    int term = (2 * n - 1) + (2 * n);
    int factorial = 1;
    for (int i = 1; i <= 2 * n; i++) factorial *= i;
    return sum9(n - 1) + pow(-1, n) * (double)term / factorial;
}

double sum9_iterative(int n) {
    double result = 0;
    int factorial = 1;
    for (int i = 1; i <= n; i++) {
        int term = (2 * i - 1) + (2 * i);
        factorial *= (2 * i - 1) * (2 * i);
        result += pow(-1, i) * (double)term / factorial;
    }
    return result;
}

double sum10(int n) {
    if (n == 1) return 1.0 * 2 / (2 + sqrt(3));
    int factorial = 1;
    for (int i = 1; i <= n + 1; i++) factorial *= i;
    return sum10(n - 1) + (double)(n * factorial) / ((n + 1) + sqrt(n + 2));
}

double sum10_iterative(int n) {
    double result = 0;
    int factorial = 1;
    for (int i = 1; i <= n; i++) {
        factorial *= (i + 1);
        result += (double)(i * factorial) / ((i + 1) + sqrt(i + 2));
    }
    return result;
}

double sum11(int n) {
    if (n == 1) return (1 + sqrt(1 + 2)) / (2 + sqrt(6));
    double numerator = n + sqrt(n + n + 1);
    double denominator = (n + 1) + sqrt(tgamma(n + 3));
    return sum11(n - 1) + numerator / denominator;
}

double sum11_iterative(int n) {
    double result = 0;
    for (int i = 1; i <= n; i++) {
        double numerator = i + sqrt(i + i + 1);
        double denominator = (i + 1) + sqrt(tgamma(i + 3));
        result += numerator / denominator;
    }
    return result;
}

int main() {
    int n;
    printf("Nhap gia tri cua n: ");
    scanf("%d", &n);

    printf("Ket qua cho tung cong thuc:\n");
    printf("1. S(%d) = %d (De quy), %d (Khu de quy)\n", n, sum1(n), sum1_iterative(n));
    printf("2. S(%d) = %f (De quy), %f (Khu de quy)\n", n, sum2(n), sum2_iterative(n));
    printf("3. S(%d) = %f (De quy), %f (Khu de quy)\n", n, sum3(n), sum3_iterative(n));
    printf("4. S(%d) = %f (De quy), %f (Khu de quy)\n", n, sum4(n), sum4_iterative(n));
    printf("5. S(%d) = %d (De quy), %d (Khu de quy)\n", n, sum5(n), sum5_iterative(n));
    printf("6. S(%d) = %f (De quy), %f (Khu de quy)\n", n, sum6(n), sum6_iterative(n));
    printf("7. S(%d) = %d (De quy), %d (Khu de quy)\n", n, sum7(n), sum7_iterative(n));
    printf("8. S(%d) = %d (De quy), %d (Khu de quy)\n", n, sum8(n), sum8_iterative(n));
    printf("9. S(%d) = %f (De quy), %f (Khu de quy)\n", n, sum9(n), sum9_iterative(n));
    printf("10. S(%d) = %f (De quy), %f (Khu de quy)\n", n, sum10(n), sum10_iterative(n));
    printf("11. S(%d) = %f (De quy), %f (Khu de quy)\n", n, sum11(n), sum11_iterative(n));

    return 0;
}


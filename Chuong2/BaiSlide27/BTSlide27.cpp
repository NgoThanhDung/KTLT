#include <stdio.h>
#include <string.h>

// Hàm hoán đổi giá trị của hai phần tử kiểu int
void swapInt(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm hoán đổi giá trị của hai phần tử kiểu float
void swapFloat(float* a, float* b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm hoán đổi giá trị của hai phần tử kiểu char
void swapChar(char* a, char* b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm hoán đổi giá trị của hai chuỗi ký tự
void swapString(char a[], char b[]) {
    char temp[100];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

// Hàm sắp xếp tăng dần cho mảng số nguyên
void interchangeSortIntAsc(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                swapInt(&arr[i], &arr[j]);
            }
        }
    }
}

// Hàm sắp xếp giảm dần cho mảng số nguyên
void interchangeSortIntDesc(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                swapInt(&arr[i], &arr[j]);
            }
        }
    }
}

// Hàm sắp xếp tăng dần cho mảng số thực
void interchangeSortFloatAsc(float arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                swapFloat(&arr[i], &arr[j]);
            }
        }
    }
}

// Hàm sắp xếp giảm dần cho mảng số thực
void interchangeSortFloatDesc(float arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                swapFloat(&arr[i], &arr[j]);
            }
        }
    }
}

// Hàm sắp xếp tăng dần cho mảng ký tự
void interchangeSortCharAsc(char arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                swapChar(&arr[i], &arr[j]);
            }
        }
    }
}

// Hàm sắp xếp giảm dần cho mảng ký tự
void interchangeSortCharDesc(char arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                swapChar(&arr[i], &arr[j]);
            }
        }
    }
}

// Hàm sắp xếp tăng dần cho mảng chuỗi ký tự
void interchangeSortStringAsc(char arr[][100], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(arr[i], arr[j]) > 0) {
                swapString(arr[i], arr[j]);
            }
        }
    }
}

// Hàm sắp xếp giảm dần cho mảng chuỗi ký tự
void interchangeSortStringDesc(char arr[][100], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(arr[i], arr[j]) < 0) {
                swapString(arr[i], arr[j]);
            }
        }
    }
}

// Hàm hiển thị mảng số nguyên
void printArrayInt(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Hàm hiển thị mảng số thực
void printArrayFloat(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

// Hàm hiển thị mảng ký tự
void printArrayChar(char arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%c ", arr[i]);
    }
    printf("\n");
}

// Hàm hiển thị mảng chuỗi ký tự
void printArrayString(char arr[][100], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Ví dụ sử dụng cho mảng số nguyên
    int intArray[] = {5, 2, 9, 1, 6};
    int intSize = sizeof(intArray) / sizeof(intArray[0]);
    printf("Mảng số nguyên ban đầu: ");
    printArrayInt(intArray, intSize);

    interchangeSortIntAsc(intArray, intSize);
    printf("Mảng số nguyên sắp xếp tăng dần: ");
    printArrayInt(intArray, intSize);

    interchangeSortIntDesc(intArray, intSize);
    printf("Mảng số nguyên sắp xếp giảm dần: ");
    printArrayInt(intArray, intSize);

    printf("\n");

    // Ví dụ sử dụng cho mảng số thực
    float floatArray[] = {3.2, 5.5, 1.7, 8.3, 4.1};
    int floatSize = sizeof(floatArray) / sizeof(floatArray[0]);
    printf("Mảng số thực ban đầu: ");
    printArrayFloat(floatArray, floatSize);

    interchangeSortFloatAsc(floatArray, floatSize);
    printf("Mảng số thực sắp xếp tăng dần: ");
    printArrayFloat(floatArray, floatSize);

    interchangeSortFloatDesc(floatArray, floatSize);
    printf("Mảng số thực sắp xếp giảm dần: ");
    printArrayFloat(floatArray, floatSize);

    printf("\n");

    // Ví dụ sử dụng cho mảng ký tự
    char charArray[] = {'b', 'e', 'a', 'c', 'd'};
    int charSize = sizeof(charArray) / sizeof(charArray[0]);
    printf("Mảng ký tự ban đầu: ");
    printArrayChar(charArray, charSize);

    interchangeSortCharAsc(charArray, charSize);
    printf("Mảng ký tự sắp xếp tăng dần: ");
    printArrayChar(charArray, charSize);

    interchangeSortCharDesc(charArray, charSize);
    printf("Mảng ký tự sắp xếp giảm dần: ");
    printArrayChar(charArray, charSize);

    printf("\n");

    // Ví dụ sử dụng cho mảng chuỗi ký tự
    char stringArray[][100] = {"orange", "banana", "apple", "mango", "grape"};
    int stringSize = sizeof(stringArray) / sizeof(stringArray[0]);
    printf("Mảng chuỗi ký tự ban đầu: ");
    printArrayString(stringArray, stringSize);

    interchangeSortStringAsc(stringArray, stringSize);
    printf("Mảng chuỗi ký tự sắp xếp tăng dần: ");
    printArrayString(stringArray, stringSize);

    interchangeSortStringDesc(stringArray, stringSize);
    printf("Mảng chuỗi ký tự sắp xếp giảm dần: ");
    printArrayString(stringArray, stringSize);

    return 0;
}

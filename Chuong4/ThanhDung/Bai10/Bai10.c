#include <stdio.h>

int binarySearch(int arr[], int left, int right, int x) {
    if (right >= left) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, left, mid - 1, x);
        return binarySearch(arr, mid + 1, right, x);
    }
    return -1;
}

int main() {
    int n, x, i;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);
    int arr[n];
    printf("Nhap cac phan tu cua mang: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Nhap gia tri can tim: ");
    scanf("%d", &x);
    
    int result = binarySearch(arr, 0, n - 1, x);
    if (result != -1)
        printf("Gia tri %d nam o vi tri %d\n", x, result);
    else
        printf("Khong tim thay %d trong mang\n", x);
    return 0;
}


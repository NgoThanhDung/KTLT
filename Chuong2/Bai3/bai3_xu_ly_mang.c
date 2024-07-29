#include <stdio.h>

// Ham nhap mang
void nhapMang(int arr[], int size) {
	printf("Nhap %d phan tu cho mang:\n",size);
	int i;
	for(i = 0; i < size; i++){
		printf("Nhap phan tu %d: ",i);
		scanf("%d",&arr[i]);
	}
}

// Hàm xuat mang
void xuatMang(int arr[], int size) {
	printf("Mang co %d phan tu:\n",size);
	int i;
	for(i = 0; i < size; i++){
		printf("%d",arr[i]);
		printf("   ");
	}

	printf("\n");
}

int timMax(int arr[], int size)
{
	int i;
	int max = arr[0]; // gan max bang phan tu dau tien trong mang
	for(i = 0; i< size; i++){
		if(arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
}

int timMin(int arr[], int size)
{
	int i;
	int min = arr[0]; // gan min bang phan tu dau tien trong mang
	for(i = 0; i< size; i++){
		if(arr[i] < min)
		{
			min = arr[i];
		}
	}
	return min;
}

void demChanLe(int arr[], int size)
{
	int chan = 0;
	int le = 0;
	int i;
	for(i = 0; i< size ; i++){
		// Kiem tra chan hay le
		if(arr[i]%2 == 0){
			chan += 1;
		}else{
			le +=1;
		}
	}
	printf("So phan tu chan la: %d va so phan tu le la: %d\n",chan,le);
}

// Tim kiem tuyen tinh
int linearSearch(int arr[], int size, int x){
	int i;
	for(i = 0; i < size; i++){
		if(arr[i]==x){
	 		return i;
		}
	}
	return -1;
}

// Tim kiem nhi phan
int binarySearch(int arr[], int size, int x){
	int left = 0;
	int right = size -1;
	
	while(left<=right){
		int mid = left + (right - left)/2;
		
		//kiem tra phan tu giua
		if(arr[mid]==x){
			return mid;
		}else if(arr[mid]<x){
			left = mid + 1;
		}else{
			right = mid - 1;
		}
	}
	return -1;
}
int demPhanTu(int arr[], int size, int x){
	int dem = 0;
	int i;
	for(i = 0; i < size; i++){
		if(arr[i]==x){
			dem += 1;
		}
	}
	return dem;
}
  

int main() {
	int size;
	
	printf("Nhap so luong phan tu cho mang:");
	scanf("%d",&size);
	
	int arr[size]; // khai bao mang voi kich thuoc nguoi dung nhap
	
	nhapMang(arr,size);
	xuatMang(arr,size);
	
	printf("=========================\n");
	
	int max = timMax(arr,size);
	printf("Gia tri lon nhat trong mang la: %d\n", max);
	
	int min = timMin(arr,size);
	printf("Gia tri nho nhat trong mang la: %d\n", min);
	
	printf("=========================\n");
	
	demChanLe(arr,size);
	
	printf("===========Tim kiem tuyen tinh==============\n");
	
	int x;	
	printf("Nhap phan tu can tim: \n");
	scanf("%d",&x);	
	int xTuyenTinh = linearSearch(arr,size,x);
	
	if(xTuyenTinh != -1){
		printf("Phan tu %d duoc tim thay o vi tri %d\n",x,xTuyenTinh);
	}else{
		printf("Phan tu %d khong ton tai trong mang.\n", x);
	}
	
	printf("===========Tim kiem nhi phan==============\n");
	
	int xNhiPhan = binarySearch(arr,size,x);
	if(xNhiPhan != -1){
		printf("Phan tu %d duoc tim thay o vi tri %d\n",x,xNhiPhan);
	}else{
		printf("Phan tu %d khong ton tai trong mang.\n", x);
	}
	
	int a;	
	printf("Nhap phan tu can dem: \n");
	scanf("%d",&a);	
	printf("==========Dem phan tu a trong mang==============\n");
	
	int demPT = demPhanTu(arr,size,a);
	printf("Tren mang vua nhap co %d phan tu a\n",demPT);
	
	
	
	
   
    return 0;
}


#include <stdio.h>
#include <stdbool.h>

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

//=========================== 1. Mang co chua toan bo so nguyen to hay khong ===============
bool ktSNT(int n){
	int i;
	if(n<=1){
		return false;
	}
	if(n==2){
		return true;
	}
	if(n%2==0){
		return false;
	}
	for(i = 3; i*i <= n; i+=2){
		if(n%i==0){
			return false;
		}
	}
}
int kiemTraMangSNT(int arr[], int size){
	int i;
	int check = 0;
	for(i = 0; i < size; i++){
		if(ktSNT(arr[i])){
			check = 1;
		}else{
			check = 0;
			return check;
		}
	}
	return check;
}

bool ktDoiXung(int arr[], int size) {
    int start = 0;
    int end = size - 1;
    
    
    while (start < end) {
        if (arr[start] != arr[end]) {
            return false;
        }
        start++;
        end--;
    }
    
    return true;
}
bool ktTangDan(int arr[], int size){
	int i;
	for(i = 1; i< size; i++){
		if(arr[i] < arr[i-1]){
			return false;
		}
	}
	return true;
	
}
bool ktGiamDan(int arr[], int size){
	int i;
	for(i = 1; i< size; i++){
		if(arr[i] > arr[i-1]){
			return false;
		}
	}
	return true;
	
}
 bool ktTangGiam(int arr[], int size){
 	return !ktTangDan(arr,size) && !ktGiamDan(arr,size);
 }
int main(){
	int size;
	printf("Nhap so luong phan tu cho mang: \n");
	scanf("%d",&size);
	
	int arr[size];
	int menu;
	
	while(1){
		printf("=================================================\n");
		printf("1. Kiem tra mang co chua toan bo so nguyen to hay khong?\n");
		printf("2. Kiem tra mang co doi xung hay khong?\n");
		printf("3. Kiem tra mang co tan dan, giam dan, hay khong tang khong giam\n");
		printf("0. Thoat chuong trinh\n");
			
		printf("Nhap chuc nang can thuc hien: \n");
		scanf("%d",&menu);
		
		switch(menu){
			case 1:
					nhapMang(arr,size);
					xuatMang(arr,size);
					int ktra = kiemTraMangSNT(arr,size);
					if(ktra==1){
						printf("Mang chua toan bo so nguyen to\n");
					}else{
						printf("Mang khong chua toan bo so nguyen to\n");
					}
					break;
			case 2:
					nhapMang(arr,size);
					xuatMang(arr,size);
					if (ktDoiXung(arr, size)) {
        				printf("Mang doi xung\n");
   					 } else {
        				printf("Mang khong doi xung\n");
    				}
					break;
			case 3:
					nhapMang(arr,size);
					xuatMang(arr,size);
					if (ktTangDan(arr, size)) {
        				printf("Mang tang dan\n");
				    } else if (ktGiamDan(arr, size)) {
				        printf("Mang giam dan\n");
				    } else {
				        printf("Mang khong tang khong giam\n");
				    }
					break;
			case 0:
		        	printf("Thoat chuong trinh.\n");
		            return 0; // Thoát chuong trình
        	default:
		            printf("Khong hop le");
		            break;
				
		}
		
	}
	
	
	
	
	return 0;

}


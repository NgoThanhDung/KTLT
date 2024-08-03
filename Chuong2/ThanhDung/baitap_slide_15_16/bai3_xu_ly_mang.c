#include <stdio.h>
#include <stdbool.h>

//========== 1. Viet ham nhap xuat mang a ==================
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
//============================================================

//================== 2. Tim max/min cua a ====================
int timMax(int arr[], int size)
{
	int i;
	int max = arr[0]; 
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
	int min = arr[0]; 
	for(i = 0; i< size; i++){
		if(arr[i] < min)
		{
			min = arr[i];
		}
	}
	return min;
}
//=========================================================================

//================== 3. Dem so phan tu chan cua mang a ================================
int demChan(int arr[], int size){
	int chan = 0;
	int i;
	for(i = 0; i< size ; i++){
		// Kiem tra chan 
		if(arr[i]%2 == 0){
			chan++;
		}
	}
	return chan;
	
}
//======================================================================================
//================== 3. Dem so phan tu le cua mang a ===================================
int demLe(int arr[], int size)
{
	int le = 0;
	int i;
	for(i = 0; i< size ; i++){
		// Kiem tra le
		if(arr[i]%2 != 0){
			le++;
		}
	}
	return le;
	
}
//======================================================================================

//====================== 4. Tim kiem phan tu x trong a theo 2 dang ==================
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
//======================================================================================

//================= 5. Dem tren a co bao nhieu phan tu x ===============================
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
//======================================================================================

//======================== Bai tap (tt) ================================================
//============== 6. Dem tren a co bao nhieu phan tu lon hon x =========================

int demPhanTuLonHonX(int arr[], int size, int x){
	int dem = 0;
	int i;
	for(i = 0; i < size; i++){
		if(arr[i] > x){
			dem += 1;
		}
	}
	return dem;
}
//======================================================================================
//============== 7. Tinh tong cac phan tu cua a =======================================
int tinhTongPT(int arr[], int size){
	int tong = 0;
	int i;
	for(i = 0; i < size; i++){
		tong += arr[i];
	}
	return tong;
}
//======================================================================================

//============== 8. Xuat cac so nguyen to trong a =======================================
bool ktraSNT(int n){
	int i;
	if(n <= 1) return false;
	if(n==2) return true;
	if(n%2==0) return false;
	
	for(i = 3; i*i <= n; i+=2){
		if(n%i==0) return false;
	}
	return true;
}
void xuatSoNguyenTo(int arr[], int size){
	int i;
	for(i = 0; i < size; i++){
		if(ktraSNT(arr[i])){
			printf("%d ",arr[i]);
		}
	}
}
//======================================================================================

//======================= 9. Xuat cac so hoan thien trong a ============================
bool ktraSHT(int n){
	int tong = 0;
	int i;
	for(i=1; i< n; i++){
		if(n%i==0){
			tong += i;
		}
	}
	if(tong==n){
		return true;
	}else{
		return false;
	}
}

void xuatSoHoanThien(int arr[], int size){
	int i;
	for(i = 1; i < size; i++){
		if(ktraSHT(arr[i])){
			printf("%d ",arr[i]);
		}
	}
}

//======================================================================================

//======================= 10.a Xuat cac phan tu o vi tri chan ============================
void xuatViTriChan(int arr[], int size){
	int i;
	for(i = 0; i< size; i++){
		if(i%2==0){
			printf("%d ",arr[i]);
		}
	}
}
//======================= 10.b Xuat cac phan tu o vi tri le ============================
void xuatViTriLe(int arr[], int size){
	int i;
	for(i = 0; i< size; i++){
		if(i%2!=0){
			printf("%d ",arr[i]);
		}
	}
}
//======================================================================================
//================== 11.a Tim max va vi tri trong mang ====================
void timViTriMax(int arr[], int size)
{
	int i;
	int vitri;
	int max = arr[0]; 
	for(i = 0; i< size; i++){
		if(arr[i] > max)
		{
			max = arr[i];
			vitri = i;
		}
	}
	printf("Gia tri lon nhat la: %d, vi tri a[%d]",max,vitri);
}
//================== 11.b Tim min va vi tri trong mang ====================
void timViTriMin(int arr[], int size)
{
	int i;
	int vitri;
	int min = arr[0]; 
	for(i = 0; i< size; i++){
		if(arr[i] < min)
		{
			min = arr[i];
			vitri = i;
		}
	}
	printf("Gia tri nho nhat la: %d, vi tri a[%d]",min,vitri);
}
//=========================================================================

//================ 12. Cho 2 day so tang dan b,c. Ghep b,c tang dan ========

void sapXepTangDanHaimang(){
	 int i = 0; 
    int j = 0; 
    int k = 0; 
    int size1 = 4;
    int size2 = 4;
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 6, 8};
    int gopmang[8];

    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            gopmang[k] = arr1[i];
            i++;
        } else {
            gopmang[k] = arr2[j];
            j++;
        }
        k++;
    }
    while (i < size1) {
        gopmang[k] = arr1[i];
        i++;
        k++;
    }
    while (j < size2) {
        gopmang[k] = arr2[j];
        j++;
        k++;
    }
    printf("Mang gop: ");
    for (i = 0; i < size1 + size2; i++) {
        printf("%d ", gopmang[i]);
    }
}

//=========================================================================
int main() {
	int size;
	int menu;
	
	printf("Nhap so luong phan tu cho mang:");
	scanf("%d",&size);
	
	int arr[size]; // khai bao mang voi kich thuoc nguoi dung nhap
	
	
	 while (1) {
	printf("\n");
	printf("================== Menu =======================\n");
	
	printf("2. Tim gia tri max\n");
	printf("3. Tim gia tri min\n");
	printf("4. Dem so phan tu chan trong a\n");
	printf("5. Dem so phan tu le trong a\n");
	printf("6. Tim kiem x tuyen tinh\n");
	printf("7. Tim kiem x nhi phan\n");
	printf("8. Dem tren a co bao nhieu phan tu x\n");
	printf("9. Dem tren a co bao nhieu phan tu lon hon x\n");
	printf("10. Tinh tong cac phan tu cua a\n");
	printf("11. Xuat cac so nguyen to trong mang a\n");
	printf("12. Xuat cac so hoan thien trong mang a\n");
	printf("13. Xuat cac phan tu o vi tri chan trong mang a\n");
	printf("14. Xuat cac phan tu o vi tri le trong mang a\n");
	printf("15. Xuat gia tri lon nhat va  vi tri cua no trong mang a\n");
	printf("16. Xuat gia tri nho nhat va  vi tri cua no trong mang a\n");
	printf("17. Gop 2 mang va sap xep tang dan mang do \n");
	printf("0. Thoat chuong trinh\n");
	
	
	printf("===============================================\n");
	
	printf("Nhap chuc nang muon su dung: \n");
	scanf("%d",&menu);
	
	 switch (menu) {
        case 2:
        	nhapMang(arr,size);
			xuatMang(arr,size);
          	int max = timMax(arr,size);
			printf("Gia tri lon nhat trong mang la: %d\n", max);
            break;
        case 3:
        	nhapMang(arr,size);
			xuatMang(arr,size);
            int min = timMin(arr,size);
			printf("Gia tri nho nhat trong mang la: %d\n", min);
            break;
        case 4:
        	nhapMang(arr,size);
			xuatMang(arr,size);
        	int chan = demChan(arr,size);
        	printf("Mang a co %d phan tu chan\n", chan);
            break;
        case 5:
        	nhapMang(arr,size);
			xuatMang(arr,size);
           	int le = demLe(arr,size);
        	printf("Mang a co %d phan tu le\n", le);
            break;
        case 6:
        	nhapMang(arr,size);
			xuatMang(arr,size);
           	int x;	
			printf("Nhap phan tu can tim: \n");
			scanf("%d",&x);	
			int xTuyenTinh = linearSearch(arr,size,x);
			
			if(xTuyenTinh != -1){
				printf("Phan tu %d duoc tim thay o vi tri %d\n",x,xTuyenTinh);
			}else{
				printf("Phan tu %d khong ton tai trong mang.\n", x);
			}
            break;
        case 7:
        	nhapMang(arr,size);
			xuatMang(arr,size);
        	int a;	
			printf("Nhap phan tu can tim: \n");
			scanf("%d",&a);	
        	int xNhiPhan = binarySearch(arr,size,a);
			if(xNhiPhan != -1){
				printf("Phan tu %d duoc tim thay o vi tri %d\n",a,xNhiPhan);
			}else{
				printf("Phan tu %d khong ton tai trong mang.\n", a);
			}
           
            break;
        case 8:
        	nhapMang(arr,size);
			xuatMang(arr,size);
            int c;	
			printf("Nhap phan tu can dem: \n");
			scanf("%d",&c);	
			
			int demPT = demPhanTu(arr,size,c);
			printf("Tren mang vua nhap co %d phan tu a\n",demPT);
            break;
        case 9:
        	nhapMang(arr,size);
			xuatMang(arr,size);
            int n;	
			printf("Nhap phan tu can dem: \n");
			scanf("%d",&n);	
			
			int demPTLonHonX = demPhanTuLonHonX(arr,size,n);
			printf("Tren mang vua nhap co %d phan tu lon hon %d\n",demPTLonHonX,n);
            break;
        case 10:
        	nhapMang(arr,size);
			xuatMang(arr,size);
        	int tong = tinhTongPT(arr,size);
        	printf("Tong cac phan tu trong mang la: %d\n",tong);
            break;
        case 11:
        	nhapMang(arr,size);
			xuatMang(arr,size);
        	printf("Cac so nguyen to trong mang a la: \n");
        	xuatSoNguyenTo(arr,size);
            break;
        case 12:
        	nhapMang(arr,size);
			xuatMang(arr,size);
        	printf("Cac so hoan thien trong mang a la: \n");
        	xuatSoHoanThien(arr,size);
            break;
        case 13:
        	nhapMang(arr,size);
			xuatMang(arr,size);
        	printf("Cac phan tu chan trong mang a la: \n");
        	xuatViTriChan(arr,size);
            break;
        case 14:
        	nhapMang(arr,size);
			xuatMang(arr,size);
        	xuatViTriLe(arr,size);
            break;
        case 15:
        	nhapMang(arr,size);
			xuatMang(arr,size);
        	timViTriMax(arr,size);
            break;
        case 16:
        	nhapMang(arr,size);
			xuatMang(arr,size);
        	timViTriMin(arr,size);
            break;
        case 17:
        	sapXepTangDanHaimang();
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


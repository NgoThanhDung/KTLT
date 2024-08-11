#include <stdio.h>
#include <conio.h>

void nhapPhanSo(int *tuSo, int *mauSo) {
    printf("Nhap tu so: ");
    while (scanf("%d", tuSo) != 1) {
        printf("Gia tri khong hop le?. Vui long nhap lai tu so: ");
        while (getchar() != '\n');
    }

    printf("Nhap mau so: ");
    while (scanf("%d", mauSo) != 1 || *mauSo == 0) {
        if (*mauSo == 0) {
            printf("Mau so khong the la 0. Vui long nhap lai mau so: ");
        } else {
            printf("Gia tri khong hop le?. Vui long nhap lai mau so: ");
        }
        while (getchar() != '\n');
    }

    toiGianPhanSo(tuSo, mauSo); 
}

void xuatPhanSo(int tuSo, int mauSo) {
    printf("%d/%d\n", tuSo, mauSo);
}
int uocSoChungLonNhat(int a, int b) {
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}
void toiGianPhanSo(int *tuSo, int *mauSo) {
	int uocSo = uocSoChungLonNhat(*tuSo, *mauSo);
	*tuSo /= uocSo;
	*mauSo /= uocSo;
	
	if(*mauSo < 0) {
	   *tuSo = -(*tuSo);
	   *mauSo = -(*mauSo);
	}
}

void tongPhanSo(int tuSo1, int mauSo1, int tuSo2, int mauSo2, int *tuSoTong, int *mauSoTong) {
	*tuSoTong = tuSo1 * mauSo2 + tuSo2 * mauSo1;
	*mauSoTong = mauSo1 * mauSo2;
	toiGianPhanSo(tuSoTong, mauSoTong);
}

void hieuPhanSo(int tuSo1, int mauSo1, int tuSo2, int mauSo2, int *tuSoHieu, int *mauSoHieu) {
	*tuSoHieu = tuSo1 * mauSo2 - tuSo2 * mauSo1; 
	*mauSoHieu = mauSo1 * mauSo2; 
	toiGianPhanSo(tuSoHieu, mauSoHieu); 
}

void tichPhanSo(int tuSo1, int mauSo1, int tuSo2, int mauSo2, int *tuSoTich, int *mauSoTich) {
	*tuSoTich = tuSo1 * tuSo2;
	*mauSoTich = mauSo1 * mauSo2;
	toiGianPhanSo(tuSoTich, mauSoTich);
}

void thuongPhanSo(int tuSo1, int mauSo1, int tuSo2, int mauSo2, int *tuSoThuong, int *mauSoThuong) {
	*tuSoThuong = tuSo1 * mauSo2;
	*mauSoThuong = mauSo1 * tuSo2;
	toiGianPhanSo(tuSoThuong, mauSoThuong);
}

void xuatSoThapPhan(int tuso, int mauso) {
    printf("So thap phan ban nhap la: %d/%d\n", tuso,mauso);
}

int main() {
    int tuSo1, mauSo1, tuSo2, mauSo2;
    int tuSoTong, mauSoTong;
    int tuSoHieu, mauSoHieu;
    int tuSoTich, mauSoTich;
    int tuSoThuong, mauSoThuong;
    int choice;

    printf("Nhap phan so thu nhat:\n");
    nhapPhanSo(&tuSo1, &mauSo1);
    printf("Nhap phan so thu hai:\n");
    nhapPhanSo(&tuSo2, &mauSo2);

    do {
        printf("\nChon phep toan ban muon thuc hien:\n");
        printf("1. Tinh tong hai phan so\n");
        printf("2. Tinh hieu hai phan so\n");
        printf("3. Tinh tich hai phan so\n");
        printf("4. Tinh thuong hai phan so\n");
        printf("5. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                tongPhanSo(tuSo1, mauSo1, tuSo2, mauSo2, &tuSoTong, &mauSoTong);
                printf("Tong cua hai phan so la: ");
                xuatPhanSo(tuSoTong, mauSoTong);
                break;
            case 2:
                hieuPhanSo(tuSo1, mauSo1, tuSo2, mauSo2, &tuSoHieu, &mauSoHieu);
                printf("Hieu cua hai phan so la: ");
                xuatPhanSo(tuSoHieu, mauSoHieu);
                break;
            case 3:
                tichPhanSo(tuSo1, mauSo1, tuSo2, mauSo2, &tuSoTich, &mauSoTich);
                printf("Tich cua hai phan so la: ");
                xuatPhanSo(tuSoTich, mauSoTich);
                break;
            case 4:
                thuongPhanSo(tuSo1, mauSo1, tuSo2, mauSo2, &tuSoThuong, &mauSoThuong);
                printf("Thuong cua hai phan so la: ");
                xuatPhanSo(tuSoThuong, mauSoThuong);
                break;
            case 5:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le, vui long chon lai.\n");
        }
    } while(choice != 5);

    return 0;
}


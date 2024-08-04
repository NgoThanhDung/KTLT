#include <stdio.h>
#include <string.h>
#include <ctype.h>

int demKhoangTrang(char str[], int lenght){
	int dem =0;
	int i;
	for(i = 0; i < lenght; i++){
		if(str[i]==' '){
			dem+=1;
		}
	}
		return dem;
}

void xoaKhoangTrangThua(char *str, int lenght){
	char result[lenght + 1];
	int index = 0;
	int i;
	for(i = 0; i< lenght; i++){
		if(str[i]!=' '){
			result[index] = str[i];
			index++;
		}else if(i > 0 && str[i-1] !=' '){
			result[index] = str[i];
			index++;
		}
	
	}
	if(result[lenght + 1]== ' '){
		result[lenght + 1] =='/0';
	}
	strcpy(str,result);
	printf("Chuoi sau khi xoa la: %s\n", str);
}

void doiKyTuInHoaThuong(char *str, int lenght){
	int i;
	char result[lenght +1];
	int index = 0;
	for(i = 0; i < lenght; i++){
		if(str[i]!=' '){
			if(i == 0){
				result[index] = toupper(str[i]);
				index++;
			}else if(i >0 &&str[i-1] != ' '){
				result[index] = tolower(str[i]);
				index++;
			}else if(i > 0 && str[i-1] == ' ' && str[i+1]!=' '){
				result[index] = toupper(str[i]);
				index++;
			}
		}else if(i > 0 && str[i-1] != ' '){
				result[index] = str[i];
				index++;	
		}
	}
	strcpy(str,result);
	printf("Chuoi sau khi xu ly xong la: %s\n",str);
	
}

void main(){
	
	char *str[100];
	printf("Nhap chuoi: \n");
    fgets(str, sizeof(str), stdin); 
    int lenght = strlen(str);
    
	int dem = demKhoangTrang(str,lenght);
	printf("So khoang trang trong chuoi la: %d\n", dem);
	
	xoaKhoangTrangThua(str,lenght);
	
	doiKyTuInHoaThuong(str,lenght);

}


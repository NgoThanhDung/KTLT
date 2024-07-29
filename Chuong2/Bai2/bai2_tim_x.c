#include <stdio.h>


void findPosition(char arr[], int size, char x){
	int find = 0; // Bien kiem tra neu tim thay x
	int i;
	
	for(i = 0; i< size; i++){
		if(arr[i]==x){
			printf("Gia tri %c can tim o vi tri %d\n",x,i);
			find = 1;
			break;
		}
	}
	if(!find){
		printf("Gia tri %c khong co trong day ky tu\n",x);
	}
}

int main(){
    char arr[] = {'R', 'L', 'K', 'H', 'F', 'E', 'C', 'A'};
	int size = sizeof(arr)/sizeof(arr[0]);
	
	// cau a
	findPosition(arr,size,'R');
	findPosition(arr,size,'C');
	// cau b
	findPosition(arr,size,'D');
	findPosition(arr,size,'Q');
	
	return 0;

}


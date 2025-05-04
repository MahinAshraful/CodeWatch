#include<stdio.h>

int main(void){

	char str[100]={0};

	for(int i=0; i<20; i++){
		
		scanf("%c",&str[i]);
		
		if(str[i] == '\n'){
			str[i]='\n';
			break;
		}
	
	}
		
	for(int i=19; i>=0; i--){
			printf("%c",str[i]);
	}
			printf("\n");
}
	
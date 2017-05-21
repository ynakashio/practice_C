#include<stdio.h>


int main(void){

	int tensu;

	printf("点数は:");
	scanf("%d",&tensu);

	if (tensu >= 80){
		printf("あなたは80点以上なのでAです");
	} else if (60 <= tensu){
		/* if (60 <= tensu < 80)は不可*/
			printf("あなたは80点未満60点以上なのでBです");
		} else {
			printf("あなたは60点未満なのでCです");
		}
	}

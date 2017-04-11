#include <stdio.h>

int main(){

	char name1[10],name2[10];
	int value1,value2;

	printf("1人目の名前は");
	scanf("%s",name1);

	printf("2人目の名前は");
	scanf("%s",name2);

	printf("1人目の点数は");
	scanf("%d",&value1);

	printf("2人目の点数は");
	scanf("%d",&value2);

	if (value1 >= value2){
		printf("%sさんの方が点数が高い",name1);
	} else {
		printf("%sさんの方が点数が高い",name2);
	}

}

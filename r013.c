#include<stdio.h>

int main(void){

	int kubun,ninzu,goukei;

	printf("区分は？(子供は1 /大人は2を入力)");
	scanf("%d",&kubun);

	printf("\n人数は？");
	scanf("%d",&ninzu);

	if (kubun == 1){
		/*子供なので*/
		goukei = 800 * ninzu;
	} else {
		/*大人なので*/
		goukei = 1500 * ninzu;
	}

	printf("\n合計金額は%d",goukei);

}
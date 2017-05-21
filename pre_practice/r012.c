#include<stdio.h>

int main(){

	int tanka,suryo;
	int kingaku;

	float zeikin = 0.08;
	float zeikomi;

	printf("単価:");
	scanf("%d",&tanka);

	printf("\n数量:");
	scanf("%d",&suryo);

	kingaku = tanka * suryo;
	zeikomi = (float)kingaku * (1+zeikin);

	/*
	printf("\n原価は:%d",kingaku);
	printf("\n税込み金額は:%f",zeikomi);

	上の書き方はちょっと冗長、以下のが良い
	*/

	printf("原価は%d円,税込みは%f円",kingaku,zeikomi);

}
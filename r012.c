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
	printf("\n原価は:%d",kingaku);

	zeikomi = (float)kingaku * (1+zeikin);
	printf("\n税込み金額は:%f",zeikomi);

}
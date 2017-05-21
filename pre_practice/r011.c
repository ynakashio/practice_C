#include<stdio.h>

int main()
{
	int kokugo,shakai,rika;
	int goukei;
    float average;

    /* raw_inputする変数がintの時は、&でアドレスを明示する
       */

    printf("国語の点数=");
	scanf("%d",&kokugo);

    printf("\n社会の点数=");
    scanf("%d",&shakai);

    printf("\n理科の点数=");
    scanf("%d",&rika);

    goukei = kokugo + shakai + rika;
    printf("\n合計は%d点",goukei);

    /*
    途中で型変換するときは、(float)とかで指定する
    */
    average = (float)goukei/3;
    printf("\n平均は%f",average);

    return 0;

}

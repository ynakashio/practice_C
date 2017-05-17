#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES

double data_num = 1001;
double cauchy_array[1001];

double make_cauchy(){

	int i;
	double mu, gamma;

	for(i=0; i<data_num; i++){
		double x;
		x = (double)rand()/((double)RAND_MAX+1);
//		cauchy_array[i][0] = x;
		cauchy_array[i] = mu + gamma*tan(M_PI*(x-0.5));
	}

	// int j;
	// for(j=0; j<10000; j++){
	// 	printf("%f %f\n",cauchy_array[j][0],cauchy_array[j][1]);
	// }

	return 0;
}

double compare_double(const void *a, const void *b){
    if(*(double*)b > *(double*)a) return 1;
    if(*(double*)b < *(double*)a) return -1;
    return 0;
}


double average_median(){

	// 平均を求める

	int i;
	double sum=0;
	double average;

	for(i=0; i<data_num; i++){
		sum = sum + cauchy_array[i];
	}
	printf("%f\n", sum/data_num);

	// 中央値を求める
	qsort(cauchy_array, data_num, sizeof(double), compare_double);
	// for(i=0; i<data_num; i++){
	// 	printf("%f",cauchy_array[i]);
	// }

	printf("中央値: %f\n",cauchy_array[500]);

	return 0;
}



int main(){
	make_cauchy();
	average_median();
	return 0;
}
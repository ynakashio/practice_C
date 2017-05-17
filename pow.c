#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int data_num=10000;
double pow_dist[10000][2];
double new_alpha,a,b;


double make_pow_dist(){

	double alpha;
	alpha = 3.0;

	/* まず逆関数法で、乱数を作る。
	最初に一様乱数を発生させて、次にべき分布の値に対応するような値を出す*/

	int i;
	for(i=0; i<data_num; i++){

		double x;
		x = (double)rand()/((double)RAND_MAX+1);
		pow_dist[i][0] = x;
		pow_dist[i][1] = pow(x,-1/alpha);
	}

/*	int j;
	for(j=0; j<10000; j++){
		printf("%f\n",pow_dist[j][1]);
	}*/

	return 0;
}


double most_likelihood(){

	// 最尤推定でalphaを求める

	int i=data_num;
	double new_alpha=0.0;
	double y;

	for(i=0; i<data_num; i++){
		y = log(pow_dist[i][1]);
//		printf("%f\n",y);
		new_alpha = new_alpha+y;
	}

	new_alpha = data_num/new_alpha;
//	printf("新しいalphaは%f\n",new_alpha);

	return new_alpha;
}


double least_square(){

	// 最小二乗法でalphaを求める

	// まず平均値を求める
	int i;
	double x_ave=0.0, y_ave=0.0;

	for(i=0; i<data_num; i++){
		x_ave = x_ave + log(pow_dist[i][1]);
		y_ave = y_ave + log(pow_dist[i][0]);
	}

	x_ave = x_ave/data_num;
	y_ave = y_ave/data_num;
//	printf("xとyの平均は => %f %f\n",x_ave,y_ave);


	//aとbを近似する
//	double a,b;
	double nom=0.0, denom=0.0;

	for(i=0; i<data_num; i++){
		nom = nom + (log(pow_dist[i][1])-x_ave)*(log(pow_dist[i][0])-y_ave);
		denom = denom + pow(log(pow_dist[i][1])-x_ave,2);
	}

	a = nom/denom;
	b = y_ave-a*x_ave;
//	printf("%f %f\n",a,b);

	return a;
}



int main(){

	int i;
	double ml_array[1000];
	double ls_array[1000];

	for(i=0; i<1000; i++){
		make_pow_dist();
		new_alpha = most_likelihood();
		a = least_square();

		ml_array[i] = new_alpha;
		ls_array[i] = a;
	}

	for(i=0; i<1000; i++){
		printf("%f %f\n",ml_array[i],-ls_array[i]);
	}

	return 0;
}



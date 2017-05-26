#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int data_num=2000;
double normal_dist[2000][2];
double plot_dist[2000][2];


double single_regression(){

	int i;

	for(i=0; i<data_num; i++){
		double a, b, x, y;
		a = (double)rand()/((double)RAND_MAX+1);
		b = (double)rand()/((double)RAND_MAX+1);

		x = cos(2*M_PI*a)*sqrt((-2)*log(b));
		y = sin(2*M_PI*a)*sqrt((-2)*log(b));

		normal_dist[i][0] = x;
		normal_dist[i][1] = y;
	}

	// for(i=0; i<data_num; i++){
	// 	printf("%f %f\n", normal_dist[i][0], normal_dist[i][1]);
	// }

	// double plot_dist[2000][2];

	for(i=0; i<data_num; i++){
		plot_dist[i][0]=2*normal_dist[i][0];
		plot_dist[i][1]=1.5*normal_dist[i][0]+3*normal_dist[i][1];
		// printf("%f %f\n",plot_dist[i][0],plot_dist[i][1]);
	}

	// for(i=0; i<data_num; i++){
	// 	printf("%f %f\n",plot_dist[i][0],plot_dist[i][1]);
	// }

	double x_ave=0.0, y_ave=0.0;
	double nom=0.0, denom=0.0;

	for(i=0; i<data_num; i++){
		x_ave = x_ave + plot_dist[i][0];
		y_ave = y_ave + plot_dist[i][1];
	}

	x_ave = x_ave/data_num;
	y_ave = y_ave/data_num;
	// printf("%f %f\n",x_ave,y_ave);

	for(i=0; i<data_num; i++){
		nom = nom + (plot_dist[i][0]-x_ave)*(plot_dist[i][1]-y_ave);
		denom = denom + pow(plot_dist[i][0]-x_ave,2);
	}

	double c,d;
	c = nom/denom;
	d = y_ave-c*x_ave;
	printf("%f %f\n", c,d);

	return 0.0;
}


double calc_average_standn_etc(){

	int i;
	double x_range, x_ceil;
	double y_ave;

	double *tmp;

	/* xが0.5ずつの範囲で計算する */
	/* columns=["x_range","average","standard"] */

	for(x_range=-10; x_range<10; x_range=x_range+0.5){

		x_ceil = x_range+0.5;
		printf("%fから%fの間の計算...\n", x_range, x_ceil);

		/* 全部の配列[0]について、x_rangeの中に入っているかを調べる => 入っているものを配列に入れる */

		/* x_range と x_ceil の間に含まれるxの数を数える */
		int data_size=0;
		for(i=0; i<data_num; i++){
			if( plot_dist[i][0]>=x_range && plot_dist[i][0]<x_ceil){
				data_size=data_size+1;
			}
		}

		/* ⬆︎で数えた配列の数を宣言する */
//		printf("データサイズは%d\n",data_size);
		tmp=(double *)calloc(data_size,sizeof(double));

		for(i=0; i<data_size; i++){
			if( plot_dist[i][0]>=x_range && plot_dist[i][0]<x_ceil){
				tmp[i]=plot_dist[i][1];
			}
		}

		// for(i=0; i<data_size; i++){
		// 	printf("%f\n",tmp[i]);
		// }

		/* 配列に入れたものの平均と標準偏差を計算 */

		/* 平均を計算*/
		int j;
		double tmp_ave=0.0;
		for(j=0; j<data_size; j++){
			tmp_ave = tmp_ave+tmp[j];
		}
		printf("和は%f サイズは%d\n",tmp_ave, data_size);

		if(data_size != 0){
			tmp_ave = tmp_ave/data_size;
//			printf("平均は%f ", tmp_ave);//, data_size);
		}

		/* 標準偏差を計算 */
		double tmp_std =0.0;
		for(j=0; j<data_size; j++){
			tmp_std = tmp_std+tmp[j]*tmp[j];
		}

		if(data_size != 0){
			tmp_std = tmp_std/data_size;
//			printf("標準偏差は%f \n", tmp_std);//, data_size);
		}
//		printf("%f %f %f\n", x_range+0.25,tmp_ave,tmp_std);


	}
	return 0;
	free(tmp);
}




int main(){

	single_regression();
	calc_average_standn_etc();

	return 0;
}





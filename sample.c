#include <stdio.h>

/*
int %d
float &f
char %c
*/

int main(void){
    int x = 10;
    float y = 5.2;
    char c = 'A';
    x += 5;
    printf("%d\n",x*x);
    printf("x = %d, y=%f, c =%c\n", x,y,c);
    return 0;
}

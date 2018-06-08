#include<stdio.h>
#include<string.h>
#define MAXSIZE 50
void input(double x[MAXSIZE],double y[MAXSIZE],long n) {
    long i;
    for(i=0;i<n;i++) {
        printf("\n请输入插值节点x[%ld],y[%ld]:",i,i);
        scanf("%lf,%lf",&x[i],&y[i]);
    }
}
int main() {
    double x[MAXSIZE],y[MAXSIZE],_x,_y,t;
    long n,i,j;
    printf("\n请输入插值点的个数：");
    scanf("%ld",&n);
    input(x, y, n);
    printf("\n请输入插值点：");
    scanf("%lf",&_x);
    _y = 0;
    for(i=0;i<n;i++) {
        t = 1;
        for(j=0;j<n;j++)
            if(j!=i) {
                t *= (_x - x[j])/(x[i] - x[j]);
            }
            _y += t * y[i];
    }
    printf("\n插值点(x,y) = (%lf,%lf)。",_x,_y);
    return 0;
}



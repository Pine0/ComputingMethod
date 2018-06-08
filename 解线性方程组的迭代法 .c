#include<stdio.h>
#include<math.h>
#define MAXSIZE 50
void input(double a[MAXSIZE][MAXSIZE],double b[MAXSIZE],long n) {
    long i,j;
    printf("\n请输入原方程组的增广矩阵：\n");
    for(i=0;i<n;i++)  {
        for(j=0;j<n;j++) {
            scanf("%lf",&a[i][j]);
        }
        scanf("%lf",&b[i]);
    }
}
void output(double x[MAXSIZE],long n) {
    long i;
    printf("\n原方程组的解向量为：\n");
    for(i=0;i<n;i++) {
        printf(" %lf",x[i]);
    }
}
int main() {
    double a[MAXSIZE][MAXSIZE],b[MAXSIZE],x[MAXSIZE];
    double epsilon,e,s,oldx;
    long n,i,j,k,maxk;
    printf("\n请输入原方程的阶数：");
    scanf("%ld",&n);
    input(a,b,n);
    printf("\n请输入迭代初始向量：");
    for(i=0;i<n;i++) {
        scanf("%lf",&x[i]);
    }
    printf("\n请输入最大迭代次数：");
    scanf("%ld",&maxk);
    printf("\n请输入误差上限：");
    scanf("%lf",&epsilon);
    for(k=1;k<=maxk;k++) {
        e=0;
        for(i=0;i<n;i++) {
            oldx=x[i]; s = 0;
            for(j=0;j<n;j++)
                if(j!=i) s += a[i][j] * x[j];
            x[i] = (b[i]-s)/a[i][i];
            if(e<fabs(oldx - x[i]))
                e = fabs(oldx - x[i]);
        }
        if(e<epsilon) break;
    }
    if(k <= maxk)
        output(x, n);
    else
        printf("\n迭代次数已超过上限。");
}

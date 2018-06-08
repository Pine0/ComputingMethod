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
    printf("\n原方程组的解为：\n");
    for(i=0;i<n;i++) {
        printf(" %lf",x[i]);
    }
}
int main() {
    double a[MAXSIZE][MAXSIZE],x[MAXSIZE],s;
    long n,i,j,k;
    printf("\n请输入原方程的阶数：");
    scanf("%ld",&n);
    input(a,x,n);
    for(k=0;k<n-1;k++) {
        for(i=k+1;i<n;i++) {
            s = 0;
            for(j=0;j<k;j++) s += a[i][j]*a[j][k];
            a[i][k] = (a[i][k] - s)/a[k][k];
        }
        for(j=k+1;j<n;j++) {
            s = 0;
            for(i=0;i<k+1;i++) s+=a[k+1][i]*a[i][j];
            a [k+1][j] -= s;
        }
    }
    for(i=1;i<n;i++) {
        s = 0;
        for(j=0;j<i;j++) s += a[i][j]*x[j];
        x[i] -= s;
    }
    for(i=n-1;i>=0;i--) {
        s = 0;
        for(j=i+1;j<=n-1;j++) s += a[i][j] * x[j];
        x[i] = (x[i]-s)/a[i][i];
    }
    output(x, n);
}

#include <stdio.h>
#include <math.h>
#include <inttypes.h>

int64_t k;
double eps=1;
int64_t fact[20];

double f(double x){
    return cos(x);
}

double degree(double x, int n){
    double a=1;
    if (n==0){
        return 1;
    }
    for (int i=0; i<n; ++i){
        a=a*x;
    }
    return a;
}

double Teylor(double x){
    double T=0;
    if (x==0){
        return 1;
    }
    k=1;
    double slag=1;
    double x2=x*x;
    while ((slag>eps || -slag>eps) && k<=100){
        T+=slag;
        slag=degree(-1, k)*(x2/fact[2*k]);
        x2=x2*x*x;
        k++;
    }
    return T;
}

int main(){
    int n;
    double x, a=0, b=1, T,h;
    x=a;
    fact[0]=1;
    fact[1]=1;
    for (int i=2; i<21;++i){
        fact[i]=fact[i-1]*i;
    }
    printf("Введите число n ");
    scanf("%d", &n);
    while (1+eps/2>1){
        eps=eps/2;
    }
    printf("\n Машинный епсилон = %e \n\n", eps); // .19 - count signs after point
    printf("-----------------------------------------------------------------\n");
	printf("|  x   |       Teylor           |         f              |  k   |\n");
	printf("-----------------------------------------------------------------\n");
    h=(b-a)/(n-1);
    for (int i=0; i<n; ++i){
        T=Teylor(x);
        printf("|%.2f  | %.19f  | %.19f  |  %ld   | \n", x, T, f(x), k);
        x+=h;
    }
    printf("-----------------------------------------------------------------\n");
}
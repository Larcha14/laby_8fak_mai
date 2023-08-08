#include <stdio.h>
#include <math.h>
#include <inttypes.h>

struct result{
    double x;
    int state;
    int count_i;
} res;

double f_1(double x1){                          //f_1()-num 16
    return 3*sin(sqrt(x1))+0.35*x1-3.8;
}

double f_2(double x1){                     //f_2() -num 17
    return 0.25*x1*x1*x1+x1-1.2502;
}

double f_1_iter(double x1){                          
    return -0.5*(3*sin(sqrt(x1))+0.35*x1-3.8)+x1;
}

double f_2_iter(double x1){                    
    return -0.4*(0.25*x1*x1*x1+x1-1.2502)+x1;
}

double derivative1(double (*f)(double), double x0){
    double dx = 0.00001;
    return (f(x0+dx)-f(x0))/dx;
}

double derivative2(double (*f)(double), double x0){
    double dx = 0.00001;
    return (derivative1(f, x0+dx) -derivative1(f, x0))/dx;
}

struct result dich(double (*f)(double), double a, double b){
    double c;
    res.count_i=0;
    double e= 0.00001;
    while (fabs(b-a>e)){
        c=(a+b)/2;
        if(f(a)*f(c)<0){
            b=c;
        } else{
            a=c;
        }
        res.count_i++;
    }
    res.x=(a+b)/2;
    res.state=1;
    return res;


}

struct result iter(double (*f)(double), double a, double b){
    double x0=(a+b)/2;
    double x1=x0;
    double e= 0.00001;
    res.count_i=0;
    do {
        if (fabs(derivative1(f,x0))>=1){
            res.state=0;
            return res;
        }
        x0=x1;
        x1=f(x0);
        res.count_i++;
        // printf("%.5lf %.5lf \n", x0, x);
    } while(fabs(x1-x0)>e);
    res.state=1;
    res.x=x1;
    return res;
}



struct result nyton(double (*f)(double), double a, double b){
    double x0=(a+b)/2;
    double e= 0.000001;
    res.count_i=0;
    double x1=x0;
    do{
        if (fabs(f(x0)*derivative2(f, x0))>= derivative1(f, x0)*derivative1(f, x0)){
                res.state=0;
                return res;
        } 
        x0=x1;
        x1=x0-f(x0)/derivative1(f, x0);
        res.count_i++;

    } while(fabs(x1-x0)>e);
    res.state=1;
    res.x=x1;
    return res;
}

int main(){
    double a1=2, b1=3, a2=0, b2=2;
    int n;
    printf("Функция 3*sin(sqrt(x1))+0.35*x1-3.8 \n \n");
    struct result dich_1=dich(f_1,a1, b1);
    double x1d=dich_1.x;
    if (f_1(a1)*f_1(b1)<0){
        printf("Метод дихотомии применим. Корень = %.5lf. Число итераций: %d  \n", x1d, dich_1.count_i );

    } else {
        printf("Метод дихотомии неприменим  \n");
        x1d=0;
    }
    struct result iter_1=iter(f_1_iter,a1, b1);
    double x1i=iter_1.x;
    if (iter_1.state==1){
        printf("Метод итерации применим. Корень = %.5lf. Число итераций: %d \n", x1i, iter_1.count_i);
    } else{
        printf("Метод итерации неприменим.  \n");
        x1i=0;
    }
    struct result nyton_1=nyton(f_1,a1, b1);
    double x1n=nyton_1.x;
    if (nyton_1.state==1){
        printf("Метод Ньютона применим. Корень = %.5lf. Число итераций: %d \n \n", x1n, nyton_1.count_i);
    } else{
        printf("Метод Ньютона неприменим.  \n");
        x1n=0;
    }
    printf("Разность результатов метода Ньютона и метода итераций %e \n", fabs(x1n-x1i));
    printf("Разность результатов метода дихотомии и метода итераций %e \n", fabs(x1d-x1i));
    printf("Разность результатов метода Ньютона и метода дихотомии %e \n", fabs(x1d-x1n));
    printf("---------------------------------------------------------------------\n \n");

    printf("Функция 0.25*x1*x1*x1+x1-1.2502 \n \n");
    struct result dich_2=dich(f_2,a2, b2);
    double x2d=dich_2.x;
    if (f_2(a2)*f_2(b2)<0){
        struct result dich_2=dich(f_2,a2, b2);
        double x2d=dich_2.x;
        printf("Метод дихотомии применим. Корень = %.5lf. Число итераций: %d  \n", x2d, dich_2.count_i );

    } else {
        printf("Метод дихотомии неприменим  \n");
        x2d=0;
    }
    struct result iter_2=iter(f_2_iter,a2, b2);
    double x2i=iter_2.x;
    if (iter_2.state==1){
        printf("Метод итерации применим. Корень = %.5lf. Число итераций: %d \n", x2i, iter_2.count_i);
    } else{
        printf("Метод итерации неприменим.  \n");
        x2i=0;
    }
    struct result nyton_2=nyton(f_2,a2, b2);
    double x2n=nyton_2.x;
    if (nyton_2.state==1){
        printf("Метод Ньютона применим. Корень = %.5lf. Число итераций: %d \n", x2n, nyton_2.count_i);
    } else{
        printf("Метод Ньютона неприменим.  \n");
        x2n=0;
    }
    printf("\n");
    printf("Разность результатов метода Ньютона и метода итераций %e \n", fabs(x2n-x2i));
    printf("Разность результатов метода дихотомии и метода итераций %e \n", fabs(x2d-x2i));
    printf("Разность результатов метода Ньютона и метода дихотомии %e \n", fabs(x2d-x2n));
    printf("\n ");
}
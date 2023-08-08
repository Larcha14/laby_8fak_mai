#include <stdio.h>

int stepen(int a, int b){
    while (b>1){
        a=a*10;
        b=b-1;
    }
    return a;
}

int BezChet(int a){
    int b,flag,n;
    n=1;
    flag=0;
    a =a/10;
    b=a%10;
    a=a/100;
    while (a!=0){
        if(a%10!=0){
            if (flag!=1){
                b=(a%10)*stepen(10,n)+b;
            } else{
                b=((a%10)-1)*stepen(10,n)+b;
                flag=0;
            }

        } else{
            if (flag!=1){
                b=stepen(10,n+1)+b;
                flag=1;
            } else{
                b=((a%10)-1)*stepen(10,n)+b;
                flag=0;
            }
            printf("%d \n", b);
        }
        a=a/100;
        n+=1;
    }
    if (flag==1){
        b=((a%10)-1)*stepen(10,n)+b;
    }
    return b;
}


int main(){
    int a;
    printf("Введите любое число в диапазоне (-1е9, 1е9)  ");
    while(1==scanf("%d", &a)){
        // scanf("%d", &a);
        printf("\n");
        if (a/10==0){
            printf("None\n");
        } else{
            printf("%d\n", BezChet(a));
        }
        printf("Введите любое число в диапазоне (-1е9, 1е9)  ");
    }
}
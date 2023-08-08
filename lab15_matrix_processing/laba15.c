//8
#include <stdio.h>

int main(){
    int n, a,indi, indj,s,i2;
    printf("Введите размер квадратной матрицы  ");
    scanf("%d \n", &n);
    int matrixx[n][n];
    for (int i=0; i<n; ++i){
        for (int j=0; j<n; ++j){
            scanf("%d", &matrixx[i][j]);
        }
    }
    printf("\n");
    if (n>=3){
        indi=n-3;
        i2=indi;
        indj=0;
        for (int y=0; y<n-2;++y){
            s=0;
            for (int i=i2;(i<n) &&(indj<n);++i){
                s+=matrixx[i][indj];
                indj+=1;
            }
            matrixx[n-2-y][y+1]=s;
            indi=indi-2;
            if (indi<0){
                i2=0;
                indj=indi*(-1);
            } else{
                indj=0;
                i2=indi;
            }

        }
    }
    for (int i=0; i<n; ++i){
        for (int j=0; j<n; ++j){
            printf("%d ", matrixx[i][j]);
        }
        printf("\n");
    }

    
}
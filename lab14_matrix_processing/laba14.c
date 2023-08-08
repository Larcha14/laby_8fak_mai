#include <stdio.h>

int main(){
    int n, a,indUp, indDown,i2;
    printf("Введите размер квадратной матрицы  ");
    scanf("%d \n", &n);
    int matrixx[n][n];
    for (int i=0; i<n; ++i){
        for (int j=0; j<n; ++j){
            scanf("%d", &matrixx[i][j]);
        }
    }
    printf("\n");
    indUp=n;
    indDown=1;
    for (int j=0; j<n;++j){
        for (int i=indUp-1;i>=0;--i){
            printf("%d ", matrixx[i][indUp-1-i]);
        }
        indUp=indUp-1;
        i2=1;
        for (int i=indDown; i<n;++i){
                printf("%d ", matrixx[i][n-i2]);
                i2+=1;
        }
        indDown+=1;
    }

    // for
}
//number 15
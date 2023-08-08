#include <stdio.h>

int modul(int x){
    if(x>0){
        return x;
    }else {
        return -x;
    }
}

int sign(int a){
    if (a==0) {
        return 0;
    } else if (a>0) {
        return 1;
    } else {
        return -1;
    }
}

int max(int a, int b){
    if (a>b){
        return a;
    } else{
        return b;
    }
}

int mod(int a, int b){
    if (a%b==0){
        return 0;
    } else {
        if ((a>0 && b>0) || (a<0 && b<0)){
            return a%b;
        }
        if (a>0 && b<0) {
            return ((a%b) - modul(b));
        }
        if (a<0 && b>0) {
            return ((a%b) +b);
        } else{
            return 0;
        }
    }
}

int proverka(int x, int y){
    if( (x-10)*(x-10)+(y-10)*(y-10)<=100){
        if( (x-10)*(x-10)+(y-10)*(y-10)>=25){
            return 1;
        } else {
            return 0;
        }
        
    } else {
        return 0;
    }
}

int icout(int ik, int jk, int lk, int k){
    int ik1;
    ik1= ((modul(ik - jk+lk))/(3-sign(ik - jk + k))) +10;
    return ik1;
}

int jcout(int ik, int jk, int lk, int k){
    int jk1;
    jk1= ((modul(ik + jk - lk))/(3-sign(jk - ik + k))) +10;
    return jk1;
}

int lcout(int ik, int jk, int lk, int k){
    int lk1;
    lk1=max(ik*jk,jk*lk)*mod((k+1),40);
    return lk1;
}

int main() {
    int i0=0;
    int j0=-3;
    int l0=-7;
    int i=i0;
    int j=j0;
    int l=l0;
    int p=0;
    int u=0;
    for (;u<=50;++u){
        if (proverka(i,j)){
            p=1;
            break;
        }
        i=icout(i0,j0,l0, u);
        j=jcout(i0,j0,l0, u);
        l=lcout(i0,j0,l0, u);
        i0=i;
        j0=j;
        l0=l;
    }
    
    if (p) {
        printf("Yes k=%d ; (i,j) = (%d, %d) ; l=%d", u,i,j,l);
    } else {
        printf("No k=%d ; (i,j) = (%d, %d) ; l=%d", u,i,j,l);
    }
}

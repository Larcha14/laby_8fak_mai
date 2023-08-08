#include "sort_Hor.h"

static double maxim(double a, double b, double c){
    double mx;
    if(a>b){
        mx=a;
    } else{
        mx=b;
    }
    if(mx<c){
        mx=c;
    }
    return mx;
}

static double minim(double a, double b, double c){
    double mn;
    if (a<b){
        mn= a;
    }else {
        mn =b;
    }
    if (c<mn){
        mn=c;
    }
    return mn;
}

static void circle_pop_front(dq_double_dyn_mass *from, dq_double_dyn_mass *to, int kd, int ku){
    double t;
    for (int K=kd; K<ku; ++K){
        t=dq_pop_front(from);
        dq_push_back(to, t);
    }

}

static void circle_pop_back(dq_double_dyn_mass *from, dq_double_dyn_mass *to, int kd, int ku){
    double t;
    for (int K=kd; K<ku; ++K){
        t=dq_pop_back(from);
        dq_push_front(to, t);
    }
}

static double get_elem(dq_double_dyn_mass *arr, int i){
    int n, len;
    dq_double_dyn_mass dq;
    dq_init(&dq);
    double a=0;
    len=dq_size(arr);
    n=len/2;
    if (i<n){
        circle_pop_front(arr, &dq, 0, i);
        a=dq_first(arr);
        circle_pop_back(&dq, arr, 0, i);
    } else{
        circle_pop_back(arr, &dq, i, len);
        a=dq_pop_front(&dq);
        dq_push_back(arr, a);
        circle_pop_front(&dq, arr, i, len-1);
    }
    dq_destroy(&dq);
    return a;
}

double find_pivot(dq_double_dyn_mass *arr, int n){
    double a, b, c;
    a=dq_first(arr);
    b=dq_last(arr);
    n=n/2;
    c=get_elem(arr, n);
    // printf("mx = %lf mn =%lf ", maxim(a,b,c), minim(a,b,c));
    c=a+b+c-minim(a,b,c)-maxim(a,b,c);
    // printf("c= %lf ", c);
    return c;
}

void partition(dq_double_dyn_mass *arr, dq_double_dyn_mass *left, dq_double_dyn_mass *eq, dq_double_dyn_mass *right, double pivot){
    int l=dq_size(arr);
    for(int i=0; i<l; ++i){
        double t;
        t=dq_pop_front(arr);
        if(t>pivot){
            dq_push_back(right, t);
        } else if(t==pivot){
            dq_push_back(eq, t);
        } else{
            dq_push_back(left, t);
        }

    }

}

void print_dq(dq_double_dyn_mass *arr){
    int n=dq_size(arr);
    dq_double_dyn_mass tmp;
    dq_init(&tmp);
    for (int i=0; i<n;++i){
        double t =dq_pop_front(arr);
        dq_push_back(&tmp, t);
        printf("%lf ", t);
    }
    for(int i=0; i<n;++i){
        double t=dq_pop_front(&tmp);
        dq_push_back(arr, t);
    }
    dq_destroy(&tmp);
}

dq_double_dyn_mass* merge_deq(dq_double_dyn_mass *to, dq_double_dyn_mass *left, dq_double_dyn_mass *eq, dq_double_dyn_mass *right){
    // dq_double_dyn_mass tmp;
    // dq_init(&tmp);
    circle_pop_front(left, to, 0, dq_size(left));
    circle_pop_front(eq, to, 0, dq_size(eq));
    circle_pop_front(right, to, 0, dq_size(right));
    return to;

}



void sort_hoar(dq_double_dyn_mass *arr, int n){
    if(n<2){
        return;
    }else if(n==2){
            if(dq_first(arr)>dq_last(arr)){
                double tmp=dq_pop_front(arr);
                dq_push_back(arr, tmp);
            }
            return;
    }
    dq_double_dyn_mass left;
    dq_init(&left);
    dq_double_dyn_mass right;
    dq_init(&right);
    dq_double_dyn_mass eq;
    dq_init(&eq);
    double b = find_pivot(arr, n);
    partition(arr, &left, &eq, &right, b); 
    // printf("\nleft = ");
    // print_dq(&left);
    // printf("\nright = \t\t");
    // print_dq(&right);
    sort_hoar(&left, dq_size(&left));
    sort_hoar(&right, dq_size(&right));

    merge_deq(arr, &left, &eq, &right);

    dq_destroy(&left);
    dq_destroy(&right);
    dq_destroy(&eq);
}

// int main(){
//     int n=8, i;
//     dq_double_dyn_mass dq;
//     dq_init(&dq);
//     double t;
//     for(int i=0;i<n;++i){
//         scanf("%lf", &t);
//         dq_push_back(&dq, t);
//     }
//     // printf("\n");
//     // find_pivot(&dq, n);
//     // int t=find_pivot(&dq, dq_size(&dq));
//     // printf("%d")
//     sort_hoar(&dq, n);
//     for(int i=0; i<n;++i){
//         printf("%lf ", dq_pop_front(&dq));
//     }
//     dq_destroy(&dq);

// }
//9 8 2 1 3 4 6 7 
//2 2 2 7 4 5 2 1

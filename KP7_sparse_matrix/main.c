#include "main.h"

static void zero_input(ddl_vector_Cercle *v, int l, int r){
    for(int i=l; i<r; ++i){
        set_el(v, i, 0);
    }
}

static void veprint(ddl_vector_Cercle *v, int l, int r){
    for(int i=l; i<r;++i){
        printf("%d ", get_el(v, i));
    }
}

void vec_print(data mas){
    printf("\n");
    printf(" Vector CIP: ");
    veprint(&mas.CIP, 0, mas.k_cip);
    printf("\n");
    printf(" Vector PI: ");
    veprint(&mas.PI, 0, mas.count);
    printf("\n");
    printf(" Vector YE: ");
    veprint(&mas.YE, 0, mas.count);
    printf("\n");
}

void function(data mas){
    int mx=1;
    int id_max_f=0;
    int id_max_s=0;
    for(int i=0; i<mas.count;++i){
        int cur_el=abs(get_el(&mas.YE, i));
        if(cur_el>mx){
            id_max_s=get_el(&mas.PI, i);
            // id_max_s=id_max_f;
            mx=cur_el;
        } else if(cur_el==mx){
            if(get_el(&mas.PI, i)>=id_max_f){
                if(get_el(&mas.PI, i)>id_max_s){
                    id_max_f=id_max_s;
                    id_max_s=get_el(&mas.PI, i);
                } else{
                    id_max_f=get_el(&mas.PI, i);
                }
            } 
        }
    }
    for(int i=0; i<mas.count;++i){
        if(get_el(&mas.PI, i)==id_max_f){
            int tmp;
            tmp=get_el(&mas.YE, i);
            tmp=tmp/mx;
            set_el(&mas.YE, i, tmp);
        }
    }
        

}

void mat_print(data mas){
    int id_cip=0;
    int id_pi=0;
    for (int i=0; i<mas.m;++i){
        int c=get_el(&mas.CIP, id_cip+1)-get_el(&mas.CIP, id_cip);
        int cnt_py=0;
        for (int j=0; j<mas.n; ++j){
            int point=0;
            if(cnt_py<c){
                if(get_el(&mas.PI, id_pi)==j){
                    printf("%d ", get_el(&mas.YE, id_pi));
                    id_pi++;
                    cnt_py++;
                } else{
                    printf("%d ", 0);
                }
            } else{
                printf("%d ", 0);
            }
        }
        printf("\n");
        id_cip++;
    }
}

data create_data(int m, int n){
    data mas;
    mas.m=m;
    mas.n=n;
    mas.count=0;
    init(&mas.CIP);
    init(&mas.PI);
    init(&mas.YE);
    set_size(&mas.CIP, START_SIZE);
    set_size(&mas.PI, START_SIZE);
    set_size(&mas.YE, START_SIZE);
    mas.k_cip=0;
    zero_input(&mas.PI, 0, START_SIZE);
    set_el(&mas.CIP, mas.k_cip,0);    
    for(int i=0; i<m;++i){
        for(int j=0;j<n;++j){
            int tmp;
            scanf("%d", &tmp);
            if(tmp!=0){
                set_el(&mas.YE, mas.count, tmp);
                set_el(&mas.PI, mas.count, j);
                mas.count++;
                if(mas.count>=START_SIZE){
                    set_size(&mas.PI, START_SIZE*2);
                    set_size(&mas.YE, START_SIZE*2);
                }
            }
        }
        if(mas.k_cip>=START_SIZE){
            set_size(&mas.CIP, START_SIZE*2);
        }
        set_el(&mas.CIP, i+1, mas.count);
        mas.k_cip++;
    }
    set_el(&mas.CIP, mas.k_cip+1, mas.count);
    mas.k_cip++;
    return mas;
    // printf(" Vector CIP: ");
    // veprint(&mas.CIP, 0, mas.k_cip);
    // printf("\n");
    // printf(" Vector PI: ");
    // veprint(&mas.PI, 0, mas.count);
    // printf("\n");
    // printf(" Vector YE: ");
    // veprint(&mas.YE, 0, mas.count);
}

bool is_exit(int c){
    if(c>='0' && c<='9'){
        return false;
    }
    return true;
}

int main(){
    int n,m;
    int c;
    printf("Enter matrix  A(m/n) size, or if you want to exit, press 'q'\n");
    printf("m = ");
    c=getchar();
    while(c!= EOF && c!='q'){
        // printf("Enter matrix  A(m/n) size, or if you want to exit, press 'q'\n");
        // printf("m = ");
        // c=getchar();
        data mas;
        if(is_exit(c)==false){
            ungetc(c, stdin);
            scanf("%d", &m);
            printf("n = ");
            scanf("%d", &n);
            mas=create_data(m, n);
            vec_print(mas);
            printf("\n");
            mat_print(mas);
            function(mas);
            printf("\n");
            mat_print(mas);
        } 
        printf("Enter matrix  A(m/n) size, or if you want to exit, press 'q'\n");
        printf("m = ");
        c=getchar();
    }
}

/*
0 0 1 2 0      
0 3 0 0 0       
0 0 0 0 0
4 5 0 0 0
0 0 6 0 0
*/
// 0 0 0 0 0
// 0 0 0 0 0
// 0 0 0 0 0
// 0 0 0 0 0
// 0 0 0 0 0

/*
0 0 0 4 0
0 3 0 5 0
1 0 0 0 6
2 0 0 0 0
0 0 0 0 0
*/

/*
1 0 0 0 0
0 2 0 0 0
0 0 3 0 0
0 0 0 4 0
0 0 0 0 5

*/
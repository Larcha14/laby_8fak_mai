#include "deque_double.h"
#define k 2
#define MIN_CAP 30

static bool increase(dq_double_dyn_mass *dq){
    int new_cap= dq->cap*k;
    if (new_cap<MIN_CAP){
        new_cap=MIN_CAP;
    }
    double *tmp=(double*)realloc(dq->buff, new_cap*sizeof(double));
    if(tmp==NULL){
        return false;
    }
    dq->buff=tmp;
    if(dq->tail<=dq->head && dq->size!=0){
        for(int i=0; i<dq->tail; ++i){
            dq->buff[dq->cap+i]=dq->buff[i];
        }
    }
    dq->cap=new_cap;
    return true;
}

static void decrease_if_possible(dq_double_dyn_mass *dq){
    if(dq->size<=dq->cap/(k*k)){
            
            int new_cap=dq->cap/k;
            if (new_cap<MIN_CAP){
                return;
            }
            if (new_cap<dq->cap && dq->size>0){
                int new_r =new_cap-1;
                if(dq->head>=new_r && (dq->tail>new_r || dq->tail==0) ){ // [  | ## ] + [  |## ] + [  | ##] -> [## | ]
                    for(int i=0; i<dq->size;++i){
                        dq->buff[i]=dq->buff[dq->head+i];
                    }
                    dq->head=0;
                    dq->tail=dq->size;
                }
                if(dq->head<new_r && dq->tail>new_r){ // [  #|#  ] -> [#  #| ]
                    for(int i=0; i<dq->tail-new_r-1;++i){
                        dq->buff[i]=dq->buff[new_r+1+i];
                    }
                    dq->tail=dq->tail-new_r-1;
                }
                if (dq->tail<new_r && dq->head>new_r){ // [#  |  #] -> [#  #| ]
                    for(int i=0; i<dq->head-dq->cap;++i){
                        dq->buff[new_r]=dq->buff[dq->cap-1-i];
                        new_r--;
                    }
                    new_r++;
                    dq->head=new_r;
                }
            }
            dq->buff=(double *)realloc(dq->buff, new_cap*sizeof(double));
            dq->cap=new_cap;
    }

}

void dq_init(dq_double_dyn_mass *dq){
    dq->buff = (double*)malloc(MIN_CAP* sizeof(double));
    dq->size=0;
    dq->head=0;
    dq->tail=0;
    dq->cap=MIN_CAP;
    increase(dq);
}

void dq_destroy(dq_double_dyn_mass *dq){
    dq->size=0;
    free(dq->buff);
    dq->cap=0;
    dq=NULL;

}

int dq_size(dq_double_dyn_mass *dq){
    return dq->size;
}

bool dq_is_empty(dq_double_dyn_mass *dq){
    return dq->size==0;
}

double dq_first(dq_double_dyn_mass *dq){
    return dq->buff[dq->head];
}

double dq_last(dq_double_dyn_mass *dq){
    return dq->buff[(dq->cap+ dq->tail-1)%dq->cap];
}

bool dq_push_back(dq_double_dyn_mass *dq, double val){
    if (dq->size>=dq->cap){
        printf("hu");
        if (!increase(dq)){
            return false;
        }
    }
    dq->buff[dq->tail]=val;
    dq->size++;
    dq->tail=(dq->tail+1)%(dq->cap+1);
    return true;
}

bool dq_push_front(dq_double_dyn_mass *dq, double val){
    if (dq->size>=dq->cap){
        if (!increase(dq)){
            return false;
        }
    }
    dq->head=(dq->cap+dq->head-1)%dq->cap;
    dq->buff[dq->head]=val;
    dq->size++;
    return true;
}

double dq_pop_back(dq_double_dyn_mass *dq){
    double val=dq->buff[(dq->cap+ dq->tail-1)%dq->cap];
    decrease_if_possible(dq);
    dq->size--;
    dq->tail=(dq->cap+ dq->tail-1)%dq->cap;
    return val;
}

double dq_pop_front(dq_double_dyn_mass *dq){
    double val= dq->buff[dq->head];
    decrease_if_possible(dq);
    dq->size--;
    dq->head=(dq->head+1)%dq->cap;
    return val;
}

// int main(){
//     int n=34;
//     dq_double_dyn_mass dq;
//     dq_double_dyn_mass *dqu =&dq;
//     dq_init(dqu);
//     for(int i=0;i<n;++i){
//         dq_push_back(dqu, i);
//     }
//     printf("\n");
//     printf("%d ", dq_size(dqu));
//     printf("\n");
//     for (int i=0; i<10; ++i){
//         printf("%lf ", dq_pop_back(dqu));
//         printf("%lf ", dq_pop_front(dqu));
//         printf("\n");
//     }
//     printf("%lf - last;  %lf - first\n", dq_last(dqu), dq_first(dqu) );
//     dq_destroy(&dq);
//     printf("%d", dq_first(dqu));

// }
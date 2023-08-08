#include "sorting.h"

typedef struct datas{
    char key[3];
    char str[2];
}datas;

static void swap(int a, int b, data arr[]){
    data tmp;
    tmp=arr[a];
    arr[a]=arr[b];
    arr[b]=tmp;
}

void shaker_sort(data arr[], int size){
    int l=1, r=size-1;
    int status=1;
    while(l<r && status==1){
        status=0;
        for(int i=l; i<r; ++i){
            if(strcmp(arr[i].key, arr[i+1].key)>0){
                swap(i, i+1, arr);
                status=1;
            }
        }
        r--;
        for(int i=r; i>l; --i){
            if(strcmp(arr[i-1].key, arr[i].key)>0){
                swap(i, i-1, arr);
                status=1;
            }
        }
        l++;
    }
}

// int main(){
//     struct datas arr[5];
//     datas tmp1, tmp2, tmp3, tmp4, tmp0;
//     strcpy(tmp1.key, "aa");
//     strcpy(tmp1.str, "1");
//     strcpy(tmp2.key, "ab");
//     strcpy(tmp2.str, "2");
//     strcpy(tmp3.key, "ba");
//     strcpy(tmp3.str, "3");
//     strcpy(tmp4.key, "bb");
//     strcpy(tmp4.str, "4");
//     arr[3]=tmp1;
//     arr[1]=tmp2;
//     arr[4]=tmp3;
//     arr[2]=tmp4;
//     arr[0]=tmp0;
//     for (int i=0; i<5;++i){
//         printf("%s - %s| ", arr[i].key, arr[i]. str);
//     }
//     printf("\n");
//     shaker_sort(arr, 5);    
//     for (int i=0; i<5;++i){
//         printf("%s - %s| ", arr[i].key, arr[i]. str);
//     }


    
// }
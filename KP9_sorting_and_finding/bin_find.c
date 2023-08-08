#include "bin_find.h"

int bin_search(data arr[], char request[7], int size){
    int l=1, r=size-1;
    int mid;
    int answ=-1;
    while(l<=r){
        mid=(l+r)/2;
        int cmp=strcmp(arr[mid].key, request);
        if(cmp==0){
            answ=mid;
        }
        if(cmp<0){
            l=mid+1;
        } else{
            r=mid-1;;
        }

    }
    return answ;
}
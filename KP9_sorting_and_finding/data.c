#include "data.h"

int line_counter(char *arg){
    int cnt=0;
    FILE *tmp=fopen(arg, "r");
    while (!feof(tmp)){
        fscanf(tmp, "%*[^\n]%*c");
        cnt++;
    }
    fclose(tmp);
    return cnt;

}

void text_print(data arr[], int size){
    printf("Keys  |");
    printf(" Strings\n");
    for(int i=1; i<size;++i){
        printf("%s | %s\n", arr[i].key, arr[i].str);
    }
}

void merge(FILE* lines, FILE* keys, data arr[]){
    fseek(lines, 0, SEEK_SET);
    fseek(keys, 0, SEEK_SET);
    data tmp;
    int i=1; //!!!
    while (fscanf(lines, "%s", tmp.str)!=EOF && fscanf(keys, "%s", tmp.key)!=EOF){
        arr[i]=tmp;
        i++;
    }
    
}

void reverse_data(FILE* lines, FILE* keys, data arr[], int size){
    fseek(lines, 0, SEEK_SET);
    fseek(keys, 0, SEEK_SET);
    data tmp;
    struct data copy[size];
    merge(lines, keys, copy);
    for(int i=0; i<size; ++i){
        arr[i]=copy[size-i];
    }

}

void random_data(FILE* lines, FILE* keys, data arr[], int size){
    fseek(lines, 0, SEEK_SET);
    fseek(keys, 0, SEEK_SET);
    data tmp;
    struct data copy[size];
    merge(lines, keys, copy);
    int rd_count[size];
    int rd_order[size];
    rd_order[0]=-1;
    rd_count[0]=1;
    for(int i=1; i<size;++i){
        rd_count[i]=0;
    }
    srand(time(NULL));
    for(int i=1; i<size;++i){
        int r=1 +rand()%size;
        while(1){
            if(rd_count[r]==0){
                rd_count[r]=1;
                rd_order[i]=r;
                break;
            } else{
                r=1 +rand()%size;
            }
        }
    }
    // for(int i=1; i<size;++i){
    //     printf("%d ", rd_order[i]);
        
    // }
    // printf("\n");
    // for(int i=0; i<size;++i){
    //     printf("%d ", rd_count[i]);
        
    // }
    for(int i=1; i<size; ++i){
        arr[i]=copy[rd_order[i]];
    }
}
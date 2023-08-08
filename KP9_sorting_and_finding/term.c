#include "data.h"
#include "sorting.h"
#include "bin_find.h"

//Запуск: первый - строки, 2 - ключи 3 - программа

int main(int argc, char* argv[]){
    if (argc != 4){
        fprintf(stderr, "Error! Uncorrect input");
        return 1;
    }
    FILE* lines = fopen(argv[1], "r");
    FILE* key = fopen(argv[2], "r");
    if (lines==NULL){
        fprintf(stderr, "Error! There is no file with strings");
        return 2;
    }
    if (key==NULL){
        fprintf(stderr, "Error! There is no file with keys");
        return 3;
    }
    int size=line_counter(argv[1]);
    if(size<=1){
        fprintf(stderr, "Error! File is empty");
        return 4;
    }
    struct data origin[size+1];
    if(strcmp( argv[3], "n")==0){ //normal 
        // struct data origin[size+1];
        merge(lines, key, origin);
        text_print(origin, size);
        printf("\n");
        shaker_sort(origin,size-1);    
        text_print(origin, size);
    } else if(strcmp( argv[3], "r")==0){ // reverse
        // struct data reverse[size];
        reverse_data(lines, key, origin, size);
        text_print(origin, size);
        printf("\n");
        shaker_sort(origin, size);
        text_print(origin, size);

    }else if(strcmp( argv[3], "c")==0){ // chaos
        // struct data random[size+1];
        random_data(lines, key, origin, size);
        text_print(origin, size);
        printf("\n");
        shaker_sort(origin, size);
        text_print(origin, size);
    } else{
        fprintf(stderr, "Error! uncorrect command");
        return 5;
    }
    printf("\n\n Enter key that you want to find\n");
    char request[90];
    int c;
    c=getchar();
    while(c!=EOF){
        ungetc(c, stdin);
        scanf("%s", request);
        printf("\nYour key is '%s' \n", request);
        int res_search=bin_search(origin, request, size+1);
        if(res_search!=-1){
            printf("The result of the search is '%s', string  %s\n", origin[res_search].key, origin[res_search].str);
        }else{
            printf("There is no '%s' in this file\n", request);
        }
        printf("\n\n Enter key that you want to find\n");
        c=getchar();
    }
    scanf("%s", request);
    // printf("%d\n",sizeof(request) );
    // if(sizeof(request)>7){
    //     printf("It's to long request");
    // }
    // printf("\nYour key is '%s' \n", request);
    // int res_search=bin_search(origin, request, size+1);
    // if(res_search!=-1){
    //     printf("The result of the search is '%s', string  %s\n", origin[res_search].key, origin[res_search].str);
    // }else{
    //     printf("There is no '%s' in this file\n", request);
    // }
    // char trash[200];
    // scanf("%s", trash);
    
}    

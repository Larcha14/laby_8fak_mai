#include <stdio.h>
#include <stdlib.h>
#include "flights.h"

int line_counter(FILE* tmp){
    int cnt=0;
    fseek(tmp, 0, SEEK_SET);
    while (!feof(tmp)){
        fscanf(tmp, "%*[^\n]%*c");
        cnt++;
    }
    return cnt;

}

static void no_val_print(char* arr[], int size){
    char str[]="No_val";
    for (int i=0; i< size; ++i){
        arr[i]=(char*)malloc(21);
        strcpy(arr[i], "No_val");
    }
}

void line_print(flights fl){
    printf("%s\t", fl.sername);
    printf("%s\t", fl.initials);
    printf("%s ", fl.sex);
    printf("%s\t", fl.baggage);
    printf("%s ", fl.company);
    printf("%s ", fl.flight);
    printf("%s ", fl.date);
    printf("%s ", fl.time);
    printf("%s ", fl.from);
    printf("%s ", fl.to);
    printf("\n");
}

void t_print(FILE* f){
    flights fl;
    int cnt=1;
    fseek(f,0, SEEK_SET);
    for(int i=0; i<N; ++i){
        printf(" %s |", names[i]);
    }
    printf("\n");
    while(fread(&fl, sizeof(flights), 1, f)){
        printf("%d) ", cnt);
        line_print(fl);
        cnt++;
    }
}

void create_dictionary(const int size, int &cnt, char *arr[], char tmp[]){
    for(int i=0;i<=size;++i){
        if (strcmp(arr[i], "No_val")==0){
            strcpy(arr[i], tmp);
            cnt++;
            return;
        } else if(strcmp(arr[i], tmp)==0){
            return;
        } 
    }
}

void interest(FILE* f){
    // FILE* f=fopen(arg, "rb");
    fseek(f,0, SEEK_SET);
    printf("Enter number of interesting column for you\n");
    for(int i=2; i<N; ++i){
        printf("%d)%s ",i-1, names[i]);
    }
    printf("\n");
    int request;
    flights fl;
    scanf("%d", &request);
    if (request==1){
        printf("Choose 1)M or 2)F\n");
        scanf("%d", &request);
        while(fread(&fl, sizeof(flights), 1, f)){
            if(request==1 && strcmp(fl.sex, "M")==0){
                line_print(fl);
            } else if( request==2 && strcmp(fl.sex, "F")==0){
                line_print(fl);
            }
        }
    } else if(request==2){
        printf("Choose 1)YES or 2)NO\n");
        scanf("%d", &request);
        while(fread(&fl, sizeof(flights), 1, f)){
            if(request==1 && strcmp(fl.baggage, "YES")==0){
                line_print(fl);
            } else if( request==2 && strcmp(fl.baggage, "NO")==0){
                line_print(fl);
            }
        }
    } else if(request==3){
        printf("Choose ");
        fseek(f,0, SEEK_SET);
        int size=0;
        no_val_print(Air_company, SIZE);
        while(fread(&fl, sizeof(flights), 1, f)){
            char tmp[21];
            strcpy(tmp, fl.company);
            create_dictionary(SIZE, size, Air_company, tmp);
        }
        // printf("%d ,", size);
        for(int i=0; i<size; ++i){
            printf("%d) %s  ",i+1, Air_company[i]);
        }
        printf("\n");
        scanf("%d", &request);
        char search[21];
        strcpy(search, Air_company[request-1]);
        fseek(f,0, SEEK_SET);
        while(fread(&fl, sizeof(flights), 1, f)){
            if(strcmp(fl.company, search)==0){
                line_print(fl);
            } 
        }
    }else if(request==4){
        printf("Choose ");
        fseek(f,0, SEEK_SET);
        int size=0;
        no_val_print(Flight, SIZE);
        while(fread(&fl, sizeof(flights), 1, f)){
            char tmp[9];
            strcpy(tmp, fl.flight);
            create_dictionary(SIZE, size, Flight, tmp);
        }
        // printf("%d ,", size);
        for(int i=0; i<size; ++i){
            printf("%d) %s  ",i+1, Flight[i]);
        }
        printf("\n");
        scanf("%d", &request);
        char search[9];
        strcpy(search, Flight[request-1]);
        fseek(f,0, SEEK_SET);
        while(fread(&fl, sizeof(flights), 1, f)){
            if(strcmp(fl.flight, search)==0){
                line_print(fl);
            } 
        }

    }else if(request==5){
        printf("Choose ");
        fseek(f,0, SEEK_SET);
        int size=0;
        no_val_print(Dates, SIZE);
        while(fread(&fl, sizeof(flights), 1, f)){
            char tmp[10];
            strcpy(tmp, fl.date);
            create_dictionary(SIZE, size, Dates, tmp);
        }
        // printf("%d ,", size);
        for(int i=0; i<size; ++i){
            printf("%d) %s  ",i+1, Dates[i]);
        }
        printf("\n");
        scanf("%d", &request);
        char search[10];
        strcpy(search, Dates[request-1]);
        fseek(f,0, SEEK_SET);
        while(fread(&fl, sizeof(flights), 1, f)){
            if(strcmp(fl.date, search)==0){
                line_print(fl);
            } 
        }
    }else if(request==6){
        printf("Choose ");
        fseek(f,0, SEEK_SET);
        int size=0;
        no_val_print(Times, SIZE);
        while(fread(&fl, sizeof(flights), 1, f)){
            char tmp[10];
            strcpy(tmp, fl.time);
            create_dictionary(SIZE, size, Times, tmp);
        }
        // printf("%d ,", size);
        for(int i=0; i<size; ++i){
            printf("%d) %s  ",i+1, Times[i]);
        }
        printf("\n");
        scanf("%d", &request);
        char search[10];
        strcpy(search, Times[request-1]);
        fseek(f,0, SEEK_SET);
        while(fread(&fl, sizeof(flights), 1, f)){
            if(strcmp(fl.time, search)==0){
                line_print(fl);
            } 
        }
    }else if(request==7){
        printf("Choose ");
        fseek(f,0, SEEK_SET);
        int size=0;
        no_val_print(From, SIZE);
        while(fread(&fl, sizeof(flights), 1, f)){
            char tmp[10];
            strcpy(tmp, fl.from);
            create_dictionary(SIZE, size, From, tmp);
        }
        // printf("%d ,", size);
        for(int i=0; i<size; ++i){
            printf("%d) %s  ",i+1, From[i]);
        }
        printf("\n");
        scanf("%d", &request);
        char search[10];
        strcpy(search, From[request-1]);
        fseek(f,0, SEEK_SET);
        while(fread(&fl, sizeof(flights), 1, f)){
            if(strcmp(fl.from, search)==0){
                line_print(fl);
            } 
        }
    }else if(request==8){
        printf("Choose ");
        fseek(f,0, SEEK_SET);
        int size=0;
        no_val_print(To, SIZE);
        while(fread(&fl, sizeof(flights), 1, f)){
            char tmp[10];
            strcpy(tmp, fl.to);
            create_dictionary(SIZE, size, To, tmp);
        }
        // printf("%d ,", size);
        for(int i=0; i<size; ++i){
            printf("%d) %s  ",i+1, To[i]);
        }
        printf("\n");
        scanf("%d", &request);
        char search[10];
        strcpy(search, To[request-1]);
        fseek(f,0, SEEK_SET);
        while(fread(&fl, sizeof(flights), 1, f)){
            if(strcmp(fl.to, search)==0){
                line_print(fl);
            } 
        }
    }else {
        printf("Uncorrect input. Try again");
    }

}

void counting(FILE* f){
    t_print(f);
    fseek(f,0, SEEK_SET);
    printf("\nIn this program you can choose line and it will be output flight at this day from this city\n");
    printf("Enter interesting string\n");
    int request;
    flights fl;
    scanf("%d", &request);
    fseek(f, sizeof(flights)*(request-1), SEEK_SET);
    fread(&fl, sizeof(flights), 1, f);
    line_print(fl);
    fseek(f,0, SEEK_SET);
    flights tmp;
    while(fread(&tmp, sizeof(flights), 1, f)){
        if(strcmp(tmp.from, fl.to)==0 &&strcmp(tmp.date, fl.date)==0){
            printf("%s %s %s %s %s %s", tmp.company, tmp.flight, tmp.date, tmp.time, tmp.from, tmp.to );
        }
    }


}

int main(int argc, char* argv[]){
    if (argc != 3){
        fprintf(stderr, "Error! Uncorrect input");
        return 1;
    }
    FILE* input = fopen(argv[1], "rb");
    if (input==NULL){
        fprintf(stderr, "Error! There is no input file");
        return 2;
    }
    char* c=argv[2];
    if(strcmp(c, "p")==0){
        t_print(input);
    } else if(strcmp(c, "i")==0){
        interest(input);
    } else if(strcmp(c, "c")==0){
        counting(input);
    } else {
        printf("Uncorrect input. Try again");

    }
    printf("\n");
    fclose(input);
    return 0;

}
// p - печатает файл; i - узнает информацию о файле; с - интересное задание!


#include <stdio.h>
#include "flights.h"

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

int main(int argc, char *argv[]){
    if (argc != 3){
        fprintf(stderr, "Error! Uncorrect input");
        return 1;
    }
    FILE* input = fopen(argv[1], "rw");
    FILE* output = fopen(argv[2], "wb");
    if (input==NULL){
        fprintf(stderr, "Error! There is no input file");
        return 2;
    }
    if (output==NULL){
        fprintf(stderr, "Error! There is no output file");
        return 3;
    }
    int count= line_counter(argv[1]);
    if(count<=1){
        fprintf(stderr, "Error! There is empty txt-file");
        return 4;
    }
    printf("counts = %d \n", count);
    flights fl;
    while(fscanf(input, "%s%s%s%s%s%s%s%s%s%s", fl.sername, fl.initials, fl.sex, fl.baggage, fl.company, fl.flight, fl.date, fl.time, fl.from, fl.to)!=EOF){
        fwrite(&fl, sizeof(flights), 1, output);
    }
    fclose(input);
    fclose(output);
    return 0;
}

//Фамилия	инициалы	пол	багаж	Авиакомпания		Рейс	Дата		Время	Откуда	Куда
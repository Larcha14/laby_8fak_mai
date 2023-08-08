//27
#include <stdio.h>

typedef unsigned long long int set;

const int aa = 1072, ya = 1103, A = 1040, YA = 1071;
const int  ee= 1105, EE = 1025, e= 1077, E= 1045, J=1046, j=1078;
const int I = 1048, O = 1054, U = 1059, YI = 1067, JE = 1069, YU = 1070;
const int i=1080, o=1086,u=1091,yi=1099,je=1101,yu=1102;
//aa - "а", e - "е", j - "ж", ja - "я", ee - "ё", o - "о", u - "у", je - "э", yi - "ы", i - "и", yu - "ю"

int index_number(int c){
    if (c>=aa && c<=e){
        return c-aa;
    } else if(c==ee || c==EE){
        return 6;
    } else if (c>=j && c<=ya){
        return c-aa+1;
    } else if(c>=A && c<=E){
        return c-A;
    } else if(c>=J && c<=YA){
        return c-A+1;
    }
}

int is_space(int c){
    return (c== ' ') || (c==',') || (c=='\t') || (c=='\n') ||(c=='.')||(c==EOF);
}


int utf8_get_num() {
    int c=getchar();
    int c1 = c, num_of_cp = 0;
    
    if (c < 0x80) {
        return c;               
    }

    while (c1) {
        if (c1 % 2) {
            num_of_cp++;
        } else {
            num_of_cp = 0;
        }
        c1 >>= 1;
    }

    if (num_of_cp== 2) {
        c -= 0xc0;
    } else if (num_of_cp == 3) {
        c -= 0xe0;
    } else if (num_of_cp == 4) {
        c -= 0xf0;
    }
    for(int i = 1; i < num_of_cp; i++) {
        int c2 = getchar() - 0x80;
        c <<= 6;
        c |= c2;
    }
    return c;
}

int main(){
    int count_Word=0;
    int c;
    int cond=0;
    set Word_Now=0;
    set Rus_vowels = ((set)1)<<(index_number(aa)) | ((set)1)<<(index_number(ya)) |((set)1)<<(index_number(ee)) |
    ((set)1)<<(index_number(e)) |((set)1)<<(index_number(i)) |((set)1)<<(index_number(o)) |
    ((set)1)<<(index_number(u)) |((set)1)<<(index_number(yi)) |((set)1)<<(index_number(je)) |((set)1)<<(index_number(yu));
    do{
        c=utf8_get_num();
        if (is_space(c)){;
            if ((Word_Now|Rus_vowels)==Word_Now){
                printf("JA-JA \n");
                cond=1;
                break;
            } 
            Word_Now=0;
        } else{
            //if ((((set)1) <<index_number(c))|Rus_vowels==((set)1) <<index_number(c)){
                Word_Now = Word_Now | (((set)1) <<index_number(c));
            //}

        }
        

    } while (c!= EOF);
    
    if (cond ==0){
        printf("NEIN!!! \n");
    } 
}
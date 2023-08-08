//27
#include <stdio.h>

typedef unsigned long long int set;

//#define vowel =(set)<<('a'-'a') | (set)<<('a'-'a')

const set ENG_vowels = ((set)1)<<('a'-'a') | ((set)1)<<('e'-'a')  
|((set)1)<<('i'-'a')|((set)1)<<('o'-'a')|((set)1)<<('u'-'a')|((set)1)<<('y'-'a');

set is_space(set c){
    return (c== ' ') || (c==',') || (c=='\t') || (c=='\n') ||(c=='.');
}

set is_Eng_vowel(set a){
    return (a=='a'|| a=='e'|| a=='i'|| a=='u'|| a=='o'||a=='y');
}
set is_Eng_vowel_UP(set a){
    return (a=='A'|| a=='E'|| a=='I'|| a=='U'|| a=='O'||a=='Y');
}

set Eng_vowel_to_UP(set a){
    if (a=='A'){
        return a='a';
    } else if(a=='E'){
        return a='e';
    } else if (a=='I'){
        return a='i';
    } else if(a=='U'){
        return a='u';
    } else if(a=='O'){
        return a='o';
    } else if(a=='Y'){
        return a='y';
    }
}

int main(){
    int count_Word=0;
    set c=getchar();
    int cond=0;
    set Word_Now=0;
    while (c!=EOF){
        if (is_space(c)){;
            if (Word_Now==ENG_vowels){
                printf("JA-JA \n");
                cond=1;
                break;
            } 
            Word_Now=0;
        } else{
            if (is_Eng_vowel(c)){
                Word_Now = Word_Now | (((set)1) <<(c-'a'));
            } else if(is_Eng_vowel_UP(c)){
                c=Eng_vowel_to_UP(c); 
                Word_Now = Word_Now | (((set)1) <<(c-'a'));
            }

        }
        c=getchar();

    }
    if (Word_Now==ENG_vowels){
                printf("JA-JA Vygoda tvoya \n");
                cond=1;
    } 
    if (cond ==0){
        printf("NEIN!!! \n");
    } 
}
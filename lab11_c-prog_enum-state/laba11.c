#include <stdio.h>

enum State{
    WHAT_SYMBLE,
    IF_LETTER_UP,
    IF_LETTER_DOWN,
    IF_IS_SPACE,
    OTHER,
};

enum State s = WHAT_SYMBLE;

int is_space(int c){
    return (c== ' ') || (c==',') || (c=='\t') || (c=='\n');
}

int main(){
    int c, n;
    n=0;
    c=getchar();
    while (c!=EOF){
        switch (s){
            case WHAT_SYMBLE:
                if ((c>='a') && (c<='z')){
                    s=IF_LETTER_DOWN;
                } else if(is_space(c)){
                    s=IF_IS_SPACE;
                } else if ((c>='A') && (c<='Z')){
                    s=IF_LETTER_UP;
                } else{
                    s=OTHER;
                }
                break;
            default:
                break;
        }
        switch (s) {
            case IF_LETTER_DOWN:             
                printf("%c", (char)('a'+(c-'a'+3+n)%26));
                s=WHAT_SYMBLE;
                n+=1;
                break;
            case IF_LETTER_UP:             
                printf("%c", (char)('A'+(c-'A'+3+n)%26));
                s=WHAT_SYMBLE;
                n+=1;
                break;
            case OTHER:
                printf("%c", (char)(c));
                s=WHAT_SYMBLE;
                break;
            case IF_IS_SPACE:
                printf("%c", (char)(c));
                s=WHAT_SYMBLE;
                n=0;
                break;
            default:
                break;

        }
        c=getchar();
    }

}
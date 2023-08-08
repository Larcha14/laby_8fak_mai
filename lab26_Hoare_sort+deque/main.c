#include <stdio.h>
#include "sort_Hor.h"
// #include "deque_double.h"

// enum State{
//     WHAT_SYMBLE,
//     INPUTTING,
//     END_INPUT,
// };
// enum State s =WHAT_SYMBLE;

int main(){
    int n;
    dq_double_dyn_mass dq;
    dq_init(&dq);
    printf("Сортировка Хоара с использованием Дэка. Ларченко Арсений\n");
    printf("Введите в строчку исходный массив\n");
    int c;
    double t;
    // c=getchar();
    // while(c!=EOF){
    //     switch(s){
    //         case WHAT_SYMBLE:
    //             if(c==' ' || c='\t'){
    //                 c=getchar();
    //                 s=WHAT_SYMBLE;
    //             } else if(c=='\n'){
    //                 s=END_INPUT;
    //             } else if(c>='0' && c<='9'){
    //                 ungetc(c, stdin);
    //                 s=INPUTTING;
    //             } else{
    //                 c=getchar();
    //                 s=WHAT_SYMBLE;
    //             }
    //             break;
    //         default:
    //             break;
    //     }
    //     switch(s){
    //         case INPUTTING:
    //             scanf("%lf", &t);
    //             dq_push_back(&dq, t);
    //             s=INPUTTING;
    //             break;
    //         case END_INPUT:

    //     }
    // }

    while(1 == scanf("%lf", &t)){
        dq_push_back(&dq, t);
    }
    printf("\nОтсортированный дэк:\n");
    sort_hoar(&dq, dq_size(&dq));
    print_dq(&dq);
    printf("\n");
    dq_destroy(&dq);
}
//номер 8
#include "Tree_OV.h"
#include "term.h"

enum State s = WHAT_SYMBLE;

int main(){
    printf("23 лаба, номер 8, разработчик Ларченко Арсений\n");
    printf("Приветствуем в онлайн терминале по работе с деревьями общего вида! Чтобы просмотреть список функций введите -h \n\n");
    int c;
    tree_ov t=empty_tree();
    c=getchar();
    int tryc;
    int num=0;
    int Error_int=0;
    char st[15];
    char path[100];
    while(c!=EOF){
        switch(s){
            case WHAT_SYMBLE:
                if (c=='-'){
                    s=IF_COMMAND;
                } else if(is_space(c)){
                    s=IS_SPACE;
                } else{
                    s=OTHER;
                }
                break;
            default:
                break;
        }
        switch(s){
            case IF_COMMAND:
                c=getchar();
                if (c=='h'){
                    command_list();
                    s=WHAT_SYMBLE;
                } else if(c=='i'){
                    s=I_COMMAND;
                } else if(c=='d'){
                    s=D_COMMAND;
                } else if(c=='p'){
                    s=P_COMMAND;
                } else if (c=='f'){
                    s=F_COMMAND;
                } else if(c=='n'){
                    print_enum_reference();
                    s=WHAT_SYMBLE;
                } else if(c=='c'){
                    s=C_COMMAND;
                } else {
                    Error_int=2; // Error 2
                    s=TRASH; 
                }
                break;
            case IS_SPACE:
                s=WHAT_SYMBLE;
                break;
            case OTHER:
                s=TRASH;
                Error_int=1; //Error 1
                break;
            default:
                break;
        }
        switch(s){
            case I_COMMAND:
                c=getchar();
                if(c!=' '){
                    Error_int=2; //Error 2
                    s=TRASH;
                    break;
                }
                tryc=getchar();
                if (tryc>='0' && tryc<='9'){
                    ungetc(tryc, stdin);
                    scanf("%d", &num);
                } else if(tryc>='A' && tryc<='Z'){
                    ungetc(tryc, stdin);
                    scanf("%s", st);
                    // printf("%s \n", st);
                    num=get_int_enum(st);
                }
                if (!is_empty(t)){
                    Error_list(3); // Error 3
                    s=WHAT_SYMBLE;
                    break;
                } 
                if(num>0 && num<clubs_count){
                    t=create_tree((enum clubs)(num));
                    Info_list(1);
                    s=WHAT_SYMBLE;
                    break;
                } else{
                    Error_list(4); //Error 4
                    s=WHAT_SYMBLE;
                    break;
                }
                Error_int=1;
                s=TRASH;
                break;
            case C_COMMAND: 
                c=getchar();
                if(c!=' '){
                    Error_int=2;
                    s=TRASH;
                    break;
                }
                tryc=getchar();
                if (tryc>='0' && tryc<='9'){
                    ungetc(tryc, stdin);
                    scanf("%d", &num);
                } else if(tryc>='A' && tryc<='Z'){
                    ungetc(tryc, stdin);
                    scanf("%s", st);
                    // printf("%s \n", st);
                    num=get_int_enum(st);
                }
                if(num>0 && num<clubs_count){
                    c=getchar();
                    if(c!=' '){
                        Error_int=2;
                        s=TRASH;
                        break;
                    }
                    scanf("%s", path);
                    // printf("%s \n", path);
                    if (!add_node(t,(enum clubs)(num), path)){
                        Error_list(5);
                        s=WHAT_SYMBLE;
                        break;
                    }
                    Info_list(5);
                    s=WHAT_SYMBLE;
                    break;
                } else{
                    Error_int=4; //Error 4
                    s=TRASH;
                    break;
                }
                Error_int=1;
                s=TRASH;
                break;
            case D_COMMAND: // исправить
                char path[100];
                scanf("%s", path);
                if (is_empty(t)){
                    Error_list(6);
                    s=WHAT_SYMBLE;
                    break;
                } 
                if(!delete_node(&t, path)){
                    Error_list(5);
                } else{
                    Info_list(2);
                }
                s=WHAT_SYMBLE;
                break;
            case P_COMMAND:
                Info_list(3);
                draw_tree(t, 0);
                printf("\n");
                s=WHAT_SYMBLE;
                break;
            case F_COMMAND:
                if (is_empty(t)){
                    Error_int=7; //Error 7
                    s=TRASH;
                    break;
                } 
                Info_list(4);
                printf("%d\n", function(t,0));
                s=WHAT_SYMBLE;
                break;
            case TRASH:
                Error_list(Error_int);
                c=getchar();
                if(is_space(c)){
                    s=WHAT_SYMBLE;
                    break;
                }
                char shit[100];
                scanf("%s", shit);
                // free(shit);
                s=WHAT_SYMBLE;
                break;
            default:
                break;

        }
        num=0;
        c=getchar();
        num=0;
    }
} 


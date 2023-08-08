#include "Tree_OV.h"

static tree_ov* get_node(tree_ov *t, char* path){
    if(path[0]=='k' || path[0]=='\0'){
        return t; 
    } else if(path[0]=='c'&&(*t)->first_child!=NULL){
        return get_node(&(*t)->first_child, path+1);
    }else if(path[0]=='b'&&(*t)->main_bro!=NULL){
        return get_node(&(*t)->main_bro, path+1);
    }else{
        return NULL;
    }
}

tree_ov empty_tree(){
    node* new_tree=(node*)malloc(sizeof(node));
    new_tree->first_child=NULL;
    new_tree->main_bro=NULL;
    new_tree->val=No_val;
    return new_tree;
}

tree_ov create_tree(clubs val){
    tree_ov new_tree=empty_tree();
    new_tree->val=val;
    // printf("%d\n", new_tree->val);
    return new_tree;
}

bool is_empty(tree_ov t){
    return t->val==No_val;
}


bool add_node(tree_ov t, clubs val, char* path){
    if(is_empty(t)){
        t=create_tree(val);
        // printf("%d\n", t->val);
        return true;
    }

    tree_ov* cur_node_adr= get_node(&t, path);
    if (cur_node_adr==NULL){
        return false;
    }
    tree_ov cur_node=(*cur_node_adr);
    tree_ov new_node=create_tree(val);
    if(cur_node->first_child==NULL){
        cur_node->first_child=new_node;
        
    }else{
        tree_ov bro1 =cur_node->first_child;
        tree_ov bro2=bro1->main_bro;
        while(bro2!=NULL){
            bro1=bro2;
            bro2=bro1->main_bro;
        }
        // printf("%d===", val);
        (bro1)->main_bro=new_node;
    }
    return true;
    
}

void draw_tree(tree_ov t, int depth){

    if(t==NULL ){
        
        return;
    }
    for(int i=0; i<depth; ++i){
        printf("|============");
    }
    printf("%s \n", enum_name[t->val]);
    draw_tree(t->first_child, depth+1);
    draw_tree(t->main_bro, depth);
}

static int max(int a, int b){
    if (a>b){
        return a;
    } else{
        return b;
    }
}

int depth(tree_ov t){
    if(t==NULL){
        return 0;
    }
    return max(depth(t->main_bro), (1+depth(t->first_child)));
}

static void destroy(tree_ov* t){
    if((*t)==NULL){
        free(*t);
        return;
    }
    destroy(&(*t)->first_child);
    destroy(&(*t)->main_bro);

    // free(*t);
}


bool delete_node(tree_ov* t, char* path){ // дописать
    int len_char=strlen(path);
    tree_ov* tmp;
    if (path[0]<1 || path[0]=='k'){
        destroy(t);
        tree_ov new_t=empty_tree();
        *t=&(*new_t);
        return true;
    }
    char last_symb=path[len_char-1]; 
    for (int i=0; i<len_char-1;++i){
        char p=(path+i)[0];
        if(p=='c'&&(*t)->first_child!=NULL){
            t=&(*t)->first_child;
        } else if( p=='b'&&(*t)->main_bro!=NULL){
            t=&(*t)->main_bro;
        } else {
            return false;
        }
    }  
    if (last_symb=='c'){
        if((*t)->first_child==NULL){
            return false;
        }
        tmp=&(*t)->first_child;
        printf("\n0000 %d 0000\n", (*tmp)->val);
        if((*tmp)->main_bro==NULL){
            (*t)->first_child=NULL;
            destroy(tmp);
        } else {
            (*t)->first_child=(*tmp)->main_bro;
            destroy(tmp);

        }
    } else if(last_symb=='b'){
        if((*t)->main_bro==NULL){
            return false;
        }
        tmp=&(*t)->main_bro;
        if(&(*tmp)->main_bro==NULL){
            (*t)->main_bro=NULL;
            destroy(tmp);
        } else {
            (*t)->main_bro=(*tmp)->main_bro;
            destroy(tmp);

        }
        
    } else {
        return false;
    }
    return true;
}

tree_ov build_tree(tree_ov bro, tree_ov child, clubs val){
    tree_ov new_tree =empty_tree();
    new_tree->main_bro=bro;
    new_tree->first_child=child;
    new_tree->val;
    return new_tree;
}


static int bro_count(tree_ov t){
    tree_ov cur =t->first_child;
    int n=0;
    while(cur!=NULL){
        n++;
        cur=cur->main_bro;
    }
    return n;
}

int function(tree_ov t, int count){
    if (t==NULL || t->val==0){
        return 0;
    }
    if(t->val==bro_count(t)){
        count++;
    }    
    count+=function(t->main_bro, 0);
    count+=function(t->first_child, 0);
    return count;
}

char* enum_name[]= {"No_val", "CSKA", "Krasnodar", "Tushino101", "Real", "Barcelona", "Atletico", "Hueska", "Bavariya", "Borussiya", "Union", "Anderlecht", 
    "Liverpool", "Arsenal", "Chelsea", "Lester", "Man_City", "Man_United", "Redding", "Fulham",
    "Sporting", "Inter", "Milan", "Roma", "Juventus", "Parma", "Fiorentina", "Lazzio", "Gamburg", 
    "Benfika", "Lokomotiv", "Dynamo", "Swansea", "Arrarat", "Smolevichi"};


// int main(){
//     printf("Приветствуем в онлайн терминале по работе с деревьями общего вида, чтобы просмотреть список функций введите -h \n");
//     tree_ov t=create_tree(Arsenal);
//     // printf("%d\n", t->val);
//     // draw_tree(t, 0);
//     // printf("%d\n", t->val);
//     add_node(t, Smolevichi, "k");
//     add_node(t, CSKA, "c");
//     add_node(t, Krasnodar, "cc");
//     add_node(t, Real, "c");
//     add_node(t, Barcelona, "c");
//     add_node(t, Barcelona, "ccb");
//     draw_tree(t, 0);
//     printf("000000000000000000\n");
//     // printf("func %d", function(t, 0));
//     delete_node(&t, "ccb");
//     draw_tree(t,0);
// }


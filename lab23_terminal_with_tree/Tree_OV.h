#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define clubs_count 35

extern char* enum_name[clubs_count];

typedef enum clubs{
    No_val, CSKA, Krasnodar, Tushino101, Real, Barcelona, Atletico, Hueska, Bavariya, Borussiya, Union, Anderlecht, 
    Liverpool, Arsenal, Chelsea, Lester, Man_City, Man_United, Redding, Fulham,
    Sporting, Inter, Milan, Roma, Juventus, Parma, Fiorentina, Lazzio, Gamburg, 
    Benfika, Lokomotiv, Dynamo, Swansea, Arrarat, Smolevichi
}clubs;


typedef struct node node;
typedef node* tree_ov;
struct node{
    clubs val;
    node* main_bro;
    node* first_child;
};

tree_ov create_tree(clubs val);
bool is_empty(tree_ov t);
tree_ov empty_tree();
bool add_node(tree_ov t, clubs val, char* path);
bool delete_node(tree_ov* t, char* path); //add *
void draw_tree(tree_ov t, int depth);
int depth(tree_ov t);
void destroy_tree(tree_ov t);
tree_ov build_tree(tree_ov bro, tree_ov child, clubs val);
int function(tree_ov t, int count);

#include <bits/stdc++.h>
using namespace std;

mt19937 rng(time(NULL)); 

struct treap_node {
    treap_node* left;
    treap_node* right;
    int x;
    int y;

    treap_node(int _x, int _y) : x(_x), y(_y){
        left =nullptr;
        right =nullptr;    }
};

using treap = treap_node*;

void split(treap t, int x0, treap & t1, treap & t2){
    if(t==nullptr){
        t1=nullptr;
        t2=nullptr;
    }
    if(x0> t->x){
        split(t->right, x0, t->right, t2);
        t1=t;
    } else{
        split(t->right, x0, t1, t->left);
        t2=t;
    }

}

treap merge(treap t1, treap t2){
    if (t1==nullptr){
        return t2;
    }
    if(t2==nullptr){
        return t1;
    }
    if(t1->x >t2->x, t1->y > t2->y){
        t1->right = merge(t1->right, t2);
        return t1;
    } else if(t1->x <t2->x, t1->y > t2->y){
        t1->left=merge(t1->left, t2);
        return t1;
    } else if(t1->x <t2->x, t1->y < t2->y){
        t2->left=merge(t2->left, t1);
        return t2;
    } else {
        t2->right=merge(t2->right, t1);
        return t2;
    }
}

void print_t(treap t){
    if(t==nullptr){
        cout<<"null"<<endl;
        return;
    }
    cout<<t->x<<' '<<t->y<<endl;
    print_t(t->left);
    print_t(t->right);
}

int main(){
    ios::sync_with_stdio(false);
    treap t =nullptr;
    int n;
    cin>>n;
    for(int i=0; i<n; ++i){
        int x, y;
        cin>>x>>y;
        treap m= new treap_node(x, y);
        t=merge(t, m);
    }
    print_t(t);


}
#include <bits/stdc++.h>
using namespace std;

//используем массив, доступ к элементу за О(1), вставка за О(Log(n)) по неявному ключу

mt19937 rng(time(NULL)); 

struct treap_node {
    treap_node* left;
    treap_node* right;
    int x;
    int64_t val;
    int64_t y;
    int64_t max_val;

    treap_node(int _val) : val(_val), max_val(_val){
        left =nullptr;
        right =nullptr;
        x=1;
        y =rng(); //y - рандом
    }
};

using treap = treap_node*;

int getx(treap t){
    return (t==nullptr ? 0 : t->x);
}


int64_t get_max(treap t){
    return (t==nullptr ? 0 : t->max_val);
}

void update(treap t){
    if(t==nullptr){
        return;
    }
    t->x= 1+getx(t->left) + getx(t->right);
    t->max_val=t->val;
    t->max_val=max(t->max_val, get_max(t->left));
    t->max_val= max(t->max_val, get_max(t->right));

}

void split(treap t, int x0, treap & t1, treap & t2){
    if(t==nullptr){
        t1=nullptr;
        t2=nullptr;
        return;
    }
    int szleft =1 +getx(t->left);
    if(x0>= 1+getx(t->left)){
        split(t->right, x0-szleft, t->right, t2);
        t1=t;
    } else{
        split(t->left, x0, t1, t->left);
        t2=t;
    }
    update(t);
    
}

treap merge(treap t1, treap t2){
    if (t1==nullptr){
        return t2;
    }
    if(t2==nullptr){
        return t1;
    }
    if(t1->y >t2->y){
        t1->right = merge(t1->right, t2);
        update(t1);
        return t1;
    } else{
        t2->left=merge(t1, t2->left);
        update(t2);
        return t2;
    }
}

void print_t(treap t, int h){
    if(t==nullptr){
        return;
    }
    print_t(t->left, h+1);
    cout<<t->val<<' ';
    print_t(t->right, h+1);
}

int main(){
    ios::sync_with_stdio(false);
    treap t =nullptr;
    int n, l;
    cin>>n;
    for(int i=0; i<n; ++i){
        int q;
        cin>>q;
        if (q==1){
            int p, x; 
            cin>>x>>p;
            treap l, r;
            split(t, p, l, r);
            treap m=new treap_node(x);
            t =merge(merge(l,m), r);
        } else {
            int l, r, mx;
            cin>>l>>r;
            treap tl, tr, tm;
            split(t, r, tm, tr);
            split(tm, l-1, tl, tm);
            mx= get_max(tm);
            t =merge(merge(tl, tm), tr);
            cout<<mx<<endl;
        }
    }

}
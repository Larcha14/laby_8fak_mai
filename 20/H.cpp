 #include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;



struct segtree{
    struct node{
        node* left =nullptr;
        node* right=nullptr;
        int64_t data;

        node(int64_t a):data(a){}
    };
    using ptr =node*;
    int n;

    vector<ptr> vers;
    segtree( const vector<int64_t>&a):n(a.size()) {
        ptr root;
        root = build(1, n, a);
        vers.push_back(root);
    }

    ptr build(int l, int r, const vector<int64_t> &a){
        ptr u=new node(0);
        if (l==r){
            u->data=a[l-1];
            return u;
        }
        int m=(l+r)/2;
        u->left= build( l, m, a);
        u->right= build( m+1, r, a);
        u->data=u->left->data+u->right->data;  // создание дерев
        return u;
    }
          
    void set(int k, int p, int x){
        ptr newroot = set(vers[k-1],1,n,p,x); // делаем копию от версии
        vers.push_back(newroot);
    }
    ptr set(ptr u, int l, int r, int p, int x){ // возвращает указатель на новый узел
        u=copy(u);
        if(l==r){
            u->data=x;
            return u;
        }
        int m=(l+r)/2;
        if(p<=m){
            u->left=set(u->left, l, m, p, x);
        } else{
            u->right=set(u->right, m+1, r, p, x);
        }
        u->data=u->left->data+u->right->data;
        // cout<<data[id]<<' ';
        return u;
    }

    ptr copy(ptr u){
        ptr v = new node(u->data);
        v->left=u->left;
        v->right=u->right;
        return v;
    }

    int64_t get(int k, int ql, int qr){
        return get(vers[k-1],1, n, ql, qr);
    }

    int64_t get(ptr u, int l, int r, int ql, int qr){
        if(ql<= l and r<=qr){
            return u->data;
        }
        int m=(l+r)/2;
        if (qr<=m){
            return get(u->left, l, m, ql, qr);
        }
        if(ql>=m+1){
            return get(u->right, m+1, r, ql, qr);
        }
        // cout<<data[id]<<' ';
        return get(u->left, l, m, ql, qr)+get(u->right, m+1, r, ql, qr);
    }

};


int main(){
    ios::sync_with_stdio(false);
    int n;
        int q;
    cin>>n>>q; 
    vector<int64_t> a(n);
    for (int i=0; i<n; ++i){
        cin>>a[i];
    }
    segtree st(a);
    while (q--)    {
        string t; 
        cin>>t;
        if(t=="get"){
            int64_t k, p;
            cin>>k>>p;
            cout<<st.get(k, p, p)<<'\n';
        } else if(t=="create"){
            int64_t k, x, y;
            cin>>k>>x>>y;
            st.set(k,x, y);
        } 
    }
    
}



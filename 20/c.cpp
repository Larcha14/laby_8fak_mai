 #include <iostream>
#include <vector>
#include <cmath>
#include <string>
const int INF=1e9+7;

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
    ptr root=nullptr;

    segtree(int _n):n(_n) { root =new node(0);}
          
    int64_t get_data(ptr u){
        if(u==nullptr){
            return 0;
        } else{
            return u->data;
        }
    }

    void set(int p, int x){
        root = set(root,1,n,p,x);
    }
    ptr set(ptr u, int l, int r, int p, int x){ 
        if (u==nullptr){
            u=new node(0);
        }
        if(l==r){
            u->data=u->data+x;
            return u;
        }
        int m=(l+r)/2;
        if(p<=m){
            u->left=set(u->left, l, m, p, x);
        } else{
            u->right=set(u->right, m+1, r, p, x);
        }
        u->data=get_data(u->left)+get_data(u->right);
        return u;
    }

    int64_t get(int ql, int qr){
        return get(root,1, n, ql, qr);
    }

    int64_t get(ptr u, int l, int r, int ql, int qr){
        if(u==nullptr){
            return 0;
        }
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
        return get(u->left, l, m, ql, qr)+get(u->right, m+1, r, ql, qr);
    }

};


int main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n; 
    segtree st(INF);
    while (n--)    {
        int t; 
        cin>>t;
        if(t==0){
            int l, r;
            cin>>l>>r;
            cout<<st.get(l,r)<<'\n';
        } else if(t==1){
            int64_t x, y;
            cin>>x>>y;
            st.set(x, y);
        } 
    }
    
}

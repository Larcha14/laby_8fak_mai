#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

struct segtree{
    int n;
    vector<int64_t> data;
    segtree(int _n):n(_n), data(4*_n) {}

    segtree( const vector<int64_t>&a):segtree(a.size()) {build(1, 1, n, a);}

    void build(int id, int l, int r, const vector<int64_t> &a){
        if (l==r){
            data[id]=a[l-1];
            return;
        }
        int m=(l+r)/2;
        build(id*2, l, m, a);
        build(id*2+1, m+1, r, a);
        data[id]=data[id*2]+data[id*2 +1];  // создание дерев
    }

    void set(int p, int x){
        set(1,1,n,p,x);
    }
    void set(int id, int l, int r, int p, int x){
        if(l==r){
            data[id]=x+data[id];
            return;
        }
        int m=(l+r)/2;
        if(p<=m){
            set(id*2, l, m, p, x);
        } else{
            set(id*2 +1, m+1, r, p, x);
        }
        data[id]=data[id*2]+data[id*2 +1];
        // cout<<data[id]<<' ';
    }

    int64_t get(int ql, int qr){
        return get(1,1, n, ql, qr);
    }

    int64_t get(int id, int l, int r, int ql, int qr){
        if(ql<= l and r<=qr){
            return data[id];
        }
        int m=(l+r)/2;
        if (qr<=m){
            return get(id*2, l, m, ql, qr);
        }
        if(ql>=m+1){
            return get(id*2 +1, m+1, r, ql, qr);
        }
        // cout<<data[id]<<' ';
        return get(id*2, l, m, ql, qr)+get(id*2 +1, m+1, r, ql, qr);
    }
};

int main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int64_t> a(n);
    for(int i=0; i<n;++i){
        cin>>a[i];
    }
    segtree st(a);
    // cout<<'\n';
    int q;
    cin>>q;
    while (q--)    {
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


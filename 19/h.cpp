#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

struct answ{
    int l;
    int r;
    int i;
};

bool cmp(answ a, answ b){
    if(a.r<b.r){
        return true;
    } 
    return false;
}

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
        data[id]=max(data[id*2], data[id*2 +1]);  // создание дерева
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
        return max(get(id*2, l, m, ql, qr),
                        get(id*2 +1, m+1, r, ql, qr) );
    }
    
};

int main(){
    ios::sync_with_stdio(false);
    int n, q;
    cin>>n>>q;
    // vector<int> pos(n+1, -1);
    vector<int64_t> a(n);
    for(int i=0; i<n;++i){
        int h;
        cin>>h;
        a[i]=h;
    }
    segtree st(a);
    vector<int> res(q);
    vector<answ> as(q);
    for (int j=0; j<q; ++q){
        int l, r;
        cin>>l>>r;
        as[j].l=l;
        as[j].r=r;
        as[j].i=j;
    }
    sort(as.begin(), as.end(), cmp);
    int l=0;
    for (int i=0; i<n;++i){
        int r=i;
        
    }
    for (int i=0; i<q; ++i){
        cout<<res[i]<<'\n';
    }
    
}


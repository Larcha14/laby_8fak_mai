#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

//template <class T>

//vector<T> data;
//segtree<int> st(a);

int64_t gcd (int64_t a, int64_t b){
    int64_t c;
    if (a<b){
        swap(a, b);
    }
    while (a%b!=0){
        a=a%b;
        swap(a, b);
    }
    return b;
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
        data[id]=gcd(data[id*2], data[id*2 +1]);  // создание дерева
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
        return gcd(get(id*2, l, m, ql, qr),
                        get(id*2 +1, m+1, r, ql, qr) );
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
    int q;
    cin>>q;
    while (q--){
        int l, r;
        cin>>l>>r;
        cout<<st.get(l,r)<<'\n';
    }
    
}


#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

struct segtree{
    int n;
    vector<int64_t> data, delay;
    segtree( const vector<int64_t>&a):n(a.size()), data(4*n), delay(4*n) {build(1, 1, n, a);}
    segtree(int _n):n(_n), data(4* n), delay(4*n) {
          
    }
    void build(int id, int l, int r, const vector<int64_t> &a){
        if (l==r){
            data[id]=a[l-1];
            return;
        }
        int m=(l+r)/2;
        build(id*2, l, m, a);
        build(id*2+1, m+1, r, a);
        data[id]=max(data[id*2], data[id*2 +1]); 
    }

    void push(int64_t id){
        if(delay[id]==0){
            return;
        }
        if (id*2<4*n){
            delay[id*2]+=delay[id];
        }
        if(id*2 +1<4*n){
            delay[id*2 +1]+=delay[id];
        }
        data[id]+=delay[id];
        delay[id]=0;
    }


    int64_t get(int ql, int qr){
        return get(1,1, n, ql, qr);
    }

    int64_t get(int id, int l, int r, int ql, int qr){
        if(ql<= l and r<=qr){
            return data[id];
        }
        push(id);
        int m=(l+r)/2;
        if (qr<=m){
            return get(id*2, l, m, ql, qr);
        }
        if(ql>m){
            return get(id*2 +1, m+1, r, ql, qr);
        }
        // cout<<data[id]<<' ';
        return max(get(id*2, l, m, ql, qr),get(id*2 +1, m+1, r, ql, qr));
    }

    void update(int l, int r, int64_t x){
        update(1,1,n,l,r,x);
    }

    void update(int id, int l, int r, int ql, int qr, int64_t x){
        if(ql>r or qr<l){
            return;
        }
        if(ql<= l and r<=qr){
            delay[id]+=x;
            push(id);
            return;
        }
        push(id);
        int m= (l+r)/2;
        update(id*2, l, m, ql, qr, x);
        update(id*2 +1, m+1, r, ql, qr, x);
        data[id]=max(data[id*2],data[id*2 +1]);
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
    while (q--) {
        int64_t l, r, x; 
        cin>>l>>r>>x;
        st.update(l,r,x);
        cout<<st.get(l,r)<<'\n';

    }
    
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct seg{
    int t;
    int x;
    int stat;
};
  
bool cmp(seg f, seg s){
    if(f.t!=s.t){
        return f.t<s.t;
    } else {
        return f.x<s.x;
    }

}

const int INF = 1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin>>n>>q;
    vector <int64_t> m(n, 0);
    vector <seg> p;
    for (int i=0; i<q;++i){
        int lg, rg, x;
        seg ell, elr;
        cin>>lg>>rg>>x;
        ell.t=lg;
        ell.x=x;
        ell.stat=1;
        elr.t=rg+1;
        elr.x=x;
        elr.stat=-1;
        p.push_back(ell);
        p.push_back(elr);
    }
    sort(p.begin(), p.end(), cmp);
    int lp=INF;
    int cnt=0;
    int answ=0;
    int64_t sum=0;
    cout<<'\n';
    // for(seg el : p){
    //     cout<<el.t<<' '<<el.x<<' '<<el.stat<<'\n';
    // }
    int j=0;
    for(int i=0;i<n;++i){
        
        while(p[j].t==i+1){
            int x=p[j].x;
            int s=p[j].stat;
            if(s==1){
                sum+=x;
            } else{
                sum-=x;
            } 
            j++;
        }
        m[i]=sum;
    }
    for(int i=0; i<n;++i){
        cout<<m[i]<<' ';
    }
    // cout<<answ;
}
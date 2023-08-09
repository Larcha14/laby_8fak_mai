#include <iostream>
#include <vector>
#include <queue>
#include <iterator>
#include <algorithm>
#include <stack>
#include <numeric>
using namespace std;

struct seg{
    int t;
    int x;
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
    cin>>n;
    vector <seg> p;
    for (int i=0; i<n;++i){
        int lg, rg;
        seg ell, elr;
        cin>>lg>>rg;
        ell.t=lg;
        ell.x=1;
        elr.t=rg+1;
        elr.x=-1;
        p.push_back(ell);
        p.push_back(elr);
    }
    sort(p.begin(), p.end(), cmp);
    int lp=INF;
    int cnt=0;
    int answ=0;
    // cout<<'\n';
    // for(seg el : p){
    //     cout<<el.t<<' '<<el.x<<'\n';
    // }
    for(seg el : p){
        int t=el.t;
        int x=el.x;
        cnt+=x;
        if(cnt>0){
            if(lp==INF){
                lp=t;
            }
        } else{
            answ+=t-lp;
            lp=INF;
        }


    }
    cout<<answ;
}
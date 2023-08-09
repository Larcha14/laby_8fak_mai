#include <iostream>
#include <vector>
#include <queue>
#include <iterator>
#include <algorithm>
#include <stack>
#include <numeric>
using namespace std;

struct seg{
    int r;
    int l;
};
  
bool cmp(seg f, seg s){
    if(f.r!=s.r){
        return f.r<s.r;
    } else {
        return f.l<s.l;
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
        seg el;
        cin>>lg>>rg;
        el.r=rg;
        el.l=lg;
        p.push_back(el);
    }
    sort(p.begin(), p.end(), cmp);
    int lp=INF;
    int r_bound=-INF;
    int answ=0;
    // cout<<'\n';
    // for(seg el : p){
    //     cout<<el.t<<' '<<el.x<<'\n';
    // }
    for(seg el : p){
        if(el.l>=r_bound){
            r_bound=el.r;
            ++answ;

        }


    }
    cout<<answ;
}
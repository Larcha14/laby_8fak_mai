#include <iostream>
#include <vector>
#include <queue>
#include <iterator>
#include <algorithm>
#include <set>
using namespace std;

const int64_t INF = 1e18;

struct wedge{
    int u, v;
};

using weight_graphs = vector< vector<wedge> >;

void dfs(int u, int p, const weight_graphs& g, vector<int>& d){
    for (int i=0; i<g[u].size();++i){
        int v = g[u][i].v;
        if (v==p){
            continue;
        }
        d[v]=d[u]+1;
        dfs(v, u, g, d);

    }
}

int main(){
    ios::sync_with_stdio(false);
    int n, m, start, pr, flag;
    int u, v, t,q;
    int64_t w;
    cin>>t;
    for (int j=0; j<t;++j){
        cin >>n;
        vector <int> pred(n+2,0);
        for (int i=2; i<2+n-1; ++i){
            cin>>u;
            pred[i]=u;
        }
        cin>>q;
        for (int h=0; h<q;++h){
            cin>>u>>v;
            start=v;
            pr=u;
            flag=0;
            for (int i=0; i<n-1;++i){
                if (pred[start]==pr){
                    flag=1;
                    break;
                } else if( pred[start]==0){
                    flag=0;
                    break;
                } else{
                    u=start;
                    start=pred[u];
                }
            }
            if (flag==0){
                cout<<"NO";
            } else{
                cout<<"YES";
            }
            cout<<"\n";

        }

    }
}
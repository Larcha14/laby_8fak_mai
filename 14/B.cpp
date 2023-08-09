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
    int n, m, start, finish;
    int u, v, k;
    int64_t w;
    cin>>k;
    for (int j=0; j<k;++j){
        cin >>n;
        weight_graphs g(n);
        for (int i=0; i<n-1; ++i){
            cin>>u>>v;
            g[u-1].push_back({u-1, v-1});
            g[v-1].push_back({v-1, u-1});
        }
        u=0;
        v=0;  
        vector<int> diameter1(n);
        dfs(u, u, g, diameter1);
        for (int i=0; i<n; ++i){
            if (diameter1[i]>diameter1[v]){
                v=i;
            }
        }
        // cout<<v;
        vector<int> diameter2(n);
        dfs(v, v, g, diameter2);
        for (int i=0; i<n; ++i){
            if (diameter2[i]>diameter2[u]){
                u=i;
            }

        }
        cout<<diameter2[u]<<'\n';
    }
}
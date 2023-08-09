#include <iostream>
#include <vector>
#include <queue>
#include <iterator>
#include <algorithm>
#include <set>
using namespace std;

const int64_t INF = 1e18;
const int MAXD =20;

struct wedge{
    int u, v;
};

using weight_graphs = vector< vector<wedge> >;

void dfs(int u, int p, const weight_graphs& g, vector<int>& d, vector<vector<int>>& up){
    for (int i=0; i<g[u].size();++i){
        int v = g[u][i].v;
        if (v==p){
            continue;
        }
        d[v]=d[u]+1;
        up[v][0]=u;
        dfs(v, u, g, d, up);

    }
}

int main(){
    int n, m, start, finish, root;
    int u, v;
    int64_t w;
    cin >>n;
    weight_graphs g(n);
    for (int i=0; i<n-1; ++i){
        cin>>u>>v;
        g[u-1].push_back({u-1, v-1});
        g[v-1].push_back({v-1, u-1});
    }
    vector <vector<int> > up(MAXD);
    vector <int> di(n);


}
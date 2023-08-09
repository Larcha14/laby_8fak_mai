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
    int64_t w;
};

using weight_graphs = vector< vector<wedge> >;
using item = pair<int64_t, int>;

int main(){
    ios::sync_with_stdio(false);
    int n, m, start, finish;
    int u, v;
    int64_t w;
    cin >>n>>m;
    weight_graphs g(n);
    start=0;
    finish=n-1;
    for (int i=0; i<m; ++i){
        cin>>u>>v>>w;
        g[u-1].push_back({u-1, v-1, w});
        g[v-1].push_back({v-1, u-1, w});
    }
    int flag =1;
    vector <int64_t> d(n, INF);
    vector <int64_t> back(n, -1);
    vector <int> visited(n, 0);
    vector <int> pass;
    // fast
    set<item> pq;
    d[start]=0;
    back[start]=start;   
    for (int i=0; i<n; ++i){
        pq.insert({d[i], i});
    }
    while (!pq.empty()){
        item el = *pq. begin();
        pq. erase(pq.begin());
        u = el.second;
        visited[u]=1;
        for (int j=0; j<g[u].size(); ++j){
                v= g[u][j].v;
                w=g[u][j].w;
                if (d[v]>d[u]+w){
                    pq.erase({d[v], v});
                    d[v]=d[u]+w;
                    back[v]=u;
                    pq.insert({d[v], v});
                }            
        }
    }
    // for (int64_t i=0; i<n;++i){
    //     if (d[i]==INF){
    //         cout<<-1<<' ';
    //     } else {
    //         cout<<d[i]<<' ';
    //     }
    // }
    if (d[finish]!=INF){
        while(back[finish]!=finish){
            pass.push_back(finish);
            finish=back[finish];
        }
        pass.push_back(finish);
        reverse(pass.begin(), pass.end());
        for (int i=0; i<pass.size(); ++i){
            cout<<pass[i]+1<<' ';
        }
    } else{
        cout<<-1;
    }
}
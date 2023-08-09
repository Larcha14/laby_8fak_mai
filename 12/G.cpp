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
    cin >>n>>m>>start;
    weight_graphs g(n);
    start--;
    vector <int64_t> back(n, -1);
    vector <int> visited(n, 0);
    vector <int> pass;
    int64_t sum=0;
    for (int i=0; i<m; ++i){
        cin>>u>>v>>w;
        g[u-1].push_back({u-1, v-1, w});
        g[v-1].push_back({v-1, u-1, w});
        // d[u-1]=max(w, d[u-1]);
        sum+=w;
    }
    // fast
    sum=sum/m;
    set<item> pq;
    vector <int64_t> d(n, -1);
    // for(int i=0;i<n;++i){
    //     int a1, a2;
    //     a1=g[v]
    // }
    d[start]=-1;
    back[start]=start;   
    for (int i=0; i<n; ++i){
        pq.insert({d[i], i});
    }
    while (!pq.empty()){
        item el = *pq. begin();
        pq.erase(pq.begin());
        u = el.second;
        visited[u]=1;
        for (int j=0; j<g[u].size(); ++j){
            v= g[u][j].v;
            w=g[u][j].w;
            if(visited[v]==1 ){
                continue;
            }
            // cout<<v<<' '<<w<<" ";
            if(d[u]<0){
                if(d[v]<w){
                    pq.erase({d[v], v});

                    d[v]=w;
                    back[v]=u;
                    // cout<<d[v]<<"\\";
                    pq.insert({d[v], v});
                }
            }else{
                if (d[v]<min(d[u], w) ){
                pq.erase({d[v], v});

                d[v]=min(d[u], w);
                back[v]=u;
                // cout<<d[v]<<"\\";
                pq.insert({d[v], v});
            }    
            }
            // if (d[v]<min(d[u], w) ){
            //     pq.erase({d[v], v});

            //     d[v]=min(d[u], w);
            //     back[v]=u;
            //     // cout<<d[v]<<"\\";
            //     pq.insert({d[v], v});
            // }            
            
        }
    }
    for (int64_t i=0; i<n;++i){
        cout<<d[i]<<' ';
    }
}
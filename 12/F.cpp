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
    int n, q, start, finish;
    int64_t w;
    cin >>n>>q;
    weight_graphs g(n);
    for (int u=0; u<n; ++u){
        for(int v=0; v<n;++v){
            cin>>w;
            g[u].push_back({u, v, w});

        }
    }
    int flag =1;
    // slow
    for(int h=0; h<q;++h){
        cin>>start;
        start--;
        vector <int64_t> d(n, INF);
        vector <int64_t> back(n, -1);
        vector <int> visited(n, 0);
        vector <int> pass;
        d[start]=0;
        back[start]=start; 
        int u, v; 
        for (int i=0; i<n; ++i){
            int mnid =0;
            int64_t val= INF;
            for (int j=0; j<n;++j){
                if(visited[j]==0 and d[j]<val){
                    mnid=j;
                    val = d[j];
                }
            }
            u = mnid;
            visited[u]=1;
            for (int j=0; j<g[u].size(); ++j){
                    v= g[u][j].v;
                    w=g[u][j].w;
                    if (d[v]>d[u]+w){
                        d[v]=d[u]+w;
                        back[v]=u;
                    }
            }
        }
        for(int i=0;i<n;++i ){
            cout<<d[i]<<' ';
        }
        cout<<'\n';
    }

}
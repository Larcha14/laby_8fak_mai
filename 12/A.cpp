//Алгоритм Форда-Белмана
#include <iostream>
#include <vector>
#include <queue>
#include <iterator>
#include <algorithm>
using namespace std;

const int64_t INF = 1e18;
using graphs = vector< vector<int> >;

struct wedge{
    int u, v;
    int64_t w;
};

int main(){
    int n, m, start;
    int u, v;
    int64_t w;
    int k=0;
    cin >>n>>m>>start;
    graphs g(n);
    --start;
    vector<wedge> edges; //вершины
    for (int i=0; i<m; ++i){
        cin>>u>>v>>w;
        v--;
        u--;
        edges.push_back({u, v, w});
        // edges.push_back({v, u, w});
    }
    int flag =1;
    vector <int64_t> dp(n, INF);
    dp[start]=0;
    for (int i=0; i<n;++i){ //идём по всему графу
        flag =0;
        for (int j=0; j<m;++j){ // количество переборов
            u=edges[j].u;
            v=edges[j].v;
            w=edges[j].w;
            if (dp[v]>dp[u]+w){
                dp[v]=dp[u]+w;
                flag=1;
            }
            if (dp[u]>dp[v]+w){
                dp[u]=dp[v]+w;
                flag=1;
            }
        }
        if (flag==0){
            break;
        }
    }
    if (flag==1){
        cout<<"Negative cycle";
    } else{
        for (int64_t i=0; i<n;++i){
            if (dp[i]==INF){
                cout<<-1<<' ';
            } else{
                cout<<dp[i]<<' ';
            }
        }
    }
}
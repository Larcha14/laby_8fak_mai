#include <iostream>
#include <vector>
#include <queue>
#include <iterator>
#include <algorithm>
using namespace std;

using graphs = vector< vector<int> >;

// vector<int> bfs(int u, const graphs& g){
//     int n= g.size();
//     queue <int> q;
//     vector<int> step(n, -1);
//     step[u]=0;
//     q.push(u);
//     while (!q.empty()){
//         u=q.front();
//         q.pop();
//         for (int j=0; j<g[u].size(); ++j){
//             int v= g[u][j];
//             if (step[v]==-1){
//                 step[v]=1+step[u];
//                 q.push(v);
//             }
//         }
//     }
//     return step;
// }

bool dfs(int u, const graphs& g, vector <int>& mt, vector <int>& visited){
    if (visited[u]==1){
        return false;
    }
    visited[u] =1;
    for (int j=0; j<g[u].size(); ++j){  //проверка, если находит увелич цепь, 
        int v=g[u][j];
        if (mt[v]==-1){
            mt[v]=u;
            return true ;
        }
        bool tmp = dfs(mt[v], g,mt,visited);
        if(tmp){
            mt[v]=u;
            return true;
        }
    }
    return false;
}

int main(){
    int n, m;
    int u, v;
    int ans=0;
    cin>>n>>m;
    graphs g(n);
    for(int i=0; i<m;++i){
        cin>>u>>v;
        g[u-1].push_back(v-1);
        // g[u-1].push_back(v-1);
    }
    vector<int> step(n, -1);
    u=0;

    vector<int> mt(n, -1); //храним для каждой вершины правой доли ее партнёра из левой
    for (int i=0; i<n; ++i){
        // if (step[i] & 1){
        //     continue;
        // }
        vector <int> visited(n, 0);
        ans+=dfs(i, g, mt, visited);
    }
    // cout<<"\n";
    cout<<ans<<"\n";
    for (int i=0; i<n; ++i){
        if (mt[i]==-1){
            continue;
        }
        cout<<mt[i]+1<<" "<<i+1<<endl;
    }

}
#include <iostream>
#include <vector>
#include <queue>
#include <iterator>
#include <algorithm>
using namespace std;

using graphs = vector< vector<int> >;

vector<int> bfs(int u, const graphs& g){
    int n= g.size();
    int start =u;
    queue <int> q;
    vector<int> step(n, -1);
    vector <int> f;
    int v;
    step[u]=0;
    q.push(u);
    while (!q.empty()){
        u=q.front();
        q.pop();
        for (int j=0; j<g[u].size(); ++j){
            v= g[u][j];
            if (step[v]==-1){
                step[v]=1+step[u];
                q.push(v);
            }
        }
        if (v==start){
            return f;
        }
    }
    return step;
}

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
    int flag=0;
    cin>>n>>m;
    graphs g(n);
    for(int i=0; i<m;++i){
        cin>>u>>v;
        g[u-1].push_back(v-1);
        g[u-1].push_back(v-1);
        if (u==v){
            flag=1;
        }
    }
    vector<int> step=bfs(0, g);
    if (step.size()==0 or flag==1){
        cout<<"-1";
        flag=1;
    }
    if (flag!=1){
            u=0;
        // for (int i=0; i<n; ++i){
        //     if (g[i].size()>0){
        //         int v2 =g[i][u];
        //         if (step[i]==-1){
        //             step[i]=v2;
        //         }
        //     }

        // }
        // for (int i=0; i<n; ++i){
        //     cout<<step[i]<<"\n";
        // }
        vector<int> mt(n, -1); //храним для каждой вершины правой доли ее партнёра из левой
        for (int i=0; i<n; ++i){
            if (step[i] & 1){
                continue;
            }
            vector <int> visited(n, 0);
            ans+=dfs(i, g, mt, visited);
        }
        cout<<"\n";
        cout<<ans<<"\n";
        for (int i=0; i<n; ++i){
            if (mt[i]==-1){
                continue;
            }
            cout<<mt[i]+1<<" "<<i+1<<endl;
        }
    }

}
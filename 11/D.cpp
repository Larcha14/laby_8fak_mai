#include <iostream>
#include <vector>
#include <queue>
#include <iterator>
#include <algorithm>
using namespace std;

using graphs = vector< vector<int> >;

bool bfs(int u, int find, const graphs &g, vector<int> &d, vector <int> &back){
    queue<int> q;
    d[u]=0; // d - количество путей
    back[u]=u;
    q.push(u);
    while(!q.empty()){
        int x1=q.front();
        q.pop();
        for(int v:g[x1]){
            if(d[v]==-1){
                d[v]=d[x1]+1;
                back[v]=x1;
                q.push(v);
                if(v==find){
                    return true;
                }
            }
        }
    }
    return false;
}

int main(){
    int n, m,u1,v1;
    cin >>n>>m>>u1>>v1;
    graphs g(n);
    u1--;
    v1--;
    for (int i=0; i<m; ++i){
        int u, v;
        cin>>u>>v;
        g[u-1].push_back(v-1);
        g[v-1].push_back(u-1);
    }
    for (int i=0; i<n;++i){
        sort(g[i].begin(), g[i].end());
    }
    vector <int> back(n, -1);
    vector<int> path(n,-1);
    vector<int> put;
    if(v1==u1){
        cout<<v1+1;
    }else if(bfs(u1, v1, g, path, back)){
        int h=v1;
        put.push_back(h);
        while(back[h]!=u1){
            put.push_back(back[h]);
            h=back[h];
        }
        put.push_back(u1);
        reverse(put.begin(), put.end());
        // cout<<back[0];
        for(int i=0; i<put.size();++i){
            cout<<put[i]+1<<" ";
        }
        // cout<<"\n";
        // for(int i=0; i<n;++i){
        //     cout<<back[i]+1<<" ";
        // }
    } else{
        cout<<-1;
    }
    // cout<<"\n";
    // for(int i=0; i<path.size();++i){
    //     cout<<path[i]<<" ";
    // }

}


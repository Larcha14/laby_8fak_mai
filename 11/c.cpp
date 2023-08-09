#include <iostream>
#include <vector>
#include <queue>
#include <iterator>
#include <algorithm>
using namespace std;
 
using graphs = vector< vector<int> >;
 
bool dfs(int u, int h, int& find, const graphs &g, vector<int> &color, vector <int> &path, vector<int> &cycle ){
    if(color[u]==2){
        return false;
    }
    path.push_back(u);
    color[u]=2;
    if(u==find){
        return true;
    }
    for(int v : g[u]){
        // if (v!=h){
            // if(color[v]==1){
            //     return false;
            // } 
            // if (v==find){
            //     path.push_back(v);
            //     return true;
            // }
            if (dfs(v, u, find, g, color, path, cycle)){
                return true;
            }
        // }
    }
    color[u]=2;
    path.pop_back();
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
    vector <int> color(n, 0);
    vector <int> cycle;
    vector<int> path;
    if(dfs(u1, -1, v1, g, color, path, cycle)){
        for(int i=0; i<path.size();++i){
            cout<<path[i]+1<<" ";
        }
    }else if(v1==u1){
        cout<<v1+1;
    } else{
        cout<<-1;
    }
    // cout<<"\n";
    // for(int i=0; i<path.size();++i){
    //     cout<<path[i]<<" ";
    // }
 
}
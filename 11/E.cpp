#include <iostream>
#include <vector>
#include <queue>
#include <iterator>
#include <algorithm>
using namespace std;

using graphs = vector< vector<int> >;

bool dfs(int u, int h, const graphs &g, vector<int> &color, vector <int> &path, vector<int> &cycle ){
    if(color[u]==2){
        return false;
    }
    path.push_back(u);
    color[u]=1;
    for(int v : g[u]){
        if (v!=h){
            if(color[v]==1){
                int i=path.size()-1;
                cycle.push_back(v+1);
                while(path[i]!=v){
                    cycle.push_back(path[i]+1);
                    i--;
                }
                // cycle.push_back(v+1);
                return true;
            } 
            if (dfs(v, u, g, color, path, cycle)){
                return true;
            }
        }
    }
    color[u]=2;
    path.pop_back();
    return false;
}

int main(){
    int n, m;
    cin >>n;
    graphs g(n);
    for (int i=0; i<n; ++i){
        int u, v;
        cin>>u>>v;
        g[u-1].push_back(v-1);
        g[v-1].push_back(u-1);
    }
    vector <int> color(n, 0);
    vector <int> cycle;
    vector<int> path;
    dfs(0, -1, g, color, path, cycle);
    sort(cycle.begin(), cycle.end());
    for(int i=0; i<cycle.size(); ++i){
        cout<<cycle[i]<<' ';
    }
    // cout<<"\n";
    // for(int i=0; i<path.size();++i){
    //     cout<<path[i]<<" ";
    // }

}


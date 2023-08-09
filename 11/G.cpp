#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using graphs = vector< vector<int> >;

bool dfs(int u, int &mx, const graphs &g, vector<int> &color, vector <int> &path){
    if(color[u]!=0){
        return false;
    }
    if(g[u].size()==0){
        color[u]=1;
        return true;
    }
    path.push_back(u);
    int max_l=0;
    for(int v : g[u]){
        int l1;
        dfs(v, mx, g, color, path);
        l1=color[v];
        if(l1>max_l){
            max_l=l1;
        }
    }

    color[u]=max_l+1;
    if(color[u]>mx){
        mx=color[u];
    }
    path.pop_back();
    return true;
}

void print_path(const graphs &g, int u, const vector<int> &color){
    if(color[u]==1){
        cout<<u+1;
        return;
    }
    int mx=color[u]-1;
    int u_next;
    for (int v:g[u]){
        if(color[v]==mx){
            mx=color[v];
            u_next=v;
            break;
        }
    }
    cout<<u+1<<' ';
    print_path(g, u_next, color);


    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, chek_point;
    int mx=1;
    cin>>n>>m;
    graphs g(n);
    vector <int> back(n, -1);
    vector<int> path;
    vector<int> color(n, 0);
    for(int i=0; i<m;++i){
        int u,v;
        cin>>u>>v;
        g[u-1].push_back(v-1);
    }
    for (int u=0;u<n;++u){
        dfs(u, mx, g, color, path);
    }
    
    cout<<mx<<'\n';
    for(int i=0;i<n;++i){
        if (color[i]==mx){
            chek_point=i;
            break;
        }
    }
    print_path(g, chek_point, color);

}
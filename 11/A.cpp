#include <iostream>
#include <vector>
#include <queue>
#include <iterator>
#include <algorithm>
#include <stack>
using namespace std;

using graphs = vector< vector<int> >;

void dfs(int start, const graphs& g,int& count, vector<int> &cnt, vector <int> &visited){
    if (visited[start]==1){
        return;
    }
    visited[start] = 1;
    cnt[start]=count;
    ++count;
    for (int v :g[start]){
        dfs(v, g, count, cnt, visited);
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    int u, v;
    cin >>n>>m>>k;
    graphs g(n);
    for (int i=0; i<m; ++i){
        cin>>u>>v;
        g[u-1].push_back(v-1);
        g[v-1].push_back(u-1);
    }
    vector <int> cnt(n, -1);
    vector <int> visited(n, 0);
    int count=0;
    dfs(k-1, g, count,  cnt, visited);
    for (int i=0; i<n;++i){
        cout<<cnt[i]<<" ";
    }


}
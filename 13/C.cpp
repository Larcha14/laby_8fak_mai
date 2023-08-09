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

bool operator < (wedge a, wedge b){
    return a.w <b.w;
}

using weight_graphs = vector< vector<wedge> >;
using item = pair<int64_t, int>;

int find(int u, vector<int> & leader){
    if (leader[u]==u){
        return u;
    }
    leader[u]=find(leader[u], leader);
    return leader[u];
}

int main(){
    ios::sync_with_stdio(false);
    int n, m, s;
    int u, v;
    int lu, lv;
    int64_t w;
    int64_t w_total=0;
    cin >>n>>m;
    vector <wedge> edges;
    vector <int> size(n,1);
    vector <int> leader(n);
    for (int i=0; i<n;++i){
        leader[i]=i;
    }
    for (int i=0; i<m; ++i){
        cin>>u>>v>>w;
        edges.push_back({u-1, v-1, w});
    }
    sort(edges.begin(), edges.end());

    for(int i=0; i<m; ++i){
        u=edges[i].u;
        v=edges[i].v;
        lu=find(u, leader);
        lv=find(v, leader);
        if (lu!=lv){
            if (size[lu]>size[lv]){
                swap(lu, lv);
            } 
            leader[lu]=lv;
            size[lv]+=size[lu];
            w=edges[i].w;
            w_total+=w;
        }

    }
    cout<<w_total;

}
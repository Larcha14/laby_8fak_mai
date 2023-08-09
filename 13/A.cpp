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
    cin >>n>>m;
    vector <int> size(n,1);
    vector <int> leader(n);
    weight_graphs g(n);
    for (int i=0; i<n;++i){
        leader[i]=i;
    }
    for (int i=0; i<m; ++i){
        cin>>u>>v;
        u--;
        v--;
        lu=find(u, leader);
        lv=find(v, leader);
        if (lu!=lv){
            if (size[lu]>size[lv]){
                swap(lu, lv);
            } 
            leader[lu]=lv;
            size[lv]+=size[lu];
        }
        cout<<size[lv]<<endl;

    }

}
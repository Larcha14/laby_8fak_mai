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

using matrix = vector <vector<int64_t>>;

int main(){
    int n, m, start, finish;
    int64_t w;
    cin >>n;
    matrix d(n, vector<int64_t>(n, INF));
    start=n-1;
    for (int u=0; u<n; ++u){
        for(int v=0; v<n;++v){
            int l;
            cin>>l;
            d[u][v]=l;

        }
    }
    // for(int i=0; i<n;++i){
    //     d[i][i]=0;
    // }
    for (int k=0; k<n; ++k){
        for (int u=0; u<n; ++u){
            for (int v=0; v<n;++v){
                d[u][v]=min(d[u][v], d[u][k]+d[k][v]);
            }
        }
    }

    for (int i=0; i<n;++i){
        for (int j=0; j<n;++j){
            cout<<d[i][j]<<' ';
        }
        cout<<'\n';
    }

}
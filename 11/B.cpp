#include <iostream>
#include <vector>
#include <queue>
#include <iterator>
#include <algorithm>
using namespace std;

using graphs = vector< vector<int> >;
#define s 12;
#define f 14;

int main(){
    int n, m, k;
    int u, v;
    int finish =f;
    cin >>n>>m>>k;
    graphs g(n);
    for (int i=0; i<m; ++i){
        cin>>u>>v;
        g[u-1].push_back(v-1);
        g[v-1].push_back(u-1);
    }
    int start =k-1;
    vector <int> step(n, -1);
    vector <int> back(n, -1);
    queue <int> q;
    step[start]=0;
    back[start]=start;
    q.push(start);
    while(!q.empty()){
        int u2=q.front();
        q.pop();
        for (int i=0; i<g[u2].size();++i){
            int v2=g[u2][i];
            if (step[v2]==-1){
                step[v2]=step[u2]+1;
                back[v2]=u2;
                q.push(v2);
            }
        } 
        // // for (int v2 : g[u2]){
        // //     if (step[v2]==-1){
        // //         step[v2]=step[u2]+1;
        // //         back[v2]=u2;
        // //         q.push(v2);

        // //     }
        // }
    }
    for(int i=0; i<n;++i){
        cout<<step[i]<<' ';
    }
    // vector <int> pass;
    // int u3=finish;
    // while(back[u3]!=u3){
    //     pass.push_back(u3);
    //     u=back[u3];

    // }
    // pass.push_back(u3);
    // reverse(pass.begin(), pass.end());
    // cout<<pass.size()<<endl;
    // for (int elem: pass){
    //     cout<<elem+1<<' ';
    // }

}
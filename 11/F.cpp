#include <iostream>
#include <vector>
#include <queue>
#include <iterator>
#include <algorithm>
using namespace std;

// using graphs = vector< vector<int> >;
#define s 12;
#define f 14;

int main(){
    int n, m, k;
    int u, v;
    int x,y;
    int finish =f;
    cin >>n>>m;
    vector< vector<int> > g(n, vector<int>(m));
    for (int i=0; i<n; ++i){
        for (int j=0; j<m; ++j){
            char a;
            cin>>a;
            if (a=='.'){
                g[i][j]=1;
            } else{
                g[i][j]=2;
            }

        }

    }
    // for (int i=0; i<n; ++i){
    //     for (int j=0; j<m; ++j){
    //         cout<<g[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    cin>>x>>y;
    x--;
    y--;
    int start =k-1;
    vector< vector<int> > step(n, vector<int>(m,-1));
    vector< vector<int> > back(n*m, vector<int>(2,-1));
    queue <int> q;
    step[x][y]=0;
    back[x*m][0]=x;
    back[x*m][1]=y;   
    q.push(x);
    q.push(y);
    while(!q.empty()){
        int x1=q.front();
        q.pop();
        int y1=q.front();
        q.pop();
        // cout<<x1<<' '<<y1;
        if ((x1+1<n)&&(g[x1+1][y1]==1)){
            if (step[x1+1][y1]==-1){
                step[x1+1][y1]=step[x1][y1]+1;
                // back[v2]=u2;
                q.push(x1+1);
                q.push(y1);
            }
        }
        if(x1-1>=0){
            if (g[x1-1][y1]==1){
                if (step[x1-1][y1]==-1){
                    step[x1-1][y1]=step[x1][y1]+1;
                    // back[v2]=u2;
                    q.push(x1-1);
                    q.push(y1);
                }
            }
        }

        if ((y1+1<m)&&(g[x1][y1+1]==1)){
            if (step[x1][y1+1]==-1){
                step[x1][y1+1]=step[x1][y1]+1;
                // back[v2]=u2;
                q.push(x1);
                q.push(y1+1);
            }
        }
        if (y1-1>=0){
            if (g[x1][y1-1]==1){
                if (step[x1][y1-1]==-1){
                    step[x1][y1-1]=step[x1][y1]+1;
                    // back[v2]=u2;
                    q.push(x1);
                    q.push(y1-1);
                }
            }
        }
        // for (int i=0; i<g[u2].size();++i){
        //     int v2=g[u2][i];
        //     if (step[x1][y1]==-1){
        //         step[v2]=step[u2]+1;
        //         back[v2]=u2;
        //         q.push(v2);
        //     }
        // } 
        // // for (int v2 : g[u2]){
        // //     if (step[v2]==-1){
        // //         step[v2]=step[u2]+1;
        // //         back[v2]=u2;
        // //         q.push(v2);

        // //     }
        // }
    }
    for(int i=0; i<n;++i){
        for (int j=0;j<m;++j){
            cout<<step[i][j]<<' ';
        }
        cout<<'\n';
        
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
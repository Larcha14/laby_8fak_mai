#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int mex(vector<int> a){
    int n=a.size();
    sort(a.begin(), a.end());
    if (a[0]>0){
        return 0;
    }
    for (int i=0;i<n-1;i++){
        if(a[i]+1 <a[i+1]){
            return a[i]+1;
        }
    }
    return a.back()+1;

}

int main(){
    int n,m;
    cin>>n>>m;
    if(n%2!=0 && m%2!=0){
        cout<<2;
    } else{
        cout<<1;
    }
    // vector< vector<int> > sg(n, vector<int>(m));
    // // vector <int>sg(n+1);
    // n--;
    // m--;
    // sg[0][m]=0;
    // for(int i=n; i>0;i--){
    //     for(int j=m; j>0;j--){
    //         vector<int> tmp;
    //         tmp.push_back()
    //         sg[i][j]=mex(tmp);
    //     }

    // }
    // if(sg[n][m]==0){
    //     cout<<2;
    // } else{
    //     cout<<1;
    // }

        // cout<<'\n';
        // for (int i=0; i<=n;++i){
        //     cout<<sg[i]<<' ';
        // }
}
    
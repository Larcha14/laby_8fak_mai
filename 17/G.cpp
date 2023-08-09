#include <iostream>
#include <vector>
#include <queue>
#include <iterator>
#include <algorithm>
#include <stack>
#include <numeric>
using namespace std;

// n<12!!!!!
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<vector<int>> g(n, vector<int>(n));
    for(int i=0; i<n;++i){
        for(int j=0; j<n;++j){
            cin>>g[i][j];
        }
    }
    vector<int> a(n);
    int mn=1e9;
    iota(a.begin(), a.end(), 0); // автоматическое заполнение массива
    do{
        if(a[0]==0){
            int tmp=0;
            for(int i=0; i<n-1;++i){
                tmp+=g[a[i]][a[i+1]];
            }
            // for(int i=0;i<n;++i){
            //     cout<<a[i]<<" ";
            // }a.begin()
            mn=min(tmp, mn);
        } 
    } while(next_permutation(a.begin(), a.end()));
    cout<<mn;


}
#include <iostream>
#include <vector>
#include <queue>
#include <iterator>
#include <algorithm>
#include <stack>
#include <numeric>
using namespace std;
 
const int64_t INF = 1e9+7;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin>>n;
    int64_t sum=0;
    // vector <int64_t> p(n);
    for (int i=0; i<n;++i){
        int64_t a;
        cin>>a;
        // p[i]=a;
        sum=(sum+a)%INF;
    }
    for(int i=0; i<n-1;++i){
        sum=(sum*2)%INF;
    }
 
    cout<<sum;
}
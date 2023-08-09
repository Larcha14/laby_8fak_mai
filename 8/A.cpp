#include <iostream>
#include <vector>
#include <queue>
#include <iterator>
#include <algorithm>
#include <stack>
#include <numeric>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin>>n;
    vector <long long int> p(n+1);
    p[0]=0;
    for(int i=1; i<=n;++i){
        int a;
        cin>>a;
        p[i]=p[i-1]+a;
    }
    // cout<<n<<"  ";
    cin>>q;
    for(int i=0; i<q;++i){
        int l, r;
        long long int a;
        cin>>l>>r;
        a=p[r]-p[l-1];
        cout<<a<<'\n';
    }

}
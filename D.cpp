#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n,a,c,b,mn,p;
    p=0;
    cin>>n;
    mn=1e9;
    // vector <vector<int> > m(n, vector <int>(n));
    // vector <vector<int> > first(n, vector <int>(n));
    vector <int64_t> m(n*n);
    for (int i=0; i<n*n;++i){
            cin>>m[i];
    }
    sort(m.begin(),m.end());
    // for (int i=0; i<n*n;++i){
    //         cout<<m[i]<<' ';
    // }
    a=m[0];
    c=m[1]-a;
    b=((m[m.size()-1]-a)/(n-1))-c;
    cout<<c<<' '<<b;



}
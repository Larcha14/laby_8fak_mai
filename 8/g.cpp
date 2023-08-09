#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int64_t sum=0;
    int n, q;
    cin>>n;
    int mx;
    vector <int64_t> p(n);
    for (int i=1; i<=n;++i){
        int64_t a;
        cin>>a;
        p[i-1]=a*i*(n-i+1);
    }
    for(int i=0;i<n;++i){
        sum=sum+p[i];
    }
    cout<<sum;
}
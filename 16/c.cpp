#include <iostream>
#include <vector>
#include <queue>
#include <iterator>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

vector <int> z_func(const string & s){
    int n=s.size();
    // cout<<n;
    vector <int> z(n);
    z[0]=n;
    int l=0;
    int r=0;
    for (int i=1; i<n; ++i){
        if (i<r){
            z[i]=min(z[i-l], r-i);
        }
        while (i+z[i]<n and s[z[i]]==s[i+z[i]]){
            ++z[i]; 
        }
        if(i+z[i]>r){
            l=i;
            r=z[i]+i;
        }
    }
    return z;
}
 

 int main(){
    ios::sync_with_stdio(false);
    string s, s1, sum;    // vector<int> z=z_func(s);
    int64_t numb;
    cin>>s;
    cin>>s1;
    int flag=0;
    sum=s1+'#'+s+s;
    vector<int> z=z_func(sum);
    for (int i=1; i<sum.size();++i){
        // cout<<z[i]<<' ';
        if(z[i]==s1.size()){
            numb=2*s1.size()%(i-1);
            flag=1;
            break;
        }
    }
    if (flag!=0){
        cout<<numb;
    } else{
        cout<<"-1";
    }
 }
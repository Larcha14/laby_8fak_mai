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
    int n=s.size();
    int len=s.size();
    vector<int> z=z_func(s);
    for(int i=0; i<s.size();++i){
        // if(z[i]+i==((s.size()/2)+1))
        if ((z[i]+i==(n/2)+1)&&(n%z[i]==0)){
            if (z[i]<len){
                len=z[i];
                break;
            } else{
                // break;
            }
        }
    }
        
    for(int i=0; i<s.size();++i){
        cout<<z[i]<<' ';
    }
    cout<<'\n';
    cout<<len;
    // }
    // if (flag!=0){
    //     cout<<numb;
    // } else{
    //     cout<<"-1";
    // }
 }
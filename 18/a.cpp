#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;


int main(){
    int n,b, s;
    cin>>n;
    vector<int> a(n);
    vector<int64_t> w(n);
    vector <int>sg(n+1);
    for (int i=0; i<n;++i){
        cin>>b;
        if(i==0){
            s=b;
        } else{
            s=s^b;
        }
        
    }
    if (s>0){
        cout<<1;
    } else{
        cout<<2;
    }

    
    

}
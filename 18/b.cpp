#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;


int main(){
    int n,a,d, s, f;
    cin>>n;
    for (int i=0; i<n;++i){
        cin>>a>>d;
        f=a%(d+1);
        if (i==0){
            s=f;
        } else{
            s=s^f;
        }
        // cout<<f<<' ';   
    }
    if (s>0){
        cout<<1;
    } else{
        cout<<2;
    }
}
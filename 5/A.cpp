#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;
 
 
 
int main() {
    ios::sync_with_stdio(false);
    int64_t n, a;
    int p=0;
    cin>>a;
    if(a==1){
        cout<<1;
    } else{
        n=2;
        for (int64_t i=2;i*i<=a;++i){
            if (a%i==0){
                if (a/i!=i){
                    n+=2;
                } else{
                    n+=1;
                }
            }
        }
        cout<<n;
 
    }
}
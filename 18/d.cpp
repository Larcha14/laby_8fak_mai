#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int mex(vector<int> a){
    int n=a.size();
    sort(a.begin(), a.end());
    if (a[0]>0){
        return 0;
    }
    for (int i=0;i<n-1;i++){
        if(a[i]+1 <a[i+1]){
            return a[i]+1;
        }
    }
    return a.back()+1;

}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector <int>sg(n+1);
    // for (int i=0; i<n;++i){
    //     cin>>a[i];
    // }
     if (n<3){
       cout<<2;
    } else{
        sg[0]=0;
        sg[1]=0;
        sg[2]=0;
        for (int i=3; i<=n;++i){
            vector <int> tmp;
            int pos=((i+1)/2)-1; //идем только до середины
            for (int j=0; j<pos;++j){
                int left =j+1;
                int right = i-j-1;
                tmp.push_back(sg[left]^sg[right]);
            }
            sg[i]=mex(tmp); 
        }
        if(sg[n]==0){
            cout<<2;
        } else{
            cout<<1;
        }

        // cout<<'\n';
        // for (int i=0; i<=n;++i){
        //     cout<<sg[i]<<' ';
        // }
    }
    
    

}
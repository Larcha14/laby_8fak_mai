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
    int n, flag=0;
    cin>>n;
    vector<int> a(n);
    vector <int>sg(n+1);
    // for (int i=0; i<n;++i){
    //     cin>>a[i];
    // }
    if (n==0){
        cout<<2;
        flag=1;
    } else if (n<3)
    {
       cout<<1;
       flag=1;
    }
    if (flag!=1){
        sg[0]=0;
        sg[1]=1;
        sg[2]=1;
        for (int i=3; i<=n;++i){
            vector <int> tmp;
            int pos=(i+1)/2; //идем только до середины
            for (int j=1; j<=pos;++j){
                int left =max(0, j-2);
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
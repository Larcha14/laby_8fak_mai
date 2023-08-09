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
    int n, f;
    cin>>n;
    vector<int> a(n);
    vector <int>sg(n+1);
    vector <int> dub;
    for (int i=1; i*i<=n;++i){
        dub.push_back(i*i);
    }
    for(int i=1; i<=n;++i){
        int j=0;
        vector<int> tmp;
        while(dub[j]<=i && j<dub.size()){
            tmp.push_back(sg[i-dub[j]]);
            j++;
            // cout<<dub[j];
        }
        // cout<<tmp.size();
        // for(int j=0;j<tmp.size();++j){
        //     cout<<tmp[j];
        // }
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
    
    


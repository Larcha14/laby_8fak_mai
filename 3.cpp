#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;
 
const int INF=1e9+7;

// int fact(int a){
//     vector <int> fa(a-1);
//     int b=1;
//     for (int i=a; i<a+1;++i){
//         fa[i]=i;
//         cout<<fa[i]<<' ';
//     }
//     cout<<endl;
//     return b;
// }

// int raznfact(int a, int b, int mn){  //b>a
//     int c=a+1;
//     vector <int> ra(b-a);
//     for (int i=0; i<b-a;++i){
//         ra[i]=c;
//         c+=1;
//         cout<<ra[i]<<' ';
//     }
//     cout<<endl;
//     return c;
// }

// int cf(int a, int b){
//     int answ;
//     int mn=min(a,b);
//     int mx=a+b-mn;
//     answ=(raznfact(mx, a+b,mn)/fact(mn))%INF;
//     return answ-1;
// }

 int main(){
    ios::sync_with_stdio(false);
    int k1,k2,k3,s;
    char y;
    k1=0;
    k2=0;
    s=1;
    string a;
    cin>>a;
    for (int i=0; i<a.size();++i){
        if (a[i]=='('){
            k1+=1;
        } else {
            k2+=1;
        }
    }
    if ((k1==0) || (k2==0)){
        cout<<0;
    } else if( (k1==1) || (k2==1)){
        cout<<(k1*k2)%INF;
    } else {
        int mn=min(k1,k2);
        int mx=k1+k2-mn;
        k3=k1+k2-mx;
        int c=mx+1;
        vector <int> fa(mn-1);
        vector <int> ra(k3);
        for (int i=0; i<k3;++i){
            ra[i]=c;
            c+=1;
            // cout<<ra[i]<<' ';
        }
        // cout<<endl;
        c=2;
        for (int i=0; i<mn-1;++i){
            fa[i]=c+i;
            // cout<<fa[i]<<' ';
        }
        for (int i=0; i<fa.size();++i){
            for (int j=0; j<ra.size();++j){
                if(ra[j]%fa[i]==0){
                    ra[j]=ra[j]/fa[i];
                    break;
                }
            }
        }
        for (int i=0; i<ra.size();++i){
            s=(s*ra[i])%INF;
        }
        cout<<(s%INF)-1;
    }
    

 }
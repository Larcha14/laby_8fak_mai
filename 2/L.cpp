#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <string.h>
using namespace std;

#define N 19

int main(){
    ios::sync_with_stdio(false);
    string a;
    vector <int> drob(15); // дробная часть
    vector <int> osnov(N); // целая часть
    int z,l, l_d, l_o,flag;
    char a1;
    while(cin>>a){ //ввод чисел 
        l_o=0;
        while(a[l_o]!='.'){
            l_o++;
        }
        l=l_o;
        z=0;
        for (int i=N-1; i>N-1-l_o; --i){
            osnov[i]= osnov[i]+z+int(a[l-1])-'0';
            if (osnov[i]>9){
                osnov[i]=osnov[i]%10;
                z=1;
            } else{
                z=0;
            }            
            // cout<<osnov[i]<<' ';
            l--;
        }
        if (z!=0){
            for(int i=N-1-l_o; i>=0;--i){
                osnov[i]+=z;
                if (osnov[i]>9){
                    osnov[i]=osnov[i]%10;
                    z=1;
                } else{
                    z=0;
                    break;
                }     
            }
        }
        z=0;
        l_d=a.size()-l_o-1;
        l=a.size();
        for (int i=l_d-1; i>=0; --i){
            drob[i]= drob[i]+z+int(a[l-1])-'0';
            if (drob[i]>9){
                drob[i]=drob[i]%10;
                z=1;
            } else{
                z=0;
            }            
            l--;
        }
        if (z!=0){
            for(int i=N-1; i>=0;--i){
                osnov[i]+=z;
                if (osnov[i]>9){
                    osnov[i]=osnov[i]%10;
                    z=1;
                } else{
                    z=0;
                    break;
                }     
            }
        }
        z=0;
        // // cout<<l_o<<' '<<l_d<<'\n';
        // for (int i=0; i<=17;++i){

        //     cout<<osnov[i];
        // }
        // cout<<'.';
        // for (int i=0; i<=14;++i){
        //     cout<<drob[i];
        // }
        // cout<<'\n';
    }
    flag=1;
    for (int i=0; i<=N-1;++i){
        if (flag==1 && osnov[i]==0){

        } else{
            flag=0;
            cout<<osnov[i];

        }
    }
    if (flag==1){
        cout<<0;
    }
    cout<<'.';
    for (int i=0; i<=14;++i){
        cout<<drob[i];
    }

}
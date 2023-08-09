#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <string.h>
#include <map>
#include <functional>
using namespace std;


// vector <string> read(string a){
//     vector <string> words(3);
//     string a1;
//     int i=0, l;
//     l=a.size();
//     for (int j=0; j<2; ++j){
//         a1="";
//         while(a[i]!=0){
//             a1.push_back(a[i]);
//             ++i;
//         }
//         ++i;
//         words[j]=a1;
//     }
//     a1="";
//     for (int j=i; j<l; ++j){
//         a1.push_back(a[j]);
//     }
//     words[2]=a1;
//     return words;

// }

int main(){
    ios::sync_with_stdio(false);
    map <string, string> dict;
    map <string, int> log;
    string a,a1, a2;
    vector <string> words;
    int flag;
    flag=0; // 0 - регистрация; 1 - log in 2 - logout
    while(cin>>a>>a1){
        map <string, string>:: iterator it;
        it =dict.find(a1);
        if(a=="register"){
            cin>>a2;
            if(it==dict.end()){
                dict[a1]=a2;
                log[a1]=0;
                cout<<"account created";
            } else{
                cout<<"login already in use";
            }
        } else if(a=="login"){
            cin>>a2;
            if(it!=dict.end()){

                if(dict[a1]==a2){
                    if (log[a1]==0){
                        log[a1]=1;
                        cout<<"logged in";
                    } else{
                        cout<<"already logged in";
                    }
                } else{
                    cout<<"wrong account info";
                }
            } else{
                cout<<"wrong account info";
            }            
        } else if(a=="logout"){
            if (log[a1]==1){
                cout<<"logged out";
                log[a1]=0;

            } else{
                cout<<"incorrect operation";
            }
        } else{
            cout<<"incorrect operation";
        }
        cout<<'\n';
    }

}
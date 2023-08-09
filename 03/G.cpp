#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;
 
 
 
int main() {
    int n,p,l;
    char b;
    ios::sync_with_stdio(false);
    cin>>n;
    l=0;
    p=1;
    vector<char>c;
    vector<char >a(n);
    for (int i=0; i<n;++i){
        cin>>b;
        a[i]=b;
        
    }
    if (a[0]=='(' or a[0]=='[' or a[0]=='{' ){
            c.push_back(a[0]);
    } else {
        p=0;
    }
    if (p!=0){
        for (int i=1; i<n;++i){
            if (a[i]=='(' or a[i]=='[' or a[i]=='{' ){
                c.push_back(a[i]);
            } else{
                l=c.size();
                if (a[i]==')' and c[l-1]=='(' ){
                    c.pop_back();
                }
                if (a[i]==')' and c[l-1]!='(' ){
                        p=0;
                        break;
                }
                if ( a[i]==']' and c[l-1]=='['){
                    c.pop_back();
                }
                if ( a[i]==']' and c[l-1]!='['){
                    p=0;
                    break;
                }
                if ( a[i]=='}' and c[l-1]=='{'){
                    c.pop_back();
                }
                if ( a[i]=='}' and c[l-1]!='{'){
                    p=0;
                    break;
                }
            }
        
        }
    }
    l=c.size();
    if (p==1 and l==0){
        cout<<"Ja";
    } else {
        cout<<"Nein";
    }
}
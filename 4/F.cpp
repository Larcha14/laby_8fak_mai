#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <string.h>
#include <stack>
#include <functional>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    int n,a1, a2;
    cin>>n;
    vector <int> numb(n);
    stack <int> clans;
    for (int i=0; i<n; ++i){
        cin>>numb[i];
    }
    sort(numb.begin(), numb.end());
    for (int i=n-1; i>=0; --i){
        clans.push(numb[i]);
    }
    for (int i=0; i<n-1; ++i){
        a1=clans.top();
        clans.pop();
        a2=clans.top();
        clans.pop();
        cout<<a1<<' '<<a2;
        clans.push(a1+a2);
    }


}
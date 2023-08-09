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
    stack <int64_t> calculate;
    char a;
    int64_t a1,a2;
    while(cin>>a){
        if((a=='+')||(a=='-')||(a=='*')){
            a2=calculate.top();
            calculate.pop();
            a1=calculate.top();
            calculate.pop();
            if (a=='+'){
                calculate.push(a1+a2);
            } else if(a=='-'){
                calculate.push(a1-a2);
            } else{
                calculate.push(a1*a2);
            }
        } else{
            calculate.push(a-'0');

        }
    }
    cout<<' '<<calculate.top();
}

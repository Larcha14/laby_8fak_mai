#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;


int main(){
    int n,a,s;
    int cnt_1=0, cnt_2=0, cnt_3=0, cnt_4=0;
    cin>>n;
    for (int i=0; i<n;++i){
        cin>>a;
        if(a==1){
            cnt_1++;
        }else if(a==2){
            cnt_2++;
        } else if(a==3){
            cnt_3++;
        } else{
            cnt_4++;
        }
        // cout<<f<<' ';   
    }
    s=cnt_1/2+cnt_2/2+cnt_3/2+cnt_4/2+(cnt_1%2)*(cnt_2%2)*(cnt_3%2);
    cout<<s;
}
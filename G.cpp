#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <algorithm>
#include <iomanip>
using namespace std;

double const Kor2=1.4142135623730951455;
double const PU =3.141592653589793116;
int main(){
    ios::sync_with_stdio(false);
    double a,h,s;
    cin>>a>>h;
    s=2*PU*(a*a+2*h*h+a*h*Kor2);

    cout<<setprecision(11)<<s;
}
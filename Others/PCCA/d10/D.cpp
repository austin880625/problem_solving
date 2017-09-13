#include <stdio.h>
#include <iostream>
#define PI 3.1415926535
using namespace std;

int main(){
    double d,h,v,e;
    while(cin>>d>>h>>v>>e){
        double a=d*d/4.0*PI;
        cout<<(e>=v/a ? "NO": "YES")<<endl;
        if(e<v/a)cout<<h/(v/a-e)<<endl;
    }
}

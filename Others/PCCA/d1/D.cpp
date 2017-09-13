#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <string.h>

using namespace std;

string a,b;
double p;

int main(){
    while(cin>>a>>b){
        int x1=0;
        for(int i=0;i<a.length();i++)x1+=(a[i]=='+' ? 1 : -1);
        int x2=0,t=0;
        for(int i=0;i<b.length();i++){
            if(b[i]=='+')x2++;
            if(b[i]=='-')x2--;
            if(b[i]=='?')t++;
        }
        int d=((x1-x2)+t)/2;
        p=0;
        if(abs(d)<=t){
            int n=1;
            for(int i=d+1;i<=t;i++)n*=i;
            for(int i=1;i<=t-d;i++)n/=i;
            p=n;
            for(int i=0;i<t;i++)p/=2.0;
        }
        printf("%.9f\n",p);
    }
    return 0;
}

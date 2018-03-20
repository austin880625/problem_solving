#include <stdio.h>
#include <iostream>
#include <math.h>
#include <assert.h>

#define eps 1e-12
#define PI 3.1415926535897932384626433

using namespace std;

int T,N;
int maxi;
double c,maxl;
double L[100];

double test(bool outside, double r){
    double ang=0;
    for(int i=0;i<N;i++){
        if(i==maxi&&outside)continue;
        ang+=2*asin(L[i]/(2*r));
    }
    if(outside)return ang-2*asin(maxl/(2*r));
    return ang-2*PI;
}

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%lf%d",&c,&N);
        maxl=0.0;maxi=-1;
        for(int i=0;i<N;i++){scanf("%lf",L+i);if(maxl<L[i]){maxl=L[i],maxi=i;}}
        double l=maxl/2,r=10000;
        assert(l<r);
        double inside=test(0,l);
        assert(fabs(test(1,l)-inside)<eps);
        //cout<<inside<<endl;
        for(int i=0;i<500;i++){
            double mid=(l+r)/2.0;
            if(test(inside<0,mid)>0){
                if(inside>0)l=mid;
                else r=mid;
            }
            else{
                if(inside>0)r=mid;
                else l=mid;
            }
        }
        //cout<<r<<endl;
        double A=0;
        for(int i=0;i<N;i++){
            A+=(L[i]/2)*sqrt(l*l-(L[i]/2)*(L[i]/2));
        }
        if(inside<0)A-=2*((maxl/2)*sqrt(l*l-(maxl*maxl/4.0)));
        //cout<<A<<endl;
        //printf("%.16f\n",A);
        printf("%.16f\n",(c*c/(4*PI))-A);
    }
    return 0;
}

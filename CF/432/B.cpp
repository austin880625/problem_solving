#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

#define MAXN
#define LL long long int

using namespace std;

LL ax,bx,cx,ay,by,cy;

LL det(LL a,LL b,LL c,LL d,LL e,LL f,LL g,LL h,LL i)
{
    return a*e*i+b*f*g+c*d*h-c*e*g-a*h*f-b*d*i;
}

LL gcd(LL a,LL b)
{
    if(a<b)swap(a,b);
    a=a>0?a:-a;b=b>0?b:-b;
    return b ? gcd(b,a%b) : a;
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    while(cin>>ax>>ay>>bx>>by>>cx>>cy){
        LL pxp,pxq,pyp,pyq;
        pxp=pyp=2*det(ax,ay,1,bx,by,1,cx,cy,1);
        pxq=det(ax*ax+ay*ay,ay,1,bx*bx+by*by,by,1,cx*cx+cy*cy,cy,1);
        pyq=det(ax,ax*ax+ay*ay,1,bx,bx*bx+by*by,1,cx,cx*cx+cy*cy,1);
        //cout<<pxq<<" "<<pxp<<" "<<pyq<<" "<<pyp<<endl;
        if(pxp==0){cout<<"No"<<endl;continue;}
        LL d=gcd(pxp,pxq);pxp/=d;pxq/=d;
        d=gcd(pyp,pyq);pyp/=d;pyq/=d;
        LL dot1q=(ax*pxp-pxq)*(bx*pxp-pxq)*(pyp*pyp)+(ay*pyp-pyq)*(by*pyp-pyq)*(pxp*pxp);
        LL dot1p=pxp*pxp*pyp*pyp;
        d=gcd(dot1p,dot1q);dot1p/=d;dot1q/=d;
        LL dot2q=(bx*pxp-pxq)*(cx*pxp-pxq)*(pyp*pyp)+(by*pyp-pyq)*(cy*pyp-pyq)*(pxp*pxp);
        LL dot2p=pxp*pxp*pyp*pyp;
        d=gcd(dot2p,dot2q);dot2p/=d;dot2q/=d;
        //cout<<dot1p<<" "<<dot1q<<" "<<dot2p<<" "<<dot2q<<endl;
        if(dot1p==dot2p&&dot1q==dot2q)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}

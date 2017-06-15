#include <stdio.h>
#include<iostream>
#include<fstream>
#include<queue>
#include<stack>
#include<vector>
#include<utility>
#include<string>
#include<map>
#include<algorithm>
#include"../Libraries/Vectors.h"
#define isFile 0
#define Problem "A"
#define SL 0
#define filePath "./"
#define lp1(I,A) for(int I=0;I<(A);I++)
#define lp2(I,A,B) for(int I=(A);I<(B);I++)
#define lp3(I,A,B) for(int I=(A);I>=(B);I--)

using namespace std;
typedef long long int ll;

ll reverse(ll x)
{
    ll res=0,tmp=x;
    while(tmp>0)
    {
        res*=10;
        res+=(tmp%10);
        tmp/=10;
    }
    return res;
}

int main()
{
    if(isFile)
    {
        string fileName=Problem;
        if(SL)fileName+="-large";
        else fileName+="-small";
        freopen((filePath+fileName+".in").c_str(),"r",stdin);
        freopen((filePath+fileName+".out").c_str(),"w",stdout);
    }
    int T;
    cin>>T;
    lp2(kase,1,T+1)
    {
        ll N,ans=1,now=1;
        cin>>N;
        //cout<<reverse(N);
        while(now<N)
        {
            if(reverse(now)>now&&reverse(now)<=N)
            {
                ll m=now;
                int i,t=0;
                for(i=now;i<N;i++)
                {
                    if(reverse(i)<=N)
                    {
                        m=max(m,reverse(i));
                        t++;
                    }
                    else break;
                }
                now=m;
                ans+=(t);
            }
            else if(now<N)
            {
                ans++;
                now++;
            }
            //cout<<now<<endl;
            if(now==N)break;
        }
        cout<<"Case #"<<kase<<": "<<ans<<endl;
    }
}
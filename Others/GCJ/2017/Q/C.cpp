#include <stdio.h>
#include <iostream>
#include <set>
#include <queue>
#define LL long long int

using namespace std;

int T;
LL N,K;

struct ent
{
    LL x,cnt;
    bool operator <(const ent& r)const
    {
        return x>r.x;
    }
};

set<ent> Q;

int main()
{
    scanf("%d",&T);
    for(int kase=1;kase<=T;kase++)
    {
        scanf("%lld%lld",&N,&K);
        Q.insert((ent){N,1});
        LL R,L;
        while(1)
        {
            set<ent>::iterator t=Q.begin();
            //cout<<t<<endl;
            LL l=((*t).x-1)/2,r=(*t).x/2;
            //cout<<(*t).x<<" "<<r<<" "<<l<<endl;
            if(K<=(*t).cnt){R=r,L=l;break;}
            K-=(*t).cnt;
            set<ent>::iterator it=Q.find((ent){l,0});
            LL tmp=(*t).cnt;
            if(it==Q.end())Q.insert((ent){l,(*t).cnt});
            else
            {
                tmp+=(*it).cnt;
                Q.erase(it),Q.insert((ent){l,tmp});
            }
            it=Q.find((ent){r,0});
            tmp=(*t).cnt;
            if(it==Q.end())Q.insert((ent){r,(*t).cnt});
            else
            {
                tmp+=(*it).cnt;
                Q.erase(it),Q.insert((ent){r,tmp});
            }

            Q.erase(t);
        }
        printf("Case #%d: %lld %lld\n",kase,R,L);
        Q.clear();
    }
    return 0;
}

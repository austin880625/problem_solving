#include <stdio.h>
#include <iostream>
#include <set>
#include <algorithm>

#define LL long long int
#define pii pair<int,LL>
#define MAXN 100005
const LL INF=(1LL<<62)-1;

using namespace std;

int N,M,K;
set<int> inCapital;
set<pii > S;

struct flight
{
    int d,f,t;
    LL c;
    bool operator <(const flight &x)const
    {
        return d<x.d;
    }
};
flight F[MAXN];
LL ans_arr[MAXN],ans_dep[MAXN];

int main()
{
    while(cin>>N>>M>>K)
    {
        inCapital.clear();S.clear();
        for(int i=0;i<M;i++)
        {
            cin>>F[i].d>>F[i].f>>F[i].t>>F[i].c;
        }
        sort(F,F+M);
        for(int i=1;i<=N;i++)ans_arr[i]=ans_dep[i]=INF;
        LL s=0,sans=-1;
        for(int i=0;i<M;i++)
        {
            //cout<<i<<" "<<F[i].t<<" "<<F[i].c<<" "<<F[i].d<<endl;
            if(F[i].t==0){
                inCapital.insert(F[i].f);
                if(ans_arr[F[i].f]!=INF)s-=ans_arr[F[i].f];
                ans_arr[F[i].f]=min(ans_arr[F[i].f],F[i].c);
                s+=ans_arr[F[i].f];
                if(inCapital.size()==N)
                {
                    //cout<<"inserting "<<F[i].d<<" "<<s<<endl;
                    S.insert(pii(-F[i].d,s));
                }
            }
        }
        if(inCapital.size()<N){cout<<"-1"<<endl;continue;}
        s=0;
        for(int i=M-1;i>=0;i--)
        {
            //cout<<i<<" "<<F[i].t<<" "<<F[i].c<<" "<<F[i].d<<endl;
            if(F[i].f==0){
                inCapital.erase(F[i].t);
                //cout<<inCapital.size()<<endl;
                if(ans_dep[F[i].t]!=INF)s-=ans_dep[F[i].t];
                ans_dep[F[i].t]=min(ans_dep[F[i].t],F[i].c);
                s+=ans_dep[F[i].t];
                if(inCapital.size()==0)
                {
                    //cout<<i<<" "<<F[i].t<<" "<<F[i].c<<" "<<F[i].d<<endl;
                    set<pii >::iterator it=S.upper_bound(pii(-(F[i].d-K),INF));
                    if(it!=S.end()){
                        if(sans==-1)sans=(*it).second+s;
                        else sans=min(sans,(*it).second+s);
                        //cout<<s<<" "<<(*it).second<<endl;
                    }
                }
            }
        }
        if(inCapital.size()>0){cout<<"-1"<<endl;continue;}
        cout<<sans<<endl;
    }
    return 0;
}

#include <iostream>
#include <stdio.h>
#include <vector>
#include <assert.h>
#include <queue>
#include <time.h>
#define LL long long int
#define MAXN 500005
using namespace std;
vector<LL> child[MAXN];
LL prime[MAXN];
//vecto<LL> pos;
LL isprime[MAXN+5];
LL P;
int factor[MAXN];
LL sz[MAXN];
LL szcnt[MAXN];
LL vis[MAXN];
LL pa[MAXN];
LL T,N,M;
queue<LL> S;
void getsz()
{
    for(LL i=1;i<=N;i++)if(child[i].size()==0)S.push(i);
    while(!S.empty())
    {
        LL x=S.front();S.pop();
        sz[x]++;
        vis[pa[x]]--;
        //cout<<x<<" "<<sz[x]<<endl;
        if(pa[x]!=0)sz[pa[x]]+=sz[x];
        if(pa[x]!=0&&!vis[pa[x]]){S.push(pa[x]);}
    }
}

void gen_prime()
{
    prime[0]=2;prime[1]=3;
    isprime[2]=1;isprime[3]=2;
    LL t=2;
    while(prime[t-1]<MAXN)
    {
        prime[t]=prime[t-1];
        LL k;
        while(1){
            prime[t]+=2;
            k=1;
            for(LL i=0;prime[i]<=prime[t]/prime[i];i++)if(!(prime[t]%prime[i])){k=0;break;}
            if(k)break;
        }
        isprime[prime[t]]=t+1;
        t++;
    }
    P=t;
}

void frac(LL sgn,LL x)
{
    //cout<<i<<endl;
    for(LL i=0;i<P;i++)
    {
        if(x==1)return ;
        while(x%prime[i]==0){x/=prime[i];factor[i]+=sgn;}
        //cout<<i<<" "<<isprime[x]<<endl;
        if(isprime[x]){factor[isprime[x]-1]+=sgn;return;}
    }
}

int main()
{
    scanf("%lld",&T);
    gen_prime();
    //for(LL i=0;i<5;i++)printf("%d ",prime[i]);
    while(T--)
    {
        //clock_t start,stop;
        //p[1]=-1;
        scanf("%lld%lld",&N,&M);
        for(LL i=0;i<=N;i++){sz[i]=0;child[i].clear();vis[i]=0;szcnt[i]=0;}
        for(int i=0;i<=P;i++)factor[i]=0;
        for(LL i=2;i<=N;i++)
        {
            scanf("%lld",&pa[i]);
            child[pa[i]].push_back(i);
            vis[pa[i]]++;
        }
        //assert(0);
        getsz();
        //assert(0);
        //for(int i=1;i<=N;i++)cout<<sz[i]<<" ";puts("");
        for(int i=1;i<=N;i++){szcnt[sz[i]]++;}
        //assert(0);
        LL ans=1LL;
        //for(LL i=1;i<MAXN;i++)frac(1,i);
        //assert(0);
        //for(LL i=1;i<MAXN;i++)frac(-1,i);

        //start=clock();
        //cout<<sz[1]<<endl;
        for(LL i=N-1;i>1;i--)
        {
        //cout<<"now "<<i<<endl;
            frac(1,i);
            //for(int i=0;i<5;i++)cout<<prime[i]<<" "<<factor[i]<<endl;
            if(szcnt[i])frac(-szcnt[i],i);
            //else printf("YA%d\n",i);
            //if(i%10000==0)printf("%d\n",(clock()-start)/1000);
        }
        //stop=clock();
        //cout<<"Time is"<<(stop-start)/CLOCKS_PER_SEC<<endl;
        //start=clock();
        //if(T==93)for(int i=0;i<P;i++){cout<<i<<" "<<factor[i]<<endl;}
        for(LL i=0;i<P;i++)
        {
            LL power,prod=prime[i];
            if(factor[i]==0LL)continue;
            LL x=1LL;
            //if(i==3)cout<<factor[i]<<endl;
            for(power=0;(1LL<<power)<=factor[i];power++)
            {
                if((factor[i]>>power)&1LL)x=x*prod%M;
                prod=prod*prod%M;
                //cout<<power<<endl;
            }
            //if(i==3)assert(0);
            ans=(ans*x)%M;
            //cout<<i<<endl;
        }
        //stop=clock();
        //cout<<"Time is"<<(stop-start)/CLOCKS_PER_SEC<<endl;
        //cout<<sz[1]<<" "<<sz[3]<<endl;
        printf("%lld\n",ans);
    }
}

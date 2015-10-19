#include<iostream>
#include<math.h>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>

using namespace std;

int isprime[50005];
vector<int> power;
vector<int> factor;
vector<int> prime;

void pre_process()
{
    prime.push_back(2);prime.push_back(3);
    for(int i=2;;i++)
    {
        prime.push_back(prime[i-1]);
        while(1)
        {
            int j;
            prime[i]+=2;
            for(j=0;prime[j]<=prime[i]/prime[j]&&prime[i]%prime[j];j++){}
            if(prime[i]%prime[j])break;
        }
        if(prime[i]>2147483647/prime[i])break;
    }
}

priority_queue<int,vector<int>,greater<int> > Q;
int n;

void dfs(int now,int pos)
{
    //for(int i=0;i<pos;i++)cout<<"\t";
    //cout<<pos<<" "<<now<<" "<<power[pos]<<endl;
    if(pos==factor.size()){Q.push(now);return ;}
    int t=1;
    for(int i=0;i<=power[pos];i++){dfs(now*t,pos+1);t*=factor[pos];}
}

int main()
{
    pre_process();
    while(scanf("%d",&n)==1)
    {
        //cout<<n<<endl;
        factor.clear();
        power.clear();
        //cout<<prime.size()<<endl;
        int t=0;
        while(n!=1&&prime[t]<=n/prime[t])
        {
            //cout<<prime[t]<<endl;
            int p=0;
            if(!(n%prime[t])){factor.push_back(prime[t]);}
            while(!(n%prime[t]))
            {
                n/=prime[t];
                p++;
            }
            //cout<<power[factor.size()-1]<<endl;
            if(p)power.push_back(p);
            t++;
        }
        if(n!=1){factor.push_back(n);power.push_back(1);}
        //cout<<"s "<<factor.size()<<endl;
        dfs(1,0);
        while(!Q.empty())
        {
            printf("%d ",Q.top());Q.pop();
        }
        printf("\n");
    }
    return 0;
}

#include <iostream>
#include <stdio.h>
#include <assert.h>
#include <vector>

using namespace std;

int T,N,A,B,C;
int vis[20000];
vector<int> V;
int mabs(int x){return x>0 ? x : -x;}
int main()
{
    //int kase=0;
    while(scanf("%d",&T)==1)
    {
        //assert(kase==0);
        //kase++;
        while(T--)
        {
            scanf("%d%d%d",&A,&B,&C);
            N=A+B+C;
            V.clear();
            for(int i=0;i<=N;i++)vis[i]=0;
            int a=A,b=B,c=C;
            int now=0;
            int q=C%3;
            printf("0");
            V.push_back(0);
            if(q<2)
            {
                while(now<C+1-!q)now+=3,c--,printf(" %d",now),V.push_back(now);//now-=3;
                if(q==0)now+=2,b--,printf(" %d",now),V.push_back(now);
                if(q==1)now-=2,b--,printf(" %d",now),V.push_back(now);
                while(now>2)now-=3,c--,printf(" %d",now),V.push_back(now);//now+=3;
                if(q==0)now-=1,a--,printf(" %d",now),V.push_back(now);
                if(q==1)now+=1,a--,printf(" %d",now),V.push_back(now);
                while(now<C+1)now+=3,c--,printf(" %d",now),V.push_back(now);//now-=3;
                assert(now==C+1);
            }
            else
            {
                while(now<C+1)now+=3,c--,printf(" %d",now),V.push_back(now);
                now-=1,a--,printf(" %d",now),V.push_back(now);
                while(now>2)now-=3,c--,printf(" %d",now),V.push_back(now);
                now-=1,a--,printf(" %d",now),V.push_back(now);
                while(now<C+2)now+=3,c--,printf(" %d",now),V.push_back(now);
            }
            //cout<<a<<" "<<b<<" "<<c<<endl;
            assert(a&&b&&(c==0));
            if(now==C+1)b--,now+=2,printf(" %d",now),V.push_back(now);
            //assert(a&&now==C+3);
            while(a>1)a--,now+=1,printf(" %d",now),V.push_back(now);
            int p=b/2+b%2;
            int d=b%2 ? -1 : 1;
            while(p--)b--,now+=2,printf(" %d",now),V.push_back(now);
            a--,now+=1*d,printf(" %d",now),V.push_back(now);
            while(b)b--,now-=2,printf(" %d",now),V.push_back(now);
            puts("");
            int x[4]={0,0,0,0};
            for(int i=0;i<V.size();i++)
            {
                if(!vis[V[i]])
                {
                    vis[V[i]]=1;
                    if(i)x[mabs(V[i]-V[i-1])]++;
                }
                else assert(0);
            }
            assert(A==x[1]&&B==x[2]&&C==x[3]);
            //puts("");
            //cout<<a<<b<<c<<endl;
            assert(a==0&&b==0&&c==0);
        }
    }
    return 0;
}

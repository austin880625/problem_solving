#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <set>
#define LL long long int
#define MAXN 100005

using namespace std;

int N,M,K;
int dr,dc;
LL INF=(1LL<<62)-1LL;

struct poi
{
    LL t;int r,c;
    bool operator <(const poi &rhs)const
    {
        if(r<rhs.r)return true;
        if(r>rhs.r)return false;
        return c<rhs.c;
    }
};

vector<poi> s;
vector<poi> sp;
set<poi> lines;
LL ANS[MAXN];

inline bool atCorner(int r,int c)
{
    return (r==0&&c==M)||(r==N&&c==0)||(r==N&&c==M);
}

int main()
{
    while(scanf("%d%d%d",&N,&M,&K)==3)
    {
        lines.clear();
        s.clear();
        sp.clear();
        sp.push_back((poi){0,0,0});
        for(int i=0;i<K;i++)
        {
            ANS[i]=0;
            int r,c;
            scanf("%d%d",&r,&c);
            s.push_back((poi){i,r,c});
        }
        dr=1;dc=1;
        int nowr=0,nowc=0,nxtr=0,nxtc=0;
        int h=min(N,M),l=max(N,M),i=1;
        long long int t=0;
        while(!atCorner(nowr,nowc))
        {
            nxtr=nowr+dr*h;
            nxtc=nowc+dc*h;
            t+=(LL)h;
            sp.push_back((poi){t,nxtr,nxtc});
            lines.insert((poi){i++,dr*dc,(nxtr-dr*dc*nxtc)});
            if(nxtr==0||nxtr==N)
            {
                dr=-dr;
                l=dc==1 ? M-nxtc : nxtc;h=N;
                if(l<h)swap(h,l);
            }
            if(nxtc==0||nxtc==M)
            {
                dc=-dc;
                l=dr==1 ? N-nxtr : nxtr;h=M;
                if(l<h)swap(h,l);
            }
            nowr=nxtr,nowc=nxtc;
        }
        //printf("traversal done %d\n",sp.size());
        for(i=0;i<s.size();i++)
        {
            set<poi>::iterator it1=lines.find((poi){0,1,s[i].r-s[i].c});
            if(it1!=lines.end())ANS[i]=abs(s[i].r-sp[(*it1).t-1].r)+sp[(*it1).t-1].t;
            else ANS[i]=INF;
            set<poi>::iterator it2=lines.find((poi){0,-1,s[i].r+s[i].c});
            if(it2!=lines.end())ANS[i]=min(abs(s[i].r-sp[(*it2).t-1].r)+sp[(*it2).t-1].t , ANS[i]);
        }

        //dq(1,sp.size(),s);

        for(int i=0;i<K;i++)
        {
            printf("%I64d\n",ANS[i]!=INF ? ANS[i] : -1);
        }
    }
}

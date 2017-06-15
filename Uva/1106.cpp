#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#define MAXN 100005
#define LL1 long long int
#define LL2 __int128

using namespace std;

struct mac
{
	LL2 d;
	LL2 p,r,g;
	bool operator <(const mac &x)const
	{
		return d<x.d;
	}
};

struct line
{
	LL2 m,b; //y=mx+b
	line(){}
	line(LL2 _m,LL2 _b){m=_m,b=_b;}
	bool operator <(const line &x)const
	{
		if(m==x.m)return b>x.b;
		return m<x.m;
	}
	inline LL2 operator ()(const LL2 d)const
	{
		return m*d+b;
	}
};

inline void getLL(LL2 &x)
{
	x=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9'){x*=10;x+=c-'0';c=getchar();}
}
void print(LL2 x)
{
	if(x==0)puts("0");
	static vector<int> dig;
	dig.clear();
	while(x)
	{
		dig.push_back((int)(x%(LL2)10));
		x/=(LL2)10;
	}
	for(int i=dig.size()-1;i>=0;i--)
	{
		printf("%d",dig[i]);
	}
}

int N;
LL2 D;
mac M[MAXN];
LL2 C;
LL2 dp[MAXN];

inline bool check(line x,line y,line z)
{
	return (y.b-z.b)*(z.m-x.m)<=(x.b-z.b)*(z.m-y.m);
}

line lns[MAXN];
line stk[MAXN];
int s_rr;
void dq(int s,int e)
{
	static vector<line> stk;
    static vector<line> lns;
    int mid=(s+e)/2;
    if(s==e)return ;
    dq(s,mid);

    lns.clear();
    for(int i=s;i<=mid;i++)
	{
		if(dp[i]>=M[i].p)lns.push_back(line(M[i].g,dp[i]-M[i].p+M[i].r-M[i].g*(M[i].d+1LL)));
	}
	sort(lns.begin(),lns.end());
	stk.clear();
	for(int i=0;i<lns.size();i++)
	{
		line L=lns[i];
		while(stk.size()&&stk.back().m==L.m&&stk.back().b<L.b)stk.pop_back();
		if(stk.size()&&stk.back().m==L.m)continue;

		while(stk.size()>=2&&check(stk[stk.size()-2],stk.back(),L))stk.pop_back();
		stk.push_back(L);
	}
	int fr=0;
	for(int i=mid+1;i<=e;i++)
	{
		LL2 x=M[i].d;
		while(fr+1<stk.size()&&stk[fr](x)<stk[fr+1](x))fr++;
		dp[i]=max(dp[i],stk[fr](x));
	}
	dq(mid+1,e);
}

int main()
{
	int tt=0;
	while(scanf("%d",&N)==1){
	getLL(C);getLL(D);
	if(!N&&!C&&!D)break;
	M[0]=(mac){0,0,C,0};
	M[N+1]=(mac){D+1,0,0,0};
	for(int i=1;i<=N;i++)
	{
		getLL(M[i].d);
		getLL(M[i].p);
		getLL(M[i].r);
		getLL(M[i].g);
		dp[i]=0;
	}
	dp[N+1]=0;
	sort(M+1,M+1+N);
	dp[0]=0;
	dq(0,N+1);
	printf("Case %d: ",++tt);
    if(dp[N+1]<=(LL2)0x7fffffffffffffffLL)printf("%lld",(LL1)dp[N+1]);
    else print(dp[N+1]);
    puts("");
	}
	return 0;
}

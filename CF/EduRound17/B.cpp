#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define LL long long int

struct mouse
{
	int id;
	LL v;
	bool operator <(const mouse &r)const
	{
		return v<r.v;
	}
};

vector<mouse> PS2;
vector<mouse> USB;
int A,B,C,N,M;
char mt[10];
int remain;
LL SU[300005],SP[300005];

int main()
{
	while(scanf("%d%d%d",&A,&B,&C)==3)
	{
		USB.clear();PS2.clear();
		N=A+B+C;
		remain=N;
		scanf("%d",&M);
		for(int i=0;i<M;i++)
		{
			int v;
			scanf("%d%s",&v,mt);
			if(mt[0]=='U')USB.push_back((mouse){i,(LL)v});
			else PS2.push_back((mouse){i,(LL)v});
		}
		sort(USB.begin(),USB.end());
		sort(PS2.begin(),PS2.end());
		SP[0]=SU[0]=0;
		for(int i=1;i<=USB.size();i++)
		{
			SU[i]=SU[i-1]+USB[i-1].v;
		}

		for(int i=1;i<=PS2.size();i++)
		{
			SP[i]=SP[i-1]+PS2[i-1].v;
		}
		LL ans=0;
		for(int i=0;i<=C;i++)
		{
			int u=A+i,p=B+C-i,r=0;
			LL tmp=0;
			if(u>USB.size())
			{
				r+=u-USB.size();
				tmp+=SU[USB.size()];
			}
			else
			{
				tmp+=SU[u];
			}

			if(p>PS2.size())
			{
				r+=p-PS2.size();
				tmp+=SP[PS2.size()];
			}
			else
			{
				tmp+=SP[p];
			}
			if(r<remain)
			{
				remain=r;
				ans=tmp;
			}
			else if(r==remain&&tmp<ans)
			{
				ans=tmp;
			}
		}
		printf("%d %I64d\n",N-remain,ans);
	}
	return 0;
}


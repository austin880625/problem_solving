#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#define MAXN 100005
#define INF 2147483646
using namespace std;

struct inter
{
	int l,r,id;
	inter(){l=r=id=-1;}
	inter(int _l,int _r,int _id){l=_l,r=_r,id=_id;}
	bool operator <(const inter &r)const{
		return l<r.l;
	}
};

int N,L,R;
int A[MAXN],C[MAXN];
int B[MAXN];
map<int,inter> S;

int main()
{
	while(scanf("%d%d%d",&N,&L,&R)==3)
	{
		for(int i=0;i<N;i++)scanf("%d",A+i);
		for(int i=0;i<N;i++)scanf("%d",C+i),S[C[i]]=inter(L-A[i],R-A[i],i);
		int nowL=-INF;
		int found=1;
		for(map<int,inter>::iterator it=S.begin();it!=S.end();it++)
		{
			nowL=max(nowL,it->second.l);
			if(nowL>it->second.r){found=-1;break;}
			B[it->second.id]=nowL++;
		}
		if(found==-1)
		{
			printf("-1");
		}
		else
		{
			for(int i=0;i<N;i++)
			{
				if(i)printf(" ");
				printf("%d",B[i]+A[i]);
			}
		}

		puts("");
	}
	return 0;
}

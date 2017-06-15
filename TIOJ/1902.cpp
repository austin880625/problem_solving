#include <stdio.h>
#include <iostream>
#include <algorithm>
#define MAXN 15005
using namespace std;

struct query
{
	int l,r,id;
	bool operator <(const query &x)const
	{
		if(r<x.r)return true;
		if(r>x.r)return false;
		return l>x.l;
	}
}qry[MAXN];
int N,Q;
int A[MAXN];
int ans[MAXN];
int maxxor_from[MAXN];

int main()
{
	scanf("%d%d",&N,&Q);
	for(int i=0;i<N;i++)scanf("%d",A+i),maxxor_from[i]=0;
	for(int i=0;i<Q;i++)
	{
		ans[i]=0;
		scanf("%d%d",&qry[i].l,&qry[i].r);
		qry[i].id=i;
		qry[i].l--,qry[i].r--;
	}
	sort(qry,qry+Q);
	int t=0;
	for(int r=0;r<N;r++)
	{
		int tmp1=0,tmp2=0;
		for(int l=r;l>=0;l--)
		{
			tmp1^=A[l];
			maxxor_from[l]=max(maxxor_from[l],tmp1);
			tmp2=max(tmp2,maxxor_from[l]);
			while(qry[t].l==l&&r==qry[t].r)ans[qry[t++].id]=tmp2;
		}
	}
	for(int i=0;i<Q;i++)printf("%d\n",ans[i]);
}
/*
5 4
1 5 4 3 2
1 5
1 3
3 5
2 3
*/

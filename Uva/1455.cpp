#include <stdio.h>
#include <iostream>
#define MAXN 100005
#define MAXY 1000005
using namespace std;

int N,M;
int Y[MAXN];
char c[25];
int BIT[2][MAXY];
int dj[MAXN];
int sz[MAXN];
int l[MAXN],r[MAXN];

int find(int x){return x==dj[x] ? x : dj[x]=find(dj[x]);}
int query(int t,int x)
{
	x++;
	int res=0;
	while(x)
	{
		res+=BIT[t][x];
		x-=(x&(-x));
	}
	return res;
}
void add(int t,int p,int v)
{
	p++;
	while(p<MAXY)
	{
		BIT[t][p]+=v;
		p+=(p&(-p));
	}
}
void merge(int a,int b)
{
	int u=find(a),v=find(b);
	int L=min(l[u],l[v]),R=max(r[u],r[v]);
	if(u==v)return ;
	//cout<<l[u]<<" "<<r[u]<<" "<<l[v]<<" "<<r[v]<<" "<<sz[u]<<" "<<sz[v]<<endl;
	add(0,l[u],-1);
	add(0,r[u],1);
	add(0,l[v],-1);
	add(0,r[v],1);
	add(1,l[u],-sz[u]);
	add(1,r[u],sz[u]);
	add(1,l[v],-sz[v]);
	add(1,r[v],sz[v]);

	dj[u]=v;
	sz[v]=sz[u]=sz[u]+sz[v];
	l[v]=l[u]=L,r[v]=r[u]=R;
	//cout<<sz[v]<<endl;
	add(0,L,1);
	add(0,R,-1);
	add(1,L,sz[v]);
	add(1,R,-sz[v]);
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		for(int i=0,x;i<N;i++)
		{
			dj[i]=i;
			scanf("%d%d",&x,Y+i);
			l[i]=r[i]=Y[i];
			sz[i]=1;
		}
		for(int i=0;i<MAXY;i++)BIT[0][i]=BIT[1][i]=0;
		scanf("%d",&M);
		for(int i=0;i<M;i++)
		{
			scanf("%s",c);
			int a,b;
			if(c[0]=='r')
			{
				scanf("%d%d",&a,&b);
				merge(a,b);
				//for(int i=0;i<20;i++)printf("%d ",query(0,i));puts("");
				//for(int i=0;i<20;i++)printf("%d ",query(1,i));puts("");
			}
			else
			{
				double y;
				scanf("%lf",&y);
				printf("%d %d\n",query(0,(int)y),query(1,(int)y));
			}
		}
	}
	return 0;
}

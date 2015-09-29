#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

#define MAX_N 10005

struct ant
{
	int pos;char dir;int id,t;
};

int turn[MAX_N];
ant start[MAX_N];
ant finalants[MAX_N];
int order[MAX_N];

int cmp(ant a,ant b)
{
	return a.pos<b.pos;
}

int main()
{
	int N,kase=0;
	scanf("%d",&N);
	while(kase++<N)
	{
		int L,T,n;
		scanf("%d %d %d",&L,&T,&n);
		int pos,i,d;char dir;
		for(i=0;i<n;i++)
		{
			turn[i]=0;
			scanf("%d %c",&pos,&dir);
			if(dir=='R')
				d=1;
			else
				d=-1;
			start[i]=(ant){pos,dir,i,0};
			finalants[i]=(ant){pos+d*T,dir,0,0};
		}
		sort(start,start+n,cmp);
		for(int i=0;i<n;i++)order[start[i].id]=i;
		//sort(turn,turn+n,cmp2);
		sort(finalants,finalants+n,cmp);
		for(i=0;i<n;i++)
		{
			if(finalants[i].pos==finalants[i+1].pos)finalants[i].t=finalants[i+1].t=1;
		}
		
		printf("Case #%d:\n",kase);
		for(i=0;i<n;i++)
		{
			//cout<<endl<<turn[i]<<endl;
			int a=order[i];
			if(finalants[a].pos>L||finalants[a].pos<0)printf("Fell off\n");
			else
			{
				printf("%d ",finalants[a].pos);
				if(finalants[a].t)printf("Turning\n");
				else printf("%c\n",finalants[a].dir);
			}
		}
		printf("\n");
	}
	return 0;
}


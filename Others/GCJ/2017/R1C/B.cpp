#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>

using namespace std;

int day[1441];
int Ac,Aj;
priority_queue<int> Q1,Q2;

int check(int i)
{
	int l=i,r=i;
	while(day[l]==0)l=(l+1440-1)%1440;
	while(day[r]==0)r=(r+1)%1440;
	if(day[l]!=day[r])return 0;
	if(r>l)return day[l]*(r-l-1);
	else return i>l ? day[l]*(r+1440-l-1) : 0;
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int kase=1;kase<=T;kase++)
	{
		while(!Q1.empty())Q1.pop();
		while(!Q2.empty())Q2.pop();
		scanf("%d%d",&Ac,&Aj);
		for(int i=0;i<=1440;i++)day[i]=0;
		int s,t;
		int Tc=0,Tj=0;
		for(int i=0;i<Ac;i++)
		{
			scanf("%d%d",&s,&t);
			Tc+=t-s;
			for(int j=s;j<t;j++)day[j]=1;
		}
		for(int i=0;i<Aj;i++)
		{
			scanf("%d%d",&s,&t);
			Tj+=t-s;
			for(int j=s;j<t;j++)day[j]=-1;
		}
		//cout<<Tc<<" "<<Tj<<endl;
		int ans=0,x=-1;
		for(int t=0,now=day[0];t<=1440+x;t++)
		{
			if(now==0)now=day[t%1440];
			else if(x==-1)x=t;
			if(now!=0&&now+day[t%1440]==0)ans++,now=day[t%1440];
		}
		//if(Ac!=0&&Aj!=0)ans++;
		//cout<<ans<<endl;
		for(int i=0;i<1440;i++)
		{
			if(day[i]==0)
			{
				int len=check(i);
				if(len==0){while(day[i]==0)i++;continue;}
				if(len>0)Tc+=len,Q1.push(len),i=i+len;
				else Tj-=len,Q2.push(-len),i=i-len;

			}
		}
		//cout<<Tc<<" "<<Tj<<endl;
		while(Tc>720&&!Q1.empty())
		{
			int t=Q1.top();
			Tc-=t;ans+=2;
			Q1.pop();
		}
		while(Tj>720&&!Q2.empty())
		{
			int t=Q2.top();
			Tj-=t;ans+=2;
			Q2.pop();
		}
		printf("Case #%d: %d\n",kase,ans);

	}
	return 0;
}

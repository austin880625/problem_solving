#include<iostream>
#include<vector>

using namespace std;

const int MAX_N=50;
const int MAX_T=250;
const int inf=20000000;
int n,t;
int M1,M2;
int ans;
int times[MAX_N+25];
int hastraint[MAX_T][MAX_N];
int hastrainb[MAX_T][MAX_N];
int DP[MAX_T][MAX_N];
int d[MAX_N];
int e[MAX_N];

void printdp()
{
	for(int i=0;i<t;i++)
	{
		for(int j=1;j<=n;j++)
			cout<<DP[i][j]<<"\t";
		cout<<endl;
	}
	cout<<endl;
}

int main()
{
	int k=0;
	while(cin>>n)
	{
		if(!n)break;
		//if(k)cout<<endl;
		cin>>t;
		for(int i=0;i<=t;i++)
		{
			for(int j=0;j<=n;j++)
				hastraint[i][j]=hastrainb[i][j]=0;
		}

		for(int i=1;i<n;i++)cin>>times[i];
		cin>>M1;
		for(int i=0;i<M1;i++)
		{
			cin>>d[i];
			int dur=0;
			for(int j=1;j<n;j++)
			{
				if(d[i]+dur<=t)hastraint[d[i]+dur][j]=1;
				dur+=times[j];
			}
		}
		cin>>M2;
		for(int i=0;i<M2;i++)
		{
			cin>>e[i];
			int dur=0;
			for(int j=n;j>=1;j--)
			{
				if(e[i]+dur<=t)hastrainb[e[i]+dur][j]=1;
				if(j>1)dur+=times[j-1];
			}
		}
		for(int i=t;i>=0;i--)
			for(int j=0;j<=n;j++)
				DP[i][j]=inf;
		DP[t][n]=0;
		
		for(int i=t-1;i>=0;i--)
		{
			for(int j=1;j<=n;j++)
			{
				DP[i][j]=DP[i+1][j]+1;
				if(j<n&&hastraint[i][j]&&i+times[j]<=t)
					DP[i][j]=min(DP[i][j],DP[i+times[j]][j+1]);
				if(j>1&&hastrainb[i][j]&&i+times[j-1]<=t)
					DP[i][j]=min(DP[i][j],DP[i+times[j-1]][j-1]);
				//printdp();
			}
		}
		cout<<"Case Number "<<++k<<": ";
		if(DP[0][1]>=inf)cout<<"impossible"<<endl;
		else cout<<DP[0][1]<<endl;
	}
	return 0;
}


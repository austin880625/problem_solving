#include<iostream>

using namespace std;

const int MAX_N=10000;

int A[MAX_N];
int C[MAX_N];

int n;

int lowbit(int x)
{
	return x&(-x);
}

int sum(int x)
{
	int res=0;
	while(x>=1)
	{
		res+=C[x];
		x-=lowbit(x);
	}
	return res;
}

void add(int i,int d)
{
	while(i<=n)
	{
		C[i]+=d;
		i+=lowbit(i);
	}
}

void query(int l,int r)
{
	cout<<sum(r)-sum(l-1)<<endl;;
}

int main()
{
	int c;
	while(cin>>n)
	{
		if(n==-1)break;
		int x;
		for(int i=0;i<n;i++)C[i]=0;
		for(int i=1;i<=n;i++){cin>>x;A[i]=x;add(i,x);}
		int t,num;
		while(cin>>c)
		{
			if(c==-1)break;
			cin>>t>>num;
			if(c==0)add(t,num);
			if(c==1)query(t,num);
		}
	}
	return 0;
}

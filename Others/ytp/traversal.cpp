
#include<iostream>
#include<stdio.h>
#define MAXN 505
#define INF 2147483647
using namespace std;
int w[MAXN][MAXN],N,ans;
int Lx[MAXN],Ly[MAXN];
int Left[MAXN];
bool S[MAXN],T[MAXN];   //it's only a tag!

bool match(int i)
{
    S[i]=true;
    for(int j=1;j<=N;j++)
    {
        if(Lx[i]+Ly[j]==w[i][j]&&!T[j])
        {
            T[j]=true;
            if(!Left[j]||match(Left[j]))
            {
                Left[j]=i;
                return true;
            }
        }
    }
    return false;   //marked S[i],T[j] will be in the hungarian tree,so we can use update()
}
void update()
{
    int a=INF;
    for(int i=1;i<=N;i++)if(S[i])
        for(int j=1;j<=N;j++)if(!T[j])
        {
            a=min(a,Lx[i]+Ly[j]-w[i][j]);
        }
    for(int i=1;i<=N;i++)
    {
        if(S[i])Lx[i]+=a;
        if(T[i])Ly[i]-=a;
    }
}
void KM()
{
    for(int i=1;i<=N;i++)
    {
        Left[i]=Lx[i]=Ly[i]=0;
        for(int j=1;j<=N;j++)
            Lx[i]=max(Lx[i],w[i][j]);
    }
    for(int i=1;i<=N;i++)
    {
        while(1)
        {
        	//cout<<i<<endl;
            for(int j=1;j<=N;j++){S[j]=T[j]=false;}
            if(match(i))break;
            else update();  //there will be a new edge between S and T'
            //cout<<"done"<<endl;
        }
    }
}

int main()
{
	while(scanf("%d",&N)==1)
	{
		ans=0;
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=N;j++)scanf("%d",&w[i][j]);
		}
		//cout<<"YEE"<<endl;
		KM();
		//cout<<"YEE"<<endl;
		for(int i=1;i<=N;i++)ans+=Lx[i]+Ly[i];
		printf("%d\n",ans);
	}
    return 0;
}

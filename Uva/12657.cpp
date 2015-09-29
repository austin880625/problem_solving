#include<iostream>
#include<string>
#include<math.h>
using namespace std;

long long int n,m;
int L[100005];
int R[100005];

void link(int Left,int Right)
{
	L[Right]=Left;
	R[Left]=Right;
}

void exec(int com,int X,int Y)
{
    if(com==3&&R[Y]==X)swap(X,Y);
	int LX=L[X],RX=R[X],LY=L[Y],RY=R[Y];
	if(com==1&&LY!=X)
	{
		link(LX,RX);
		link(LY,X);
		link(X,Y);
	}
	else if(com==2&&R[Y]!=X)
	{
		link(LX,RX);
		link(Y,X);
		link(X,RY);
	}
	else if(com==3)
	{
        if(R[X] == Y) {
            link(LX, Y);
            link(Y, X);
            link(X, RY);
        } else {
            link(X, RY);
            link(LY, X);
            link(Y, RX);
            link(LX, Y);
        }
	}
}

int main()
{
	int T=0;
	while(cin>>n>>m)
	{
		for(int i=0;i<=n;i++){R[i]=i+1;L[i]=i-1;}
		R[n]=0;L[0]=0;
		int com,A,B,inv=0;
		for(int i=0;i<m;i++)
		{
			cin>>com;
			if(com!=4)
			{
				cin>>A>>B;
				if(inv&&(com==1||com==2))exec(3-com,A,B);
				else exec(com,A,B);
			}
			else
			{
				inv=!inv;
			}
			/*int beg=0;
			for(int i=0;i<n;i++)
			{
				beg=R[beg];
				cout<<beg<<" ";
			}
			cout<<endl;*/
		}
		long long int beg=0,sum=0;
		for(int i=0;i<n;i++)
		{
			beg=R[beg];
			if(i%2==0)
			{
				sum+=beg;
			}
		}
	cout<<"Case "<<++T<<": "<<(n%2==1 ? sum : (inv ? (n*(n+1)/2)-sum : sum))<<endl;
	}
    return 0;
}

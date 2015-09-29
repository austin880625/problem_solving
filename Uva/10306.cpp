#include<iostream>
#include<math.h>

using namespace std;

int board[305][305];
int dx[45];
int dy[45];
const int INF=20000000;

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int ans=INF,m,S;
		cin>>m>>S;
		for(int i=0;i<m;i++)
		{
			cin>>dx[i]>>dy[i];
		}
		for(int i=0;i<=S;i++)
		{
			for(int j=0;j<=S;j++)
				board[i][j]=INF;
		}
		board[0][0]=0;
		for(int i=0;i<=S;i++)
		{
			for(int j=0;j<=S;j++)
			{
				for(int k=0;k<m;k++)
				{
					if(i-dx[k]>=0&&j-dy[k]>=0)board[i][j]=min(board[i][j],board[i-dx[k]][j-dy[k]]+1);
					if(sqrt(i*i+j*j)==S)ans=min(ans,board[i][j]);
				}
			}
		}
		if(ans<INF)cout<<ans;
		else cout<<"not possible";
		cout<<endl;
	}
}

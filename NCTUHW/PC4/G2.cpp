#include<stdio.h>
#include<iostream>

using namespace std;

#define maxn 205
#define ll long long int

const int inf=2147483647;

int two[maxn], five[maxn];
int dp[2][maxn][5200];
int possible[2][maxn][5200];
ll a[maxn];

int main(){
    int n,K;
    scanf("%d%d", &n,&K);
    for(int i=1; i<=n; i++){
        scanf("%lld", a+i);
        while(a[i]%2==0)a[i]/=2,two[i]++;
        while(a[i]%5==0)a[i]/=5,five[i]++;
    }
    dp[0][0][0]=0;
	possible[0][0][0] = 1;
    for(int i=1; i<=n; i++){
        for(int j=0; j<5200; j++)dp[i&1][0][j]=dp[i&1][i+1][j]=0;
	possible[i&1][0][0]=1;
        for(int j=1; j<=i; j++){
            for(int k=0; k<5200; k++){
                dp[i&1][j][k]=dp[1-i&1][j][k];
		possible[i&1][j][k] = possible[1-i&1][j][k];
		if(possible[1-i&1][j-1][k-five[i]])possible[i&1][j][k]=1;
                if(k>=five[i]&&possible[1-i&1][j-1][k-five[i]]){
                    dp[i&1][j][k] = max(dp[i&1][j][k], dp[1-i&1][j-1][k-five[i]]+two[i]);
                }
//		if(k<=3)cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<endl;
            }
        }
    }
    int ans=0;
    for(int i=0;i<5200;i++){if(possible[n%2][K][i])ans=max(ans,min(i,dp[n%2][K][i]));}
    printf("%d\n", ans);
}

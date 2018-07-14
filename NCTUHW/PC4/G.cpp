#include<stdio.h>
#include<iostream>

using namespace std;

#define maxn 205
#define ll long long int

const int inf=2147483647;

int two[maxn], five[maxn];
int dp[2][maxn][5200];
int possible[maxn][5200];
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
    possible[0][0]=1;
    for(int i=1; i<=n; i++){
        for(int k=0; k<=i+1; k++)for(int j=0; j<5200; j++)dp[i%2][k][j]=0;
        for(int j=1; j<=i; j++){
            for(int k=5199; k>=0; k--){
                dp[i%2][j][k]=dp[1-i%2][j][k];
		possible[i][k]=possible[i-1][k];
                if(k>=five[i]&&possible[i-1][k-five[i]]){
			possible[i][k]=1;
                    dp[i%2][j][k] = max(dp[i%2][j][k], dp[1-i%2][j-1][k-five[i]]+two[i]);
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<5200;i++){
	    //if(i<10)cout<<i<<" "<<dp[n%2][K][i]<<endl;
	    if(possible[n][i])ans=max(ans,min(i,dp[n%2][K][i]));
    }
    printf("%d\n", ans);
}

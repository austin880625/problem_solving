#include <stdio.h>
#include <iostream>

using namespace std;

int vis[20];
int p[20];
char s[200];
int ans;

void dfs(int i){
	if(i==10){
		int pos=0;
		for(int j=0; s[j]; j++){
			if(p[s[j]-'0'] == pos)pos++;
		}
		if(pos==10)ans++;
		return ;
	}
	for(int j=0;j<10;j++){
		if(vis[j])continue;
		vis[j]=1;
		p[i]=j;
		dfs(i+1);
		vis[j]=0;
	}
}

int main()
{
	scanf("%s", s);
	ans=0;
	dfs(0);
	printf("%d\n",ans);
	return 0;
}

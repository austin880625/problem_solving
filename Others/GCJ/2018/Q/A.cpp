#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <iostream>

using namespace std;

typedef long long int ll;
ll dam[50];
vector<int> cpos;

int main()
{
	int T,D;
	char *s = (char*)malloc(50*sizeof(char));
	scanf("%d", &T);
	for(int kase = 1; kase <=T; kase++){
		cpos.clear();
		scanf("%d %s", &D, s);
		int len = strlen(s);
		ll t = 1, d=0, cs=0;
		for(int i=0; i<len; i++){
			if(s[i] == 'C'){t<<=1; dam[i]=0; cpos.push_back(i);}
			else if(s[i] == 'S'){dam[i]=t;d+=t;cs++;}
		}
		printf("Case #%d: ", kase);
		if(cs > D){ puts("IMPOSSIBLE"); continue; }
		else if(d <= D){ puts("0"); continue; }
		int ans = 0;
		cpos.push_back(len);
		for(int i=cpos.size()-2; i>=0; i--){
			while(d > D && cpos[i] < cpos[i+1]-1){
				ans++;
				dam[cpos[i]] = dam[cpos[i]+1]/2;
				d -= dam[cpos[i]+1]/2;
				dam[cpos[i]+1] = 0;
				cpos[i]++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

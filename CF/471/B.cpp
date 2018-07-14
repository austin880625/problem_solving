#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

char s[100005];
int cnt[27];

int main()
{
	scanf("%s", s);
	int len = strlen(s);
	for(int i=0; i<27; i++)cnt[i]=0;
	int ntype=0;
	for(int i=0; i<len; i++)
	{
		if(cnt[s[i]-'a'] == 0)ntype++;
		cnt[s[i]-'a']++;
	}
	if(ntype > 4 || ntype == 1){
		puts("No");
	}
	else if(ntype == 4){
		puts("Yes");
	}
	else if(ntype == 3){
		if(len >= ntype+1)puts("Yes");
		else puts("No");
	}
	else{
		int c = 0;
		for(int i=0; i<26; i++){
			if(cnt[i]>1)c++;
		}
		if(c >= 2) puts("Yes");
		else puts("No");
	}
	return 0;
}

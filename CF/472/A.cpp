#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int n;
char s[1000];

int main()
{
	scanf("%d", &n);
	scanf("%s", s);
	int len = strlen(s);
	int ans=(s[0] == '?' || s[len-1] == '?');
	for(int i=1; i<len-1; i++){
		if(s[i-1] == s[i] && s[i] != '?'){ans=0; break;}
		if(s[i+1] == s[i] && s[i] != '?'){ans=0; break;}
		if(s[i-1] == '?' && s[i] == '?'){ans|=1;}
		if(s[i] == '?' && s[i-1] == s[i+1]){ans|=1;}
	}
	if(ans)puts("Yes");
	else puts("No");
	return 0;
}

#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

char s[100005];

int main()
{
	scanf("%s", s);
	int len = strlen(s);
	char cur = 'a';
	int m=0;
	for(int i=0; i<len; i++){
		if(cur == 'z'&&m==25){s[i] = 'z';m++;break;}
		if(s[i]<=cur)s[i] = cur, cur++, m++;
	}
	if(cur == 'z' && m ==26)printf("%s\n", s);
	else puts("-1");
	return 0;
}

#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int n;
char s[10000];

int main()
{
	scanf("%d", &n);
	int c=0;
	for(int i=0; i<1000; i++){
		sprintf(s+c, "%d", i);
		int l = strlen(s+c);
		c+=l;
	}
	printf("%c\n", s[n]);
	return 0;
}

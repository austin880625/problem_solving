#include <stdio.h>
#include <iostream>

using namespace std;

char s[1000005];

int main()
{
	int n;
	scanf("%d", &n);
	scanf("%s", s);
	int lastx=0, lasty=0, x=0, y=0,ans=0;
	for(int i=0;i<n;i++){
		if(s[i]=='U'){
			if((lastx-lasty)*(x-y-1)<0)ans++;
			lastx=x;lasty=y;
			y++;
		}
		else {
			if((lastx-lasty)*(x+1-y)<0)ans++;
			lastx=x;lasty=y;
			x++;
		}
	}
	printf("%d\n",ans);
	return 0;
}

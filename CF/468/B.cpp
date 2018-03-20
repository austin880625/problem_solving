#include <stdio.h>
#include <iostream>

using namespace std;

int N,A,B,log;

int main()
{
	scanf("%d%d%d",&N,&A,&B);
	for(log=0; (1<<log) < N; log++);
	A--, B--;
	int x=A^B;
	int ans=0;
	while(x)ans++, x>>=1;
	if(ans==log)printf("Final!\n");
	else printf("%d\n", ans);
	return 0;
}

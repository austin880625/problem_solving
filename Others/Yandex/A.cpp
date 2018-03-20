#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int q=n/(k+1), r=n%(k+1);
	if(r==1)printf("%d\n", q*2+1);
	else if(r>1) printf("%d\n", q*2+2);
	else printf("%d\n", q*2);
	
	return 0;
}

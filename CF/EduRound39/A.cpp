#include <stdio.h>
#include <iostream>

using namespace std;

int n;
int a[1000];

int main()
{
	scanf("%d",&n);
	for(int i=0; i<n; i++)scanf("%d",a+i);
	int B=0, C=0;
	for(int i=0; i<n; i++){
		if(a[i]<0)C+=a[i];
		else B+=a[i];
	}
	printf("%d\n", B-C);
	return 0;
}

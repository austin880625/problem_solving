#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int a,b;

int main()
{
	scanf("%d%d",&a,&b);
	if(a>b)swap(a,b);
	int d=b-a;
	if(d%2==0){
		int n=d/2;
		printf("%d\n", n*(n+1));
	}
	else{
		int n=(d+1)/2;
		printf("%d\n", n*n);
	}
	return 0;
}

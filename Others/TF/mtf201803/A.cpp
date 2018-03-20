#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	int T,p,q;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&p,&q);
		if(q<0){q=-q;p=-p;}
		int l=-1000, r=1000;
		while(l<r){
			int mid = (l+r)>>1;
			if(mid*q<p)l=mid+1;
			else r=mid;
		}
		printf("%d\n",l-1);
	}
	return 0;
}

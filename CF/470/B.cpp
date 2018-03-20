#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int x2;

int main()
{
	cin>>x2;
	int n=x2;
	int mp=1;
	for(int i=2; i*i<=n; i++){
		if(n%i==0&&i*2<=x2)mp=max(mp, i);
		while(n%i==0)n/=i;
	}
	if(n*2<=x2)mp = max(mp, n);
	int x0=x2;
	for(int x1 = x2-mp+1; x1<=x2; x1++){
		n=x1;
		int mp2=1;
		for(int i=2; i*i<=n; i++){
			if(n%i==0&&i*2<=x1)mp2 = max(mp2, i);
			while(n%i==0)n/=i;
		}
		if(n*2<=x1)mp2 = max(mp2, n);
		x0 = min(x0, x1-mp2+1);
	}
	cout<<x0<<endl;

	return 0;
}

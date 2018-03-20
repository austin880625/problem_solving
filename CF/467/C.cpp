#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
typedef long long int ll;
ll k,d,t;

int main()
{
	cin>>k>>d>>t;
	ll r=k%d;
	ll x=k,y=(d-r)%d;
	ll ans = ((x+y)*((2*t)/(2*x+y)));
	ll res = 2*t-((2*x+y)*((2*t)/(2*x+y)));
	double ansd;
	if(res<=2*x){
		ansd = (double)ans + (double)res/2.0;
	}
	else{
		ansd = (double)(ans - x + res);
	}
	printf("%.10f\n", ansd);
	return 0;
}

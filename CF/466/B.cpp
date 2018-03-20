#include <stdio.h>
#include <iostream>

using namespace std;

typedef long long ll;
ll n,k,a,b;
ll r[100];
ll f(ll n)
{
	if(n<k)return (n-1)*a;
	if(k==1)return (n-1)*a;
	ll q=n/k;
	ll r=n%k;
	if((k-1)*q*a<b)return r*a+(k-1)*q*a+f(q);
	else return r*a+b+f(q);

}

int main()
{
	cin>>n>>k>>a>>b;
	cout<<f(n)<<endl;
	return 0;
}

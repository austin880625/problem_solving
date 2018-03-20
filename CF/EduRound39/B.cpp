#include <stdio.h>
#include <iostream>

using namespace std;

typedef long long int ll;
ll N,M;

int main()
{
	cin>>N>>M;
	while(!((N==0||M==0) || (N<2*M && M<2*N))){
		if(N>=2*M){if(M==0)continue; N = N%(2*M);}
		else if(M>=2*N){if(N==0)continue; M = M%(2*N);}
	}
	cout << N <<" "<< M << endl;
	return 0;
}

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string.h>

#define MAXN 5005
#define INF 2147483647
#define LL long long int

using namespace std;

int N;
vector<int> prime;
vector<int> nonprime;
int isprime[MAXN];

int main()
{
	isprime[1]=0,isprime[2]=isprime[3]=1;
	nonprime.push_back(1);
	for(int i=4;i<=5000;i++)isprime[i]=1;
	for(int i=2;i<=5000;i++){
		if(isprime[i]){
			prime.push_back(i);
			for(int j=2*i;j<=MAXN;j+=i)isprime[j]=0;
		}
		else{
			nonprime.push_back(i);
		}
	}
	vector<int> ans;
	while(scanf("%d",&N)==1){
			ans.clear();
		if(isprime[N]){
			for(int i=0;i<prime.size()&&prime[i]<=N;i++)ans.push_back(prime[i]);
		}
		else{
			for(int i=0;i<nonprime.size()&&nonprime[i]<=N;i++)ans.push_back(nonprime[i]);
		}
		for(int i=ans.size()-1;i>=0;i--){
			printf("%d",ans[i]);
			if(i)printf(" ");
		}
		puts("");
	}

	return 0;
}

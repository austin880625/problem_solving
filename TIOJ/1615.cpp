#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#define LL long long int

using namespace std;

vector<LL> primes;

void gen_prime()
{
	primes.push_back(2LL),primes.push_back(3LL);
	for(LL i=5LL;i*i<=1000000000000LL;i+=2LL)
	{
		bool isprime=true;
		for(int j=0;primes[j]*primes[j]<=i&&j<primes.size();j++)
		{
			if(i%primes[j]==0){isprime=false;break;}
		}
		if(isprime)primes.push_back(i);
	}
}

LL A,B;

int main()
{
	gen_prime();
	set<LL> ans;
	while(scanf("%lld%lld",&A,&B)==2)
	{
		if(A>B)swap(A,B);
        LL tmp=1;
        for(LL i=A+1;i<=B;i++)tmp*=i;tmp++;
        ans.clear();
        bool f1=true;
        for(int i=0;i<primes.size()&&primes[i]*primes[i]<=tmp;i++)
		{
			while(tmp%primes[i]==0)
			{
				f1=false;
				ans.insert(primes[i]);
				tmp/=primes[i];
				/*LL d=tmp/primes[i];
				bool f=true;
				for(int j=0;primes[j]*primes[j]<=d;j++)
				{
					if(d%primes[j]==0){f=false;break;}
				}
				if(f)ans.insert(d);
				*/
			}
		}
		if(tmp!=1)ans.insert(tmp);
		for(int i=0;i<primes.size()&&primes[i]<=A;ans.insert(primes[i]),i++);
		printf("%d\n",ans.size());
	}
	return 0;
}

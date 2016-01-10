#include <stdio.h>
#include<iostream>
#include<queue>
#include<vector>
#include<fstream>
#include<string>
#include<map>
#define MAX_B 1000
typedef long long int LL;
using namespace std;

LL GCD(LL a, LL b){
 if(a%b){
  return GCD(b, a%b);
 }
 else{
  return (b);
 }
}
long long int LCM(long long int a,long long int b)
{
	return a*b/GCD(a,b);
}
int main()
{
    freopen("B.in","r",stdin);
    freopen("p2.out","w",stdout);
    int T;
    LL B,N,G,S;
    cin>>T;
    for(int kase=1;kase<=T;kase++)
    {
        cin>>B>>N;
        G=1;S=0;
        LL M[MAX_B];
        LL ans=0;
        for(int i=0;i<B;i++)
		{
			cin>>M[i];
			if(i==0)G=M[i];
			else G=LCM(G,M[i]);
		}
		for(int i=0;i<B;i++)
		{
			S+=G/M[i];
		}
		//cout<<S<<endl;
		//ans+=(N/S)*G;
		N%=S;
		N--;
		if(N<0)N=S-1;
		LL t=0,o=0,f=0;
		while(1)
		{
			for(int i=0;i<B;i++)
			{
				if(t%M[i]==0)
				{
					if(o==N){ans=i+1;f=1;break;}
					o++;
				}

			}
			//cout<<o<<endl;
			t++;
			//cout<<t<<endl;
			if(f)break;
		}
		cout<<"Case #"<<kase<<": "<<ans<<endl;
    }
}

#include <stdio.h>
#include <iostream>
#define MOD 4294967296LL
#define LL long long int

using namespace std;

struct mat{
	LL m[2][2];
	mat(){m[0][0]=m[0][1]=m[1][0]=m[1][1]=0;}
	mat operator *(const mat &r)const{
		mat res;
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<2;j++)
			{
				for(int k=0;k<2;k++)
				{
					res.m[i][j]+=(m[i][k]*r.m[k][j])%MOD;
					res.m[i][j]%=MOD;
				}
			}
		}
		return res;
	}
	void operator =(mat r){
		for(int i=0;i<2;i++)for(int j=0;j<2;j++)m[i][j]=r.m[i][j];
	}
};

mat pow;
mat ans;
 LL n;
unsigned LL a,b,x,y;

int main()
{
	while(scanf("%llu",&n)==1&&n>=0)
	{
		scanf("%llu%llu%llu%llu",&a,&b,&x,&y);
		if(n==0){printf("%llu\n",(LL)a);continue;}
		else if(n==1){printf("%llu\n",(LL)b);continue;}
		n-=2;
		pow.m[0][0]=0,pow.m[0][1]=1;
		pow.m[1][0]=x,pow.m[1][1]=y;
		ans=pow;
		while(n)
		{
			if(n&1LL)ans=ans*pow;
			n>>=1;
			pow=pow*pow;
		}
		printf("%llu\n",((ans.m[1][0]*a)%MOD+(ans.m[1][1]*b)%MOD)%MOD);
	}
	return 0;
}

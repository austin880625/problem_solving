#include<iostream>
#include<stdio.h>
#include<math.h>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
int x[1000000];
int y[1000000];


int N;
long long int ans;
int tx,ty;

int get_int ()
{
	int sign=1,num=0;char tc;
	tc=getchar();
	while((tc>'9'||tc<'0')&&tc!='-')tc=getchar();
	if(tc=='-'){tc=getchar();sign=-1;}
	while(tc<='9'&&tc>='0'){ num=num*10+(tc-'0'),tc=getchar();}
	return sign*num;
}
int main()
{
	int T;
	T=get_int();
	printf("%d",T);
	while(T--){
		N=get_int();
		
		for(int i=0;i<N;i++){
			x[i]=get_int();
			y[i]=get_int();
		}
		
		nth_element(x,x+N/2,x+N);
		tx=x[N/2];
		nth_element(y,y+N/2,y+N);
		ty=y[N/2];
		ans=0;
		for(int i=0;i<N;i++){
			ans+=(tx>x[i]?tx-x[i] : x[i]-tx)+(ty>y[i]? ty-y[i] : y[i]-ty);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
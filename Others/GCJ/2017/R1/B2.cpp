#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>
#include <set>
#include <map>

#define MAXN 1005

using namespace std;

int C[6];
int C2[6];
int N;

int all_zero()
{
	for(int i=0;i<6;i++){if(C2[i]<0)return -1; else if(C2[i])return 0;}
	return 1;
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int kase=1;kase<=T;kase++)
	{
		scanf("%d",&N);
		for(int i=0;i<6;i++)scanf("%d",C+i),C2[i]=C[i];
		C2[4]-=C2[1];C2[1]=0;
		C2[0]-=C2[3];C2[3]=0;
		C2[2]-=C2[5];C2[5]=0;
		int ans=all_zero();
		if(ans==-1)printf("Case #%d: IMPOSSIBLE\n",kase);
		printf("Case #%d: ",kase);
		int m=min(C2[0],min(C2[2],C2[4]));
		C2[0]-=m;C2[2]-=m;C2[4]-=m;
		int mm;
		if(C2[0]==0)mm=min(C2[2],C2[4]),C[2]-=mm,C[4]-=mm;
		else if(C2[2]==0)mm=min(C2[0],C2[4]),C[0]-=mm,C[4]-=mm;
		else if(C2[4]==0)mm=min(C2[0],C2[2]),C[2]-=mm,C[0]-=mm;
	}
    return 0;
}

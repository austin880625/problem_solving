#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#define MAXN 1005

using namespace std;

int N,D;
struct horse
{
	int sp,pos;
	bool operator <(const horse &x)const
	{
		return pos < x.pos;
	}
}H[MAXN];

int main()
{
	int T;
	scanf("%d",&T);
	for(int kase=1;kase<=T;kase++)
	{
		scanf("%d",&D);
		scanf("%d",&N);
		for(int i=0;i<N;i++)scanf("%d%d",&H[i].pos,&H[i].sp);
		sort(H,H+N);
		int P=H[0].pos,S=H[0].sp;
		for(int i=1;i<N;i++)
		{
			double t=(double)(D-P)/(double)S;
			double x=(double)(D-H[i].pos)/(double)H[i].sp;
			if(t>x)
			{

			}
		}
	}
    return 0;
}

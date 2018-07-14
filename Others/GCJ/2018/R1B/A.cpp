#include <stdio.h>
#include <iostream>

using namespace std;

#define MAXN 100005
int N,L;
int C[MAXN];
int S;

int main()
{
	int T;
	int upper[5] = {0, 5, 3, 2, 2};
	scanf("%d", &T);
	for(int kase=1; kase <= T; kase++){
		S=0;
		scanf("%d%d", &N, &L);
		for(int i=0; i<L; i++)scanf("%d", C+i), S+=C[i];
		printf("Case #%d: ", kase);
		if(N<=1000){
			int R=N-S;
			int p=(1000/N)%10;
			if(p==0){
				printf("100\n");
			}else if(p<5){
				int ans=0;
				for(int i=0; i<L; i++){
					int c=(C[i]*1000/N)%10, d;
					for(d=0; d<upper[p]; d++)if(c+p*d >= 5 && c+p*d < 10)break;
					if(d!=upper[p] && R>=d && c<5){ans+=(C[i]+1)*100/N + 1;R-=d;}
					else ans+=C[i]*100/N + (c < 5 ? 0 : 1);
				}
				ans+=(R/upper[p])*((upper[p]*100/N)+1);
				if(R%upper[p])ans += (R%upper[p])*100/N;
				printf("%d\n", ans);
			}
			else{
				//cout<<"up"<<endl;
				int ans=0;
				for(int i=0; i<L; i++){
					int c=(C[i]*1000/N)%10;
					ans+=C[i]*100/N + (c < 5 ? 0 : 1);
				}
				ans+=R*((100/N)+1);
				printf("%d\n", ans);
			}
		}
	}
	return 0;
}

#include<cstdio>
int N,A[500000],TAG[499999];
int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	int ans=0;
	for(int i=0,L,R;i+1<N;i++)
	{
		for(R=i;R+1<N&&A[R]!=A[R+1];R++);
		L=i;
		int i1=L+1,i2=R-1;
		int cnt=0;
		while(i1<=i2)
		{
			A[i1++]=A[L],A[i2--]=A[R];
			cnt++;
		}
		if(cnt>ans)ans=cnt;
	}
	printf("%d\n",ans);
	for(int i=0;i<N;i++)
	{
		if(i)printf(" ");
		printf("%d",A[i]);
	}
	puts("");
	return 0;
}

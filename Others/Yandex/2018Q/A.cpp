#include <stdio.h>
#include <iostream>

using namespace std;

int A[35];
int B[35];
int N;
int cnt[35];

int main()
{
	for(int i=0; i<10; i++)scanf("%d",A+i);
	scanf("%d",&N);
	for(int i=0; i<N; i++){
		for(int j=0; j<=32; j++)cnt[j]=0;
		for(int j=0; j<10; j++)cnt[A[j]]++;
		int chk=0;
		for(int j=0; j<6; j++){
			scanf("%d",B+j);
			if(cnt[B[j]]){cnt[B[j]]--;chk++; }
		}
		if(chk>=3)puts("Lucky");
		else puts("Unlucky");
	}
	return 0;
}

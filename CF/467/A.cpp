#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
int n;
int A[500];
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)cin>>A[i];
	sort(A,A+n);
	int i=0;
	while(A[i]==0)i++;
	int cnt=0;
	for(i;i<n;i++)if(A[i]!=A[i-1])cnt++;
	cout<<cnt<<endl;
	return 0;
}

#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;
int T,N;
int A[100000];
int L;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        int ans=0;
        scanf("%d",&N);
        scanf("%d",&L);
        for(int i=0;i<N;i++)scanf("%d",&A[i]);
        sort(A,A+N);
        int l=0,r=N-1;
        while(l<=r)
        {
            ans++;
            if(l==r)break;
            if(A[r]+A[l]<=L)
            {
                //cout<<A[l]<<" "<<A[r]<<endl;
                l++;r--;
            }
            else
            {
                r--;
            }
        }
        printf("%d\n",ans);
        if(T)puts("");
    }
    return 0;
}

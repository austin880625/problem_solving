#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
    long long int A,B,ans1,ans2;
    int N;
    scanf("%d",&N);
    for(int kase=1;kase<=N;kase++){
    scanf("%lld %lld",&A,&B);
        int bit=61,c=1;
        ans1=ans2=0;
        for(;bit>=0;bit--)
        {
            if(((A>>bit)&1LL)!=((B>>bit)&1LL))c=0;
            if(c){ans1|=A&(1LL<<bit);ans2=ans1;}
            else ans2|=(1LL<<bit);
            //if(bit<4)cout<<bit<<" "<<((A>>bit)&1)<<((B>>bit)&1)<<" "<<c<<" "<<ans2<<endl;
        }

        printf("Case %d: %lld %lld\n",kase,ans2,ans1);
    }
    return 0;
}

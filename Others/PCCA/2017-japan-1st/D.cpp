#include <stdio.h>
#include <iostream>
#include <vector>
#include <assert.h>
#define LL long long int

using namespace std;

LL N,I,J;
char ans[70];

int main()
{
    while(scanf("%lld%lld%lld",&N,&I,&J)==3&&N)
    {
        I--;
        LL t=(1LL<<N);int cnt=0;
        LL q=t/2,altJ=J;
        if(I&1)
        {
            if(J<=q)ans[cnt]='R',altJ=q+1-J;
            else ans[cnt]='L',altJ=t+1-J,J-=q;
        }
        else{
            if(J<=q)ans[cnt]='L',altJ=J,J=q+1-J;
            else ans[cnt]='R',altJ=J-q,J=t+1-J;
        }
        I>>=1;t>>=1;cnt++;
        while(cnt<N)
        {
            q=t/2;
            if(I&1)
            {
                LL q=t/2;
                if(J<=q)ans[cnt]='R',altJ=q+1-J;
                else ans[cnt]='L',altJ=t+1-J,J-=q;
            }
            else
            {
                ans[cnt-1]=(ans[cnt-1]=='L' ? 'R' : 'L');
                J=altJ;
                if(J<=q)ans[cnt]='L',altJ=J,J=q+1-J;
                else ans[cnt]='R',altJ=J-q,J=t+1-J;
            }
            //cout<<t<<" "<<J<<endl;
            I>>=1;t>>=1;cnt++;
        }
        //cout<<J<<endl;
        assert(J==1);
        ans[cnt]='\0';
        printf("%s\n",ans);
    }
    return 0;
}

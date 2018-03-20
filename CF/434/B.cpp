#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int N,M;
struct flat
{
    int k,f;
    bool operator <(const flat &x)const{
        return f<x.f;
    }
};
flat F[105];

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    while(cin>>N>>M)
    {
        for(int i=0;i<M;i++)cin>>F[i].k>>F[i].f;
        sort(F,F+M);
        int ans=-1;
        for(int t=1;t<=105;t++)
        {
            int f=1;
            //cout<<t<<": "<<endl;
            for(int i=0;i<M;i++)
            {
                int ff=F[i].k/t+(F[i].k%t==0 ? 0 : 1);
                f=f&&(ff==F[i].f);
                //cout<<F[i].f<<" "<<ff<<endl;
            }
            if(f==1)
            {
                if(ans==-1)ans=N/t+(N%t==0 ? 0 : 1);
                else if(ans!=N/t+(N%t==0 ? 0 : 1)) {ans=-1; break;}
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

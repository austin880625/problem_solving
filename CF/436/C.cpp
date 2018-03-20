#include <stdio.h>
#include <iostream>

using namespace std;

int A,B,F,K;

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    while(cin>>A>>B>>F>>K){
        int ans=0,t=B;
        if(K==1){cout<<(t<F ? -1 : (t<A ? (t<A-F ? -1 : 1) : 0))<<endl;continue;}
        for(int i=0;i<K/2;i++){
            //cout<<t<<endl;
            if(i==0){
            if(t<F){
                ans=-1;break;
            }
            t-=F;
            }
            //cout<<t<<endl;
            if(t>=2*(A-F)){
                t-=(2*(A-F));
            }
            else{
                t=B;ans++;
                if(t<2*(A-F)){ans=-1;break;}
                t-=(2*(A-F));
            }
            //cout<<t<<endl;
            if(i==K/2-1&&K%2==0){
                if(t<F){t=B;ans++;}
                t-=F;
            }
            else{
                if(t<2*F){t=B;ans++;}
                if(t<2*F){ans=-1;break;}
                t-=2*F;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

#include <stdio.h>
#include <iostream>

using namespace std;

int cnt[105];
int N;

int main()
{
    while(cin>>N){
        for(int i=0;i<=100;i++)cnt[i]=0;
        int x=0;
        for(int i=0,t;i<N;i++){
            cin>>t;
            if(cnt[t]==0)x++;
            cnt[t]++;
        }
        if(x>2)cout<<"NO"<<endl;
        else if(x<=1)cout<<"NO"<<endl;
        else {
            x=0;int y=0;
            for(int i=0;i<=100;i++)if(cnt[i]){x=i;break;}
            for(int i=100;i>=0;i--)if(cnt[i]){y=i;break;}
            if(cnt[x]==cnt[y])cout<<"YES"<<endl<<x<<" "<<y<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}

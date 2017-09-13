#include <stdio.h>
#include <iostream>
#define LL long long int
#define MAXN 100005
using namespace std;

int T,N;
LL A[2*MAXN];

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        //cout<<N<<endl;
        for(int i=0;i<N;i++){
            scanf("%lld",A+i);
            A[N+i]=A[i];
        }
        int anss=0,anst=0;
        int s=1;LL x=0;
        for(int i=0;i<2*N;i++){
            //cout<<x<<endl;
            x+=A[i];
            if(x<=0||(i+1)%N==s){
                if(anst-anss<i-s&&){
                    anst=i%N,anss=s;
                }
                s=i+1,x=0;
            }
        }
        printf("%d %d\n",anss+1,anst+1);
        //cout<<"YEE";
    }
    return 0;
}

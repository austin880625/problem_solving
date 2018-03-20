#include <stdio.h>

int N,T;
int fl[205];

int main()
{
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        for(int i=0;i<205;i++)fl[i]=0;
        for(int i=0,f;i<N;i++){scanf("%d",&f);fl[f]++;}
        int ans=0;
        for(int i=202;i>=2;i--){
            if(fl[i]){
                ans++;
                fl[i]=fl[i-1]=0;
            }
        }
        printf("%d\n",ans);
    }
}

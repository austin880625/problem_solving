#include <stdio.h>
#include <iostream>
#include <string.h>
#define MAXN 200005
#define LL long long int
#define INF 0x3f3f3f3f

using namespace std;

int H[MAXN];
LL ST[MAXN][30];
int N;
LL M;
LL ANS;

int main()
{
    memset(ST,INF,sizeof(ST));
    while(scanf("%d%lld",&N,&M)==2)
    {
        LL mmmm=0;
        ANS=0;
        for(int i=0;i<=N;i++)
        {
            for(int j=0;j<30;j++)ST[i][j]=INF;
        }
        for(int i=1;i<=N;i++)
        {
            scanf("%d",H+i),ST[i][0]=H[i],mmmm=max(mmmm,ST[i][0]);
        }

            int l=1;
        while((1<<l)<=N)
        {
            for(int i=1;i<=N;i++)
            {
                ST[i][l]=min(ST[i][l-1],ST[i+(1<<(l-1))][l-1]);
                //if(l==2&&i==2)printf("WAA %d %d\n",ST[i][l-1],ST[i+(1<<(l-1))][l-1]);

        //cout<<"YEE";
            }
            l++;
        }
        /*
        for(int i=0;i<6;i++)
        {
            for(int j=1;j<=N;j++)printf("%d ",ST[j][i]);
            puts("");
        }
        */
        for(LL gap1=1;gap1*gap1<=M;gap1++)
        {
            if(gap1>N)break;
            if(M%gap1)continue;
            LL gap2=M/gap1;
            int pow1=0,pow2=0;
            while((1LL<<pow1)<=gap1)pow1++;pow1--;
            while((1LL<<pow2)<=gap2)pow2++;pow2--;
            for(int i=1;i+gap1-1<=N;i++)
            {
                LL range;
                if(i+gap1-1<=N)
                {
                    range=min(ST[i][pow1],ST[i-(1<<pow1)+gap1][pow1])-gap2;
                    //cout<<gap1<<" "<<range<<" "<<i<<"YEE"<<endl;
                    if(range>=0)ANS+=(range+1);
                }
                if(i+gap2-1<=N&&gap1!=gap2)
                {
                    range=min(ST[i][pow2],ST[i-(1<<pow2)+gap2][pow2])-gap1;
                    //cout<<gap2<<" "<<range<<" "<<i<<"YAA"<<endl;
                    if(range>=0)ANS+=(range+1);
                }
            }
        }
        printf("%lld\n",ANS);
    }
    return 0;
}

/*
5 4
1 3 2 4 1
8 8
3 4 3 3 5 6 3 1
6 2
3 3 0 3 3 3
*/

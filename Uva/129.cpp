#include<iostream>
#include<string>
#include<vector>
#include<math.h>
using namespace std;

int S[100];
int n,L,ord;

int check(int s,int l)
{
    int lh=l/2;
    for(int i=0;i<lh;i++)
    {
        if(S[s+i]!=S[s+i+lh])return 0;
    }
    return 1;
}

int dfs(int cur)
{
    if(ord==n)
    {
        for(int i=0;i<cur;i++)
        {
            cout<<(char)('A'+S[i]);
            if((i+1)%64==0&&i!=cur-1)cout<<endl;
            if(i%4==3&&(i+1)%64&&i!=cur-1)cout<<" ";
        }
        cout<<endl<<cur<<endl;
        return 1;
    }
        for(int i=0;i<L;i++)
        {
            S[cur]=i;
            int chk=1;
            if(cur>0)
            {
            for(int i=2;i<=cur+1;i+=2)
            {
                if(check(cur-i+1,i)){chk=0;break;}
            }
            }
            if(chk)
            {
                ord++;
                if(dfs(cur+1))return 1;
            }
            
        }
    return 0;
}

int main()
{
    while(cin>>n>>L)
    {
        if(n==0&&L==0)break;
        ord=0;
        dfs(0);
    }
    return 0;
}

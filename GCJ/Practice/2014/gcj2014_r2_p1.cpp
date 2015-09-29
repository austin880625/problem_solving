#include <stdio.h>
#include<iostream>
#include<queue>
#include<vector>
#include<fstream>
#include<string>
#include<map>
#define isFile 1
#define loop1(I,A) for(int I=0;I<A;I++)
#define loop2(I,A,B) for(int I=A;I<B;I++)
#define loop3(I,A,B) for(int I=A;I>=B;I--)
#define MAX_N 10000

using namespace std;

int main()
{
    if(isFile)
    {
        freopen("A-large.in","r",stdin);
        freopen("p1.out","w",stdout);
    }
    int T;
    int N,X,s[MAX_N],used[MAX_N],ans;
    cin>>T;
    for(int kase=1;kase<=T;kase++)
    {
        ans=0;
        cin>>N>>X;
        int i=0;
        loop1(i,N)
        {
            cin>>s[i];
            used[i]=0;
        }
        sort(s,s+N);
        int j;
        loop3(i,N-1,0)
        {
            if(!used[i])
            {
                used[i]=1;
                int f=0;
                loop3(j,i-1,0)
                {
                    if(!used[j]&&s[j]+s[i]<=X)
                    {
                        //cout<<j<<endl;
                        ans++;
                        used[j]=1;
                        f=1;
                        break;
                    }
                }
                if(!f)ans++;
                }
        }
        cout<<"Case #"<<kase<<": "<<ans<<endl;
    }
}
#include <stdio.h>
#include<iostream>
#include<fstream>
#include<queue>
#include<stack>
#include<vector>
#include<utility>
#include<string>
#include<map>
#define isFile 1
#define P "A"
#define SL 1
#define filePath "./"
#define lp1(I,A) for(int I=0;I<(A);I++)
#define lp2(I,A,B) for(int I=(A);I<(B);I++)
#define lp3(I,A,B) for(int I=(A);I>=(B);I--)

using namespace std;

int abs(int x){return (x>0 ? x : -x);}

int main()
{
    if(isFile)
    {
        string fileName=P;
        if(SL)fileName+="-large";
        else fileName+="-small";
        freopen((filePath+fileName+".in").c_str(),"r",stdin);
        freopen((filePath+fileName+".out").c_str(),"w",stdout);
    }
    int T,N;
    string s[105];
    int pos[105];
    cin>>T;
    lp2(kase,1,T+1)
    {
        int ans=0,f=1;
        cin>>N;
        lp1(i,N){cin>>s[i];pos[i]=0;}
        while(pos[0]<s[0].length())
        {
            int count[N];
            lp1(i,N)
            {
                char c=s[i][pos[i]];
                if(i!=0&&c!=s[0][pos[0]-1])f=0;
                int sum=0;
                count[i]=0;
                while(c==s[i][pos[i]])
                {
                        sum++;
                        pos[i]++;
                        count[i]++;
                }
            }
            int Min=100000;
            lp1(i,101)
            {
                int tmp=0;
                lp1(j,N)
                {
                    tmp+=abs(i-count[j]);
                }
                Min=min(tmp,Min);
            }
            ans+=Min;
        }
        lp1(i,N)if(pos[i]<s[i].length())f=0;
        if(f)
            cout<<"Case #"<<kase<<": "<<ans<<endl;
        else
            cout<<"Case #"<<kase<<": "<<"Fegla Won"<<endl;
    }
}
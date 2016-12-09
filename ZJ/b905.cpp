#include <stdio.h>
#include <iostream>
#include <string.h>
#define MAXN 3000005

using namespace std;

string T,S;
int f[MAXN];
int sp;
int ttt;

void calc_f()
{
    f[0]=f[1]=0;
    for(int i=1;sp+i<T.length()&&T[sp+i]!='*';i++)
    {
        int j=f[i];
        while(T[sp+j]!=T[sp+i]&&j)j=f[j];
        f[i+1]=T[sp+j]==T[sp+i] ? j+1 : 0;
    }
}

int main()
{
    scanf("%d",&ttt);
    while(ttt--)
    {
        cin>>T>>S;
        int ans=1,now=0;
        sp=0;

        while(sp<T.length())
        {
            while(T[sp]=='*')sp++;
            //cout<<"YAA"<<endl;
            if(sp>=T.length())break;

            calc_f();
            int j=0;
            for(int i=now;i<S.length();i++)
            {
                if(S[i]!=T[sp+j]&&sp==0){ans=0;break;}
                while(S[i]!=T[sp+j]&&j)j=f[j];
                if(S[i]==T[sp+j])j++;
                    //cout<<"YEE"<<endl;
                    //cout<<i<<" "<<j<<endl;
                if(sp+j>=T.length()||T[sp+j]=='*'){now=i;sp=sp+j;break;}
            }
            if(!j){ans=0;break;}
            if(!ans)break;
            if(!(sp>=T.length()||T[sp]=='*')){ans=0;break;}
        }

        cout<<(ans ? "Yes" : "No")<<endl;

    }
    return 0;
}

#include <stdio.h>
#include<iostream>
#include<fstream>
#include<queue>
#include<stack>
#include<vector>
#include<utility>
#include<string>
#include<map>
#include<algorithm>
#include"../Libraries/Vectors.h"
#define isFile 1
#define Problem "B"
#define SL 0
#define filePath "./"
#define lp1(I,A) for(int I=0;I<(A);I++)
#define lp2(I,A,B) for(int I=(A);I<(B);I++)
#define lp3(I,A,B) for(int I=(A);I>=(B);I--)

using namespace std;
typedef long long ll;

string key,tar;
int K,L,S;
int times[1000];

int count(char c)
{
    int res=0;
    lp1(i,key.length())
    {
        if(key[i]==c)res++;
    }
    return res;
}

int main()
{
    if(isFile)
    {
        string fileName=Problem;
        if(SL)fileName+="-large";
        else fileName+="-small";
        freopen((filePath+fileName+".in").c_str(),"r",stdin);
        freopen((filePath+fileName+".out").c_str(),"w",stdout);
    }
    int T;
    cin>>T;
    lp2(kase,1,T+1)
    {
        cin>>K>>L>>S;
        cin>>key>>tar;
        memset(times,0,sizeof(times));
        int t=1;
        double p=1;
        lp1(i,S)
        {
            int c=count(tar[i%tar.length()]);
            
        }
    }
}
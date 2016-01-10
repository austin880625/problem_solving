#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stack>
#define MAXN 100005
using namespace std;
struct DQ
{
    int fr,rr;
    int s[MAXN];
    void clear(){fr=0;rr=-1;}
    int size(){return rr-fr+1;}
    void push(int _v){s[++rr]=_v;}
    void pop(){rr--;}
    int back(){return s[rr];}
    int secback(){return s[rr-1];}
    bool empty(){return fr>rr;}
    void print(){for(int i=fr;i<=rr;i++)printf("%d ",s[i]); puts("");}
};
int T,N,L;
char seq[MAXN];
int pre[MAXN];
DQ S;
int cmp(int b1,int a1,int b2,int a2)
{
    int c1=(pre[b1]-pre[a1-1])*(b2-a2+1);
    int c2=(pre[b2]-pre[a2-1])*(b1-a1+1);
    if(c1==c2)return 0;
    if(c1<c2)return -1;
    if(c1>c2)return 1;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        S.clear();
        scanf("%d%d",&N,&L);
        scanf("%s",seq);
        pre[0]=0;
        for(int i=0;i<N;i++)
        {
            pre[i+1]=pre[i]+seq[i]-'0';
            //cout<<pre[i+1]<<" ";
        }
        //puts("");
        int ansL=1,ansR=L;
        //double slope,ans=0.0;

        int cur=0;
        for(int i=L;i<=N;i++)
        {
            int j=i-L+1;
            while(S.size()-cur>=2&&cmp(j-1,S.back(),j-1,S.secback())<=0)S.pop();
            S.push(j);
            //S.print();
            while(S.size()-cur>=2&&(cmp(i,S.s[cur+1],i,S.s[cur])>=0))cur++;
            //cur--;
            
            int c=cmp(i,S.s[cur],ansR,ansL);
            if(c==1||(c==0&&ansR-ansL>i-S.s[cur])){ansL=S.s[cur];ansR=i;}
        }
        printf("%d %d\n",ansL,ansR);
        //puts("");
    }
    return 0;
}

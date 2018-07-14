//polynomial multiplication,

#include <stdio.h>
#include <iostream>
#include <vector>
#include <assert.h>
#include <string.h>
#define test
#define MAXN 100005
#define VEC_SIZE 10
using namespace std;

//int ANS[MAXN];
char S[MAXN];
char T[MAXN];
int getn(int x,int y)
{
    int res=1;
    while(res<x||res<y)res<<=1;
    return res;
}
struct vec
{
    int s[VEC_SIZE];
    vec(){for(int i=0;i<VEC_SIZE;i++)fill(s,s+VEC_SIZE,0);}
    vec(int p){for(int i=0;i<VEC_SIZE;i++)fill(s,s+VEC_SIZE,0);s[p]=1;}
    inline int sumup(){int res=0;for(int i=0;i<VEC_SIZE;i++)res+=s[i];return res;}
    vec operator +(const vec &r)
    {
        vec res;
        for(int i=0;i<VEC_SIZE;i++)res.s[i]=s[i]+r.s[i];
        return res;
    }
    void operator +=(const vec &r)
    {
        for(int i=0;i<VEC_SIZE;i++)s[i]+=r.s[i];
    }
    vec operator -(const vec &r)
    {
        vec res;
        for(int i=0;i<VEC_SIZE;i++)res.s[i]=s[i]-r.s[i];
        return res;
    }
    vec operator *(const vec &r)
    {
        vec res;
        for(int i=0;i<VEC_SIZE;i++)res.s[i]=s[i]*r.s[i];
        return res;
    }
};
vector<vec> P,Q;
vector<vec> sum(vector<vec>& p,vector<vec>& q,int sgn)
{
    vector<vec> res;
    for(int i=0;i<p.size();i++)
    {
        if(sgn==1)res.push_back(p[i]+q[i]);
        else res.push_back(p[i]-q[i]);
    }
    return res;
}
void print(vector<vec> &p)
{
    for(int k=0;k<VEC_SIZE;k++){
    for(int i=0;i<p.size();i++)
    {
        printf("%d ",p[i].s[k]);
    }
    puts("");
    }
    puts("");
}
vector<vec> mult(vector<vec>& p,vector<vec>& q)
{
    //print(p);
    //print(q);
    int n=p.size();
    if(n<=64)
    {
        vector<vec> res;
        res.reserve(2*n);
        res.resize(2*n);
        for(int i=0;i<q.size();i++)
        {
            for(int j=0;j<p.size();j++)
            {
                res[i+j]+=p[j]*q[i];
            }
        }
        return res;
    }
    int m=n/2;
    vector<vec> a0,a1,b0,b1;
    for(int i=0;i<m;i++)a0.push_back(p[i]),b0.push_back(q[i]);
    for(int i=m;i<n;i++)a1.push_back(p[i]),b1.push_back(q[i]);
    vector<vec> u=sum(a0,a1,1),v=sum(b0,b1,1);
    vector<vec> a0b0=mult(a0,b0),mid=mult(u,v),a1b1=mult(a1,b1);
    u=sum(mid,a0b0,-1);
    mid=sum(u,a1b1,-1);
    for(int i=m;i-m<mid.size();i++)
    {
        if(i<a0b0.size())a0b0[i]+=mid[i-m];
        else a0b0.push_back(mid[i-m]);
    }
    for(int i=n;i-n<a1b1.size();i++)
    {
        if(i<a0b0.size())a0b0[i]+=a1b1[i-n];
        else a0b0.push_back(a1b1[i-n]);
    }
    return a0b0;
}
int main()
{
    //for(int i=0;i<2*n;i++)ANS[i]=0;
    scanf("%s",S);
    int n=strlen(S);
    for(int i=0;i<n;i++)P.push_back(vec(S[i]-'a'));
    scanf("%s",S);
    int m=strlen(S);
    for(int i=0;i<m;i++)Q.push_back(vec(S[m-1-i]-'a'));

    n=getn(n,m);
    while(P.size()<n)P.push_back(vec());
    while(Q.size()<n)Q.push_back(vec());

    vector<vec> ANS=mult(P,Q);
    //print(ANS);
    int ans=0;
    for(int i=0;i<ANS.size();i++)ans=max(ans,ANS[i].sumup());//puts("");
    printf("%d\n",ans);
    //#ifdef test
    //system("PAUSE");
    //#endif // test
    return 0;
}

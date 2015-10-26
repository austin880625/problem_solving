#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
int sign[8];
int X,ans;
struct Node
{
    int num,sgn,din;
};
void SUM(Node &A,Node B)
{
    A.num*=B.din;
    A.din*=B.din;
    A.sgn=B.sgn;
    if(A.sgn==1)A.num+=B.num*A.din;
    if(A.sgn==2)A.num-=B.num*A.din;
    if(!(A.num%A.din)){A.num/=A.din;A.din=1;}
}
queue<Node> T;
int calc()
{
    int temp=1;
    for(int i=0;i<=8;i++)
    {
        while(sign[i]==0&&i<8)
        {
            temp*=10,temp+=(i+2);
            i++;
        }
        T.push((Node){temp,(i<8 ? sign[i]:-1),1});
        temp=i+2;
    }

    while(!T.empty())
    {
        Node t=T.front();T.pop();
        Node temp=t;
        while(t.sgn==3||t.sgn==4)
        {
            static Node t2=T.front();T.pop();
            if(t.sgn==3){temp.num*=t2.num;temp.din*=t2.din;}
            if(t.sgn==4){temp.din*=t2.num;temp.num*=t2.din;}
            t=t2;temp.sgn=t.sgn;
        }
        T.push(temp);
        if(t.sgn==-1)break;
        //if(ans<100)cout<<t.num<<" ";
    }
    Node res=T.front();T.pop();
    while(!T.empty())
    {
        Node t=T.front();T.pop();
        SUM(res,t);
        //if(t.sgn==-1)cout<<"S:"<<T.size()<<endl;
    }
    //printf("%d\n",res.num);
    //if(ans<100)cout<<endl;
    return res.din==1 ? (res.num==X ? 1 : 0 ):0;
}
void dfs(int now,int sgn)
{
    sign[now]=sgn;
    if(now==7)
    {
        ans+=calc();
        return ;
    }
    for(int i=0;i<5;i++)dfs(now+1,i);
}

int main()
{
    scanf("%d",&X);

    for(int i=0;i<5;i++)dfs(0,i);
    printf("%d\n",ans);
    return 0;
}

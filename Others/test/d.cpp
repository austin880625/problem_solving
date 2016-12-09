#include <iostream>
#include <stdio.h>
#include <assert.h>
#define MAXN 200000
#define MAXCORD 1000000
using namespace std;
struct Node
{
    int sz;
    bool c;
    Node *ch[2];
    Node(bool _c){ch[0]=ch[1]=NULL;sz=1;c=_c;}
};
inline int Sz(Node *o){return o ? o->sz : 0;}
inline void maintain(Node *&o)
{
    //sz is the number of points under this interval
    o->sz=0;
    o->sz+=Sz(o->ch[0])+Sz(o->ch[1]);
}

int N;
//X,Y inserting
int IX,IY;
Node *XDtree;


//xpyl,xpyr :left,right boundary of x+y,xmyl,xmyr: left ,right boundary of x-y
void insert(Node *&o,int xpyl,int xpyr,int xmyl,int xmyr,bool c)
{
    if(!o)o=new Node(c);
    //cout<<xpyl<<" "<<xpyr<<" "<<xmyl<<" "<<xmyr<<endl;
    if(xpyl==xpyr&&xmyl==xmyr){return ;}
    int mid;
    if(c)
    {
        mid=(xpyl+xpyr)/2;
        if(IX+IY<=mid)insert(o->ch[0],xpyl,mid,xmyl,xmyr,!c);
        else insert(o->ch[1],mid+1,xpyr,xmyl,xmyr,!c);
    }
    else
    {
        mid=(xmyl+xmyr)/2;
        if(xmyl+xmyr<0)mid--;
        if(IX-IY<=mid)insert(o->ch[0],xpyl,xpyr,xmyl,mid,!c);
        else insert(o->ch[1],xpyl,xpyr,mid+1,xmyr,!c);
    }
    maintain(o);
}

int Qxpyl,Qxpyr,Qxmyl,Qxmyr;
int query(Node *&o,int xpyl,int xpyr,int xmyl,int xmyr,bool c)
{
    if(!o)return 0;
    if(Qxpyl<=xpyl&&xpyr<=Qxpyr&&Qxmyl<=xmyl&&xmyr<=Qxmyr)return o->sz;
    int mid,res=0;
    if(c)
    {
        mid=(xpyl+xpyr)/2;
        if(Qxpyl<=mid)res+=query(o->ch[0],xpyl,mid,xmyl,xmyr,!c);
        if(Qxpyr>mid) res+=query(o->ch[1],mid+1,xpyr,xmyl,xmyr,!c);
    }
    else
    {
        mid=(xmyl+xmyr)/2;
        if(xmyl+xmyr<0)mid--;
        if(Qxmyl<=mid)res+=query(o->ch[0],xpyl,xpyr,xmyl,mid,!c);
        if(Qxmyr>mid) res+=query(o->ch[1],xpyl,xpyr,mid+1,xmyr,!c);
    }
    return res;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        XDtree=NULL;
        scanf("%d",&N);
        int t;
        for(int i=0;i<N;i++)
        {
            scanf("%d%d%d",&t,&IX,&IY);
            if(t==0)insert(XDtree,2,2*MAXCORD,1-MAXCORD,MAXCORD-1,0);
            else
            {
                int ansl=0,ansr=2*MAXCORD;
                //binary search on the manhatton distance
                int rt=0;
                while(ansl<ansr)
                {
                    int mid=(ansl+ansr)/2;
                    Qxpyl=IX+IY-mid;
                    Qxpyr=IX+IY+mid;
                    Qxmyl=IX-IY-mid;
                    Qxmyr=IX-IY+mid;
                    if(query(XDtree,2,2*MAXCORD,1-MAXCORD,MAXCORD-1,0)>=1)ansr=mid;
                    else ansl=mid+1;
                    //assert(rt++<35);
                }
                printf("%d\n",ansl);
            }
        }
    }
    return 0;
}

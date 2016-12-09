#include <iostream>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#define MAXN 200000
#define MAXCORD 1000000
using namespace std;

int sz[MAXCORD*16];
int ch[MAXCORD*16][2];
int node_cnt;
int newnode(){sz[++node_cnt]=0;ch[node_cnt][0]=ch[node_cnt][1]=0;return node_cnt;}
//bool c[MAXCORD*8];

int N;
int IX,IY;

void insert(int o,int xpyl,int xpyr,int xmyl,int xmyr,bool c)
{
    //cout<<o<<" "<<xpyl<<" "<<xpyr<<" "<<xmyl<<" "<<xmyr<<endl;
    if(xpyl==xpyr&&xmyl==xmyr){sz[o]=1;return ;}
    int mid;
    if(c)
    {
        mid=(xpyl+xpyr)/2;
        if(IX+IY<=mid)insert(ch[o][0] ? ch[o][0] : ch[o][0]=newnode(),xpyl,mid,xmyl,xmyr,!c);
        else insert(ch[o][1] ? ch[o][1] : ch[o][1]=newnode(),mid+1,xpyr,xmyl,xmyr,!c);
    }
    else
    {
        mid=(xmyl+xmyr)/2;
        if(xmyl+xmyr<0)mid--;
        if(IX-IY<=mid)insert(ch[o][0] ? ch[o][0] : ch[o][0]=newnode(),xpyl,xpyr,xmyl,mid,!c);
        else insert(ch[o][1] ? ch[o][1] : ch[o][1]=newnode(),xpyl,xpyr,mid+1,xmyr,!c);
    }
    sz[o]=sz[ch[o][0]]+sz[ch[o][1]];
    //cout<<"YEE"<<sz[o]<<endl;
}

int Qxpyl,Qxpyr,Qxmyl,Qxmyr;
int query(int o,int xpyl,int xpyr,int xmyl,int xmyr,bool c)
{
    //if(!sz[c][o])return 0;
    if(Qxpyl<=xpyl&&xpyr<=Qxpyr&&Qxmyl<=xmyl&&xmyr<=Qxmyr)return sz[o];
    int mid,res=0;
    if(c)
    {
        mid=(xpyl+xpyr)/2;
        if(Qxpyl<=mid&&ch[o][0])res+=query(ch[o][0],xpyl,mid,xmyl,xmyr,!c);
        if(Qxpyr>mid&&ch[o][1]) res+=query(ch[o][1],mid+1,xpyr,xmyl,xmyr,!c);
    }
    else
    {
        mid=(xmyl+xmyr)/2;
        if(xmyl+xmyr<0)mid--;
        if(Qxmyl<=mid&&ch[o][0])res+=query(ch[o][0],xpyl,xpyr,xmyl,mid,!c);
        if(Qxmyr>mid&&ch[o][1]) res+=query(ch[o][1],xpyl,xpyr,mid+1,xmyr,!c);
    }
    return res;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        //assert(T>=2);
        //XDtree=NULL;
        node_cnt=0;
        //memset(sz,0,sizeof(sz));
        //memset(ch,0,sizeof(ch));
        scanf("%d",&N);
        int t;
        int XDtree=newnode();
        for(int i=0;i<N;i++)
        {
            scanf("%d%d%d",&t,&IX,&IY);
            if(t==0)insert(XDtree,2,2*MAXCORD,1-MAXCORD,MAXCORD-1,0);
            else
            {
                //cout<<sz[1]<<endl;
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
                    //cout<<ansl<<" "<<ansr<<endl;
                    //assert(rt++<35);
                }
                printf("%d\n",ansl);
            }
            //printf("%d\n",sz[1]);
        }
    }
    return 0;
}

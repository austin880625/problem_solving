#include<iostream>
#include<math.h>

using namespace std;

int ar[1000];
int treee[3][2005];
int n;

void update(int O,int L,int R,int pos,int v)
{
    if(L==R)
    {
        for(int i=0;i<3;i++)treee[i]=v;
        return ;
    }
    int mid=(L+R)/2;
    if(pos<=mid)update(O*2,L,mid,pos,v);
    else update(O*2+1,mid,R,pos,v);
    
    treee[0][O]=max(tmax[O*2],tmax[O*2+1]);
    treee[1][O]=min(tmax[O*2],tmax[O*2+1]);
    treee[2][O]=tmax[O*2]+tmax[O*2+1];
}

int a,b;
int query(int f,int O,int L,int R)
{
    if(L==R)
    {
        return treee[f][O];
    }
    int mid=(L+R)/2;
    int ans,inf=(1<<30);
    if(f==0)
    {
        
    }
}

int main(){
	while(scanf("%d %d",&n,&q)==2)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&ar[i]);
            update(1,0,n-1,i,ar[i]);
        }
        for(int i=0;i<q;i++)
        {
            scanf("%d %d",&a,&b);
            printf("%d %d %d\n",query(0,1,0,n-1),query(1,1,0,n-1),query(2,1,0,n-1));
        }
	}
}


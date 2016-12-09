#include <stdio.h>
#include <iostream>
#define MAXN 100005
using namespace std;

struct Node
{
	int v,setv;
	Node *ch[2];
	Node(int _v){ch[0]=ch[1]=NULL;v=_v;}
};

Node* T=NULL;
int N,M;
int A[MAXN];
int QL[MAXN],QR[MAXN],QQ[MAXN];

void build(Node*& o, int l, int r)
{
	if(o==NULL)o=new Node(0);
	o->v=o->setv=0;
	if(l==r){A[l]=0;return ;}
	int mid=(l+r)/2;
	build(o->ch[0],l,mid);
	build(o->ch[1],mid+1,r);
}

void push_down(Node *&o)
{
	o->setv=0;
	if(o->ch[0])o->ch[0]->setv=1,o->ch[0]->v|=o->v;
	if(o->ch[1])o->ch[1]->setv=1,o->ch[1]->v|=o->v;
}

void pull(Node *&o)
{
	o->v=o->ch[0]->v&o->ch[1]->v;
}

int L,R,Q;
void modify(Node*& o, int l, int r)
{
	if(o->setv)push_down(o);
	if(L<=l&&r<=R)
	{
		o->v|=Q;
		o->setv=1;
		return ;
	}
	int mid=(l+r)/2;
	if(L<=mid)modify(o->ch[0],l,mid);
	if(R>mid)modify(o->ch[1],mid+1,r);
	pull(o);
}

int check(Node *&o, int l, int r)
{
	if(o->setv)push_down(o);
	if(L<=l&&r<=R)
	{
		if(l!=r)pull(o);
		return o->v;
	}
	pull(o);
	int res=~0;
	int mid=(l+r)/2;
	if(L<=mid)res&=check(o->ch[0],l,mid);
	if(R>mid)res&=check(o->ch[1],mid+1,r);
	return res;
}
bool check2(Node *&o, int l, int r)
{
	int a=A[L];
	for(int i=L+1;i<=R;i++)a&=A[i];
	if(a==Q)return true;
	return false;
}

void gen_A(Node *&o,int l, int r)
{
	if(l==r)
	{
		A[l]=o->v;
		return ;
	}
	if(o->setv)push_down(o);
	int mid=(l+r)/2;
	gen_A(o->ch[0], l, mid);
	gen_A(o->ch[1], mid+1, r);
	pull(o);
}

int main()
{
	while(scanf("%d%d",&N,&M)==2)
	{
		build(T,1,N);
		bool ans1=1;
		for(int i=0;i<M;i++)
		{
			scanf("%d%d%d",&QL[i],&QR[i],&QQ[i]);
			L=QL[i],R=QR[i],Q=QQ[i];
			modify(T,1,N);
		}
		gen_A(T,1,N);
		for(int i=0;i<M;i++)
		{
			L=QL[i],R=QR[i],Q=QQ[i];
			int v=check(T,1,N);
			for(int i=0;i<31;i++)
			{
				if(((v>>i)&1)==1&&((Q>>i)&1)==0)ans1=false;
			}
		}
		if(ans1)
		{
			puts("YES");
			printf("%d",A[1]);
			for(int i=2;i<=N;i++)printf(" %d",A[i]);
			puts("");
		}
		else
		{
			puts("NO");
		}
	}
	return 0;
}

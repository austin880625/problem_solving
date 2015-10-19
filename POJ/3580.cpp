#include<stdio.h>
#include<iostream>
#include<string.h>
#define INF 2147483647
#define ll long long
using namespace std;

struct Node
{
    ll v,minv;
    int sz;
    int flip,add;
    Node *ch[2];
    Node(ll xv){
        flip=0;
        add=0;
        v=xv;
        sz=1;
        minv=v;
    }
    Node(){}
};
Node *null = new Node();
void initnull(){null->sz=0;null->minv=INF;null->ch[0]=null;null->ch[1]=null;}
void init(Node *&O){O->ch[0]=null;O->ch[1]=null;}
void maintain(Node *&O)
{
	if(O==null)return ;
    O->sz=O->ch[0]->sz+1+O->ch[1]->sz;
    O->minv=min(O->ch[0]->minv,O->ch[1]->minv);
	O->minv=min(O->v,O->minv);
}
void pushdown(Node *&O)
{
	if(O==null)return;
    if(O->flip)
    {
        swap(O->ch[0],O->ch[1]);
        O->flip=0;
        O->ch[0]->flip^=1;
        O->ch[1]->flip^=1;
    }
    if(O->add)
    {
        if(O->v!=INF)O->v+=O->add;
        if(O->minv!=INF)O->minv+=O->add;
        O->ch[0]->add+=O->add;
        O->ch[1]->add+=O->add;
        O->add=0;
        //maintain(O);
    }
}
void rotate(Node *&O,int dir)
{
    pushdown(O);
    Node *T=O->ch[dir^1];
    O->ch[dir^1]=T->ch[dir];
    T->ch[dir]=O;
    maintain(O);maintain(T);
    O=T;
}

void debug(Node *&O)
{
    //cout<<"r"<<endl;
    if(O==null){cout<<"()";return;}
    //pushdown(O);
    cout<<"(";
    //if(O->v!=INF)
    cout<<O->v<<","<<O->add;
    debug(O->ch[0]);
    debug(O->ch[1]);
    cout<<")";
}

void build(Node *&O)
{
	if(O!=null)
	{
	    pushdown(O);
		build(O->ch[0]);
		//if(O->v!=INF)
			cout<<O->v<<" ";
		build(O->ch[1]);
	}
}

void splay(Node *&O,int k)
{
    pushdown(O);
    int now1=O->ch[0]->sz+1;
    int dir1=(now1==k ? -1 :(k<now1 ? 0 : 1));
    k-=dir1*now1;

    if(dir1!=-1)
    {
        Node *p=O->ch[dir1];
        pushdown(p);
        int childnow=p->ch[0]->sz+1,dir2=(k==childnow ? -1 : (k<childnow ? 0 : 1)); //子樹節點的rank
        k-=dir2*childnow;
        if(dir2!=-1)    //目標不在孫子
        {
            splay(p->ch[dir2],k);  //把它轉到孫子
            if(dir1==dir2)  //一字型
                rotate(O,dir1^1); //先轉根
            else    //之字形
                rotate(O->ch[dir1],dir2^1); //先轉兒子
        }
        rotate(O,dir1^1);
    }
    maintain(O);
}
void split(Node *&O,int k,Node *&L,Node *&R)
{
	//cout<<"To split ";debug(O);cout<<endl;
    splay(O,k);
	pushdown(O);
    R=O->ch[1];
    O->ch[1]=null;
    L=O;
    maintain(L);
	//cout<<"R is";debug(R);cout<<endl;
	//cout<<"L is:";debug(L);cout<<endl;
}
void merge(Node *&L,Node *&R)
{
    pushdown(L);
    if(L==null)L=R;
    splay(L,L->sz);
    L->ch[1]=R;
    maintain(L);
}
void Add(Node *&O,int l,int r,int D)
{
    pushdown(O);
    Node *T1,*T2;
	//cout<<"split1";
    split(O,l,O,T1);
    split(T1,r-l+1,T1,T2);
	//cout<<"split2";
    T1->add+=D;
    debug(O);cout<<endl;debug(T1);cout<<endl;debug(T2);cout<<endl;
    merge(O,T1);
    merge(O,T2);
    //maintain(O);
    debug(O);cout<<endl;
}

void insert(Node *&O,int x,int P)
{
    if(O==null){O=new Node(P);init(O);return;}
    Node *T1;
    split(O,x+1,O,T1);
    Node *A=new Node(P);
    init(A);
	maintain(A);maintain(T1);
    merge(O,A);merge(O,T1);
}

void reverse(Node *&O,int x,int y){
    pushdown(O);
	Node *T1,*T2;
	split(O,x,O,T1);
	split(T1,y-x+1,T1,T2);
	T1->flip^=1;
	pushdown(T1);
	//debug(O);cout<<"; ";debug(T1);cout<<"; ";debug(T2);cout<<endl;
	merge(O,T1);
	merge(O,T2);
	//debug(O);cout<<endl;
}

void Del(Node *&O,int x){
	Node *T1,*T2;
	split(O,x,O,T1);
	split(T1,1,T1,T2);
	delete T1;
	merge(O,T2);
}

int Query(Node *&O,int x,int y){
	Node *T1,*T2;
	pushdown(O);
	split(O,x,O,T1);
	//debug(O);cout<<endl;
	split(T1,y-x+1,T1,T2);
	//cout<<T1->add<<endl;
	//debug(T1);cout<<endl;
	maintain(T1);
	int res=T1->minv;
	merge(T1,T2);
	merge(O,T1);
	maintain(O);
	return res;
}

Node *ST=NULL;
int n,m,x,y,P;
char com[20];
int main()
{
    initnull();
    while(scanf("%d",&n)==1)
    {
    	ST=new Node(INF);
    	init(ST);
		for(int i=0;i<n;i++){
			int t;
			scanf("%d",&t);
			insert(ST,i,t);
			//build(ST);
		}
		//build(ST);
		scanf("%d",&m);
		while(m--){
			scanf("%s",com);
        	if(com[0]=='A'){
				scanf("%d %d %d",&x,&y,&P);
				//debug(ST);
				Add(ST,x,y,P);
			}else if(com[0]=='I'){
				scanf("%d %d",&x,&P);
				insert(ST,x,P);
			}else if(com[0]=='D'){
				scanf("%d",&x);
				Del(ST,x);
			}else if(com[0]=='M'){
				scanf("%d %d",&x,&y);
				printf("%d\n",Query(ST,x,y));
			}
			else if(com[3]=='E')
			{
                scanf("%d %d",&x,&y);
                reverse(ST,x,y);
			}
			else if(com[3]=='O')
            {
			    scanf("%d %d %d",&x,&y,&P);
			    reverse(ST,x,y-P);
                //build(ST);
			    reverse(ST,y-P+1,y);
			    //build(ST);
			    reverse(ST,x,y);
			}
        	//debug(ST);
			//cout<<endl;
			//build(ST);
			//cout<<endl;
		}
    }
    return 0;
}

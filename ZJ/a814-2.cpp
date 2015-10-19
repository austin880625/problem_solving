#include<iostream>
#include<stdio.h>
#include<string.h>
#include<time.h>

using namespace std;

int n,m,Q;
int T[1000005];
int used[1000005];

struct Node
{
    int v,sz;
    Node *ch[2];
    Node(int x){
        v=x;
        sz=1;
        ch[0]=ch[1]=NULL;
    }
};
int getsz(Node *&O){return O ? O->sz : 0;}

void maintain(Node *&O){O->sz=getsz(O->ch[0])+1+getsz(O->ch[1]);}

void rotate(Node *&O,int dir){
    Node* T=O->ch[dir^1];
    O->ch[dir^1]=T->ch[dir];
    T->ch[dir]=O;
    maintain(O);maintain(T);
    O=T;
}

void insert(Node *&O,int v)
{
    if(!O){O=new Node(v);return ;}
    
    int dir=v < O->v ? 0 : 1;
    insert(O->ch[dir],v);
    maintain(O);
    if(getsz(O->ch[dir])>getsz(O->ch[dir^1]))rotate(O,dir^1);
}

int POP(Node *&O)
{
    if(!O->ch[0])
    {
        int res=O->v;
        Node *P=O;
        O=O->ch[1];
        delete P;
        return res;
    }
    return POP(O->ch[0]);
}
/*void debug(Node *O)
{
    if(O==NULL){cout<<"()";return;}
    cout<<"("<<O->v;
    debug(O->ch[0]);
    debug(O->ch[1]);
    cout<<")";
}*/

//以上是樹

Node* Treap=NULL;
int get_int ()
{
    int sign=1,num=0;char tc;
    tc=getchar();
    while((tc>'9'||tc<'0')&&tc!='-')tc=getchar();
    if(tc=='-'){tc=getchar();sign=-1;}
    while(tc<='9'&&tc>='0'){ num=num*10+(tc-'0'),tc=getchar();}
    return sign*num;
}
int main()
{
    /*//this is debug mode
    int x,y;
    while(cin>>x>>y)
    {
        if(x==0)insert(Treap,y);
        else if(x==1) POP(Treap);
        else cout<<getMin(Treap)<<endl;
        debug(Treap);
        cout<<endl;
    }*/
    scanf("%d",&Q);
    while(Q--)
    {
        Treap=NULL;
        int mx=-1;
        int same=0;
        n=get_int();m=get_int();
        for(int i=0;i<=m;i++)used[i]=0;
        for(int i=0;i<n;i++)
        {
            T[i]=get_int();
            if(used[T[i]]++)same++;
        }
        for(int i=1;i<=m;i++)if(!used[i]){insert(Treap,i);mx=max(mx,i);}
        for(int i=n-1;i>=0;i--)
        {
            if(used[T[i]]>1)same--;
            used[T[i]]--;
            if(!used[T[i]]){insert(Treap,T[i]);mx=max(mx,T[i]);}
            //cout<<i<<" : "<<mx<<endl;
            if(mx>T[i]&&same==0)
            {
                int ch=0,t;
                for(int j=i+1;j<n||!ch;)
                {
                    t=POP(Treap);
                    if(t>T[i]&&!ch)
                    {
                        ch=1;T[i]=t;
                    }else if(j<n){
                        T[j++]=t;
                    }
                }
                break;
            }
        }
        
        printf("%d",T[0]);
        for(int i=1;i<n;i++)printf(" %d",T[i]);
        puts("");
    }
    return 0;
}
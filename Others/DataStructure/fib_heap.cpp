#include <stdio.h>
#include <iostream>
#include <vector>
#define LL long long int
#define MAXD 64

using namespace std;

struct fib_node
{
    fib_node *p;
    fib_node *l_sib,*r_sib;
    fib_node *ch;
    int deg;
    LL v;
    fib_node(LL _v)
    {
        v=_v;deg=0;
        p=ch=NULL;
    }
};

struct fib_heap
{
    int n;
    fib_node *A[MAXD];
    fib_node *maxP;
    fib_heap()
    {
        maxP=NULL;n=0;
    }
    void print_root_list()
    {
        for(fib_node *w=maxP;;)
        {
            printf("%lld ",w->v);
            w=w->r_sib;if(w==maxP)break;
        }
        puts("");
    }
    void push(LL v)
    {
        n++;
        if(!maxP)
        {
            maxP=new fib_node(v);
            maxP->l_sib=maxP->r_sib=maxP;
            return ;
        }
        fib_node *t=new fib_node(v);

        t->r_sib=maxP->r_sib;
        t->r_sib->l_sib=t;
        maxP->r_sib=t;
        t->l_sib=maxP;

        if(v>maxP->v)maxP=t;
    }
    void join(fib_heap H)
    {
        n=n+H.n;
        if(maxP==NULL||(H.maxP!=NULL&&H.maxP->v>maxP->v)){maxP=H.maxP;}
        maxP->r_sib->l_sib=H.maxP->r_sib;
        H.maxP->r_sib->l_sib=maxP->r_sib;
        maxP->r_sib=H.maxP;
        H.maxP->r_sib=maxP;
    }
    LL top()
    {
        return maxP ? maxP->v : 0;
    }
    void heap_link(fib_node *&y,fib_node *&x)
    {
        y->l_sib->r_sib=y->r_sib;
        y->r_sib->l_sib=y->l_sib;
        x->deg++;
        y->p=x;
        if(x->ch==NULL){y->r_sib=y->l_sib=y;x->ch=y;return ;}
        y->r_sib=x->ch->r_sib;
        y->l_sib=x->ch;
        x->ch->r_sib->l_sib=y;
        x->ch->r_sib=y;
    }
    void consolidate()
    {
        for(int i=0;i<MAXD;i++)A[i]=NULL;
        for(fib_node *w=maxP;;)
        {
            fib_node *x=w;
            cout<<"now on "<<w->v<<" within the root list"<<endl;
            int d=x->deg;
            while(A[d]!=NULL)
            {
                fib_node *y=A[d];
                if(x->v<y->v)swap(x,y);
                heap_link(y,x);
                A[d++]=NULL;
            }
            A[d]=x;
            w=w->r_sib;
            if(w==maxP)break;
        }
        maxP=NULL;
        for(int i=0;i<MAXD;i++)
        {
            if(A[i]==NULL)continue;
            if(maxP==NULL||A[i]->v>maxP->v)maxP=A[i];
        }
    }
    void pop()
    {
        fib_node *t=maxP;
        if(!t)return ;
        cout<<"to be removed: "<<t->v<<endl;
        fib_node *c=t->ch;
        while(c&&c->p)
        {
            fib_node *nxt=c->r_sib;
            c->p=NULL;
            t->r_sib->l_sib=c;
            c->r_sib=t->r_sib;
            t->r_sib=c;
            c->l_sib=t;

            c=nxt;
        }
        print_root_list();
        if(t->r_sib==t)delete t,maxP=NULL;
        else
        {
            maxP=t->r_sib;
            cout<<"new maxP is "<<maxP->v<<endl;
            t->l_sib->r_sib=t->r_sib;
            t->r_sib->l_sib=t->l_sib;
            delete t;
            consolidate();
        }
        n--;
    }
};

fib_heap H;

int main()
{
    LL x;
    for(int i=0;i<5;i++)
    {
        scanf("%lld",&x);
        H.push(x);
        H.print_root_list();
    }
puts("");
    while(H.n)
    {
        //printf("%d ",H.n);
        H.print_root_list();
        H.pop();
    }
    puts("");
    return 0;
}

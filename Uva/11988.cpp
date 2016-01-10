#include <iostream>
#include <stdio.h>
#include <string.h>
#include <assert.h>

using namespace std;
char s[100005];
struct Node
{
    char c;
    Node *nxt;
    Node(char x){c=x;nxt=NULL;}
};
Node *L=NULL;
Node *cur=NULL,*End=NULL;
int main()
{
    while(scanf("%s",s)!=EOF)
    {
        L=NULL;
        L=new Node('0');
        cur=L;
        End=L;
        int Len=strlen(s);
        for(int i=0;i<Len;i++)
        {
            if(s[i]=='[')
            {
                cur=L;
            }
            else if(s[i]==']')
            {
                cur=End;
            }
            else
            {
                Node *T=cur->nxt;
                cur->nxt=new Node(s[i]);
                cur=cur->nxt;
                cur->nxt=T;
                if(End->nxt){End=End->nxt;}
            }
        }
        cur=L->nxt;
        int len=0;
        while(cur)
        {
            len++;
            printf("%c",cur->c);
            cur=cur->nxt;
        }
        //cout<<Len<<" "<<len<<endl;
        assert(len=Len);
        puts("");
    }
    return 0;
}

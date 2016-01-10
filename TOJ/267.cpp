#include <iostream>
#include <stdio.h>
#include <map>
#include <string.h>
#include <vector>
#include <assert.h>
#define MAX_SIGMA 27
#define MAXN 1000005
using namespace std;

struct node
{
    char v;
    int pass;
    map<char,int> ch;
    node(char x){ch.clear();v=x;pass=0;}
};

vector<node> trie;
int sz;
char S[MAXN];
int T,N;
int insert(char *s)
{
    int cur=0;
    trie[cur].pass++;
    for(int i=0;s[i]!='\0';i++)
    {
        if(trie[cur].ch.find(s[i])!=trie[cur].ch.end())
        {
            cur=trie[cur].ch[s[i]];
            //if(s[i]=='e')cout<<i<<" Yee"<<endl;
        }
        else
        {
            trie.push_back(node(s[i]));sz++;
            //cout<<trie[cur].pass<<" "<<trie[cur].v<<endl;
            trie[cur].ch.insert(pair<char,int>(s[i],sz));
            cur=sz;
        }
        //cout<<trie[cur].pass<<endl;
        trie[cur].pass++;
        //if(trie[cur].pass>=2)cout<<trie[cur].v<<endl;
    }
    int res=0;
    cur=0;
    for(int i=0;s[i]!='\0';i++)
    {
        res++;
        //cout<<s[i]<<" "<<trie[cur].pass<<endl;
        //cout<<"now has been passed "<<trie[cur].pass<<" times"<<endl;
        cur=trie[cur].ch[s[i]];
        if(trie[cur].pass==1){break;}
    }
    return res;
}

int main()
{
    scanf("%d",&T);
    int kase=0;
    while(T--)
    {
        trie.clear();
        trie.push_back(node('0'));sz=0;
        //trie[0].pass++;
        scanf("%d",&N);
        int ans=0;
        for(int i=0;i<N;i++)
        {
            scanf("%s",S);
            ans+=insert(S);
            //printf("%d ",ans);
        }
        //puts("");
        //printf("%d\n",trie[0].pass);
        printf("Case #%d: %d\n",++kase,ans);
    }
    return 0;
}

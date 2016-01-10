#include<iostream>
#include<string.h>

using namespace std;

struct Trie
{
    int ch[1000][30];
    int val[1000];
    int sz;
    Trie(){sz=1;memset(ch[0],0,sizeof(ch[0]));}
    int idx(char c){return c-'a';}

    void insert(char *s,int v)
    {
        int current=0,n=strlen(s);
        for(int i=0;i<n;i++)
        {
            int next=idx(s[i]);
            if(!ch[current][next])
            {
                memset(ch[sz],0,sizeof(ch[sz]));
                val[sz]=0;
                ch[current][next]=sz++;
            }
            current=ch[current][next];
        }
        val[current]=v;
    }

    int query(char *s)
    {
        int cur=0,n=strlen(s);
        for(int i=0;i<n;i++)
        {
            int next=idx(s[i]);
            if(!ch[cur][next])return 0;
            cur=ch[cur][next];
        }
        return val[cur];
    }
};

int main()
{
    char input[105];
    char c;
    Trie T;
    while(cin>>c)
    {
        if(c=='e')break;
        if(c=='i')
        {
            int v;
            cin>>input>>v;
            T.insert(input,v);
        }
        if(c=='q')
        {
            cin>>input;
            cout<<T.query(input)<<endl;
        }
    }
    return 0;
}

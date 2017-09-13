#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#define MAXN 2000005

using namespace std;

int N;
char s[20005][105];
char bmail_domain[11]="moc.liamb@";
vector<int> groupname[2];

struct trie{
    int sz=0,id=0,bmail=0;
    int ch[MAXN][29];
    vector<int> group[MAXN];
    int insert(char *s,int num){
        int plus=0,at=0,now=0;
        for(int i=0;s[i]!='\0';i++){
            int c=s[i];
            if(c=='.'&&!at&&bmail)continue;
            else if(c=='.')c='z'+3;
            else if(c=='+')plus=1,c='z'+2;
            else if(c=='@'){plus=0,at=1;c='z'+1;}
            if(bmail&&plus)continue;
            if('A'<=c&&c<='Z')c='a'+c-'A';
            c=c-'a';
            if(!ch[now][c])ch[now][c]=++id;
            now=ch[now][c];
            if(s[i+1]=='\0'){
                group[now].push_back(num);
                if(group[now].size()==1)groupname[bmail].push_back(now);
                return group[now].size();
            }
        }
        return 0;
    }
    void clear(){
        for(int i=0;i<=id;i++){group[i].clear();for(int j=0;j<28;j++)ch[i][j]=0;}
    }
};

int isbmail(char *s){
    int len=strlen(s);
    for(int i=1;i<=10;i++){
        int c=s[len-i];
        if('A'<=c&&c<='Z')c='a'+c-'A';
        if(c!=bmail_domain[i-1])return 0;
    }
    return 1;
}

trie Mail[2];

int main(){
    while(scanf("%d",&N)==1){
        Mail[0].clear(),Mail[1].clear();
        Mail[1].bmail=1;
        int ans=0;
        for(int i=0;i<N;i++){
            scanf("%s",s[i]);
            if(isbmail(s[i])){
                if(Mail[1].insert(s[i],i)==1)ans++;
                //cout<<"yee"<<endl;
            }else {
                if(Mail[0].insert(s[i],i)==1)ans++;
            }
        }
        printf("%d\n",ans);
        for(int i=0;i<2;i++){
            for(int j=0;j<groupname[i].size();j++){
                int K=Mail[i].group[groupname[i][j]].size();
                printf("%d",K);
                for(int k=0;k<K;k++){
                    printf(" %s",s[Mail[i].group[groupname[i][j]][k]]);
                }
                puts("");
            }
        }
    }
    return 0;
}

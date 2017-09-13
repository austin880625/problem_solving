#include <stdio.h>
#include <iostream>
#include <map>
#include <set>
#include <vector>

#define LL long long int
#define MAXN 200005

using namespace std;

int N,Q;
set<int> S;
map<int,int> M[2];

int main()
{
    while(scanf("%d%d",&N,&Q)==2)
    {
        M[0].clear();M[1].clear();
        S.clear();
        M[0][1]=0;M[1][1]=0;
        for(int i=0;i<Q;i++)
        {
            int q[2];char op;
            scanf("%d %d %c",&q[1],&q[0],&op);
            if(S.find(q[1])==S.end())S.insert(q[1]);
            else {puts("0");continue;}

            //for(set<int>::iterator it=S.begin();it!=S.end();it++)printf("%d ",(*it));
            //puts("");
            int dir=op=='L' ? 0 : 1;
            map<int,int>::iterator it=M[dir].upper_bound(q[dir]); it--;
            printf("%d\n",q[dir^1]-(*it).second);
            // if(M[dir^1][(*it).second+1]<q[dir])
            // {
            //     M[dir^1][q[dir^1]+1]=M[dir^1][(*it).second+1];
            //     M[dir^1][(*it).second+1]=q[dir];
            // }
            // else
            // {
            M[dir][q[dir]+1]=M[dir][(*it).first];M[dir][q[dir]]=q[dir^1];
                it=M[dir^1].upper_bound(q[dir^1]); it--;
                M[dir^1][q[dir^1]+1]=M[dir^1][(*it).first];
                M[dir^1][(*it).first]=q[dir];
            //}
        }
    }
    return 0;
}

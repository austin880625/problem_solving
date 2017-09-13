#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#define LL long long

using namespace std;

int N;
int A[50005];
set<int> S;

int main()
{
    while(scanf("%d",&N)==1)
    {
        S.clear();
        for(int i=0;i<N;i++)
        {
            scanf("%d",A+i);
            S.insert(A[i]);
        }
        //sort(A,A+N);
            for(set<int>::reverse_iterator rit=S.rbegin();;rit=S.rbegin())
            {
                //cout<<(*rit)<<endl;
                int now=(*rit)/2;
                set<int>::iterator it=S.find(now);
                while(it!=S.end())now/=2,it=S.find(now);//,cout<<"rit"<<endl;
                if(now==0)break;
                S.erase(*rit);S.insert(now);

            }
            //cout<<"YEE"<<endl;
        for(set<int>::iterator it=S.begin();it!=S.end();it++)
        {
            if(it!=S.begin())printf(" ");
            printf("%d",(*it));
        }
        puts("");
    }
    return 0;
}

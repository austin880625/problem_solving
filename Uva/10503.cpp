#include<iostream>

using namespace std;
int n,m;
int used[100];
int ans;

struct domino
{
    int fr,ta;
    int connect(domino D)
    {
        if(ta==D.fr)return 1;
        if(ta==D.ta)return -1;
        return 0;
    }
};
domino Dominos[100];
int ord[100];

void dfs(int dep,int now)
{
    //cout<<"\n";
    //for(int i=0;i<dep;i++)cout<<"\t";
    domino D=Dominos[now];
    //cout<<ans<<" "<<now<<"\n";
    if(dep==n)
    {
        //cout<<"Get!!"<<endl;
        ans=(D.ta==Dominos[2].fr ? 1 : 0);
    }
    else if(!ans)
    {
        //for(int t=0;t<dep;t++)cout<<"\t";
        for(int i=4; i<=2*(m+1)+1; i++)
        {

            //cout<<"["<<used[i]<<"]";
            if(!used[i])
            {
                int det=D.connect(Dominos[i]);
                if(det)
                {
                    used[i]=used[i^1]=1;
                    dfs(dep+1,i);
                    used[i]=used[i^1]=0;
                }
            }
        }
        //cout<<endl;
    }
}

int main()
{
    while(cin>>n)
    {
        if(n==0)break;
        cin>>m;
        int f,t;
        for(int i=0; i<=m+1; i++)
        {
            used[2*i]=used[2*i+1]=0;
            cin>>f>>t;
            Dominos[2*i]=(domino){f,t};
            Dominos[2*i+1]=(domino){t,f};
        }
        ord[0]=0;
        ans=0;
        dfs(0,0);
        cout<<(ans ? "YES" : "NO")<<endl;
    }
    return 0;
}
/*
3
4
0 1
3 4
2 1
5 6
2 2
3 2
2
4
0 1
3 4
1 4
4 4
3 2
5 6
0
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct sold
{
    int b,j;
    bool operator < (const sold &rhs)const
    {
        return j>rhs.j;
    }
};
vector<sold> S;

int main()
{
    int N,kase=0;
    while(cin>>N)
    {
        if(!N)break;
        S.clear();
        for(int i=0;i<N;i++)
        {
            int b,j;
            cin>>b>>j;
            S.push_back((sold){b,j});
        }
        sort(S.begin(),S.end());
        int T=0,ans=0;
        for(int i=0;i<N;i++)
        {
            T+=S[i].b;
            if(T+S[i].j>=ans){ans=T+S[i].j;}
        }
        cout<<"Case "<<++kase<<": "<<ans<<endl;
    }
    return 0;
}

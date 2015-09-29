#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int n,m;
    vector<int> heads;
    vector<int> knights;
    while(cin>>n>>m)
    {
        if(n==0&&m==0)break;
        heads.clear();
        knights.clear();
        for(int i=0;i<n;i++)
        {
            int t;
            cin>>t;
            heads.push_back(t);
        }
        for(int i=0;i<m;i++)
        {
            int t;
            cin>>t;
            knights.push_back(t);
        }
        sort(heads.begin(),heads.end());
        sort(knights.begin(),knights.end());
        
        int cur=0,ans=0;
        for(int i=0;i<heads.size();i++)
        {
            if(cur==knights.size()){ans=-1;break;}
            if(heads[i]<=knights[cur])
            {
                ans+=knights[cur];
            }
            else
                i--;
            cur++;
        }
        if(ans==-1)
            cout<<"Loowater is doomed!"<<endl;
        else
            cout<<ans<<endl;
    }
    return 0;
}

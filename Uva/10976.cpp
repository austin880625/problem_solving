#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int x,k;
    vector<int> y;
    while(cin>>k)
    {
        y.clear();
        int K=2*k;
        for(int i=k+1;i<=K;i++)
        {
            if((k*i)%(i-k)==0)
            {
                y.push_back(i);
            }
        }
        cout<<y.size()<<endl;
        for(int i=0;i<y.size();i++)
        {
            cout<<"1/"<<k<<" = 1/"<<(k*y[i])/(y[i]-k)<<" + 1/"<<y[i]<<endl;
        }
    }
}

#include <stdio.h>
#include<iostream>
#include<queue>
#include<vector>
#include<fstream>
#include<string>
#include<map>
#define MAX_N 1000

using namespace std;

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("p1l.out","w",stdout);
    int T,N;
    int rate,ans1,ans2,M;
    int m[MAX_N];
    cin>>T;
    for(int kase=1;kase<=T;kase++)
    {
        cin>>N;
        ans1=ans2=0;
        rate=0;
        for(int i=0;i<N;i++)
		{
			cin>>m[i];
		}
		for(int i=0;i<N-1;i++)
		{
			//M+=m[i];
			if(m[i]>=m[i+1]){
				ans1+=m[i]-m[i+1];
				if(rate<=m[i]-m[i+1])
				{
					int tr=m[i]-m[i+1];
					rate=max(rate,tr);
				}
			}
		}
		//cout<<rate<<endl;
		for(int i=0;i<N-1;i++)
		{
			if(rate>=m[i]){ans2+=m[i];}
			else ans2+=rate;
		}
		cout<<"Case #"<<kase<<": "<<ans1<<" "<<ans2<<endl;
    }
}

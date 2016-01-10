//
//  p1.cpp
//
//
//  Created by Mac on 4/3/15.
//
//

#include <stdio.h>
#include<iostream>
#include<algorithm>
#include<fstream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#define INF 2147483646
#define MAX_D 1005
using namespace std;

int D,P[MAX_D],ans;

int main()
{
    //freopen("B.in","r",stdin);
    //freopen("p2.out","w",stdout);
    int T;
    cin>>T;
	for(int kase=1;kase<=T;kase++)
	{
		cin>>D;
		ans=INF;
        for(int i=0;i<D;i++)cin>>P[i];
        sort(P,P+D);
        
		cout<<"Case #"<<kase<<": "<<ans<<endl;
	}
}

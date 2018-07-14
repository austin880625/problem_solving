#include <stdio.h>
#include <iostream>

using namespace std;

typedef long long int ll;

const double eight = 1200;
const double day = 1440;

int hh, mm;
double H,D,N,C;

int main()
{
	cin>>hh>>mm;
	cin>>H>>D>>C>>N;
	int now = hh*60+mm;
	int d = 0;
	if(eight <= now && now <= day){}
	else d = eight - now;
	int num = (int)H/(int)N;
	if((int)H%(int)N) num++;
	if(d == 0)
	{
		cout << num*(C*0.8) << endl;
		return 0;
	}
	double ans = num*C;
	//cout<<ans<<" "<<d<<endl;
	H += d*D;
	for(int i=0; i<=num; i++)
	{
		double tmp = i*C;
		//cout<<H<<endl;
		int tmpn = (int)H/(int)N;
		if((int)H%(int)N) tmpn++;
		
		tmp += (double)tmpn*(C*0.8);
		ans = min(tmp, ans);
		H -= N;
	}
	cout << ans << endl;
	return 0;
}

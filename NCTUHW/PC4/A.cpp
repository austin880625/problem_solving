#include <stdio.h>
#include <iostream>

using namespace std;

string s;

int main()
{
	int n;
	cin >> n;
	getline(cin, s);
	getline(cin, s);
	int ans=0, tmp=0;
	for(int i=0; i<s.length(); i++){
		if(s[i] == ' '){
			ans = max(ans, tmp);
			tmp = 0;
		}
		if(s[i] >= 'A' && s[i] <= 'Z'){
			tmp++;
		}
	}
	ans = max(ans, tmp);
	cout<<ans<<endl;

	return 0;
}

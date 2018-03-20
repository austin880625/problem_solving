#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int cnt[28];
string s;
int N;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    while(cin>>N){
        cin>>s;
        int sz=0;
        int ans=0;
        for(int i=0;i<=N;i++){
            if(i==N||('A'<=s[i]&&s[i]<='Z')){
                for(int j=0;j<28;j++)cnt[j]=0;sz=0;
            }else{
                if(cnt[s[i]-'a'])continue;
                //cout<<i<<" "<<s[i]<<endl;
                sz++;
                cnt[s[i]-'a']++;
                ans=max(ans,sz);
            }
        }
        cout<<ans<<endl;

    }

    return 0;
}

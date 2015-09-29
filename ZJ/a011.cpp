#include<iostream>
#include<string>

using namespace std;

int isAlpha(int c)
{
    return (c>='A'&&c<='Z')||(c>='a'&&c<='z');
}

int main()
{
    string S;
    while(getline(cin,S))
    {
        int ans=0;
        for(int i=0;i<S.length();i++)
        {
            if(isAlpha(S[i]))
            {
                ans++;
                while(isalpha(S[i]))i++;
                i--;
            }
        }
        cout<<ans<<endl;
    }
}
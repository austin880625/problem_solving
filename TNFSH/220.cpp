#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int N,T;
int KAN,PP;
int marker;
string S;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        marker=KAN=PP=0;
        scanf("%d",&N);
        cin>>S;
        for(int i=0;i<S.length();i++)
        {
            if(S[i]=='W')
            {
                KAN+=10;
                KAN+=5*marker;
                marker=0;
            }
            else if(S[i]=='L')
            {
                marker=min(marker+1,5);
                PP+=10;
            }
            else
            {
                KAN+=5;PP+=5;
            }
            //cout<<S[i]<<" "<<i<<" "<<PP<<" "<<KAN<<endl;
        }
        printf("%d %d\n",KAN,PP);
    }
    return 0;
}

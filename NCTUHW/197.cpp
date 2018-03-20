#include <stdio.h>
#include <iostream>

using namespace std;

int T;
string s;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        cin>>s;
        int L=0,LO=0,LOV=0,LOVE=0;
        for(int i=0;i<s.length();i++)
        {
            switch(s[i]){
                case 'L':
                    L++;
                    break;
                case 'O':
                    if(L)L--,LO++;
                    break;
                case 'V':
                    if(LO)LOV++,LO--;
                    break;
                case 'E':
                    if(LOV)LOVE++,LOV--;
                    break;
                default:
                    break;
            }
        }
        cout<<LOVE<<endl;
    }
    return 0;
}

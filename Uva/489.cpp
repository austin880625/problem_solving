#include<iostream>
#include<math.h>
#include<string>
using namespace std;

string guesser;
string com;
int chance,state,lef;

void guess(int c)
{
    int bad=1;
    for(int i=0;i<com.length();i++)
    {
        if(guesser[c]==com[i])
        {
            bad=0;
            com[i]=' ';
            lef--;
            if(lef==0){state=1;break;}
        }
    }
    if(bad)
    {
        chance--;
        if(chance==0)state=2;
    }
}

int main()
{
    int t;
    while(cin>>t)
    {
        if(t==-1)break;
        chance=7;
        state=0;
        cin>>com;
        cin>>guesser;
        lef=com.length();
        cout<<"Round "<<t<<endl;
        for(int i=0;i<guesser.length();i++)
        {
            guess(i);
            if(state)
            {
                if(state==1)cout<<"You win."<<endl;
                if(state==2)cout<<"You lose."<<endl;
                break;
            }
        }
        if(!state)cout<<"You chickened out."<<endl;
    }
}

#include <iostream>

using namespace std;

int ran()
{
    static unsigned x=2147483647;
    return x=x*3+1;//be a prime so that it won't repeat
}

int main()
{
    for(int i=0;i<1000;i++)
    {
        cout<<ran()<<endl;
    }
    return 0;
}

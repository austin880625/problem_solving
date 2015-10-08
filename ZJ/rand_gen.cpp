#include <stdio.h>
#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

int TestCase;

int maxt=20;
int maxn=1001;

/*int rand()
{
    static int x=20150537;
    return x=x*0xdefaced+1;
}*/
int mabs(int x)
{
    return x>0 ? x : -x;
}

int main()
{
    //cin>>TestCase;
    srand(time(NULL));
    int n,m;
    while(cin>>n>>m)
    {
        cout<<n<<" "<<m<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0&&j==0)||(i==n-1&&j==m-1))cout<<'.';
                else cout<<(rand()%4 ? '.' :'O');
            }
            cout<<endl;
        }
    }
    /*for(int tc=0;tc<TestCase;tc++)
    {
        int N=mabs(rand())%maxn;
        int T=mabs(rand())%maxt;
        printf("%d %d ",N,T);
        for(int i=0;i<T;i++)
        {
            printf("%d ",mabs(rand()%N));
        }
        cout<<endl;
    }*/
        
}

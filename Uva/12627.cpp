#include<iostream>
#include<string>
#include<math.h>
#define ll long long int
using namespace std;

long long int table[31]={1,3,9,27,81,243,729,2187,6561,19683,59049,177147,531441,1594323,4782969,14348907,43046721
    ,129140163,387420489,1162261467,3486784401,10460353203,31381059609,94143178827,282429536481,847288609443,2541865828329,7625597484987,22876792454961,68630377364883,205891132094649};

ll F(int K,int A,int B)
{
    //cout<<K<<" "<<A<<" "<<B<<endl;
    if(K==0)return 1;
    ll k=(1<<K)/2;
    if(A==1&&B==k*2)return table[K];
    if(B<=k)
        return 2*F(K-1,A,B);
    if(A>=k+1)
        return F(K-1,A-k,B-k);
    return 2*F(K-1,A,k)+F(K-1,1,B-k);
}

int main()
{
    int T;
    cin>>T;
    int kase=0;
    while(T--)
    {
        int K,A,B;
        cin>>K>>A>>B;
        cout<<"Case "<<++kase<<": ";
        cout<<F(K,A,B)<<endl;
    }
    
    return 0;
}

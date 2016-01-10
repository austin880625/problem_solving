#include<iostream>
#include<map>
#include<queue>

using namespace std;
map<int,int> m;
long long a,c[100100];

void add(long long q,long long x){
    while(q<0){q+=1000000007;}
    while(x<=100010){
        c[x]+=q;
        c[x]%=1000000007;
        x+=x&-x;
    }
}

long long  sum(long long  x){
    long long ans=0;
    while(x>0){
        ans+=c[x];
        ans%=1000000007;
        x-=x&-x;
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        m.clear();
        for(int i=0;i<100100;i++) c[i]=0;

        for(int i=1;i<=n;i++){
            cin>>a;
            if(!m.count(a)) add(sum(i-1)+1,i);
            else add(sum(i-1)-sum(m[a]-1),i);
            m[a]=i;

        }
//for(int i=1;i<=n;i++) cout<<sum(i)-sum(i-1);
        cout<<sum(n)<<endl;
    }

}

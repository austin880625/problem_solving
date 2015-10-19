#include<iostream>
#include<stack>
#include<vector>
#define INF 1000000005
#define ll long long int
using namespace std;
vector<int> C;
int n;
ll ans;

struct Stack
{
    int B[1000000],cnt[1000000],sz,rear;
    void clear(){sz=0;rear=-1;}
    int size(){return sz;}
    int top(){return B[rear];}
    void push(int v)
    {
        if(sz!=0&&top()==v)cnt[rear]++;
        else
        {
            B[++rear]=v;
            cnt[rear]=1;
        }
        sz++;
    }
    void pop()
    {
        sz-=cnt[rear--];
    }
    int kanbudaode(int v)
    {
        if(sz==0)return 0;  //到底啦
        if(v<top()) //top以前的全部看不到
            return size()-1;
        if(rear==0)return 0;    //高度相同的會一路看到底
        return size()-cnt[rear]-1;  //除了高度相同的，還看得到凸出來的一個
    }
};

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int c;
        scanf("%d",&c);
        C.push_back(c);
    }
    Stack S;
    S.clear();
    for(int i=0;i<n;i++)    //往左看
    {
        ans+=S.size();  //假設全部都看得到
        while(S.sz!=0&&C[i]>S.top())
        {
            //這裏從C[i]往左全部都看得到
            S.pop();
        }
        ans-=S.kanbudaode(C[i]);  //由top相同或不相同決定看不到的數量
        S.push(C[i]);
    }
    S.clear();
    for(int i=n-1;i>=0;i--)    //往右看
    {
        ans+=S.size();  //假設全部都看得到
        while(S.sz!=0&&C[i]>S.top())
        {
            //這裏從C[i]往右全部都看得到
            S.pop();
        }
        ans-=S.kanbudaode(C[i]);  //由top相同或不相同決定看不到的數量
        S.push(C[i]);
    }
    printf("%lld\n",ans);
}
#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

struct DEQ
{
    int fr,rr;
    int q[100005];
    void clear(){fr=0,rr=0;}
    DEQ(){clear();}
    void pushback(int v){q[rr++]=v;}
    void popback(){rr--;}
    void popfront(){fr++;}
    int back(){return q[rr-1];}
    int front(){return q[fr];}
    bool empty(){return rr<=fr;}
};
int N,M,K,ans;
DEQ Mx,Mn;  //候選最大值最小值
int s[100005];
int main()
{
    while(scanf("%d %d %d",&N,&M,&K)==3)
    {
        ans=0;
        Mx.clear();
        Mn.clear();
        for(int i=0;i<N;i++)
        {
            scanf("%d",&s[i]);
        }
        //Mx.pushback(0),Mn.pushback(0);
        int L=0;
        for(int i=0;i<N;i++)    //每次把i當作右邊界
        {
            while(!Mx.empty()&&s[i]>=s[Mx.back()]){Mx.popback();}   //以i為右邊界時，小於s[i]的必不會再成為候選解
            while(!Mn.empty()&&s[i]<=s[Mn.back()]){Mn.popback();}
            Mx.pushback(i),Mn.pushback(i);

            while(s[Mx.front()]-s[Mn.front()]>K)    //要找左邊界
            {
                //看看L是不是不能用的位置，是的話就pop，而且L之後不會再用到所以不用歸零
                if(!Mx.empty()&&Mx.front()==L)Mx.popfront();
                if(!Mn.empty()&&Mn.front()==L)Mn.popfront();
                //兩個不會同時成立
                L++;
            }
            //cout<<L<<endl;
            //cout<<Mx.front()<<" "<<Mn.front()<<endl;
            if(s[Mx.front()]-s[Mn.front()]>=M)ans=max(ans,i-L+1);
        }
        printf("%d\n",ans);
    }
}

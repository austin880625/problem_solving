#include <stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

int n,m;
int w[1005];
int boxes[55];

int iddfs(int toPut,int prevBox)
{
    if(toPut==0)return 1;
    int start=0;
    if(w[toPut]==w[toPut+1]&&prevBox>=0)start=prevBox;  //w[toPut+1]>=w[toPut],w[toPut+1]放得進去的prevBox,w[toPut]至少要到prevBox才放得進去
    for(int i=start;i<m;i++)    //嘗試放各個箱子
    {
        //cout<<"got it "<<toPut<<endl;
        if(w[toPut]<=boxes[i])   //放得進去
        {
            boxes[i]-=w[toPut];
            int res=iddfs(toPut-1,i);
            boxes[i]+=w[toPut];
            if(res)return 1;    //都放進去才return,失敗就輪下一個
        }
    }
    return 0;   //都失敗
    
}

int main()
{
        scanf("%d",&m);
        scanf("%d",&n);
        int boxsum=0;
        for(int i=0;i<m;i++){scanf("%d",&boxes[i]);boxsum+=boxes[i];}
        for(int i=1;i<=n;i++)scanf("%d",&w[i]);
        sort(w+1,w+1+n);
        int depth,sum2=0;
        for(depth=1;depth<=n;depth++)
        {
            sum2+=w[depth];
            if(sum2>boxsum)break;
            int ans=iddfs(depth,-1);
            if(!ans)break;  //測試前i小的物品能不能放入，從大的開始放
        }
        printf("%d\n",depth-1);
}
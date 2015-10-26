#include <iostream>
 #include <cstdio>
 #include <cstring>
 using namespace std;

 const int MAX=1000005;
 int a[MAX],n,m;
 int Q[MAX],head,tail;

 void deal1()
 {
     head=tail=0;
     int i;
     for(i=1;i<=n;i++)
     {
         while(head<tail&&a[i]<=a[Q[tail-1]]) tail--;
         Q[tail++]=i;
         if(i>=m)
         {
             while(head<tail&&Q[head]<=i-m) head++;
             printf("%d ",a[Q[head]]);
         }
     }
     puts("");
 }

 void deal2()
 {
     head=tail=0;
     int i;
     for(i=1;i<=n;i++)
     {
         while(head<tail&&a[i]>=a[Q[tail-1]]) tail--;
         Q[tail++]=i;
         if(i>=m)
         {
             while(head<tail&&Q[head]<=i-m) head++;
             printf("%d ",a[Q[head]]);
         }
     }
     puts("");
     //printf("min");
 }

 int main()
 {
     while(scanf("%d%d",&n,&m)!=-1)
     {
         int i;
         for(i=1;i<=n;i++) scanf("%d",&a[i]);
         deal1();
         deal2();
     }
     return 0;
 }

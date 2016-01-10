#include <iostream>
#include <stdio.h>
#include <assert.h>
#include <vector>
#include <string.h>
#define MOD 100000
using namespace std;

struct bigint
{
    vector<int> B;
    bigint(char *s)
    {
        int l=strlen(s);
        for(int i=l-1;i>=0;i++)
        {
            B.push_back(s[i]-'0');
        }
    }
};
bigint N,D;
char num[105];
int e;
int t;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",num);
    }
}

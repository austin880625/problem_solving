#include<iostream>
#include<algorithm>

using namespace std;

const int MAX_M=15;
const int MAX_N=105;
const int INF=2147483646;

int mat[MAX_M][MAX_N];  //it may be less than 0
long long int d[MAX_M][MAX_N];
int ans[MAX_M][MAX_N];
long long int ans1;
int row[3];
int m,n;

void conv()
{
    if(row[0]<0)row[0]=m-1;
    if(row[2]==m)row[2]=0;
}

int main()
{
    while(cin>>m>>n)
    {
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>mat[i][j];
                d[i][j]=0;
                if(j==n-1)d[i][j]=mat[i][j];
            }
        }
        for(int i=n-2;i>=0;i--)
        {
            for(int j=0;j<m;j++)
            {
                row[0]=j-1;
                row[1]=j;
                row[2]=j+1;
                conv();
                sort(row,row+3);
                int v=INF;
                int s=0;
                for(int k=0;k<3;k++)
                {
                    int t=d[row[k]][i+1]+mat[j][i];
                    if(t<v||v==INF){v=t;s=row[k];}
                }
                d[j][i]=v;
                ans[j][i]=s;
                //cout<<s<<" ";
            }
            //cout<<endl;
        }
        ans1=INF;
        int first=0;
        for(int i=0;i<m;i++)
        {
            if(d[i][0]<ans1||ans1==INF)
            {
                ans1=d[i][0];
                first=i;
            }
        }

        cout<<first+1;
        int t=first;
        for(int i=0;i<n-1;i++){cout<<" "<<ans[t][i]+1;if(i!=n-2)t=ans[t][i];}
        cout<<endl<<ans1<<endl;
    }
}

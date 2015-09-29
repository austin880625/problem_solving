#include<iostream>
#include<string>
using namespace std;
char cubes[15],cube[7];
int mapping[6][6]={
    {5,4,2,3,1,0},
    {4,0,2,3,5,1},
    {3,1,0,5,4,2},
    {2,1,5,0,4,3},
    {1,5,2,3,0,4},
    {0,1,2,3,4,5}
};

void rotate(int c)
{
    for(int i=0;i<6;i++)cube[i]=cubes[mapping[c][i]];
}

void rotate()
{
    char cubet[4]={cube[1],cube[2],cube[3],cube[4]};
    cube[1]=cubet[1];
    cube[2]=cubet[3];
    cube[3]=cubet[0];
    cube[4]=cubet[2];
}

int isSame()
{
    int res=1;
    for(int i=0;i<6;i++)res=res&&(cube[i]==cubes[6+i]);
    return res;
}

int main()
{
    while(cin>>cubes)
    {
        int ans=0;
        for(int i=0;i<6;i++)
        {
            rotate(i);
            for(int j=0;j<4;j++)
            {
                rotate();
                ans=ans||isSame();
            }
        }
        cout<<(ans ? "TRUE" : "FALSE")<<endl;
    }
    return 0;
}

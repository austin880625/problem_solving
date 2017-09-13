#include <stdio.h>
#include <iostream>

using namespace std;

int w,h;
int cnt[105][105][4];
char b[105][105];
int dr[4]={-1,0,1,0};
int dc[4]={0,1,0,-1};

void GO(int r,int c){
    int cd=0;
    //cout<<r<<" "<<c<<endl;
    if(b[r][c]=='U')cd=0;
    else if(b[r][c]=='R')cd=1;
    else if(b[r][c]=='D')cd=2;
    else if(b[r][c]=='L')cd=3;
    cnt[r][c][cd]++;
    while(cnt[r][c][cd]<=4){
        //cout<<r<<" "<<c<<" "<<cd<<endl;
        int nr=r+dr[cd],nc=c+dc[cd];
        int tried=0;
        while(nr<0||nr>=h||nc<0||nc>=w||b[nr][nc]=='*'){
            cd++,cd%=4,nr=r+dr[cd],nc=c+dc[cd];
            tried++;
            if(tried>4){nr=r,nc=c;break;}
        }
        cnt[nr][nc][cd]++,r=nr,c=nc;
    }
}

int main(){
    while(scanf("%d%d",&h,&w)==2){
        for(int i=0;i<h;i++)for(int j=0;j<w;j++)for(int k=0;k<4;k++)cnt[i][j][k]=0;
        for(int r=0;r<h;r++){
            scanf("%s",b[r]);
        }
        for(int r=0;r<h;r++){
            for(int c=0;c<w;c++)if(b[r][c]!='.'&&b[r][c]!='*')GO(r,c);
        }
        int ans=0;
        /*for(int r=0;r<h;r++){
            for(int c=0;c<w;c++)cout<<cnt[r][c]<<" ";
            cout<<endl;
        }*/
        for(int r=0;r<h;r++){
            for(int c=0;c<w;c++){
                for(int i=0;i<4;i++)if(cnt[r][c][i]){ans++;break;}
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

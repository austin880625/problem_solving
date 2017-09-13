#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string.h>
#include <map>

#define MAXN 1005
#define LL long long int
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define pii pair<int,int>
#define mi map<int,int>::iterator

using namespace std;

map<int,int> S;
int N,M;

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        S.clear();
        scanf("%d%d",&M,&N);
        for(int i=0,l,r,op;i<N;i++){
            scanf("%d",&op);
            if(op==1){
                scanf("%d%d",&l,&r);
                int mid=(l+r)>>1,h=mid-l;
                mi it=S.find(mid);
                if(it==S.end()||(it!=S.end()&&it->second<h)){
                    //cout<<"inserting"<<endl;
                    if(it!=S.end())S.erase(it);
                    int x=1;
                    it=S.upper_bound(mid);
                    //cout<<"checking"<<(it==S.end())<<endl;
                    if(it==S.end()){
                        if(it==S.begin())x=1;
                        else{
                            it--;
                            int lp=it->first,lh=it->second;
                            x=x&&(lh-(mid-lp)<h);
                        }
                    }
                    else{
                        int rp=it->first,rh=it->second;
                        x=x&&(rh-(rp-mid)<h);
                        if(it!=S.begin()){
                            it--;
                            int lp=it->first,lh=it->second;
                            x=x&&(lh-(mid-lp)<h);
                        }
                    }
                    //cout<<"checked"<<endl;
                    if(x){
                        S[mid]=h;
                        it=S.upper_bound(mid);
                        while(it!=S.end()){
                            if(h-(it->first-mid)>it->second)S.erase(it++);
                            else it++;
                        }
                        it=S.lower_bound(mid);
                        if(it!=S.begin()){
                            it--;
                            while(1){
                                //cout<<h<<endl;
                                int f=0;
                                if(it==S.begin())f=1;
                                if(h-(mid-it->first)>it->second)S.erase(it--);
                                else it--;
                                if(f)break;
                            }
                        }
                        //cout<<"inserted"<<endl;
                    }
                }
            }
            else{
                scanf("%d",&l);
                mi it=S.lower_bound(l);
                int h=0;
                if(it!=S.end()){
                    h=max(h,it->second-(it->first-l));
                }
                if(it!=S.begin()){
                    it--;
                    h=max(h,it->second-(l-it->first));
                }

                LL x=1,mm=M;
                while(h){
                    if(h&1)x=(x*mm)%MOD;
                    mm=(mm*mm)%MOD;
                    h>>=1;
                }
                printf("%lld\n",x);
            }
        }
    }
    return 0;
}

/*
1
3 9
2 7
1 3 9
2 7
1 9 13
2 9
2 10
1 4 12
2 7
2 11
*/

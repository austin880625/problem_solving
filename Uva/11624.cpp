#include<iostream>
#include<queue>
using namespace std;

char maps[1005][1005];
int ans[1005][1005];
int A[4000];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
struct point{
	int x,y;
};

int main(){
	int T;
	cin>>T;
	while(T--){
		int R,C;
		cin>>R>>C;
		for(int r=0;r<R;r++){
			cin>>maps[r];
			for(int c=0;c<C;c++)ans[r][c]=-1;
		}
		for(int i=0;i<4000;i++)A[i]=1000000;
		int possible=0;
		queue<point> moves;
		queue<point> spread;
		int step=0;
		int sp=0;
		int fn=0;
		int mv=0;
		int mn=0;
		
		for(int r=0;r<R;r++){
			for(int c=0;c<C;c++){
				if(maps[r][c]=='J'){point Joe;Joe.x=c;Joe.y=r;moves.push(Joe);ans[r][c]=step;step++;mv++;}
				if(maps[r][c]=='F'){point Fire;Fire.x=c;Fire.y=r;spread.push(Fire);sp++;}
			}
		}
		int t=0;
		int ls=mv;
		while(!moves.empty()){
		int laststep=sp;
		while(fn<laststep&&!spread.empty()){
		for(int i=0;i<4;i++){
			point sn;
			sn.x=spread.front().x+dx[i];
			sn.y=spread.front().y+dy[i];
			if(sn.x<C&&sn.x>=0&&sn.y<R&&sn.y>=0&&maps[sn.y][sn.x]!='#'&&maps[sn.y][sn.x]!='F'){
				maps[sn.y][sn.x]='F';
				spread.push(sn);
				//fn++;
				sp++;
			}
			
		}
		fn++;
		spread.pop();
		}
		//fn=0;
		while(mn<ls){
		for(int i=0;i<4;i++){
			point Next;
			int nx,ny;
			Next.x=nx=moves.front().x+dx[i];
			Next.y=ny=moves.front().y+dy[i];
			//cout<<nx<<" "<<ny<<endl;
			if(nx<0||nx>=C||ny<0||ny>=R){A[t]=ans[moves.front().y][moves.front().x]+1;t++;possible=1;}
			else if(ans[ny][nx]==-1&&maps[ny][nx]=='.'){ans[ny][nx]=step;moves.push(Next);mv++;}
		}
		mn++;
		//step++;
		moves.pop();
		}
		step++;
		ls=mv;
	//	for(int i=0;i<R;i++){
	//	for(int j=0;j<C;j++)
	//	 cout<<ans[i][j];
	//	 cout<<endl;
	//	 }
		if(possible)break;
		}
		if(possible==0)cout<<"IMPOSSIBLE"<<endl;
		else{
			int min=A[0];
			for(int i=0;i<t;i++){if(min>A[i])min=A[i];}
			cout<<min<<endl;
		}
	}
	return 0;
}

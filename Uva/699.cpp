#include<iostream>
#include<vector>
using namespace std;

//const int MAX_N=500;

struct Node{
	int L,R,V,x,y;
};
vector<Node> tree;

int sum[1999];
//int sumtable[1000][1000];

void addNode(int v){
	if(tree.size()){
		int t=tree.size()-1;
		int s=tree.size();
		Node p=tree[t];
		Node newNode;
		newNode.L=0;
		newNode.R=0;
		newNode.V=v;
		while((p.L!=0&&p.R!=0)||p.V==-1){
			p=tree[--t];
		}
		if(p.L==0){
			tree[t].L=s;
			newNode.x=p.x+1;
			newNode.y=p.y;
			if(v!=-1){
//				sumtable[tree[t].x+1][tree[t].y]+=v;
				sum[p.y-p.x-1+999]+=v;
			}
		}else if(p.R==0){
			tree[t].R=s;
			newNode.x=p.x;
			newNode.y=p.y+1;
			if(v!=-1){
//				sumtable[tree[t].x][tree[t].y+1]+=v;
				sum[p.y+1-p.x+999]+=v;
			}
		}

		tree.push_back(newNode);
	}else {
//		sumtable[0][0]+=v;
		sum[999]+=v;
		Node n;
		n.L=0;
		n.R=0;
		n.x=0;
		n.y=0;
		n.V=v;
		tree.push_back(n);
	}
}
/*
void sum(int n,int x,int y){
	sumtable[x][y]+=tree[n].V;
	if(tree[n].R!=0&&tree[tree[n].R].V!=-1)sum(tree[n].R,x,y+1);
	if(tree[n].L!=0&&tree[tree[n].L].V!=-1)sum(tree[n].L,x+1,y);
}
*/
int main(){
	int cases=1;
	int root;
	while(cin>>root){
		if(root==-1)break;
//		for(int i=0;i<1000;i++){
//			for(int j=0;j<1000;j++)sumtable[i][j]=0;
//		}
		tree.clear();
		int cntn=0,cntp=1;
		for(int i=0;i<1999;i++)sum[i]=0;
		int n;
		addNode(root);
		while(cin>>n){
			addNode(n);

			if(n>0)cntp++;
			else cntn++;
			if(cntn==cntp+1)break;
		}
//		sum(0,0,0);
//		int sum[1999]={0};
		int t=0;
/*
		for(int i=0;i<10;i++){
			for(int j=0;j<10;j++){
				cout<<sumtable[i][j]<<"\t";
			}
			cout<<endl;
		}

		for(int i=999;i>=0;i--){
			for(int j=0;j<1000-i;j++){
				sum[t]+=sumtable[j+i][j];
			}
			t++;
		}
		for(int i=1;i<1000;i++){
			for(int j=0;j<1000-i;j++){
				sum[t]+=sumtable[j][j+i];
			}
			t++;
		}
*/
		t=0;
		//for(int i=0;i<1999;i+=5)cout<<sum[i]<<" "<<sum[i+1]<<" "<<sum[i+2]<<" "<<sum[i+3]<<" "<<sum[i+4]<<endl;
		while(sum[t]==0)t++;
		cout<<"Case "<<cases++<<":\n"<<sum[t++];
		while(sum[t]!=0)cout<<" "<<sum[t++];
		cout<<endl<<endl;
	}
	return 0;
}

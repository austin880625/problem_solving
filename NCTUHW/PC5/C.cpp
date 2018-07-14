#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int T, n, m;
struct edge
{
	int u, v;
	edge(int _u, int _v){u = _u; v = _v;}
};
vector<edge> E;

int dj[100005];
int ans[100005];
int find(int x){return x == dj[x] ? x : dj[x] = find(dj[x]);}
void merge(int u, int v)
{
	int x = find(u);
	int y = find(v);
	dj[y] = x;
}

int main()
{
	scanf("%d", &T);
	for(int kase=1; kase<=T; kase++)
	{
		E.clear();
		int n0, m0;
		scanf("%d%d", &n0, &m0);
		n = 2*n0;
		for(int i=0; i<n; i++)dj[i] = i ;
		for(int i=0; i<m0; i++)
		{
			int op0, op1;
			char opr[10];
			cin >> op0 >> opr >> op1;
			op0--, op1--;
			if(opr[0] == '+' || opr[0] == '-')
			{
				/*
				G[2*op0+1].push_back(2*op1);
				G[2*op1+1].push_back(2*op0);
				G[2*op0].push_back(2*op1+1);
				G[2*op1].push_back(2*op0+1);
				*/
				E.push_back(edge(2*op0+1, 2*op1));
				E.push_back(edge(2*op1+1, 2*op0));
			}
			else if(opr[0] == '*')
			{
				ans[2*op0] = 1;
				ans[2*op1] = 1;
			}
			else
			{
				ans[2*op0] = 1;
			}
		}
		for(int i=0; i<E.size(); i++)
		{
			merge(E[i].u, E[i].v);
		}
		for(int i=0; i<n; i++)cout << dj[i] << " ";
		puts("");
		int anss = 1;
		for(int i=0; i<n0; i++)
		{
			cout << find(2*i) << " " << find(2*i+1) << endl;
			if(find(2*i) == find(2*i+1))cout<<i<<endl,anss = 0;
		}
		if(anss)puts("Yes");
		else puts("No");
	}
	return 0;
}

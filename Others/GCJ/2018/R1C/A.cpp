#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>

using namespace std;

int N,L;
char tab[2005][15];
struct Node{
	int cnt;
	Node *ch[26];
	Node(){cnt=0; for(int i=0; i<26;i++)ch[i]=NULL;}
} *root;

void insert(char *s){
	if(!root)root = new Node();
	Node *now = root;
	for(int i=0; s[i]; i++){
		now->cnt++;
		if(!(now->ch[s[i]-'A'])){
			now->ch[s[i]-'A'] = new Node();
		}
		now = now->ch[s[i]-'A'];
	}
	now->cnt++;
}

int g[26][26];
int s[26][15];

int main()
{
	int T;
	scanf("%d", &T);
	for(int kase=1; kase<=T; kase++){
		root = NULL;
		scanf("%d%d", &N, &L);
		for(int i=0; i<26; i++)for(int j=0; j<L; j++)s[i][j] = 0;
		for(int i=0; i<N; i++){
			scanf("%s", tab[i]);
			for(int j=0; j<L; j++)s[tab[i][j]-'A'][j] = 1;
		//	insert(tab[i]);
		}
		printf("Case #%d: ", kase);
		int f=0;
		char l,m,r;
		for(int i=0; i<L-1; i++){
			for(int i=0; i<26; i++){for(int j=0; j<26; j++)g[i][j] = 0;}
			for(int j=0; j<N; j++){
				//cout << tab[j][i] << " " << tab[j][i+1] <<endl;
				g[tab[j][i]-'A'][tab[j][i+1]-'A'] = 1;
			}
			for(int j=0; j<26; j++){
				for(int k=0; k<26; k++){
					if(s[j][i]&&s[k][i+1]&&g[j][k]==0){
						l=j+'A', r=k+'A';
					//	cout << l << " " << r <<endl;
						f=i+1;
						break;
					}
				}
				if(f)break;
			}
			if(f)break;
		}
		int ls=-1, rs=-1;
		if(!f)puts("-");
		else{
			for(int i=0; i<N; i++){
				if(tab[i][f-1] == l){
					ls=i;
					l=0; continue;
				}
				if(tab[i][f+1] == r){
					rs=i;
					r=0; continue;
				}
			}
			for(int j=0; j<f; j++)printf("%c", tab[ls][j]);
			printf("%c", m);
			for(int j=f; j<L; j++)printf("%c", tab[rs][j]);
			puts("");
		}
	}
	return 0;
}

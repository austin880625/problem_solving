#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long int ll;
#define pll pair<ll,ll>
#define MAXN 100005
struct pile{
	ll x, s;
	int i;
	pile(){x=s=0; i=0;}
	pile(ll _x){x=_x; s=i=0;}
	bool operator <(const pile &r)const{
		return x<r.x;
	}
};
vector<pile> b;

struct Node{
	vector<int> maxpos;
	Node *ch[2];
} nodes[MAXN*8], *root;
int nc;
Node *newNode(){
	nodes[nc].maxpos.clear();
	nodes[nc].ch[0] = nodes[nc].ch[1] = NULL;
	return nodes+(nc++);
}

void build(Node *&o, int l, int r){
	if(!o)o = newNode();
	if(l == r){o->maxpos.push_back(l); return;}
	int mid = (l+r)>>1;
	build(o->ch[0], l, mid);
	build(o->ch[1], mid+1, r);
	o->maxpos.clear();
	vector<int> &ch0 = o->ch[0]->maxpos, &ch1 = o->ch[1]->maxpos;
	if(b[ch0[0]].s == b[ch1[0]].s){
		for(int i=0; i<ch0.size(); i++)o->maxpos.push_back(ch0[i]);
		for(int i=0; i<ch1.size(); i++)o->maxpos.push_back(ch1[i]);
	}
	else if(b[ch0[0]].s > b[ch1[0]].s)
		for(int i=0; i<ch0.size(); i++)o->maxpos.push_back(ch0[i]);
	else
		for(int i=0; i<ch1.size(); i++)o->maxpos.push_back(ch1[i]);
}
int L, R;
vector<int> res;
int P;

void qm(Node *&o, int l, int r){
	if(L<=l && r<=R){
		if(b[o->maxpos[0]].s == 0)return ;
		//cout << "inter: " << l <<" "<<r<<endl;
		//for(int v:o->maxpos)cout<<" "<<v; cout<<endl;
		if(res.size() == 0 || b[o->maxpos[0]].s >= b[res[0]].s){
			if(res.size()&&b[o->maxpos[0]].s!=b[res[0]].s)res.clear();
			for(int v:o->maxpos){res.push_back(v);}
		}
		return ;
	}
	int mid = (l+r)>>1;
	if(L<=mid)qm(o->ch[0], l, mid);
	if(R>mid)qm(o->ch[1], mid+1, r);
}

void modify(Node *&o, int l, int r)
{
	if(l==r){b[l].s = 0;return ;}
	int mid = (l+r)>>1;
	if(P<=mid)modify(o->ch[0], l, mid);
	else modify(o->ch[1], mid+1, r);
	o->maxpos.clear();
	vector<int> &ch0 = o->ch[0]->maxpos, &ch1 = o->ch[1]->maxpos;
	if(b[ch0[0]].s == b[ch1[0]].s){
		for(int i=0; i<ch0.size(); i++)o->maxpos.push_back(ch0[i]);
		for(int i=0; i<ch1.size(); i++)o->maxpos.push_back(ch1[i]);
	}
	else if(b[ch0[0]].s > b[ch1[0]].s)
		for(int i=0; i<ch0.size(); i++)o->maxpos.push_back(ch0[i]);
	else
		for(int i=0; i<ch1.size(); i++)o->maxpos.push_back(ch1[i]);
}

int main()
{
	int T;
	int n,m;
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &n, &m);
		b.clear();
		nc=0;
		root = NULL;
		b.push_back(pile(-1LL));
		for(int i=1; i<=n; i++){
			b.push_back(pile());
			scanf("%lld%lld", &b[i].x, &b[i].s);
		}
		b.push_back(pile(1000000007));
		sort(b.begin(), b.end());
		for(int i=0; i<=n+1; i++){
			b[i].i = i;
		}
		//for(int i=0; i<=n+1; i++){
		//	cout<<i<<" "<<b[i].x<<" "<<b[i].s<<endl;
		//}
		build(root, 0, n+1); //cout << endl;
		ll last = 0;
		for(int i=0; i<m; i++){
			long long int p, q;
			scanf("%lld%lld", &p, &q);
			p^=last; q^=last;
			//cout<<"query; "<<p<<" "<<q<<endl;
			vector<pile>::iterator lit = lower_bound(b.begin(), b.end(), pile(p));
			vector<pile>::iterator rit = upper_bound(b.begin(), b.end(), pile(q)); rit--;
			L = lit->i, R = rit->i;
			//cout<<"LR: "<<L << " "<<R<<endl;
			qm(root, 0, n+1);
			//for(int v:res)cout<<v<<" ";cout<<endl;
			last = (long long int)res.size()*(res.size() ? b[res[0]].s : 0);
			printf("%lld\n", last);
			for(unsigned long i=0; i<res.size(); i++){
				P = res[i];
				modify(root, 0, n+1);
			}
			res.clear();
		}
	}
	return 0;
}

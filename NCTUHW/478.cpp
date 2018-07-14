#include <stdio.h>
#include <iostream>

using namespace std;
typedef long long int ll;
int n;
ll A[100005];
int ran(){ static int x = 7122; return x=x*0xdefaced+1; }
struct Node{
	ll v,cnt,num,sum;
	int pri;
	struct Node *ch[2];
	Node(ll _v, ll c):v(_v),cnt(c),num(c),sum(c*_v),pri(ran()){ ch[0] = ch[1] = NULL; }
};

void pull(Node *o)
{
	if(!o)return ;
	o->num = o->cnt;
	o->sum = o->v * o->cnt;
	if(o->ch[0]){ o->num += o->ch[0]->num; o->sum += o->ch[0]->sum; }
	if(o->ch[1]){ o->num += o->ch[1]->num; o->sum += o->ch[1]->sum; }
}

Node *merge(Node *a, Node *b){
	if(!a || !b) return a ? a : b;
	Node *res;
	if(a->pri > b->pri){
		res = a;
		res->ch[1] = merge(a->ch[1], b);
	}
	else{
		res = b;
		res->ch[0] = merge(a, b->ch[0]);
	}
	pull(res);
	return res;
}

void split(Node *o, int v, Node **a, Node **b)
{
	if(!o){ *a = *b = NULL; return ; }
	if(v < o->v){
		*b=o;
		split(o->ch[0], v, a, &((*b)->ch[0]));
		pull(*b);
	}
	else{
		*a=o;
		split(o->ch[1], v, &((*a)->ch[1]), b);
		pull(*a);
	}
}

void insert(Node **o, ll v, ll c)
{
	Node *a, *b;
	if( !c ) return ;
	if( !(*o) ) { *o = new Node(v,c); return ; }
	split(*o, v, &a, &b);
	Node *q, *p;
	split(a, v-1, &q, &p);
	if( !p ) p = new Node(v, c);
	else {
		p->cnt+=c;
		p->num+=c;
		p->sum+=c*v;
	}
	*o = merge(merge(q, p), b);
}

void remove(Node **o, ll v)
{
	Node *a, *b;
	if( !(*o) ) return ;
	split(*o, v, &a, &b);
	Node *q, *p;
	split(a, v-1, &q, &p);
	if( !p ) { return ; }
	p->cnt--;
	p->num--;
	p->sum-=v;
	if(!p->cnt){ delete p; *o = merge(q, b); }
	else { *o = merge(merge(q, p), b); }
}

Node *rt = NULL;
int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		rt = NULL;
		scanf("%d",&n);
		for(int i=0; i<n; i++){
			scanf("%lld", A+i);
			insert(&rt, A[i], 1);
		}
		ll res = 0;
		ll a = 2147483647;
		for(int i=n-1; i>=0; i--){
			Node *l, *r;
			a = min(A[i], a);
			remove(&rt, a);
			split(rt, a, &l, &r);
			if(r){
				res += a*(r->sum - a*r->num);
			}
			insert(&l, a, r ? r->num : 0);
			rt = l;
		}
		printf("%lld\n", res);
	}
	return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int MAXN = 50005;
unsigned int ran(){ static unsigned int x = 7122; return x = x*0xdefaced+1; }
typedef struct Node
{
	char c;
	int sz;
	struct Node *ch[2];
} Node;

Node *newNode(char c)
{
	Node *p = (Node*)malloc(sizeof(Node));
	p->c = c;
	p->sz = 1;
	p->ch[0] = p->ch[1] = NULL;
	return p;
}
Node *copy(Node *o){
	Node *p = (Node*)malloc(sizeof(Node));
	p->c = o->c;
	p->sz = 1;
	p->ch[0] = o->ch[0]; p->ch[1] = o->ch[1];
	return p;
}

int getSz(Node *o){ return o ? o->sz : 0; }
void pull(Node *o){
	o->sz = 1;
	if(o->ch[0])o->sz += o->ch[0]->sz;
	if(o->ch[1])o->sz += o->ch[1]->sz;
}
int cmpNode(Node *a, Node *b){
	unsigned int all = getSz(a) + getSz(b);
	return ran()%all < (unsigned int)getSz(a);
}

void split(Node *o, int k, Node **a, Node **b)
{
	if(!o) return ;
	if( 1 + getSz(o->ch[0]) <= k ){
		*b = copy(o);
		split( o->ch[0], k, a, &((*b)->ch[0]) );
		pull(*b);
	}
	else{
		*a = copy(o);
		split( o->ch[1], k-getSz(o)-1, &((*a)->ch[1]), b );
		pull(*a);
	}
}
Node *merge(Node *a, Node *b){
	if(!a || !b) return a ? a : b;
	if(cmpNode(a, b)){
		Node *o = copy(a);
		o->ch[1] = merge(o->ch[1], b);
		return o;
	}
	else{
		Node *o = copy(b);
		o->ch[0] = merge(a, o->ch[0]);
		return o;
	}
}
Node *build(char *s){
	Node *o = newNode(s[0]);
	for(int i=1; s[i]; i++){
	}
}

Node *insert(Node *o, int p, char *s)
{
	Node *l, *r;
	split(o, p, &l, &r);
}

int main()
{
	int n;
	scanf("%d", &n);
	char *s = (char*)malloc(105*sizeof(char));
	Node *rt = (Node*)malloc(MAXN*sizeof(Node*));
	int v = 0;
	for(int q=0; q<n; q++){
		int com;
		scanf("%d", &com);
		int p, c;
		if(com == 1){
			scanf("%d %s", &p, s);
			rt[v+1] = insert(rt[v], p, s);
			v++;
		}
	}
	free(s);
	free(rt);
	return 0;
}

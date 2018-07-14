#include <stdio.h>
#include <stdlib.h>
#define M_TYPE int

typedef struct Node
{
	M_TYPE v;
	int s;
	struct Node *ch[2];
} Node;
void initNode(Node *o, M_TYPE v)
{
	o->v = v;
	o->s = 1;
	o->ch[0] = o->ch[1] = NULL;
}
Node *merge(Node *a, Node *b)
{
	if(!a||!b){
		return a ? a : b;
	}
	Node *o = a->v < b->v ? a : b;
	Node *p = o == a ? b : a;
	o->ch[1] = merge(o->ch[1], p);
	if(!o->ch[0]){
		o->ch[0] = o->ch[1];
		o->ch[1] = NULL;
		return o;
	}
	if(o->ch[0]->s < o->ch[1]->s){
		Node *t = o->ch[0];
		o->ch[0] = o->ch[1];
		o->ch[1] = t;
	}
	o->s = 1+o->ch[1]->s;
	return o;
}
void insert(Node **o, M_TYPE v)
{
	Node *p = (Node*)malloc(sizeof(Node));
	initNode(p, v);
	*o = merge(*o, p);
}
void extract(Node **o){
	if(*o == NULL)return ;
	Node *p = *o;
	*o = merge((*o)->ch[0], (*o)->ch[1]);
	free(p);
}
static inline M_TYPE *top(Node *o)
{
	return o ? &o->v : NULL;
}
#define MAXN 100005
Node *heap[MAXN];
#undef MAXN
int main()
{
	int n,m;
	scanf("%d %d", &n, &m);
	for(int i=0; i<=n; i++){
		heap[i] = NULL;
	}
	while(m--){
		char com[10];
		scanf("%s", com);
		int i,j,x;
		if(com[0] == 'i'){
			scanf("%d %d", &i, &x);
			insert(heap+i, x);
		}
		else if(com[0] == 'j'){
			scanf("%d %d", &i, &j);
			heap[i] = merge(heap[i], heap[j]);
			heap[j] = NULL;
		}
		else if(com[0] == 'e'){
			scanf("%d", &i);
			M_TYPE *r = top(heap[i]);
			if(r == NULL)puts("NULL");
			else printf("%d\n", *r);
			extract(heap+i);
		}
		else if(com[0] == 'l'){
			scanf("%d", &i);
			M_TYPE *r = top(heap[i]);
			if(r == NULL)puts("NULL");
			else printf("%d\n", *r);
		}
	}
	return 0;
}

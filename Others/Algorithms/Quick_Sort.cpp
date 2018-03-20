#include <stdio.h>
#include <iostream>

template<class T>
void swap(T &a, T &b){
    if(a<b || b<a){
        a^=b^=a^=b;
    }
}
template<class T>
void quick_sort(T *s, T *e, unsigned int n)
{
    if(n<=1)return ;

    unsigned p=n/2;
    p = s[p] < s[0] ? (s[p] < s[n-1] ? n-1 : p) : (s[0] < s[n-1] ? n-1 : 0);
    unsigned int t=n-1;
    swap(s[p], s[n-1]);
    T *pivot = s+n-1;
    for(T *i=s; i!=pivot; i++){
        if(*pivot < *i){
            swap(*(pivot-1),*pivot);
            if(pivot!=i+1)swap(*pivot,*i);
            pivot--;i--;t--;
        }
    }
    quick_sort(s, pivot, t);
    quick_sort(pivot+1, e, n-t-1);
}
template<class T>
void sort(T *s, T *e){
	int n=0;
	for(T *t=s; t!=e; t++)n++;
	quick_sort(s,e,n);
}

int N;
int A[1000005];

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++)scanf("%d", A+i);
    sort(A, A+N);
    for(int i=0; i<N; i++)printf("%d ", A[i]);
    puts("");
}

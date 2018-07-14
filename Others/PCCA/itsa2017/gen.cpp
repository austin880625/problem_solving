#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
	srand(7122);
	int n=100;
	printf("%d\n", n);
	for(int i=0; i<n; i++){
		printf("9\n");
		for(int j=0; j<9;j++){
			printf("%d %d\n", 1, rand()%1000+1);
		}
	}
	return 0;
}

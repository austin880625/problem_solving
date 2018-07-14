#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

double A[2], B[2];

int main()
{
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%lf %lf %lf %lf", A, A+1, B, B+1);
		double ans = 1e23;
		for(int k=0; k<100000; k++){
		double lA = A[0]*A[0] + A[1]*A[1];
		double lB = B[0]*B[0] + B[1]*B[1];
		if(lA < lB) {swap(lA, lB); swap(A[0], B[0]); swap(A[1], B[1]);}
		double ip = A[0]*B[0] + A[1]*B[1];
		A[0] -= B[0]*floor(ip/lB + 0.5);
		A[1] -= B[1]*floor(ip/lB + 0.5);
		//cout << A[0] << "," << A[1] << " " << B[0] << "," << B[1] << endl;
		for(int i=-2; i<=2; i++){
			for(int j=-2; j<=2; j++){
				if(i == 0 && j == 0)continue;
				double l = (A[0]*i - B[0]*j)*(A[0]*i - B[0]*j) + (A[1]*i - B[1]*j)*(A[1]*i - B[1]*j);
				ans = min(ans, l);
			}
		}
		}
		printf("%.2lf\n", sqrt(ans));
	}
	return 0;
}

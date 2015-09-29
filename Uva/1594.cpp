#include<stdio.h>


int abs(int x){return x>0 ? x : -x;}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int l;
		scanf("%d",&l);
		int ducci[l];
		int e=1;
		int i=0;
		for(i=0;i<l;i++){scanf("%d",&ducci[i]);if(ducci[i]-ducci[0])e=0;}
		if(l==4||l==8)printf("ZERO\n");
		else if(l%2){
			if(e)printf("ZERO\n");else printf("LOOP\n");
		}else{
			for(i=0;i<3;i++){
				int tmp,j=0;
				for(j=0;j<l-1;j++){
					int tmp=ducci[0];
					ducci[j]=abs(ducci[j]-ducci[j+1]);
				}
				ducci[l-1]=abs(ducci[l-1]-tmp);
			}
			int res=0;
			for(i=0;i<l;i++){
				res=res||ducci[i];
			}
			if(res)printf("LOOP\n");else printf("ZERO\n");
		}
	}
	return 0;
}


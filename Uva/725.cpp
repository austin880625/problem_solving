#include<iostream>

using namespace std;
int main(){
	int N,c=0;
	while(cin>>N){
		int used[10]={0};
		if(!N)break;
		if(c)cout<<endl;
		c++;
		int ex=0;
		for(int f=0;f<=9;f++){
			used[f]=1;
			for(int g=0;g<=9;g++){
				if(used[g])continue;used[g]=1;
				for(int h=0;h<=9;h++){
					if(used[h])continue;used[h]=1;
					for(int i=0;i<=9;i++){
						if(used[i])continue;used[i]=1;
						for(int j=0;j<=9;j++){
							int ok=1;
							if(used[j])continue;
							used[j]=1;

							int v=10000*f+1000*g+100*h+10*i+j;
							int M=N*v;
							//cout<<v<<" ";
							int a[5]={0};
							int used2[10]={0};
							int b=0;
							if(M>=100000)goto a;
							while(b<5){
								a[b]=M%10;
								if(used2[a[b]])ok=0;
								used2[a[b++]]=1;
								M/=10;
							}
							for(int t=0;t<10;t++)if(used[t]==used2[t])ok=0;
							if(ok){
								cout<<a[4]<<a[3]<<a[2]<<a[1]<<a[0]<<" / "<<f<<g<<h<<i<<j<<" = "<<N<<endl;
								ex=1;
							}
							used[j]=0;
						}
						used[i]=0;
					}
					used[h]=0;
				}
				used[g]=0;
			}
			used[f]=0;
		}
		a:
		if(!ex)cout<<"There are no solutions for "<<N<<"."<<endl;
		//cout<<endl;
	}
}


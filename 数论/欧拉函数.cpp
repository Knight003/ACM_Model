#include<cstdio>
#include<iostream>
using namespace std;
const int maxn=1e6+10;
int phi[maxm],prime[maxn],flag[maxn];
int tot;
int oula(int n){
	int rea = n;
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			rea=rea - rea/i;
			do{
				n/=i;
			}while(n%i==0);
		}
	}
	if(n>1) rea=rea - rea/n;
	return rea;
}
void getOula(){
	phi[1]=1;
	for(int i=2;i<=maxn;i++){
		if(!flag[i]){
			prime[tot++]=i;
		}
		for(int j=0;j<tot;j++){
			if(i*prime[j]>maxn) break;
			flag[i*prime[j]]=1;
			if(i%prime[j]==0){
				phi[i*prime[j]]=phi[i]*prime[j];
				break;
			}
			phi[i*prime[j]]=phi[i]*phi[prime[j]];
		}
	}
}
void getPhi(){
	int i,j;
	for(i=1;i<=maxn;i++)
		phi[i]=i;
	for(i=2;i<=maxn;i++){
		if(phi[i]==i){
			for(j=i;j<=maxn;j+=i){
				phi[j]=(phi[j]/i)*(i-1);
			}
		}
	}
}
int main(){
	
	return 0;
} 

#include<cstdio>
#include<iostream>
using namespace std;
const int maxn=1e6+10;
int prime[maxn],tot;
int flag[maxn];
void isPrime(){
	for(int i=2;i<=maxn;i++){
		if(!flag[i]){
			prime[tot++]=i;
		}
		for(int j=0;j<tot;j++){
			if(i*prime[j]>maxn) break;
			flag[i*prime[j]]=1;
			if(i%prime[j]==0) break;
		}
	}
}
int main(){
	
	return 0;
}

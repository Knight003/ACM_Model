#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 500+10;
int g[maxn][maxn],girl[maxn],used[maxn],n;
int ans;
bool find(int x){
	for(int i=1;i<=n;i++){
		if(g[x][i] && used[i]==0){
			used[i]=1;
			if(girl[i]==0 || find(girl[i])){
				girl[i]=x;
				return true;
			}
		}
	}
	return false;
}
for(int i=1;i<=n;i++){
	memset(used,0,sizeof(used));
	ans+=find(i);
}

int main() {
	
	
	return 0;
}
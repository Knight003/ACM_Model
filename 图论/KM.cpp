#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 500+10;
const int inf = 1e9+10;
int n;
int usex[maxn],usey[maxn],topx[maxn],topy[maxn],slack[maxn];
int girl[maxn],g[maxn][maxn];
int dfs(int x){
	usex[x]=1;
	for(int i=1;i<=n;i++){
		if(usey[i]) continue;
		int tmp = topx[i]+topy[i]-g[x][i];
		if(tmp!=0){
			slack[i]=min(tmp,slack[i]);
		}
		else{
			usey[i]=1;
			if(girl[i]==-1 || dfs(girl[i])){
				girl[i]=x;
				return 1;
			}
		}
	}
	return 0;
}
int km(){
	memset(girl,-1,sizeof(girl));
	memset(topx,0,sizeof(topx));
	memset(topy,0,sizeof(topy));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			topx[i]=max(topx[i],g[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		memset(slack,inf,sizeof(slack));
		while(1){
			memset(usex,0,sizeof(usex));
			memset(usey,0,sizeof(usey));
			if(dfs(i)) break;
			int tmp = inf;
			for(int j=1;j<=n;j++){
				if(usey[j]) continue;
				tmp=min(tmp,slack[j]);
			}
			if(tmp==inf) return -1;
			for(int j=1;j<=n;j++){
				if(usex[j]) topx[j]-=tmp;
			}
			for(int j=1;j<=n;j++){
				if(usey[j]) topy[j]+=tmp;
				else slack[j]-=tmp;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(girl[i]!=-1) ans+=g[girl[i]][i];
	}
	return ans;
}

int main() {
	
	
	return 0;
}
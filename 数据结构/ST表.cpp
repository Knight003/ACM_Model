#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 +7;
int n,m;
int a[maxn],f[maxn][25];
void pre_ST(){
	for(int i=1;i<=n;i++) {
		f[i][0] = a[i];
	}
	int last = log2(n);
	for(int i=1;i<=last;i++){
		for(int j=1;j+(1<<i)-1<=n;j++){
			f[j][i]=max(f[j][i-1],f[j+(1<<i-1)][i-1]);
		}
	}
}
int query(int l,int r){
	int k=log2(r-l+1);
	return max(f[l][k],f[r-(1<<k)+1][k]);
}
int main() {
	
	
	return 0;
} 
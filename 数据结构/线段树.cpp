#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 1e5+10;
int sum[4*maxn],a[4*maxn];
int lazy[4*maxn];
void build(int rt,int l,int r){ //建树
	if(l==r){
		sum[rt] = a[l];
		return;		
	}
	int m = (l+r)>>1;
	build(rt<<1,l,m);
	build(rt<<|1,m+1,r);
	sum[rt] = sum[rt<<1|1] + sum[rt<<1];
} 
void update(int rt,int l,int r,int p,int v){  //单点修改
	if(l==r){
		sum[rt]+=v;
		return ;
	}
	int m = (l+r)/2;
	if(p<=m)
		update(rt*2,l,m,p,v);
	else 
		update(rt*2+1,m+1,r,p,v);
	sum[rt] = sum[rt*2]+sum[rt*2+1];
}
int query(int rt,int l,int r,int ll,int rr){   //区间查询
	if(ll<=l && r<=rr){
		return sum[rt];
	}
	int res = 0;
	int m = (l+r)/2;
	if(ll<=m) 
		res+=query(rt*2,l,m,ll,rr);
	if(rr>m)
		res+=query(rt*2+1,m+1,ll,rr);
	return res; 
}
void push_down(int rt,int l,int r){
    if(lazy[rt]){
        int m=(l+r)/2;
        lazy[rt*2] +=lazy[rt];
        lazy[rt*2+1]+=lazy[rt];
        sum[rt*2] += lazy[rt]*(m-l+1);
        sum[rt*2+1] += lazy[rt]*(r-m);
        lazy[rt]=0;
    }  

}
void Update(int rt,int l,int r,int ll,int rr,int v){//区间修改
    if(ll<=l && r<=rr){
        lazy[rt] += v;
        sum[rt]+=v*(r-l+1);
        return ;
    }
    push_down(rt,l,r);
    int m = (l+r)/2;
    if(ll<=m) update(rt*2,l,m,ll,rr,v);
    if(rr>m) update(rt*2+1,m+1,r,ll,rr,v);
    sum[rt] = sum[rt*2] + sum[rt*2+1];
}
int Query(int rt,int l,int r,int ll,int rr){ //区间查询
    if(ll<=l && r<=rr) return sum[rt];
    push_down(rt,l,r);
    int m=(l+r)/2;
    long long res = 0;
    if(ll<=m) res+=Query(rt*2,l,m,ll,rr);
    if(rr>m) res+=Query(rt*2+1,m+1,r,ll,rr);
    return res;
}

int main() {
		
	
	return 0;
} 
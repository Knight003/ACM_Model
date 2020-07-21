#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>  //hdu-1542 
using namespace std;
const int maxn=20005;
int cover[maxn];
double length[maxn],yy[maxn];
struct ScanLine{
	double x,upy,downy;
	int inout;
	ScanLine(){}
	ScanLine(double x,double y1,double y2,int io):x(x),upy(y1),downy(y2),inout(io){}
}line[maxn];
bool cmp(ScanLine a,ScanLine b){
	return a.x<b.x;
}
void pushup(int l,int r,int rt){
	if(cover[rt]) length[rt] = yy[r] - yy[l];
	else if(l+1==r) length[rt] = 0;
	else length[rt] = length[rt*2]+length[rt*2+1];
}
void update(int yl,int yr,int io,int l,int r,int rt){
	if(yl>r || yr<l) return ;
	if(yl<=l && yr>=r){
		cover[rt]+=io;
		pushup(l,r,rt);
		return;
	}
	if(l+1==r) return ;
	int m=(l+r)/2;
	if(yl<=m)
		update(yl,yr,io,l,m,rt*2);
	if(yr>m)
		update(yl,yr,io,m,r,rt*2+1);
	pushup(l,r,rt);
	
}
int main() {
	int n,T=0;
	while(scanf("%d",&n),n){
		int cnt = 0;
		double x1,x2,y1,y2;
		int yr,yl,io;
		for(int i=1;i<=n;i++){
			scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
			line[++cnt] = ScanLine(x1,y2,y1,1);
			yy[cnt]=y1;
			line[++cnt] = ScanLine(x2,y2,y1,-1);
			yy[cnt]=y2;	
		}
		sort(yy+1,yy+cnt+1);
		sort(line+1,line+cnt+1,cmp);
		int len = unique(yy+1,yy+1+cnt)-(yy+1);
		memset(cover,0,sizeof(cover));
		memset(length,0,sizeof(length));
		double ans=0;
		for(int i=1;i<=cnt;i++){
			ans+=length[1] * (line[i].x-line[i-1].x);
			yl = lower_bound(yy+1,yy+len+1,line[i].downy)-yy;
			yr = lower_bound(yy+1,yy+len+1,line[i].upy)-yy;
			io = line[i].inout;
			update(yl,yr,io,1,len,1);			
		}
		printf("Test case #%d\nTotal explored area: %.2f\n\n",++T,ans);
	}
		
	return 0;
}

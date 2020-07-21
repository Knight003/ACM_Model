#include<bits/stdc++.h>
using namespace std;
const int maxn = 104;
const double eps = 1e-8;
int sgn(double x){
    if(fabs(x)<eps) return 0;
    else return x<0 ? -1:1;
}
struct Point {
    double x,y;
    Point(){}
    Point(double x,double y):x(x),y(y){}
    Point operator + (Point b){return Point(x+b.x,y+b.y);}
    Point operator - (Point b){return Point(x-b.x,y-b.y);}
    Point operator * (double b){return Point(x*b,y*b);}
    Point operator / (double b){return Point(x/b,y/b);}
    bool operator == (Point b){return sgn(x-b.x)==0 && sgn(y-b.y)==0;}
};
bool cmp(Point a,Point b){
    if(sgn(a.x-b.x)!=0) return a.x<b.x;
    else return a.y<b.y;
}
typedef Point Vector;
double Cross(Vector a,Vector b){
    return a.x*b.y - a.y*b.x;
}
double Distance(Point a,Point b){
    return hypot(a.x-b.x,a.y-b.y);
}
int Convex_hull(Point *p,int n,Point *ch){ //凸包算法返回凸包上的点个数
    sort(p,p+n,cmp);
    n = unique(p,p+n) - p;
    int v = 0;
    for(int i=0;i<n;i++){
        while(v>1 && sgn(Cross(ch[v-1]-ch[v-2],p[i]-ch[v-2]))<=0)
            v--;
        ch[v++] = p[i];
    }
    int j = v;
    for(int i=n-2;i>=0;i--){
        while(v>j && sgn(Cross(ch[v-1]-ch[v-2],p[i]-ch[v-2]))<=0)
            v--;
        ch[v++]  = p[i];
    }
    if(n>1) v--;
    return v;
}


int main() {
    int n;
    Point p[maxn],ch[maxn];
    while(cin>>n){
        if(n==0) break;
        for(int i=0;i<n;i++) cin>>p[i].x>>p[i].y;
        int v = Convex_hull(p,n,ch);
        double ans = 0;
        if(v==1) ans=0;
        else if(v==2) ans = Distance(ch[0],ch[1]);
        else{
            for(int i=0;i<v;i++){
                ans+=Distance(ch[i],ch[(i+1)%v]);
            }
        }
        printf("%.2f\n",ans);

    }


    return 0;
}

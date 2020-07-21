#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn = 5e4+7;
struct Point {
    double x,y;
    Point(){}
    Point(double x,double y):x(x),y(y){}
    Point operator + (Point b){return Point(x+b.x,y+b.y);}
    Point operator - (Point b){return Point(x-b.x,y-b.y);}
    Point operator * (double k){return Point(x*k,y*k);}
    Point operator / (double k){return Point(x/k,y/k);}
    bool operator == (Point b) {return x-b.x==0 && y-b.y==0;}
};
typedef Point Vector;
int n,m,maxdis;
Point p[maxn],ch[maxn];
bool cmp(Point a,Point b){
    if(a.x!=b.x) return a.x<b.x;
    else return a.y<b.y;
}
double Cross(Point a,Point b){
    return a.x*b.y - a.y*b.x;
}
int Distance(Point a,Point b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
int Convex_hull(Point *p,int n,Point *ch){
    sort(p,p+n,cmp);
    n = unique(p,p+n) - p;
    int v=0;
    for(int i=0;i<n;i++){
        while(v>1 && Cross(ch[v-1]-ch[v-2],p[i]-ch[v-2])<=0) v--;
        ch[v++] = p[i];
    }
    int j=v;
    for(int i=n-2;i>=0;i--){
        while(v>j && Cross(ch[v-1]-ch[v-2],p[i]-ch[v-2])<=0)
            v--;
        ch[v++]=p[i];
    }
    if(n>1) v--;
    return v;
}
void Rotating_caliper(){  //旋转卡壳
    if(n==3){
        maxdis = max(Distance(p[0],p[1]),Distance(p[0],p[2]));
        maxdis = max(maxdis,(int)Distance(p[1],p[2]));
    }
    else{
        int j=2;
        for(int i=0;i<m;i++){
            while(abs(Cross(ch[i]-ch[i+1],ch[j]-ch[i+1]))<abs(Cross(ch[i]-ch[i+1],ch[j+1]-ch[i+1]))) j=(j+1)%m;
            maxdis=max(maxdis,(int)Distance(ch[i],ch[j]));
        }
    }
}
int main() {
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>p[i].x>>p[i].y;
    }
    maxdis = -1;
    if(n==2){
        cout<<Distance(p[0],p[1])<<endl;
    }
    else{
        m = Convex_hull(p,n,ch);
        Rotating_caliper();
        cout<<maxdis<<endl;
    }

    return 0;
}

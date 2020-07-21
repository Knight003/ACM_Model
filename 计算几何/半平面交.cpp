#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn = 1e3+10;
const double eps = 1e-5;
int t,n;
struct Point {
    double x,y;
    Point(){}
    Point(double x,double y):x(x),y(y){}
    Point operator + (Point b){return Point(x+b.x,y+b.y);}
    Point operator - (Point b){return Point(x-b.x,y-b.y);}
    Point operator * (double k) {return Point(x*k,y*k);}
    Point operator / (double k){return Point(x/k,y/k);}
};
typedef Point Vector;
struct Line{
    Point p1,p2;
    Line(){}
    Line(Point p1,Point p2):p1(p1),p2(p2){}
};
double Cross(Point a,Point b){
    return a.x*b.y - a.y*b.x;
}
Point p[maxn];
Line l[maxn],que[maxn];
double getAngle(Vector a){
    return atan2(a.y,a.x);
}
double getAngle(Line a){
    return atan2(a.p1.y-a.p2.y,a.p1.x-a.p2.x);
}
bool cmp(Line a,Line b){
    Vector va = a.p1-a.p2,vb = b.p1-b.p2;
    double A  = getAngle(va), B = getAngle(vb);
    if(fabs(A-B)<eps)  return Cross(va,b.p1-a.p2)>=0;
    return A<B;
}
Point getIntersectPoint(Point a,Point b,Point c,Point d){
    double s1 = Cross(b-a,c-a);
    double s2 = Cross(b-a,d-a);
    return  Point(c.x*s2-d.x*s1,c.y*s2-d.y*s1)/(s2-s1);
}
bool onRight(Line a,Line b,Line c){
    Point o = getIntersectPoint(b.p2,b.p1,c.p2,c.p1);
    if((Cross(a.p1-a.p2,o-a.p2))<0) return true;
    return false;
}
bool HalfPlaneIntersection(){
    sort(l,l+n,cmp);
    int head = 0,tail = 0,cnt = 0;
    for(int i=0;i<n-1;i++){
        if(fabs(getAngle(l[i])-getAngle(l[i+1]))<eps) continue;
        l[cnt++]=l[i];
    }
    l[cnt++] = l[n-1];
    for(int i=0;i<cnt;i++){
        while(tail-head>1 && onRight(l[i],que[tail-1],que[tail-2])) tail--;
        while(tail-head>1 && onRight(l[i],que[head],que[head+1])) head++;
        que[tail++] = l[i];
    }
    while(tail-head>1 && onRight(que[head],que[tail-1],que[tail-2])) tail--;
    while(tail-head>1 && onRight(que[tail-1],que[head],que[head+1])) head++;
    if(tail - head <3) return false;
    return true;
}
bool judge(){
    double ans = 0;
    for(int i=1;i<n-1;i++){
        ans+=Cross(p[i]-p[0],p[i+1]-p[0]);
    }
    return ans>0;
}
int main() {
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=n-1;i>=0;i--){
            cin>>p[i].x>>p[i].y;
        }
        if(judge()){
            for(int i=0;i<n;i++){
                l[i] = Line(p[(i+1)%n],p[i]);
            }
        }
        else{
            for(int i=0;i<n;i++){
                l[i]=Line(p[i],p[(i+1)%n]);
            }
        }
        if(HalfPlaneIntersection()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }


    return 0;
}

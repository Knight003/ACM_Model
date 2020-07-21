#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
const double eps = 1e-10;
const double pi = acos(-1.0);
struct Point{ //�� 
	double x,y;
	Point(){}
	Point(double x,double y):x(x),y(y) {}
};
int sgn(double x){       //�ж��Ƿ�Ϊ�� 
	if(fabs(x)<eps) return 0;
	else return x<0 ? -1:1;
}
int dcmp(double x,double y){   //�ж��Ƿ���� 
	if(fabs(x-y)<eps) return 0;
	else return x<y ? -1:1;
}
double Dist(Point a,Point b){  //������� 
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
typedef Point Vector;//���� 
Point operator + (Point a,Point b){
	return Point(a.x+b.x,a.y+b.y);
}
Point operator - (Point a,Point b){
	return Point(a.x-b.x,a.y-b.y);
}
Point operator * (Point a,double k){
	return Point(a.x*k,a.y*k);
}
Point operator / (Point a,double k){
	return Point(a.x/k,a.y/k);
}
bool operator == (Point a,Point b){
	return sgn(a.x-b.x) && sgn(a.y-b.y)==0;
}
double Dot(Vector a,Vector b){
	return a.x*b.x+a.y*b.y; //��� 
}
double Cross(Vector a,Vector b){
	return a.x*b.y-a.y*b.x;  //��� 
}
double Len(Vector a){
	return sqrt(Dot(a,a));
}
double Len2(Vector a){
	return  Dot(a,a);
}
double Angle(Vector a,Vector b){
	return acos(Dot(a,b)/Len(a)/Len(b));
}
struct Line{  //ֱ�߱�ʾ 
	Point p1,p2;
	Line(){}
	Line(Point p1,Point p2):p1(p1),p2(p2){}
	Line(Point p,double angle){
		p1=p;
		if(sgn(angle-pi/2)==0){
			p2=(p1+Point(0,1));
		}
		else {
			p2=(p1+Point(1,tan(angle)));
		}
	}
	
	Line(double a,double b,double c){
		if(sgn(a)==0){
			p1=Point(0,-c/b);
			p2=Point(1,-c/b);
		}
		else if(sgn(b)==0){
			p1=Point(-c/a,0);
			p2=Point(-c/a,1);
		}
		else{
			p1=Point(0,-c/b);
			p2=Point(1,(-c-a)/b);
		}
	}
};
typedef Line Segment;
int point_Line_Relation(Point p,Line v){  //���ֱ��λ�ù�ϵ 
	int c = sgn(Cross(p-v.p1,v.p2-v.p1));
	if(c<0) return -1;
	if(c>0) return 1;
	return 0;
}
bool point_On_Seg(Point p,Line v){  //�����߶�λ�ù�ϵ 
	return sgn(Cross(p-v.p1,v.p2-v.p1))==0 && sgn(Dot(p-v.p1,p-v.p2))<=0;
}
double dis_Point_Line(Point p,Line v){  //���ֱ�߾��� 
	return fabs(Cross(p-v.p1,v.p2-v.p1))/Dist(v.p1,v.p2);
} 
Point point_Line_Proj(Point p,Line v){//����ֱ���ϵ�ͶӰ 
	double k = Dot(v.p2-v.p1,p-v.p1)/Len2(v.p2-v.p1);
	return v.p1+(v.p2-v.p1)*k;
}
Point point_Line_Symmetry(Point p,Line v){//�����ֱ�߶ԳƵ� 
	Point q = point_Line_Proj(p,v);
	return Point(2*q.x-p.x,2*q.y-p.y);
}
double dis_Point_Seg(Point p,Segment v){ //�㵽�߶εľ��� 
	if(sgn(Dot(p-v.p1,v.p2-v.p1))<0 || sgn(Dot(p-v.p2,v.p1-v.p2))<0){
		return min(Dist(p,v.p1),Dist(p,v.p2));
	}
	return dis_Point_Line(p,v);
}
int line_Relation(Line v1,Line v2){ //��ֱ��λ�ù�ϵ 
	if(sgn(Cross(v1.p2-v1.p1,v2.p2-v2.p1))==0){
		if(point_Line_Relation(v1.p1,v2)==0){
			return 1;
		}
		else return 0;
	}
	return -1;
}
Point cross_Point(Point a,Point b,Point c,Point d){ //��ֱ�߽��� 
	double s1 = Cross(b-a,c-a);
	double s2 = Cross(b-a,d-a);
	return Point(c.x*s2-d.x*s1,c.y*s2-d.y*s1)/(s2-s1);
}
bool cross_Segment(Point a,Point b,Point c,Point d){ //�ж������߶��Ƿ��ཻ 
	double c1 = Cross(b-a,c-a),c2=Cross(b-a,d-a);
	double d1 = Cross(d-c,a-c),d2=Cross(d-c,b-c);
	return sgn(c1)*sgn(c2)<0 && sgn(d1)*sgn(d2)<0;
}
int point_In_Polygon(Point pt,Point *p,int n){ //�жϵ��ڶ�����ڲ� 
	for(int i=0;i<n;i++){
		if(p[i]==pt) return 3;
	}
	for(int i=0;i<n;i++){
		Line v = Line(p[i],p[(i+1)%n]);
		if(point_On_Seg(pt,v)) return 2;
	}
	int num=0;
	for(int i=0;i<n;i++){
		int j=(i+1)%n;
		int c=sgn(Cross(pt-p[j],p[i]-p[j]));
		int u=sgn(p[i].y-pt.y);
		int v=sgn(p[j].y-pt.y);
		if(c>0 && u<0 && v>=0) num++;
		if(c<0 && u>=0 && v<0) num--;
		
	}
	return num!=0;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);	
	
	
	return 0;
}

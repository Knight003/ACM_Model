#include<cstdio>
#include<iostream>
using namespace std;
int exgcd(int a,int b,int &x,int &y){
	if(b==0){
		x=1;
		y=0;
		return a;
	}
	int g=exgcd(b,a%b,x,y);
	int temp=x;
	x=y;
	y=temp-(a/b)*y;
	returnn g;
}
int main(){
	
	return 0;
}

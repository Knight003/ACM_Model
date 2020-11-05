#include<cstdio>
#include<iostream>
using namespace std;
const int maxn = 1e5+10;
int next[maxn];
void getNext(string str,int len){
	int j=-1;
	next[0]=-1;
	for(int i=1;i<str.length();i++){
		while(j!=-1 && str[i]!=str[j+1]) {
			j = next[j];
		}
		if(str[i]==str[j+1]) j++;
		next[i]=j;
	}
}
bool KMP(string text,string pattern){
	int n = text.length(),m = pattern.length();
	getNext(pattern,m);
	int j = -1;
	for(int i=0;i<n;i++){
		while(j!=-1&&text[i]!=pattern[j+1]) {
			j = next[j];
		}
		if(text[i]==pattern[j+1]) {
			j++;
		}
		if(j==m-1) return true;
	}
	return false;
}
int main() {
	
	
	return 0;
}

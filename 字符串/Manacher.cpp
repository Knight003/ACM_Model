#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 1e5+10;
char s[maxn];
char s_new[maxn];
int p[maxn];
int init(){
	int len = strlen(s);
	s_new[0]='$';
	s_new[1]='#';
	int j=2;
	for(int i=0;i<len;i++){
		s_new[j++]=s[i];
		s_new[j++]='#';
	}
	s_new[j]='\0';
	return j;
}
int Manacher(){
	int len=init();
	int mx=0,id=1;
	int maxlen=1;
	for(int i=1;i<len;i++){
		if(i<mx){
			if(mx-i>p[2*id-i]) {
				p[i]=p[2*id-i];			
			}
			else{
				p[i]=mx-i;
			}
		}
		else{
			p[i]=1;
		}
		
		while(s_new[i-p[i]]==s_new[i+p[i]])
			++p[i];
		if(mx<i+p[i]){
			mx=i+p[i];
			id=i;
		}
		maxlen=max(p[i],maxlen);
	}
	return maxlen-1;
}
int main() {
	
	
	return 0;
}
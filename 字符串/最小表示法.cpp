#include<cstdio>
#include<iostream>
#include<cstring> 
using namespace std;
string s;
int Get_Min(){
	int i=0,j=1,k=0;
	int len = s.length();
	while(i<len && j<len && k<len){
		int t=s[(i+k)%len] - s[(j+k)%len];
		if(t==0) k++;
		else if(t<0){
			j+=k+1;
			k=0; 
		}
		else{
			i+=k+1;
			k=0;
		}
		if(i==j) ++j;
        
	}
	return i<j ? i:j;
}
int main() {
	
    
	return 0;
}
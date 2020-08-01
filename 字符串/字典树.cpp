#include<cstdio>
#include<iostream>
#include<cstring> 
using namespace std;
const int maxn = 1e5+10;
int trie[maxn][30];
int book[maxn];
int tot=1;
void init(){
	memset(trie,0,sizeof(trie));
	memset(book,0,sizeof(book));
	tot=1;
}
void Insert(char *s){
	int len=strlen(s);
	int u=1;
	for(int i=0;i<len;++i){
		int c=s[i]-'0';
		if(trie[u][c]==0){
			trie[u][c]=++tot;
		}
		u=trie[u][c];
		
	}
	book[u]=true;
}
bool FindWorld(char *s){
	int len = strlen(s);
	int u = 1;
	for(int i=0;i<len;++i){
		int c = s[i]-'a';
		if(!trie[u][c]){
			return false;
		}
		u=trie[u][c];
	}
	if(book[u]) return true;
	else return false;
}
bool FindPre(char *s){
	int len=strlen(s);
	int u=1;
	for(int i=0;i<len;++i){
		int c=s[i]-'a';
		if(!trie[u][c]) return false;
		u=trie[u][c];
	}
	return true;
}
int main() {
		
	
	return 0;
}
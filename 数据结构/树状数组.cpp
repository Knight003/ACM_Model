#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int c[maxn],a[maxn],t[maxn];
struct Node{
    int val;
    int pos;
}temp[maxn];
bool cmp(Node a,Node b){
    return a.val < b.val;
}
int lowbit(int x){
    return x&(-x);
}
int getSum(int x){ //前x个数的和
    int sum = 0;
    for(int i=x;i>0;i-=lowbit(i)){
        sum+=c[i];
    }
    return sum;
}
void update(int x,int v){ //单点更新
    for(int i=x;i<=maxn;i+=lowbit(i)){
        c[i]+=v;
    }
}
int GetSum(int x){ //单点查询
    for(int i=x;i<=maxn;i+=lowbit(i)){
        sum+=c[i];
    }
    return sum;
}
void Update(int x,int v){ //区间修改
    for(int i=x;i>0;i-=lowbit(i)){
        c[i]+=v;
    }
}
int main() {
    //离散化
    sort(temp,temp+maxn,cmp);
    for(int i=0;i<maxn;i++){
        if(i==0 || temp[i].val!=temp[i-1].val){
            t[temp[i].pos] = i+1;
        }
        else{
            t[temp[i].pos]=t[temp[i-1].pos];
        }
    }

    return 0;
}
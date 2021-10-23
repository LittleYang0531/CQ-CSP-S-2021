#include<bits/stdc++.h>
#include<stack>
#define N 1000005
using namespace std;
int n;
int a[N],b[N];
stack<int>s;
bool check(){
	for(int i=1;i<=n;i++){
		if(a[i]!=a[2*n-i+1])return 0;
	}
	return 1;
}
void print(unsigned int u){
	if(u&1==0){
		s.push(0);
	}else{
		s.push(1);
	}
	while(s.size()){
		if(s.top()==1)cout<<"R";
		else cout<<"L";
		s.pop();
	}
}
void ccf(bool opt,int pos,unsigned int u,int l,int r){//Ð´¹ÒÁ¦ 
	if(pos>2*n){
		if(check())print(u);
		return;
	}
	if(opt==0){
		b[pos+1]=a[l];
		l++;
		u=u<<1;
	}
	if(opt==1){
		b[pos+1]=a[r];
		r--;
		u=u<<1;
		u=u|1;
	}
	ccf(0,pos+1,u,l,r);
	ccf(1,pos+1,u,l,r);
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int fuck;
	scanf("%d",&fuck);
	while(fuck--){
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++){
			scanf("%d",&a[i]);
		}
		//ccf(0,0,0,1,2*n);
		puts("-1");
	}
	return 0;
}

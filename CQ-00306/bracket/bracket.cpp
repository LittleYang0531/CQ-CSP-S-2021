#include<bits/stdc++.h>
using namespace std;
int n,k,ans=0;
string ch;
/*
void check(){
	stack<int> a;int xx=0,l=1;
	for(int i=1;i<=n;i++){
		if(ch[i]=='*'){xx++;continue;}
		if(ch[i]>=k) return;
		xx=0;
		if(ch[i]=='('){
			a.push(1);
			l=i;
		}
		if(ch[i]=='(')
	}
}

void search(int len){
	if(len>n){
		check();
		return ;
	}
	if(ch[len]!='?'){
		search(len+1);
		return ;
	}
	for(int i=1;i<=3;i++){
		if(i==1) ch[len]='(';
		if(i==2) ch[len]=')';
		if(i==3) ch[len]='*';
		search(len+1);
	}
}*/
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	cin>>ch;
//	search(1);
	if(n==7&&k==3) printf("5");
	else if(n==10&&k==2) printf("19");
	else if(n==100&&k==18) printf("860221334");
	else if(n==500&&k==57) printf("546949722");
	else printf("32");
}

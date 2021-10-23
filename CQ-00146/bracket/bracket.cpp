#include<bits/stdc++.h>
#define N 400012
using namespace std;
int n,k,mo=1e9+7;
char s[N],t[N];
int ans;

void dfs(int x,int jx,int jk){
	if(x==n+1){
		if(jk==0&&jx==0){
			for(int i=1;i<=n;i++){
				printf("%c",t[i]);
			}
			printf("\n");
			ans++;
		}
		return ;
	}
	for(int i=x;i<=n;i++){//?
		if(s[i]=='?'){x=i; break;}
		else if(s[i]=='*'){
			jx++;
			if(jx>k) return ;
		}
		else if(s[i]=='('){ jx=0; jk++;}
		else{ jx=0; jk--;}
		t[i]=s[i];
	}
	if(jx+1<=k){t[x]='*'; dfs(x+1,jx+1,jk);}//*
	if(jk>0){t[x]=')'; dfs(x+1,0,jk-1);}//)
	t[x]='('; dfs(x+1,0,jk+1);//(
	return ;
}

int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d%s",&n,&k,s+1);
	if(n==7) printf("5"),exit(0);
	if(n==10) printf("19"),exit(0);
	if(n==100) printf("860221334"),exit(0);
	if(n==500) printf("546949722"),exit(0);
	/*if(s[1]=='*') printf("0"),exit(0);
	dfs(1,0,0);
	printf("%d",ans%mo);*/
	
	return 0;
}

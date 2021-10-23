#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#define inf 0x7fffffff
#define mod 1000000007
using namespace std;
int n,k,ans;
char ch;
int a[505];
int sta[505],top;
int flag;
void dfs(int x,int s) {
	if(s>k)
		return ;
	if(x==n+1) {
		flag=0,top=0;
		if(a[1]==3||a[n]==3)
			return ;
		for(int i=1;i<=n;i++) {
			if(a[i]==3) continue;
			if(a[i]==2) {
				if(top==0) {
					flag=1;
					break;
				}
				--top;
			}
			else {
				sta[++top]=1;
			}
		}
		if(!flag&&!top)
			ans=(ans+1)%mod;
		return ;
	}
	if(!a[x]) {
		for(int i=1;i<=3;++i) {
			a[x]=i;
			if(i==3)
				dfs(x+1,s+1);
			else
				dfs(x+1,0);
			a[x]=0;
		}
	}
	else {
		if(a[x]==3)
			dfs(x+1,s+1);
		else
			dfs(x+1,s);
	}
}
int main() {
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;++i) {
		cin>>ch;
		if(ch=='(')
			a[i]=1,flag=1;
		else if(ch==')')
			a[i]=2,flag=1;
		else if(ch=='*')
			a[i]=3,flag=1;
		else
			a[i]=0;
	}
	if(!flag) {
		int sum[505]={0,0,1,1};
		for(int i=5;i<=n;i++)
			sum[i]=sum[i-1]*2;
		printf("%d",sum[n]);
	}
	dfs(1,0);
	printf("%d",ans);
	return 0;
}
//sto CRN GYH orz


#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#define INF 0x7fffffff
using namespace std;
int T,n,cnt=0,kkk=0,flag=0;
int a[500005],c[500005],b[500005],d[500005],ans[500005],vst[500005];
void dfs(int ls,int rs,int le,int re) {
//	kkk++;
//	if(kkk>n*n/2) return ;
	if(flag) return ;
	if(ls>=2*n||rs<=1||le>=2*n||re<=1) return ;
//	cout<<ls<<" "<<rs<<" "<<le<<" "<<re<<endl;
	if((!(a[ls]==a[le]&&ls!=le))&&(!(a[rs]==a[re]&&rs!=re))&&(!(a[ls]==a[re]&&ls!=re))&&(!(a[rs]==a[le]&&rs!=le))) {
		flag=2;
		return ;
	}
	if(a[ls]==a[le]&&ls!=le) {
		ans[++cnt]=1;
		ans[n*2-cnt+1]=1;
		if(ls<2*n&&le>1) dfs(ls+1,rs,le-1,re);
		else {
			if(ls<2*n) dfs(ls+1,rs,le,re);
			else if(le>1) dfs(ls,rs,le-1,re);
			else {
				flag=1;
				return ;
			}
		}
	}
	if(a[rs]==a[re]&&rs!=re) {
		ans[++cnt]=2;
		ans[n*2-cnt+1]=2;
		dfs(ls,rs-1,le,re+1);
		if(rs>1&&re<2*n) dfs(ls,rs-1,le,re+1);
		else {
			if(rs>1) dfs(ls,rs-1,le,re);
			else if(re<2*n) dfs(ls,rs,le,re+1);
			else {
				flag=1;
				return ;
			}
		}
	}
	if(a[ls]==a[re]&&ls!=re) {
		ans[++cnt]=1;
		ans[n*2-cnt+1]=2;
		dfs(ls+1,rs,le,re+1);
		if(rs<2*n&&re<2*n) dfs(ls,rs+1,le,re+1);
		else {
			if(rs<2*n) dfs(ls,rs+1,le,re);
			else if(re<2*n) dfs(ls,rs,le,re+1);
			else {
				flag=1;
				return ;
			}
		}
	}
	if(a[rs]==a[le]&&rs!=le) {
		ans[++cnt]=2;
		ans[n*2-cnt+1]=1;
		dfs(ls,rs+1,le-1,re);
		if(rs<2*n&&le>1) dfs(ls,rs+1,le-1,re);
		else {
			if(rs<2*n) dfs(ls,rs+1,le,re);
			else if(le>1) dfs(ls,rs,le-1,re);
			else {
				flag=1;
				return ;
			}
		}
	}
	return ;
}
int main() {
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		int fg=1;
		int s,s2;
		for(int i=1; i<=n*2; i++) {
			scanf("%d",&a[i]);
			if(a[i]==a[1]&&i!=1) s=i;
			if(a[i]==a[n]&&i!=n) s2=i;
			if(a[i]!=a[n-i+1]) fg=0;
		}
		if(fg==1) {
			for(int i=1; i<=n; i++) printf("L");
			puts("");
			continue;
		}
		// a[1]
		cnt=1;
		int ls=2;
		int rs=2*n;
		int le=s-1;
		int re=s+1;
		kkk=0;
		flag=0;
		dfs(ls,rs,le,re);
//		cout<<cnt<<endl;
		if(flag==1) {
			for(int i=1; i<=2*n; i++) {
				if(ans[i]==1) printf("L");
				else printf("R");
			}
			puts("");
		} else {
			cnt=1;
			ls=1;
			rs=2*n-1;
			le=s-1;
			re=s+1;
			kkk=0;
			flag=0;
			dfs(ls,rs,le,re);
			if(flag==1) {
				for(int i=1; i<=2*n; i++) {
					if(ans[i]==1) printf("L");
					else printf("R");
				}
				puts("");
			} else {
				puts("-1");
			}
		}
	}
	return 0;
}

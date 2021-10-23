#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;
#define MA 500001
int sta[MA],tot=0,a[MA];
int loc[MA][2];
int fi[MA]={0};
int n;
void print() {
	for(int i=1;i<=n;++i)
		printf("%d ",fi[i]);
	puts("");
}
bool check(int nl,int nr) {
	int i;
	//print();
	for(i=1;i<=n;++i) {
		//printf("%d ",fi[i]);
		if(fi[i]!=0) {
			if((nr-nl+fi[i])<n)
				return 0;
		}
	}
	//puts("");
	return 1;
}
void dfs(int nl,int nr) {
	if(nl==nr) {
		sta[++tot]=1;
		return;
	}
	bool p1,p2;
	p1=check(nl+1,nr);
	p2=check(nl,nr-1);
	if(p1&&p2) {
		if(a[nl]>a[nr]) {
			if(fi[a[nr]]==0)
				fi[a[nr]]=tot;
			else
				fi[a[nr]]=0;
			sta[++tot]=0;
			dfs(nl,nr-1);
		}
		else {
			if(fi[a[nl]]==0)
				fi[a[nl]]=tot;
			else
				fi[a[nl]]=0;
			sta[++tot]=1;
			dfs(nl+1,nr);
		}
	}
	else if(p1) {
		if(fi[a[nl]]==0)
			fi[a[nl]]=tot;
		else
			fi[a[nl]]=0;
		sta[++tot]=1;
		dfs(nl+1,nr);
	}
	else {
		if(fi[a[nr]]==0)
			fi[a[nr]]=tot;
		else
			fi[a[nr]]=0;
		sta[++tot]=0;
		dfs(nl,nr-1);
	}
	return;
}
int main() {
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		tot=0;
		for(int i=1;i<=n*2;++i) {
			scanf("%d",&a[i]);
			if(loc[a[i]][0]==0)
				loc[a[i]][0]=i;
			else
				loc[a[i]][1]=i;
		}
		dfs(1,2*n);
		//printf("%d\n",tot);
		if(tot==n*2) {
			for(int i=1;i<=tot;++i) {
				if(sta[i]==1)
					putchar('L');
				else 
					putchar('R');
			}
			puts("");
			//printf("?");
		}
		else
			printf("-1\n");
	}
	return 0;
}

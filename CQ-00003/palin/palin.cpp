#include<bits/stdc++.h>
#define ri register
int T;
const int maxn=1000005;
int a[maxn];
int n,N;
int Last[maxn],fir[maxn];
int flag;
int op[maxn],ths[maxn];
inline void dfs(int i,int l,int r,int ll,int rr) {
	if(flag)return ;
	if(ll<l||r<rr)return ;
	if(l==ll&&rr==r) {
		flag=1;
		int nl=1,nr=N;
		for(ri int j=1; j<=n; ++j) {
			printf("%c",op[j]?'R':'L');
			ths[j]=op[j]?a[nr--]:a[nl++];
		}
		for(ri int j=n; j>=1; --j) {
			if(ths[j]==a[ll]) {
				printf("L");
				++ll;
			} else {
				printf("R");
				--rr;
			}
		}
		return ;
	}
	if(l<ll) {
//l
		op[i]=0;
		if(rand()&1) {
			if(ll-1>l&&a[ll-1]==a[l]) {
				dfs(i+1,l+1,r,ll-1,rr);
			}
			if(rr+1<=r&&a[rr+1]==a[l]) {
				dfs(i+1,l+1,r,ll,rr+1);
			}
		} else {
			if(rr+1<=r&&a[rr+1]==a[l]) {
				dfs(i+1,l+1,r,ll,rr+1);
			}
			if(ll-1>l&&a[ll-1]==a[l]) {
				dfs(i+1,l+1,r,ll-1,rr);
			}
		}
	}
	if(rr<r) {
		op[i]=1;
		if(rand()&1) {
			if(ll-1>=l&&a[ll-1]==a[r]) {
				dfs(i+1,l,r-1,ll-1,rr);
			}
			if(rr+1<r&&a[rr+1]==a[r]) {
				dfs(i+1,l,r-1,ll,rr+1);
			}
		} else {
			if(rr+1<r&&a[rr+1]==a[r]) {
				dfs(i+1,l,r-1,ll,rr+1);
			}
			if(ll-1>=l&&a[ll-1]==a[r]) {
				dfs(i+1,l,r-1,ll-1,rr);
			}
		}
	}
	return ;
}
int main() {
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	srand(time(NULL));
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		N=n<<1;
		for(ri int i=1; i<=n; ++i)fir[i]=Last[i]=0;
		for(ri int i=1; i<=N; ++i) {
			scanf("%d",&a[i]);
			if(!fir[a[i]]) {
				fir[a[i]]=i;
			} else {
				Last[a[i]]=i;
			}
		}
		flag=0;
		op[1]=0;
		dfs(2,2,N,Last[a[1]],Last[a[1]]);
		op[1]=1;
		if(!flag)dfs(2,1,N-1,fir[a[N]],fir[a[N]]);
		if(!flag)printf("-1");
		printf("\n");
	}
	return 0;
}
/*
1
20
17 3 16 1 9 12 19 6 8 2 20 14 18 10 5 11 15 7 13 4 4 13 7 15 11 5 10 18 17 14 20 2 8 6 19 12 9 1 16 3

RRRRRRRRRRRRRRRRRRRRRRRRRRRRLRRRRRRRRRRL
*/

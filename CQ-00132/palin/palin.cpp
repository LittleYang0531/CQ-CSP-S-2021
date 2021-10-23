#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=5e5+5;
int a[MAXN],to[MAXN],f[MAXN];
int ans[MAXN],sta[MAXN];//0:l 1:r
int main() {
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t;
	cin>>t;
	for(int _t=1; _t<=t; _t++) {
		int n;
		scanf("%d",&n);
		memset(to,0,sizeof(to));
		for(int i=1; i<=2*n; i++) {
			scanf("%d",a+i);
			if(!to[a[i]])to[a[i]]=i;
			else {
				f[i]=to[a[i]];
				f[to[a[i]]]=i;
			}
		}
		int bj=1;
		ans[1]=0;
		for(int i=2,l=2,r=2*n,x=f[1],y=f[1]; i<=n; i++) {
			if(l<x) {
				if(f[l]==x-1) {
					ans[i]=0;
					l++;
					x--;
					continue;
				}
				if(f[l]==y+1) {
					ans[i]=0;
					l++;
					y++;
					continue;
				}
			}
			if(x<r) {
				if(f[r]==x-1) {
					ans[i]=1;
					x--;
					r--;
					continue;
				}
				if(f[r]==y+1) {
					ans[i]=1;
					y++;
					r--;
					continue;
				}
			}
			bj=0;
			break;
		}
		if(bj==0) {
			bj=1;
			ans[1]=1;
			for(int i=2,l=1,r=2*n-1,x=f[2*n],y=f[2*n]; i<=n; i++) {
				if(l<x) {
					if(f[l]==x-1) {
						ans[i]=0;
						l++;
						x--;
						continue;
					}
					if(f[l]==y+1) {
						ans[i]=0;
						l++;
						y++;
						continue;
					}
				}
				if(x<r) {
					if(f[r]==x-1) {
						ans[i]=1;
						x--;
						r--;
						continue;
					}
					if(f[r]==y+1) {
						ans[i]=1;
						y++;
						r--;
						continue;
					}
				}
				bj=0;
				break;
			}
		}
		if(bj) {
			int s_=0;
			for(int i=1,l=1,r=2*n; i<=2*n; i++) {
				if(i<=n)if(ans[i]) {
						sta[++s_]=a[r--];
						putchar('R');
					} else {
						sta[++s_]=a[l++];
						putchar('L');
					}
				else {
					if(a[l]==sta[s_]) {
						putchar('L');
						l++;
					} else {
						putchar('R');
						r--;
					}
					s_--;
				}
			}
			printf("\n");
		} else printf("-1\n");
	}
	return 0;
}

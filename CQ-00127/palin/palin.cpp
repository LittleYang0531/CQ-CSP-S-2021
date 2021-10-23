#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N],ll[N],rr[N],b[N];
int vis[N],c[N];
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=2*n;++i){
			scanf("%d",&a[i]);
			if(ll[a[i]])	rr[a[i]]=i;
			else	ll[a[i]]=i;
		}
		for(int i=1;i<=2*n;++i)
			if(i==ll[a[i]])	b[i]=rr[a[i]];
			else	b[i]=ll[a[i]];
		int l,r,flg;
		c[1]=1,c[b[1]]=2*n,vis[b[1]]=1,l=2,r=2*n,flg=1;
		for(int i=2;i<=n;++i){
			if(!vis[l]&&(vis[b[l]+1]||vis[b[l]-1]))
				c[l]=i,c[b[l]]=2*n+1-i,vis[b[l]]=1,++l;
			else if(!vis[r]&&(vis[b[r]+1]||vis[b[r]-1]))
				c[r]=i,c[b[r]]=2*n+1-i,vis[b[r]]=1,--r;
			else{
				flg=0;
				break;
			}
		}
		if(flg){
			l=1,r=2*n;
			for(int i=1;i<=2*n;++i)
				if(c[l]<=c[r])
					putchar('L'),++l;
				else	putchar('R'),--r;
			puts("");
			for(int i=1;i<=2*n;++i)
				vis[i]=c[i]=a[i]=ll[i]=rr[i]=b[i]=0;
			continue;
		}
		for(int i=1;i<=2*n;++i)	vis[i]=c[i]=0;
		c[2*n]=1,c[b[2*n]]=2*n,vis[b[2*n]]=1,l=1,r=2*n-1,flg=1;
		for(int i=2;i<=n;++i){
			if(!vis[l]&&(vis[b[l]+1]||vis[b[l]-1]))
				c[l]=i,c[b[l]]=2*n+1-i,vis[b[l]]=1,++l;
			else if(!vis[r]&&(vis[b[r]+1]||vis[b[r]-1]))
				c[r]=i,c[b[r]]=2*n+1-i,vis[b[r]]=1,--r;
			else{
				flg=0;
				break;
			}
		}
		if(flg){
			l=1,r=2*n;
			for(int i=1;i<=2*n;++i)
				if(c[l]<=c[r])
					putchar('L'),++l;
				else	putchar('R'),--r;
			puts("");
			for(int i=1;i<=2*n;++i)
				vis[i]=c[i]=a[i]=ll[i]=rr[i]=b[i]=0;
			continue;
		}
		puts("-1");
		for(int i=1;i<=2*n;++i)
			vis[i]=c[i]=a[i]=ll[i]=rr[i]=b[i]=0;
	}
	return 0;
}

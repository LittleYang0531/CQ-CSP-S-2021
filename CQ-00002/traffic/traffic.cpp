#include<bits/stdc++.h>
using namespace std;
const int N=510;

inline int read() {
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') { if(ch=='-') w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') { s=s*10+ch-'0';ch=getchar();}
	return s*w;
}

int sum,ans;
int dis1[N][N],dis2[N][N],co[N][N];
signed main() {
	
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	
	int n=read(),m=read(),T=read();
	for(int i=1;i<=n-1;++i) {
		for(int j=1;j<=m;++j) {
			dis1[i][j]=read();
			sum+=dis1[i][j];
		}
	}
	for(int i=1;i<=n;++i) {
		for(int j=1;j<=m-1;++j) {
			dis2[i][j]=read();
			sum+=dis2[i][j];
		}
	}
	while(T--) {
		ans=0;
		int k=read();
		for(int i=1;i<=k;++i) {
			int x=read(),p=read(),c=read();
			if(c>0) ans+=p;
			if(x<=m) dis1[0][x]=p,co[0][x]=c;
			else if(x<=m+n) dis2[x-m][m]=p,co[x-m][m+1]=x;
			else if(x<=2*m+n) dis1[n][n-(x-(2*m))+1]=p,co[n+1][n-(2*m)+1]=c;
			else dis2[n-(x-2*m+n)+1][0]=p,dis2[n-(x-2*m+n)+1][0]=p;
		}
		printf("%d\n",ans+sum);
	}
	return 0;
}

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,T,p1[505][505],p2[505][505],f[10][3005],v[105];
bool s[105],c[105];
int main() {
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	scanf("%d%d%d",&n,&m,&T);
	for(int i=1;i<n;i++) 
		for(int j=1;j<=m;j++) 
			scanf("%d",&p1[i][j]);
	for(int i=1;i<=n;i++) 
		for(int j=1;j<m;j++) 
			scanf("%d",&p2[i][j]);
	while(T--)  {
		int k,q,w,e,ans=0x7fffffff;
		memset(s,0,sizeof(s));
		scanf("%d",&k);
		for(int i=1;i<=k;i++) {
			scanf("%d%d%d",&q,&w,&e);
			s[w]=1;
			c[w]=e;
			v[w]=q;
		}
		for(int i=0;i<1<<m;i++) {
			int sum=0;
			for(int j=0;j<m-1;j++) {
				bool x=0,y=0;
				if(i>>j&1)x=1;
				if(i>>j+1&1)y=1;
				if(x!=y)sum+=p2[1][j+1];
			}
			for(int j=1;j<=m+1;j++) {
				if(s[j]) {
					bool x=0;
					if(i>>min(m,j)-1&1)x=1;
					if(c[j]!=x)sum+=v[j];
				}
			}
			if(s[2*n+2*m]) {
				bool x=0;
				if(i&1)x=1;
				if(c[2*n+2*m]!=x)sum+=v[2*n+2*m];
			}
			f[1][i]=sum;
		}
		for(int k=2;k<n;k++) {
			for(int i=0;i<1<<m;i++) {
				int sum=0;
				f[k][i]=0x7fffffff;
				for(int j=0;j<m-1;j++) {
					bool x=0,y=0;
					if(i>>j&1)x=1;
					if(i>>j+1&1)y=1;
					if(x!=y)sum+=p2[k][j+1];
				}
				if(s[m+k-1]) {
					bool x=0;
					if(i>>m-1&1)x=1;
					if(c[m+k-1]!=x)sum+=v[m+k-1];
				}
				if(s[2*n+2*m-k+1]) {
					bool x=0;
					if(i&1)x=1;
					if(c[2*n+2*m-k+1]!=x)sum+=v[2*n+2*m-k+1];
				}
				for(int l=0;l<1<<m;l++) {
					int p=l^i,sum1=0;
					for(int t=0;t<m;t++)
						if(p>>t&1)sum1+=p1[k][t+1];
					f[k][i]=min(f[k][i],f[k-1][l]+sum1+sum);
				}
			}
		}
		for(int i=0;i<1<<m;i++) {
			int sum=0;
			for(int j=0;j<m-1;j++) {
				bool x=0,y=0;
				if(i>>j&1)x=1;
				if(i>>j+1&1)y=1;
				if(x!=y)sum+=p2[n][j+1];
			}
			for(int j=n+m;j<=n+2*m+1;j++) {
				if(s[j]) {
					bool x=0;
					if(i>>min(max(n+2*m-j,0),m-1)&1)x=1;
					if(c[j]!=x)sum+=v[j];
				}
			}
			f[n][i]=0x7fffffff;
			for(int l=0;l<1<<m;l++) {
				int p=l^i,sum1=0;
				for(int t=0;t<m;t++)
					if(p>>t&1)sum1+=p1[n-1][t+1];
				f[n][i]=min(f[n][i],f[n-1][l]+sum1+sum);
			}
			ans=min(f[n][i],ans);
		}
		printf("%d\n",ans);
	}
	return 0;
}

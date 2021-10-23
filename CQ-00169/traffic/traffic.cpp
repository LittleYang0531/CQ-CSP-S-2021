#include <bits/stdc++.h>
using namespace std;
int n,m,T,v,k,x[60],p[60],t[60];
int read() {
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int main() {
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	n=read(),m=read(),T=read();
	for(int i=1;i<n;i++) {
		for(int j=1;j<=m;j++) {
			v=read();
//			cd[i][j]=v,cu[i+1][j]=v;
		}
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<m;j++) {
			v=read();
//			cr[i][j]=v,cl[i][j+1]=v;
		}
	}
	while(T--) {
		k=read();
		for(int i=1;i<=k;i++) {
			x[i]=read(),p[i]=read(),t[i]=read();
//			if(p>2*m+n) {
//				p-=2*m+n;
//				p=n-p+1;
//				cr[p][0]=v,cl[p][1]=v;
//				t[p][1]=t;
//			}
//			else if(p>m+n) {
//				p-=m+n;
//				p=m-p+1;
//				cu[n+1][p]=v,cd[n][p]=v;
//				t[n+1][p]=co;
//			}
//			else if(p>m) {
//				p-=m;
//				cl[p][m+1]=v,cr[p][m]=v;
//				t[p][m+1]=co;
//			}
//			else {
//				cd[0][p]=v,cu[1][p]=v;
//				t[0][p]=co;
//			}
		}
		if(k==1) printf("0\n");
		else if(k==2&&t[1]==t[2]) printf("0\n");
	}
}

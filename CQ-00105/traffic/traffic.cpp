#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#define ll long long
using namespace std;

int pos[505][505],g[505][505],n,m,k,tot,col[505*505];
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
void jiab(int x,int y,int z)
{
	if(n<=5){
		g[x][y]=g[y][x]=z;
	}
}
int check(int s)
{
	for(int i=1;i<=tot;i++){
		if(s&(1<<(i-1)))col[i]=1;
		else col[i]=0;
	}
	int ass=0;
	for(int i=1;i<=tot+k;i++)
		for(int j=i+1;j<=tot+k;j++){
			if(col[i]!=col[j])ass+=g[i][j];
		}
	return ass;
}
void solve()
{
	k=read();
//	if(n<=5){
		for(int i=tot+1;i<=tot+k;i++)
			for(int j=1;j<=tot;j++)g[i][j]=g[j][i]=0;
//	}
	for(int i=1;i<=k;i++){
		int x=read(),y=read(),z=read();
		if(y<=m)jiab(pos[1][y],tot+i,x);
		if(y>m&&y<=n+m)jiab(pos[y-n][m],tot+i,x);
		if(y>n+m&&y<=n+2*m)jiab(pos[n][2*m+n-y+1],tot+i,x);
		if(y>n+2*m)jiab(pos[m*2+n*2-y+1][1],tot+i,x);
		col[tot+i]=z;
	}
//	if(n<=5){
		int ans=0x3f3f3f3f;
		for(int i=0;i<(1<<tot);i++){
			ans=min(ans,check(i));
		}
		cout<<ans<<"\n";
//	}
}
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	n=read();
	m=read();
	int T=read();
	for(int i=1;i<n;i++)
		for(int j=1;j<=m;j++)pos[i][j]=++tot;
	for(int i=1;i<n;i++){
		for(int j=1;j<=m;j++){
			int x=read();
			jiab(pos[i][j],pos[i+1][j],x);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<m;j++){
			int x=read();
			jiab(pos[i][j],pos[i][j+1],x);
		}
	}
//	cout<<"&&&";
	while(T--){
		solve();
	}
	return 0;
}

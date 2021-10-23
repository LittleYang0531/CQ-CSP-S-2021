#include<bits/stdc++.h>
using namespace std;
inline int in(){
	int x;
	scanf("%d",&x);
	return x;	
}
typedef long long ll;
const int N=505;
const ll inf=1e18;
int n,m,t;
int x1[N][N],x2[N][N];
int val[N][N][2];
ll f[19][1<<18],g[19][1<<18];
void solve(){
	int k=in();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			val[i][j][0]=val[i][j][1]=0;
	for(int i=1;i<=k;i++){
		int v=in(),p=in(),t=in();
		int x,y;
		if(p<=m)x=1,y=p;
		else if(p<=n+m)x=p-m,y=m;
		else if(p<=n+m+m)x=n,y=n+m+m-p+1;
		else x=n+n+m+m-p+1,y=1;
		val[x][y][t^1]+=v;
	}
	int tot=(1<<m)-1;
	for(int s=0;s<=tot;s++){
		f[1][s]=g[1][s];
		for(int i=0;i<m;i++){
			if(s&(1<<i))f[1][s]+=val[1][i+1][1];
			else f[1][s]+=val[1][i+1][0];
		}
	}
	for(int i=2;i<=n;i++){
		for(int s=0;s<=tot;s++)f[i][s]=f[i-1][s];
		for(int j=1,p=1;j<=tot;j<<=1,p++)
			for(int k=0;k<=tot;k++)
				f[i][k]=min(f[i][k],f[i][k^j]+x1[i-1][p]);
		for(int s=0;s<=tot;s++){
			f[i][s]=f[i][s]+g[i][s];
			if(s&1)f[i][s]+=val[i][1][1];
			else f[i][s]+=val[i][1][0];
			if(s&(1<<m-1))f[i][s]+=val[i][m][1];
			else f[i][s]+=val[i][m][0];
		}
	}
	ll ans=inf;
	for(int s=0;s<=tot;s++){
		for(int i=1;i<m-1;i++){
			if(s&(1<<i))f[n][s]+=val[n][i+1][1];
			else f[n][s]+=val[n][i+1][0];
		}
		ans=min(ans,f[n][s]);
	}
	cout<<ans<<endl;
}
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	n=in(),m=in(),t=in();
	if(n>18||m>18)return 0;
	for(int i=1;i<n;i++)
		for(int j=1;j<=m;j++)
			x1[i][j]=in();
	for(int i=1;i<=n;i++)
		for(int j=1;j<m;j++)
			x2[i][j]=in();
	int tot=(1<<m)-1;
	for(int i=1;i<=n;i++){
		for(int s=0;s<=tot;s++){
			for(int j=1;j<m;j++){
				int d1=s&(1<<j-1),d2=s&(1<<j);
				if((d1&&!d2)||(!d1&&d2))g[i][s]+=x2[i][j];
			}
		}
	}
	while(t--)solve();
	return 0;
}


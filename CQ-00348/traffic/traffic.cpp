#include<bits/stdc++.h>
#define ll long long
using namespace std;
ifstream in("traffic.in");
ofstream out("traffic.out");
//bool happy1041;
//ll time1=clock();
//
const ll N=500;
ll n,m,t,ans=1e9;
ll sside[N+10][N+10],hside[N+10][N+10],sx[4*N+10][3],mmap[N+10][N+10];
//
void dfs(ll x,ll y,ll lans){
	if(lans>=ans) return;
	if(y>m){
		ans=lans;
//		out<<lans<<endl;
		return;
	}
	ll tot0=0,tot1=0;
	mmap[x][y]=0;
	if(x>1){
		if(mmap[x-1][y]!=mmap[x][y]) tot0+=sside[x-1][y];
		else tot1+=sside[x-1][y];
	}
	if(y>1){
		if(mmap[x][y-1]!=mmap[x][y]) tot0+=hside[x][y-1];
		else tot1+=hside[x][y-1];
	}
	if(x==1&&sx[y][1]){
		if(sx[y][2]!=mmap[x][y]) tot0+=sx[y][1];
		else tot1+=sx[y][1];
	}
	if(x==n&&sx[n+m+m-y+1][1]){
		if(sx[n+m+m-y+1][2]!=mmap[x][y]) tot0+=sx[n+m+m-y+1][1];
		else tot1+=sx[n+m+m-y+1][1];
	}
	if(y==1&&sx[2*n+2*m-x+1][1]){
		if(sx[2*n+2*m-x+1][2]!=mmap[x][y]) tot0+=sx[2*n+2*m-x+1][1];
		else tot1+=sx[2*n+2*m-x+1][1];
	}
	if(y==m&&sx[m+x][1]){
		if(sx[m+x][2]!=mmap[x][y]) tot0+=sx[m+x][1];
		else tot1+=sx[m+x][1];
	}
	dfs(x+(x<n?1:-n+1),y+(x<n?0:1),lans+tot0);
	mmap[x][y]=1;
	dfs(x+(x<n?1:-n+1),y+(x<n?0:1),lans+tot1);
}
//
//bool Happy1041;
//void usage(){
//	ll time2=clock();
//	cout<<(&Happy1041-&happy1041)/1024/1024<<" Mb, "<<time2-time1<<" ms" ;
//}
int main(){
	in>>n>>m>>t;
	for(int i=1; i<n; ++i){
		for(int j=1; j<=m; ++j){
			in>>sside[i][j];
		}
	}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<m; ++j){
			in>>hside[i][j];
		}
	}
	for(int hp=1; hp<=t; ++hp){
		ll abn;
		in>>abn;
		memset(sx,0,sizeof(sx));
		for(int i=1; i<=abn; ++i){
			ll t1,t2,t3;
			in>>t1>>t2>>t3;
			sx[t2][1]=t1;
			sx[t2][2]=t3;
		}
		dfs(1,1,0);
		out<<ans<<endl;
	}
	return 0;
}


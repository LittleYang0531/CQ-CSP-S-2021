#include<bits/stdc++.h>
using namespace std;
# define ll long long
# define read read1<ll>()
# define Type template<typename T>
Type T read1(){
	T t=0;
	char k;
	bool vis=0;
	do (k=getchar())=='-'&&(vis=-1);while('0'>k||k>'9');
	while('0'<=k&&k<='9')t=(t<<3)+(t<<1)+(k^'0'),k=getchar();
	return vis?-t:t;
}
# define fre(k) freopen(k".in","r",stdin);freopen(k".out","w",stdout)
int n,m,T,a[4][505][505],vis[505][505],dis[2][505][505];
int tx[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
struct A{
	int x,y,v,c;
	A(int _x=0,int _y=0,int _v=0,int _c=0){x=_x;y=_y;v=_v;c=_c;}
	bool operator <(const A &b)const{return v<b.v;}
};
priority_queue<A>q;
bool judge(int _x,int _y){return 0<_x&&_x<=n&&0<_y&&_y<=m;}
int main(){fre("traffic");
	n=read,m=read,T=read;
	for(int i=1;i<n;++i)
		for(int j=1;j<=m;++j)
			a[0][i+1][j]=a[2][i][j]=read;
	for(int i=1;i<=n;++i)
		for(int j=1;j<m;++j)
			a[1][i][j+1]=a[3][i][j]=read;
	while(T--){
		memset(dis,0,sizeof(dis));
		memset(vis,-1,sizeof(vis));
		while(q.size())q.pop();
		for(int G=read;G--;){
			int v=read,w=read,c=read;
			int x,y;
			if(w<=m)x=0,y=w,a[2][x][y]=v;
			else if(w<=n+m)x=w-m,y=m+1,a[3][x][y-1]=v;
			else if(w<=n+2*m)x=n+1,y=w-n-m,y=m-y+1,a[2][x-1][y]=v;
			else x=w-m*2-n,x=n-x+1,y=0,a[3][x][y]=v;
			vis[x][y]=c;
			for(int i=0;i<4;++i){
				int ux=x+tx[i][0],uy=y+tx[i][1];
				if(judge(ux,uy)){
					dis[c][ux][uy]=v;
					q.push(A(ux,uy,v,c));
				}
			}
		}
		while(q.size()){
			while(q.size()&&~vis[q.top().x][q.top().y])q.pop();
			if(q.empty())break;
			A t=q.top();q.pop();
			vis[t.x][t.y]=t.c;
//			printf("%d::%d %d %d\n",t.x,t.y,t.v,t.c);
			for(int i=0;i<4;++i){
				int ux=t.x+tx[i][0],uy=t.y+tx[i][1];
				if(!~vis[ux][uy]&&judge(ux,uy)){
//					cout<<i<<" "<<t.x<<' '<<t.y<<' '<<a[i][t.x][t.y]<<"::\n";
					dis[t.c][ux][uy]+=a[i][t.x][t.y];
					q.push(A(ux,uy,dis[t.c][ux][uy],t.c));
				}
			}
//			for(int i=1;i<=n;++i)
//				for(int j=1;j<=m;++j)
//					printf("%d(%d,%d)%c",vis[i][j],dis[0][i][j],dis[1][i][j]," \n"[j==m]);
		}ll ans=0;
		for(int i=0;i<=n;++i)
			for(int j=0;j<=m;++j)
				if(~vis[i][j])
					for(int k=2;k<4;++k){
						int ux=i+tx[k][0],uy=j+tx[k][1];
						if(~vis[ux][uy]&&vis[i][j]!=vis[ux][uy])
							ans+=a[k][i][j];
					}
		cout<<ans<<endl;
	}
	return 0;
}


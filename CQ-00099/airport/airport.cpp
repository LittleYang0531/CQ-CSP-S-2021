#include<bits/stdc++.h>
using namespace std;
int read() {
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return s*w;
}
const int maxn = 110000;
struct info{
	int a,b;
};
bool cmp(info x,info y) {
	return x.a<y.a;
}
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
//堆q：按离开时间从小到大排序 
priority_queue<int,vector<int>,greater<int> >p;
//堆p：里面堆全是一定可以停的，按编号从小到大排序 
void slv(info*a,int*c,int n) {
	sort(a+1,a+1+n,cmp);
	while(!q.empty()) q.pop();
	while(!p.empty()) p.pop();
	int tot=0;
	for(int i=1,x;i<=n;i++) {
		while(!q.empty()&&q.top().first<a[i].a) p.push(q.top().second),q.pop();
		if(p.empty()) {
			x=++tot,++c[tot];
		} else ++c[x=p.top()],p.pop();
		q.push(make_pair(a[i].b,x));
	}
}
info a[2][maxn];
int c[2][maxn],n,m[2],ans;
signed main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(),m[0]=read(),m[1]=read();
	for(int i=1;i<=m[0];i++) a[0][i]=(info){read(),read()};
	for(int i=1;i<=m[1];i++) a[1][i]=(info){read(),read()};
	for(int i=0;i<2;i++) {
		slv(a[i],c[i],m[i]);
		for(int j=1;j<=n;j++) c[i][j]+=c[i][j-1];
	}
	for(int i=0;i<=n;i++) ans=max(ans,c[0][i]+c[1][n-i]);
	cout<<ans<<'\n';
	return 0;
}

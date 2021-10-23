#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int read() {
	int x=0,f=0;char ch=getchar();
	while(!isdigit(ch)) {if(ch=='-') f=1;ch=getchar();}
	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
const int N=100005;
int n,ma,mb,ta[N],tb[N],maxe,cnt,ans,suma,sumb,vv[N];
pii a[N*2],b[N*2];
//bool vis[N];
priority_queue<int,vector<int>,greater<int> > c,d;
map<int,int> id;
int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
//	scanf("%d%d%d",&n,&ma,&mb);
	n=read(),ma=read(),mb=read();
	int tot=0;
	for(int i=1,l,r;i<=ma;++i) {
//		scanf("%d%d",&l,&r);
		l=read(),r=read();
		id[l]=i,id[r]=i;
		a[++tot]=pii(l,0);
		a[++tot]=pii(r,1);
	}
	tot=0;
	for(int i=1,l,r;i<=mb;++i) {
//		scanf("%d%d",&l,&r);
		l=read(),r=read();
		id[l]=i,id[r]=i;
		b[++tot]=pii(l,0);
		b[++tot]=pii(r,1);
	}
	sort(a+1,a+1+ma*2);
	sort(b+1,b+1+mb*2);
	int x,y,z,idd;
	bool flag=0;
	for(int i=1;i<=2*ma;++i) {
		x=a[i].first,y=a[i].second,idd=id[x];
		if(y==0) {
			if(!c.empty()) z=c.top(),c.pop(),vv[idd]=z,++ta[z];
			else ++cnt,vv[idd]=cnt,++ta[cnt];
		}
		else {
			c.push(vv[idd]);
			if(vv[idd]==cnt) --cnt;
		}
	}
	cnt=0;
//	memset(vis,0,sizeof vis);
	memset(vv,0,sizeof vv);
	for(int i=1;i<=2*mb;++i) {
		x=b[i].first,y=b[i].second,idd=id[x];
		if(y==0) {
			if(!d.empty()) z=d.top(),d.pop(),vv[idd]=z,++tb[z];
			else ++cnt,vv[idd]=cnt,++tb[cnt];
		}
		else {
			d.push(vv[idd]);
			if(vv[idd]==cnt) --cnt;
		}
	}
	for(int i=0;i<=n;++i) sumb+=tb[i];
	for(int i=0;i<=n;++i) {
		suma+=ta[i],sumb-=(i==0?0:tb[n-i+1]);
		ans=max(ans,suma+sumb);
	}
	printf("%d",ans);
	return 0;
}
/*
3 5 4
1 5
3 8
6 10
9 14
13 18
2 11
4 15
7 17
12 16

7

2 4 6
20 30
40 50
21 22
41 42
1 19
2 18
3 4
5 6
7 8
9 10

4
*/

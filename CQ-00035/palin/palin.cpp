#include<queue>
#include<math.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll t,n,a[5000001],b[5000001],flg,c[50000001],tot,f[50000001],d[5000001];
inline void read(ll &x) {
	x=0;
	char c=getchar();
	ll p=1;
	while(c<48||c>57) {
		if(c==45)p-=2;
		c=getchar();
	}
	while(c>47&&c<58)x=(x<<3)+(x<<1)+(c^48),c=getchar();
	x*=p;
}
bool check(ll b[]) {
	for(ll i=1; i<=n; i++)
		if(b[i]!=b[2*n-i+1])return 0;
	return 1;
}
struct team {
	ll h,t,b[5000001],top,ch,id;
};
ll bfs() {
//	cout<<1<<' '<<top<<'\n';
//	cout<<2<<' '<<h<<' '<<t<<'\n';
	ll id=0;
	queue<team>q;
	q.push((team){1,2*n,0,0,0,++id});
	memcpy(q.front().b,b,sizeof(b));
	c[id]=0;
	while(q.size()) {
		ll h=q.front().h,t=q.front().t,b[5000001],top=q.front().top,idd=q.front().id;
		memcpy(b,q.front().b,sizeof(b));
		q.pop();
		if(top==2*n-1) {
			b[top+1]=a[h];
			if(check(b))flg=1;
			return idd;
		}
		if(a[h]<=a[t]) {
			b[top+1]=a[h];
			q.push((team){h+1,t,0,top+1,76,++id});
			memcpy(q.front().b,b,sizeof(b));
			c[id]='L';
			f[id]=idd;
			b[top+1]=a[t];
			q.push((team){h,t-1,0,top+1,82,++id});
			memcpy(q.front().b,b,sizeof(b));
			c[id]='R';
			f[id]=idd;
		} else {
			b[top+1]=a[t];
			q.push((team){h,t-1,0,top+1,82,++id});
			memcpy(q.front().b,b,sizeof(b));
			c[id]='R';
			f[id]=idd;
			b[top+1]=a[h];
			q.push((team){h+1,t,0,top+1,76,++id});
			memcpy(q.front().b,b,sizeof(b));
			c[id]='L';
			f[id]=idd;
		}
	}
}
int main() {
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	read(t);
	while(t--) {
		read(n);
		for(ll i=1; i<=2*n; i++)read(a[i]);
		flg=tot=0;
		ll k=bfs();
		if(flg) {
			for(ll i=k;i;i=f[i])d[++tot]=c[i];
			for(ll i=tot;i>0;i--)cout<<(char)d[i];
			puts("");
		} else puts("-1");
	}
	return 0;
}
/*RERERERERERERERERERERERE
QAQAQAQAQAQAQAQAQAQAQAQAQAQ

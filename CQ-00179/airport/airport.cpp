#include<bits/stdc++.h>
#define van long long
#define pii pair<int, int>
#define mp make_pair

using namespace std;

int read() {
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-') f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}

void put(int x) {
	if(x>=10) put(x/10);
	putchar(x%10+'0');
}

void putc(int x,char c) {
	put(x),putchar(c);
}

const int Maxn=1e5+11;
int n,m1,m2,res;
struct xx {
	int s,t;
	bool vis;
} a[Maxn],b[Maxn];
int ans[Maxn][2];

bool cmp(xx x,xx y) {
	if(x.s==y.s) return x.t<y.t;
	return x.s<y.s;
}
int wentad(int x,int l,int r) {
	a[x].vis=1;
	int to=0;
	for(int i=l; i<=r; i++) {
		if(a[i].s>=a[x].t) {
			to=i;
			break;
		}
	}
	if(to) res+=wentad(to,to+1,m1);
	return res;
}
int wenta(int x,int l,int r) {
	a[x].vis=1;
	int res=1,ck=0,to=0;
	while(l<=r) {
		int mid=(l+r)/2;
		if(a[mid].s>=a[x].t) r=mid-1,ck=mid;
		else l=mid+1;
	}
	while(a[ck-1].s>=a[x].t)ck--;
	for(int i=ck; i<=m1; i++) {
		if(!a[i].vis) {
			to=i;
			break;
		}
	}
	if(to) res+=wenta(to,to+1,m1);
	return res;
}
int wentb(int x,int l,int r) {
	b[x].vis=1;
	int res=1,ck=0,to=0;
	while(l<=r) {
		int mid=(l+r)/2;
		if(b[mid].s>=b[x].t) r=mid-1,ck=mid;
		else l=mid+1;
	}
	while(b[ck-1].s>=b[x].t)ck--;
	for(int i=ck; i<=m1; i++) {
		if(!b[i].vis) {
			to=i;
			break;
		}
	}
	if(to) res+=wentb(to,to+1,m2);
	return res;
}
int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(),m1=read(),m2=read();
	for(int i=1; i<=m1; i++) a[i].s=read(),a[i].t=read();
	for(int i=1; i<=m2; i++) b[i].s=read(),b[i].t=read();
	sort(a+1,a+m1+1,cmp),sort(b+1,b+m2+1,cmp);
	int p=1;
	for(int i=1; i<=n; i++) {
		for(; p<=m1; p++) {
			if(a[p].vis) continue;
			ans[i][0]=wenta(p,p+1,m1);
			break;
		}
		ans[i][0]+=ans[i-1][0];
	}
	p=1;
	for(int i=1; i<=n; i++) {
		for(; p<=m2; p++) {
			if(b[p].vis) continue;
			ans[i][1]=wentb(p,p+1,m2);
			break;
		}
		ans[i][1]+=ans[i-1][1];
	}
	for(int i=0; i<=n; i++)
		res=max(res,ans[i][0]+ans[n-i][1]);
	cout<<res;
	return 0;
}

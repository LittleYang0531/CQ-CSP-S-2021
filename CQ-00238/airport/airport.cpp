#include<bits/stdc++.h>
#define N 200005
using namespace std;
int n,m1,m2,n1[N],n2[N],ans,p1[N],p2[N];
priority_queue<int,vector<int>,greater<int> >q1,q2;
struct node {
	int t,pos;
} a[N],b[N];
inline int read() {
	int f=0,s=0;
	char ch=getchar();
	while(ch<48||ch>57)f|=(ch=='-'),ch=getchar();
	while(ch>47&&ch<58)s=(s<<1)+(s<<3)+(ch^48),ch=getchar();
	return f?-s:s;
}
bool cmp(node x,node y) {return x.t<y.t;}
int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(),m1=read(),m2=read();
	for(int i=1; i<=m1; ++i)a[i].t=read(),a[i].pos=i,a[i+m1].t=read(),a[i+m1].pos=-i;
	for(int i=1; i<=m2; ++i)b[i].t=read(),b[i].pos=i,b[i+m2].t=read(),b[i+m2].pos=-i;
	sort(a+1,a+2*m1+1,cmp),sort(b+1,b+2*m2+1,cmp);
	for(int i=1; i<=n; ++i)q1.push(i),q2.push(i);
	for(int i=1; i<=2*m1; ++i) {
		if(a[i].pos>0) {
			if(q1.empty())continue;
			int x=q1.top();q1.pop();
			++n1[p1[a[i].pos]=x];
		} else if(p1[-a[i].pos])q1.push(p1[-a[i].pos]);
	}
	for(int i=1; i<=2*m2; ++i) {
		if(b[i].pos>0) {
			if(q2.empty())continue;
			int x=q2.top();q2.pop();
			++n2[p2[b[i].pos]=x];
		} else if(p2[-b[i].pos])q2.push(p2[-b[i].pos]);
	}
	for(int i=1; i<=n; ++i)n1[i]+=n1[i-1],n2[i]+=n2[i-1];
	for(int i=0; i<=n; ++i)ans=max(ans,n1[i]+n2[n-i]);
	cout<<ans;
	return 0;
}

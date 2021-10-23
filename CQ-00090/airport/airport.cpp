#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define maxn 100005
using namespace std;
template <typename T> void read(T &x) {
	x=0;
	char c=getchar();
	for (; !isdigit(c); c=getchar());
	for (; isdigit(c); c=getchar()) x=x*10+c-'0';
}
struct node {
	int a1,b1;
} q[maxn];
struct node1 {
	int a2,b2;
} q1[maxn];
int n,m1,m2;
bool cmp(const node &x,const node &y) {
	return x.a1<y.a1;
}
bool cmp1(const node1 &x,const node1 &y) {
	return x.a2<y.a2;
}
int endd[maxn],endd1[maxn],ans,maxx=-10000;
int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	read(n),read(m1),read(m2);
	int ans=m1;
	for (int i=1; i<=m1; ++i) {
		read(q[i].a1),read(q[i].b1);
	}
	sort(q+1,q+1+m1,cmp);
	for (int i=1; i<=m2; ++i) {
		read(q1[i].a2),read(q1[i].b2);
	}
	sort(q1+1,q1+1+m2,cmp1);
	for (int T=0; T<=n; ++T) {
		ans=0;
		int m1lq=T,m2lq=n-T;
		memset(endd1,0,sizeof(endd1));
		memset(endd,0,sizeof(endd));
		for (int i=1; i<=m1; ++i) {
			for (int j=1; j<=m1lq; ++j) {
				if (endd[j]!=0) {
					endd[j]=endd[j]-q[i].a1+q[i-1].a1;
					if (endd[j]<0) endd[j]=0;
				}
			}
			for (int j=1; j<=m1lq; ++j) {
				if (endd[j]==0) {
					ans++;
					endd[j]=q[i].b1-q[i].a1;
					break;
				}
			}
		}
		for (int i=1; i<=m2; ++i) {
			for (int j=1; j<=m2lq; ++j) {
				if (endd1[j]!=0) {
					endd1[j]=endd1[j]-q1[i].a2+q1[i-1].a2;
					if (endd1[j]<0) endd1[j]=0;
				}
			}
			for (int j=1; j<=m2lq; ++j) {
				if (endd1[j]==0) {
					ans++;
					endd1[j]=q1[i].b2-q1[i].a2;
					break;
				}
			}
		}
		maxx=max(maxx,ans);
	}
	printf("%d",maxx);
	return 0;
}
//CSP-S AK ME

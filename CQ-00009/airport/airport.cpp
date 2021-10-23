#include<bits/stdc++.h>
#define N 100005
using namespace std;
int n,m1,m2,Max;
priority_queue<int,vector<int>,greater<int> >q;
struct P {
	int b,e;
}a[N],b[N];
bool cmp(P x,P y) {
	return x.b<=y.b;
}
int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d %d %d",&n,&m1,&m2);
	for (int i=1;i<=m1;i++) scanf("%d %d",&a[i].b,&a[i].e);
	for (int i=1;i<=m2;i++) scanf("%d %d",&b[i].b,&b[i].e);
	sort(a+1,a+m1+1,cmp);
	sort(b+1,b+m2+1,cmp);
	for (int u=0;u<=n;u++) {
		int now=u,ans=0;
		for (int i=1;i<=m1;i++) {
			while (!q.empty()&&q.top()<a[i].b) {
				q.pop();
				now++;
			}
			if (now) {
				q.push(a[i].e);
				now--,ans++;
			}
		}
		while(!q.empty()) q.pop();
		now=n-u;
		for (int i=1;i<=m2;i++) {
			while (!q.empty()&&q.top()<b[i].b) {
				q.pop();
				now++;
			}
			if (now) {
				q.push(b[i].e);
				now--,ans++;
			}
		}
		while(!q.empty()) q.pop();
		Max=max(Max,ans);
	}
	printf("%d",Max);
	return 0;
}

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=1e5+5;
struct point {
	int x,y;
};
point a[MAXN];
bool operator<(const point &a,const point &b) {
	return a.x<b.x;
}
struct po {
	int time,lang;
};
bool operator<(const po &a,const po &b) {
	return a.time>b.time;
}
int a1[MAXN],a2[MAXN];
int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m1,m2;
	cin>>n>>m1>>m2;
	for(int i=1; i<=m1; i++)scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+1+m1);
	priority_queue<int,vector<int>,greater<int> >lang;
	priority_queue<po>q;
	for(int i=1; i<=m1; i++)lang.push(i);
	for(int i=1; i<=m1; i++) {
		while(!q.empty()) {
			if(q.top().time<a[i].x) {
				lang.push(q.top().lang);
				q.pop();
			} else break;
		}
		int x=lang.top();
		lang.pop();
		a1[x]++;
		q.push({a[i].y,x});
	}
	for(int i=1; i<=n; i++)a1[i]+=a1[i-1];
	while(!lang.empty())lang.pop();
	for(int i=1; i<=m2; i++)lang.push(i);
	while(!q.empty())q.pop();
	for(int i=1; i<=m2; i++)scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+1+m2);
	for(int i=1; i<=m2; i++) {
		while(!q.empty()) {
			if(q.top().time<a[i].x) {
				lang.push(q.top().lang);
				q.pop();
			} else break;
		}
		int x=lang.top();
		lang.pop();
		a2[x]++;
		q.push({a[i].y,x});
	}
	for(int i=1; i<=n; i++)a2[i]+=a2[i-1];
	int ans=0;
	for(int i=0; i<=n; i++)ans=max(ans,a1[i]+a2[n-i]);
	cout<<ans<<endl;
	return 0;
}

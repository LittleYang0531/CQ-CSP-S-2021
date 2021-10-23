#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int read() {
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x*f;
}
int n,m1,m2,cnt1[maxn],cnt2[maxn],ans;
struct node {
	int l,r;
	friend bool operator<(const node a,const node b) {
		return a.l<b.l;
	}
} p[maxn],q[maxn];
struct qe {
	int v,id;
	qe(int v,int id) {
		this->v=v,this->id=id;
	}
	friend bool operator<(const qe a,const qe b) {
		return a.v>b.v;
	}
};
priority_queue<qe> q1;
priority_queue<int,vector<int>,greater<int> > q2;
int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(),m1=read(),m2=read();
	for(int i=1; i<=m1; i++)p[i].l=read(),p[i].r=read(),q2.push(i);
	sort(p+1,p+m1+1);
	for(int i=1; i<=m1; i++) {
		while(!q1.empty()&&q1.top().v<p[i].l) {
			q2.push(q1.top().id);
			q1.pop();
		}
		int id=q2.top();
		q2.pop();
		cnt1[id]++,q1.push(qe(p[i].r,id));
	}
	while(!q1.empty())q1.pop();
	while(!q2.empty())q2.pop();
	for(int i=1; i<=m2; i++)q[i].l=read(),q[i].r=read(),q2.push(i);
	sort(q+1,q+m2+1);
	for(int i=1; i<=m2; i++) {
		while(!q1.empty()&&q1.top().v<q[i].l) {
			q2.push(q1.top().id);
			q1.pop();
		}
		int id=q2.top();
		q2.pop();
		cnt2[id]++,q1.push(qe(q[i].r,id));
	}
	for(register int i=1; i<=n; i++)cnt1[i]+=cnt1[i-1];
	for(register int i=1; i<=n; i++)cnt2[i]+=cnt2[i-1];
	for(register int i=0; i<=n; i++)ans=max(ans,cnt1[i]+cnt2[n-i]);
	printf("%d",ans);
	return 0;
}
//你是一个一个一个，一个一个一个哼哼啊啊啊啊啊啊啊啊啊啊啊啊啊1145141919810

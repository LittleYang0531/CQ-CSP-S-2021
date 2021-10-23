//fuckccf
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
inline int rd() {
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0')
		x=(x<<3)+(x<<1)+c-48,c=getchar();
	return x*f;
}
int n,m1,m2,ans;
struct tim {
	int start,end;
} a[100005],b[100005];
struct tie {
	int start,end;
	bool operator < (const tie &a)const {
		return end>a.end;
	}
} ta[100005],tb[100005];
int check(int x) {
	priority_queue<tie > p;
	int y=n-x,wans=0,k=0,t=1;
	for(int i=ta[1].start,num=1; num<=m1; i=ta[++num].start) {
		
		if(k<x) {
			wans++;
			p.push(ta[num]);
			k++;
//			printf("%d ",i);
		}if(p.size())
			while(p.top().end<i&&k>0) {
				k--;
				p.pop();
			}
	}
//	cout<<1;
//	puts("");
	k=0;
	t=1;
	priority_queue<tie >q;
	for(int i=tb[1].start,num=1; num<=m2; i=tb[++num].start) {
		
		if(k<y) {
			wans++;
			q.push(tb[num]);
			k++;
//			printf("%d ",i);
		}if(q.size())
			while(q.top().end<i&&k>0) {
				k--;
				q.pop();
			}
	}
//	puts("");
	if(ans<wans) {
		ans=wans;
//		printf("%d",wans);
		return 1;
	}
	return 0;
}
bool cmp(const tim &a,const tim &b) {
	return a.start<b.start;
}
int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=rd(),m1=rd(),m2=rd();
	for(int i=1; i<=m1; i++)
		a[i].start=rd(),a[i].end=rd();
	sort(a+1,a+1+m1,cmp);
	for(int i=1; i<=m2; i++)
		b[i].start=rd(),b[i].end=rd();
	sort(b+1,b+1+m2,cmp);
	for(int i=1; i<=m1; i++)
		ta[i].end=a[i].end,ta[i].start=a[i].start;
	for(int i=1; i<=m2; i++)
		tb[i].end=b[i].end,tb[i].start=b[i].start;
//	check(2);
//	printf("%d",ans);
	int l=1,r=n;
	while(l<r) {
		int mid=(l+r)>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	printf("%d",ans);
	return 0;
}

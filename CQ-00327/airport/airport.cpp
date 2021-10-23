#include<bits/stdc++.h>
using namespace std;
const int M=1e5+1,MAX=0x7fffffff/2;
priority_queue<int, vector<int>, greater<int> > q1,q2;
int n,m1,m2;
int lm,mx,rm;
int Max=-1;
struct node1 {
	int a1,a2;
}e1[M];
struct node2 {
	int b1,b2;
}e2[M];
int cmp1(node1 x,node1 y) {
	return x.a1<y.a1;
}
int cmp2(node2 x,node2 y) {
	return x.b1<y.b1;
}
int check(int x) {
	int y=n-x;
//	printf("%d %d\n",x,y);
	int t,cnt1,cnt2,v;
	t=v=0;
	cnt1=cnt2=1;
	while (t<=Max) {
		t++;
		if(t==e1[cnt1].a1) {
			if(x>=1) {
				v++;
				x--;
				q1.push(e1[cnt1].a2);
//				cout<<t<<"!1   ";
			}
			cnt1++;
		}
		if(t==e2[cnt2].b1) {
			if(y>=1) {
				v++;
				y--;
				q2.push(e2[cnt2].b2);
//				cout<<t<<"!2   ";
			}
			cnt2++;
		}
		if(!q1.empty()&&t==q1.top()) x++,q1.pop();
		if(!q2.empty()&&t==q2.top()) y++,q2.pop();
	}
	return v;
}
int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d %d %d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++) scanf("%d %d",&e1[i].a1,&e1[i].a2),Max=max(Max,e1[i].a2);
	for(int i=1;i<=m2;i++) scanf("%d %d",&e2[i].b1,&e2[i].b2),Max=max(Max,e2[i].b2);
	sort(e1+1,e1+m1+1,cmp1);
	sort(e2+1,e2+m2+1,cmp2);
//	for(int i=1;i<=m1;i++) printf("%d %d\n",e1[i].a1,e1[i].a2);
	int l=0,r=n,mid,lm,rm,lx=-1,rx=-1,mx=-1;
	int ans;
	int zy=max(check(l),check(r));
	while (l<r) {
		mid=(l+r+1)>>1,lm=(l+mid+1)>>1,rm=(mid+r+1)>>1;
//		printf("%d %d %d %d %d\n",lm,mid,rm,l,r);
		lx=max(lx,check(lm));
		mx=max(mx,check(mid));
		rx=max(rx,check(rm));
//		printf("%d %d %d\n",lx,mx,rx);
//		if(lm==mid&&mid==rm) break;
		if(lx>=mx&&lx>=rm) r=mid;
		if(mx>=lx&&mx>=rm) l=lm,r=rm;
		if(rx>=mx&&rx>=lm) l=mid;
		ans=max(max(mx,zy),max(lx,rx));
	}
	ans=max(mx,max(lx,rx));
	printf("%d",ans);
//	cout<<"\n\n"<<check(2);
	return 0;
}

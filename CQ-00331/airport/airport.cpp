#include<bits/stdc++.h>
using namespace std;

struct node{int s,t;} p1[100005],p2[100005];
inline bool cmp(node x,node y){return x.s<y.s;}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m1,m2;
	scanf("%d %d %d",&n,&m1,&m2);
	for(int i=1;i<=m1;++i)scanf("%d %d",&p1[i].s,&p1[i].t);
	for(int i=1;i<=m2;++i)scanf("%d %d",&p2[i].s,&p2[i].t);
	sort(p1+1,p1+m1+1,cmp);
	sort(p2+1,p2+m2+1,cmp);
	int ans=0;
	priority_queue<int,vector<int>,greater<int> > Q;
	for(int d1=0;d1<=n;++d1){
		int d2=n-d1,tot=0;
		while(Q.size())Q.pop();
		for(int i=1;i<=d1;++i)Q.push(0);
		for(int i=1;i<=m1;++i){
			if(Q.size()&&Q.top()<p1[i].s)Q.pop(),Q.push(p1[i].t),++tot;
		}
		while(Q.size())Q.pop();
		for(int i=1;i<=d2;++i)Q.push(0);
		for(int i=1;i<=m1;++i){
			if(Q.size()&&Q.top()<p2[i].s)Q.pop(),Q.push(p2[i].t),++tot;
		}
		ans=max(ans,tot);
	}
	printf("%d",ans);
	return 0;
}


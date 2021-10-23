#include<bits/stdc++.h>
using namespace std;
int f[2][100005],c[100005],d[100005],ans,n,m1,m2,LR;
struct A{
	int l,r;
}a[100005],b[100005];
bool cmp(A x,A y){return x.l<y.l;}
priority_queue<int,vector<int>,greater<int> >Q[100005];
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	if(n>m1+m2)return cout<<m1+m2,0;
	for(int i=1;i<=m1;++i){
		scanf("%d%d",&a[i].l,&a[i].r);
	}
	for(int i=1;i<=m2;++i){
		scanf("%d%d",&b[i].l,&b[i].r);
	}
	sort(a+1,a+m1+1,cmp);
	sort(b+1,b+m2+1,cmp);
	for(int i=1;i<=m1;++i){
		for(int j=1;j<=n&&j<=m1;++j){
			while(Q[j].size()&&Q[j].top()<a[i].l)Q[j].pop();
			if(Q[j].size()<j)++f[0][j],Q[j].push(a[i].r);
		}
	}
	for(int i=1;i<n;++i)while(Q[i].size())Q[i].pop();
	for(int i=1;i<=m2;++i){
		for(int j=1;j<=n&&j<=m2;++j){
			while(Q[j].size()&&Q[j].top()<b[i].l)Q[j].pop();
			if(Q[j].size()<j)++f[1][j],Q[j].push(b[i].r);
		}
	}
	for(int i=0;i<=n;++i){
		ans=max(ans,f[0][i]+f[1][n-i]);
	}
	cout<<ans;
	return 0;
}

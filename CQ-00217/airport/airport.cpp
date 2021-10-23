#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn=100003;
priority_queue<int>q;
int n,m1,m2,tim[maxn],ans;
struct node{int l,r;}a[maxn],b[maxn];
bool cmp(node x,node y){return x.l<y.l;}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;++i) scanf("%d%d",&a[i].l,&a[i].r);sort(a+1,a+m1+1,cmp);
	for(int i=1;i<=m2;++i) scanf("%d%d",&b[i].l,&b[i].r);sort(b+1,b+m2+1,cmp);
	for(int k=0,num;num=0,k<=n;++k){
		if(k!=0){
			while(!q.empty()) q.pop();for(int i=1;i<=k;++i) q.push(0);
			for(int i=1;i<=m1;++i){
				int x=-q.top();
				if(a[i].l>x) ++num,q.pop(),q.push(-a[i].r);
			}
		}
		if(k!=n){
			while(!q.empty()) q.pop();for(int i=k+1;i<=n;++i) q.push(0);
			for(int i=1;i<=m2;++i){
				int x=-q.top();
				if(b[i].l>x) ++num,q.pop(),q.push(-b[i].r);
			}
		}ans=max(ans,num);
	}cout<<ans<<'\n';
	return 0;
}
/*
3 5 4
1 5
3 8
6 10
9 14
13 18
2 11
4 15
7 17
12 16
--------------
2 4 6
20 30
40 50
21 22
41 42
1 19
2 18
3 4
5 6
7 8
9 10

*/

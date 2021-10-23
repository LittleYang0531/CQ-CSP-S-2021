#include<bits/stdc++.h>
using namespace std;
struct bb{
	int s,e;
}a[100005],b[100005];
bool cmp(bb x,bb y){
	return x.s<y.s;
}
int n,m1,m2,q[100005],l,r;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++){
		scanf("%d%d",&a[i].s,&a[i].e);
	}
	sort(a+1,a+m1+1,cmp);
	for(int i=1;i<=m2;i++){
		scanf("%d%d",&b[i].s,&b[i].e);
	}
	sort(b+1,b+m2+1,cmp);
	int ans=0;
	for(int x=0;x<=n;x++){
		int y=n-x,sum=0,u=0,l=1,r=0;
		priority_queue<int,vector<int>,greater<int> > q1,q2;
		for(int i=1;i<=m1;i++){
			while(!q1.empty()&&q1.top()<a[i].s){
				q1.pop();
				u--;
			}
			if(u<x){
				q1.push(a[i].e);
				sum++;
				u++;
			}
		}
		l=1,r=0,u=0;
		for(int i=1;i<=m2;i++){
			while(!q2.empty()&&q2.top()<b[i].s){
				q2.pop();
				u--;
			}
			if(u<y){
				q2.push(b[i].e);
				sum++;
				u++;
			}
		}
		ans=max(ans,sum);
	}
	printf("%d\n",ans);
	return 0;
}
/*
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

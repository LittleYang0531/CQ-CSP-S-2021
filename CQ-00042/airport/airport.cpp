#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
struct plane{
	int come,leave;
}a[maxn],b[maxn];
bool operator<(plane a,plane b){
	return a.leave>b.leave;
}
priority_queue<plane> q;
int ans,n,m1,m2;
bool cmp(plane a,plane b);
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++){
		scanf("%d%d",&a[i].come,&a[i].leave);
	}
	sort(a+1,a+1+m1,cmp);
	for(int i=1;i<=m2;i++){
		scanf("%d%d",&b[i].come,&b[i].leave);
	}
	sort(b+1,b+1+m2,cmp);
	for(int i=0;i<=n;i++){
		int k=n-i,sum=0,all=0;
		for(int j=1;j<=m1;j++){
			if(!q.empty()){
				plane x=q.top();
				if(x.leave<=a[j].come){
					sum--;
					q.pop();
				}
			}
			if(sum<i){
				sum++,all++;
				q.push(a[j]);
			}
		}
		while(!q.empty())q.pop();
		sum=0;
		for(int j=1;j<=m2;j++){
			if(!q.empty()){
				plane x=q.top();
				if(x.leave<=b[j].come){
					sum--;
					q.pop();
				}
			}
			if(sum<k){
				sum++,all++;
				q.push(b[j]);
			}
		}
		ans=max(ans,all);
		while(!q.empty())q.pop();
	}
	cout<<ans;
	return 0;
}
bool cmp(plane a,plane b){
	return a.come<b.come;
}

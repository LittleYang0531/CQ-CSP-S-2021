#include<bits/stdc++.h>
using namespace std;
int n,m1,m2,tot,sum;
struct name{
	int a,b;
};
int cmp(name x,name y){
	return x.a<y.a;
}
priority_queue<int,vector<int>,greater<int> > q;
name a[100005],b[100005];
int work(int x){
	tot=0,sum=0;
	while(!q.empty()) q.pop();
	for(int i=1;i<=m1;i++){
		if(tot>=x){
			if(q.empty()) break;
			if(q.top()>=a[i].a){
				continue;
			}
			while(!q.empty()&&q.top()<a[i].a){
				tot--;
				q.pop();
			}
		}
		if(tot<x){
//			cout<<i<<" ";
			tot++;
			sum++;
			q.push(a[i].b);
		}
	}
//	cout<<" "; 
//	cout<<sum<<" ";
	while(!q.empty()) q.pop();
	tot=0;
	int ssum=sum;
	for(int i=1;i<=m2;i++){
		if(tot>=n-x){
			if(q.empty()) break;
			if(q.top()>=b[i].a){
				continue;
			}
			while(!q.empty()&&q.top()<b[i].a){
				tot--;
				q.pop();
			}
		}
		if(tot<n-x){
//			cout<<i<<' ';
			tot++;
			sum++;
			q.push(b[i].b);
//			cout<<b[i].b<<" "<<q.top()<<" "; 
		}
	}
//	cout<<sum-ssum<<" "; 
	while(!q.empty()) q.pop();
	return sum;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++){
		cin>>a[i].a>>a[i].b;
	}
	sort(a+1,a+m1+1,cmp);
	for(int i=1;i<=m2;i++){
		cin>>b[i].a>>b[i].b;
	}
	sort(b+1,b+m2+1,cmp);
//	for(int i=1;i<=m2;i++){
//		cout<<b[i].a<<" "<<b[i].b<<endl;
//	}
	int ans=0;
	for(int i=0;i<=n;i++){
		ans=max(ans,work(i));
//		cout<<work(i)<<endl;
//		work(i);
	}
	cout<<ans;
}

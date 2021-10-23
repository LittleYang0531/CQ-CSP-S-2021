#include<bits/stdc++.h>
using namespace std;
int n,m1,m2,ans1[100005],ans2[100005],ans;
struct node{
	int a,b;
	bool operator<(const node &t)const{
		return a<t.a;
	}
}arr[100005],aee[100005];
struct Node{
	int x,id;
	bool operator<(const Node &t)const{
		return x>t.x;
	}
};
priority_queue<Node>q;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)scanf("%d%d",&arr[i].a,&arr[i].b);
	for(int i=1;i<=m2;i++)scanf("%d%d",&aee[i].a,&aee[i].b);
	sort(arr+1,arr+m1+1);
	sort(aee+1,aee+m2+1);
	int tot1=0;
	for(int i=1;i<=m1;i++){
		queue<Node>Q;
		while(!q.empty()&&q.top().x>arr[i].a){
			Q.push(q.top());
			q.pop();
		}
		if(q.empty()){
			Node d;
			d.id=++tot1;
			d.x=arr[i].b;
			q.push(d);
			while(!Q.empty()){
				q.push(Q.front());
				Q.pop();
			}
			ans1[tot1]=i;
		}
		else{
			Node d=q.top();
			q.pop();
			d.x=arr[i].b;
			q.push(d);
			while(!Q.empty()){
				q.push(Q.front());
				Q.pop();
			}
			for(int j=d.id;j<=tot1;j++)ans1[j]++;
		}
	}
	int tot2=0;
	while(!q.empty())q.pop();
	for(int i=1;i<=m2;i++){
		queue<Node>Q;
		while(!q.empty()&&q.top().x>aee[i].a){
			Q.push(q.top());
			q.pop();
		}
		if(q.empty()){
			Node d;
			d.id=++tot2;
			d.x=aee[i].b;
			ans2[tot2]=i;
			q.push(d);
			while(!Q.empty()){
				q.push(Q.front());
				Q.pop();
			}
		}
		else{
			Node d=q.top();
			q.pop();
			d.x=aee[i].b;
			q.push(d);
			while(!Q.empty()){
				q.push(Q.front());
				Q.pop();
			}
			for(int j=d.id;j<=tot2;j++)ans2[j]++;
		}
	}
	for(int i=1;i<=tot1;i++)cerr<<ans1[i]<<' ';
	cerr<<endl;
	for(int i=1;i<=tot2;i++)cerr<<ans2[i]<<' ';
	cerr<<endl;
	for(int i=0;i<=min(n,tot1);i++){
		int j=min(tot2,n-i);
		ans=max(ans1[i]+ans2[j],ans);
	}
	for(int j=0;j<=min(n,tot2);j++){
		int i=min(tot1,n-j);
		ans=max(ans,ans1[i]+ans2[j]);
	}
	printf("%d",ans);
	return 0;
}

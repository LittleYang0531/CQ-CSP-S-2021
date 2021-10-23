#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
struct node{
	int f,s;
}arr[100005],brr[100005];
int k,n,m;
priority_queue<int> q;
int f1[100005],f2[100005],tot;
bool cmp(node x,node y){
	return x.f<y.f;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&k,&n,&m);
	for(int i=1;i<=n;i++)scanf("%d%d",&arr[i].f,&arr[i].s);
	for(int i=1;i<=m;i++)scanf("%d%d",&brr[i].f,&brr[i].s);
	sort(arr+1,arr+1+n,cmp);
	sort(brr+1,brr+1+m,cmp);
	for(int i=1;i<=k;i++){
		tot=0;
		int sum=0;
		for(int j=1;j<=m;j++){
		if(q.empty()){
			q.push(-brr[j].s);
			tot++;
			sum++;
		}
		else if(-q.top()<brr[j].f){
			q.pop();
			q.push(-brr[j].s);
			sum++;
		}
		else{
			if(tot<i){
				q.push(-brr[j].s);
				tot++;
				sum++;
			}
		}
	}f1[i]=sum;
	}
	for(int i=1;i<=k;i++){
		tot=0;
		int sum=0;
		while(!q.empty())q.pop();
		for(int j=1;j<=n;j++){
		if(q.empty()){ 
			q.push(-arr[j].s);
			tot++;
			sum++;
		}
		else if(-q.top()<arr[j].f){
			q.pop();
			q.push(-arr[j].s);
			sum++;
		}
		else{
			if(tot<i){
				q.push(-arr[j].s);
				tot++;
				sum++;
			}
		}
	}f2[i]=sum;
	}
	int ans=0;
	for(int i=0;i<=k;i++)ans=max(ans,f1[i]+f2[k-i]);
	printf("%d",ans);
	return 0;
}

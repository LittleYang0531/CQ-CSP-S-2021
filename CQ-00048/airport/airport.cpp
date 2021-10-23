#include<bits/stdc++.h>
using namespace std;
struct node{
	int S,E;
};
node a[100003],b[100003];
int Sum[100003],Sum1[100003],n,m1,m2;
bool use[100003],use1[100003];
bool cmp(node a,node b){
	return a.S<b.S;
}
bool operator<(node a,node b){
	return a.E>b.E;
}
priority_queue <node> q;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
    if(n<=5000){
    	for(int i=1;i<=m1;i++)scanf("%d%d",&a[i].S,&a[i].E);
    for(int i=1;i<=m2;i++)scanf("%d%d",&b[i].S,&b[i].E);
    sort(a+1,a+m1+1,cmp);
    sort(b+1,b+m2+1,cmp);
    for(int i=1;i<=n;i++){
    	while(!q.empty())q.pop();
    	int cnt=0;
    	for(int j=1;j<=m1;j++){
    		while(q.size()&&q.top().E<=a[j].S)q.pop();
    		if(q.size()<i)q.push(a[j]),++cnt;
		}
		Sum[i]=cnt;
		while(!q.empty())q.pop();
		cnt=0;
		for(int j=1;j<=m2;j++){
    		while(q.size()&&q.top().E<=b[j].S)q.pop();
    		if(q.size()<i)q.push(b[j]),++cnt;
		}
		Sum1[i]=cnt;
	}
    int maxn=0;
    for(int i=0;i<=n;i++)maxn=max(maxn,Sum[i]+Sum1[n-i]);
    cout<<maxn;
	}else{
	set <int> q1,q2,q3,q4;
	map <int,int> qq,qq1;
	for(int i=1;i<=m1;i++)scanf("%d%d",&a[i].S,&a[i].E),q1.insert(a[i].S),q2.insert(-a[i].S);
    for(int i=1;i<=m2;i++)scanf("%d%d",&b[i].S,&b[i].E),q3.insert(b[i].S),q4.insert(-b[i].S);
    sort(a+1,a+m1+1,cmp);
    sort(b+1,b+m2+1,cmp);
    for(int i=1;i<=m1;i++)qq[a[i].S]=i;
    for(int i=1;i<=m2;i++)qq1[b[i].S]=i;
    int cnt=0,j=1;
	for(int i=1;cnt<m1;++i){
		int cnt1=0;
		for(;j<=m1;j++)
		if(!use[j])break;
		q1.erase(a[j].S);q2.erase(-a[j].S);
		for(int k=j;k<=m1;){
			++cnt1,use[k]=1;
			if(-(*q2.begin())<=a[k].E)break;
			int now= *q1.lower_bound(a[k].E);
			int now1=qq[now];
			q1.erase(a[now1].S);q2.erase(-a[now1].S);
			k=now1;
		}
		Sum[i]=cnt1;
		cnt+=cnt1;
	}
	cnt=0,j=1;
	for(int i=1;cnt<m2;++i){
		int cnt1=0;
		for(;j<=m2;j++)
		if(!use1[j])break;
		q3.erase(b[j].S);q4.erase(-b[j].S);
		for(int k=j;k<=m2;){
			++cnt1,use1[k]=1;
			if(-(*q4.begin())<=b[k].E)break;
			int now= *q3.lower_bound(b[k].E);
			int now1=qq1[now];
			q3.erase(b[now1].S);q4.erase(-b[now1].S);
			k=now1;
		}
		Sum1[i]=cnt1;
		cnt+=cnt1;
	}
	for(int i=1;i<=n;i++)Sum[i]+=Sum[i-1],Sum1[i]+=Sum1[i-1];
    int maxn=0;
    for(int i=0;i<=n;i++)maxn=max(maxn,Sum[i]+Sum1[n-i]);
    cout<<maxn;
	}
	return 0;
}

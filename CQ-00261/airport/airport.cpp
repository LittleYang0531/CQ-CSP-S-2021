#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m1,m2,ans=-1,maxt;
struct node{
	int l,r;
}a[100005],b[100005];
bool visa[100005],visb[100005];
int work(int t1){
	deque <node>q1,q2;
	int ans1=0,ans2=0,t2=n-t1,size1=0,size2=0;
	for(int i=1;i<=m1;i++){
		while(!q1.empty()&&q1.front().r<a[i].l)q1.pop_front(),size1--;
		while(!q1.empty()&&q1.back().r<a[i].l)q1.pop_back(),size1--;
		if(size1<t1)q1.push_back(a[i]),ans1++,size1++;
	}
	for(int i=1;i<=m2;i++){
		while(!q2.empty()&&q2.front().r<b[i].l)q2.pop_front(),size2--;
		while(!q2.empty()&&q2.back().r<b[i].l)q2.pop_back(),size2--;
		if(size2<t2)q2.push_back(b[i]),ans2++,size2++;
	}
	return ans1+ans2;
}
bool cmp(node x,node y){
	return x.l<y.l;
}
signed main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++){
		cin>>a[i].l>>a[i].r;
		if(a[i].r>maxt)maxt=a[i].r;
	}
	for(int i=1;i<=m2;i++){
		cin>>b[i].l>>b[i].r;
		if(b[i].r>maxt)maxt=b[i].r;
	}
	sort(a+1,a+m1+1,cmp);
	sort(b+1,b+m2+1,cmp);
	int mans;
	for(int i=0;i<=n;i++){
		ans=max(ans,work(i));
	}
	cout<<ans;
	return 0;
}

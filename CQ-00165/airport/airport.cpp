#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
int n,m1,m2;
pii a1[100010],a2[100010];
pii ok[100010];
int answ;
int ins(int x){
	if(x==0||m1==0){
		return 0;
	}
	priority_queue <int,vector<int>,greater<int> > q;
	while(!q.empty()){
		q.pop();
	}
	int ans=1;
	int smaller=a1[1].second;
	int sum=1;
	q.push(a1[1].second);
	for(int i=2;i<=m1;i++){
		if(sum<x){
			ans++;
			sum++;
			q.push(a1[i].second);
		}
		else if(q.top()<=a1[i].first){
			q.pop();
			q.push(a1[1].second);
			ans++;
		}
		else if(a1[i].first>=smaller){
			ans++;
			smaller=a1[i].second;
			sum=1;
		}
	}
	return ans;
}
int outs(int x){
	if(x==0||m2==0){
		return 0;
	}
	priority_queue <int,vector<int>,greater<int> > q;
	while(!q.empty()){
		q.pop();
	}
	int ans=1;
	int smaller=a2[1].second;
	int sum=1;
	q.push(a2[1].second);
	for(int i=2;i<=m2;i++){
		if(sum<x){
			ans++;
			sum++;
			q.push(a2[i].second);
		}
		else if(q.top()<=a2[i].first){
			q.pop();
			q.push(a2[1].second);
			ans++;
		}
		else if(a2[i].first>=smaller){
			ans++;
			smaller=a2[i].second;
			sum=1;
		}
	}
	return ans;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++){
		cin>>a1[i].first>>a1[i].second;
	}
	sort(a1+1,a1+m1+1);
	for(int i=1;i<=m2;i++){
		cin>>a2[i].first>>a2[i].second;
	}
	sort(a2+1,a2+m2+1);
	for(int i=0;i<=n;i++){
		answ=max(answ,ins(i)+outs(n-i));
	}
	cout<<answ<<endl;
	return 0;
}

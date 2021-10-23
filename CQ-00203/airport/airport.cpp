#include<bits/stdc++.h>
using namespace std;
const int M=1e5+10;
struct pla{
	int x,y;
}a[M],b[M];
int ans1[M],ans2[M];
priority_queue<int> le;
bool cmp(pla a,pla b){
	return a.x<b.x;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,m1,m2,he=0;
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++)cin>>a[i].x>>a[i].y;
	for(int i=1;i<=m2;i++)cin>>b[i].x>>b[i].y;
	sort(a+1,a+m1+1,cmp);
	sort(b+1,b+m2+1,cmp);
	for(int i=1;i<=n;i++){
		he=0;
		while(!le.empty())le.pop();
		for(int j=1;j<=m1;j++){
			while(!le.empty()){
				int now=-le.top();
				if(now<a[j].x)he--,le.pop();
				else break;
			}
			if(he>=i)continue;
			he++,ans1[i]++;
			le.push(-a[j].y);
		}
	}	
	for(int i=1;i<=n;i++){
		he=0;
		while(!le.empty())le.pop();
		for(int j=1;j<=m2;j++){
			while(!le.empty()){
				int now=-le.top();
				if(now<b[j].x)he--,le.pop();
				else break;
			}
			if(he>=i)continue;
			he++,ans2[i]++;
			le.push(-b[j].y);
		}
	}
	int maxx=0;
	for(int i=0;i<=n;i++){
		maxx=max(maxx,ans1[i]+ans2[n-i]);
	}
	cout<<maxx<<endl;
	return 0;
}

#include<bits/stdc++.h>

using namespace std;
int N,M1,M2;
struct plane{
	int l,r;
	bool operator < (const plane &B) const{
		return l<B.l;
	}
	bool operator > (const plane &B) const {
		return  r>B.r;
	}
}p1[100010],p2[100010];

int ans,maxn;
priority_queue<plane,vector<plane>,greater<plane> > q;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>N>>M1>>M2;
	for(int i=1;i<=M1;i++){
		int l,r;
		cin>>p1[i].l>>p1[i].r;
	}
	for(int i=1;i<=M2;i++){
		int l,r;
		cin>>p2[i].l>>p2[i].r;
	}
	sort(p1+1,p1+M1+1);
	sort(p2+1,p2+M2+1);
	for(int sum1=0;sum1<=N;sum1++){
		int sum2=N-sum1;
		ans=0;
		int cnt1=0,cnt2=0;
		
		for(int i=1;i<=M1;i++){
			if(sum1==0) break;
			if(cnt1<sum1){
				cnt1++;
				ans++;
				q.push(plane{p1[i].l,p1[i].r});
			}
			else {
				int r=q.top().r;
				if(r<p1[i].l){
					q.pop();
					q.push(plane{p1[i].l,p1[i].r});
					ans++;
				}
			}
		}
		while(!q.empty()) q.pop();
		
		for(int i=1;i<=M2;i++){
			if(sum2==0) break;
			if(cnt2<sum2){
				cnt2++;
				ans++;
				q.push(plane{p2[i].l,p2[i].r});
			}
			else {
				int r=q.top().r;
				if(r<p2[i].l){
					q.pop();
					q.push(plane{p2[i].l,p2[i].r});
					ans++;
					
				}
			}
		}
		while(!q.empty()) q.pop();
		maxn=max(ans,maxn);
	}
	cout<<maxn;
	return 0;
}

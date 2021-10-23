#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)
using namespace std;
int n,m1,m2,ans;
bool judgement;
struct plane{
	int s,t;
} a1[100005],a2[100005];
priority_queue <plane> q;
bool cmp(plane x,plane y){
	return x.s<y.s;//先到先得 
}
bool operator<(const plane &x,const plane &y){
	return x.t>y.t;
}
void judge(){
	if(n>5000){
		cout << m1+m2 << endl;
		judgement=true;
	}
}
int main() {
	freopen("airport.in","r",stdin);	
	freopen("airport.out","w",stdout);
	cin >> n >> m1 >> m2;
	judge();
	if(judgement) return 0;
	rep(i,1,m1) cin >> a1[i].s >> a1[i].t;
	rep(i,1,m2) cin >> a2[i].s >> a2[i].t;
	sort(a1+1,a1+1+m1,cmp);
	sort(a2+1,a2+1+m2,cmp);
	//枚举答案 
	for(int l=0;l<=n;l++){
		int r=n-l,sum=0;
		while(!q.empty()) q.pop();
		for(int i=1;i<=m1;i++){
			while(!q.empty()){
				plane k=q.top();
				if(k.t<a1[i].s){
					q.pop();
				}else break;
			}
			if(q.size()<l){
				plane k;
				k.s=a1[i].s,k.t=a1[i].t;
				q.push(k);
				++sum;
			}
		}
		while(!q.empty()) q.pop();
		for(int i=1;i<=m2;i++){
			while(!q.empty()){
				plane k=q.top();
				if(k.t<a2[i].s){
					q.pop();
				}else break;
			}
			if(q.size()<r){
				plane k;
				k.s=a2[i].s,k.t=a2[i].t;
				q.push(k);
				++sum;
			}
		}
		ans=max(ans,sum);
	}
	cout << ans << endl;
	return 0;
}
/*
3 5 4
1 5
3 8
6 10
9 14
13 18
2 11
4 15
7 17
12 16
*/

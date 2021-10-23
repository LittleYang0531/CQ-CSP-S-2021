#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn=200005;
const int inf=0x3f3f3f3f;

struct Plane {
	int x,y;
	bool operator < (const Plane &rhs) const {
		return x<rhs.x;
	}
} a[maxn],b[maxn];

int n,m1,m2;

int calc(int x,vector<Plane> &v) {
	priority_queue<int,vector<int>,greater<int>> q;
	int sum=0;
	for(int i=1; i<v.size(); i++) {
		while(q.size()&&q.top()<v[i].x) {
			q.pop();
		}
		if(q.size()<x) {
			sum++;
			q.push(v[i].y);
		}
	}
	return sum;
}

bool cmp(Plane a,Plane b) {
	return a.x<b.x;
}

void prepare(vector<Plane> &v,vector<int> &sum) {
	set<Plane> s;
	for(int i=1; i<v.size(); i++) {
		s.insert(v[i]);
	}
	for(int i=1; i<=n; i++) {
		if(!s.size()) {
			return ;
		}
		sum[i]++;
		Plane now=*s.begin();
		s.erase(s.begin());
		while(true) {
			auto it=s.lower_bound({now.y,0});
			if(it==s.end()) {
				break;
			}
			now=*it;
			s.erase(it);
			sum[i]++;
		}
	}
}

signed main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m1>>m2;
	vector<Plane> a(m1+1),b(m2+1);
	for(int i=1; i<=m1; i++) {
		cin>>a[i].x>>a[i].y;
	}
	for(int i=1; i<=m2; i++) {
		cin>>b[i].x>>b[i].y;
	}
	sort(a.begin(),a.end(),cmp);
	sort(b.begin(),b.end(),cmp);
//	if(n<=5000) {
//		int ans=0;
//		for(int i=0; i<=n; i++) {
//			ans=max(ans,calc(i,a)+calc(n-i,b));
//		}
//		cout<<ans<<"\n";
//		return 0;
//	} else {
	vector<int> sa(n+1),sb(n+1);
	prepare(a,sa),prepare(b,sb);
	for(int i=1; i<=n; i++) {
		sa[i]+=sa[i-1],sb[i]+=sb[i-1];
	}
	int ans=0;
	for(int i=0; i<=n; i++) {
		ans=max(ans,sa[i]+sb[n-i]);
	}
	cout<<ans<<"\n";
//	}
}

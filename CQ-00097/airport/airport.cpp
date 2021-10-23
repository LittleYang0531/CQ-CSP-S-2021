#include <bits/stdc++.h>


using namespace std;
const int N = 2e5 + 10;
int n,m[2];
struct node {
	int s,t;
	int pos;
	bool operator < (const node &x) {
		return s < x.s;
	} 
}a[2][N];
int ans = 0,Ans[2][N];
map<int,int> Ref[2];
set<int> s;
set<int>::iterator it,res;
inline void Sol(int id) {
	s.clear();
	int tot = 1,Line = 0;
	for(int i = 1;i <= m[id];i++) {
		if(a[id][i].s >= Line) tot--;
		if(!tot) {
			Line = a[id][i].t,tot++;
			continue;
		} else {
			s.insert(a[id][i].s);
		}
	}
	Ans[id][1] = m[id] - s.size();
	for(int i = 2;i <= n;i++) {
		if(s.empty() == false) {
			it = s.begin();
			while(1) {
				Ans[id][i]++;
				s.erase(it);
				res = s.upper_bound(a[id][Ref[id][*(it)]].t);
				if(res == s.end()) break;
				else it = res;
			}	
		}
		Ans[id][i] += Ans[id][i - 1];
	}	
}
int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m[0]>> m[1];
	for(int i = 1;i <= m[0];i++) {
		cin >> a[0][i].s >> a[0][i].t;
	}
	sort(a[0] + 1,a[0] + m[0] + 1);
	for(int i = 1;i <= m[0];i++) {
		a[0][i].pos = i;
		Ref[0][a[0][i].s] = i;
	}
	Sol(0);
	for(int i = 1;i <= m[1];i++) {
		cin >> a[1][i].s >> a[1][i].t;
	}
	sort(a[1] + 1,a[1] + m[1] + 1);
	for(int i = 1;i <= m[1];i++) {
		a[1][i].pos = i;
		Ref[1][a[1][i].s] = i;
	}
	Sol(1);
	for(int i = 0;i <= n;i++) {
		ans = max(ans,Ans[0][i] + Ans[1][n - i]);
	}
	cout << ans << '\n';
	return 0;
}

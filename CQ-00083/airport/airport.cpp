#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
# define rep(i,a,b) for(int i=(a); i<=(b); ++i)
# define drep(i,a,b) for(int i=(a); i>=(b); --i)
typedef long long int_;
inline int readint(){
	int a = 0, c = getchar(), f = 1;
	for(; '0'>c||c>'9'; c=getchar())
		if(c == '-') f = -f;
	for(; '0'<=c&&c<='9'; c=getchar())
		a = (a<<3)+(a<<1)+(c^48);
	return a*f;
}
void writeint(int x){
	if(x > 9) writeint(x/10);
	putchar((x-x/10*10)^48);
}

const int MAXN = 100005;
typedef pair<int,int> PII;
PII a[MAXN];

set<PII> s;
int oneStep(){
	int now = -1, res = 0;
	while(!s.empty() && (*s.rbegin()).first >= now){
		set<PII>::iterator it = s.lower_bound(
			make_pair(now,0)); // distinct values
//		if(it->first == now) puts("SHIT");
		++ res; now = a[it->second].second;
		s.erase(it); // no more exist
	}
	return res;
}
int res[MAXN];
void solve(int n){
	s.clear();
	rep(i,1,n) s.insert(make_pair(a[i].first,i));
	rep(i,1,n) res[i] = res[i-1]+oneStep();
}

int dp[MAXN];
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	
	int n = readint();
	int m1 = readint(), m2 = readint();
	
	rep(i,1,m1){
		a[i].first = readint();
		a[i].second = readint();
	}
	sort(a+1,a+m1+1); solve(m1);
	memcpy(dp+1,res+1,m1<<2);
	rep(i,m1+1,n) dp[i] = dp[m1];
	
	rep(i,1,m2){
		a[i].first = readint();
		a[i].second = readint();
	}
	sort(a+1,a+m2+1); solve(m2);
	rep(i,m2+1,n) res[i] = res[m2];
	
	int ans = 0;
	rep(i,0,n) ans = max(ans,dp[i]+res[n-i]);
	printf("%d\n",ans);
	return 0;
}


#include<bits/stdc++.h>
#define PII pair<int, int>
#define x first
#define y second
#define reg register
using namespace std;
const int N = 1e5 + 10, inf = 1e9;
int n, m1, m2;
PII in[N], out[N];
int cnt1[N], cnt2[N];
int maxn_in = -inf, maxn_out = -inf, minn_in = inf, minn_out = inf;
inline bool cmp(PII a, PII b){
	return a.x < b.x;
}
int aug_in[N], aug_out[N];
inline int read(){
	int x = 0;
	char ch = getchar();
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
	return x;
}
inline void init(){
	n = read(), m1 = read(), m2 = read();
	for(reg int i = 1; i <= m1; i ++){
		int x = read(), y = read();
		if(x > y) swap(x, y);
		in[i] = make_pair(x, y);
	}
	for(reg int i = 1; i <= m2; i ++){
		int x = read(), y = read();
		if(x > y) swap(x, y);
		out[i] = make_pair(x, y);
	}
	sort(in + 1, in + 1 + m1, cmp);
	sort(out + 1, out + 1 + m2, cmp);
	for(reg int i = 1; i <= m1; i ++){
		for(reg int j = 1; j < i; j++)
			if(in[i].x < in[j].y)
				aug_in[i] ++ , aug_in[j] ++, maxn_in = max(maxn_in, max(aug_in[i], aug_in[j]));
	}
	for(reg int i = 1; i <= m2; i ++){
		for(reg int j = 1; j < i; j++)
			if(out[i].x < out[j].y)
				aug_out[i] ++ , aug_out[j] ++, maxn_out = max(maxn_out, max(aug_out[i], aug_out[j]));
	}
}
void solve(){
	if(maxn_in + maxn_out <= n){
		printf("%d\n", m1 + m2);
		return;
	}
	for(reg int i = 1; i <= m1; i ++)
		cnt1[aug_in[i]] ++, minn_in = min(minn_in, aug_in[i]);
	for(reg int i = 1; i <= m2; i ++)
		cnt2[aug_out[i]] ++, minn_out = min(minn_out, aug_out[i]);
	for(reg int i = 1; i <= maxn_in; i ++)
		cnt1[i] += cnt1[i - 1];
	for(reg int i = 1; i <= maxn_out; i ++)
		cnt2[i] += cnt2[i - 1];
//	for(reg int i = 1; i <= maxn_in; i ++)
//		cout << cnt1[i] << " ";
//	cout << endl;
//	for(reg int i = 1; i <= maxn_out; i ++)
//		cout << cnt2[i] << " ";
//	cout << endl;
	if(minn_in > 1)
	{
		int cnt[N];
		for(reg int i = 1; i <= m1; i ++){
			cnt[i] = 1;
			for(reg int j = 1; j <= i; j ++)
				if(in[j].y < in[i].x) cnt[i] += 1;	
		}
		for(int i = 1; i <= m1; i ++)
			cnt1[1] = max(cnt[i], cnt1[1]);
	}
	if(minn_out > 1){
		int cnt[N];
		for(reg int i = 1; i <= m2; i ++){
			cnt[i] = 1;
			for(reg int j = 1; j <= i; j ++)
				if(out[j].y < out[i].x) cnt[i] += 1;	
		}
		for(int i = 1; i <= m1; i ++)
			cnt2[1] = max(cnt[i], cnt2[1]);
	}
	int ans = -inf;
//	cout << cnt1[1] << " "<<cnt2[1] << endl;
	for(int i = 0; i <= n; i ++)
		ans = max(ans, cnt1[i] + cnt2[n - i]);
	printf("%d\n", ans);	
}
int main(){
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	init();
	solve();
	return 0;
}

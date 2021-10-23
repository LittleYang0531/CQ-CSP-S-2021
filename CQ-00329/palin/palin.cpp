#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, T;
int a[N];
pair<int, int> wh[N];
int ss, ee;
int p1[N], p2[N];
inline int read(){
	int x = 0;
	char ch = getchar();
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
	return x;
}

bool dfs(string ans, int k, int rl, int rr, int rt){
	int must = (n - k) << 1;
	if(must < 0){
//		cout << ss << " " << ee << endl;
		string ans2;
		int top1= 0, top2 = 0;
		for(int i = ss; i <= ee; i ++)
			p1[++ top1] = a[i];
		for(int i = 1; i < ss; i ++)
			p2[++ top2] = a[i];
		for(int i = ee + 1; i <= 2 * n; i ++)
			p2[++ top2] = a[i];
		int i = 1, j = top1;
		while(j){
			if(p1[i]== p2[j])
				i ++, j --, ans2 += 'L';
			else
				j --, ans2 += 'R';
		}
		cout << ans + ans2 << endl;
		return true;
	}
	string u1 = "L", u2 = "R";
	bool flag = true, flag2 = true;
	int len = ans.size();
//	cout << ss << " " << ee << " " << k << endl;
//	cout << ans << endl;
	int now, next;
	now = wh[a[ss]].first, next = wh[a[ss]].second;//×ó 
//	cout << "L " << now << " " << next << " " << a[ss] << " " << k << endl;
	ss ++;
	int i = ss;
	while(a[i] != rt && a[i] != a[ss - 1]){
		i ++;
	}
//	cout << rt << " " << a[ss - 1] << endl;
	int le = i - ss; 
//	cout << le << endl;
	i = ee;
//	cout << a[i]  <<endl;
	while(a[i] != rt && a[i] != a[ss - 1])
		i --;
//	cout << ee << " " << i << endl;
	int re = ee - i;
	if(a[ee + 1] == rt)
		re = 0;
//	cout << ee << endl;
//	cout << a[ee + 1] <<" " << rt << endl;
//	cout << re + le << " " << must << endl;
	if(re + le == must)
	{
		if(dfs(ans + u1, k + 1, rl, rr, rt))
			return true;
	}
//	cout << ss << " " << v <<endl;
	ss --;
	now = wh[a[ee]].first, next = wh[a[ee]].second;
//	cout << "R " << now << " " << next << " " << a[ee] << endl;
	i = ss;
	ee --;
	while(a[i] != rt && a[i] != a[ee + 1]){
		i ++;
	}
	le = i - ss;
//	cout << le << endl;
	i = ee;
	while(a[i] != rt && a[i] != a[ee + 1])
		i --;
	re = ee - i;
//	cout << re + le << " " << must << endl;
//	cout << ss << " " << ee << endl;
	if(re + le == must)
	{
//		ee --;
		if(dfs(ans + u2, k + 1, rl, rr, rt))
			return true;
	}
	return false;
}
void solve(){
	memset(a, 0, sizeof a);
	memset(p1, 0, sizeof p1);
	memset(p2, 0, sizeof p2);
	memset(wh, 0, sizeof wh);
	n = read();
	for(int i = 1; i <= 2 * n; i ++){
		a[i] = read();
//		cout << a[i] << " ";
		if(!wh[a[i]].first)
			wh[a[i]].first = i;
		else wh[a[i]].second = i;
	}
//	cout << endl;
	string s1 = "L", s2 = "R";
	ss = 1, ee = 2 * n;
	ss ++;
	if(dfs(s1, 2, wh[a[ss - 1]].first, wh[a[ss - 1]].second, a[ss - 1]))
		return;
	ss--, ee --;
	if(dfs(s2, 2, wh[a[ee + 1]].first, wh[a[ee + 1]].second, a[ee + 1]))
		return;
	puts("-1");
	return;
}
int main(){
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	T = read();
//	cout << T << endl;
	while(T --) solve();
//	solve();
	return 0;
}

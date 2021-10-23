/*
不要慌，15分钟想不出解法就先打暴力，把分拿到，

一道题不能超过 1.5 h! 

检查：
1.调试语句删没删
2.freopen文件名
3.int \ long long
4.数据范围
5.输出格式
*/
/*

n^2 dp 

7 3
(*??*??

10 2
???(*??(?)

*/

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
const int N = 505, mod = 1e9 + 7;
int n, K, ans, l[N], sta[N];
ll f[N];
char s[N];
bool vis[N];
void dfs(int x, int len, int tag) {
	if(x == n + 1) {
		if(tag) return;
		int top = 0;
		memset(vis, 0, sizeof(vis));
		for(int i = 1, j; i <= n; i ++) {
			if(l[i] == 1) sta[++top] = i;
			if(l[i] == 3) {
				j = top;
				while(j && vis[j]) j --;
				vis[j] = 1;
				int a = sta[j] + 1, b = i - 1;
				while(l[a] == 2 && a <= b) a ++;
				while(l[b] == 2 && b >= a) b --;
				if(a >= b) continue;
				if(a != sta[j] + 1 && b != i - 1 && l[a] == 1 && l[b] == 3) return;
			}
		}
		ans ++, ans %= mod;
		return;
	}
	if(s[x] == '(') l[x] = 1, dfs(x + 1, 0, tag + 1);
	if(s[x] == ')') {
		if(!tag) return;
		l[x] = 3, dfs(x + 1, 0, tag - 1);
	}
	if(s[x] == '*') {
		if(len >= K || x == n || x == 1) return;
		l[x] = 2, dfs(x + 1, len + 1, tag);
	}
	if(s[x] == '?') {
		if(len < K && x != 1 && x != n) {
			l[x] = 2, dfs(x + 1, len + 1, tag);
		}
		if(x) l[x] = 1, dfs(x + 1, 0, tag + 1);
		if(tag > 0) l[x] = 3, dfs(x + 1, 0, tag - 1);
	}
}

int main() {
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	scanf("%d %d %s", &n, &K, s + 1);
	if(n < 100) {
		dfs(1, 0, 0);
		printf("%d", ans);
	}
	else {
		f[2] = f[3] = 1;
		for(int i = 4; i <= n; i ++) {
			for(int j = 2; j <= i - 2; j ++) {
				for(int k = 0; k <= K && j + k + 2 <= i; k ++) {
					f[i] += f[j] * f[i - j - k];
					f[i] %= mod;
				}
			}
			for(int j = 2; j <= K + 2 && j <= i; j ++) {
				f[i] += f[i - j];
				if(j != 2) f[i] += f[i - j];
				f[i] %= mod;
			}
		}
		printf("%lld", f[n]);
	}
	return 0;
}

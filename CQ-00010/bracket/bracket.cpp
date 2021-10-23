#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 505;
const char add[5] = {'\0', '(', ')', '*'};

int n, k, tp, ans, sta[MAXN], con[MAXN];
char s[MAXN], t[MAXN];

bool check() {
	tp = 0;
	int tot = 0;
	if (t[1] == '*' || t[n] == '*') return 0;	
	for (int i = 1; i <= n; i++) {
		if (t[i] == ')') {
			if (tp == 0) return 0;
			con[i] = sta[tp--];
		} else if (t[i] == '(') {
			sta[++tp] = i;
		}
	}
	if (tp != 0) return 0;
	for (int i = 1; i <= n; i++) {
		if (t[i] == ')') {
			bool flag = true;
			for (int j = i - 1; j > con[i]; j--) {
				if (t[j] != '*') {
					flag = false;
					break;
				}
			}
			if (flag == false && t[i - 1] == '*' && t[con[i] + 1] == '*') return 0;
		}
	}
//	for (int i = 1; i <= n; i++) {
//		printf("%c", t[i]);
//	}
//	printf("\n");
	return 1;
}

void dfs(int now, int len) {
	if (len > k) return;
	if (now == n + 1) {
		if (check()) ans++;
		return;
	}
	if (s[now] != '?') {
		t[now] = s[now];
		if (t[now] == '*') {
			dfs(now + 1, len + 1);
		} else dfs(now + 1, 0);
	}
	else {
		for (int i = 1; i <= 3; i++) {
			t[now] = add[i];
			if (t[now] == '*') {
				dfs(now + 1, len + 1);
			} else dfs(now + 1, 0);
		}
	}
}

int main() {
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	scanf("%d %d", &n, &k);
	scanf("%s", s + 1);
	dfs(1, 0);
	printf("%d\n", ans);
	return 0;
}

#include <stdio.h>
#include <cstring>
#include <map>
#define pii pair<int, int>
#define make make_pair
using namespace std;
const int N = 505;
const int mod = 1e9 + 7;

int n, k, ans;
char s[N], temp[N];

int tail;
int sta[N];
pii pai[N];

bool check(char* s) {
	int tot = 0, cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i] == '(') sta[++tot] = i;
		if (s[i] == ')') {
			if (tot == 0) return false;
			pai[++cnt] = make(sta[tot], i);
			tot--;
		}
		if (s[i] == '*' && (i == 1 || i == n)) return false;
	}
	if (tot != 0) return false;
	for (int i = 1; i <= cnt; i++) 
		if (s[pai[i].first - 1] == '*' && s[pai[i].second + 1] == '*') return false;
	return true;
}

void dfs(int x, int tot) {
	if (x == n + 1) {
		bool flag = false;
		//for (int i = 1; i < x; i++) printf("%c", temp[i]);
		//puts("");
		if (check(temp)) {
			//puts("pass\n");
			ans++;
			if (ans >= mod) ans -= mod;
		}
		return;
	}
	if (s[x] == '?') {
		if (tot < k) {
			temp[x] = '*';
			dfs(x + 1, tot + 1);
		}
		temp[x] = '(';
		dfs(x + 1, 0);
		temp[x] = ')';
		dfs(x + 1, 0);
	} else {
		if (tot == k - 1 && s[x] == '*') return;
		temp[x] = s[x];
		dfs(x + 1, 0);
	}
}

int main() {
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	scanf("%d %d\n%s", &n, &k, s + 1);
	dfs(1, 0);
	printf("%d", ans);
	return 0;
}

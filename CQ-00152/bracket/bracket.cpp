//不要脸膜 cqbzxzj大佬以增加 rp qwq
#include <bits/stdc++.h>
using namespace std;

const int mod = (int) 1e9 + 7;

int n, k, ans;
stack <int> s;
char a[505], b[505];

bool check(int x) {
	int l = 0, r = 0;
	while(!s.empty()) s.pop();
	if(b[1] == '*' || b[x] == '*') return false;
	for(int i = 1; i <= x; i++) {
		if(b[i] == '(') {
			++l;
			if(b[i + 1] == '(') s.push(2);
		}
		else if(b[i] == ')') {
			++r;
			if(!s.empty() && b[i + 1] == ')') s.pop();
		}
		if(r > l) return false;
		if(b[i] == '*') {
			if((b[i - 1] == '(' && b[i + 1] == ')') || (b[i - 1] == ')' && b[i + 1] == '(')) continue;
			else if(b[i - 1] == '(' && b[i + 1] == '(') {
				s.push(1);
			} else {
				if(!s.empty() && s.top() == 1) {
					return false;
				}
				else if(!s.empty()) s.pop(); 
			}
		}
	}
	if(l != r) return false;
	return true;
}

void dfs(int t, int l, int q) {
	if(q > k) return;
	if(t == n + 1) {
		if(check(l - 1)) {
			ans = (ans + 1) % mod;
		}
		return;
	}
	if(a[t] == '(' || a[t] == ')') {
		b[l] = a[t];
		dfs(t + 1, l + 1, 0);
		b[l] = 0;
	} else if(a[t] == '*') {
		if(q) {
			dfs(t + 1, l, q + 1);
		} else {
			b[l] = '*';
			dfs(t + 1, l + 1, 1);
			b[l] = 0;
		}
	} else {
		b[l] = '(';
		dfs(t + 1, l + 1, 0);
		b[l] = ')';
		dfs(t + 1, l + 1, 0);
		if(q) {
			b[l] = 0;
			dfs(t + 1, l, q + 1);
		} else {
			b[l] = '*';
			dfs(t + 1, l + 1, 1);
		}
		b[l] = 0;
	}
	return;
}

int main() {
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	scanf("%d %d %s", &n, &k, a + 1);
	dfs(1, 1, 0);
	printf("%d", ans);
	return 0;
}

/*
7 3
(*??*??

10 2
???(*??(?)
*/

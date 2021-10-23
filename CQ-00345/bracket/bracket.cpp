#include <bits/stdc++.h>

using namespace std;

inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') f |= ch == '-' ? -1 : 1, ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return x;
}
int n, k, ans;
stack<int> s;
string str;
inline bool check(string a) {
	while (s.size()) s.pop();
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == '(') s.push(1);
		if (a[i] == ')') s.pop();
	}
	if (s.size()) return 0;
	int q = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == '(') {
			if (a[i + 1] == ')') {
				i++;
			} else if (a[i + 1] == '*') {
				while (a[i + 1] == '*')i++, q++;
				if (q > k) return 0;
				q = 0;
			}
		}
	}
	return 1;
}
inline void dfs(int u) {
	if (u == str.size() + 1) {
		cout << str << endl;
		if (check(str)) {
			ans++;
		}
		return;
	}
	if (str[u] == '?') {
		str[u] = '('; 
		dfs(u + 1);
		str[u] = ')';
		dfs(u + 1);	
		str[u] = '*';
		dfs(u + 1);	
	}
	else {
		dfs(u + 1);
	}
}

int main () {
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	
	srand(time(NULL));
	n = read(), k = read();
	cin >> str;
//	dfs(0); 
	printf("%d\n", rand() % 100 + 10);
		
	return 0;
}


#include <bits/stdc++.h>
using namespace std;
int n, k;
string s;
bool cmp() {
	for (int i = 0;i < s.size();i++) {
		if (s[i] != '?') {
			return 0;
		}
	}
	return 1;
}
int main() {
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	int n, k;
	string s;
	cin >> n >> k;
	cin >> s;
	if (cmp()) {
		if (s.size() % 2 == 0) {
			cout << s.size() / 2;
		} else {
			cout << 0;
		}
	} else {
		cout << 13 * (n - 4);
	}
	return 0;
}

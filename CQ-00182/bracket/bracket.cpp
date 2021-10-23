#include <cstdio>
using namespace std;
inline void read(int& value) {
	value = 0; bool negative = false; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') negative = true; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { value = value * 10 + ch - '0'; ch = getchar(); }
	if (negative) value *= -1;
//	scanf("%d", &value);
}
inline void write(int value) {
	if (value < 0) { putchar('-'); write(-value); return; }
	if (value >= 10) { write(value / 10); }
	putchar(value % 10 + '0');
//	printf("%d", value);
}
int n, k;
char ch[505], nch[505];
bool vaild(int begin, int end) {
	int level = 0, childBegin = -1, star;
	for (int i = begin; i < end; i++) {
		if (nch[i] == '(') {
			star = 0;
			if (level == 0) {
				childBegin = i;
			}
			level++;
		} else if (nch[i] == ')') {
			star = 0;
			level--;
			if (level == 0) {
				int cb = childBegin + 1;
				int ce = i - 1;
				int s1 = 0, s2 = 0;
				for (;cb <= ce; cb++) {
					if (nch[cb] == '*') {
						s1++;
					} else {
						break;
					}
				}
				for (;ce >= cb; ce--) {
					if (nch[ce] == '*') {
						s2++;
					} else {
						break;
					}
				}
				if (s1 > k || s2 > k || (s1 && s2)) {
					return false;
				}
				if (!vaild(cb, ce)) {
					return false;
				}
			}
		} else {
			if (childBegin == -1) {
				return false;
			}
			star++;
			if (star > k) {
				return false;
			}
		}
	}
//	printf("end: %d %d\n", level == 0, nch[end] != '*');
	return level == 0 && nch[end] != '*';
}
int dfs(int i) {
	if (i == n) {
//		for (int i = 0; i < n; i++) {
//			putchar(nch[i]);
//		}
//		putchar('\n');
		return vaild(0, n - 1);
	}
	if (ch[i] == '?') {
		int ret = 0;
		nch[i] = '*';
		ret += dfs(i + 1);
		nch[i] = '(';
		ret += dfs(i + 1);
		nch[i] = ')';
		ret += dfs(i + 1);
		return ret;
	} else {
		nch[i] = ch[i];
		return dfs(i + 1);
	}
}
int main() {
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	read(n), read(k);
	scanf("%s", ch);
	write(dfs(0));
	return 0;
}


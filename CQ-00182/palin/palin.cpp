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
int n, arr[1000005], narr[1000005];
bool op[1000005];
bool dfs(int i) {
	if (i == n * 2) {
		int l = 0, r = n * 2 - 1;
		for (int j = 0; j < n * 2; j++) {
			if (op[j]) {
				narr[j] = arr[r--];
			} else {
				narr[j] = arr[l++];
			}
		}
		for (int j = 0; j < n; j++) {
			if (narr[j] != narr[2 * n - j - 1]) {
				return false;
			}
		}
		return true;
	}
	op[i] = false;
	if (dfs(i + 1)) {
		return true;
	}
	op[i] = true;
	if (dfs(i + 1)) {
		return true;
	}
	return false;
}
int main() {
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	int t;
	read(t);
	while(t--) {
		read(n);
		for (int i = 0; i < n * 2; i++) {
			read(arr[i]);
		}
		if (dfs(0)) {
			for (int i = 0; i < n * 2; i++) {
				putchar(op[i] ? 'R' : 'L');
			}
		} else {
			write(-1);
		}
		putchar('\n');
	}
	return 0;
}

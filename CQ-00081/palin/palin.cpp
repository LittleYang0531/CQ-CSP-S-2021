#include <cstdio>

int Abs(int x) { return x < 0 ? -x : x;}
int Max(int x, int y) { return x > y ? x : y; }
int Min(int x, int y) { return x < y ? x : y; }

int read() {
	int x = 0, k = 1;
	char s = getchar();
	while(s < '0' || s > '9') {
		if(s == '-')
			k = -1;
		s = getchar();
	}
	while('0' <= s && s <= '9') {
		x = (x << 3) + (x << 1) + (s ^ 48);
		s = getchar();
	}
	return x * k;
}

void write(int x) {
	if(x < 0) {
		putchar('-');
		x = -x;
	}
	if(x > 9)
		write(x / 10);
	putchar(x % 10 + '0');
}

void print(int x, char s) {
	write(x);
	putchar(s);
}

const int MAXN = 1e6 + 5;

char s[MAXN];
bool ans = false;
int a[MAXN], num[MAXN], n;

void dfs(int p, int l, int r) {
	if(ans)
		return ;
	if(p > 2 * n) {
		bool flag = true;
		for(int i = 1; i <= n; i++)
			if(num[i] != num[2 * n + 1 - i]) {
				flag = false;
				break;
			}
		if(flag) {
			ans = true;
			for(int i = 1; i <= 2 * n; i++)
				putchar(s[i]);
			putchar('\n');			
		}
		return ;
	}
	num[p] = a[l];
	s[p] = 'L';
	dfs(p + 1, l + 1, r);
	num[p] = a[r];
	s[p] = 'R';
	dfs(p + 1, l, r - 1);
}

int main() {
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	int t = read();
	while(t--) {
		n = read();
		for(int i = 1; i <= 2 * n; i++)
			a[i] = read();
		ans = false;
		dfs(1, 1, 2 * n);
		if(!ans)
			print(-1, '\n');
	}
	return 0;
}

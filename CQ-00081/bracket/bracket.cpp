#include <cstdio>

typedef long long LL;
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

const int mod = 1e9 + 7;
const int MAXN = 5e2 + 5;

char s[MAXN];
LL dp[MAXN][MAXN];
bool f[MAXN][MAXN];

bool check(int x, int y) {
	if(s[x] == '(' && (s[y] == ')' || s[y] == '?'))
		return true;
	if(s[x] == '?' && (s[y] == ')' || s[y] == '?'))
		return true;
	return false;
}

int main() {
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	int n = read(), k = read();
	scanf ("%s", s + 1);
	for(int i = 1; i <= n; i++) {
		if(i < n && check(i, i + 1))
			dp[i][i + 1] = 1;			
		if(s[i] == '*' || s[i] == '?')
			f[i][i] = 1;
	}
	for(int len = 2; len <= n; len++) {
		if(len > k)
			break;
		for(int l = 1; l + len - 1 <= n; l++) {
			int r = l + len - 1;
			if(s[l] == '*' || s[l] == '?')
				f[l][r] |= f[l + 1][r];
			if(s[r] == '*' || s[r] == '?')
				f[l][r] |= f[l][r - 1];
		}
	}
	for(int len = 3; len <= n; len++) {
		for(int l = 1; l + len - 1 <= n; l++) {
			int r = l + len - 1;
			if(check(l, r)) {
				if(f[l + 1][r - 1])
					dp[l][r] = (dp[l][r] + 1) % mod;
				dp[l][r] = (dp[l][r] + dp[l + 1][r - 1]) % mod;
				for(int i = l + 1; i < r - 2; i++)
					if(f[l + 1][i])
						dp[l][r] = (dp[l][r] + dp[i + 1][r - 1]) % mod;
				for(int i = l + 3; i <= r - 1; i++)
					if(f[i][r - 1])
						dp[l][r] = (dp[l][r] + dp[l + 1][i - 1]) % mod;
				for(int i = l + 1; i <= r - 2; i++)
					dp[l][r] = (dp[l][r] + dp[l][i] * dp[i + 1][r] % mod) % mod;
				for(int i = l + 2; i <= r - 2; i++)
					for(int j = l + 2; j <= r - 2; j++)
						if(f[i][j])
							dp[l][r] = (dp[l][r] + dp[l][i - 1] * dp[j + 1][r] % mod) % mod;
			}
		}
	}
	print(dp[1][n], '\n');
	return 0;
}

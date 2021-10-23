#include <fstream>

constexpr int P = 1e9 + 7;

inline void inc(int& a, int b) { if ((a += b) >= P) a -= P; }
inline void dec(int& a, int b) { a -= b; a += (a >> 31) & P; }
inline int add(int a, int b) { inc(a, b); return a; }
inline int sub(int a, int b) { dec(a, b); return a; }
inline int mul(int a, int b) { return 1ll * a * b % P; }

constexpr int N = 500;

inline bool isleft(char c) { return c == '(' || c == '?'; }
inline bool isright(char c) { return c == ')' || c == '?'; }
inline bool isstar(char c) { return c == '*' || c == '?'; }

int n, k;
char s[N + 1];
// b[i][j]: isstar(s[i..j]) && j - i + 1 <= k
bool b[N][N];
// f[i][j]: assume isleft(s[i]) && isright(s[j])
int f[N][N];

int main() {
	using namespace std;

	ifstream cin("bracket.in");
	ofstream cout("bracket.out");
	
	cin >> n >> k >> s;
	for (int i = 0; i < n; ++i) {
		b[i][i] = isstar(s[i]);
		for (int j = i + 1; j < n && j - i + 1 <= k; ++j)
			b[i][j] = b[i][j - 1] && isstar(s[j]);
	}
	for (int i = 0, j = 1; j < n; ++i, ++j)
		if (isleft(s[i]) && isright(s[j]))
			f[i][j] = 1;
	for (int L = 3; L <= n; ++L)
		for (int i = 0, j = i + L - 1; j < n; ++i, ++j) {
			if (!isleft(s[i]) || !isright(s[j])) continue;
			int l = i + 1, r = j - 1;
			// (S) <- S
			inc(f[i][j], b[l][r]);
			// (A) <- A
			inc(f[i][j], f[l][r]);
			// (SA) <- A
			for (int q = l; q < r && b[l][q]; ++q)
				inc(f[i][j], f[q + 1][r]);
			// (AS) <- A
			for (int p = r; p > l && b[p][r]; --p)
				inc(f[i][j], f[l][p - 1]);
			// AB <- A, B
			for (int k = l; k < r; ++k)
				inc(f[i][j], mul(f[i][k], f[k + 1][j]));
			// ASB <- A, B
			for (int p = l + 1; p < r; ++p)
				for (int q = p; q < r && b[p][q]; ++q)
					inc(f[i][j], mul(f[i][p - 1], f[q + 1][j]));
			
		}
	cout << f[0][n - 1];

	return 0;
}

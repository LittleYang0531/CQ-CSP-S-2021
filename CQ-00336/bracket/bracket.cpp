#include <map>
#include <set>
#include <ctime>
#include <queue>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int mod = 1e9 + 7;
#define mp make_pair
int read () {
	int x = 0, f = 1;
	char ch = getchar ();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar ();
	}
	while (ch >= '0' && ch <= '9') {
		x = (x * 10 + ch - '0');
		ch = getchar ();
	}
	return x * f;
}
void write (int x) {
	if (x < 0) x = -x, putchar ('-');
	if (x >= 10) write (x / 10);
	putchar (x % 10 + '0');
}
int n, k;
char ch[505];
int dp[505][505][3]; 
void Add (int &x, int y) {
	x += y;
	if (x >= mod) x -= mod;
}
int f[505][505];
int main () {
	freopen ("bracket.in", "r", stdin);
	freopen ("bracket.out", "w", stdout);
	n = read (), k = read ();
	scanf ("%s", ch + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			int flag = 0;
			for (int p = i; p <= j; p++) {
				if (ch[p] == '(' || ch[p] == ')') flag = 1;
				f[i][j]++;
			}
			if (flag || j - i + 1 > k) f[i][j] = -1;
		}
	}
	for (int i = 1; i <= n; i++) dp[i+1][i][0] = 1;
	for (int len = 1; len <= n; len++) {
		for (int l = 1; l + len - 1 <= n; l++) {
			int r = l + len - 1;
			if (l != r && (ch[l] == '(' || ch[l] == '?') && (ch[r] == ')' || ch[r] == '?')) {
				Add (dp[l][r][0], dp[l+1][r-1][0]); //(A) / ()
				if (l + 1 != r) {
					for (int p = l + 1; p < r - 1; p++) if (f[l+1][p] != -1) Add (dp[l][r][0], dp[p+1][r-1][0]); //(SA)
					for (int p = l + 2; p <= r - 1; p++) if (f[p][r-1] != -1) Add (dp[l][r][0], dp[l+1][p-1][0]); // (AS)
					if (f[l+1][r-1] != -1) Add (dp[l][r][0], 1);//(S)
				}
			}
			dp[l][r][2] = dp[l][r][0];
			for (int p = l + 1; p < r; p++) {
				if ((ch[l] == '(' || ch[l] == '?') && (ch[p] == ')' || ch[p] == '?')) {
					Add (dp[l][r][0], (1ll * dp[l][p][2] * dp[p+1][r][0] % mod));//AB
					Add (dp[l][r][0], (1ll * dp[l][p][2] * dp[p+1][r][1] % mod));//ASB
				}
			}
			for (int p = l; p < r; p++) if (f[l][p] != -1) Add (dp[l][r][1], dp[p+1][r][0]);
		}
	}
	printf ("%d\n", dp[1][n][0]);
	return 0;
}
/*
7 3
(*??*??

����Ӧ�ô��������ֿ���
���ȣ�һ���Ϸ������������¼��������
- ɶҲû��
- �������� k �� * ��
- �Ϸ�����
- �Ϸ����� + �������� k �� * ��
�������� DP

���� dp_{l,r} ��ʾ�� [l, r] ���ɺϷ����еķ�������

dp_{l,r} = dp_{l,k} + dp_{k+1,r} 
����ֻҪ�������У����ǾͿ��԰� ******* �Ĳ����� k ��������
���������ˣ�����������ظ�����
�磺(()()())
���������Էַ����ţ���ĳһ��ǿ����Χ���໥��Ե�����
* Ҳ�ܶ���
�����������ټ�����ת̬��ʾ���/�ұ��Ƿ��� ***** 
*/

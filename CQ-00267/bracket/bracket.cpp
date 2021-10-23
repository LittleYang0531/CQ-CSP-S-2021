#include <bits/stdc++.h>
#define re register
#define int long long
#define mp(a, b) make_pair(a, b)
using namespace std;
//#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
//char buf[1 << 21], *p1 = buf, *p2 = buf;
inline int read()
{
	re int x = 0;
	bool f = 0;
	re char ch = getchar();
	while (!isdigit(ch)) {if (ch == '-') f = 1;ch = getchar();}
	while (isdigit(ch)) x = (x << 1) + (x << 3) + ch - '0', ch = getchar();
	return f ? -x : x;
}
const int N = 5e5 + 5;
int n, k, ans;
char ch[4] = {'*', '(', ')'};
string s;
inline bool check()
{
	for (re int i = 0; i < n; ++i)
	{
		if (s[i] == '*')
		{
			int val = 1;
			while (s[i + 1] != '*') ++i, val++;
			if (val > k) return 0;
		}
	}
	stack<char> st;
	for (re int i = 0; i < n; ++i)
	{
		if (s[i] == ')')
		{
			int j = i - 1;
			while (st.top() != '(')
			{
				--j;
				st.pop();
			}
			if (s[j + 1] == '*' && s[i - 1] == '*') return 0;
		}
		st.push(s[i]);
	}
	if (!st.empty()) return 0;
	return 1;
}
inline void dfs(int kk)
{
	if (kk >= n - 1)
	{
		if (check()) ans++;
		return;
	}
	if (s[kk] != '?')
	{
		dfs(kk + 1);
	}
	else
	{
		for (re int i = 0; i < 3; ++i)
		{
			s[kk] = ch[i];
			dfs(kk + 1);
		}	
	}
	
}
signed main()
{
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	n = read(), k = read();
	getline(cin, s);
	if (s[0] == '?') s[0] = '(';
	if (s[n - 1] == '?') s[n - 1] = ')';
	if (s[0] != '(' || s[n - 1] != ')') return printf("0"), 0;
	dfs(1);
	printf("%lld", ans);
	return 0;
}

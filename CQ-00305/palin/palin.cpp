#include<bits/stdc++.h>
using namespace std;
const int N = 1000010;
int n, a[N], b[N];
bool flag;
void dfs(string s, int l, int r)
{
	if(flag)
		return;
	int x = 2 * n + l - r;
	if(x > 2 * n)
	{
		cout << s << endl;
		flag = 1;
		return;
	}
	b[x] = a[l];
	if(x > n && b[x] == b[2 * n - x + 1])
		dfs(s + "L", l + 1, r);
	else if(x <= n)
		dfs(s + "L", l + 1, r);
	b[x] = a[r];
	if(x > n && b[x] == b[2 * n - x + 1])
		dfs(s + "R", l, r - 1);
	else if(x <= n)
		dfs(s + "R", l, r - 1);
}
int main()
{
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 1; i <= n * 2; i++)
			cin >> a[i];
		flag = 0;
		dfs("", 1, n * 2);
		if(flag == 0)
			cout << -1 << endl;
	}
	return 0;
}


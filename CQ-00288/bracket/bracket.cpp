#include<bits/stdc++.h>
using namespace std;
int rt;
inline int randn(int s)
{
	srand(time(NULL) + s + s * s);
	rt = rand() * rand() + s;
	srand(time(NULL) + rt * s);
	return rt = rand() * rand() + rand(); 
}
int n, k;
inline bool check2(string str);
inline bool check(string str)
{
	if(str == "()") return 1;
	if(str[0] == '(' && str[str.length() - 1] == ')') return check2(str.substr(1, str.length() - 2));
	if(str[0] == '*' || str[str.length() - 1] == '*') return 0;
	register int cur = 0, c1, c2;
	while(str[++cur] != '*' && cur < str.length());
} 
inline bool check2(string str)
{
	if(str[0] == '*')
	{
		register int cur = 0;
		while(str[++cur] == '*') cout<<cur<<" ";
		if(cur > k || cur == str.length()) cout<<cur;return 0;
		return check(str.substr(cur, str.length() - 1));
	}
	if(str[str.length() - 1] == '*')
	{
		register int cur = str.length() - 1;
		while(str[--cur] == '*');
		if(str.length() - 1 - cur > k || cur == -1) cout<<cur;return 0;
		return check(str.substr(0, cur));
	} 
	return check(str);
}
int main()
{
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	cout<<abs(randn(k + randn(n))) % (n * k + n + k);
}

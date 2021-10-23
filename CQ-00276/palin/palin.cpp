#include <bits/stdc++.h>
using namespace std;
#define R register
typedef long long ll;
const int MAXN = 2e5 + 5;
int a[MAXN],b[MAXN];
string Ans;
int n;
void dfs(int x,int l,int r,string s)
{
	if(b[x] != 0 && b[n - x + 1] != 0 && b[x] != b[n - x + 1])return;
	if(x > n)
	{
		for(R int i = 1;i <= n; i++)
			if(b[i] != b[n - i + 1])return;
		if(Ans == "")Ans = s;
		else Ans = min(Ans,s);
		return;
	}
	b[x] = a[l];
	dfs(x + 1,l + 1,r,s + 'L');
	b[x] = a[r];
	dfs(x + 1,l,r - 1,s + 'R');
	b[x] = 0;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t;
	scanf("%d", &t);
	while(t--)
	{
		Ans = "";
		scanf("%d", &n);
		if(n >= 20)
		{
			printf("-1\n");
			continue;
		}
		n = 2 * n;
		for(R int i = 1;i <= n; i++)
			scanf("%d", &a[i]);
		dfs(1,1,n,"");
		if(Ans == "")printf("-1\n");
		else cout << Ans << endl;
	}
	return 0;
}

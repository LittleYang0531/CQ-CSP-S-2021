#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1e6+10;
int T,n,l,r,a[MAXN],b[MAXN];
char ans[MAXN];
int vis[MAXN];

template <typename T>
void read(T &s)
{
	s = 0;
	bool w = false;
	char ch = getchar();
	while(ch < '0' || ch > '9')
	{
		if(ch == '-')
		w = true;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		s = (s<<3) + (s<<1) + (ch^48);
		ch = getchar();
	}
	s = w ? -s:s;
	return;
}

inline bool check()
{
	for(int i = 1;i <= n;i++)
	{
		if(b[i] != b[2 * n - i + 1])
		return false;
	}
	return true;
}

bool dfs(int now)
{
	if(now > 2 * n)
	{
		if(check() == true)
			return true;
		else
			return false;
	}
	b[now] = a[l++];
	ans[now] = 'L';
	if(dfs(now+1) == true)
	return true;
	l--;
	b[now] = a[r--];
	ans[now] = 'R';
	if(dfs(now+1) == true)
	return true;
	r++;
	return false;
}

int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	read(T);
	while(T--)
	{
		read(n);
		l = 1,r = 2*n;
		for(int i = 1;i <= 2*n;i++)
		{
			read(a[i]);
			vis[a[i]]++;
		}
		bool flag = true,cmp = true;
		for(int i = 1;i <= 2 * n;i++)
		{
			if(vis[a[i]] % 2 != 0)
			{
				printf("-1");
				flag = false;
			}
			if(i <= n && a[i] != a[n * 2 - i + 1])
			{
				cmp = false;
			}
			if(flag == false && cmp == false)
				break;
		}
		if(flag == false)
		continue;
		if(cmp == true)
		{
			for(int i = 1;i <= 2 * n;i++)
			{
				printf("L");
			}
			putchar('\n');
			continue;
		}
		if(n >= 5000)
		{
			printf("-1");
			continue;
		}
		if(dfs(1) == true)
		{
			for(int i = 1;i <= 2*n;i++)
			{
				printf("%c",ans[i]);
			}
			putchar('\n');
		}
		else
			printf("-1\n");
	}
	return 0;
}


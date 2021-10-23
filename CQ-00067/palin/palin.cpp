#include <bits/stdc++.h>
using namespace std;
int n;
//1001
char as[2021];
int m=0;
int a[2021],b[2021];
int s[1001];
int l=1,r=2*n;
bool newyear=false;
bool check()
{
	for (int i=1; i<=n; i++)
	{
		if (b[i]!=b[2*n-i+1])
		{
			return false;
		}
	}
	return true;
}
void dfs(int k)
{
	if (newyear) return ;
	if (k>n*2 && check())
	{
		for (int i=1; i<=2*n; i++) printf("%c",as[i]);
		printf("\n");
		newyear=1;
	}
	else if (k>2*n) return ;
	else
	{
		if (k<=n)
		{
			if (s[a[l]]==0)
			{
				s[a[l]]++;
				as[++m]='L';
				b[k]=a[l++];
				dfs(k+1);
				m--;
				l--;
				s[a[l]]--;
			}
			if (s[a[r]]==0)
			{
				s[a[r]]++;
				as[++m]='R';
				b[k]=a[r--];
				dfs(k+1);
				m--;
				r++;
				s[a[r]]--;
			}
		}
		else
		{
			int wa=2*n-(k-1);
			wa=b[wa];
			if (a[l]==wa)
			{
				b[k]=a[l++];
				as[++m]='L';
				dfs(k+1);
				l--;
				m--;
			}

			if (a[r]==wa)
			{
				b[k]=a[r--];
				as[++m]='R';
				dfs(k+1);
				r++;
				m--;
			}

		}
	}
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		newyear=false;
		memset(b,0,sizeof (b));
		memset(a,0,sizeof (a));
		memset(s,0,sizeof (s));
		for (int i=1; i<=n*2; i++)
		{
			scanf("%d",&a[i]);
		}
		l=1;
		r=2*n;
		dfs(1);
		if (!newyear) printf("-1\n");
	}
	return 0;
}

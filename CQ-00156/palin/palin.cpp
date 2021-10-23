#include <bits/stdc++.h>
#define ll long long
using namespace std;
int T,n;
int num[1005];
string best;
int read()
	{
		int x=0,f=1;
		char c=getchar();
		while (c>'9' or c<'0')
			{
				if (c=='-')
					f=-1;
				c=getchar();
			}
		while (c>='0' and c<='9')
			{
				x= (x<<3) + (x<<1) + (c^48);
				c=getchar();
			}
		return x*f;
	}
inline bool check(string s)
	{
		int l=s.size();
		for (int i=0;i<=l/2;i++)
			{
				if (s[i]!=s[l-1-i]) return 0;
			}
		return 1;
	}
int compair(int n,string a,string b)
	{
		if(best=="\0") return 1;
		for (int i=0;i<n;i++)
			{
				if (a[i]>b[i]) return 0;
				if (a[i]<b[i]) return 1;
			}
		return 0;
	}
void dfs(int l,int r,string ans="\0",string sx="\0")
	{
		if (l>r)
			{
				if (check(ans))
					{
						if (compair(n,sx,best))
							best=sx;
					}
				else
					return;
				
			}
		else
			{
				dfs(l+1,r,ans+(char)(num[l]+'0'),sx+'L');
				dfs(l,r-1,ans+(char)(num[r]+'0'),sx+'R');
			}
	}
void print(string s)
	{
		int l=s.size();
		for (int i=0;i<l;i++)
			{
				printf("%c",s[i]);
			}
		printf("\n");
	}
int main()
	{
		freopen("palin.in","r",stdin);
		freopen("palin.out","w",stdout);
		T=read();
		while (T--)
			{
				n=read();n=2*n;best="\0";
				memset(num,0,sizeof(num));
				for (int i=1;i<=n;i++)
					{
						num[i]=read();
					}
				dfs(1,n);
				if (best=="\0") printf("-1\n");
				else print(best);
			}
		return 0;
	}

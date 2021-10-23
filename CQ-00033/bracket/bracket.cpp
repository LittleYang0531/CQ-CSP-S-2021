#include<bits/stdc++.h>
using namespace std;
const int mo=1000000007;
int n,m,nxt[505];
char s[505];
long long f[505][505];//l到r合法序列方案数 
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
		if(s[i]=='*'||s[i]=='?')
		{
			int j=i+1;
			while(j<=n&&(s[j]=='*'||s[j]=='?')) ++j;
			nxt[i]=j-1;
		}
	for(int i=2;i<=n;i++)//区间长度
	{
		for(int l=1,r=i;r<=n;l++,r++)
		{
			if((s[l]=='('||s[l]=='?')&&(s[r]==')'||s[r]=='?'))
			{
				if(i==2) f[l][r]=1;//()
				else
				{
					f[l][r]=f[l+1][r-1];//(A)
					int t=l+1;
					while(t-l<=m&&t<r&&(s[t]=='*'||s[t]=='?')) ++t;
					if(t==r){++f[l][r];}//(S)
					if(s[r-1]=='?'||s[r-1]==')')//(SA)
					{
						t=l+1;
						while(t-l<=m&&t<r-1&&(s[t]=='*'||s[t]=='?'))
						{
							++t;
							if(s[t]=='('||s[t]=='?'){f[l][r]+=f[t][r-1],f[l][r]%=mo;}
						}
					}
					if(s[l+1]=='?'||s[l+1]=='(')//(AS)
					{
						t=r-1;
						while(r-t<=m&&t>l+1&&(s[t]=='*'||s[t]=='?'))
						{
							--t;
							if(s[t]==')'||s[t]=='?'){f[l][r]+=f[l+1][t],f[l][r]%=mo;}
						}
					}
					for(int tx=l+2;tx<=r-1;tx++)
					{
						if((s[tx]=='*'||s[tx]=='?')&&f[l][tx-1])//ASB
							for(int ty=tx+1;ty<r;ty++)
							{
								if(s[ty]=='(')
								{
									
									f[l][r]+=f[l][tx-1]*f[ty][r];
									f[l][r]%=mo;
									break;
								}
								if(s[ty]=='?')
								{
									f[l][r]+=f[l][tx-1]*f[ty][r];
									f[l][r]%=mo;
								}
							}
						if(f[tx][r]&&f[l][tx-1]){f[l][r]+=f[l][tx-1]*f[tx][r],f[l][r]%=mo;}//AB
					}
				}
			}
		}
	}
	printf("%lld\n",f[1][n]);
	return 0;
}
/*
3:
5 1
?????

1-3 6-7
1-4 6-7
*/

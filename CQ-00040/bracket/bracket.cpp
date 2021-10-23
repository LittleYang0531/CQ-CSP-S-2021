#include<bits/stdc++.h>
using namespace std;
const int N=505,M=1e9+7;
char s[N];
int d[N][N],e[N][N],h[N][N];
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	int n,k;
	scanf("%d%d%s",&n,&k,s+1);
	for(int i=1;i<=n;i++)
		e[i][i-1]=1;
	for(int i=2;i<=n;i++)
		for(int j=1,l;j+i<=n+1;j++)
		{
			l=j+i-1;
			if(s[j]==')'||s[j]=='*'||s[l]=='('||s[l]=='*')
			{
				for(int r=l;(s[r]=='*'||s[r]=='?')&&l+1<=k+r&&r>j+1;r--)
					h[j][l]=(h[j][l]+e[j][r-1])%M;
				continue;
			}
			if(i<=k+2)
			{
				d[j][l]=1;
				for(int o=j+1;o<l;o++)
					if(s[o]=='('||s[o]==')')
					{
						d[j][l]=0;
						break;
					}
			}
			for(int o=j+1;(s[o]=='*'||s[o]=='?')&&o<=k+j&&o+2<l;o++)
				d[j][l]=(d[j][l]+e[o+1][l-1])%M;
			for(int o=l-1;(s[o]=='*'||s[o]=='?')&&l<=k+o&&o>j+2;o--)
				d[j][l]=(d[j][l]+e[j+1][o-1])%M;
			if(i>2)
				d[j][l]=(d[j][l]+e[j+1][l-1])%M;
			for(int q=j;q<l;q++)
				if(s[q]=='('||s[q]=='?')
					e[j][l]=(1ll*(h[j][q-1]+e[j][q-1])*d[q][l]+e[j][l])%M;
			for(int r=l;(s[r]=='*'||s[r]=='?')&&l+1<=k+r&&r>j+1;r--)
				h[j][l]=(h[j][l]+e[j][r-1])%M;
		}
	printf("%d",e[1][n]);
}

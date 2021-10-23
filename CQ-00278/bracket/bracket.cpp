#include<bits/stdc++.h>
using namespace std;
int ans,n,m,z[505][505],y[505][505],h[505][505],mo=1e9+7;
char s[505];
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d%s",&n,&m,&s);
	int lens=strlen(s);
	for(int a=0;a<lens;a++)
	{
		if(s[a]=='*'&&s[a-1]!='*')
	}
	for(int a=0;a<lens;a++) 
	{
		if(s[a]=='(') z[a][a]=1;
		else if(s[a]==')') y[a][a]=1;
		else z[a][a]=1,y[a][a]=1;
	}
	for(int len=2;len<=lens;len++)
	{
		for(int l=0;l+len-1<lens;l++)
		{
			int r=l+len-1;
			if((s[l]=='('||s[l]=='?')&&(s[r]==')'||s[r]=='?'))
			{
				if(r-l==1) h[l][r]=1;
				else h[l][r]=h[l+1][r-1];
			    for(int k=l+1;k<r;k++)
			    {
				    h[l][r]=(h[l][r]+y[l+1][k]*z[k+1][r-1])%mo;
			    }
			    for(int k=l+1;k<r;k++)
			    {
				    h[l][r]=(h[l][r]+h[l+1][k]*h[k+1][r-1])%mo;
			    }
			}
			if(s[r]==')'||s[r]=='?') y[l][r]=h[l][r-1];
			if(s[l]=='('||s[l]=='?') z[l][r]=h[l+1][r];
		}
	}
	printf("%d",h[0][lens-1]);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

int lefts[505],other[505],start[505];
char sr[505];
int main(int argc,char **argv)
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	getchar();
	for(int i=1;i<=n;++i) 
	{
		sr[i]=getchar();
		lefts[i]=lefts[i-1];
		other[i]=other[i-1];
		start[i]=start[i-1];
		if(sr[i]=='(') lefts[i]++;
		else if(sr[i]==')') other[i]++;
		else start[i]++;
	}
	for(int i=1;i<=n;++i)
	{
		if(sr[i]=='?')
		{
			//1.
			if(lefts[i]%2!=0)
			{
				other[i]++;
			}
			int gs=0;
			for(int j=i;sr[j]=='*'&&gs<=k;--j) ++gs;
			if(gs>k) lefts[i]++;
			else start[i]++;
		}
	}
	int ans=0;
	for(int i=1;i<=n;++i) 
	{
		if(sr[i]=='?') ans+=lefts[i]*other[i]*start[i];
	}
	printf("%d",ans/4);
	exit(0);
}


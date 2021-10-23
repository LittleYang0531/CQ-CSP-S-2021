#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
typedef long long ll;
const int N=501,mod=1e9+7;
int n,m;
char s[N];
ll f[N][N];	//f[i][j]表示s[i]和s[j]是一对括号并且s[i~j]合法的内部方案 

int main()
{
//	freopen("E:\\CSP2021 S2\\bracket\\bracket1.in","r",stdin);
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d %d",&n,&m);
	scanf(" %s",s+1);
	if(n==1||(s[1]!='('&&s[1]!='?')&&(s[n]!=')'&&s[n]!='?'))
	{
		puts("0");
		return 0;
	}
//	s[1]='(',s[n]=')';
	
	for(int len=1;len<=n;len++)
		for(int i=1;i+len<=n;i++)
		{
			int j=i+len;
			if(s[i]!='('&&s[i]!='?')	continue;
			if(s[j]!=')'&&s[j]!='?')	continue;
			//1
			if(len==1)
			{
				f[i][j]=1;
				continue;
			}
			if(j-i-1<=m)
			{
				bool flag=1;
				for(int k=i+1;k<j&&flag;k++)	flag=(s[k]=='*'||s[k]=='?');
				f[i][j]+=flag;
			}
			//2
			for(int k=i+1;k<j;k++)
				if(s[k]=='*'||s[k]=='?')
					for(int q=k;q<j&&(s[q]=='*'||s[q]=='?')&&q-k+1<=m;q++)
					{
						f[i][j]=(f[i][j]+f[i][k-1]*f[q+1][j])%mod;
					}
			for(int k=i+1;k<j;k++)
				if((s[k]==')'||s[k]=='?')&&(s[k+1]=='('||s[k+1]=='?'))
				f[i][j]=(f[i][j]+f[i][k]*f[k+1][j])%mod;
			//3
			f[i][j]=(f[i][j]+f[i+1][j-1])%mod;
			if(((len+1)&1)==0)
			{
				int mid=(j+i)>>1;
				bool flag=1;
				for(int k=i+1;k<=mid&&flag;k++)
					if(s[k]!='('&&s[k]!='?')	flag=0;
				for(int k=j-1;k>mid&&flag;k--)
					if(s[k]!=')'&&s[k]!='?')	flag=0;
				f[i][j]-=flag;
			}
//			if(s[i+1]=='*'||s[i+1]=='?')
				for(int k=i+1;k<j&&k-i<=m&&(s[k]=='*'||s[k]=='?');k++)
				{
					f[i][j]=(f[i][j]+f[k+1][j-1])%mod;
				}
//			if(s[j-1]=='*'||s[j-1]=='?')
				for(int k=j-1;k>i&&j-k<=m&&(s[k]=='*'||s[k]=='?');k--)
					f[i][j]=(f[i][j]+f[i+1][k-1])%mod;
		}
//	printf("   ");
//	for(int i=1;i<=n;i++)
//		printf("%d ",i);putchar('\n');
//	for(int i=1;i<=n&&printf("%d: ",i);i++,puts(""))
//		for(int j=1;j<=n;j++)
//			printf("%d ",f[i][j]);
	cout<<f[1][n]<<endl;
	return 0;
}


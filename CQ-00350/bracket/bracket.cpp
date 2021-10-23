#include<stdio.h>
using namespace std;
char  a[601];
int d[601];
int idx;
int s1,s2,s3;
int k1,k2,k3;
int n,k;
long long ans;
void dfs(int x,int m1,int m2,int m3)
{
	if(x==idx)
	{
		if(!(a[0]=='('&&a[n-1]==')')) return;
		if((m2+k2)!=(m3+k3)) return;
		for(int i=0;i<n;i++)
		{
			if(a[i]=='*'&&a[i+k]=='*')
			{
				int c=0;
				for(int j=i;j<i+k;j++)
				{
					if(a[j]!='*')
					{
					 c=1;
					 break;	
					} 
				}
				if(c==0) return;
			}
			if(a[i]=='('&&a[i+1]==')')
			{
				if(!(i==0||i+1==n-1))
				{
				   if((i+1)%2==n%2)
				   {
				   	  if(a[i-1]=='*'&&a[i+2]=='*') return;
				   }
				}
			}
		}
		ans++;
		return;
	}
	if(x>idx) return;
	if(d[x]!=0)
	{
		a[d[x]]='*';
		dfs(x+1,m1+1,m2,m3);
		a[d[x]]='?';
	}
	if(d[x]!=n-1&&m2+k2<s2)
	{
		a[d[x]]='(';
		dfs(x+1,0,m2+1,m3);
		a[d[x]]='?';
	}
	if(d[x]!=0&&m3+k3<s3)
	{
		a[d[x]]=')';
		dfs(x+1,m1,m2,m3+1);
		a[d[x]]='?';
	}
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d\n",&n,&k);
	for(int i=0;i<n;i++)
	{
		scanf("%c",&a[i]);
		if(a[i]!='?')
		{
			if(a[i]=='(') k2++;
			else if(a[i]==')') k3++;	
		}
		 
		else
		{
			d[idx]=i;
			idx++;
		}
	}
	s2=(idx+1)/2;
	s3=s2;
	s1=(idx+1)%2;
	dfs(0,0,0,0);
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

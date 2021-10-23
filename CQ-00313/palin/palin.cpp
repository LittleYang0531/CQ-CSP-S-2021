#include<bits/stdc++.h>
using namespace std;
int t,n,l,r;
int a[1000005],b[1000005];
bool check(int a[1000005],int n)
{
	for(int i=1;i<=n/2;i++)if(a[i]!=a[n-i+1])return false;
	return true;
}
char ans[1000005];
bool palin(int i)
{
	if(i<=n/2)
	{
		ans[i]='L';
		b[i]=a[l];
		if(!palin(i+1))
		{
			b[i]=a[r];
			ans[i]='R';
			if(!palin(i+1))
			{
				b[i]=0,ans[i-1]=0;
				return false;
			}
			else 
			{
				r--;
				return true;
			}
		}
		else l++;
		return true;
	}
	else
	{
		if(a[l]!=b[n+1-i]&&a[r]!=b[n+1-i])return false;
		if(a[l]==b[n-i+1])
		{
			b[i]=a[l];
			ans[i]='L';
			if(!palin(i+1))
			{
				b[i]=0,ans[i]=0;
				if(a[r]!=b[n-i+1])return false;
				else
				{
					b[i]=a[r];
					ans[i]='R';
					if(!palin(i+1))
					{
						b[i]=0,ans[i]=0;
						return false;
					}
					else 
					{
						r--;
						return true;
					}
				}
			}
			else 
			{
				l++;
				return true;
			}
		}
		else
		{
			if(a[r]!=b[n-i+1])return false;
			else
			{
				b[i]=a[r];
				ans[i]='R';
				if(!palin(i+1))
				{
					b[i]=0,ans[i]=0;
					return false;
				}
				else 
				{
					r--;
					return true;
				}
			}
		}
	}
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		n*=2;
		l=1,r=n;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		if(!palin(1))printf("-1\n");
		else 
		{
			for(int i=1;i<=n;i++)printf("%c",ans[i]);
			printf("\n");
		}	
	}
	return 0;
}

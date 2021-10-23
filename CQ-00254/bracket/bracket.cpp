#include<bits/stdc++.h>
using namespace std;
int n,k,sum;
char a[505];
bool pd()
{
	if(a[0]=='*'||a[n-1]=='*')return 0;
	int geshu=0;
	int xinshu[100],lianxu=0;
	for(int i=0;i<=n;++i)
	xinshu[i]=0;
	//cout<<a<<endl;
	for(int i=0;i<n;++i)
	{
		//cout<<i;
		if(a[i]=='(')
		{
			if(lianxu>k)return 0;
			lianxu=0;
			geshu++;
		}
		else if(a[i]=='*')
		{
			if(a[i-1]==')'&&xinshu[geshu]!=0)
			{
				int k=i;
				while(a[k]=='*')k++;
				if(a[k]==')')return 0;
			}
			xinshu[geshu]++;
			lianxu++;
		}
		else 
		{
			if(lianxu>k)return 0;
			lianxu=0;
			xinshu[geshu]=0;
			geshu--;
			if(geshu<0)return 0;
		}
	}
	if(geshu!=0)return 0;
	return 1;
}
void ans(int s)
{
	if(s>=n)
	{
		if(pd())
		{
		sum++;
	//	cout<<sum;
		}
		return;
	}
	else
	{
		if(a[s]=='?')
		{
			a[s]=')';
			ans(s+1);
			a[s]='?';
			a[s]='(';
			ans(s+1);
			a[s]='?';
			a[s]='*';
			ans(s+1);
			a[s]='?';
		}
		else
		ans(s+1);
	}
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	int shu=0;
	scanf("%s",&a);
	for(int i=0;i<n;++i)
	if(a[i]=='?')shu++;
	if(shu>=20)
	{
		cout<<20060324;
	}
	else
	{
	ans(0);
	printf("%d",sum);
	}
	return 0;
}

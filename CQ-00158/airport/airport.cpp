#include<iostream>
#include<cstdio>
using namespace std;
int n, m1, m2, s[100000], sum=0;
int p1(int);
int p2(int);
struct n
{
	int a1, a2;
}a[100000];
struct w
{
	int b1, b2;
}b[100000];
int main()
{
	freopen("airport.in","r",stdin); freopen("airport.out","w",stdout);
	int m, M;
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++)
	{
		cin>>a[i].a1>>a[i].a2;
	}
	for(int i=1;i<=m2;i++)
	{
		cin>>b[i].b1>>b[i].b2;
	}
	for(int i=0;i<=n;i++)
	{
		int m=i; M=n-i;
		if(sum<p1(m)+p2(M))
		{
			sum=p1(m)+p2(M);
		}
	}
	cout<<sum;
	fclose(stdin); fclose(stdout);
	return 0;
}
int p1(int x)
{
	int s1=0;
	for(int i=1;i<=m1;i++)
	{
		for(int j=1;j<=x;j++)
		{
			if(a[i].a1>=s[j])
			{
				s1++;
				s[j]=a[i].a2;
				break;
			}
		}
	}
	for(int k=1;k<=x;k++)
	{
		s[k]=0;
	}
	return s1;
}
int p2(int y)
{
	int s2=0;
	for(int i=1;i<=m2;i++)
	{
		for(int j=1;j<=y;j++)
		{
			if(b[i].b1>=s[j])
			{
				s2++;
				s[j]=b[i].b2;
				break;
			}
		}
	}
	for(int k=1;k<=y;k++)
	{
		s[k]=0;
	}
	return s2;
}

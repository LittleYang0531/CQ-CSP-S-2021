#include<bits/stdc++.h>
using namespace std;

int N;
int M1;
int M2;
int ans;
int w1[100005];
int w2[100005];
int vis1[100005];
int vis2[100005];

struct f
{
	int l;
	int r;
}a[100005],b[100005];

bool cmp(f x,f y)
{
	return  x.l<y.l;
}

void deal()
{
	int ok=1;
	for(int i=1;i<=M1;i++)
	{
		if(vis1[i])
		{
			continue;
		}
		int id=a[i].r;
		int k=1;
		for(int j=i+1;j<=M1;j++)
		{
			if(vis1[j])
			{
				continue;
			}
			if(id<a[j].l)
			{
				k++;
				vis1[j]=1;
				id=a[j].r;
			}
		}
		w1[ok]=k;	
		ok++;
	}
	ok=1;
	for(int i=1;i<=M2;i++)
	{
		if(vis2[i])
		{
			continue;
		}
		int id=b[i].r;
		int k=1;
		for(int j=i+1;j<=M2;j++)
		{
			if(vis2[j])
			{
				continue;
			}
			if(id<b[j].l)
			{
				k++;
				vis2[j]=1;
				id=b[j].r;
			}
		}
		w2[ok]=k;
		ok++;
	}
}

int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>N>>M1>>M2;
	for(int i=1;i<=M1;i++)
	{
		cin>>a[i].l>>a[i].r;
	}
	for(int i=1;i<=M2;i++)
	{
		cin>>b[i].l>>b[i].r;
	}
	sort(a+1,a+M1+1,cmp);
	sort(b+1,b+M2+1,cmp);
	deal();
	for(int i=0;i<=N;i++)
	{
		int j=N-i;
		int sum=0;
		for(int k=1;k<=i;k++)
		{
			sum+=w1[k];
		}
		for(int k=1;k<=j;k++)
		{
			sum+=w2[k];
		}
		ans=max(ans,sum);
	}
	cout<<ans<<endl;
	return 0;
}

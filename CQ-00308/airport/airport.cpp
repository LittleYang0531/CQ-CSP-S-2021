#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;

struct node
{
	int d,c,t;
	int g;
}a[N],b[N];
priority_queue<int,vector<int>,greater<int> > q;
bool cmp(node x,node y)
{
	return x.d<y.d?1:0;
}
int n,m1,m2;
bool gl,gw;
int sa[N],sb[N];
int s=0;
int pl,pw;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++)	
	{
		gl=0;
		cin>>a[i].d>>a[i].c;
		for(int j=1;j<=i;j++)
			if(a[i].d>a[j].c)
			{
				gl=1;
				break;
			}
		if(!gl)
		pl++;	
	}
	int s=0;
	int p[N];
	for(int i=1;i<=pl&&i<=n;i++)
	{
		for(int j=1;j<=m1;j++)
			if(a[j].d>=p[i]&&!a[j].g)
			{
				p[i]=a[j].c;
				s++;
				a[j].g=1;
			}
		sa[i]=s;
	}
	for(int i=1;i<=m2;i++)
	{
		gw=0;
		cin>>b[i].d>>b[i].c;
		for(int j=1;j<=i;j++)
			if(b[i].d>b[j].c)
			{
				gw=1;
				break;
			}		
		if(!gw)
		pw++;
	}
	s=0;
	memset(p,0,sizeof p);
	for(int i=1;i<=pw&&i<=n;i++)
	{
		for(int j=1;j<=m2;j++)
			if(b[j].d>=p[i]&&!b[j].g)
			{
				p[i]=b[j].c;
				b[j].g=1;
				s++;
			}
		sb[i]=s;
	}
	int maxe=0;
	for(int i=1;i<=n;i++)
		maxe=max(maxe,sa[i]+sb[n-i]);
	cout<<maxe<<endl;
	return 0;
}

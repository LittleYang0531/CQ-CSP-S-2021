#include<bits/stdc++.h>
using namespace std;
int n,m1,m2,naxx=0;
struct ban
{
	int l,r;
}G_in[100100],G_out[100100];
bool cmp(ban x,ban y)
{
	return x.l<y.l;
}
void Deal(int x)//x->G_in
{
//	cout<<x<<":"<<endl;
	int ans=0;
	priority_queue< int , vector<int> , greater<int> > q,qu;
	if(x!=0)
	{
		int k=1;q.push(G_in[1].r);ans++;
		for(int i=2;i<=m1;i++)
		{
			if(G_in[i].l>q.top())
			{
				q.pop();
				q.push(G_in[i].r);
				ans++;
			}
			else if(k<x)
			{
				k++;
				ans++;
				q.push(G_in[i].r);
			}
			if(ans+m1-i+1+m2<naxx) break;
		}
	}
//	cout<<ans<<" ";
	if(x!=n)
	{
		int k=1;qu.push(G_out[1].r);ans++;
		for(int i=2;i<=m2;i++)
		{
			if(G_out[i].l>qu.top())
			{
				qu.pop();
				qu.push(G_out[i].r);
				ans++;
			}
			else if(k<n-x)
			{
				k++;
				ans++;
				qu.push(G_out[i].r);
			}
			if(ans+m2-i+1<naxx) break;
		}
	}
//	cout<<ans<<endl;
	naxx=max(ans,naxx);
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++)
	{
		cin>>G_in[i].l>>G_in[i].r;
	}
	for(int i=1;i<=m2;i++)
	{
		cin>>G_out[i].l>>G_out[i].r;
	}
	sort(G_in+1,G_in+m1+1,cmp);
	sort(G_out+1,G_out+m2+1,cmp);
	for(int i=0;i<=n;i++) Deal(i);
	cout<<naxx<<endl;
	return 0;
}

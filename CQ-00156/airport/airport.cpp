#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,m1,m2;
struct Plane{
	int inti,otti;
}plane1[100005],plane2[100005];
priority_queue<int> ing,otg;
int res[100005][2];
int t1,t2,ans;
bool cmp(Plane a,Plane b)
	{
		return a.inti<b.inti;
	}
int read()
	{
		int x=0,f=1;
		char c=getchar();
		while (c>'9' or c<'0')
			{
				if (c=='-')
					f=-1;
				c=getchar();
			}
		while (c>='0' and c<='9')
			{
				x= (x<<3) + (x<<1) + (c^48);
				c=getchar();
			}
		return x*f;
	}
int main()
	{
		freopen("airport.in","r",stdin);
		freopen("airport.out","w",stdout);
		n=read();m1=read();m2=read();
		for (int i=1;i<=m1;i++)
			{
				plane1[i].inti=read();
				plane1[i].otti=read();
				t1=max(t1,plane1[i].otti);
			}
		for (int i=1;i<=m2;i++)
			{
				plane2[i].inti=read();
				plane2[i].otti=read();
				t2=max(t2,plane2[i].otti);
			}
		sort(plane1,plane1+m1,cmp);
		sort(plane2,plane2+m2,cmp);
		for (int a=0;a<=n;a++)
			{
				int p=1;
				int b=n-a;
				for(int i=1;i<=t1;i++)
					{
						if (a==0) break;
						if (!ing.empty())
							{
								if (t1-(int)ing.top()==i)
									{
										ing.pop();
										res[a][1]++;
									}	
							}
						if (plane1[p].inti==i)
							{
								if (ing.size()<a)
									ing.push(t1-plane1[p].otti);
								p++;
							}
					}
				p=1;
				for(int i=1;i<=t2;i++)
					{
						if (b==0) break;
						//cout<<endl<<otg.top()<<endl<<endl;
						if (!otg.empty())
							{
								if (t2-(int)otg.top()==i)
									{
										otg.pop();
										res[a][0]++;
									}	
							}
						if (plane2[p].inti==i)
							{
								if (otg.size()<b)
									otg.push(t2-plane2[p].otti);
								p++;
							}
					}
			}
		for (int i=0;i<=n;i++)
			{
				ans=max(ans,res[i][1]+res[i][0]);
			}
		cout<<ans;
		return 0;
	}

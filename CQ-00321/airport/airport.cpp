#include<bits/stdc++.h>
using namespace std;
int n,m1,m2,ans;
struct node
{
	int s,t;
	bool operator <(const node &T) const
	{
		return s < T.s;
	}
} arrx[100005],arry[100005];
struct nobe
{
	int val,s,t;
	bool vis;
	bool operator <(const nobe &T) const
	{
		return val < T.val;
	}
} arr[100005];
struct edgo
{
	int num;
	map<int,bool> vis;
} num[100005];
int a[100005],b[100005],cnt,sum[100005];
int f[100005],g[100005];
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i = 1 ; i <= m1 ; i++) scanf("%d %d",&arrx[i].s,&arrx[i].t),arr[++cnt].s = arrx[i].s,arr[cnt].t = arrx[i].t,arr[cnt].val = arrx[i].s,arr[cnt].vis = 1,arr[++cnt].s = arrx[i].s,arr[cnt].t = arrx[i].t,arr[cnt].val = arrx[i].t;
	sum[0] = 0;
	sort(arr + 1,arr + cnt + 1);
	for(int i = 1 ; i <= cnt ; i++)
	{
		if(arr[i].vis)
		{
			arr[i].vis = 0;
			sum[i] = sum[i - 1] + 1;
			for(int j = 1 ; j <= n ; j++) 
			{
				if(num[j].num + 1 <= j)
				{
					num[j].num++;
					num[j].vis[arr[i].s] = true;
					f[j]++;
				}
			}
		}
		else
		{
			sum[i] = sum[i - 1] - 1;
			for(int j = 1 ; j <= n ; j++)
			{
				if(num[j].vis[arr[i].s] == 1)
				{
					num[j].num--;
					num[j].vis[arr[i].s] = false;
				}
			}
		}
//		for(int j = 1 ; j <= n ; j++) cout<<num[j].num<<' ';
//		cout<<arr[i].val<<',';
	}
	cnt = 0;
	for(int i = 1 ; i <= m2 ; i++) scanf("%d %d",&arry[i].s,&arry[i].t),arr[++cnt].s = arry[i].s,arr[cnt].t = arry[i].t,arr[cnt].val = arry[i].s,arr[cnt].vis = 1,arr[++cnt].s = arry[i].s,arr[cnt].t = arry[i].t,arr[cnt].val = arry[i].t;
	sum[0] = 0;
	sort(arr + 1,arr + cnt + 1);
	for(int i = 1 ; i <= cnt ; i++)
	{
		if(arr[i].vis)
		{
			arr[i].vis = 0;
			sum[i] = sum[i - 1] + 1;
			for(int j = 1 ; j <= n ; j++) 
			{
				if(num[j].num + 1 <= j)
				{
					num[j].num++;
					num[j].vis[arr[i].s] = true;
					g[j]++;
				}
			}
		}
		else
		{
			sum[i] = sum[i - 1] - 1;
			for(int j = 1 ; j <= n ; j++)
			{
				if(num[j].vis[arr[i].s] == 1)
				{
					num[j].num--;
					num[j].vis[arr[i].s] = false;
				}
			}
		}
//		for(int j = 1 ; j <= n ; j++) cout<<num[j].num<<' ';
//		cout<<arr[i].val<<',';
	}
	cnt = 0;
	for(int i = 0 ; i <= n ; i++)
	{
//		cout<<f[i]<<' '<<g[n - i]<<endl;
		ans = max(ans,f[i] + g[n - i]);
	}
	cout<<ans;
	return 0;
}

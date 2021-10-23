#include<bits/stdc++.h>
using namespace std;
int n,a[1000005];
int q1;
char d[1000005];
int used[1000005],chs[1000005];
deque <int> q;
bool t=0,if_cout=0;
void dfs(int x)
{
	if (x==q1*2+1)
	{
		t=1;
		if (if_cout==0)
		{
			for (int i=1;i<=q1*2;i++)
			{
				printf("%c",d[i]);
			}
			printf("\n");
			if_cout=1;
			return;
		}
		
	}
	else
	{
		if (x<=q1)
		{
			if (used[q.front()]==0 && if_cout==0)
			{
				int p=q.front();
				q.pop_front();
				used[p]++;
				d[x]='L';
				chs[x]=p;
				dfs(x+1);
				chs[x]=0;
				used[p]--;
				q.push_front(p);
			}
			if (used[q.back()]==0 && if_cout==0)
			{
				int p=q.back();
				used[p]++;
				q.pop_back();
				d[x]='R';
				chs[x]=p;
				dfs(x+1);
				chs[x]=0;
				used[p]--;
				q.push_back(p);
			}
		}
		else
		{
			if (used[q.front()]==1 && q.front()==chs[2*q1+1-x] && if_cout==0)
			{
				int p=q.front();
				q.pop_front();
				used[p]++;
				d[x]='L';
				dfs(x+1);
				used[p]--;
				q.push_front(p);
			}
			if (used[q.back()]==1 && q.back()==chs[2*q1+1-x] && if_cout==0)
			{
				int p=q.back();
				q.pop_back();
				used[p]++;
				d[x]='R';
				dfs(x+1);
				used[p]--;
				q.push_back(p);
			}
		}
		
	}
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		memset(a,0,sizeof(a));
		memset(used,0,sizeof(used));
		t=0;
		scanf("%d",&q1);
		q.clear();
		if_cout=0;
		for (int i=1;i<=q1*2;i++)
		{
			scanf("%d",&a[i]);
			q.push_back(a[i]);
		}
		dfs(1);
		if (t==0) printf("-1\n");
	}
	//I love TLE so much!!! 48pts
	//20060324 
	return 0;
}

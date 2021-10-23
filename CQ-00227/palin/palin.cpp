#include<bits/stdc++.h>
using namespace std;
#define re register int
#define LL long long

char ans[105][500005];
int pos[500005][5], a[500005], mk[500005], cas, step, n;
inline bool check1(int l, int r, int fr, int to)
{
	int x=a[l];
	if(pos[x][0]==l)
	{
		if(step) return fr<=pos[x][1] && pos[x][1]<=to;
		fr=min(fr, pos[x][1]-1);
		to=max(to, pos[x][1]+1);
	}
	else
	{
		if(step) return fr<=pos[x][0] && pos[x][0]<=to;
		fr=min(fr, pos[x][0]-1);
		to=max(to, pos[x][0]+1);
	}
	{
		int x=a[l+1];
		int y=(pos[x][1]==l+1)^1;
		int p=pos[x][y];
		if(fr<=p && p<=to)return 1;
	}
	{
		int x=a[r];
		int y=(pos[x][1]==r)^1;
		int p=pos[x][y];
		if(fr<=p && p<=to)return 1;
	}
	return 0;
}
inline bool check2(int l, int r, int fr, int to)
{
	int x=a[r];
	if(pos[x][0]==r)
	{
		if(step) return fr<=pos[x][1] && pos[x][1]<=to;
		fr=min(fr, pos[x][1]-1);
		to=max(to, pos[x][1]+1);
	}
	else
	{
		if(step)return fr<=pos[x][0] && pos[x][0]<=to;
		fr=min(fr, pos[x][0]-1);
		to=max(to, pos[x][0]+1);
	}
	{
		int x=a[l];
		int y=(pos[x][1]==l)^1;
		int p=pos[x][y];
		if(fr<=p && p<=to)return 1;
	}
	{
		int x=a[r-1];
		int y=(pos[x][1]==r-1)^1;
		int p=pos[x][y];
		if(fr<=p && p<=to)return 1;
	}
	return 0;
}
inline bool dfs(int l, int r, int fr, int to)
{
	if(l == r)
	{
		ans[cas][++step]='L';
		printf("%s\n", ans[cas]+1);
		return 1;
	}
	if(a[l] == a[r])
	{
		ans[cas][++step]='L';
		mk[l]=step;
		mk[r]=2*n-step+1;
		return dfs(l+1, r, 0, 0);
	}
	if(step>=n)
	{
		step++;
		if(mk[l]==step){ans[cas][step]='L';return dfs(l+1, r, 0, 0);}
		if(mk[r]==step){ans[cas][step]='R';return dfs(l, r-1, 0, 0);}
		return 0;
	}
	if(l<fr && check1(l, r, fr, to))
	{
		ans[cas][++step]='L';
		int x=a[l];
		int y=(l==pos[x][1])^1;
		
		mk[l]=step;
		mk[pos[x][y]]=2*n-step+1;
		
		if(pos[x][0]==l)
		{
			fr=min(fr, pos[x][1]-1);
			to=max(to, pos[x][1]+1);
		}
		else
		{
			fr=min(fr, pos[x][0]-1);
			to=max(to, pos[x][0]+1);
		}
		
		return dfs(l+1, r, fr, to);
	}
	if(r>to && check2(l, r, fr, to))
	{
		ans[cas][++step]='R';
		int x=a[r];
		int y=(pos[x][1]==r)^1;
		
		mk[r]=step;
		mk[pos[x][y]]=2*n-step+1;
		
		if(pos[x][0]==r)
		{
			fr=min(fr, pos[x][1]-1);
			to=max(to, pos[x][1]+1);
		}
		else
		{
			fr=min(fr, pos[x][0]-1);
			to=max(to, pos[x][0]+1);
		}
		return dfs(l, r-1, fr, to);
	}
	return 0;
}
inline void work()
{
	step=0;
	scanf("%d",&n);
	for(re i=1;i<=2*n;++i) mk[i]=0;
	for(re i=1;i<=2*n;++i)
	{
		scanf("%d",&a[i]);
		if(!pos[a[i]][0])pos[a[i]][0]=i;
		else pos[a[i]][1]=i;
	}
	if(!dfs(1, 2*n, 100000, 0))puts("-1");
	return;
}
signed main()
{
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	int T;
	scanf("%d",&T);
	for(cas=1;cas<=T;++cas)work();
	return 0;
}

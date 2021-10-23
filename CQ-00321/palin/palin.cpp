#include<bits/stdc++.h>
using namespace std;
int t,n;
int x[1000005];
int pre[1000005];
char ans[10000005];
bool flag;
void dfs(int l,int r,int k)
{	
//	cout<<l<<' '<<r<<endl;
	if(flag) return;
	if(k == n * 2 + 1)
	{
		for(int i = 1 ; i <= n * 2 ; i++) cout<<ans[i];
		cout<<endl;
		flag = true;
		return;
	}
	int t = k - 1;
	if(l > r) return;
	if(t > n)
	{
		if(pre[t] != pre[n * 2 + 1 - t]) return;
	}
	pre[k] = x[l];
	ans[k] = 'L';
	dfs(l + 1,r,k + 1);
	pre[k] = x[r];
	ans[k] = 'R';
	dfs(l,r - 1,k + 1);
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>t;
	while(t--)
	{
		flag = false;
		cin>>n;
		for(int i = 1 ; i <= 2 * n ; i++) cin>>x[i];
		dfs(1,n * 2,1);
		if(!flag) cout<<-1<<endl;
	}
	return 0;
}
/*
2 4 4 2 4 2 4 4 2 4
3 3 2 0 0 1 1 2 4 4
4 1 2 4 5 3 1 2 3 5
--- - - ----- - - -
*/

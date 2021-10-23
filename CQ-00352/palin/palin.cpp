#include<bits/stdc++.h>
using namespace std;
int T,n;
bool bb=false;
char ans[205]={'0'};
void dfs(int wei,int A[205],int B[205],char lr)
{
	if(wei==2*n+1)
	{
		for(int i=1;i<=n;i++)
			if(B[i]!=B[2*n+1-i]) return;
		bb=true;
		ans[wei]=lr;
		return;
	}
	if(lr=='L')//left
	{
		B[wei]=A[1];
		for(int i=1;i<2*n+1-wei;i++)
			A[i]=A[i+1];
		A[2*n+1-wei]=0;
		
	}
	else
	{
		B[wei]=A[2*n+1-wei];
		A[2*n+1-wei]=0;
	}
	dfs(wei+1,A,B,'L');
	if(bb)
	{
		ans[wei]=lr;
		return;
	}
	dfs(wei+1,A,B,'R');
	if(bb)
	{
		ans[wei]=lr;
		return;
	}
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		cin>>n;
		int A[205];
		for(int j=1;j<=2*n;j++)
			cin>>A[j];
		int B[205]={0};
		dfs(1,A,B,'L');
		ans[1]='L';
		if(ans[2]=='0')
		{
			int C[205]={0};
			dfs(1,A,C,'R');
			ans[1]='R';
			if(ans[2]=='0')
			{
				cout<<-1<<endl;
				continue;
			}
		}
		for(int j=1;j<=2*n;j++)
			cout<<ans[j];
		cout<<endl;
		ans[0]='0';
		bb=false;
		memset(ans,'0',sizeof(ans));
	}
	return 0;
}

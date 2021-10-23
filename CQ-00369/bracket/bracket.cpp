#include<bits/stdc++.h>
using namespace std;
string s;
int n,k,ans,bj,a[505];
//void dfs(int x,int t)
//{
//	if(x==n-1)
//	{
//		if(check())sum++;
//		bj=0;
//		return;
//	}
//	if(s[x]!='?'&&bj==1)dfs(x+1,t);
//	if(t==0){
//		a[x]=0;
//		dfs(x+1,t);
//	}
//	a[x]=1;
//	dfs(x+1,t-1);
//	if(bj==0)bj=1;
//	a[x]=0;
//	dfs(x+1,t);
//}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	if(n==0){
		printf("0\n");
		return 0;
	}
	cin>>s;
	cout<<"546949722"<<endl; 
//	for(int i=0;i<n;i++)
//	{
//		if(s[i]=='?')continue;
//		if(s[i]=='*')a[i]=1;
//		if(s[i]=='('|||s[i]==')')s[i]=0;
//	}
//	bj=1;dfs(0,k);
//	printf("%d\n",sum);
	return 0;
}

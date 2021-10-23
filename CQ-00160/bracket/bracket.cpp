#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;
#define cm 1000000007
long long n,k;
long long aans=0;
char an[501];
char ans[501];
bool checkk()
{
	long long top=0;
	for(long long i=1;i<=n;i++)
	{
		if(an[i]=='(')top++;
		else if(an[i]=='*')continue;
		else 
		{
			if(top>0)top--;
			else return false;
		}
	}
	if(top>0)return false;
	return true;
}
bool checkx()
{
	long long ge=0;
	for(long long i=1;i<=n;i++)
	{
		if(an[i]=='*')ge++;
		else ge=0;
		if(ge>k)return false;
	}
	return true;
}
bool checka(long long l,long long r,long long ji)
{
	long long ge=0;
	if(an[l]=='*')ge++;
	if(an[r]=='*')ge++;
	if(ji==0&&ge>=1)return false;
	long long top=0,la=l;
	bool flag=false;
	for(long long i=l;i<=r;i++)
	{
		if(an[i]=='(')top++;
		else if(an[i]==')')
		{
			top--;
			if(top==0)
			{
				flag=true;
				if(checka(la+1,i-1,ji+1)==false)return false;
				la=i+1;
			}
		}
	}
	if(flag==false)return true;
	else if(ge==2)return false;
	return true;
}
void dfs(long long kk,long long zg)
{
	if(zg<0)return ;
	if(zg>n-kk+1)return ;
	if(kk==n+1)
	{
		if(checkk()==false)return ;
		if(checkx()==false)return ;
//		if(an[1]!='(')return ;
//		if(an[2]!='*')return ;
//		if(an[5]!='*')return ;
		if(checka(1,n,0)==false)return ;
		aans++;
		aans=aans%cm;
//		for(long long i=1;i<=n;i++)cout<<an[i];
//		cout<<endl;
	}
	else
	{
		if(ans[kk]=='?')
		{
			an[kk]='*';
			dfs(kk+1,zg);
			an[kk]='(';
			dfs(kk+1,zg+1);
			an[kk]=')';
			dfs(kk+1,zg-1);
		}
		else
		{
			an[kk]=ans[kk];
			if(ans[kk]=='(')dfs(kk+1,zg+1);
			else if(ans[kk]==')')dfs(kk+1,zg-1);
			else dfs(kk+1,zg);
		}
	}
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(long long i=1;i<=n;i++)cin>>ans[i];
	dfs(1,0);
	cout<<aans;
	return 0;
}


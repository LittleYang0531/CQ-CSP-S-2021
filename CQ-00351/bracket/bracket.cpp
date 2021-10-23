#include<bits/stdc++.h>
using namespace std;
int n,k,ans=0;
char s[1010];char Ders[1010];
void dfs(int x,int cn,int su)
{
	if(cn<0||su>k) return;
	if(x==n+1)
	{
		int cnt=0,sum=0,top=0;
		char Ch[1010];
//		cout<<endl;
		for(int i=1;i<=n;i++)
		{
			
			if(Ders[i]=='(') cnt++,sum=0;
			if(Ders[i]==')') cnt--,sum=0;
			if(Ders[i]=='*') sum++;
			if(sum>k) return;
			if(cnt<0) return;
			Ch[++top]=Ders[i];
			if(Ch[top]==')') 
			{
				while(Ch[top]!='(') top--;top--;
				if(Ch[top]=='*'&&Ders[i+1]=='*') return;
			}
//			cout<<Ders[i];
		}
		if(cnt==0&&sum==0&&Ders[n]==')') 
		{
			ans++;
//			cout<<"!!!";
		}
		return;
	}
	if(s[x]!='?')
	{
		Ders[x]=s[x];
		if(s[x]=='(')
		dfs(x+1,cn+1,0);
		if(s[x]==')')
		dfs(x+1,cn-1,0);
		if(s[x]=='*')
		dfs(x+1,cn,su+1);
	}
	if(s[x]=='?')
	for(int i=1;i<=3;i++)
	{
		if(i==1)
		{
			if(x!=n){Ders[x]='(';dfs(x+1,cn+1,0);
			}
		}
		else if(i==2){
			Ders[x]=')';dfs(x+1,cn-1,0);
		}
		else if(i==3)
		{
			if(x!=1&&x!=n){
				Ders[x]='*';dfs(x+1,cn,su+1);
			}
		}
	}
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	cin>>(s+1);
	dfs(1,0,0);
	cout<<ans<<endl;
	return 0;
}

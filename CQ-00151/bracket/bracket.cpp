#include<bits/stdc++.h>
using namespace std;

int N;
int K;
int cnt;
int ans;
string str;
char s[505];
int id[505];
int vis[505];
char d[]={'0','(',')','*'};

struct f
{
	int x;
	int y;
}e[505];

bool check(string k)
{
	memset(e,0,sizeof e);
	if(k[0]=='*'||k[N-1]=='*')
	{
		return false;
	}
	memset(vis,-1,sizeof vis);
	int ant=0;
	for(int i=0;i<N;i++)
	{
		if(k[i]==')')
		for(int j=i-1;j>=0;j--)
		{
			if((vis[j]==-1)&&(k[j]=='('))
			{
				vis[i]=0;
				vis[j]=0;
				e[ant].x=j;
				e[ant].y=i;
				ant++;
				break;
			}
		}
	}
	for(int i=0;i<N;i++)
	{
		if(vis[i]==-1)
		{
			if((k[i]=='(')||(k[i]==')'))
			{
				return false;
			}
		}
	}
	for(int i=1;i<=ant;i++)
	{
		int l=e[i].x-1;
		int knt1=0;
		while(k[l]=='*'&&l>=0)
		{
			knt1++;
			l--;
		}
		int r=e[i].y+1;
		int knt2=0;
		while(k[r]=='*'&&r<N)
		{
			knt2++;
			r++;
		}
		if(knt1==knt2&&knt1!=0)
		{
			return false;
		}
		if(knt1>K||knt2>K)
		{
			return false;
		}
	}
	for(int i=1;i<=ant;i++)
	{
		int x=e[i].x;
		int y=e[i].y;
		bool ok=true;
		for(int j=x+1;j<=y-1;j++)
		{
			if(k[j]!='*')
			{
				ok=false;
			}
		}
		if(ok==true)
		{
			int m=y-x;
			if(m>K+1)
			{
				return false;
			}
		}
	}
	return true;
}

void dfs(int x,string k)
{
	if(x==1+cnt)
	{
		if(check(k))
		{
			ans++;
		}
		return ;
	}
	for(int i=1;i<=3;i++)
	{
		k[id[x]]=d[i];
		dfs(x+1,k);
	}
}

int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>N>>K;
	for(int i=1;i<=N;i++)
	{
		cin>>s[i];
		str+=s[i];
		if(s[i]=='?')
		{
			id[++cnt]=i-1;
		}
	}
	dfs(1,str);
	cout<<ans<<endl;
	return 0;
}

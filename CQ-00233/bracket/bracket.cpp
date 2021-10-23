#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5;
int n,K,cnt,ans;
int wh[N];
char CH[5]={'(',')','*'};
string s;

void dfs(int k,string ch)
{
	if(k==cnt+1)
	{
		int lcnt=0,rcnt=0;
		for(int i=0;i<s.size();i++)
		{
			if(ch[i]=='(') lcnt++;
			if(ch[i]==')') rcnt++;
		}
		if(lcnt!=rcnt) return;
		for(int i=0;i<s.size();i++)
		{
			if(ch[i]=='*')
			{
				int l=i-1,r=i+1,cnt1=1;
				while(l!=-1)
				{
					if(ch[l]=='*') cnt1++;
					else break;
					l--;
				}
				while(r!=s.size())
				{
					if(ch[r]=='*') cnt1++;
					else break;
					r++;
				}
				if(cnt1>K) return ;
				if(ch[l]=='(' && ch[r]=='(')
				{
					lcnt=1;
					int qr=r+1;
					while(qr!=s.size())
					{
						if(ch[qr]=='(') lcnt++;
						if(ch[qr]==')') lcnt--;
						if(lcnt==0) break;
						qr++;
					}
					if(ch[qr+1]=='*')
					{
						int xr=qr+2,f=0;
						while(xr!=s.size())
						{
							if(xr=='(')
							{
								f=1;
								break;
							}
							if(xr==')') break;
							xr++;
						}
						if(f==0) return ;
					}
				}
			}
		}
		ans++;
		return ;
	}
	for(int i=0;i<3;i++)
	{
		ch[wh[k]]=CH[i];
		dfs(k+1,ch);
		ch[wh[k]]='?';
	}
}

signed main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%lld %lld",&n,&K);
	cin>>s;
	if(s[0]=='?') s[0]='(';
	if(s[0]!='(')
	{
		printf("0");
		return 0;
	}
	if(s[s.size()-1]=='?') s[s.size()-1]=')';
	if(s[s.size()-1]!=')')
	{
		printf("0");
		return 0;
	}
	for(int i=0;i<s.size();i++)
		if(s[i]=='?') wh[++cnt]=i;
	dfs(1,s);
	printf("%lld",ans);
	return 0;
 } 

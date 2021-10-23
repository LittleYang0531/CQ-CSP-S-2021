#include<bits/stdc++.h>
using namespace std;
int k,n,ans;
string ss,co1,co2,co3;
bool check(string s)
{
	int lk=0,rk=0;
	for(int i=0;i<ss.size();i++)
	{
		if(s[i]=='(') lk++;
		if(s[i]==')') rk++;
	}
	if(lk!=rk) return 0;
	int cnt=0;
	string ne;
	if(s.size()==0) return 1;
	if(ss[0]!='('||ss[ss.size()-1]!=')') 
	{
		return 0;
	}	
	for(int l=1;l<s.size();l++)
	{
		for(int r=s.size()-2;r>=0&&l<=r;r--)
		{
			if(s[l]=='*') cnt++;
			if(s[r]=='*') cnt++;
			if(cnt>k) return 0;
			int p=0;
			if(s[l]!='*'&&s[r]!='*') 
			{
				for(int i=l;i<=r;i++) ne[p++]=s[i];
				return check(ne);
			}
		}
	}
	return 0;
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	cin>>ss;
	for(int i=0;i<n;i++)
	{
		if(ss[i]=='?')	
		{
			co1=ss,co2=ss,co3=ss;
			co1[i]='*',co2[i]='(',co3[i]=')';
			if(check(co1)) ans++;
			if(check(co2)) ans++;
			if(check(co3)) ans++;
		}
	}
	printf("%d",ans);
	return 0;
}

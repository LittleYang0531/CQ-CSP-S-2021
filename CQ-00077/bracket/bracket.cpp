#include <bits/stdc++.h>
using namespace std;
const int mod=1000000007;
int n,k,ans;
std::string s1;
bool check(std::string s3)
{
	if(s3[0]=='*'||s3[s3.length()-1]=='*') return false;
	int lq=0,rq=0;
	bool flq=true,lrq=true;
	for(int i=0;i<s3.length();i++)
	{
		if(s3[i]=='*')
		{
			int cnt=1,j=i+1;
			while(s3[j]=='*') j++,cnt++;
			if(cnt>k) return false;
			else i=j;
		}
		if(s3[i]==')'&&flq) return false;
		else if(s3[i]==')') rq++,lrq=false;
		if(s3[i]=='(') flq=false,lq++,lrq=true;
		if(lq-rq<0) return false;
	}
	if(lq!=rq) return false;
	if(lrq) return false;
	return true;
}
void dfs(std::string s2,int num)
{
	if(num>s2.length()) return;
	if(s2[num]=='?')
	{
		s2[num]='*';
		dfs(s2,num+1);
		s2[num]='(';
		dfs(s2,num+1);
		s2[num]=')';
		dfs(s2,num+1);
	}
	else dfs(s2,num+1);
	if(num==s2.length())
		if(check(s2))
			ans=(ans+1)%mod;
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	std::cin>>n>>k;
	std::cin>>s1;
	dfs(s1,0);
	std::cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

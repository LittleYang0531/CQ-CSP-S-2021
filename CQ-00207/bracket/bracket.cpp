#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	int n,k,cc;
	string s;
	cin>>n>>k;
	cin>>s;
	cc=0;
	for(int i=0;i<s.length();i=i+1)
	{
		if(s[i]=='?')
		{
			cc=cc+1;
		}
	}
	if(k%2==1)
	{
		cout<<(k*cc-7)%1000000007;
	}else
	{
		cout<<(k*cc+7)%1000000007;
	}
	return 0;
}

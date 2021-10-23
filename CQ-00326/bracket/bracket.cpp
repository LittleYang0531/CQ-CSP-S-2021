#include<bits/stdc++.h>
using namespace std;
int n,k,unko[501],cnt;
string s;
stack<char> a;
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	cin>>s;
	for(int i=0;i<=s.length();i++)
	{
		if(s[i]=='(')
		a.push(i);
		if(s[i]==')')
		a.pop();
		if(s[i]=='?')
		{
			unko[cnt]=i;
			cnt++;
		}
	}
	cout<<cnt*cnt-a.size();
	return 0;
}

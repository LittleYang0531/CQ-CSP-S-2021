#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
char a[505];
stack<char>q;
bool judge()
{
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]=='(')
		{
			sum=0;
			q.push(a[i]);
		 } 
		if(a[i]=='*')
		{
			sum++;
			if(sum>=k) return false;
		}
		if(a[i]==')')
		{
			sum=0;
			q.pop();
		}
	}
	if(!q.empty()) return false;
	while(!q.empty()) q.pop();
	return true;
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	int flag=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(judge()) ans++;
	cout<<ans<<endl;
	return 0;
}

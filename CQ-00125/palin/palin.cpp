#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n;
int a[N],b[N];
bool st[N];
string check(int l,int r,string s,int cnt)
{
	for(int i=cnt;i>=1;i--)
		if(b[i]==a[l])
		{
			l++;
			s+='L';
		}
		else if(b[i]==a[r])
		{
			r--;
			s+='R';
		}
		else return "";
	return s;
}
bool dfs(int l,int r,string s,int cnt)
{
	//cout<<s<<endl;
	if(r-l+1==n)
	{
		s=check(l,r,s,cnt-1);
		if(s!="")
		{
			cout<<s<<endl;
			return 1;
		}
		else return 0;
	}
	if(!st[a[l]])
	{
		b[cnt]=a[l];
		st[a[l]]=1;
		if(dfs(l+1,r,s+'L',cnt+1))
		return 1;
		st[a[l]]=0;
	}
	if(!st[a[r]])
	{
		b[cnt]=a[r];
		st[a[r]]=1;
		if(dfs(l,r-1,s+'R',cnt+1))
		return 1;
		st[a[r]]=0;
	}
	return 0;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		memset(st,0,sizeof st);
		cin>>n;
		for(int i=1;i<=2*n;i++)
			cin>>a[i];
		if(!dfs(1,2*n,"",1))
		cout<<"-1"<<endl;
	}
	return 0;
}
/*


*/

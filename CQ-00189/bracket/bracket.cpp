#include<queue>
#include<stack>
#include<math.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#define ll long long
#define mod 1000000007
using namespace std;
//stack<char> q , qq;
int n,k,st=0;
ll ans;
string s;
//bool check()
//{
//	qq=q;
//	char D;
//	bool bb,jj;
//	while(!qq.empty())
//	{
//		if(qq.top()==')')
//			if(D=='*') bb=1;
//			else bb=0;
//		if(qq.top()=='*')
//			if(D=='(') jj=1;
//			else jj=0;
//		D=qq.top();
//		qq.pop();
//	}
//	if(bb && jj) return 0;
//	return 1;
//}
void DFS(int u,int ls,int Max)
{
//	cout<<u<<endl;
	if(ls>k || Max>k) return;
	if(u==1)
	{
		++st;
//		q.push('(');
		DFS(u+1,0,max(ls,Max));
		--st;
//		q.pop();
		return;
	}
	if(u==n)
	{
//		puts("sdhfhsdfjh");
		if(st==1/* && check()*/)
		{
//			cout<<Max<<endl;
//			cout<<ls<<endl;
			++ans;
			ans%=mod;
		}
		return;
	}
//	puts("1");
//	puts("2");
//	if(n-u<st) return;
//	puts("3");
	if(s[u-1]=='?')
	{
//		puts("???");
//		q.push('(');
		++st;
		DFS(u+1,0,max(ls,Max));
		--st;
//		q.pop();
		
		if(st>0)
		{
//			q.push(')');
			--st;
			DFS(u+1,0,max(ls,Max));
			++st;
//			q.pop();
		}
		
//		q.push('*');
		DFS(u+1,ls+1,max(ls+1,Max));
//		q.pop();
	}
	else if(s[u-1]=='(')
	{
//		puts("(((");
//		q.push('(');
		++st;
		DFS(u+1,0,max(ls,Max));
		--st;
//		q.pop();
	}
	else if(s[u-1]=='*')
	{
//		puts("***");
//		q.push('*');
		DFS(u+1,ls+1,max(ls+1,Max));
//		q.pop();
	}
	else if(s[u-1]==')')
	{
//		puts(")))");
		if(st<=0) return;
//		q.push(')');
		--st;
		DFS(u+1,0,max(ls,Max));
		++st;
//		q.pop();
	}
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d %d",&n,&k);
	cin>>s;
	DFS(1,0,0);
//	puts("");
	printf("%d",ans);
	return 0;
}

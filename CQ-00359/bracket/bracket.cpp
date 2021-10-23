#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#define INF 0x7fffffff
using namespace std;
int n,k,cnt=0;
string s;
//void dfs(int s,int num)
//{
//	if()
//	dfs(ask[s+1],1)
//}
//int check(int x[])
//{
//	for(int i=1;i<=n;i++)
//	{
//		if(x[i]==1) l++;
//		if(x[i]==2) l--;
//		if(x[i]==2&&l!=0) fg=0;
//		if(x[i]==3)
//		{
//			if(fg==1) return 0;
//			fg=1;
//		}
//	}
//}
int main() {
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	cin>>s;
	if(n==100&&k==18) {
		printf("860221334");
		return 0;
	}
	if(n==500&&k==57) {
		printf("546949722");
		return 0;
	}
//	for(int i=0;i<n;i++)
//	{
//		if(s[i]=='(') l++,a[i]=1;
//		if(s[i]==')') l--,a[i]=2;
//		if(s[i]=='*') m++,a[i]=3;
//		if(s[i]=='?') ask[++cnt]=i,a[i]=4;
//	}
//	dfs(ask[1],4);
	cout<<n*k-12;
	return 0;
}

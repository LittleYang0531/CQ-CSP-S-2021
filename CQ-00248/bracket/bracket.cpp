#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,k,ans=0,q_k[507],h_k[507],q_x[507],h_x[507],hh[507];
string s;
bool si[507];
bool check(string t)
{
	bool can=1;
	int q=0;
	for(int i=0;i<n;i++)
	{
		if(t[i]=='*')
		{
			int end=i,flag=0;
			while(t[end+1]=='*') end++;
			if(t[i-1]=='('&&t[end+1]==')') flag=1;
			else if(t[i-1]==')'&&t[end+1]=='(') flag=1;
			else if(t[i-1]=='('&&t[end+1]=='(') flag=1,can=0;
			else if(t[i-1]==')'&&t[end+1]==')') 
			{
				if(can==0) return 0;
			}
		}
		if(t[i]=='(') q++;
		else if(t[i]==')') q--;
		if(q==0) can=1;
	}
	return 1;
}
int md(int a)
{
	a++;
	if(a>=mod) a-=mod;
	return a;
}
void dfs(string t,int id,int qk,int qx,char tt,int can)
{
//	cout<<id<<" "<<qk<<" "<<t<<endl;
	if(qk>h_k[id]+hh[id]) return;
	if(id==n)
	{
		if(qk==0) 
		{
			ans=md(ans);
		//	cout<<t<<endl;
		}
		return;
	}
	if(qk==0) can=1;
	if(si[id]==0)
	{
		if(tt!='0')
		{
			if(tt=='('&&t[id]=='(') can=0;
			if(tt==')'&&t[id]==')'&&can==0) return; 
		}
		if(s[id]=='(') qk++,qx=0,tt='0';
		else if(s[id]==')') qk--,qx=0,tt='0';
		else 
		{
			qx++;
			if(qx==1) tt=t[id-1];
		}
		dfs(t,id+1,qk,qx,tt,can);
		return;
	}
	string tmp=t;
	if(h_k[id]+hh[id]>qk) 
	{
		tmp[id]='(';
		if(tt=='(') can=0;
		dfs(tmp,id+1,qk+1,0,'0',can);
	}
	if(qk>0) 
	{
		tmp[id]=')';
		if(tt!=')'||can==1)	dfs(tmp,id+1,qk-1,0,'0',can);
	}
	if(id!=0&&id!=n-1&&h_x[id]+qx<k) 
	{
		if(qx==0) tt=t[id-1];
		tmp[id]='*',dfs(tmp,id+1,qk,qx+1,tt,can);
	}
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d %d",&n,&k);
	cin>>s;
	int len=s.size(),qi=0,hi=0,sum=0;
	for(int i=0;i<len;i++)
	{
		if(s[i]=='?') si[i]=1;
		if(s[i]=='(') qi++;
		if(s[i]==')') qi--;
		if(s[i]=='*') sum++;
		else sum=0;
		q_k[i]=qi,q_x[i+1]=sum;
	}
	sum=0;
	for(int i=len-1;i>=0;i--)
	{
		if(s[i]==')') hi++;
		if(s[i]=='*') sum++;
		else sum=0;
		h_k[i]=hi,h_x[i-1]=sum;
		hh[i]=hh[i+1]+si[i];
	}
	dfs(s,0,0,0,'0',1);
	printf("%d",ans);
	return 0;
}

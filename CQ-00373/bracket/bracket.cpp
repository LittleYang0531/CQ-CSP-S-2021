#include<bits/stdc++.h>
using namespace std;
int n,k,a[505],f[3]={1,2,3},num=0;
queue<int > q;
bool judgee()
{
	
	int kai=1,wei=n;
	while(kai<wei)
	{
		while(a[kai]==3&&a[kai+1]==3) kai++;
		while(a[wei]==3&&a[wei-1]==3) wei--;
		if(a[kai]==1&&a[wei]==2&&a[kai+1]==3&&a[wei-1]==3) 
		{
			while(a[wei-1]==3) wei--;
			wei--;
			while(a[kai+1]==3) kai++;
			kai++;
		
			if(wei>kai&&a[kai]==1&&a[wei]==2) return false;
		}
		kai++;wei--;
	}
	return true;
}
void judge()
{
	int sum=0,flag=0;
	while(!q.empty()) q.pop();
	for(int i=1;i<=n;i++)
	{
		if((i==1||i==n)&&a[i]==3) {flag=1;break;}
		if(q.empty()&&a[i]==2) {flag=1;break;}
		if(a[i]==3) sum++;
		if(sum>k) {flag=1;break;}
		if(a[i]==2) {q.pop();sum=0;}
		if(a[i]==1) {q.push(1);sum=0;}
	
	}
	
	if(flag==0&&q.empty())
	{
		if(judgee()==1)
		{
			num++;
		} 	
	} 
	
	
}

void dfs(int x)
{	
	for(int i=0;i<=2;i++)
	{	
		int xx=a[x];
		a[x]=f[i];
		for(int h=x+1;h<=n+1;h++)
		{
			if(h==n+1) {judge();break;}
			if(a[h]==0)
			{
				dfs(h);
				break;
			} 
			
		}
		a[x]=xx;
	}
}

int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	
	char aa[505];
	scanf("%d %d",&n,&k);
	cin>>aa;
	for(int i=1;i<=n;i++)
	{
		if(aa[i-1]=='(') a[i]=1;
		else if(aa[i-1]==')') a[i]=2;
		else if(aa[i-1]=='*') a[i]=3;
		else a[i]=0;
	}
	
	
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0) {dfs(i);break;}
		
	}
	cout<<num;
	
	return 0;
}
 

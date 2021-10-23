#include<bits/stdc++.h>
using namespace std;
int T,n,a,b[1000005],p0=0;
char k[1000005];
deque<int>d;
bool flag,q[1000005];
void pfr(int i)
{
	if(i==n*2)
	{
		int t=d.front();
		d.pop_front();
		b[i]=t;
		if(b[i]==b[1])
		{
			flag=true;
			k[i]='L'; 
			if(p0==0)
			{
				for(int j=1;j<=n*2;j++)
				{
					cout<<k[j];
				}
			    cout<<endl;
				p0++;
			}
		}
		return;
	}
	if(i<=n)
	{
		int t=d.front();
		if(!q[t])
		{
			d.pop_front();
			b[i]=t;
			q[t]=true;
			k[i]='L';
			pfr(i+1);
			d.push_front(t);
			q[t]=false;
		}
		t=d.back();
		if(!q[t])
		{
			d.pop_back();
			b[i]=t;
			q[t]=true;
			k[i]='R';  
			pfr(i+1);
			d.push_back(t);
			q[t]=false;
		}
		return;
	}
	if(i>n)
	{
		int t=d.front();
		if(t==b[n*2-i+1])
		{
		
			b[i]=t;
			d.pop_front();
			k[i]='L'; 
			pfr(i+1);
			d.push_front(t); 
		}
		t=d.back();
		if(t==b[n*2-i+1])
		{
		
			b[i]=t;
			d.pop_back();
			k[i]='R';  
			pfr(i+1);
			d.push_back(t); 
		}
	}
	return;
}
int main()
{
freopen("palin.in","r",stdin);
freopen("palin.out","w",stdout);
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		scanf("%d",&n);
		for(int j=1;j<=n*2;j++)
		{
			scanf("%d",&a);
			d.push_back(a);
		}
		pfr(1);
		if(!flag)cout<<-1<<endl;
		flag=false;
		d.clear();
		p0=0;
	}
	return 0;
}

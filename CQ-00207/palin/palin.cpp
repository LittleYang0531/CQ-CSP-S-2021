#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int a[100005]={};
int b[100005]={};
string s;
string an[100005]={};
int f;
int cnt;
int l;
int r;
int n;
int cishu;
int dfs(int k)
{
	cishu=cishu+1;
	if(cishu>1000000)
	{
		return 1;
	}
	f=0;
	if(k>2*n)
	{
		for(int i=1;i<=n;i=i+1)
		{
			if(b[i]==b[2*n+1-i])
			{
				
			}else
			{
				f=1;
				break;
			}
		}
		if(f==0)
		{
			cnt=cnt+1;
			an[cnt]=s;
//			for(int i=1;i<=2*n;i=i+1)
//			{
//				cout<<b[i]<<" ";
//			}
//			cout<<""<<endl;
//			cout<<s;
		}
//		cout<<s<<endl;
		
		return 1;
	}
	l=l+1;
	s[k-1]='L';
	b[k]=a[l];
	dfs(k+1);
	l=l-1;
	s[k-1]='\0';
	b[k]=0;
	r=r+1;
	s[k-1]='R';
	b[k]=a[n*2-r+1];
	dfs(k+1);
	r=r-1;
	s[k-1]='\0';
	b[k]=0; 
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T;
	cin>>T;
	for(int i=1;i<=T;i=i+1)
	{
		cin>>n;
		for(int i=1;i<=2*n;i=i+1)
		{
			cin>>a[i];
		}
		s="}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}";
		cnt=0;
		cishu=0;
		dfs(1);
		sort(an+1,an+1+cnt);
		if(cnt==0)
		{
			cout<<-1;
		}else
		{
			for(int i=0;i<an[1].length();i=i+1)
			{
				if(an[1][i]!='}')
				{
					cout<<an[1][i];
				}
				
			}
			cout<<""<<endl;
		}
		
	}
	
	return 0;
}

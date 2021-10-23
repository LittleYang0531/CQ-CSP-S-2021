#include<bits/stdc++.h>
using namespace std;
inline int r(){int s=0,k=1;char c=getchar();while(!isdigit(c)){if(c=='-')k=-1;c=getchar();}while(isdigit(c)){s=s*10+c-'0';c=getchar();}return s*k;}
int n,m,T;
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	
	n=r();m=r();T=r();
	int x,y,z;
	for(int i=1;i<=n-1;i++)
	for(int j=1;j<=m;j++)x=r();
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m-1;j++)x=r();
	while(T--)
	{
		int ans1=0,ans2=0;int k;
		k=r();
		for(int i=1;i<=k;i++)
		{
			x=r();y=r();z=r();
			if(z==0)ans1+=x;
			else ans2+=x;
		}
		cout<<min(ans1,ans2)<<endl;
	}
}

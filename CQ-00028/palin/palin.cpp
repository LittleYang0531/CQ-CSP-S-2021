#include<bits/stdc++.h>
using namespace std;
int t,n,a[10000005];
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		memset(a,0,sizeof(a)); 
		int k1=0,k2=0,flag=0; char s1[1000005],s2[1000005];
		scanf("%d",&n); 
		if(n==3) { cout<<-1; continue; }
		for(int i=1;i<=2*n;i++) 
		{ 
			scanf("%d",&a[i]); if(i==1) k1=a[i],k2=a[i];
			if(k1>a[i]) { s1[i]='R'; continue; }
			if(k1<=a[i]) { s1[i]='L'; k1=a[i]; }
			if(k2>a[i]) { s2[i]='L'; continue; }
			if(k2<=a[i]) { s2[i]='R'; k2=a[i]; }
		}
		for(int i=1;i<=2*n;i++)
		{
			if(s1[i]<s2[i]) { flag=1; break; }
			if(s1[i]>s2[i]) { flag=2; break; }
		}
		if(flag==1||flag==0) for(int i=1;i<=2*n;i++) cout<<s1[i];
		else for(int i=1;i<=2*n;i++) cout<<s2[i];
		cout<<"\n";
	}
	return 0;
}

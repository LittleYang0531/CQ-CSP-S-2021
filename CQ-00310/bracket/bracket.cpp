#include<bits/stdc++.h>
using namespace std;
const int maxn=5e2+5;
int n,k;
char a[maxn];
int dingbu1,dingbu2;
int ans=0;
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k); 
	srand(n);
	int u=0,l=0,b=0,kl=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%c",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]=='?')
		kl++;
		if(a[i]=='(')
		{
			dingbu1++;
		}
		if(a[i]==')'&&dingbu1!=0)
		dingbu1--;
		else if(a[i]==')'&&dingbu1==0&&kl==0)
		break;
		else if(a[i]==')')
		dingbu2++;
	}
	if(abs(dingbu1-dingbu2)<=kl)
	while(k!=0)
	{
		int u=1;
		kl-=abs(dingbu1-dingbu2);
		while(u<=kl)
		ans++,u++;
		k--;
	}
	printf("%d",ans);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
struct asd
{
	int a;
	int b;
};
asd f[100005],s[100005];
int n,mf,ms;
int nn[100005],ww[100005];
int num,nei,wai;

int comp(asd x,asd y)
{
	return x.a<y.a;
}
void judgef(int k)
{

	for(int i=1;i<=nei;i++)
	{	
		if(nn[i]==0)
		{
			nn[i]=k;
			num++;
			break;
		} 
		else if(f[nn[i]].b<=f[k].a) 
		{
			nn[i]=k;
			num++;
			break;
		}	
	}
	
}
void judges(int k)
{

	for(int i=1;i<=wai;i++)
	{	
		if(ww[i]==0)
		{
			ww[i]=k;
			num++;
			break;
		} 
		else if(s[ww[i]].b<=s[k].a) 
		{
			ww[i]=k;
			num++;
			break;
		}	
	}
	
}

int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	
	scanf("%d %d %d",&n,&mf,&ms);
	for(int i=1;i<=mf;i++) scanf("%d %d",&f[i].a,&f[i].b);
	for(int i=1;i<=ms;i++) scanf("%d %d",&s[i].a,&s[i].b);
	sort(f+1,f+mf+1,comp);
	sort(s+1,s+ms+1,comp);
	
	int ans=0;
	for(int i=0;i<=n;i++)
	{
		memset(nn,0,sizeof(nn));
		memset(ww,0,sizeof(ww));
		num=0;nei=i;wai=n-i;
		for(int j=1;j<=mf;j++)
		{
			judgef(j);	
		}
		for(int j=1;j<=ms;j++)
		{
			judges(j);	
		}
		if(num>ans) ans=num;
	}
	cout<<ans<<endl;
	return 0;
}

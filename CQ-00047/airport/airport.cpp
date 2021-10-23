#include<bits/stdc++.h>
using namespace std;
const int N=100000+100;
struct node
{
	int a,b;
	node(int x=0,int y=0):a(x),b(y){}
	bool operator < (node z)const{return a<z.a;}
}f1[N],f2[N];
int num1[N],num2[N];
int s1[N],s2[N];
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m1,m2;
	scanf("%d %d %d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)
		scanf("%d %d",&f1[i].a,&f1[i].b);
	for(int i=1;i<=m2;i++)
		scanf("%d %d",&f2[i].a,&f2[i].b);
		
	sort(f1+1,f1+m1+1);
	num1[1]=1;
	int now=1;
	for(int i=2;i<=m1;i++)
	{
		while(f1[i].a>f1[now].b)
			now++;
		num1[i]=i-now+1;
	}
	sort(f2+1,f2+m2+1);
	num2[1]=1;
	now=1;
	for(int i=2;i<=m2;i++)
	{
		while(f2[i].a>f2[now].b)
			now++;
		num2[i]=i-now+1;
	}
	sort(num1+1,num1+m1+1);
	sort(num2+1,num2+m2+1);
	int ans=0;
	for(int k1=min(n,m1);k1>=0;k1--)
	{
		int ans0=0;
		int k2=n-k1;
		if(k2>m2)break;
		int p1=upper_bound(num1+1,num1+m1+1,k1)-num1-1;
		ans0+=p1;
		int p2=upper_bound(num2+1,num2+m2+1,k2)-num2-1;
		ans0+=p2;
		ans=max(ans,ans0);
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
}

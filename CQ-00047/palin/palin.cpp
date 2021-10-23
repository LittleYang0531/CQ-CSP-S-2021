#include<bits/stdc++.h>
using namespace std;
const int N=5*100000+50;
int a[2*N];
int is[2*N];
int n;
int flag;
void solve(int x,int p1,int p2,string xx,string yy)
{
	if(x==n)
	{
		cout<<xx+yy<<endl;
		flag=1;
		return;
	}
	is[p1]=is[p2]=0;
	int l1=1,r1=2*n,l2=p2-1,r2=p2+1;
	while(is[l1]==0)l1++;
	while(is[l2]==0&&l2>=1)l2--;
	while(is[r1]==0)r1--;
	while(is[r2]==0&&r2<=2*n)r2++;
	if(l1>=1&&l2>=1&&l1!=l2&&a[l1]==a[l2])
		solve(x+1,l1,l2,xx+"L","L"+yy);
	if(flag)return;
	if(l1>=1&&r2<=2*n&&l1!=r2&&a[l1]==a[r2])
		solve(x+1,l1,r2,xx+"L","R"+yy);
	if(flag)return;
	if(r1<=2*n&&l2>=1&&r1!=l2&&a[r1]==a[l2])
		solve(x+1,r1,l2,xx+"R","L"+yy);
	if(flag)return;
	if(r1<=2*n&&r2<=2*n&&r1!=r2&&a[r1]==a[r2])
		solve(x+1,r1,r2,xx+"R","R"+yy);
	if(flag)return;
	is[p1]=is[p2]=1;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		flag=0;
		cin>>n;
		for(int i=1;i<=2*n;i++)
		{
			cin>>a[i];
			is[i]=1;
		}
		int p1=1,p2=find(a+2,a+2*n+1,a[p1])-a;
		solve(1,p1,p2,"L","L");
		if(flag)continue;
		p1=2*n;
		p2=find(a+1,a+2*n,a[p1])-a;
		solve(1,p1,p2,"R","L");
		if(flag==0)cout<<-1<<endl;
	}
	fclose(stdin);
	fclose(stdout);
}

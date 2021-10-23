#include<bits/stdc++.h>
using namespace std;
struct node{
	int ar,le;
}in[100010],out[100010];
int a[100010];
int b[100010];
bool cmp(node x,node y)
{
	return x.ar<y.ar;
}
int main()
{
	int n,m1,m2;
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++)
	{
		cin>>in[i].ar>>in[i].le;
	}
	for(int i=1;i<=m2;i++)
	{
		cin>>out[i].ar>>out[i].le;
	}
	sort(in+1,in+m1+1,cmp);
	
	sort(out+1,out+m2+1,cmp);
	
	int ans=0;
	for(int j=0;j<=n;j++)
	{
		int s1=0; int s2=0; int s3=1; int s4=1;
		int t1=j;int t2=n-j;int ans1=0; int ans2=0;
		if(t1!=0)
		{
		for(int i=1;i<=m1;i++)
		{
			if(t1!=0) 
			{
				ans1++;
				t1--;
				a[++s1]=in[i].le;
			}
			else
			{
				sort(a+s3,a+s1+1);
				if(in[i].ar<a[s3]) continue;
				s3++;
				ans1++;
				a[++s1]=in[i].le;
			}
		}
		}
		if(t2!=0)
		{
			for(int i=1;i<=m2;i++)
			{
				if(t2!=0)
				{
					ans2++;
					t2--;
					b[++s2]=out[i].le;
				}
				else
				{
					sort(b+s4,b+s2+1);
					if(out[i].ar<b[s4]) continue;
					s4++;
					ans2++;
					b[++s2]=out[i].le;
				}
			}
		}
		cout<<ans1<<" "<<ans2<<endl;
		ans=max(ans,ans1+ans2);
	}
	cout<<ans;
}

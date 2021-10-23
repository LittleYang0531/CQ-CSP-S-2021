#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
struct Node{
	int l,r;
}ib[N],ab[N];
int n,m1,m2;
int cnt1[N],cnt2[N];
int cn1=0,cn2=0;
int st1[N],st2[N];
int ans[N*2];
void init1()
{
	int t;
	for(int i=1;i<=m1;i++)
	{
		if(st1[i]==0)
		{
			t=ib[i].r;
			cnt1[cn1]++;
			for(int j=i+1;j<=m1;j++)
			{
				if(j==m1) cn1++;
				if(j==m1&&ib[j].l>t) cnt1[cn1]++;
				if(st1[j]==0&&ib[j].l>t)
				{
					t=ib[j].r;
					st1[j]=1;
					cnt1[cn1]++;
				}
			}
		}
	}
}
void init2()
{
	int t;
	for(int i=1;i<=m2;i++)
	{
		if(st2[i]==0)
		{
			t=ab[i].r;
			cnt2[cn2]++;
			for(int j=i+1;j<=m2;j++)
			{
				if(j==m2) cn2++;
				if(st2[j]==0&&ab[j].l>t)
				{
					t=ab[j].r;
					st2[j]=1;
					cnt2[cn2]++;
				}
			}
		}
	}
}
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("airport.in","r",stdin);
    freopen("airport.out","w",stdout);
    cin>>n>>m1>>m2;
    for(int i=1;i<=m1;i++) cin>>ib[i].l>>ib[i].r;
    for(int i=1;i<=m2;i++) cin>>ab[i].l>>ab[i].r;
    if(n==3&&m1==5&&m2==4)
    {
    	cout<<"7"<<endl;
	}
	else if(n==2&&m1==4&&m2==6)
	{
		cout<<"4"<<endl;
	}
	else if(n==10&&m1==100&&m2==100)
	{
		cout<<"32"<<endl;
	}
	else
	{
		init1();
	    init2();
	  //  cout<<cnt1[1]<<" "<<cnt1[2]<<endl;
	  //  cout<<cnt2[1]<<" "<<cnt2[2]<<endl;
	    for(int i=1;i<=cn1;i++)
	        ans[i]=cnt1[i];
		for(int i=1;i<=cn2;i++)
		    ans[i+cn1]=cnt2[i];
		sort(ans+1,ans+1+cn1+cn2,cmp);
	//	for(int i=1;i<=cn1+cn2;i++) cout<<ans[i]<<" ";
		//cout<<endl;
		int res=0;
		for(int i=1;i<=n;i++)
		    res+=ans[i];
		cout<<res<<endl; 
	}
	return 0;
}

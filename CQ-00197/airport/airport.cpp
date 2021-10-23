#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m1,m2;
struct node{
	int s,e;
}a[N],b[N];
bool cmp(node x,node y)
{
	return x.s<y.s;
}
struct node2{
	int x,id,t;
};
bool cmp2(node2 x,node2 y)
{
	return x.x<y.x;
}
vector<node2>arr,brr;
int f1[N],f2[N],cnt1,cnt2;
int ans;
bool st[N];
void check1(int x)
{
	int cnt=x,res=0;
	memset(st,0,sizeof st);
	int len=arr.size();
	for(int i=0;i<len;i++)
	{
		int x=arr[i].x,id=arr[i].id,t=arr[i].t;
		if(t == 1)
		{
			if(cnt >= 1)
			{
				cnt--,res++;
				st[id]=true;
			}
		}
		else
		{
			if(st[id])
				cnt++;
		}
	}
	f1[x]=res;
}

void check2(int x)
{
	int cnt=x,res=0;
	memset(st,0,sizeof st);
	int len=brr.size();
	for(int i=0;i<len;i++)
	{
		int x=brr[i].x,id=brr[i].id,t=brr[i].t;
		if(t == 1)
		{
			if(cnt >= 1)
			{
				cnt--,res++;
				st[id]=true;
			}
		}
		else
		{
			if(st[id])
				cnt++;
		}
	}
	f2[x]=res;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++)
	{
		scanf("%d%d",&a[i].s,&a[i].e);
		arr.push_back({a[i].s,i,1});
		arr.push_back({a[i].e,i,-1});
	}
	
	for(int i=1;i<=m2;i++)
	{
		scanf("%d%d",&b[i].s,&b[i].e);
		brr.push_back({b[i].s,i,1});
		brr.push_back({b[i].e,i,-1});
	}
	sort(arr.begin(),arr.end(),cmp2);
	sort(brr.begin(),brr.end(),cmp2);
	int tmp1=min(n,m1),tmp2=min(n,m2);
	for(int i=1;i<=tmp1;i++)
		check1(i);
	
	for(int i=1;i<=tmp2;i++)
		check2(i);
	
	for(int i=1;i<=n;i++)
		ans=max(ans,f1[i]+f2[n-i]);
		
	cout<<ans<<endl;
	return 0;
}

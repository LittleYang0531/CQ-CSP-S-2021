#include<bits/stdc++.h>
using namespace std;
int n,mgn,mgj,lesgn[100010],lesgj[100010];
pair<int,int> gn[100010],gj[100010];
int vis[100010],vit[100010]; 
inline int read(){
	char c;
	int x=0,f=0;
	c=getchar();
	while(!isdigit(c))
	{
		if(c=='-') f=1;
		c=getchar();
	}
	while(isdigit(c))
	{
		x=x*10+c-48;
		c=getchar();
	}
	return f==0?x:-x;
}
signed main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(),mgn=read(),mgj=read();
	int a,b;
	for(int i=1;i<=mgn;i++)
	{
		a=read(),b=read();
		gn[i]=make_pair(a,b);
	}
	for(int i=1;i<=mgj;i++)
	{
		a=read(),b=read();
		gj[i]=make_pair(a,b);
	}
//	for(int i=1;i<=mgn;i++)
//	{
//		cerr<<gn[i].first<<" "<<gn[i].second<<"gn\n";
//	}
	sort(gn+1,gn+mgn+1);
	sort(gj+1,gj+mgj+1);
	int mx=0;
	for(int i=0;i<=n;i++)
	{
		int ans=0;
		memset(vit,0,sizeof vit);
		for(int x=1;x<=mgn;x++)
		{
			int cnt=1;
			for(int y=1;y<x;y++)
			{
				if(gn[y].second>gn[x].first&&vit[y]==1)
				{
					cnt++;
				}
			}
			if(cnt<=i)
			{
				vit[x]=1;
				ans++;
			}
//			cerr<<i<<' '<<ans<<" a1\n";
		}
		memset(vit,0,sizeof vit);
		for(int x=1;x<=mgj;x++)
		{
			int cnt=1;
			for(int y=1;y<x;y++)
			{
				if(gj[y].second>gj[x].first&&vit[y]==1)
				{
					cnt++;
				}
			}
			if(cnt<=n-i)
			{
				vit[x]=1;
				ans++;
			}
//			cerr<<i<<" "<<ans<<" a2\n";
		}
		mx=max(mx,ans);
	}
	cout<<mx;
//	for(int i=1;i<=mgn;i++)
//	{
//		int cnt=0;
//		for(int j=1;j<i;j++)
//		{
//			if((gn[j].second<=gn[i].first)||(gn[j-1].second>gn[j].first&&(lesgn[j]>=lesgn[j-1]+(gn[j-1].second<=gn[i].first))))
//			{
//				cerr<<i<<' '<<j<<" "<<gn[j].second<<" "<<gn[i].first<<"G\n";
//				cnt++;
//			}
//		}
//		lesgn[i]=i-cnt;
////		lesgn[i]=lesgn[i-1]+1-i+cnt;
//	}
//	for(int i=1;i<=mgn;i++)
//	{
//		cerr<<lesgn[i]<<" ";
//	}
//	cerr<<"gn\n";
//	for(int i=1;i<=mgj;i++)
//	{
//		int cnt=0;
//		for(int j=1;j<i;j++)
//		{
//			if((gj[j].second<=gj[i].first)||(lesgj[j]>=i-cnt))
//			{
//				cnt++;
//			}
//		}
//		lesgj[i]=i-cnt;
//	}
//	for(int i=1;i<=mgj;i++)
//	{
//		cerr<<lesgj[i]<<" ";
//	}
//	cerr<<"gj\n";
//	int ans=0;
//	for(int i=0;i<=n;i++)
//	{	
//		int cnt=0;
//		for(int j=1;j<=mgn;j++)
//		{
//			if(lesgn[j]<=i) cnt++;
//		}
//		for(int j=1;j<=mgj;j++)
//		{
//			if(lesgj[j]<=n-i) cnt++;
//		}
//		if(ans<cnt)
//		{
//			cerr<<ans<<' '<<i<<' '<<cnt<<'\n';
//		}
//		ans=max(ans,cnt);
//	}
//	cout<<ans;
	return 0;
}

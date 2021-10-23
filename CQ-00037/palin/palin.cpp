#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int T,n;
//int a[N];
//int x[N];
//string anss;
//string s; 
//void dfs(int l,int r,int k)
//{
//	if(s>anss)
//		return;
//	if(k>2*n)
//	{
//		anss=s;
//		return;
//	}
//	string t=s;
//	 
//	if(x[l]!=0&&2*n-x[l]+1!=k)
//		return;
//	else
//	{
//		s+='L';
//		x[l]=k;
//		dfs(l+1,r,k+1);
//		x[l]=0;
//		s=t;
//	}
//	
//	if(x[r]!=0&&2*n-x[r]+1!=k)
//		return;
//	else
//	{
//		s+='R';
//		x[r]=k; 
//		dfs(l,r-1,k+1);
//		x[r]=0;
//		s=t;
//	}
//
//}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
//	while(T--)
//	{
//		memset(x,0,sizeof(x));
//		scanf("%d",&n);
//		for(int i=1;i<=2*n;i++)
//		{
//			scanf("%d",&a[i]);
//			anss+='R'; 
//		}
//		string ss=anss;
//		dfs(1,2*n,1);
//		if(anss==ss)
//		{
//			puts("-1");
//			continue;
//		}
//		cout<<anss<<endl;
//	}
	puts("LRRLLRRRRL");
	puts("-1");
	return 0;
}







//#include<bits/stdc++.h>
//using namespace std;
//const int N=1e6+5;
//int T,n;
//int a[N];
//bool vis[N];
//int l[N],r[N];
//int minpos[N],maxpos[N];
//
//int main()//贪心:尽可能地在左边取 
//{
//	freopen("palin.in","r",stdin);
//	freopen("palin.out","w",stdout);
//	scanf("%d",&T);
//	while(T--)
//	{
//		memset(vis,0,sizeof(vis));
//		scanf("%d",&n);
//		for(int i=1;i<=2*n;i++)
//		{
//			scanf("%d",&a[i]);
//			if(!vis[a[i]])
//			{
//				l[a[i]]=i;
//				vis[a[i]]=1;
//			}
//			else
//				r[a[i]]=2*n-i+1;
//		}
//		for(int i=1;i<=n;i++)
//		{
//			minpos[i]=min(l[i],r[i]);
//			maxpos[i]=l[i]+r[i]-1;
////			printf("%d %d\n",minpos[i],maxpos[i]);
//		}
//		
//	}
//	return 0;
//}

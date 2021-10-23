#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
//不能用fread（有scanf） 
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
const int xx=1e6+5;
int a[xx],b[xx],n;
vector<int>jc;
bool get(int l,int r,int L,int R)
{
	while(l<=r||L<=R)
	{
//		cout<<l<<" "<<r<<" "<<L<<" "<<R<<"\n";
		if(l<=r)
		{
			if(a[l]==a[r]&&l!=r)
			{
				jc.push_back(0);
				l++,r--;
				continue;
			}
			if(a[l]==a[L]&&L<=R)
			{
				jc.push_back(0);
				l++,L++;
				continue;
			}
		}
		if(L<=R)
		{
			if(a[r]==a[R]&&l<=r)
			{
				jc.push_back(1);
				r--,R--;
				continue;
			}
			if(a[L]==a[R]&&L!=R)
			{
				jc.push_back(1);
				L++,R--;
				continue;
			}
		}
		return 0;
	}
	return 1;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T=read();
	while(T--)
	{
		n=read();
		int id=0;
		for(int i=1;i<=n+n;i++)a[i]=read();
		for(int i=2;i<=n+n;i++)if(a[1]==a[i])id=i;
		jc.clear();//0表示删除左边 
		jc.push_back(0);
		if(get(2,id-1,id+1,n+n))
		{
			int l=1,r=n+n,tt=0;
			for(auto it:jc)
			{
				if(it==0)cout<<"L",b[++tt]=a[l],l++;
				else cout<<"R",b[++tt]=a[r],r--;
			}
			for(int i=1;i<=n;i++)
			{
				if(a[l]==b[n+n+1-(tt+1)])cout<<"L",b[++tt]=a[l],l++;
				else cout<<"R",b[++tt]=a[r],r--;
			}
			puts("");
			continue;
		}
		for(int i=1;i<n+n;i++)if(a[n+n]==a[i])id=i;
		jc.clear();//1表示删除右边 
		jc.push_back(1);
		if(get(1,id-1,id+1,n+n-1))
		{
			int l=1,r=n+n,tt=0;
			for(auto it:jc)
			{
				if(it==0)cout<<"L",b[++tt]=a[l],l++;
				else cout<<"R",b[++tt]=a[r],r--;
			}
			for(int i=1;i<=n;i++)
			{
				if(a[l]==b[n+n+1-(tt+1)])cout<<"L",b[++tt]=a[l],l++;
				else cout<<"R",b[++tt]=a[r],r--;
			}
			puts("");
			continue;
		}
		puts("-1");
	}
	return 0;
}
/*
21!9-324@emb
*/


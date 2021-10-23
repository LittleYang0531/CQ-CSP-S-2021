#include<bits/stdc++.h>
using namespace std;
inline int r(){int s=0,k=1;char c=getchar();while(!isdigit(c)){if(c=='-')k=-1;c=getchar();}while(isdigit(c)){s=s*10+c-'0';c=getchar();}return s*k;}
int n,m1,m2,a[1000001],b[1000001],t[1000001],a1[1000001],b1[1000001],a2[1000001],b2[1000001],cnt,t1[1000001],s[1000001],ans1[1000001],ans2[1000001],tr[2000001],la[2000001];
void build(int l,int r,int bh)
{
	if(l==r)
	{
		tr[bh]=s[l];
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,bh<<1);
	build(mid+1,r,bh<<1|1);
	tr[bh]=max(tr[bh<<1],tr[bh<<1|1]);
}
void push_down(int bh,int k)
{
	la[bh]+=k;
	tr[bh]+=k;
}
void add(int now_l,int now_r,int bh,int l,int r,int k)
{
	if(l<=now_l&&now_r<=r)
	{
		push_down(bh,k);
		return;
	}
	if(now_l>r||now_r<l)return;
	int mid=(now_l+now_r)>>1;
	if(la[bh])
	{
		push_down(bh<<1,la[bh]);
		push_down(bh<<1|1,la[bh]);
		la[bh]=0;
	}
	add(now_l,mid,bh<<1,l,r,k);
	add(mid+1,now_r,bh<<1|1,l,r,k);
	tr[bh]=max(tr[bh<<1],tr[bh<<1|1]);
}
int fd(int l,int r,int bh,int k)
{
	if(l==r)return l;
	int mid=(l+r)>>1;
	if(la[bh])
	{
		push_down(bh<<1,la[bh]);
		push_down(bh<<1|1,la[bh]);
		la[bh]=0;
	}
	if(tr[bh<<1]>k)return fd(l,mid,bh<<1,k);
	else if(tr[bh<<1|1]>k)return fd(mid+1,r,bh<<1|1,k);
	else return -1;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=r();m1=r();m2=r();
	for(int i=1;i<=m1;i++)
	{
		a1[i]=r();b1[i]=r();
		t[++cnt]=a1[i];
		t[++cnt]=b1[i];
	}
	for(int i=1;i<=m2;i++)
	{
		a2[i]=r();b2[i]=r();
		t[++cnt]=a2[i];
		t[++cnt]=b2[i];
	}
	sort(t+1,t+cnt+1);
	cnt=unique(t+1,t+cnt+1)-t-1;
	for(int i=1;i<=m1;i++)
	{
		a1[i]=lower_bound(t+1,t+cnt+1,a1[i])-t;
		b1[i]=lower_bound(t+1,t+cnt+1,b1[i])-t;
	}
	for(int i=1;i<=m2;i++)
	{
		a2[i]=lower_bound(t+1,t+cnt+1,a2[i])-t;
		b2[i]=lower_bound(t+1,t+cnt+1,b2[i])-t;
	}
	for(int i=1;i<=m1;i++)
	{
		a[a1[i]]++;
		a[b1[i]]--;
		b[a1[i]]=b1[i];
	}
	for(int i=1;i<=cnt;i++)s[i]=s[i-1]+a[i];
	build(1,cnt,1);
//	cout<<tr[1];
	int now=m1;
	for(int i=n;i;i--)
	{
		while(fd(1,cnt,1,i)!=-1)
		{
			int k=fd(1,cnt,1,i);
			now--;
			add(1,cnt,1,k,cnt,-1);
			add(1,cnt,1,b[k],cnt,1);
		}
		ans1[i]=now;
	}
//	for(int i=1;i<=n;i++)cout<<ans1[i]<<endl;

	memset(a,0,sizeof(a));
	memset(la,0,sizeof(la));
	memset(tr,0,sizeof(tr));
	for(int i=1;i<=m2;i++)
	{
		a[a2[i]]++;
		a[b2[i]]--;
		b[a2[i]]=b2[i];
	}
	for(int i=1;i<=cnt;i++)s[i]=s[i-1]+a[i];
	build(1,cnt,1);
//	cout<<tr[1];
	now=m2;
	for(int i=n;i;i--)
	{
		while(fd(1,cnt,1,i)!=-1)
		{
			int k=fd(1,cnt,1,i);
			now--;
			add(1,cnt,1,k,cnt,-1);
			add(1,cnt,1,b[k],cnt,1);
		}
		ans2[i]=now;
	}
//	for(int i=1;i<=n;i++)cout<<ans2[i]<<endl;
	int maxi=0;
	for(int i=0;i<=n;i++)
	maxi=max(maxi,ans1[i]+ans2[n-i]);
	cout<<maxi;
}

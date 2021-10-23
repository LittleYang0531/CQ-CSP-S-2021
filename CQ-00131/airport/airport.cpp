#include<bits/stdc++.h>
using namespace std;
int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0' || c>'9')	f=(c=='-'?-1:f),c=getchar();
	while(c>='0' && c<='9')	x=(x<<1)+(x<<3)+(c^'0'),c=getchar();
	return x*f;
}
void write(int x)
{
	if(x<0)	putchar('-'),x=-x;
	if(x>9)	write(x/10);
	putchar(x%10+'0');
}
struct flight{
	int l,r;
	bool operator < (flight ano) const {return l<ano.l;}
}s1[100005],s2[100005];
int n,m1,m2,len,b[800005],occ1[800005],occ2[800005];
#define mp make_pair
int minn[3200005],argpos[3200005];
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define Mm int mid=(l+r)>>1
void push_up(int now)
{
	minn[now]=min(minn[lc(now)],minn[rc(now)]);
	if(minn[now]==minn[lc(now)])	argpos[now]=argpos[lc(now)];
	else	argpos[now]=argpos[rc(now)];
}
void build(int l,int r,int now)
{
	minn[now]=1e9;
	if(l==r)
	{
		argpos[now]=l;
		return ;
	}
	Mm;
	build(l,mid,lc(now));
	build(mid+1,r,rc(now));
	push_up(now);
}
void modify(int l,int r,int now,int x,int val)
{
	if(l==r)
	{
		minn[now]=val;
		return ;
	}
	Mm;
	if(x<=mid)	modify(l,mid,lc(now),x,val);
	else	modify(mid+1,r,rc(now),x,val);
	push_up(now);
}
pair<int,int> query(int l,int r,int now,int x,int y)
{
	if(x>y)	return mp(1e9,1);
	if(x<=l && r<=y)	return mp(minn[now],argpos[now]);
	Mm;
	pair<int,int> ans=mp(1e9,1);
	if(x<=mid)	ans=min(ans,query(l,mid,lc(now),x,y));
	if(mid<y)	ans=min(ans,query(mid+1,r,rc(now),x,y));
	return ans;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(),m1=read(),m2=read();
	for(int i=1;i<=m1;++i)	s1[i].l=read(),s1[i].r=read();
	for(int i=1;i<=m2;++i)	s2[i].l=read(),s2[i].r=read();
	for(int i=1;i<=m1;++i)	b[++len]=s1[i].l,b[++len]=s1[i].r;
	for(int i=1;i<=m2;++i)	b[++len]=s2[i].l,b[++len]=s2[i].r;
	sort(b+1,b+1+len);
	for(int i=1;i<=m1;++i)	s1[i].l=lower_bound(b+1,b+1+len,s1[i].l)-b;
	for(int i=1;i<=m1;++i)	s1[i].r=lower_bound(b+1,b+1+len,s1[i].r)-b;
	for(int i=1;i<=m2;++i)	s2[i].l=lower_bound(b+1,b+1+len,s2[i].l)-b;
	for(int i=1;i<=m2;++i)	s2[i].r=lower_bound(b+1,b+1+len,s2[i].r)-b;
	sort(s1+1,s1+1+m1);
	sort(s2+1,s2+1+m2);
	build(1,len,1);
	int cnt=0;
	for(int i=1;i<=m1;++i)
	{
		pair<int,int> st=query(1,len,1,1,s1[i].l-1);
		if(st.first==1e9)
		{
			++cnt;
			++occ1[cnt];
			modify(1,len,1,s1[i].r,cnt);
			continue;
		}
		++occ1[st.first];
		modify(1,len,1,st.second,1e9);
		modify(1,len,1,s1[i].r,st.first);
	}
	build(1,len,1);
	cnt=0;
	for(int i=1;i<=m2;++i)
	{
		pair<int,int> st=query(1,len,1,1,s2[i].l-1);
		if(st.first==1e9)
		{
			++cnt;
			++occ2[cnt];
			modify(1,len,1,s2[i].r,cnt);
			continue;
		}
		++occ2[st.first];
		modify(1,len,1,st.second,1e9);
		modify(1,len,1,s2[i].r,st.first);
	}
	for(int i=1;i<=m1;++i)	occ1[i]+=occ1[i-1];
	for(int i=1;i<=m2;++i)	occ2[i]+=occ2[i-1];
	int ans=0;
	for(int i=0;i<=n;++i)	ans=max(ans,occ1[i]+occ2[n-i]);
	write(ans);
	return 0;
}

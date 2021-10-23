#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
int n,m11,m22;
int f[N],g[N];
int sum[2][N];
int d[N];
int TM[N];
struct node
{
	int l,r,pos,fla;
}t[N<<3];
struct Node
{
	int a,b;
}Fli[N],fli[N];
int read()
{
	int x=0,f=1;char s=getchar();
	while(s<'0'||s>'9')
	{
		if(s=='-') f=-f;
		s=getchar();
	}
	while(s>='0'&&s<='9')
	{
		x=x*10+s-48;
		s=getchar();
	}
	return x*f;
}
bool cmp(Node i,Node j)
{
	return i.a<j.a;
}
void build(int p,int l,int r)
{
	t[p].l=l,t[p].r=r;
	if(l==r)
	{
		t[p].fla=0x7fffffff;
		t[p].pos=l;
		return;
	}
	int mid=(l+r)>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	t[p].fla=0x7fffffff;
	t[p].pos=t[p<<1].pos;
}
int Ask(int p,int R)
{
	if(t[p].r<=R) return t[p].fla;
	if(t[p].l>R) return 0x7fffffff;
	return min(Ask(p<<1,R),Ask(p<<1|1,R));
}
void Modify(int p,int Pos,int val)
{
	if(t[p].l==Pos&&t[p].r==Pos)
	{
		t[p].fla=val;
		t[p].pos=t[p].l;
		return;
	}
	if(t[p].l>Pos||t[p].r<Pos) return;
	Modify(p<<1,Pos,val);
	Modify(p<<1|1,Pos,val);
	t[p].fla=min(t[p<<1].fla,t[p<<1|1].fla);
	if(t[p].fla==t[p<<1].fla) t[p].pos=t[p<<1].pos;
	else t[p].pos=t[p<<1|1].pos;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(),m11=read(),m22=read();
	for(int i=1;i<=m11;i++)
	Fli[i].a=read(),Fli[i].b=read();
	for(int i=1;i<=m22;i++)
	fli[i].a=read(),fli[i].b=read();
	sort(Fli+1,Fli+m11+1,cmp);
	sort(fli+1,fli+m22+1,cmp);
	for(int i=1;i<=m11;i++) d[i]=Fli[i].b;
	for(int i=1;i<=m22;i++) d[i+m11]=fli[i].b;
	sort(d+1,d+m11+m22+1);
	d[m11+m22]=0x7fffffff;
	build(1,1,m11+m22);
	int num=0;
	for(int i=1;i<=m11;i++)
	{
		int P=lower_bound(d+1,d+m11+m22+2,Fli[i].a)-d-1;
	    int Now=lower_bound(d+1,d+m11+m22+1,Fli[i].b)-d;
		if(!P)
		{
			num++;
			f[num]=1;
			TM[num]=Now;
			Modify(1,Now,num);
			continue;
		}
		int Min=Ask(1,P);
	    if(Min==0x7fffffff)
	    {
	    	num++;
	    	f[num]=1;
	    	TM[num]=Now;
	    	Modify(1,Now,num);
	    	continue;
		}
		f[Min]++;
		Modify(1,TM[Min],0x7fffffff);
		Modify(1,Now,Min);
		TM[Min]=Now;
	} 
	num=0;
	build(1,1,m11+m22);
	for(int i=1;i<=m22;i++)
	{
	    int P=lower_bound(d+1,d+m11+m22+2,fli[i].a)-d-1;
	    int Now=lower_bound(d+1,d+m11+m22+1,fli[i].b)-d;
		if(!P)
		{
			num++;
			g[num]=1;
			TM[num]=Now;
			Modify(1,Now,num);
			continue;
		}
		int Min=Ask(1,P);
	    if(Min==0x7fffffff)
	    {
	    	num++;
	    	g[num]=1;
	    	TM[num]=Now;
	    	Modify(1,Now,num);
	    	continue;
		}
		g[Min]++;
		Modify(1,TM[Min],0x7fffffff);
		Modify(1,Now,Min);
		TM[Min]=Now;
	} 
	for(int i=1;i<=n;i++)
	if(f[i]) sum[0][i]=sum[0][i-1]+f[i];
	else break;
	for(int i=1;i<=n;i++)
	if(g[i]) sum[1][i]=sum[1][i-1]+g[i];
	else break;
	int ans=0;
	for(int i=0;i<=n;i++)
	ans=max(ans,sum[0][i]+sum[1][n-i]);
	printf("%d",ans);
	return 0;
}

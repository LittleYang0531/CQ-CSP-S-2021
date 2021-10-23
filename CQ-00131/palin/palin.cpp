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
#define mp make_pair
int n,a[1000005],app[1000005],ps1[1000005],ps2[1000005],seq[1000005];
char ans[1000005],tmp[1000005];
void check()
{
	int sl=1,sr=2*n;
	for(int i=1;i<=n;++i)
	{
		if(tmp[i]=='L')	seq[i]=a[sl++];
		else	seq[i]=a[sr--];
	}
	reverse(seq+1,seq+1+n);
	int pos=n;
	for(int i=1;i<=n;++i)
	{
		if(a[sl]==seq[i])	tmp[++pos]='L',++sl;
		else	tmp[++pos]='R',--sr;
	}
//	puts(tmp+1);
	if(ans[1]==0)	memcpy(ans,tmp,sizeof tmp);
	else
	{
		for(int i=1;i<=2*n;++i)
		{
			if(ans[i]>tmp[i])
			{
				memcpy(ans,tmp,sizeof tmp);
				return ;
			}
			else if(ans[i]<tmp[i])	return ;
		}
	}
}
bool getAns(int l,int r)
{
	for(int i=l;i<=r;++i)	ps2[a[i]]=i;
	for(int i=1;i<l;++i)	ps1[a[i]]=i;
	for(int i=r+1;i<=2*n;++i)	ps1[a[i]]=i;
	if(l==1)
	{
		int sl=ps2[a[2*n]],sr=ps2[a[2*n]];
		for(int i=2*n-1;i>r;--i)
		{
			if(ps2[a[i]]==sl-1)	--sl;
			else if(ps2[a[i]]==sr+1)	++sr;
			else	return false;
		}
		for(int i=1;i<=n;++i)	tmp[i]='R';
		check();
		return true;
	}
	else if(r==2*n)
	{
		int sl=ps2[a[1]],sr=ps2[a[1]];
		for(int i=2;i<l;++i)
		{
			if(ps2[a[i]]==sl-1)	--sl;
			else if(ps2[a[i]]==sr+1)	++sr;
			else	return false;
		}
		for(int i=1;i<=n;++i)	tmp[i]='L';
		check();
		return true;
	}
	else
	{
		bool suc=false;
		int sl,sr,pl,pr,st;
		st=0;
		pl=2,pr=2*n;
		sl=ps2[a[1]],sr=ps2[a[1]];
		tmp[++st]='L';
		while(sl!=l || sr!=r)
		{
			if(pl!=l && ps2[a[pl]]==sl-1)
			{
				--sl;
				tmp[++st]='L';
				++pl;
				continue;
			}
			if(pl!=l && ps2[a[pl]]==sr+1)
			{
				++sr;
				tmp[++st]='L';
				++pl;
				continue;
			}
			if(pr!=r && ps2[a[pr]]==sl-1)
			{
				--sl;
				tmp[++st]='R';
				--pr;
				continue;
			}
			if(pr!=r && ps2[a[pr]]==sr+1)
			{
				++sr;
				tmp[++st]='R';
				--pr;
				continue;
			}
			goto fail1;
		}
		suc=true;
		check();
		fail1:;
		st=0;
		pl=1,pr=2*n-1;
		sl=ps2[a[2*n]],sr=ps2[a[2*n]];
		tmp[++st]='R';
		while(sl!=l || sr!=r)
		{
			if(pl!=l && ps2[a[pl]]==sl-1)
			{
				--sl;
				tmp[++st]='L';
				++pl;
				continue;
			}
			if(pl!=l && ps2[a[pl]]==sr+1)
			{
				++sr;
				tmp[++st]='L';
				++pl;
				continue;
			}
			if(pr!=r && ps2[a[pr]]==sl-1)
			{
				--sl;
				tmp[++st]='R';
				--pr;
				continue;
			}
			if(pr!=r && ps2[a[pr]]==sr+1)
			{
				++sr;
				tmp[++st]='R';
				--pr;
				continue;
			}
			goto fail2;
		}
		suc=true;
		check();
		fail2:;
		return suc;
	}
}
void Solve()
{
	n=read();
	for(int i=1;i<=2*n;++i)	a[i]=read(),ans[i]=app[i]=ps1[i]=ps2[i]=0;
	vector<pair<int,int>> Seg;
	int pos=0,f=0;
	for(int i=1;i<=2*n;++i)
	{
		while(pos<2*n)
		{
			++pos;
			++app[a[pos]];
			if(app[a[pos]]==1)	++f;
			else
			{
				--app[a[pos]];
				--pos;
				break;
			}
		}
		if(f==n)	Seg.push_back(mp(i,pos));
		if(app[a[i]]==1)	--f;
		--app[a[i]];
	}
	bool flag=false;
	for(auto st:Seg)	flag|=getAns(st.first,st.second);
	puts(flag?ans+1:"-1");
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T-->0)	Solve();
	return 0;
}

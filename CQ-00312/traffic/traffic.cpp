#include<bits/stdc++.h>
using namespace std;
namespace IO
{
	const int buf_size=1<<20;
	char buf[buf_size],*S,*T;
	inline char read_char()
	{
		if(S==T)
			T=(S=buf)+fread(buf,1,buf_size,stdin);
		return S!=T?*(S++):EOF;
	}
	inline int read_int()
	{
		char c=read_char();
		bool neg=false;
		while(c<'0'||c>'9')
		{
			neg=(c=='-');
			c=read_char();
		}
		int x=0;
		while(c>='0'&&c<='9')
		{
			x=x*10+(c^'0');
			c=read_char();
		}
		return neg?-x:x;
	}
	char fw[buf_size];
	int pw;
	inline void flush()
	{
		fwrite(fw,1,pw,stdout);
		pw=0;
	}
	inline void write_char(char x)
	{
		if(pw==buf_size)
			flush();
		fw[pw++]=x;
	}
	inline void write_int(int x)
	{
		if(!x)
		{
			write_char('0');
			return;
		}
		if(x<0)
		{
			write_char('-');
			x=-x;
		}
		static char st[26];
		int tp=0;
		while(x)
		{
			st[++tp]=x%10^'0';
			x/=10;
		}
		while(tp>0)
			write_char(st[tp--]);
	}
}
int n,m,T;
const int max_n=500+5;
const int max_m=500+5;
int v1[max_n][max_m],v2[max_n][max_m];
inline int Abs(int x)
{
	return x>0?x:-x;
}
inline int query(int a,int b,int c,int d)
{
	if(a==c)
	{
		if(b>d)
			swap(b,d);
		if(d!=b+1)
			return 0;
		return v2[a][b];
	}
	if(b==d)
	{
		if(a>c)
			swap(a,c);
		if(c!=a+1)
			return 0;
		return v1[a][b];
	}
	return 0;
}
const int max_k=50+5;
int x[max_k],p[max_k],t[max_k];
/*
namespace Subtask1
{
	const int max_n=5+5;
	const int max_m=5+5;
	int id[max_n][max_m];
	const int max_tot=25+5;
	int X[max_tot],Y[max_tot];
	const int max_s=1<<25|5;
	int val[max_s];
	inline void solve()
	{
		int tot=0;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
			{
				X[tot]=i,Y[tot]=j;
				id[i][j]=tot++;
			}
		for(int s=0;s<(1<<tot);++s)
		{
			int res=0;
			for(int i=1;i<=n-1;++i)
				for(int j=1;j<=m;++j)
				{
					if((s>>id[i][j]&1)!=(s>>id[i+1][j]&1))
						res+=v1[i][j];
				}
			for(int i=1;i<=n;++i)
				for(int j=1;j<=m-1;++j)
				{
					if((s>>id[i][j]&1)!=(s>>id[i][j+1]&1))
						res+=v2[i][j];
				}
			val[s]=res;
		}
	}
}
*/
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	n=IO::read_int(),m=IO::read_int(),T=IO::read_int();
	for(int i=1;i<=n-1;++i)
		for(int j=1;j<=m;++j)
			v1[i][j]=IO::read_int();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m-1;++j)
			v2[i][j]=IO::read_int();
//	if(n<=5&&m<=5)
//	{
//		Subtask1::solve();
//		return 0;
//	}
	for(int Case=1;Case<=T;++Case)
	{
		int k=IO::read_int();
		for(int i=1;i<=k;++i)
			x[i]=IO::read_int(),p[i]=IO::read_int(),t[i]=IO::read_int();
		if(k==1)
		{
			puts("0");
			continue;
		}
		if(k==2)
		{
			if(t[1]==t[2])
			{
				puts("0");
				continue;
			}
			if(p[1]>p[2])
			{
				swap(x[1],x[2]);
				swap(p[1],p[2]);
				swap(t[1],t[2]);
			}
			if((p[1]==1&&p[2]==2*m+2*n)||(p[1]==m&&p[2]==m+1)||(p[1]==m+n&&p[2]==m+n+1)||(p[1]==2*m+n&&p[2]==2*m+n+1))
			{
				printf("%d\n",min(x[1],x[2]));
				continue;
			}
		}
	}
	IO::flush();
	return 0;
}


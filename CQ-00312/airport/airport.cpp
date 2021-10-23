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
typedef pair<int,int> P;
set<P> S;
const int max_n=1e5+5;
int cnt[2][max_n],M[2];
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n=IO::read_int();
	M[0]=IO::read_int(),M[1]=IO::read_int();
//	fprintf(stderr,"n=%d m1=%d m2=%d\n",n,M[0],M[1]);
	for(int k=0;k<=1;++k)
	{
		int m=M[k];
		for(int i=1;i<=m;++i)
		{
			int a=IO::read_int(),b=IO::read_int();
//			fprintf(stderr,"a=%d b=%d\n",a,b);
			S.insert(P(a,b));
		}
		for(int i=1;i<=n;++i)
		{
			cnt[k][i]=cnt[k][i-1];
			int now=-1;
			while(!S.empty())
			{
				set<P>::iterator it=S.upper_bound(P(now,0));
				if(it!=S.end())
				{
					++cnt[k][i];
					now=it->second;
					S.erase(it);
				}
				else
					break;
			}
		}
		S.clear();
	}
	int ans=0;
	for(int i=0;i<=n;++i)
		ans=max(ans,cnt[0][i]+cnt[1][n-i]);
	printf("%d\n",ans);
	return 0;
}


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
int T;
const int max_T=100+5;
int N[max_T],mx_n,sum_n;
vector<int> A[max_T];
int n;
const int max_n=5e5+5;
int a[max_n<<1];
inline void init(int t)
{
	n=N[t];
	for(int i=1;i<=2*n;++i)
		a[i]=A[t][i-1];
}
char ans[max_n<<1];
int b[max_n<<1];
namespace Solution1
{
	bool flag_over;
	void dfs(int x,int y,int l,int r)
	{
		if(x+y==n)
		{
			assert(l==x+1);
			assert(r==2*n-y);
			flag_over=true;
			for(int i=x+1,j=2*n-y,k=1;k<=n;++k)
			{
				if(a[i]==b[n+1-k])
				{
					ans[n+k]='L';
					++i;
				}
				else
				{
					assert(a[j]==b[n+1-k]);
					ans[n+k]='R';
					--j;
				}
			}
			ans[2*n+1]='\0';
			printf("%s\n",ans+1);
			return;
		}
		if(x==0&&y==0)
		{
			for(int i=2;i<=2*n;++i)
			{
				if(a[i]==a[1])
				{
					ans[1]='L';
					b[1]=a[1];
					dfs(1,0,i,i);
					if(flag_over)
						return;
					break;
				}
			}
			for(int i=1;i<=2*n-1;++i)
			{
				if(a[i]==a[2*n])
				{
					ans[1]='R';
					b[1]=a[2*n];
					dfs(0,1,i,i);
					if(flag_over)
						return;
					break;
				}
			}
			return;
		}
		if(x+1<l-1&&a[x+1]==a[l-1])
		{
			ans[x+y+1]='L';
			b[x+y+1]=a[x+1];
			dfs(x+1,y,l-1,r);
			if(flag_over)
				return;
		}
		if(x+1<l&&a[x+1]==a[r+1])
		{
			ans[x+y+1]='L';
			b[x+y+1]=a[x+1];
			dfs(x+1,y,l,r+1);
			if(flag_over)
				return;
		}
		if(2*n-y>r&&a[2*n-y]==a[l-1])
		{
			ans[x+y+1]='R';
			b[x+y+1]=a[2*n-y];
			dfs(x,y+1,l-1,r);
			if(flag_over)
				return;
		}
		if(2*n-y>r+1&&a[2*n-y]==a[r+1])
		{
			ans[x+y+1]='R';
			b[x+y+1]=a[2*n-y];
			dfs(x,y+1,l,r+1);
			if(flag_over)
				return;
		}
	}
	inline void solve()
	{
		for(int t=1;t<=T;++t)
		{
			init(t);
//			fprintf(stderr,"t=%d\n",t);
			flag_over=false;
			dfs(0,0,0,0);
			if(!flag_over)
				puts("-1");
		}
	}
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	T=IO::read_int();
	for(int i=1;i<=T;++i)
	{
		N[i]=IO::read_int();
		mx_n=max(mx_n,N[i]);
		sum_n+=N[i];
		A[i].resize(2*N[i]);
		for(int j=0;j<2*N[i];++j)
			A[i][j]=IO::read_int();
	}
	if(mx_n<=20&&T<=100)
		Solution1::solve();
	else
		Solution1::solve();
	IO::flush();
	return 0;
}


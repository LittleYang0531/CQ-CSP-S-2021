//ruo guo ba T<=50 huan cheng T<=20,wo jiang jue sha.
//ke xi huan bu de.
//start time: 16:40
//end time: 18:27(((/ll/ll/ll
//E:70
#include<iostream>
#include<iomanip>
#include<cmath>
#include<ctime>
#include<cctype>
#include<cstdio>
#include<cstdlib>
#include<climits>
//#define NDEBUG
#include<cassert>
#include<cstring>
#include<complex>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<vector>
#include<bitset>
//#define LL __int128
#define LL long long
#define ULL unsigned LL
#define uint unsigned int
//#define int LL
//#define double long double
#define mkp make_pair
#define par pair<int,int>
#define psb push_back
#define epb emplace_back
#define f(x) ((x).first)
#define s(x) ((x).second)
using namespace std;
#define Lbt(x) ((x)&(-(x)))
#define Swap(x,y) (x^=y^=x^=y)
const int Mxxx=1e5;
inline char gc()
{
	static char buf[Mxxx],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxxx,stdin),p1==p2)?EOF:*p1++;
}
inline char pc(char ch,bool fl=false)
{
	static char buf[Mxxx],*p1=buf,*p2=buf+Mxxx;
	return (fl||((*p1++=ch)&&p1==p2))&&(fwrite(buf,1,p1-buf,stdout),p1=buf),0;
}
//#define gc getchar
//#define pc(x,y) y?0:(putchar(x),0)
#define output pc('!',true)
inline int read()
{
	char ch=gc();
	int gans=0,gflag=0;
	for(;ch<'0'||'9'<ch;gflag|=ch=='-',ch=gc());
	for(;'0'<=ch&&ch<='9';gans=(gans<<1)+(gans<<3)+(ch^48),ch=gc());
	return gflag?-gans:gans;
}
template<typename T>
inline char read(T&gans)
{
	char ch=gc();
	int gflag=0;gans=0;
	for(;ch<'0'||'9'<ch;gflag|=ch=='-',ch=gc());
	for(;'0'<=ch&&ch<='9';gans=(gans<<1)+(gans<<3)+(ch^48),ch=gc());
	return gans=gflag?-gans:gans,ch;
}
template<typename T>
inline void write(T x)
{
	if(x>9)write(x/10);
	pc(x%10^48);
}
template<typename T>
inline void writenum(T x,char ch)
{
	if(x<0)pc('-'),x=-x;
	write(x);pc(ch);
}
inline void writechar(char x,char ch)
{
	pc(x);pc(ch);
}
template<typename T>
inline T Max(T x,T y)
{
	return x>y?x:y;
}
template<typename T>
inline T Min(T x,T y)
{
	return x<y?x:y;
}
template<typename T>
inline T Abs(T x)
{
	return x<0?-x:x;
}
template<typename T>
inline void ckmx(T&x,T y)
{
	x=Max(x,y);
}
template<typename T>
inline void ckmn(T&x,T y)
{
	x=Min(x,y);
}
const int Mx=500;
int n,m,Q,T[Mx+5],vl1[Mx+5][Mx+5],vl2[Mx+5][Mx+5];
vector<pair<par,int> >vec[Mx+5];
int psx[Mx+5],psy[Mx+5];
int pre[Mx+5][Mx+5],val[Mx+5][Mx+5];
const int N=18;
int ans,F[N+1][1<<N];
int stt[N+1];
inline int Calc0(int st)
{
	int i,s=0;
	for(i=1;i<=m;i++)
	{
		stt[i]=(st>>(i-1))&1;
	}
	for(i=1;i<m;i++)
	{
		s+=stt[i]^stt[i+1]?vl2[1][i]:0;
	}
	for(i=1;i<=m;i++)
	{
		s+=~pre[0][i]&&stt[i]^pre[0][i]?val[0][i]:0;
	}
//	cout<<"Calc0:"<<st<<":"<<s<<" "<<(~pre[1][0]&&stt[1]^pre[1][0]?val[1][0]:0)<<" "<<(~pre[1][m+1]&&stt[m]^pre[1][m+1]?val[1][m+1]:0)<<"|"
//	<<s+(~pre[1][0]&&stt[1]^pre[1][0]?val[1][0]:0)+(~pre[1][m+1]&&stt[m]^pre[1][m+1]?val[1][m+1]:0)<<"\n";
	return s+=(~pre[1][0]&&stt[1]^pre[1][0]?val[1][0]:0)+(~pre[1][m+1]&&stt[m]^pre[1][m+1]?val[1][m+1]:0);
}
inline int Calcn(int st)
{
	int i,s=0;
	for(i=1;i<=m;i++)
	{
		stt[i]=(st>>(i-1))&1;
	}
	for(i=1;i<=m;i++)
	{
		s+=~pre[n+1][i]&&stt[i]^pre[n+1][i]?val[n+1][i]:0;
	}
//	cout<<"Calcn:"<<st<<":"<<s<<"\n";
	return s;
}
inline int Val(int f,int x,int y,int st,int f2)
{
	int s=0;
	if(y==1)
	{
		s=~pre[x][0]&&f^pre[x][0]?val[x][0]:0;
	}
	else
	{
		int f1=(st>>(y-2))&1;
		s=f^f1?vl2[x][y-1]:0;
	}
//	cout<<"Val:"<<x<<" "<<y<<":"<<s<<" "<<(f^f2?vl1[x-1][y]:0)<<" "<<(y==m&&~pre[x][m+1]&&f^pre[x][m+1]?val[x][m+1]:0)<<"|"
//	<<f<<" "<<(y==1?~pre[x][0]&&f^pre[x][0]:f^((st>>(y-2))&1))<<" "<<f2<<"\n";
	s+=f^f2?vl1[x-1][y]:0;
	return s+(y==m&&~pre[x][m+1]&&f^pre[x][m+1]?val[x][m+1]:0);
}
const int M=Mx*Mx;
int cnt,h[M+5],nxt[(M<<3)+5],tto[(M<<3)+5],wgt[(M<<3)+5];
inline void ade(int x,int y,int v)
{
	nxt[++cnt]=h[x];
	tto[h[x]=cnt]=y;
	wgt[cnt]=v;
}
inline void Ade(int x,int y,int v)
{
//	cout<<"Ade:"<<x<<"<->"<<y<<":"<<v<<"\n";
	ade(x,y,v);ade(y,x,v);
}
int ds[M+5],vst[M+5];
priority_queue<par>q;
inline int Dij(int s,int t)
{
	int i,x,to;
	for(i=1;i<=t;i++)vst[i]=0,ds[i]=INT_MAX;
	q.push(mkp(-(ds[s]=0),s));
	for(;!q.empty();)
	{
		x=s(q.top());q.pop();
		if(vst[x])continue;vst[x]=1;
		for(i=h[x];i;i=nxt[i])
		{
			if(ds[to=tto[i]]>ds[x]+wgt[i])
			{
				ds[to]=ds[x]+wgt[i];
				q.push(mkp(-ds[to],to));
			}
		}
	}
	return ds[t];
}
int anss[Mx+5];
signed main()
{/*9184175
181573
895801
498233
0*/
	#ifndef ONLINE_JUDGE
//	system("fc _.out traffic4.ans");
//	freopen("traffic4.in","r",stdin);
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	#endif
	int i,j,k,t,p,v,f,ff;
	n=read();m=read();Q=read();
	for(i=1;i<n;i++)
	{
		for(j=1;j<=m;j++)
		{
			vl1[i][j]=read();
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<m;j++)
		{
			vl2[i][j]=read();
		}
	}
	for(i=1;i<=m;i++)
	{
		psx[i]=0;psy[i]=i;
	}
	for(i=1;i<=n;i++)
	{
		psx[m+i]=i;psy[m+i]=m+1;
	}
	for(i=1;i<=m;i++)
	{
		psx[m+n+i]=n+1;
		psy[m+n+i]=(m-i+1);
	}
	for(i=1;i<=n;i++)
	{
		psx[(m<<1)+n+i]=(n-i+1);
		psy[(m<<1)+n+i]=0;
	}
//	if(n<=18&&m<=18&&false)
	if(n<=18&&m<=18)
	{
		for(;Q;Q--)
		{
			t=read();
			for(i=1;i<=(n+m)<<1;i++)
			{
				pre[psx[i]][psy[i]]=-1;
				val[psx[i]][psy[i]]=0;
			}
			for(i=1;i<=t;i++)
			{
				v=read();p=read();f=read();
				pre[psx[p]][psy[p]]=f;
				val[psx[p]][psy[p]]=v;
			}
			for(i=0;i<1<<m;i++)
			{
				F[m][i]=Calc0(i);
			}
			for(i=2;i<=n;i++)
			{
				for(j=0;j<1<<m;j++)
				{
					F[0][j]=F[m][j];
				}
				for(k=1;k<=m;k++)
				{
					for(j=0;j<1<<m;j++)
					{
						p=(f=(j>>(k-1))&1)?j^(1<<(k-1)):j;
						F[k][j]=Min(F[k-1][p]+Val(f,i,k,p,0),F[k-1][p|(1<<(k-1))]+Val(f,i,k,p,1));
//						cout<<"F:"<<i<<" "<<j<<" "<<k<<":"<<p<<" "<<F[k][j]<<"\n";
					}
				}
			}
			for(ans=INT_MAX,i=0;i<1<<m;i++)
			{
				ckmn(ans,F[m][i]+Calcn(i));
			}
			writenum(ans,10);
		}
		return output;
	}
	for(ff=i=1;i<=Q;i++)
	{
		T[i]=read();
		ff&=T[i]<=2;
		for(j=1;j<=T[i];j++)
		{
			v=read();p=read();f=read();
			vec[i].epb(mkp(mkp(v,p),f));
		}
	}
//	if(ff)
	{
		for(i=1;i<=Q;i++)
		{
			#define ps(x,y) ((x-1)*(m-1)+(y))
			if(T[i]==1||T[i]>2)continue;
			int s=ps(n-1,m-1)+1,t=ps(n-1,m-1)+2,v1,p1,f1,v2,p2,f2;
			cnt=0;for(j=1;j<=t;j++)h[j]=0;
			for(j=1;j<n;j++)
			{
				for(k=1;k<m;k++)
				{
					if(j<n-1)
					{
						Ade(ps(j,k),ps(j+1,k),vl2[j+1][k]);
					}
					if(k<m-1)
					{
						Ade(ps(j,k),ps(j,k+1),vl1[j][k+1]);
					}
				}
			}
			v1=f(f(vec[i][0]));
			p1=s(f(vec[i][0]));
			f1=s(vec[i][0]);
			v2=f(f(vec[i][1]));
			p2=s(f(vec[i][1]));
			f2=s(vec[i][1]);
			if(p1>p2)
			{
				Swap(p1,p2);
				swap(v1,v2);
				swap(f1,f2);
			}
			for(j=1;j<m;j++)
			{
				Ade(ps(1,j),(j<p1||j>=p2?t:s),vl2[1][j]);
			}
			for(j=1;j<n;j++)
			{
				Ade(ps(j,m-1),(m+j<p1||m+j>=p2?t:s),vl1[j][m]);
			}
			for(j=1;j<m;j++)
			{
				Ade(ps(n-1,m-1-(j-1)),(m+n+j<p1||m+n+j>=p2?t:s),vl2[n][m-j]);
			}
			for(j=1;j<n;j++)
			{
				Ade(ps(n-1-(j-1),1),((m<<1)+n+j<p1||(m<<1)+n+j>=p2?t:s),vl1[n-j][1]);
			}
//			cout<<"???:"<<Min(v1,v2)<<"\n";
			Ade(s,t,f1==f2?0:Min(v1,v2));
			anss[i]=Dij(s,t);
//			writenum(Dij(s,t),10);
		}
		for(i=1;i<=Q;i++)
		{
			writenum(anss[i],10);
		}
		return output;
	}
	if(Min(n,m)<=18)
	{
		return puts("sbC*F,chu ni ma de shen me sha bi shui shui shui shui(=man)shu ju,wo ri ni xian ren,wo ri le ni de ma yo"),
		puts("ni ma chou de cong ta de fen tou cao li zhang chu lai ba ta quan jia de gu hui he li de gu hui dou gei ni na chu lai dao le"),6662333;
		return output;
	}
	return output;
}
/*
2 3 1
9 4 7
3 8
10 5
2
19 3 1
17 9 0
*///12

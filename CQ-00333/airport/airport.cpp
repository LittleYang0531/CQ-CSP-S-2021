//E:100
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
const int Mx=1e5;
const int M=Mx<<1;
int n,m1,m2;
namespace btt
{
	int c[Mx+5];
	inline void Clr()
	{
		int i;
		for(i=1;i<=n;i++)c[i]=0;
	}
	inline void Add(int x,int v)
	{
		int i;
		for(i=x;i<=n;i+=Lbt(i))
		{
			c[i]+=v;
		}
	}
	inline int Ask(int x)
	{
		int i,s=0;
		for(i=x;i;i-=Lbt(i))
		{
			s+=c[i];
		}
		return s;
	}
}
struct Node
{
	int l,r;
	inline void Read()
	{
		l=read();r=read();
	}
}P[Mx+5];
int top,ans,stk[M+5],ans1[Mx+5],ans2[Mx+5];
set<int>st;
vector<int>vec[M+5];
signed main()
{//32
	#ifndef ONLINE_JUDGE
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	#endif
	int i,j,l,r,x;
	n=read();m1=read();m2=read();
	for(i=1;i<=m1;i++)
	{
		P[i].Read();
		stk[++top]=P[i].l;stk[++top]=P[i].r;
	}
	sort(stk+1,stk+1+top);
//	assert(top==unique(stk+1,stk+1+top)-stk-1);
	sort(P+1,P+1+m1,[](const Node&x,const Node&y){return x.l<y.l;});
	for(i=1;i<=n;i++)
	{
		st.insert(i);
	}
	for(j=0,i=1;i<=m1;i++)
	{
		l=P[i].l=lower_bound(stk+1,stk+1+top,P[i].l)-stk;
		r=P[i].r=lower_bound(stk+1,stk+1+top,P[i].r)-stk;
		for(;j<=l;j++)
		{
			for(int to:vec[j])
			{
//				cout<<"Back:"<<j<<" "<<to<<"\n";
				st.insert(to);
			}
		}
		if(!st.empty())
		{
			x=*st.begin();
			st.erase(st.begin());
			vec[r].epb(x);
//			cout<<"flight:"<<i<<':'<<l<<' '<<r<<" "<<x<<"\n";
			btt::Add(x,1);
		}
	}
	for(i=1;i<=n;i++)
	{
		ans1[i]=btt::Ask(i);
	}
	btt::Clr();top=0;
	for(i=1;i<=m2;i++)
	{
		P[i].Read();
		stk[++top]=P[i].l;stk[++top]=P[i].r;
	}
	sort(stk+1,stk+1+top);
	for(i=1;i<=top;i++)vec[i].clear();
//	assert(top==unique(stk+1,stk+1+top)-stk-1);
	sort(P+1,P+1+m2,[](const Node&x,const Node&y){return x.l<y.l;});
	st.clear();
	for(i=1;i<=n;i++)
	{
		st.insert(i);
	}
	for(j=0,i=1;i<=m2;i++)
	{
		l=P[i].l=lower_bound(stk+1,stk+1+top,P[i].l)-stk;
		r=P[i].r=lower_bound(stk+1,stk+1+top,P[i].r)-stk;
		for(;j<=l;j++)
		{
			for(int to:vec[j])
			{
				st.insert(to);
			}
		}
		if(!st.empty())
		{
			x=*st.begin();
			st.erase(st.begin());
			vec[r].epb(x);
			btt::Add(x,1);
		}
	}
	for(i=1;i<=n;i++)
	{
		ans2[i]=btt::Ask(i);
	}
	for(i=0;i<=n;i++)
	{
//		cout<<"ans:"<<i<<":"<<ans1[i]<<" "<<ans2[i]<<"\n";
		ckmx(ans,ans1[i]+ans2[n-i]);
	}
	writenum(ans,10);
	return output;
}
/*
3 5 4 
1 5
3 8
6 10
9 14
13 18
2 11
4 15
7 17
12 16
*///7
/*
2 4 6
20 30
40 50
21 22
41 42
1 19
2 18
3 4
5 6
7 8
9 10
*///4

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
const int Mx=5e5;
const int M=Mx<<1;
int TT,n,m,p[M+5];
int top1,top2,stk1[Mx+5],stk2[Mx+5];
inline int Slv(int a,int b,int c,int d,int dep=0)
{
//	if(dep>=n)
//	{
//		cerr<<a<<" "<<b<<" "<<c<<" "<<d<<"???NMSL\n";
//	}
//	if(a>c||d>b)return 
//	cout<<"Slv_Fail1:"<<a<<" "<<b<<" "<<c<<" "<<d<<"\n",
//	0;
	if(a==c&&b==d)
	{
		return 
//		cout<<"Slv_Sucs1:"<<a<<" "<<b<<" "<<c<<" "<<d<<"\n",
		stk1[++top1]=a,stk2[++top2]=b,1;
	}
	if(a>c&&d>b)return 
//	cout<<"Slv_Sucs2:"<<a<<" "<<b<<" "<<c<<" "<<d<<"\n",
	1;
	int f;
	if(a<c&&p[a]==p[c])
	{
		f=Slv(a+1,b,c-1,d
		,dep+1
		);
		return stk1[++top1]=a,stk2[++top2]=c,f;
	}
	if(a<=c&&d<=b&&p[a]==p[d])
	{
		f=Slv(a+1,b,c,d+1
		,dep+1
		);
		return stk1[++top1]=a,stk2[++top2]=d,f;
	}
	if(a<=c&&d<=b&&p[b]==p[c])
	{
		f=Slv(a,b-1,c-1,d
		,dep+1
		);
		return stk1[++top1]=b,stk2[++top2]=c,f;
	}
	if(d<b&&p[b]==p[d])
	{
		f=Slv(a,b-1,c,d+1
		,dep+1
		);
		return stk1[++top1]=b,stk2[++top2]=d,f;
	}
//	cout<<"Slv_Fail:"<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
	return 0;
}
int ps[Mx+5][2];
signed main()
{
	#ifndef ONLINE_JUDGE
//	system("fc _.out palin2.ans");
//	freopen("palin2.in","r",stdin);
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	#endif
	int i,l,r;
	for(TT=read();TT;TT--)
	{
		n=read();m=n<<1;
		for(i=1;i<=n;i++)
		{
			ps[i][0]=ps[i][1]=0;
		}
		for(i=1;i<=m;i++)
		{
			p[i]=read();
			if(!ps[p[i]][0])
			{
				ps[p[i]][0]=i;
			}
			else
			{
				ps[p[i]][1]=i;
			}
		}
		top1=top2=0;
		if(Slv(2,m,ps[p[1]][1]-1,ps[p[1]][1]+1))
		{
			stk1[++top1]=1;
			stk2[++top2]=ps[p[1]][1];
//			cerr<<top1<<" "<<top2<<"\n";
			assert(top1==n&&top2==n);
			for(l=1,r=m,i=top1;i;i--)
			{
				assert(stk1[i]==l||stk1[i]==r);
				if(stk1[i]==l)
				{
					pc('L');
					l++;
				}
				else
				{
					pc('R');
					r--;
				}
			}
			for(i=1;i<=top2;i++)
			{
				assert(stk2[i]==l||stk2[i]==r);
				if(stk2[i]==l)
				{
					pc('L');
					l++;
				}
				else
				{
					pc('R');
					r--;
				}
			}
			pc(10);
			continue;
		}
//		puts("???");
		top1=top2=0;
		if(Slv(1,m-1,ps[p[m]][0]-1,ps[p[m]][0]+1))
		{
			stk1[++top1]=m;
			stk2[++top2]=ps[p[m]][0];
//			cerr<<top1<<" "<<top2<<"\n";
			assert(top1==n&&top2==n);
			for(l=1,r=m,i=top1;i;i--)
			{
				assert(stk1[i]==l||stk1[i]==r);
				if(stk1[i]==l)
				{
					pc('L');
					l++;
				}
				else
				{
					pc('R');
					r--;
				}
			}
			for(i=1;i<=top2;i++)
			{
				assert(stk2[i]==l||stk2[i]==r);
				if(stk2[i]==l)
				{
					pc('L');
					l++;
				}
				else
				{
					pc('R');
					r--;
				}
			}
			pc(10);
			continue;
		}
		writenum(-1,10);
	}
	return output;
}
/*
2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3
*/
/*
LRRLLRRRRL
-1
*/
/*
1
20
5 13 1 3 2 16 7 19 6 18 10 4 4 10 20 18 6 19 7 8 2 14 1 11 17 9 13 5 15 3 16 12 20 12 8 14 15 11 17 9

5 13 1 3 2 16 7 19 6 18 10 4 4 10 20 18 6 19 7 8 2 14 1 11 17 9 13 5 15 3 16 12 20 12 8 14 15 11 17 9
*/

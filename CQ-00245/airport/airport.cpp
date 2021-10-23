#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a,i##END=b;i<=i##END;++i)
#define go(x) for(int i=a,i##END=b;i<=i##END;++i)
template<class T>
inline void in(T&x)
{
	T f=1;x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	x*=f;
}
template void in<int>(int&);
template<class T>
void out(T x)
{
	if(x<0)putchar('-'),x=-x;
	if(x>9)out(x/10);
	putchar(x%10^48);
}
template void out<int>(int);

using namespace std;

const int N=105005;

int n,m1,m2,ans;
//int ex[N*4];
int num[2][N];

struct fly
{
	int l,r;
	friend bool operator<(const fly&A,const fly&B)
	{
		return A.l<B.l;
	}
}a[2][N];

//void exlize()
//{
//	sort(ex+1,ex+1+ex[0]);
//	For(i,1,m1)
//	{
//		a[0][i].l=lower_bound(ex+1,ex+1+ex[0],a[0][i].l)-ex;
//		a[0][i].r=lower_bound(ex+1,ex+1+ex[0],a[0][i].r)-ex;
//	}
//	For(i,1,m2)
//	{
//		a[1][i].l=lower_bound(ex+1,ex+1+ex[0],a[1][i].l)-ex;
//		a[1][i].r=lower_bound(ex+1,ex+1+ex[0],a[1][i].r)-ex;
//	}
//}

set<fly>::iterator it;

void Link(int w,int m)
{
	set<fly>q;
	q.clear();
	For(i,1,m)q.insert(a[w][i]);
	For(i,1,n)
	{
		fly p=(fly){0,0};
//		printf("i:%d\n",i);
		int now=0;
		while(1)
		{
			it=q.upper_bound(p);
			if(it==q.end())break;
//			printf("l,r:%d %d\n",it->l,it->r);
			++now;
			p=(fly){it->r,0};
			q.erase(it);
		}
		num[w][i]=num[w][i-1]+now;
	}
}

signed main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	in(n),in(m1),in(m2);
	For(i,1,m1)
	{
		in(a[0][i].l),in(a[0][i].r);
//		ex[++ex[0]]=a[0][i].l,ex[++ex[0]]=a[0][i].r;
	}
	For(i,1,m2)
	{
		in(a[1][i].l),in(a[1][i].r);
//		ex[++ex[0]]=a[1][i].l,ex[++ex[0]]=a[1][i].r;
	}
//	exlize();
	sort(a[0]+1,a[0]+1+m1);
	sort(a[1]+1,a[1]+1+m2);
	Link(0,m1);
	Link(1,m2);
	For(i,0,n)
	{
//		printf("%d %d\n",num[0][i],num[1][i]);
		ans=max(ans,num[0][i]+num[1][n-i]);
	}
	out(ans);
	return 0;
}

#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
#include<set>
#include<map>
#define LL long long
using namespace std;
const int INF=1e9;
int rd()
{
	int s=0;bool bj=0;char ch=getchar();
	while(ch<'0'||ch>'9'){bj|=(ch=='-');ch=getchar();}
	while(ch>='0'&&ch<='9'){s=(s<<1)+(s<<3)+(ch^48);ch=getchar();}
	return bj?-s:s;
}
void ptnum(int x)
{
	if(x>9)ptnum(x/10);
	putchar(x%10^48);
}
void pt(int x,char ch)
{
	if(x<0){x=-x;putchar('-');}
	ptnum(x);
	putchar(ch);
}
int n,m[2];
struct node{int l,r;}a[2][100005];
map<int,int>rev[2];
set<int>aha[2];
bool cmp(node x,node y){return x.l<y.l;}
int f[2][100005];
bool vst[100005];
void Work(int bj)
{
	f[bj][0]=0;memset(vst,0,sizeof(vst));
	int no=INF;
	for(int i=1;i<=n;++i)
	{
//		cout<<"i:     "<<i<<endl;
		f[bj][i]=f[bj][i-1];
		if(f[bj][i]==m[bj])continue;
		for(int j=1;j<=m[bj];++j)
		if(!vst[j])
		{
			vst[j]=1;no=a[bj][j].r;
			aha[bj].erase(no);
			break;
		}
		if(no==INF)break;
		++f[bj][i];
		while(1)
		{
//			cout<<no<<endl;
			no=*aha[bj].lower_bound(no);
//			cout<<"QAQ"<<no<<" ";cout<<rev[bj][no]<<" "<<a[bj][rev[bj][no]].r<<endl;
			if(no==INF)break;
			int num=rev[bj][no];
			vst[num]=1;aha[bj].erase(no);
			no=a[bj][num].r;
			++f[bj][i];
		}
	}
//	for(int i=0;i<=n;++i)pt(f[bj][i],' ');puts("");
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=rd();m[0]=rd();m[1]=rd();
	for(int i=1;i<=m[0];++i){a[0][i].l=rd();a[0][i].r=rd();aha[0].insert(a[0][i].l);}
	for(int i=1;i<=m[1];++i){a[1][i].l=rd();a[1][i].r=rd();aha[1].insert(a[1][i].l);}
	aha[0].insert(INF);aha[1].insert(INF);
	sort(a[0]+1,a[0]+m[0]+1,cmp);sort(a[1]+1,a[1]+m[1]+1,cmp);
	for(int i=1;i<=m[0];++i)rev[0][a[0][i].l]=i;
	for(int i=1;i<=m[1];++i)rev[1][a[1][i].l]=i;
	Work(0);Work(1);
	int maxx=0;
	for(int i=0;i<=n;++i)maxx=max(maxx,f[0][i]+f[1][n-i]);
	pt(maxx,'\n');
	return 0;
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
*/
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
*/

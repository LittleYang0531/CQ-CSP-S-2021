#include <queue>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
void read(int &x)
{
	x=0;char c=getchar();int f=1;
	while(!('0'<=c&&c<='9')){if(f=='-')f=-1;c=getchar();}
	while('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();}
	x*=f;
}
struct Seg{
	int l,r,cnt;
}P[200005];
int res1[200005],res2[200005];
int brr[200005],cnt,tag[200005],Ans[200005];
priority_queue<int,vector<int>,greater<int> >Q;
int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m1,m2;
	read(n);read(m1);read(m2);
	for(int i=1;i<=m1;i++) read(P[i].l),read(P[i].r),brr[++cnt]=P[i].l,brr[++cnt]=P[i].r;
	sort(brr+1,brr+1+cnt);cnt=unique(brr+1,brr+1+cnt)-brr-1;
	for(int i=1;i<=m1;i++)
	{
		P[i].l=lower_bound(brr+1,brr+1+cnt,P[i].l)-brr;
		P[i].r=lower_bound(brr+1,brr+1+cnt,P[i].r)-brr;
		tag[P[i].l]=i; tag[P[i].r]=-i;
	}
	int Sum=0;
	for(int i=1;i<=cnt;i++)
	{
		if(tag[i]>0)
		{
			if(!Q.empty())
			{
				int u=Q.top();
				res1[u]++,Ans[i]=u;Q.pop();
			}
			else Ans[i]=++Sum,res1[Ans[i]]++;
		}
		else Q.push(Ans[P[-tag[i]].l]);
	}
	for(int i=1;i<=n;i++) res1[i]+=res1[i-1];
	
	cnt=0;
	for(int i=1;i<=m2;i++) read(P[i].l),read(P[i].r),brr[++cnt]=P[i].l,brr[++cnt]=P[i].r;
	sort(brr+1,brr+1+cnt);cnt=unique(brr+1,brr+1+cnt)-brr-1;
	for(int i=1;i<=m2;i++)
	{
		P[i].l=lower_bound(brr+1,brr+1+cnt,P[i].l)-brr;
		P[i].r=lower_bound(brr+1,brr+1+cnt,P[i].r)-brr;
		tag[P[i].l]=i; tag[P[i].r]=-i;
	}
	for(int i=1;i<=cnt;i++) Ans[i]=0;
	Sum=0;
	while(!Q.empty()) Q.pop();
	for(int i=1;i<=cnt;i++)
	{
		if(tag[i]>0)
		{
			if(!Q.empty())
			{
				int u=Q.top();Q.pop();
				res2[u]++,Ans[i]=u;	
			}
			else Ans[i]=++Sum,res2[Ans[i]]++;
		}
		else Q.push(Ans[P[-tag[i]].l]);
	}
	for(int i=1;i<=n;i++) res2[i]+=res2[i-1];
	
	int ANS=0;
	for(int i=0;i<=n;i++) ANS=max(ANS,res1[i]+res2[n-i]);
	printf("%d",ANS);
	return 0;
}
/*
1 1 5
1 2
3 9
1 5
2 4
6 7
8 10

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

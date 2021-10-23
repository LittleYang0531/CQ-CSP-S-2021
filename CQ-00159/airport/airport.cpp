#include "bits/stdc++.h"
using namespace std;
const int Len = 1e5 + 5;
int n,a,b,GNS[Len],GNT[Len],GWS[Len],GWT[Len];
struct node
{
	int l,r;
}Nei[Len],Wai[Len];
bool cmp(node x,node y){return x.l < y.l;}
int flag[Len];
int tot1,tot2,nval[Len],wval[Len],sumn[Len],sumw[Len],maxn[Len << 2];
#define ls(p) p << 1
#define rs(p) p << 1 | 1
void push_up(int p){maxn[p] = max(maxn[ls(p)] , maxn[rs(p)]);}
void build(int p,int l,int r,int opt)
{
	maxn[p] = 0;
	if(l == r) 
	{
		if(opt == 0) maxn[p] = GNS[l];
		else maxn[p] = GWS[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(ls(p) , l , mid , opt);
	build(rs(p) , mid + 1 , r , opt);
	push_up(p);
}
int findup(int p,int l,int r,int w)
{
	if(l == r) 
	{
		if(maxn[p] > w)
		{
			maxn[p] = 0;
			return l;
		}
		return -1;
	}
	int mid = (l + r) >> 1;
	int ret = 0;
	if(maxn[ls(p)] > w) ret = findup(ls(p) , l , mid , w);
	else ret = findup(rs(p) , mid + 1 , r , w);
	push_up(p);
	return ret;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d %d %d",&n,&a,&b);
	for(int i = 1 ; i <= a ; i ++) scanf("%d %d",&Nei[i].l,&Nei[i].r);
	for(int i = 1 ; i <= b ; i ++) scanf("%d %d",&Wai[i].l,&Wai[i].r);
	sort(Nei + 1 , Nei + 1 + a , cmp);
	sort(Wai + 1 , Wai + 1 + b , cmp);
	for(int i = 1 ; i <= a ; i ++) GNS[i] = Nei[i].l , GNT[i] = Nei[i].r;
	for(int i = 1 ; i <= b ; i ++) GWS[i] = Wai[i].l , GWT[i] = Wai[i].r;
	build(1 , 1 , a , 0);int xxx = 0;
	for(int i = 1 ; i <= a ; i ++)
	{
		if(!flag[i]) 
		{
			flag[i] = ++ tot1;
			nval[flag[i]] = 1;
			int now = i;bool fd = 1;
			while(fd)
			{
				xxx = -1;
				xxx = findup(1 , 1 , a , GNT[now]);
				if(xxx == -1) break;
				flag[xxx] = flag[i];
				nval[flag[i]] ++;
				now = xxx;
			}
		}
	}
	memset(flag , 0 , sizeof flag);
	build(1 , 1 , b , 1);
	xxx = -1;
	for(int i = 1 ; i <= b ; i ++)
	{
		if(!flag[i]) 
		{
			flag[i] = ++ tot2;
			wval[flag[i]] = 1;
			int now = i;bool fd = 1;
			while(fd)
			{
				xxx = -1;
				xxx = findup(1 , 1 , b , GWT[now]);
				if(xxx == -1) break;
				flag[xxx] = flag[i];
				wval[flag[i]] ++;
				now = xxx;
			}
		}
	}
	for(int i = 1 ; i <= tot1 ; i ++) sumn[i] = sumn[i - 1] + nval[i];
	for(int i = 1 ; i <= tot2 ; i ++) sumw[i] = sumw[i - 1] + wval[i];
	int ans = 0;
	for(int i = 0 ; i <= tot1 && i <= n ; i ++) 
	{
		int Lans = sumn[i] , Rans = sumw[min(tot2 , n - i)];
		ans = max(ans , Lans + Rans);
	}
	printf("%d\n",ans);
	return 0;
}

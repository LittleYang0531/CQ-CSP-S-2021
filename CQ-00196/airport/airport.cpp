#include <bits/stdc++.h>
using namespace std;

#define Int register int
#define MAXN 100005

int n,m1,m2,t1[MAXN],t2[MAXN];

struct node{
	int st,ed;
	bool operator < (const node &p)const{return st < p.st;}
}s1[MAXN],s2[MAXN];

struct edge{
	int st,ed,v;
	bool operator < (const edge &p)const{return ed > p.ed;}
};

template <typename T> inline void read (T &x){
	x = 0;char c = getchar();int f = 1;
	while (!isdigit (c)) f *= (c == '-' ? -1 : 1),c = getchar();
	while (isdigit (c)) x = x * 10 + c - '0',c = getchar();
	x *= f;
}
template <typename T> inline void write (T x){
	if (x < 0) putchar ('-'),x = -x;
	if (x > 9) write (x / 10);putchar (x % 10 + '0');
}
template <typename T> inline void chkmax (T &a,T b){a = max (a,b);}
template <typename T> inline void chkmin (T &a,T b){a = min (a,b);}

struct Bit_Tree{
	int up = 1e5,sum[MAXN];
	int lowbit (int x){return x & (-x);}
	void modify (int x,int v){for (Int i = x;i <= up;i += lowbit (i)) sum[i] += v;}
	int query (int x){int res = 0;for (Int i = x;i;i -= lowbit (i)) res += sum[i];return res;}
	void clear (){for (Int i = 1;i <= up;++ i) sum[i] = 0;}
}tree;

signed main(){
	freopen ("airport.in","r",stdin);
	freopen ("airport.out","w",stdout);
	read (n),read (m1),read (m2);
	for (Int i = 1;i <= m1;++ i) read (s1[i].st),read (s1[i].ed);
	for (Int i = 1;i <= m2;++ i) read (s2[i].st),read (s2[i].ed);
	sort (s1 + 1,s1 + m1 + 1),sort (s2 + 1,s2 + m2 + 1);
	priority_queue <edge> q; 
	for (Int i = 1;i <= m1;++ i){
		while (!q.empty() && q.top().ed < s1[i].st) tree.modify (q.top().v,-1),q.pop (); 
		int l = 1,r = i,ans = i;
		while (l <= r){
			int mid = l + r >> 1;
			if (tree.query (mid) < mid) ans = mid,r = mid - 1;
			else l = mid + 1;
		}
		t1[ans] ++,q.push (edge {s1[i].st,s1[i].ed,ans}),tree.modify (ans,1);
	}
	while (!q.empty()) q.pop ();tree.clear();
	for (Int i = 1;i <= m1;++ i){
		while (!q.empty() && q.top().ed < s2[i].st) tree.modify (q.top().v,-1),q.pop (); 
		int l = 1,r = i,ans = i;
		while (l <= r){
			int mid = l + r >> 1;
			if (tree.query (mid) < mid) ans = mid,r = mid - 1;
			else l = mid + 1;
		}
		t2[ans] ++,q.push (edge {s2[i].st,s2[i].ed,ans}),tree.modify (ans,1);
	}
	for (Int i = 1;i <= n;++ i) t1[i] += t1[i - 1],t2[i] += t2[i - 1];
	int ans = 0;
	for (Int i = 0;i <= n;++ i) chkmax (ans,t1[i] + t2[n - i]);
	write (ans),putchar ('\n');
	return 0;
}
/*
似乎按我暴力的做法并没有办法进行优化
我们尝试找到第一个值使得这个点可以进入廊桥
那么我们就需要满足在它前面这个值比当前枚举的值小的飞机这个时候不到这个值个了
有三个log的做法了，等会再写
实时维护ed>当前st的集合，你现在要二分一个mid使得集合里面v<
这个可以使用树状数组实现 
*/

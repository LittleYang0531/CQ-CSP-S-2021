#include<set>
#include<map>
#include<cmath>
#include<stack>
#include<queue>
#include<bitset>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define MAXN 200005
#define LL long long
#define DB double
#define ENDL putchar('\n')
#define lowbit(x) (-(x) & (x))
LL read() {
	LL f=1,x=0;int s = getchar();
	while(s < '0' || s > '9') {if(s<0)return -1;if(s=='-')f=-f;s=getchar();}
	while(s >= '0' && s <= '9') {x = (x<<3) + (x<<1) + (s^48);s = getchar();}
	return f * x;
}
void putpos(LL x) {if(!x)return ;putpos(x/10);putchar((x%10)^48);};
void putnum(LL x) {
	if(!x) {putchar('0');return ;}
	if(x<0) putchar('-'),x = -x;
	return putpos(x);
}
void AIput(LL x,int c) {putnum(x);putchar(c);}

int n,m,s,o,k;
int m1,m2;
struct it{
	int t,op,id;
	it(){t=op=0;}
	it(int T,int O,int I){t=T;op=O;id=I;}
}a[MAXN<<1],b[MAXN<<1];
bool cmp(it a,it b) {return a.t == b.t ? (a.op < b.op):(a.t < b.t);}
int sm[MAXN],pos[MAXN];
int c[MAXN];
void addc(int x,int y) {
	while(x <= n) c[x] += y,x+=lowbit(x);
}
int sum(int x) {
	int s = 0;while(x>0) s+=c[x],x-=lowbit(x);
	return s;
}
int MN() {
	int as = 0;
	for(int i = 17;i >= 0;i --) {
		if(as+(1<<i) <= n && sum(as+(1<<i)) >= 0) {
			as += (1<<i);
		}
	}return as;
}
int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n = read();m1 = read();m2 = read();
	for(int i = 1;i <= m1;i ++) {
		s = read();o = read();
		a[i*2-1] = it(s,1,i);
		a[i*2] = it(o,0,i);
	}
	for(int i = 1;i <= m2;i ++) {
		s = read();o = read();
		b[i*2-1] = it(s,1,i);
		b[i*2] = it(o,0,i);
	}
	sort(a + 1,a + 1 + m1*2,cmp);
	sort(b + 1,b + 1 + m2*2,cmp);
	for(int i = 1;i <= n;i ++) c[i] = 0;
	for(int i = 1;i <= n;i ++) addc(i,-1);
	for(int i = 1;i <= m1*2;i ++) {
		if(a[i].op) {
			int y = a[i].id;
			int ps = MN();
			addc(ps+1,1);
			pos[y] = ps+1;
			sm[ps+1] ++;
		}
		else{
			addc(pos[a[i].id],-1);
		}
	}
	for(int i = 1;i <= n;i ++) c[i] = 0;
	for(int i = 1;i <= n;i ++) addc(i,-1);
	for(int i = 1;i <= m2*2;i ++) {
		if(b[i].op) {
			int y = b[i].id;
			int ps = MN();
			addc(ps+1,1);
			pos[y] = ps+1;
			sm[0] ++;
			sm[n-ps] --;
		}
		else {
			addc(pos[b[i].id],-1);
		}
	}
	int ans = sm[0];
	for(int i = 1;i <= n;i ++) {
		sm[i] += sm[i-1];
		ans = max(ans,sm[i]);
	}
	AIput(ans,'\n');
	return 0;
}

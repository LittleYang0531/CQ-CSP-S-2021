#include<bits/stdc++.h>
#define file(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
#define mod 1000000007
#define ll long long
#define N 1000005
using namespace std;
template<class T>void read(T&x) {
	T f=1;x=0;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();}
	x*=f;
}
char _st;
int T,n,tot,a[N],ans[N],fir[N],lst[N],tim[N];
bool solveL() {
	int p = lst[a[1]],L1 = 2,R1 = p-1,L2 = p+1,R2 = n*2;
	ans[tot = 1] = 0;tim[p] = n*2-tot+1;
	while(tot < n) {
		if((L1 <  R1 && a[L1] == a[R1]) || (L1 <= R1 && a[L1] == a[L2])) {
			ans[++tot] = 0;
			if(L1 < R1 && a[L1] == a[R1])tim[R1] = n*2-tot+1,L1++,R1--;
			else tim[L2] = n*2-tot+1,L1++,L2++;
		}
		else if((L2 < R2 && a[R2] == a[L2]) || (L2 <= R2 && a[R2] == a[R1])) {
			ans[++tot] = 1;
			if(L2 < R2 && a[R2] == a[L2])tim[L2] = n*2-tot+1,R2--,L2++;
			else tim[R1] = n*2-tot+1,R2--,R1--;
		}
		else return 0;
	}
	while(++tot <= n*2) {
		if(L1 <= p && tim[L1] == tot)ans[tot] = 0,L1++;
		else ans[tot] = 1,R2--;
	}
	for(int i=1; i<tot; ++i)putchar(ans[i]?'R':'L');
	putchar('\n');
	return 1;
}
bool solveR() {
	int p = fir[a[n*2]],L1 = 1,R1 = p-1,L2 = p+1,R2 = n*2-1;
	ans[tot = 1] = 1;tim[p] = n*2-tot+1;
	while(tot < n) {
		if((L1 <  R1 && a[L1] == a[R1]) || (L1 <= R1 && a[L1] == a[L2])) {
			ans[++tot] = 0;
			if(L1 < R1 && a[L1] == a[R1])tim[R1] = n*2-tot+1,L1++,R1--;
			else tim[L2] = n*2-tot+1,L1++,L2++;
		}
		else if((L2 < R2 && a[R2] == a[L2]) || (L2 <= R2 && a[R2] == a[R1])) {
			ans[++tot] = 1;
			if(L2 < R2 && a[R2] == a[L2])tim[L2] = n*2-tot+1,R2--,L2++;
			else tim[R1] = n*2-tot+1,R2--,R1--;
		}
		else return 0;
	}
	while(++tot <= n*2) {
		if(L1 <= p && tim[L1] == tot)ans[tot] = 0,L1++;
		else ans[tot] = 1,R2--;
	}
	for(int i=1; i<tot; ++i)putchar(ans[i]?'R':'L');
	putchar('\n');
	return 1;
}
char _ed;
int main() {
	cerr << "Memory: " << ((&_st-&_ed)>>20) << '\n';
	file("palin");
	read(T);
	while(T--) {
		read(n);
		for(int i=1; i<=n*2; ++i)tim[i] = 0;
		for(int i=1; i<=n*2; ++i)read(a[i]),lst[a[i]] = i;
		for(int i=n*2; i>=1; --i)fir[a[i]] = i;
		if(!solveL() && !solveR())puts("-1");
	}
}


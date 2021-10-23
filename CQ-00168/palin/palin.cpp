#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<bitset>
#define inlint inline int
#define inloid inline void
#define inbool inline bool
#define MAXN 45
using namespace std;

namespace _MAIN{
	int n;
	inlint read() {
		register int nega = 1, num = 0, c = getchar();
		for(;~c && !isdigit(c); c = getchar()) if(c == '-') nega = -1;
		for(;~c &&  isdigit(c); c = getchar()) num = num * 10 + c - '0';
		return nega * num;
	}
} using namespace _MAIN;

namespace _SOLV{
	int a[MAXN], b[MAXN];
	inbool chkSeq() {
		for(int i = 1; i <= n; i++) {
			if(b[i] != b[2 * n - i + 1]) return false;
		}
//		for(int i = 1; i <= 2 * n; i++) cout << b[i] << " ";
		return true;
	}
	bitset<MAXN> ans, ope;
	inloid dfs(int lpnt, int rpnt, int dep) {
		if(dep == 2 * n) {
			if(chkSeq() && !ans.to_ulong()) ans = ope;
			return;
		}
		b[dep + 1] = a[lpnt], ope[dep + 1] = 0, dfs(lpnt + 1, rpnt, dep + 1);
		if(!ans.to_ulong()) b[dep + 1] = a[rpnt], ope[dep + 1] = 1, dfs(lpnt, rpnt - 1, dep + 1);
		return;
	}
} using namespace _SOLV;

signed main(void){
	freopen("palin.in", "r", stdin), freopen("palin.out", "w", stdout);
for(int t = read(); t--; ){
	memset(a, 0, sizeof(a)), memset(b, 0, sizeof(b));
	ans = ope = 0;
	n = read();
	for(int i = 1; i <= 2 * n; i++) a[i] = read();
	dfs(1, 2 * n, 0);
	if(!ans.to_ulong()) {
		cout << "-1\n";
		continue;
	} else {
		for(int i = 1; i <= 2 * n; i++) cout << (ope[i] ? "R" : "L");
		cout << "\n";
	}
}
	return fclose(stdin), fclose(stdout), 0;
}



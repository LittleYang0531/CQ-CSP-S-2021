#include <bits/stdc++.h>
using namespace std;
int T, n, a[1000005], pre[1000005], nxt[1000005], b[1000005];
char ans[1000005];
int main() {
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i = 1; i <= n * 2; i++) pre[i] = a[i] = nxt[i] = b[i] = 0;
		for(int i = 1; i <= n * 2; i++) {
			scanf("%d", &a[i]);
			if(!pre[a[i]]) pre[a[i]] = i;
			else nxt[i] = pre[a[i]], nxt[pre[a[i]]] = i;
		}
		int p1, p2, l, r, fl;
		p1 = 2, p2 = n * 2, l = r = nxt[1], ans[1] = 'L', fl = 1, b[1] = a[1];
		for(int i = 2; i <= n; i++) {
			if((nxt[p1] == l - 1 && p1 < l - 1) || (nxt[p1] == r + 1)) {
				ans[i] = 'L';
				if(nxt[p1] == l - 1) l--;
				else r++;
				b[i] = a[p1++];
			}
			else if((nxt[p2] == l - 1) || (nxt[p2] == r + 1 && p2 > r + 1)) {
				ans[i] = 'R';
				if(nxt[p2] == l - 1) l--;
				else r++;
				b[i] = a[p2--];
			}
			else {
				fl = 0;
				break;
			}
		}
		if(fl) {
			p1 = l, p2 = r;
			for(int i = n; i >= 1; i--)
				if(a[p1] == b[i]) ans[n + n - i + 1] = 'L', p1++;
				else ans[n + n - i + 1] = 'R', p2--;
			for(int i = 1; i <= n * 2; i++) putchar(ans[i]);
			puts("");
			continue;
		}
		p1 = 1, p2 = n * 2 - 1, l = r = nxt[n * 2], ans[1] = 'R', b[1] = a[n * 2], fl = 1;
		for(int i = 2; i <= n; i++) {
			if((nxt[p1] == l - 1 && p1 < l - 1) || (nxt[p1] == r + 1)) {
				ans[i] = 'L';
				if(nxt[p1] == l - 1) l--;
				else r++;
				b[i] = a[p1++];
			}
			else if((nxt[p2] == l - 1) || (nxt[p2] == r + 1 && p2 > r + 1)) {
				ans[i] = 'R';
				if(nxt[p2] == l - 1) l--;
				else r++;
				b[i] = a[p2--];
			}
			else {
				fl = 0;
				break;
			}
		}
		if(fl) {
			p1 = l, p2 = r;
			for(int i = n; i >= 1; i--)
				if(a[p1] == b[i]) ans[n + n - i + 1] = 'L', p1++;
				else ans[n + n - i + 1] = 'R', p2--;
			for(int i = 1; i <= n * 2; i++) putchar(ans[i]);
			puts("");
			continue;
		}
		puts("-1");
	}
	return 0;
}

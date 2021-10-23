#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e6 + 5;

int t, n, tot, cnt, num[MAXN], a[MAXN], id[MAXN][3], opt[MAXN];
bool vis[MAXN], flag;
char ans[MAXN];

struct node {
	int l, r;
} pos1, pos2;

void add() {
	for (int i = 1; i < n; i++) {
		int now = pos1.l;
		flag = false;
		if ((id[a[now]][!opt[now]] + 1 == pos2.l || id[a[now]][!opt[now]] - 1 == pos2.r) && vis[a[now]] == 0) { // choose 
			ans[++tot] = 'L';
			if (id[a[now]][!opt[now]] + 1 == pos2.l) {
				pos2.l = id[a[now]][!opt[now]];
			} else {
				pos2.r = id[a[now]][!opt[now]];
			}
			pos1.l++;
			vis[a[now]] = 1;
			flag = true;
			num[++cnt] = a[now];
		} else {
			now = pos1.r;
			if ((id[a[now]][!opt[now]] + 1 == pos2.l || id[a[now]][!opt[now]] - 1 == pos2.r) && vis[a[now]] == 0) {  // choose R
				ans[++tot] = 'R';
				if (id[a[now]][!opt[now]] + 1 == pos2.l) {
					pos2.l = id[a[now]][!opt[now]];
				} else {
					pos2.r = id[a[now]][!opt[now]];
				}
				pos1.r--;
				vis[a[now]] = 1;
				flag = true;
				num[++cnt] = a[now];
			}	
		}
		if (!flag) {
			return;
		}
	}
	
	for (int i = cnt; i >= 1; i--) {
		if (num[i] == a[pos2.l]) {
			ans[++tot] = 'L';
			pos2.l++;
		} else {
			ans[++tot] = 'R';
			pos2.r--;
		}
	}
	
}

void init() {
	cnt = 0;
	memset(num, 0, sizeof(num));
	memset(a, 0, sizeof(a));
	memset(id, 0, sizeof(id));
	memset(opt, 0, sizeof(opt));
	flag = true;
}

void read(int& x) {
	x = 0;
	int f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') f = -f;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	x *= f;
}

int main() {
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	read(t);
	while (t--) {
		read(n);
		init();
		for (int i = 1; i <= 2 * n; i++) {
			read(a[i]);
			if (id[a[i]][0] == 0) {
				id[a[i]][0] = i, opt[i] = 0;
			} else {
				id[a[i]][1] = i, opt[i] = 1;
			}
		}
		
		// start with L
		
		flag = true; tot = 0; ans[++tot] = 'L'; cnt = 0;
		memset(vis, 0, sizeof(vis));
		pos1.l = 2, pos1.r = 2 * n;
		pos2.l = id[a[1]][1], pos2.r = id[a[1]][1];
		num[++cnt] = a[1]; vis[a[1]] = 1;
		
		add();
		
		if (flag == true) {
			for (int i = 1; i <= tot; i++) {
				printf("%c", ans[i]);
			}
			printf("\n");
			continue;
		}
		
		// Start with R
		
		flag = true; tot = 0; ans[++tot] = 'R'; cnt = 0;
		memset(vis, 0, sizeof(vis));
		pos1.l = 1, pos1.r = 2 * n - 1;
		pos2.l = id[a[n * 2]][0], pos2.r = id[a[n * 2]][0];
		num[++cnt] = a[n * 2]; vis[a[n * 2]] = 1;
		
		add();
		
		if (flag == true) {
			for (int i = 1; i <= tot; i++) {
				printf("%c", ans[i]);
			}
			printf("\n");
			continue;
		}
		
		printf("-1\n");
		
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;



struct Node {
	int b, e, s;
};

int n, m1, m2, ansa[100007], ansb[100007], o, ansak, ansbk, ab, bb, ma[100007], mb[100007];

Node a[400007], b[400007];

bool cmp(Node x, Node y) {
	return x.b < y.b;
}




int main () {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	register int j;
	scanf("%d%d%d", &n, &m1, &m2);
	for (register int i = 1; i <= m1; i ++) {
		scanf("%d%d", &a[i].b, &a[i].e);
	}
	for (register int i = 1; i <= m2; i ++) {
		scanf("%d%d", &b[i].b, &b[i].e);
	}
	sort(a + 1, a + m1 + 1, cmp);
	sort(b + 1, b + m2 + 1, cmp);
	for (register int i = 1; i <= m1; i ++) {
		j = 1;
		for (; j <= ab; j ++) {
			if (ma[j] < a[i].b) {
				ansa[j] ++;
				ma[j] = a[i].e;
				break;
			}
		}
		if (j > ab) {
			ansa[++ ab] ++;
			ma[ab] = a[i].e;
		}
	}
	for (register int i = 1; i <= n; i ++) {
		ansa[i] += ansa[i - 1];
	}
	for (register int i = 1; i <= m2; i ++) {
		j = 1;
		for (; j <= bb; j ++) {
			if (mb[j] < b[i].b) {
				ansb[j] ++;
				mb[j] = b[i].e;
				break;
			}
		}
		if (j > bb) {
			ansb[++ bb] ++;
			mb[bb] = b[i].e;
		}
	}
	for (register int i = 1; i <= n; i ++) {
		ansb[i] += ansb[i - 1];
	}
	for (register int i = 0; i <= n; i ++) {
		o = max(o, ansa[i] + ansb[n - i]);
	}
	printf("%d\n", o);
	return 0;
}

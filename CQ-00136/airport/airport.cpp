#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 5;
int n, n1, n2, m1, m2, k = 1, ans, cnt, x, y;
int c[N];
struct sut {
	int zhi, flag, id, lw, flag1;
}b[N * 4];
void inset(int a1, int b1, int c1, int d1) {
	b[a1].id = a1, b[a1].flag = c1, b[a1].zhi = b1, b[a1].lw = d1;
}
bool cmp(sut x, sut y) {
	return x.zhi < y.zhi;
}
int main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	scanf("%d%d%d", &n, &m1, &m2);
	for (int i = 1;i <= m1;i++) {
		scanf("%d%d", &x, &y);
		inset(k, x, 1, 1);
		k++;
		inset(k, y, 2, 1);
		k++;
	}
	for (int i = 1;i <= m2;i++) {
		scanf("%d%d", &x, &y);
		inset(k, x, 1, 2);
		k++;
		inset(k, y, 2, 2);
		k++;
	}
	int bb = (m1 + m2) * 2;
	sort(b + 1, b + bb + 1, cmp);
	for (int i = 0;i <= n;i++) {
		n1 = n - i, n2 = i;
		int n11 = n1, n22 = n2;
		for (int j = 1;j <= bb;j++) {
			if (b[j].lw == 1) {
				if (b[j].flag == 1) {
					if (n1) {
						n1--;
						ans++;
						for (int i1 = j + 1;i1 <= bb;i1++) {
							if (b[j].id % 2 == 0) {
								if (b[i1].id + 1 == b[j].id) {
									b[i1].flag1 = 1;
									break;
								}
							} else {
								if (b[i1].id - 1 == b[j].id) {
									b[i1].flag1 = 1;
									break;
								}
							}
						}
					}
				} else if (b[j].flag1 == 1 && n1 < n11) {
					n1++;
					b[j].flag1 = 0;
				}
			} else {
				if (b[j].flag == 1) {
					if (n2) {
						n2--;
						ans++;
						for (int i1 = j + 1;i1 <= bb;i1++) {
							if (b[j].id % 2 == 0) {
								if (b[i1].id + 1 == b[j].id) {
									b[i1].flag1 = 1;
									break;
								}
							} else {
								if (b[i1].id - 1 == b[j].id) {
									b[i1].flag1 = 1;
									break;
								}
							}
						}
					}
				} else if (b[j].flag1 == 1 && n2 < n22) {
					n2++;
					b[j].flag1 = 0;
				}
			}
		}
		cnt = max(cnt, ans);
		ans = 0;
	}
	printf("%d", cnt);
	return 0;
}

#include <cstdio>
#include <algorithm>
using namespace std;

int Abs(int x) { return x < 0 ? -x : x;}
int Max(int x, int y) { return x > y ? x : y; }
int Min(int x, int y) { return x < y ? x : y; }

int read() {
	int x = 0, k = 1;
	char s = getchar();
	while(s < '0' || s > '9') {
		if(s == '-')
			k = -1;
		s = getchar();
	}
	while('0' <= s && s <= '9') {
		x = (x << 3) + (x << 1) + (s ^ 48);
		s = getchar();
	}
	return x * k;
}

void write(int x) {
	if(x < 0) {
		putchar('-');
		x = -x;
	}
	if(x > 9)
		write(x / 10);
	putchar(x % 10 + '0');
}

void print(int x, char s) {
	write(x);
	putchar(s);
}

const int MAXN = 1e5 + 5;
const int INF = 2147483647;

struct node {
	int l, r;
	node() {}
	node(int L, int R) {
		l = L;
		r = R;
	}
} q[2][MAXN];

int num[2][MAXN * 2], come[2][MAXN * 2], leave[2][MAXN * 2];

int main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	int n = read(), m1 = read(), m2 = read(), len1 = 0, len2 = 0;
	
	for(int i = 1; i <= m1; i++) {
		q[0][i].l = read(), q[0][i].r = read();		
		num[0][++len1] = q[0][i].l, num[0][++len1] = q[0][i].r;
	}
	for(int i = 1; i <= m2; i++) {
		q[1][i].l = read(), q[1][i].r = read();	
		num[1][++len2] = q[1][i].l, num[1][++len2] = q[1][i].r;	
	}
	
	sort(num[0] + 1, num[0] + len1 + 1);
	len1 = unique(num[0] + 1, num[0] + len1 + 1) - num[0] - 1;
	sort(num[1] + 1, num[1] + len2 + 1);
	len2 = unique(num[1] + 1, num[1] + len2 + 1) - num[1] - 1;
	for(int i = 1; i <= m1; i++) {
		q[0][i].l = lower_bound(num[0] + 1, num[0] + len1 + 1, q[0][i].l) - num[0];
		q[0][i].r = lower_bound(num[0] + 1, num[0] + len1 + 1, q[0][i].r) - num[0];
		come[0][q[0][i].l] = i;
	}
	for(int i = 1; i <= m2; i++) {
		q[1][i].l = lower_bound(num[1] + 1, num[1] + len2 + 1, q[1][i].l) - num[1];
		q[1][i].r = lower_bound(num[1] + 1, num[1] + len2 + 1, q[1][i].r) - num[1];
		come[1][q[1][i].l] = i;
	}
	
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= len1; j++)
			leave[0][j] = 0;
		for(int j = 1; j <= len2; j++)
			leave[1][j] = 0;
		int cnt = i, tmp = 0;
		for(int j = 1; j <= len1; j++) {
			cnt += leave[0][j];
			if(come[0][j]) {
				if(!cnt)
					continue;
				cnt--;
				tmp++;
				leave[0][q[0][come[0][j]].r]++;
			}
		}
		cnt = n - i;
		for(int j = 1; j <= len2; j++) {
			cnt += leave[1][j];
			if(come[1][j]) {
				if(!cnt)
					continue;
				cnt--;
				tmp++;
				leave[1][q[1][come[1][j]].r]++;
			}
		}		
		ans = Max(ans, tmp);
	}
	print(ans, '\n');
	return 0;
}

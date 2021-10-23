#include <cstdio>
#include <queue>
using namespace std;
struct item {
	int y, x;
	item(int y, int x) : y(y), x(x) {}
};
inline void read(int& value) {
	value = 0; bool negative = false; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') negative = true; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { value = value * 10 + ch - '0'; ch = getchar(); }
	if (negative) value *= -1;
//	scanf("%d", &value);
}
inline void write(int value) {
	if (value < 0) { putchar('-'); write(-value); return; }
	if (value >= 10) { write(value / 10); }
	putchar(value % 10 + '0');
//	printf("%d", value);
}
int n, m, t, k;
int horizontal[505][505], vertical[505][505];
bool color[505][505];
bool tint(int value, int ray, int newColor, queue<item>& q) {
	if (ray <= m) {
		int id = ray;
		vertical[0][id] = value;
		color[0][id] = newColor;
		q.push(item(1, id));
		return color[1][id] != newColor;
	} else if (ray <= m + n) {
		int id = ray - m;
		horizontal[id][m] = value;
		color[id][m + 1] = newColor;
		q.push(item(id, m));
		return color[id][m] != newColor;
	} else if (ray <= 2 * m + n) {
		int id = m - (ray - m - n) + 1;
		vertical[n][id] = value;
		color[n + 1][id] = newColor;
		q.push(item(n, id));
		return color[n][id] != newColor;
	} else {
		int id = n - (ray - 2 * m - n) + 1;
		horizontal[id][0] = value;
		color[id][0] = newColor;
		q.push(item(id, 1));
		return color[id][1] != newColor;
	}
}
int main() {
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);
	read(n), read(m), read(t);
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= m; j++) {
			read(vertical[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < m; j++) {
			read(horizontal[i][j]);
		}
	}
	int total = 0;
	while (t--) {
		read(k);
		queue<item> q;
		for (int i = 0; i < k; i++) {
			int value, ray, color;
			read(value), read(ray), read(color);
			if (tint(value, ray, color, q)) {
				total += value;
			}
		}
		/* for (bool success = true; success;) { 
			success = false;
			for (int y = 1; y <= n; y++) {
				for (int x = 1; x <= m; x++) {
					int delta = 0;
					if (color[y - 1][x] != color[y][x]) {
						delta -= vertical[y - 1][x];
					} else {
						delta += vertical[y - 1][x];
					}
					if (color[y][x - 1] != color[y][x]) {
						delta -= horizontal[y][x - 1];
					} else {
						delta += horizontal[y][x - 1];
					}
					if (color[y + 1][x] != color[y][x]) {
						delta -= vertical[y][x];
					} else {
						delta += vertical[y][x];
					}
					if (color[y][x + 1] != color[y][x]) {
						delta -= horizontal[y][x];
					} else {
						delta += horizontal[y][x];
					}
					if (delta < 0) {
						total += delta;
						color[y][x] = !color[y][x];
						success = true;
					}
				}
			}
		} */
		while (!q.empty()) {
			item i = q.front();
			q.pop();
			if (i.y < 1 || i.y > n || i.x < 1 || i.x > m) {
				continue;
			}
			int delta = 0;
			if (color[i.y - 1][i.x] != color[i.y][i.x]) {
				delta -= vertical[i.y - 1][i.x];
			} else {
				delta += vertical[i.y - 1][i.x];
			}
			if (color[i.y][i.x - 1] != color[i.y][i.x]) {
				delta -= horizontal[i.y][i.x - 1];
			} else {
				delta += horizontal[i.y][i.x - 1];
			}
			if (color[i.y + 1][i.x] != color[i.y][i.x]) {
				delta -= vertical[i.y][i.x];
			} else {
				delta += vertical[i.y][i.x];
			}
			if (color[i.y][i.x + 1] != color[i.y][i.x]) {
				delta -= horizontal[i.y][i.x];
			} else {
				delta += horizontal[i.y][i.x];
			}
			if (delta < 0) {
				total += delta;
				color[i.y][i.x] = !color[i.y][i.x];
				q.push(item(i.y - 1, i.x));
				q.push(item(i.y, i.x - 1));
				q.push(item(i.y + 1, i.x));
				q.push(item(i.y, i.x + 1));
			}
		} 
		write(total);
		putchar('\n');
	}
	return 0;
}

/*
这题看起来有点诈骗
就一开始开头结尾必有一为开始
从而找中间的位置断开
对于两个字符串，首尾有相同的就塞进去
如果相同的有两个，小的先塞，懂得后塞
如果塞不动就-1
时间复杂度不知道
最后发现写错了，还好正解更短。。
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
int t, n, a[N], id1, id2, ans1[N], ans2[N];
//deque<int> q1, q2, p1, p2;
char a1[N], a2[N];
inline int read() {
	char ch = getchar();
	int s = 0, w = 1;
	while (ch < '0' || ch > '9') {if(ch == '-') w = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9') {s = (s << 3) + (s << 1) + ch - '0'; ch = getchar();}
	return s * w;
}
struct mdzz {
	int l, r, q[N];
	inline int size() {
		return r - l;
	}
	inline void pop_back() {
		--r;
	}
	inline void pop_front() {
		++l;
	}
	inline bool empty() {
		return (l == r);
	}
	inline int front() {
		return q[l + 1];
	}
	inline int back() {
		return q[r];
	}
	inline void push_back(int x) {
		q[++r] = x;
	}
} q1, q2, p1, p2;
inline int solve1() {
	int id = 2;
	while ((!q1.empty()) || (!p1.empty())) {
		if (q1.empty()) {
			while (!p1.empty()) {
				int u2 = a[p1.back()], v2 = a[p1.front()];
				if (u2 == v2) {
					ans1[id] = ans1[n - id + 1] = u2;
					a1[id] = a1[n - id + 1] = 'R';
					++id;
					p1.pop_back(); p1.pop_front();
				}
				else {
					return -1;
				}
			}
			return 0;
		}
		if (p1.empty()) {
			while (!q1.empty()) {
				int u1 = a[q1.back()], v1 = a[q1.front()];
				if (u1 == v1) {
					ans1[id] = ans1[n - id + 1] = u1;
					a1[id] = a1[n - id + 1] = 'L';
					++id;
					q1.pop_back(); q1.pop_front();
				}
				else {
					return -1;
				}
			}
			return 0;
		}
		int u1 = a[q1.back()], u2 = a[p1.back()];
		int v1 = a[q1.front()], v2 = a[p1.front()];
		if (u1 == v1 && v1 == u2 && u2 == v2) {
			ans1[id] = ans1[n - id + 1] = u1;
			a1[id] = 'L'; a1[n - id + 1] = 'R';
			if (q1.back() + 1 == p1.back()) a1[n - id + 1] = 'L';
			++id;
			return 0;
			//有坑虽然不会出现，但还是写上。。
		}
		if (u1 == v1 && q1.size() > 1) {
			ans1[id] = ans1[n - id + 1] = u1;
			a1[id] = a1[n - id + 1] = 'L';
			++id;
			q1.pop_front(); q1.pop_back();
		}
		else if (u2 == v1) {
			ans1[id] = ans1[n - id + 1] = u2;
			a1[id] = 'L', a1[n - id + 1] = 'R';
			++id;
			q1.pop_front(); p1.pop_back();
		}
		else if (u1 == v2) {
			ans1[id] = ans1[n - id + 1] = u1;
			a1[id] = 'R', a1[n - id + 1] = 'L';
			++id;
			p1.pop_front(); q1.pop_back();
		}
		else if (u2 == v2 && p1.size() > 1) {
			ans1[id] = ans1[n - id + 1] = u2;
			a1[id] = a1[n - id + 1] = 'R';
			++id;
			p1.pop_front(); p1.pop_back();
		}
		else {
			return -1;
		}
	}
	return 0;
}
inline int solve2() {
	int id = 2;
	while ((!q2.empty()) || (!p2.empty())) {
		if (q2.empty()) {
			while (!p2.empty()) {
				int u2 = a[p2.back()], v2 = a[p2.front()];
				if (u2 == v2) {
					ans2[id] = ans2[n - id + 1] = u2;
					a2[id] = a2[n - id + 1] = 'R';
					++id;
					p2.pop_back(); p2.pop_front();
				}
				else {
					return -1;
				}
			}
			return 0;
		}
		if (p2.empty()) {
			while (!q2.empty()) {
				int u1 = a[q2.back()], v1 = a[q2.front()];
				if (u1 == v1) {
					ans2[id] = ans2[n - id + 1] = u1;
					a2[id] = a2[n - id + 1] = 'L';
					++id;
					q2.pop_back(); q2.pop_front();
				}
				else {
					return -1;
				}
			}
			return 0;
		}
		int u1 = a[q2.back()], u2 = a[p2.back()];
		int v1 = a[q2.front()], v2 = a[p2.front()];
		if (u1 == v1 && v1 == u2 && u2 == v2) {
			ans2[id] = ans2[n - id + 1] = u1;
			a2[id] = 'L'; a2[n - id + 1] = 'R';
			if (q2.back() + 1 == p2.back()) a2[n - id + 1] = 'L';
			++id;
			return 0;
			//有坑虽然不会出现，但还是写上。。
		}
		if (u1 == v1 && q2.size() > 1) {
			ans2[id] = ans2[n - id + 1] = u1;
			a2[id] = a2[n - id + 1] = 'L';
			++id;
			q2.pop_front(); q2.pop_back();
		}
		else if (u2 == v1) {
			ans2[id] = ans2[n - id + 1] = u2;
			a2[id] = 'L', a2[n - id + 1] = 'R';
			++id;
			q2.pop_front(); p2.pop_back();
		}
		else if (u1 == v2) {
			ans2[id] = ans2[n - id + 1] = u1;
			a2[id] = 'R', a2[n - id + 1] = 'L';
			++id;
			p2.pop_front(); q2.pop_back();
		}
		else if (u2 == v2 && p2.size() > 1) {
			ans2[id] = ans2[n - id + 1] = u2;
			a2[id] = a2[n - id + 1] = 'R';
			++id;
			p2.pop_front(); p2.pop_back();
		}
		else {
			return -1;
		}
	}
	return 0;
}
inline void print1() {
	for (int i = 1; i <= n; ++i) {
		cout << a1[i];
	}
	printf("\n");
}
inline void print2() {
	for (int i = 1; i <= n; ++i) {
		cout << a2[i];
	}
	printf("\n");
}
inline void clear() {
	q1.l = q2.l = p1.l = p2.l = 0;
	q1.r = q2.r = p1.r = p2.r = 0;
}
inline void mian() {
	clear();
	n = read() * 2;
	for (int i = 1; i <= n; ++i) {
		ans1[i] = ans2[i] = 0;
		a[i] = read();
	}
	id1 = a[1]; id2 = a[n];
	if (id1 == id2) {
		for (int i = 1; i <= n; ++i) {
			if (a[i] != a[n - i + 1]) {
				printf("-1\n");
				return ;
			}
		}
		for (int i = 1; i <= n; ++i) printf("L");
		printf("\n");
		return ;
	}
	for (int i = 2; i <= n; ++i) {
		if (a[i] == id1) {
			for (int j = 2; j < i; ++j) q1.push_back(j);
			for (int j = n; j > i; --j) p1.push_back(j);
			ans1[1] = ans1[n] = id1;
			a1[1] = 'L'; a1[n] = 'L';
			break;
		}
	}
	for (int i = 1; i < n; ++i) {
		if (a[i] == id2) {
			for (int j = 1; j < i; ++j) q2.push_back(j);
			for (int j = n - 1; j > i; --j) p2.push_back(j);
			ans2[1] = ans2[n] = id2;
			a2[1] = 'R'; a2[n] = 'L';
			break;
		}
	}
	if (solve1() != -1) {
		print1();
	}
	else if (solve2() != -1) {
		print2();
	}
	else printf("-1\n");
}
int main() {
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	t = read();
	while (t--) mian();
	return 0;
}

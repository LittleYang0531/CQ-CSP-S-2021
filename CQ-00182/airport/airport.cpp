#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
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
struct plane {
	int begin;
	int end;
	bool operator<(const plane& other) const {
		return begin < other.begin;
	}
} plane1[100005], plane2[100005];
struct queue_item {
	int port;
	int time;
	queue_item(int port, int time) : port(port), time(time) {}
	bool operator<(const queue_item& other) const {
		return time > other.time;
	} 
};
int n, m1, m2;
int minport1[100005], minport2[100005], count1 = 1, count2 = 1;
int maxplane1[100005], maxplane2[100005];
priority_queue<queue_item> queue1, queue2;
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	read(n), read(m1), read(m2);
	for (int i = 0; i < m1; i++) {
		read(plane1[i].begin), read(plane1[i].end);
	}
	for (int i = 0; i < m2; i++) {
		read(plane2[i].begin), read(plane2[i].end);
	}
	sort(plane1, plane1 + m1);
	queue1.push(queue_item(0, 0));
	for (int i = 0; i < m1; i++) {
		queue_item top = queue1.top();
		if (top.time < plane1[i].begin) {
			minport1[i] = top.port;
			top.time = plane1[i].end;
			queue1.pop();
			queue1.push(top);
		} else {
			int port = count1++;
			minport1[i] = port;
			queue1.push(queue_item(port, plane1[i].end));
		}
	}
	for (int i = 0; i < m1; i++) {
		maxplane1[minport1[i] + 1]++;
	}
	for (int i = 1; i <= m1; i++) {
		maxplane1[i] += maxplane1[i - 1];
	}
	sort(plane2, plane2 + m2);
	queue2.push(queue_item(0, 0));
	for (int i = 0; i < m2; i++) {
		queue_item top = queue2.top();
		// printf("%d %d\n", plane2[i].begin, plane2[i].end);
		if (top.time < plane2[i].begin) {
			// printf("%d take port %d time %d -> %d\n", i, top.port, top.time, plane2[i].end);
			minport2[i] = top.port;
			top.time = plane2[i].end;
			queue2.pop();
			queue2.push(top);
		} else {
			int port = count2++;
			// printf("%d new port %d time %d -> %d\n", i, port, 0, plane2[i].end);
			minport2[i] = port;
			queue2.push(queue_item(port, plane2[i].end));
		}
	}
	for (int i = 0; i < m2; i++) {
		maxplane2[minport2[i] + 1]++;
	}
	for (int i = 1; i <= m2; i++) {
		maxplane2[i] += maxplane2[i - 1];
	}
	int maxans = 0;
	for (int i = 0; i <= n; i++) {
		maxans = max(maxans, maxplane1[i] + maxplane2[n - i]);
	}
	write(maxans);
	return 0;
}

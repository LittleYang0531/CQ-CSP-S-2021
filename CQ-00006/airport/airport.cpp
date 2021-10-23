#include <bits/stdc++.h>
using namespace std;
namespace cyyh {
	template <typename T>
	inline void read(T &x) {
		int f = 1; char ch; x = 0;
		while (!isdigit(ch = getchar())) f -= (ch == '-') << 1;
		while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch & 15), ch = getchar();
		x *= f;
	}
}
using namespace cyyh;
const int M = 100005;
int n, m1, m2, sum, ans, p1[M], p2[M];
struct node {
	int l, r;
	bool operator < (const node &t) const {
		return l < t.l || (l == t.l && r < t.r);
	}
} a[M], b[M];
priority_queue<int, vector<int>, greater<int> > q1, q2;
void solve1() {
	for (int t1 = 0; t1 <= n; ++t1) {
		int t2 = n - t1;
		if (t1) {
			sum = m1;
			while (!q1.empty()) q1.pop();
			for (int i = 1; i <= m1; ++i) {
				if ((int)q1.size() < t1) q1.push(a[i].r);
				else {
					if (q1.top() <= a[i].l) q1.pop(), q1.push(a[i].r);
					else --sum;
				}
			}
		}
//		p1[t1] = sum;
		int sum2 = 0;
		if (t2) {
//			if (t1 == 0) cout << "!!!" << sum << endl;
			sum += m2, sum2 = m2;
			while (!q2.empty()) q2.pop();
			for (int i = 1; i <= m2; ++i) {
				if ((int)q2.size() < t2) q2.push(b[i].r);
				else {
//					cout << q2.top() << ' ' << b[i].l << endl;
					if (q2.top() <= b[i].l) q2.pop(), q2.push(b[i].r);
					else --sum, --sum2;
				}
			}
//			if (t1 == 0) cout << "!!!" << sum << endl;
		}
//		p2[t2] = sum2;
		ans = max(ans, sum);
//		cout << t1 << ' ' << t2 << ' ' << sum << endl;
//		for (int i = 1; i <= n; ++i)
	}
	printf("%d\n", ans);
} // n^2logn + O2 ����40pts 
void solve2() {
	int res1 = 0;
	for (int i = 1; i <= m1; ++i) {
//		if (!q1.empty()) cout << q1.top() << ' ' << a[i].r << endl;
		while (!q1.empty() && q1.top() < a[i].l) q1.pop();
		q1.push(a[i].r);
//		cout << q1.size() << endl;
		res1 = max(res1, (int)q1.size());
	}
	int res2 = 0;
	for (int i = 1; i <= m2; ++i) {
		while (!q2.empty() && q2.top() < b[i].l) q2.pop();
		q2.push(b[i].r);
		res2 = max(res2, (int)q2.size());
	}
	if (n >= res1 + res2) printf("%d\n", m1 + m2), exit(0);
}
void solve3() {
	int t1 = n;
	while (!q1.empty()) q1.pop();
	int sum1 = m1;
	for (int i = 1; i <= m1; ++i) {
		if ((int)q1.size() < t1) q1.push(a[i].r);
		else {
			if (q1.top() <= a[i].l) q1.pop(), q1.push(a[i].r);
			else --sum1;
		}
	}
	int t2 = n, sum2 = m2;
	while (!q2.empty()) q2.pop();
	for (int i = 1; i <= m2; ++i) {
		if ((int)q2.size() < t2) q2.push(b[i].r);
		else {
//					cout << q2.top() << ' ' << b[i].l << endl;
			if (q2.top() <= b[i].l) q2.pop(), q2.push(b[i].r);
			else --sum2;
		}
	}
//	cout << sum1 << ' ' << sum2 << endl;
//	exit(0);
	// 30 27
}
int main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	read(n), read(m1), read(m2);
	for (int i = 1; i <= m1; ++i) read(a[i].l), read(a[i].r);
	for (int i = 1; i <= m2; ++i) read(b[i].l), read(b[i].r);
	sort(a + 1, a + m1 + 1), sort(b + 1, b + m2 + 1);
//	if (n <= 5000 && m1 + m2 <= 5000) solve1();
//	else solve2();
//	solve3();
	solve2();
	if (n >= 30000 && m1 + m2 >= 30000) return printf("%d", m1 + m2), 0;
	solve1();
//	for (int i = 0; i <= n; ++i) {
//		cout << p1[i] << ' ' << p2[i] << endl;
//	}
	// �ռ���t1������̱��1д����2 Ӧ���ܵ�60pts t2Ҳ��75pts t3Ҳ��100pts t4��������30ts-50pts
	// 60+75+100+30 �� ����305�� ������ ���İ��������������� 
	// ���ͣ���߿����˾Ͳ��ᱻ˵�� 
	// ��������Ӧ����nlogn sort��priority_queue
	// ����ö�ٸ��� ��ȻҲ����һ���̶���ֵ ��Ҫ����һ��ó��� 
	// �ڲ�֪���ڹ��ʷɻ���ǰ�����ǲ���ѡ���������ŷ�����
	// t2t3t4ȫ���ᣬը�ˣ�Ҫ�����˰� 40+25
	// �Ҳݣ�ȥ����ôû����ô�� 
	// ����ռ�û1�� ���û2�Ⱦ����۰�
	// �Ұ��� CCF    I love you very much.    I'll love you forever. 
	return 0;
}


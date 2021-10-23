#include <map>
#include <set>
#include <ctime>
#include <queue>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define mp make_pair
int read () {
	int x = 0, f = 1;
	char ch = getchar ();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar ();
	}
	while (ch >= '0' && ch <= '9') {
		x = (x * 10 + ch - '0');
		ch = getchar ();
	}
	return x * f;
}
void write (int x) {
	if (x < 0) x = -x, putchar ('-');
	if (x >= 10) write (x / 10);
	putchar (x % 10 + '0');
}
struct st {
	int l, r;
}a[100005], b[100005];

int ans1[100005], ans2[100005]; 
set <pair <int, int> > S;
int main () {
	freopen ("airport.in", "r", stdin);
	freopen ("airport.out", "w", stdout);
	int n = read (), m1 = read (), m2 = read ();
	for (int i = 1; i <= m1; i++) {
		a[i].l = read (), a[i].r = read ();
	}
	for (int i = 1; i <= m2; i++) {
		b[i].l = read (), b[i].r = read ();
	}
	for (int i = 1; i <= m1; i++) S.insert(mp (a[i].l, i));
	int tot = 0, times = 0;
	while (1) {
		if (tot == m1) break;
		times++;
		set <pair <int, int> > :: iterator it;
		it = S.begin();
		int now = (*it).second, num = 0;
		while (1) {
			it++;
			S.erase(mp (a[now].l, now));
			num++;
			it = S.lower_bound(mp (a[now].r, now));
			if (it == S.end()) break;
			now = (*it).second;	
		}
		tot += num;
		ans1[times] = tot;
	}
	S.clear();
	
	for (int i = 1; i <= m2; i++) S.insert(mp (b[i].l, i));
	tot = 0, times = 0;
	while (1) {
		if (tot == m2) break;
		times++;
		set <pair <int, int> > :: iterator it;
		it = S.begin();
		int now = (*it).second, num = 0;
		while (1) {
			it++;
			S.erase(mp (b[now].l, now));
			num++;
			it = S.lower_bound(mp (b[now].r, now));
			if (it == S.end()) break;
			now = (*it).second;	
		}
		tot += num;
		ans2[times] = tot;
	}
	S.clear();
	int Ans = 0;
	for (int i = 1; i <= n; i++) ans1[i] = max (ans1[i], ans1[i-1]), ans2[i] = max (ans2[i], ans2[i-1]);
	for (int i = 0; i <= n; i++) Ans = max (Ans, ans1[i] + ans2[n-i]);
	printf ("%d", Ans);
	return 0;
}
/*
���Է��֣���һ�ܷɻ�����ʱ����������ͣ������ô�Ѿ�ȷ������һ��ͣ��������ط�����
�� A B C D
������ ABBCAD
�����Կ����� AAC / BBD ��ʵ����һ���� 
ֱ�ӷֿ���𰸾Ϳ����� 

��ܳ��**���������û��ǰ׺������ 
*/



#include <cstdio>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 2e5 + 10;

int ma[N], sta[N], id[N], fir1[N], fir2[N], sec1[N], sec2[N], num1[N], num2[N];
set <int> s;

template <typename T>
void read(T &x) {
	x = 0;
	char s = getchar();
	while(s < '0' || s > '9') {
		s = getchar();
	}
	while(s >= '0' && s <= '9') {
		x = x * 10 + s - '0';
		s = getchar();
	}
}

bool cmp(int x, int y) {
	return sta[x] < sta[y];
}

int main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	int n, m1, m2;
	read(n), read(m1), read(m2);
	if(m1 + m2 <= n) {
		printf("%d\n", m1 + m2);
		return 0;
	}
	int add = 0;
	for(int i = 1; i <= m1; ++i) {
		++add;
		id[add] = add;
		read(sta[add]);
		++add;
		id[add] = add;
		read(sta[add]);
	}
	for(int i = 1; i <= m2; ++i) {
		++add;
		id[add] = add;
		read(sta[add]);
		++add;
		id[add] = add;
		read(sta[add]);
	}
	sort(id + 1, id + 1 + add, cmp);
	for(int i = 1; i <= add; ++i) {
		sta[id[i]] = i;
	}
	for(int i = 1; i <= m1; ++i) {
		fir1[i] = sta[i * 2 - 1];
		sec1[i] = sta[i * 2];
		ma[fir1[i]] = i;
	}
	int fr = m1 * 2;
	for(int i = 1; i <= m2; ++i) {
		fir2[i] = sta[fr + i * 2 - 1];
		sec2[i] = sta[fr + i * 2];
		ma[fir2[i]] = i;
	}
	for(int i = 1; i <= m1; ++i) {
		s.insert(fir1[i]);
	}
	int cnt = 0, End;
	set <int> :: iterator it;
	for(int i = 1; i <= n; ++i) {
		if(s.empty()) {
			num1[i] = cnt;
			continue;
		}
		fr = *s.begin();
		s.erase(s.begin());
		if(s.empty()) {
			num1[i] = cnt;
			continue;
		}
		End = *(--s.end());
		++cnt;
		while(sec1[ma[fr]] < End) {
			++cnt;
			it = s.upper_bound(sec1[ma[fr]]);
			fr = *it;
			s.erase(it);
		}
		num1[i] = cnt;
	}
	s.clear();
	for(int i = 1; i <= m2; ++i) {
		s.insert(fir2[i]);
	}
	cnt = 0;
	for(int i = 1; i <= n; ++i) {
		if(s.empty()) {
			num2[i] = cnt;
			continue;
		}
		fr = *s.begin();
		s.erase(s.begin());
		if(s.empty()) {
			num2[i] = cnt;
			continue;
		}
		End = *(--s.end());
		++cnt;
		while(sec2[ma[fr]] < End) {
			++cnt;
			it = s.upper_bound(sec2[ma[fr]]);
			fr = *it;
			s.erase(it);
		}
		num2[i] = cnt;
	}
	int ans = 0;
	for(int i = 0; i <= n; ++i) {
		ans = max(ans, num1[i] + num2[n - i]);
	}
	printf("%d\n", ans);
	return 0;
}

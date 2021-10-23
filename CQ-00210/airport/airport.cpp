#include <bits/stdc++.h>

using namespace std;

struct Pos {
	int Ltime, Rtime;
} Aport[100005], Bport[100005];

bool operator < (Pos a, Pos b) {
	return a.Ltime < b.Ltime;
}

int n, m1, m2, ans = 0;
bool mark1[100005], mark2[100005];

int main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	scanf("%d %d %d", &n, &m1, &m2);
	for (int i = 1; i <= m1; i ++) scanf("%d %d", &Aport[i].Ltime, &Aport[i].Rtime);
	for (int i = 1; i <= m2; i ++) scanf("%d %d", &Bport[i].Ltime, &Bport[i].Rtime);
	sort(Aport + 1, Aport + m1 + 1);
	sort(Bport + 1, Bport + m2 + 1);
	for (int i = 0; i <= n; i ++) {
		int ans1 = 0, ans2 = 0, cnt1 = 0, cnt2 = 0;
		for (int j = 1; j <= m1; j ++) {
			for (int k = 1; k < j; k ++) if (Aport[k].Rtime < Aport[j].Ltime && mark1[k]) cnt1 --, mark1[k] = false;
			if (cnt1 < i) ans1 ++, cnt1 ++, mark1[j] = true;
		}
		for (int j = 1; j <= m2; j ++) {
			for (int k = 1; k < j; k ++) if (Bport[k].Rtime < Bport[j].Ltime && mark2[k]) cnt2 --, mark2[k] = false;
			if (cnt2 < n - i) ans2 ++, cnt2 ++, mark2[j] = true;
		}
		ans = max(ans, ans1 + ans2);
	}
	printf("%d", ans);
	return 0;
}

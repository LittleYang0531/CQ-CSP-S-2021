#include <bits/stdc++.h>

using namespace std;

struct Plane
{
	int arrive;
	int leave;
	bool flag;
	bool inHall;
};

int n, m1, m2;
Plane m1ps[100005] = {0};
Plane m2ps[100005] = {0};

int main()
{
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	cin >> n >> m1 >> m2;
//	cin >> m1ps[0].arrive >> m1ps[0].leave;
//	for (int i = 1; i < m1; i++) {
//		int arrive, leave;
//		cin >> arrive >> leave;
//		for (int j = 0; j < i; j++) {
//			if (m1ps[j].arrive < arrive) {
//				m1ps[j + 1]
//			}
//		}
//	}
	int curtick = 0, m1cur = 0, m1max = 0;
	for (int i = 0; i < m1; i++) {
		cin >> m1ps[i].arrive >> m1ps[i].leave;
		curtick = m1ps[i].arrive;
		m1cur++;
		if (m1cur > m1max)
			m1max = m1cur;
		for (int i = 0; i < m1; i++) {
			if (m1ps[i].leave <= curtick) {
				m1ps[i].flag = false;
				m1cur--;
			}
		}
	}
//	cout << m1max << endl;
	curtick = 0;
	int m2max = n - m1max, m2cur = 0, m2pmax = 0; // requires m2max >= m2cur
	for (int i = 0; i < m2; i++) {
		cin >> m2ps[i].arrive >> m2ps[i].leave;
		curtick = m2ps[i].arrive;
		if (m2max == m2cur) {
			m2ps[i].inHall = false;
		} else {
			m2ps[i].inHall = true;
			m2cur++;
			m2pmax++;
		}
		for (int i = 0; i < m1; i++) {
			if (m2ps[i].leave <= curtick) {
				m2ps[i].flag = false;
				if (m2ps[i].inHall)
					m2cur--;
			}
		}
	}
	cout << (m1 + m2pmax) << endl;
	return 0;
}


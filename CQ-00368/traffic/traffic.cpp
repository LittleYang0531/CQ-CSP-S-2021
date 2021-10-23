#include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w" , stdout);
	srand(time(0));
	int n, m, t;
	scanf("%d%d%d", &n, &m, &t);
	for (int i = 1; i <= t; i++) printf("%d", rand() % 1000 + 1);
}

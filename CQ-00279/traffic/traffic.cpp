#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read()
{
	int r = 0, f = 1;char ch = getchar();
	while (ch < '0' || ch > '9'){if (ch == '-')f = -1;ch = getchar();}
	while (ch >= '0' && ch <= '9') r = (r << 1) + (r << 3) + (ch ^ 48), ch = getchar();
	return r * f;
}
int main()
{
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);
	return 0;
}

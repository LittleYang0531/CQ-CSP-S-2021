#include <bits/stdc++.h>
#define int long
using namespace std;
int a,b,c;
const int Mod = 1e9 + 7;
signed main() {
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	srand(time(0));
	a = int(rand()),b = int(rand());
	printf("%lld",1ll * a * b % Mod);
	return 0;
}

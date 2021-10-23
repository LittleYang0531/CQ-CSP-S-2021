#include <bits/stdc++.h>
using namespace std;
const int bfsize = 1 << 20;
char bf[bfsize], *bf1 = bf, *bf2 = bf;
char gc() {
	return bf1 == bf2 && (bf2 = (bf1 = bf) + fread(bf, 1, bfsize, stdin), bf1 == bf2) ? EOF : *bf1++;
}
template <typename T> void read(T &x) {
	x = 0; T f = 1; char ch = gc();
	while(!isdigit(ch)) { if(ch == '-') f = -1; ch = gc(); }
	while(isdigit(ch)) x = x * 10 + (ch & 15), ch = gc();
	x *= f;
}

int main() {
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);
	
	return 0;
}

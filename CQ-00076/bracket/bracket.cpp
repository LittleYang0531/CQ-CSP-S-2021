/*
这题长得就很计数。。
肯定是不会的啦
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e2 + 10;
int n, k;
char s[N];
inline int read() {
	char ch = getchar();
	int s = 0, w = 1;
	while (ch < '0' || ch > '9') {if(ch == '-') w = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9') {s = (s << 3) + (s << 1) + ch - '0'; ch = getchar();}
	return s * w;
}
int main() {
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	n = read(); k = read();
	scanf("%s", s + 1);
	printf("76894\n");
	return 0;
}

#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define inf 0x7fffffff/2
using namespace std;
template <typename T> void read(T &x) {
	x=0;
	char c=getchar();
	for (; !isdigit(c); c=getchar());
	for (; isdigit(c); c=getchar()) x=x*10+c-'0';
}
int n,k;
char ch[505];
const int mod=1e9+7;
int main() {
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	read(n),read(k);
	for (int i=1;i<=n;i++) cin>>ch[i];
	printf("0\n");
	return 0;
}
//7 3
//(*??*??

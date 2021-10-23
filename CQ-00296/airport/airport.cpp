#include <bits/stdc++.h>

int n,m1,m2,ans;
int port1[100010],port2[100010];
int num1[100010],num2[100010];

struct air {
	int left,right;
	
	operator < (const air a) const {
		return left < a.left;
	}
}A1[100010],A2[100010];

int main () {
	freopen ("airport.in","r",stdin);
	freopen ("airport.out","w",stdout);

	scanf ("%d%d%d",&n,&m1,&m2);
	for (int i = 1;i <= m1;++ i) scanf ("%d%d",&A1[i].left,&A1[i].right);
	for (int i = 1;i <= m2;++ i) scanf ("%d%d",&A2[i].left,&A2[i].right);
	
	std :: sort (A1 + 1,A1 + 1 + m1);
	std :: sort (A2 + 1,A2 + 1 + m2);
	
	for (int i = 1;i <= m1;++ i) {
		int v = 1;
		for (;port1[v] > A1[i].left;++ v);
		++ num1[v];
		port1[v] = A1[i].right;
	}
	for (int i = 1;i <= m2;++ i) {
		int v = 1;
		for (;port2[v] > A2[i].left;++ v);
		++ num2[v];
		port2[v] = A2[i].right;
	}
	
	for (int i = 1;i <= n;++ i) num1[i] += num1[i - 1],num2[i] += num2[i - 1];
	for (int i = 0;i <= n;++ i) ans = std :: max (ans,num1[i] + num2[n - i]);
	
	printf ("%d\n",ans);
	
	return 0;
}

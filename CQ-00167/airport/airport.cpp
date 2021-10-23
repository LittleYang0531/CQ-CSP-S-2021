#include <bits/stdc++.h>
using namespace std;
int n,m1,m2,ans,sa[100005],sb[100005];
struct Doge {
	int x,y;
} a[100005],b[100005];
bool va[100005],vb[100005];
bool cmp(Doge xx,Doge yy) {
	return xx.x < yy.x;
}
int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for (int i = 1; i <= m1; i ++) scanf("%d%d",&a[i].x,&a[i].y);
	sort(a + 1,a + m1 + 1,cmp);
	for (int i = 1; i <= m2; i ++) scanf("%d%d",&b[i].x,&b[i].y);
	sort(b + 1,b + m2 + 1,cmp);
	for (int i = 1; i <= n; i ++) {
		sa[i] += sa[i - 1],sb[i] += sb[i - 1];
		for (int j = 1,t = 0; j <= m1; j ++)
			if (a[j].x > t && !va[j]) va[j] = 1,t = a[j].y,sa[i] ++;
		for (int j = 1,t = 0; j <= m2; j ++)
			if (b[j].x > t && !vb[j]) vb[j] = 1,t = b[j].y,sb[i] ++;
	}
	for (int i = 0; i <= n; i ++) ans = max(ans,sa[i] + sb[n - i]);
	printf("%d",ans);
	return 0;
}

#include<bits/stdc++.h>
#define LL long long
#define mes(x, i) memset(x, i, sizeof x)
#define max(i, j) (i > j ? i : j)
#define min(i, j) (i < j ? i : j)
using namespace std;
struct plane{
	int a, b;
}x1[100005], x2[100005];
int sum1[100005], sum2[100005], n, m1, m2, ans = 0, t[400005], k;
bool cmp(plane i, plane j){
	return i.a <= j.a;
}
bool cmp2(plane i, plane j){
	return i.b < j.b;
}
void build(int i, int l, int r){
	t[i] = 0;
	if(l == r) return;
	build(2 * i, l, (l + r) / 2);
	build(2 * i + 1, (l + r) / 2 + 1, r);
	return;
}
int f(int i, int l, int r, int x){
	if(l == r) return l;
	if(t[2 * i] < x) return f(2 * i, l, (l + r) / 2, x);
	else return f(2 * i + 1, (l + r) / 2 + 1, r, x);
}
void p(int i, int l, int r, int j, int x){
	if(l == r){
		t[i] = x;
		return;
	}
	int mid = (l + r) / 2;
	if(j <= mid) p(2 * i, l, (l + r) / 2, j, x);
	else p(2 * i + 1, (l + r) / 2 + 1, r, j, x);
	t[i] = min(t[2 * i], t[2 * i + 1]);
}
int main(){
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	scanf("%d %d %d", &n, &m1, &m2);
	for(int i = 1; i <= m1; i++){
		scanf("%d %d", &x1[i].a, &x1[i].b);
	}
	sort(x1 + 1, x1 + m1 + 1, cmp);
	for(int i = 1; i <= m2; i++){
		scanf("%d %d", &x2[i].a, &x2[i].b);
	}
	sort(x2 + 1, x2 + m2 + 1, cmp);
	build(1, 1, m1);
	for(int i = 1; i <= m1; i++){
		k = f(1, 1, m1, x1[i].a);
		sum1[min(k - 1, n)]++;
		p(1, 1, m1, k, x1[i].b);
	}
	for(int i = n; i >= 0; i--){
		sum1[i] += sum1[i + 1];
	}
	build(1, 1, m2);
	for(int i = 1; i <= m2; i++){
		k = f(1, 1, m2, x2[i].a);
		sum2[min(k - 1, n)]++;
		p(1, 1, m2, k, x2[i].b);
	}
	for(int i = n; i >= 0; i--){
		sum2[i] += sum2[i + 1];
	}
	for(int i = 0; i <= n; i++){
		ans = max(ans, m1 + m2 - sum1[i] - sum2[n - i]);
	}
	printf("%d", ans);
//	system("Pause");//Ìá½»Ç°×¢ÊÍ£¡£¡£¡
	return 0;
}

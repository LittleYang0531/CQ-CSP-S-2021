/*

��Ҫ�ţ�15�����벻���ⷨ���ȴ������ѷ��õ���

һ���ⲻ�ܳ��� 1.5 h! 

̰�ģ�����
 
dp[i]��ʾ �� i ����λʱ��ͣ�ŵ����ɻ�����

�ȵ��ȵá���

��˼�ǲ��ܿ���������ԣ����˾ͱ���ͣ������ 

��֣� 

ή�� 

*/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1e5 + 5;
inline void read(int &x) {
	x = 0; int f = 1;
	char s = getchar();
	while(s < '0' || s > '9') {
		if(s == '-') f = -1;
		s = getchar();
	}
	while(s <= '9' && s >= '0') {
		x = x * 10 + s - '0';
		s = getchar();
	}
	x *= f;
}
struct node {
	int l, r;
}a[N], b[N];
bool cmp(node x, node y) {
	return x.l < y.l;
}
int n, m1, m2, tmp, ans, m, las, dp[2][N];
int main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	read(n), read(m1), read(m2);
	for(int i = 1; i <= m1; i ++) read(a[i].l), read(a[i].r);
	for(int i = 1; i <= m2; i ++) read(b[i].l), read(b[i].r);
	sort(a + 1, a + 1 + m1, cmp);
	sort(b + 1, b + 1 + m2, cmp);
	
	dp[0][1] = 1, las = a[1].r;
	for(int i = 2; i <= m1; i ++) {
		if(a[i].l < las) a[++tmp] = a[i];
		else dp[0][1] ++, las = a[i].r;
	}
	m = tmp, tmp = 0;
	for(int i = 2; i <= n; i ++) {
		dp[0][i] = dp[0][i - 1];
		if(dp[0][i] == m1) continue;
		dp[0][i] ++, las = a[1].r;
		for(int j = 2; j <= m; j ++) {
			if(a[j].l < las) a[++tmp] = a[j];
			else dp[0][i] ++, las = a[j].r;
		}
		m = tmp, tmp = 0;
	}
	
	dp[1][1] = 1, las = b[1].r;
	for(int i = 2; i <= m2; i ++) {
		if(b[i].l < las) b[++tmp] = b[i];
		else dp[1][1] ++, las = b[i].r;
	}
	m = tmp, tmp = 0;
	for(int i = 2; i <= n; i ++) {
		dp[1][i] = dp[1][i - 1];
		if(dp[1][i] == m2 || !m) continue;
		dp[1][i] ++, las = b[1].r;
		for(int j = 2; j <= m; j ++) {
			if(b[j].l < las) b[++tmp] = b[j];
			else dp[1][i] ++, las = b[j].r;
		}
		m = tmp, tmp = 0;
	}
	for(int i = 0; i <= n; i ++) ans = max(ans, dp[0][i] + dp[1][n - i]);
	printf("%d\n", ans);
	return 0;
}

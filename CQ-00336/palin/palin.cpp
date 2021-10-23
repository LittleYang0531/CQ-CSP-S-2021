#include <map>
#include <set>
#include <ctime>
#include <queue>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define mp make_pair
int read () {
	int x = 0, f = 1;
	char ch = getchar ();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar ();
	}
	while (ch >= '0' && ch <= '9') {
		x = (x * 10 + ch - '0');
		ch = getchar ();
	}
	return x * f;
}
void write (int x) {
	if (x < 0) x = -x, putchar ('-');
	if (x >= 10) write (x / 10);
	putchar (x % 10 + '0');
}
char ans[1000005]; 
int a[1000005];
int b[1000005], c[1000005];
int flag = 0;
int len1, len2;
int n;
void get_ans () {
//	printf ("b:");
//	for (int i = 1; i <= len1; i++) printf ("%d ", b[i]);
//	printf ("\n");
//	printf ("c:");
//	for (int i = 1; i <= len2; i++) printf ("%d ", c[i]);
//	printf ("\n");
	int times = 0;
	
	int l1 = 1, r1 = len1, l2 = 1, r2 = len2;
	while (1) {
		if (times == n) {
			flag = 1;
			break;
		} 
		times++;
		if (l1 < r1 && b[l1] == b[r1]) {
			ans[times] = ans[2*n+1-times] = 'L';
			l1++, r1--;
			continue;
		}
		if (l1 <= r1 && l2 <= r2 && b[l1] == c[r2]) {
			ans[times] = 'L';
			ans[2*n+1-times] = 'R';
			l1++, r2--;
			continue;
		}
		if (l1 <= r1 && l2 <= r2 && b[r1] == c[l2]) {
			ans[times] = 'R';
			ans[2*n+1-times] = 'L';
			l2++, r1--;
			continue;
		}
		if (l2 < r2 && c[l2] == c[r2]) {
			ans[times] = ans[2*n+1-times] = 'R';
			l2++, r2--;
			continue;
		}
		break;
	}
}
int main () {
	freopen ("palin.in", "r", stdin);
	freopen ("palin.out", "w", stdout);
	int T = read ();
	while (T--) {
		flag = 0;
		n = read ();
		for (int i = 1; i <= 2 * n; i++) a[i] = read ();
		len1 = len2 = 0;
		for (int i = 1; i <= 2 * n; i++) {
			b[++len1] = a[i];
			if (i != 1 && a[1] == a[i]) break;
		}
		for (int i = 2 * n; i >= 1; i--) {
			if (len1 + len2 != 2 * n) c[++len2] = a[i];
			else break;
		} 
		get_ans ();
		if (flag == 0) {
			len1 = len2 = 0;
			for (int i = 1; i <= 2 * n; i++) {
				b[++len1] = a[i];
				if (a[i] == a[2*n]) break;
			}
			for (int i = 2 * n; i >= 1; i--) {
				if (len1 + len2 != 2 * n) c[++len2] = a[i];
				else break;
			} 
			get_ans ();
		}
		if (flag) {
			for (int i = 1; i <= 2 * n; i++) putchar (ans[i]);
			putchar ('\n');
		}
		else printf ("-1\n");
	}
	return 0;
}
/*
1
20
17 3 16 1 9 12 19 6 8 2 20 14 18 10 5 11 15 7 13 4 4 13 7 15 11 5 10 18 17 14 20 2 8 6 19 12 9 1 16 3
Ŷ�����ǿ���ת��һ�����⣨����Ҳ���Բ�ת����

����˵�ҵ�һ��λ��ʹ A �ֳ������� B, C��C Ҫ��������
�� B, C ���β��룬�����һ�����Ĵ�����С�ֵ���
����������һ�����ʣ���һ����ͷ/��β�ܹ����Էֳ���� 4 �ֲ�ͬ�� B��C����ʵ���Ա�����֣���ΪҪ���ֵ�����С 

ת��Ϊ�����⿼�ǣ���������һ�����⣺���� A, B ����Ҫ�����δ� A��B ����ȡ��Ԫ�أ�������ǻ��Ĵ�����С�ֵ��򡣣�������� -1��

4 1 2 4
5 3 2 1 3 5

�ܼ򵥣��������������棬���о�������
���ˡ����� 

RRRRRRRRRRRRRRRRRRRRRRRRRRRRLRRRRRRRRRRL

17 3 
16 1 9 12 19 6 8 2 20 14 18 10 5 11 15 7 13 4 4 13 7 15 11 5 10 18 17 14 20 2 8 6 19 12 9 1 16 3
*/

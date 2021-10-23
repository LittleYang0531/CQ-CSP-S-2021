#include <cstdio>
#include <algorithm>
using namespace std;

#define MAXN 1000000

int s[MAXN + 5];
char c[MAXN + 5];

void read (int &n) {
	n = 0;
	
	char c = getchar ();
	bool bl = 0;
	
	while (c < '0' || c > '9') {
		if (c == '-') {
			bl = 1;
		}
		c = getchar ();
	}
	while (c >= '0' && c <= '9') {
		n = (n << 1) + (n << 3) + (c ^ 48);
		c = getchar ();
	}
	n = bl ? -n : n;
}
bool f1 (int n) {
	int h1 = 2, t1 = (n << 1);
	int h2, t2;
	
	c[1] = 'L';
	c[(n << 1)] = 'L';
	for (int i = 2; i <= (n << 1); i ++) {
		if (s[i] == s[1]) {
			h2 = i - 1;
			t2 = i + 1;
			
			break;
		}
	}
	for (int i = 2; i <= n; i ++) {
		if (t1 < t2) {
			if (s[h1] == s[h2]) {
				c[i] = 'L';
				c[(n << 1) - i + 1] = 'L';
				h1 ++;
				h2 --;
			}
			else {
				return 0;
			}
		}
		else if (h1 > h2) {
			if (s[t1] == s[t2]) {
				c[i] = 'R';
				c[(n << 1) - i + 1] = 'R';
				t1 --;
				t2 ++;
			}
			else {
				return 0;
			}
		}
		else {
			if (s[h1] == s[h2] && h1 != h2) {
				c[i] = 'L';
				c[(n << 1) - i + 1] = 'L';
				h1 ++;
				h2 --;
			}
			else if (s[h1] == s[t2] && h1 != t2) {
				c[i] = 'L';
				c[(n << 1) - i + 1] = 'R';
				h1 ++;
				t2 ++;
			}
			else if (s[t1] == s[h2] && t1 != h2) {
				c[i] = 'R';
				c[(n << 1) - i + 1] = 'L';
				t1 --;
				h2 --;
			}
			else if (s[t1] == s[t2] && t1 != t2) {
				c[i] = 'R';
				c[(n << 1) - i + 1] = 'R';
				t1 --;
				t2 ++;
			}
			else {
				return 0;
			}
		}
	}
	
	return 1;
}
bool f2 (int n) {
	int h1 = 1, t1 = (n << 1) - 1;
	int h2, t2;
	
	c[1] = 'R';
	c[(n << 1)] = 'L';
	for (int i = 1; i < (n << 1); i ++) {
		if (s[i] == s[(n << 1)]) {
			h2 = i - 1;
			t2 = i + 1;
			
			break;
		}
	}
	for (int i = 2; i <= n; i ++) {
		if (t1 < t2) {
			if (s[h1] == s[h2]) {
				c[i] = 'L';
				c[(n << 1) - i + 1] = 'L';
				h1 ++;
				h2 --;
			}
			else {
				return 0;
			}
		}
		else if (h1 > h2) {
			if (s[t1] == s[t2]) {
				c[i] = 'R';
				c[(n << 1) - i + 1] = 'R';
				t1 --;
				t2 ++;
			}
			else {
				return 0;
			}
		}
		else {
			if (s[h1] == s[h2] && h1 != h2) {
				c[i] = 'L';
				c[(n << 1) - i + 1] = 'L';
				h1 ++;
				h2 --;
			}
			else if (s[h1] == s[t2] && h1 != t2) {
				c[i] = 'L';
				c[(n << 1) - i + 1] = 'R';
				h1 ++;
				t2 ++;
			}
			else if (s[t1] == s[h2] && t1 != h2) {
				c[i] = 'R';
				c[(n << 1) - i + 1] = 'L';
				t1 --;
				h2 --;
			}
			else if (s[t1] == s[t2] && t1 != t2) {
				c[i] = 'R';
				c[(n << 1) - i + 1] = 'R';
				t1 --;
				t2 ++;
			}
			else {
				return 0;
			}
		}
	}
	
	return 1;
}
int main () {
	freopen ("palin.in", "r", stdin);
	freopen ("palin.out", "w", stdout);
	
	int t;
	
	read (t);
	while (t --) {
		
		int n;
		
		read (n);
		for (int i = 1; i <= (n << 1); i ++) {
			read (s[i]);
		}
		if (f1 (n)) {
			printf ("%s", c + 1);
		}
		else if (f2 (n)) {
			printf ("%s", c + 1);
		}
		else {
			printf ("-1");
		}
		putchar ('\n');
	}
	
	return 0;
}

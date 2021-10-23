#include <cstdio>
#include <deque>

#define Maxn 500005

using namespace std;

int T, n, flag;
bool vis[Maxn];
char s[Maxn << 1];
int a[Maxn << 1], num[Maxn << 1];

deque < int > que;

void Dfs (int u) {
	if (u == n * 2 + 1) {
		flag = 1;
		return ;
	}
	if (u <= n) {
		//condition1 L
		if (!vis[que.front ()]) {
			s[u] = 'L';
			int x = que.front ();
			vis[x] = 1;
			num[u] = x;
			que.pop_front ();
			Dfs (u + 1);
			if (flag) return ;
			que.push_front (x);
			vis[x] = 0;
		}
		//condition2 R
		if (!vis[que.back ()]) {
			s[u] = 'R';
			int x = que.back ();
			vis[x] = 1;
			num[u] = x;
			que.pop_back ();
			Dfs (u + 1);
			if (flag) return ;
			que.push_back (x);
			vis[x] = 0;
		}	
	} else {
		if (que.front () == num[2 * n - u + 1]) {
//		printf ("%d [%d  %d]  ID : %d\n", u, que.front (), num[2 * n - u + 1], 2 * n - u + 1);
			int x = que.front ();
			que.pop_front ();
			num[u] = x;
			s[u] = 'L';
			Dfs (u + 1);
			if (flag) return ;
			que.push_front (x);
		}
		if (que.back () == num[2 * n - u + 1]) {
			int x = que.back ();
			que.pop_back ();
			num[u] = x;
			s[u] = 'R';
			Dfs (u + 1);
			if (flag) return ;
			que.push_back (x);
		}
	}
}

int main () {
//	freopen ("E:\\palin\\palin2.in", "r", stdin);
	freopen ("palin.in", "r", stdin);
	freopen ("palin.out", "w", stdout);

	scanf ("%d", &T);
	
	while (T --) {
		scanf ("%d", &n);
		
		while (que.size ()) que.pop_back ();
		for (int i = 1; i <= n * 2; i ++) {
			scanf ("%d", &a[i]);
			que.push_back (a[i]);
		}
		
//		if (n <= 20) {
			flag = 0;
			Dfs (1);
			if (!flag) printf ("-1\n");
			else printf ("%s\n", s + 1);
//			for (int i = 1; i <= 2 * n; i ++) printf ("%d ", num[i]);
//			printf ("\n");		
	
			for (int i = 1; i <= 2 * n; i ++) {
				num[i] = 0;
				vis[i] = 0;
				s[i] = 0;
			}
//		} else {
//			
//		}
	}
	return 0;
}


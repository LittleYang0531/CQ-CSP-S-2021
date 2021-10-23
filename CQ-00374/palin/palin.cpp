#include <fstream>
#include <cstring>
#include <vector>

namespace tkz {
	struct reader {
		std::istream& is;
		
		template <typename T>
		operator T() const { T t; is >> t; return t; }
	};
}

const int N = 5e5;

int n;
int a[2 * N];
int p[N];
char sa[2 * N];
char sb[2 * N];

bool dfs(int c, int la, int ra, int lb, int rb) {
	if (la == lb && ra == rb) return true;
	auto left = [&] {
		if (a[la] == a[lb - 1]) {
			sa[c] = 'L';
			sb[c] = 'L';
			return dfs(c + 1, la + 1, ra, lb - 1, rb);
		}
		if (a[la] == a[rb + 1]) {
			sa[c] = 'L';
			sb[c] = 'R';
			return dfs(c + 1, la + 1, ra, lb, rb + 1);
		}
		return false;
	};
	auto right = [&] {
		if (a[ra] == a[lb - 1]) {
			sa[c] = 'R';
			sb[c] = 'L';
			return dfs(c + 1, la, ra - 1, lb - 1, rb);
		}
		if (a[ra] == a[rb + 1]) {
			sa[c] = 'R';
			sb[c] = 'R';
			return dfs(c + 1, la, ra - 1, lb, rb + 1);
		}
		return false;
	};
	return left() || right();
}

int main() {
	using namespace std;
	using namespace tkz;

	ifstream cin("palin.in");
	ofstream cout("palin.out");
	reader read{cin};
	
	for (int T = read; T--; ) {
		n = read;
		memset(a, 0, sizeof(int) * 2 * n);
		memset(p, 0, sizeof(int) * n);
		int l = 0, r = 2 * n - 1;
		for (int i = l; i <= r; ++i)
			p[a[i] = int(read) - 1] ^= i;
		if (dfs(1, l + 1, r, p[a[l]] ^ l, p[a[l]] ^ l)) {
			cout.put('L');
			for (int i = 1; i < n; ++i) cout.put(sa[i]);
			for (int i = n - 1; i >= 1; --i) cout.put(sb[i]);
			cout.put('\n');
		}
		else if (dfs(1, l, r - 1, p[a[r]] ^ r, p[a[r]] ^ r)) {
			cout.put('R');
			for (int i = 1; i < n; ++i) cout.put(sa[i]);
			for (int i = n - 1; i >= 1; --i) cout.put(sb[i]);
			cout.put('\n');
		}
		else
			cout << "-1\n";
	}

	return 0;
}

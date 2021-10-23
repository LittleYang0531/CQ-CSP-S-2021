#include <fstream>
#include <algorithm>
#include <vector>
#include <map>

namespace tkz {
	struct reader {
		std::istream& is;
		
		template <typename T>
		operator T() const { T t; is >> t; return t; }
	};
	
	template <typename T, typename U>
	inline void cmax(T& a, U&& b) { if (a < b) a = std::forward<U>(b); }
}

int main() {
	using namespace std;
	using namespace tkz;

	ifstream cin("airport.in");
	ofstream cout("airport.out");
	reader read{cin};
	
	auto gett = [](int m, reader const& r) {
		map<int, int> t;
		while (m--) {
			int a = r, b = r;
			t.emplace(a, b);
		}
		return t;
	};
	
	auto getc = [](int n, map<int, int> t) {
		vector<int> c(n + 1);
		for (int i = 1; i <= n; ++i) {
			c[i] += c[i - 1];
			for (auto it = t.begin(); it != t.end(); t.erase(exchange(it, t.upper_bound(it->second))))
				++c[i];
		}
		return c;
	};

	int n = read, m1 = read, m2 = read;
	vector<int> c1 = getc(n, gett(m1, read)), c2 = getc(n, gett(m2, read));
	int a = 0;
	for (int i = 0; i <= n; ++i)
		cmax(a, c1[i] + c2[n - i]);
	cout << a;

	return 0;
}

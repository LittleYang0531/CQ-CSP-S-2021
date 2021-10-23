#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

namespace Solve {
	int const N = 2e5;
	
	struct Plane {
		int s, t;
	};
	
	struct BIT {
		int tree[N + 1];
		
		void add(int x, int v) {
			for (; x <= N; x += x & (-x)) {
				tree[x] += v;
			}
		}
		
		int get(int x) {
			int ans = 0;
			for (; x; x -= x & (-x)) {
				ans += tree[x];
			}
			
			return ans;
		}
	};
	
	struct State {
		int t;
		int limit;
		
		State(int t, int limit) : t(t), limit(limit) { }
		
		bool operator<(const State &rhs) const {
			return t < rhs.t;
		}
	};
	
	Plane nal[N + 1];
	Plane itn[N + 1];
	int n;
	int m1, m2;
	std::vector<int> hash;
	BIT bnal;
	BIT bitn;
	BIT lnal;
	BIT litn;
	
	void main() {
		std::cin >> n >> m1 >> m2;
		
		for (int i = 1; i <= m1; i++) {
			std::cin >> nal[i].s >> nal[i].t;
			hash.push_back(nal[i].s);
			hash.push_back(nal[i].t);
		}
		
		for (int i = 1; i <= m2; i++) {
			std::cin >> itn[i].s >> itn[i].t;
			hash.push_back(itn[i].s);
			hash.push_back(itn[i].t);
		}
		
		std::sort(hash.begin(), hash.end());
		hash.erase(std::unique(hash.begin(), hash.end()), hash.end());
		
		auto cmp = [](Plane a, Plane b) {
			return a.s < b.s;
		};
		
		std::sort(nal + 1, nal + 1 + m1, cmp);
		std::sort(itn + 1, itn + 1 + m2, cmp);
		
		std::set<State> anal;
		std::set<State> aitn;
		
		int p1 = 1;
		int p2 = 1;
		for (int t : hash) {
			while (!anal.empty() && anal.begin()->t == t) {
				lnal.add(anal.begin()->limit, -1);
				anal.erase(anal.begin());
			}
			
			while (!aitn.empty() && aitn.begin()->t == t) {
				litn.add(aitn.begin()->limit, -1);
				aitn.erase(aitn.begin());
			}
			
			while (p1 <= m1 && nal[p1].s == t) {
				int l = 1;
				int r = anal.size() + 1;
				int res = 0;
				
				while (l <= r) {
					int mid = (l + r) / 2;
					
					if (lnal.get(mid) + 1 <= mid) {
						res = mid;
						r = mid - 1;
					}
					else {
						l = mid + 1;
					}
				}
				
//				std::cout << res << '\n';
				anal.insert(State(nal[p1].t, res));
				bnal.add(res, 1);
				lnal.add(res, 1);
				p1++;
			}
			
			while (p2 <= m2 && itn[p2].s == t) {
				int l = 1;
				int r = aitn.size() + 1;
				int res = 0;
				
				while (l <= r) {
					int mid = (l + r) / 2;
					
					if (litn.get(mid) + 1 <= mid) {
						res = mid;
						r = mid - 1;
					}
					else {
						l = mid + 1;
					}
				}
				
				aitn.insert(State(itn[p2].t, res));
				bitn.add(res, 1);
				litn.add(res, 1);
				p2++;
			}
		}
		
		int ans = 0;
		for (int i = 0; i <= n; i++) {
			ans = std::max(ans, bnal.get(i) + bitn.get(n - i));
			
//			std::cout << i << ' ' << bnal.get(i) << ' ' << n - i << ' ' << bitn.get(n - i) << '\n';
		}
		
		std::cout << ans << '\n';
	}
}

int main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);	
	
	Solve::main();
	
	return 0;
}

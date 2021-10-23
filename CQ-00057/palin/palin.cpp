#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>

namespace Solve {
	int const N = 1e6;
	
	int a[N + 1];
	int n;

	namespace Subtask40 {
		int p1;
		int p2;
		bool taken[N + 1];
		int arr[N + 1];
		std::string ans;
		bool found;
		
		void dfs(int);
		
		void dfs(int k) {
			if (k > n) {
				found = true;
				int t1 = p1;
				int t2 = p2;
				
				std::string ans = Subtask40::ans;
				for (int i = n; i >= 1; i--) {
					if (a[t1] == arr[i]) {
						t1++;
						ans += 'L';
					}
					else if (a[t2] == arr[i]) {
						t2--;
						ans += 'R';
					}
					else {
						found = false;
					}
				}
				
				if (found) {
					std::cout << ans << '\n';
				}
			}
			else if (!found) {
				if (!taken[a[p1]]) {
					ans += 'L';
					taken[a[p1]] = true;
					arr[k] = a[p1];
					p1++;
					dfs(k + 1);
					
					p1--;
					taken[a[p1]] = false;
					ans.pop_back();
				}
				
				if (!found && !taken[a[p2]]) {
					ans += 'R';
					taken[a[p2]] = true;
					arr[k] = a[p2];
					p2--;
					dfs(k + 1);
					
					p2++;
					taken[a[p2]] = false;
					ans.pop_back();
				}
			}
		}
		
		void main() {
			p1 = 1;
			p2 = 2 * n;
			memset(taken, 0, sizeof taken);
			memset(arr, 0, sizeof arr);
			ans = "";
			found = false;
			
			dfs(1);
			
			if (!found) {
				std::cout << -1 << '\n';
			}
			
//			for (int s = 0; s < (1 << n); s++) {
//				std::vector<int> pre;
//				
//				int p1 = 1;
//				int p2 = 2 * n;
//				for (int i = n - 1; i >= 0; i--) {
//					if (!(s & (1 << i))) {
//						pre.push_back(a[p1]);
//						p1++;
//					}
//					else {
//						pre.push_back(a[p2]);
//						p2--;
//					}
//				}
//				
//				bool is = true;
//				std::string ans;
//				for (int i = (int) pre.size() - 1; i >= 0; i--) {
//					if (a[p1] == pre[i]) {
//						p1++;
//						ans += 'L';
//					}
//					else if (a[p2] == pre[i]) {
//						p2--;
//						ans += 'R';
//					}
//					else {
//						is = false;
//						break;
//					}
//				}
//				
//				if (is) {
//					for (int i = n - 1; i >= 0; i--) {
//						if (!(s & (1 << i))) {
//							std::cout << 'L';
//						}
//						else {
//							std::cout << 'R';
//						}
//					}
//					
//					std::cout << ans << '\n';
//					
//					return;
//				}
//			}
//			
//			std::cout << -1 << '\n';
		}
	}

	void main() {
		std::cin >> n;
		
		for (int i = 1; i <= 2 * n; i++) {
			std::cin >> a[i];
		}
		
		Subtask40::main();
	}
	
	void clear() {
		
	}
}

int main() {
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);	
	
	int t;
	std::cin >> t;
	
	for (; t; t--) {
		Solve::main();	
		Solve::clear();
	}
	
	return 0;
}

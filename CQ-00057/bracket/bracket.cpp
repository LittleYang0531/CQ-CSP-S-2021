#include <iostream>
#include <cstdio>
#include <string>

namespace Solve {
	int const N = 500;
	int const MOD = 1e9 + 7;
	
	std::string s;
//	int dp[N + 1][N + 1][N + 1][3];
	int n, lim;
	
	namespace BF {
		std::string s;
		std::string::iterator c;
		int cnt;
		
		bool matchA();
		bool matchS();
		bool match();
		void dfs(int);
		
		void dfs(int k) {
			if (k > n) {
				c = s.begin() + 1;
				cnt += match();
//				std::cerr << s << ' ' << cnt << '\n';
			}
			else {
				s += 'B';
				if (Solve::s[k] == '?') {
					s[k] = '(';
					dfs(k + 1);
					s[k] = ')';
					dfs(k + 1);
					s[k] = '*';
					dfs(k + 1);
				}
				else {
					s[k] = Solve::s[k];
					dfs(k + 1);
				}
				
				s.pop_back();
			}
		}
		
		bool matchS() {
//			std::cerr << "S " << *c << '\n';
			int cnt = 0;
			while (c != s.end() && *c == '*') {
				cnt++;
				c++;
			}
			
			return cnt <= lim;
		}
		
		bool matchA() {
//			std::cerr << "A\n";
			if (c == s.end() || *c != '(') {
				return false;
			}
			
			c++;
			int cnt = 0;
			int last = 0;
			bool same = false;
			while (c != s.end() && *c != ')') {
				bool cur = false;
				if (*c == '(') {
					cur = matchA();
					
					if (cnt == 0) {
						last = 0;
						cnt++;
						same = !same;
					}
					else if (last != 0) {
						cnt++;
						last = 0;
						same = !same;
					}
				}
				else {
					cur = matchS();
					
					last = 1;
					cnt++;
					same = !same;
				}
				
				if (!cur) {
					return false;
				}
			}
			
			if (c == s.end()) {
				return false;
			}
			else {
				c++;
				return cnt <= 1 || (cnt > 1 && (!same || (same && last == 0)));
			}
		}
		
		bool match() {
			bool t = matchA();
			
			if (!t) {
				return false;
			}
			else {
				while (c != s.end()) {
					if (*c == '*') {
						bool t1 = matchS();
						bool t2 = matchA();
						
						if (!t1 || !t2) {
							return false;
						}	
					}
					else {
						if (!matchA()) {
							return false;
						}
					}
				}
				
				return true;
			}
		}
		
		void main() {
			s = ' ';
			dfs(1);
			std::cout << cnt << '\n';
		}
	}
	
	void main() {
		std::cin >> n >> lim >> s;
		
		s = " " + s;
		
		BF::main();
		
//		if (s[1] != '(' && s[1] != '?') {
//			std::cout << 0 << '\n';
//			return;
//		}
//		
//		dp[1][1][0][0] = 1;
//		for (int i = 2; i <= n; i++) {
//			char c = s[i];
//			for (int j = 0; j <= i; j++) {
//				if (j > 0 && (c == '(' || c == '?')) {
//					for (int k = 0; k + j - 1 <= i - 1 && k <= lim; k++) {
//						dp[i][j][0][0] = ((long long) dp[i][j][0][0] + dp[i - 1][j - 1][k][0] + dp[i - 1][j - 1][k][1] + dp[i - 1][j - 1][k][3] + dp[i - 1][j - 1][k][4] + dp[i - 1][j - 1][k][5]) % MOD;
//						dp[i][j][0][1] = (dp[i][j][0][1] + dp[i - 1][j - 1][k][4]) % MOD;
//					}
//				}
//			
//				if (c == ')' || c == '?') {
//					for (int k = 0; k + j + 1 <= i - 1 && k <= lim; k++) {
//						dp[i][j][0][2] = (dp[i][j][0] + dp[i - 1][j + 1][k]) % MOD;
//					}
//				}
//				
//				if (j > 0 && (c == '*' || c == '?')) {
//					for (int k = 1; k + j <= i && k <= lim; k++) {
//						dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][k - 1]) % MOD;
//					}
//				}
//				
//				for (int k = 0; k + j <= i && k <= lim; k++) {
//					std::cout << i << ' ' << j << ' ' << k << ' ' << dp[i][j][k] << '\n';
//				}
//			}
//		}
//		
//		std::cout << dp[n][0][0] << '\n';
	}
}

int main() {
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);	
	
	Solve::main();
	
	return 0;
}

#include "iostream"
#include "string"

using namespace std;



int n, k, ans;
string S;




int main () {
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	cin >> n >> k >> S;
	for (register int i = 0; i < n; i ++) {
		ans += (S[i] == '?');
	}
	cout << ans << endl;
	return 0;
}

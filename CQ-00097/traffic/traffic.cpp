#include <bits/stdc++.h>


using namespace std;
typedef long long ll;
const int N = 500 * 500 + 500;
int n,m,t;
ll a[N];


int main() {
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m >> t;
	int cnt = 0;
	for(int i = 1;i <= n - 1;i++) {
		for(int j = 1;j <= m;j++) {
			cin >> a[++cnt];
		}
	}
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j < m;j++) {
			cin >> a[++cnt];
		}
	}
	while(t--) {
		int k;
		cin >> k;
		if(k == 1) {
			cout << "0\n"; 
		} else {
			int x,y,z;
			cin >> x >> y >> z;
			int x1,y1,z1;
			cin >> x1 >> y1 >> z1;
			if(y1 < y) {
				swap(x,x1);
				swap(y,y1);
				swap(z,z1);
			}
			if(z == z1) {
				cout << "0\n";
			} else
			if((y == 1 && y1 == m * 2 + n * 2)||(y == m && y1 == y + 1) || (y == m + n && y1 == y + 1) || (y == m * 2 + n && y1 == y + 1)) {
				cout << min(x,x1) << '\n';
			} else {
				cout << min(x,x1) << '\n';  
			}
		}
	}
	return 0;
}

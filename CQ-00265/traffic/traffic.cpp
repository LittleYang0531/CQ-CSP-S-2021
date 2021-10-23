#include<bits/stdc++.h>
using namespace std;
int n,m,t;
int x,y;
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	cin >> n >> m >> t;
	for(int i = 1;i < n;i ++){
		for(int j = 1;j <= m;j ++){
			cin >> x;
		}
	}
	for(int i = 1;i <= n;i ++){
		for(int j = 1;j < m;j ++){
			cin >> y;
		}
	}
	int k;
	int a,b,c;
	for(int i = 1;i <= t;i ++){
		cin >> k;
		for(int j = 1;j <= k;j ++){
			cin >> a >> b >> c;
		}
		cout << (a + b + c) % x + y - k << endl;
	}
	return 0;
}

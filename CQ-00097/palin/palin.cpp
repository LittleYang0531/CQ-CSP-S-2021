#include <bits/stdc++.h>


using namespace std;
const int N = 1e6 + 10;
int n,m;
char res[N],res2[N];
bool sol1,sol2;
int a[N],b[N],loc[N],vis[N];
int vis1[N],vis2[N],s[N];
int cnt1,cnt2 = 0;

inline bool com() {
	for(int i = 1;i <= n * 2;i++) {
		if(res[i] == res2[i]) continue;
		if(res[i] < res2[i]) {return 1;
		} else return 0;
	}
	return 1;
}
int main() {
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int times;
	cin >> times;
	while(times--) {
		cin >> n;
		for(int i = 1;i <= n * 2;i++) vis[i] = 0,vis1[i] = vis2[i] = 0;
		for(int i = 1;i <= n * 2;i++) {
			cin >> a[i];
			if(!vis[a[i]]) vis[a[i]] = i;
			else loc[i] = vis[a[i]],loc[vis[a[i]]] = i;
		}
		// 1:
		sol1 = sol2 = true;
		cnt1 = cnt2 = 0;
		int poi1 = 2,poi2 = 2 * n,poi3 = loc[1] - 1,poi4 = loc[1] + 1;
		res[++cnt1] = 'L',vis1[1] = true,s[cnt1] = a[1];
		if(sol1) {
			int tot = n * 2 - 2;
			while(tot) {
				if(poi1 < poi3 && a[poi1] == a[poi3]) {
					res[++cnt1] = 'L';
					s[cnt1] = a[poi1];
					vis1[poi1] = 1;
					poi1++,poi3--;
				} else if(poi1 < poi4 && a[poi1] == a[poi4]) {
					res[++cnt1] = 'L';
					vis1[poi1] = 1;
					s[cnt1] = a[poi1];
					poi1++,poi4++;
				} else  if(poi2 > poi4 && a[poi2] == a[poi4]){
					res[++cnt1] = 'R';
					vis1[poi2] = 1;
					s[cnt1] = a[poi2];
					poi2--,poi4++;
				} else if(poi3 < poi2 && a[poi3] == a[poi2]) {
					res[++cnt1] = 'R';
					s[cnt1] = a[poi3];
					vis1[poi2] = 1;
					poi2--,poi3--;
				} else {
					sol1 = false;
					break;
				}
				tot -= 2;
			}
			if(sol1) {
				tot = 0;
				for(int i = 1;i <= n * 2;i++) if(!vis1[i]) b[++tot] = a[i];
				poi1 = 1,poi2 = tot;
				for(int i = 1;i <= n;i++) {
					if(s[n - i + 1] == b[poi1]) {
						res[++cnt1] = 'L';
						poi1++;
					} else {
						res[++cnt1] = 'R';
						poi2--;
					}
				}
			}
		}
		poi1 = 1,poi2 = 2 * n - 1,poi3 = loc[n * 2] - 1,poi4 = loc[n * 2] + 1;
		res2[++cnt2] = 'R',vis2[n * 2] = true,s[cnt2] = a[n * 2];
		if(sol2) {
			int tot = n * 2 - 2;
			while(tot) {
				if(poi1 < poi3 && a[poi1] == a[poi3]) {
					res2[++cnt2] = 'L';
					s[cnt2] = a[poi1];
					vis2[poi1] = 1;
					poi1++,poi3--;
				} else if(poi1 < poi4 && a[poi1] == a[poi4]) {
					res2[++cnt2] = 'L';
					vis2[poi1] = 1;
					s[cnt2] = a[poi1];
					poi1++,poi4++;
				} else  if(poi2 > poi4 && a[poi2] == a[poi4]){
					res2[++cnt2] = 'R';
					vis2[poi2] = 1;
					s[cnt2] = a[poi2];
					poi2--,poi4++;
				} else if(poi3 < poi2 && a[poi3] == a[poi2]) {
					res2[++cnt2] = 'R';
					s[cnt2] = a[poi3];
					vis2[poi2] = 1;
					poi2--,poi3--;
				} else {
					sol2 = false;
					break;
				}
				tot -= 2;
			}
			if(sol2) {
				tot = 0;
				for(int i = 1;i <= n * 2;i++) if(!vis2[i])b[++tot] = a[i];
				poi1 = 1,poi2 = tot;
				for(int i = 1;i <= n;i++) {
					if(s[n - i + 1] == b[poi1]) {
						res2[++cnt2] = 'L';
						poi1++;
					} else {
						res2[++cnt2] = 'R';
						poi2--;
					}
				}
			}
		}
		if(sol1) {
			for(int i = 1;i <= n * 2;i++) {
				cout << res[i];
			}
			cout << '\n';
		} else if(sol2){
			for(int i = 1;i <= n * 2;i++) {
				cout << res2[i];
			}
			cout << '\n';
		} else {
			cout << "-1\n";
		}
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int t,n,a[1000000],v[500000];
string r_ans;
bool flag;
void check(string ans) {
	if (ans < r_ans) {
		flag = 0;
		r_ans = ans;
	}
}
void dfs(int l,int r,int i,string s) {
	if (l > r || i == 2 * n || s.size() == 2 * n) {
		check(s);
		return ;
	}
	string ss;
	if (!v[a[l]] || v[a[l]] + i == 2 * n) {
		ss = s + 'L';
		bool ff = 0;
		if (!v[a[l]]) ff = 1,v[a[l]] = i + 1;
		dfs(l + 1,r,i + 1,ss);
		if (ff) v[a[l]] = 0;
	}
	if (!v[a[r]] || v[a[r]] + i == 2 * n) {
		ss = s + 'R';
		bool ff = 0;
		if (!v[a[r]]) ff = 1,v[a[r]] = i + 1;
		dfs(l,r - 1,i + 1,ss);
		if (ff) v[a[r]] = 0;
	}
}
int main() {
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while (t --) {
		flag = 1;
		string s;
		r_ans.clear();
		memset(v,0,sizeof(v));
		scanf("%d",&n);
		for (int i = 0; i < 2 * n; i ++) r_ans += "a";
		for (int i = 0; i < 2 * n; i ++) scanf("%d",&a[i]);
		dfs(0,2 * n - 1,0,s);
		if (flag) printf("-1\n");
		else cout << r_ans << endl;
	}
	return 0;
}

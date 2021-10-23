#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int n, k;
string xx;
string ans;
int ANS=0;
//x:连续*数量 y：(0:in) *(1:in) ()2:out&!*  *()3:out&*
void dfs(int d, int x, int y, int lef) {
	if(d>n) {
		if(lef==0) {
			ANS=(ANS+1)%mod;
//			if(ANS%1000==0) cout << ANS << endl;
//			cout << ans << endl;
		}
	}

	if(xx[d]=='*') {
		if(x<k&&y<=2) dfs(d+1, x+1, y, lef);
		return;
	}
	if(xx[d]=='(') {
		dfs(d+1, 0, xx[d-1]=='*', lef+1);
		return;
	}
	if(xx[d]==')') {
		dfs(d+1, 0, y+2, lef-1);
		return;
	}
	if(xx[d]=='?') {
		if(lef+1<=n-d) {
			ans[d]='(';
			dfs(d+1, 0, xx[d-1]=='*'?1:0, lef+1);

		}
		if(lef) {
			ans[d]=')';
			dfs(d+1, 0, y+2, lef-1);
			if(lef==n-d) return;
		}
		if(y<=2&&x<k) {
			ans[d]='*';
			dfs(d+1, x+1, y, lef);
		}
	}
}
int main() {
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	scanf("%d%d", &n, &k);
	cin >> xx;
	xx='0'+xx;
	if(xx[1]=='?') {
		xx[1]='(';
	} else if(xx[1]!='(') {
		putchar('0');
		return 0;
	}
	if(xx[n]=='?') {
		xx[n]=')';
	} else if(xx[n]!=')') {
		putchar('0');
		return 0;
	}
	ans=xx;
	dfs(1, 0, -1, 0);
	cout << ANS << endl;
	return 0;
}


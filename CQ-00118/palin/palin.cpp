# include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5+5;
int T, n, tot;
int ak[2*maxn];
char ans[2*maxn];
bool check(deque<int> z){
	int j = 0, b[2*maxn];
	while(!z.empty()){
		int cnt = z.front();
		z.pop_front();
		j++;
		b[j] = cnt;
	}
	for (int i=1; i<=j; i++){
		if (b[i] != b[2*j+1-i]){
			return false;
		}
	}
	return true;
}
void find(deque<int> x, deque<int> y){
	if (y.size() == 2*n){
		if (check(y) == true)	return ;
	}
	int k1 = x.front();
	x.pop_front();
	y.push_back(k1);
	tot++, ans[tot] = 'L';
	find(x, y);
	int k2 = x.back();
	x.pop_back();
	y.push_back(k2);
	tot++, ans[tot] = 'R';
	find(x, y);
}
int main (){
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	scanf("%d", &T);
	deque<int> a;
	deque<int> b;
	while(T--){
		scanf("%d", &n);
		tot = 0;
		a.clear(), b.clear();
		for (int i=1; i<=2*n; i++){
			scanf("%d", &ak[i]);
			a.push_back(ak[i]);
		}
		find(a, b);
		if (tot != 2 * n){
			printf("-1\n");
		}
		else printf("%s\n", ans);
	}
	
	return 0;
}

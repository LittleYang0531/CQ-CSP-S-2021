#include <iostream>
#include <algorithm>
#include <set>
#include <cstdio>

using namespace std;

typedef struct {
	int a;
	int b;
} Item;

typedef struct Fuck_tag {
	int id;
	int start;
	int end;
	Fuck_tag(int id_, int start_, int end_){
		id = id_;
		start = start_;
		end = end_;
	}
} Fuck;

int a1[100007], b1[100007], a2[100007], b2[100007];
int lsp[400007], fuck1[100007], fuck2[100007];
Item a[100007];
set<Fuck> s;

bool operator <(const Item a, const Item b){
	return a.a < b.a;
}

bool operator <(const Fuck a, const Fuck b){
	return a.start < b.start;
}

int main(){
	int n, m1, m2, k = 0, ans = 0;
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	scanf("%d %d %d", &n, &m1, &m2);
	for (int i = 1; i <= m1; i++){
		scanf("%d %d", &a[i].a, &a[i].b);
	}
	sort(a + 1, a + m1 + 1);
	for (int i = 1; i <= m1; i++){
		a1[i] = a[i].a;
		b1[i] = a[i].b;
		lsp[++k] = a1[i];
		lsp[++k] = b1[i];
	}
	for (int i = 1; i <= m2; i++){
		scanf("%d %d", &a[i].a, &a[i].b);
	}
	sort(a + 1, a + m2 + 1);
	for (int i = 1; i <= m2; i++){
		a2[i] = a[i].a;
		b2[i] = a[i].b;
		lsp[++k] = a2[i];
		lsp[++k] = b2[i];
	}
	sort(lsp + 1, lsp + k + 1);
	for (int i = 1; i <= m1; i++){
		a1[i] = lower_bound(lsp + 1, lsp + k + 1, a1[i]) - lsp;
		b1[i] = lower_bound(lsp + 1, lsp + k + 1, b1[i]) - lsp;
	}
	for (int i = 1; i <= m2; i++){
		a2[i] = lower_bound(lsp + 1, lsp + k + 1, a2[i]) - lsp;
		b2[i] = lower_bound(lsp + 1, lsp + k + 1, b2[i]) - lsp;
	}
	for (int i = 1; i <= m1; i++){
		s.insert(Fuck(i, a1[i], b1[i]));
	}
	for (int i = 1; i <= n; i++){
		fuck1[i] = fuck1[i - 1];
		for (set<Fuck>::iterator j = s.begin(); j != s.end(); ){
			int cur = j->id;
			s.erase(j);
			j = s.lower_bound(Fuck(0, b1[cur], 0));
			fuck1[i]++;
		}
	}
	s.clear();
	for (int i = 1; i <= m2; i++){
		s.insert(Fuck(i, a2[i], b2[i]));
	}
	for (int i = 1; i <= n; i++){
		fuck2[i] = fuck2[i - 1];
		for (set<Fuck>::iterator j = s.begin(); j != s.end(); ){
			int cur = j->id;
			s.erase(j);
			j = s.lower_bound(Fuck(0, b2[cur], 0));
			fuck2[i]++;
		}
	}
	for (int i = 0; i <= n; i++){
		ans = max(ans, fuck1[i] + fuck2[n - i]);
	}
	cout << ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

int n = 0, m1 = 0, m2 = 0, max1 = 0, max2 = 0, ans1 = 0, ans2 = 0, ans = 0;
int va[100001] = {}, vb[100001] = {};

struct Node{
	int sta, end;
}a[100001] = {}, b[100001] = {};

bool cmp(Node p, Node q){
	return p.sta <= q.sta;
}

void sf(int x){
	ans1 = 0;
	ans2 = 0;
	priority_queue<int> da, db;
	int la = 1, lb = 1;
	da.push(-2147483647);
	db.push(-2147483647);
	for(int i = 1; i <= max(max1, max2); i++){
		if(1){
			la++; la--;
		}
		if(-da.top() > i && !da.empty()){
			da.pop();
			la--;
		}
		if(-db.top() > i && !db.empty()){
			db.pop();
			lb--;
		}
		if(va[i] && da.size() < x){
			da.push(-a[va[i]].end);
			la++;
			ans1++;
		}
		if(vb[i] && db.size() <= n - x){
			db.push(-b[vb[i]].end);
			lb++;
			ans2++;
		}
	}
}

int main(){
	int l = 0, r = 0;
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	scanf("%d %d %d", &n, &m1, &m2);
	for(int i = 1; i <= m1; i++){
		scanf("%d %d", &a[i].sta, &a[i].end);
		max1 = max(max1, a[i].end);
	}
	for(int i = 1; i <= m2; i++){
		scanf("%d %d", &b[i].sta, &b[i].end);
		max2 = max(max2, b[i].end);
	}
	stable_sort(a + 1, a + n + 1, cmp);
	stable_sort(b + 1, b + n + 1, cmp);
	for(int i = 1; i <= m1; i++){
		va[a[i].sta] = i;
	}
	for(int i = 1; i <= m2; i++){
		vb[b[i].sta] = i;
	}
	r = n;
	int lmid = 0, rmid = n;
	while(l != r - 1 && l != r && lmid != rmid - 1){
		double midd = 1.0 * (l + r) / 3.0;
		if(midd < l){
			lmid = l;
		}
		else if(l <= midd && midd <= r){
			lmid = midd;
		}
		else{
			lmid = r;
		}
		if(midd * 2 < l){
			rmid = midd * 2;
		}
		else if(l <= midd * 2 && midd * 2 <= r){
			rmid = midd * 2;
		}
		else{
			rmid = r;
		}
		sf(l);
		int vl = ans1 + ans2;
		sf(lmid);
		int vlm = ans1 + ans2;
		sf(rmid);
		int vrm = ans1 + ans2;
		sf(r);
		int vr = ans1 + ans2;
		ans = max(max(max(vl, vlm), max(vrm, vr)), ans);
		if(vl >= vlm && vlm >= vrm && vrm >= vr){
			r = lmid;
		}
		else if(vl <= vlm && vlm >= vrm && vrm >= vr){
			r = rmid;
		}
		else if(vl <= vlm && vlm <= vrm && vrm >= vr){
			l = lmid;
		}
		else{
			l = rmid;
		}
	}
	printf("%d", ans);
	return 0;
}

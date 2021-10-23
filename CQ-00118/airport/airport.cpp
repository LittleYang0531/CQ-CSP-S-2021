# include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
struct node{
	int get, leave;
};
int n, m1, m2, t1, t2, ans = -maxn;
node mm1[maxn], mm2[maxn];
node cnt1[maxn], cnt2[maxn];
bool cmp(node a, node b){
	if (a.get == b.get){
		return a.leave < b.leave;
	}
	return a.get < b.get;
}
bool cmp2(node a, node b){
	if (a.leave == b.leave){
		return a.get < b.get;
	}
	return a.leave < b.leave;
}
int main (){
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	scanf("%d %d %d", &n, &m1, &m2);
	for (int i=1; i<=m1; i++){
		scanf("%d %d", &mm1[i].get, &mm1[i].leave);
	}
	sort(mm1+1, mm1+m1+1, cmp);
	for (int i=1; i<=m2; i++){
		scanf("%d %d", &mm2[i].get, &mm2[i].leave);
	}
	sort(mm2+1, mm2+m2+1, cmp);
	for (int i=0; i<=n; i++){
		int ans1 = 0, ans2 = 0;
		int j = n - i;
		for (int k=1; k<=i; k++){
			cnt1[k] = mm1[k];
		}
		t1 = i, ans1 = i;
		sort(cnt1+1, cnt1+t1+1, cmp2);
		if (i != 0){
			int x = 1;
			for (int k=i+1; k<=m1; k++){
				for (int l=x; l<=t1; l++){
					if (mm1[k].get > cnt1[l].leave){
						cnt1[++t1] = mm1[k];
						x = l+1;
						ans1++;
						break;
					}
				}
			} 
		}
		for (int k=1; k<=j; k++){
			cnt2[k] = mm2[k];
		}
		t2 = j, ans2 = j;
		sort(cnt2+1, cnt2+t2+1, cmp2);
		if (j != 0){
			int y = 1;
			for (int k=j+1; k<=m2; k++){
				for (int l=y; l<=t2; l++){
					if (mm2[k].get > cnt2[l].leave){
						cnt2[++t1] = mm2[k];
						y = l+1;
						ans2++;
						break;
					}
				}
			}
		}
		if (i == 0){
			ans = max(ans, ans2);
		}
		else if (j == 0){
			ans = max(ans, ans1);
		}
		else ans = max(ans, ans2+ans1);
	}
	printf("%d", ans);
	
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node {
	int x, y;
} pl[100005];
//int ccf[100000005];
int tmp1, tmp2;
bool cmp(node x, node y) {
	return x.x<y.x;
}
int n, m1, m2, ans=0;
struct num {
	int x;
};
bool operator <(num x, num y) {
	return x.x>y.x;
}
priority_queue<num> q;
void cheak(int x, int y) {
	int ANS=0;
	while(!q.empty()) q.pop();
	for(int i=1; i<=m1; ++i) {
		if(!q.empty()&&pl[i].x>=q.top().x) {
			++x;
			q.pop();
		}
		if(x) {
			--x;
			++ANS;
			q.push(num {pl[i].y});
		}
	}
	tmp1=ANS;
//	cout << ANS << " ";
	while(!q.empty()) q.pop();
	for(int i=m1+1; i<=m1+m2; ++i) {
		if(!q.empty()&&pl[i].x>=q.top().x) {
			++y;
			q.pop();
		}
		if(y) {
			--y;
			++ANS;
			q.push(num {pl[i].y});
		}
	}
//	cout << ANS-tmp1 << " " << ANS << endl;
	tmp2=ANS-tmp1;
	ans=max(ans, ANS);
//	return ANS;
}

int main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
//	cout << sizeof(ccf)/1024/1024;
//	q.push(num{1});
//	q.push(num{2});
//	cout << q.top().x;
	
	scanf("%d%d%d", &n, &m1, &m2);

	for(int i=1; i<=m1; ++i) {
		scanf("%d%d", &pl[i].x, &pl[i].y);
	}
	for(int i=1; i<=m2; ++i) {
		scanf("%d%d", &pl[i+m1].x, &pl[i+m1].y);
	}
	sort(pl+1, pl+m1+1, cmp);
	sort(pl+m1+1, pl+m1+m2+1, cmp);
	for(int L1=n/2; L1<=n; ++L1) {
		int L2=n-L1;
		cheak(L1, L2);
		if(tmp1==m1) break;
	}
	for(int L1=n/2-1; L1>=0; --L1) {
		int L2=n-L1;
		cheak(L1, L2);
		if(tmp2==m2) break;
	}
	printf("%d", ans);
	return 0;
}
/*
3 5 4
1 5
3 8
6 10
9 14
13 18
2 11
4 15
7 17
12 16
*/

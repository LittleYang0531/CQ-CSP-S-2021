#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
int n, m1, m2, ans;
struct feiji
{
	int a, b;
}x1[N], x2[N];
int nei(int x)
{
	priority_queue<int, vector<int>, greater<int> > q;
	int sum = 0;
	for(int i = 1; i <= m1; i++)
	{
		if(q.size() < x)
		{
			q.push(x1[i].b);
			sum++;
		}
		else if(q.size() > 0 && q.top() < x1[i].a)
		{
			q.pop();
			q.push(x1[i].b);
			sum++;
		}
	}
	return sum;
}
int ji(int x)
{
	priority_queue<int, vector<int>, greater<int> > q;
	int sum = 0;
	for(int i = 1; i <= m2; i++)
	{
		if(q.size() < x)
		{
			q.push(x2[i].b);
			sum++;
		}
		else if(q.size() > 0 && q.top() <= x2[i].a)
		{
			q.pop();
			q.push(x2[i].b);
			sum++;
		}
	}
	return sum;
}
bool cmp(feiji x, feiji y)
{
	return x.a < y.a;
}
int main()
{
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	cin >> n >> m1 >> m2;
	for(int i = 1; i <= m1; i++)
		scanf("%d%d", &x1[i].a, &x1[i].b);
	for(int i = 1; i <= m2; i++)
		scanf("%d%d", &x2[i].a, &x2[i].b);
	sort(x1 + 1, x1 + m1 + 1, cmp);
	sort(x2 + 1, x2 + m2 + 1, cmp);
	for(int i = 0; i <= n; i++)
	{
		ans = max(ans, nei(i) + ji(n - i));
	}
	cout << ans << endl;
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
struct sfarg {
	int a,b;
} go[3][100001];
bool cmp(sfarg a,sfarg b)
{
	return a.a > b.a ? 1 : 0;
}
queue<sfarg> clear()
{
	queue<sfarg> q;
	return q;
}
int main()
{

	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m1,m2;
	cin >> n >> m1 >> m2;
	for(int i = 1;i <= m1;i++)
	{
		cin >> go[1][i].a >> go[1][i].b;
	}
	for(int i = 1;i <= m2;i++)
	{
		cin >> go[2][i].a >> go[2][i].b;
	}
	sort(go[1]+1,go[1]+m1+1,cmp);
	sort(go[2]+1,go[2]+m2+1,cmp);
//	for(int i = 1;i <= m1;i++)
//	{
//		cout << go[1][i].a << " " << go[1][i].b << endl;
//	}
//	cout << endl;
//	for(int i = 1;i <= m2;i++)
//	{
//		cout << go[2][i].a << " " << go[2][i].b << endl;
//	}
//	cout << endl;
	
	queue<sfarg> q;
	int maxx = 0;
	for(int k = 0;k <= n;k++)
	{
		while(!q.empty())
		{
			q.pop();
		}
		int ans = 0;
		if(k != 0)
		{
			ans++;
		q.push(go[1][m1]);
//		cout << "k:" << k << " 1,i:" << go[1][m1].a << "," << go[1][m1].b << endl;
		for(int i = m1-1;i >= 1;i--)
		{
			if(go[1][i].a >= q.front().b)
			{
				q.pop();
			}
			if(q.size() < k)
			{
//				cout << "k:" << k << " 1,i:" << go[1][i].a << "," << go[1][i].b << endl;
				q.push(go[1][i]);
				ans++;
			}
		}
		}
		
//		if(k == 0)
//		{
//			ans = 0;
//		}
//		int cns = ans;
		while(!q.empty())
		{
			q.pop();
		}
		if(n-k != 0)
		{
			q.push(go[2][m2]);
		ans++;
//		cout << "k:" << k << " 2,i:" << go[2][m2].a << "," << go[2][m2].b << endl;
		for(int i = m2-1;i >= 1;i--)
		{
			if(go[2][i].a >= q.front().b)
			{
				q.pop();
			}
			if(q.size() < n-k)
			{
//				cout << "k:" << k << " 2,i:" << go[2][i].a << "," << go[2][i].b << endl;
				q.push(go[2][i]);
				ans++;
			}
		}
		}
		
//		cout << endl;
//		if(n-k == 0)
//		{
//			ans = cns;
//		}
		if(ans != m1+m2)
		{
			maxx = max(maxx,ans);
		}
		
	}
	
	cout << maxx;
	return 0;
}

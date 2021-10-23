#include<bits/stdc++.h>
using namespace std;
int rt;
inline int randn(int s)
{
	srand(time(NULL) + s + s * s);
	rt = rand() * rand() + s;
	srand(time(NULL) + rt * s);
	return rt = rand() * rand() + rand(); 
}
int main()
{
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, t;
	cin>>n>>m>>t;
	cout<<abs(randn(randn(randn(n * n) + m * m) + t * t)) % 100;
}

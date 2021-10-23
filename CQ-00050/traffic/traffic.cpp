#include <bits/stdc++.h>
using namespace std;
int T , n , m , k , x , p , c , x1[550][550] , x2[550][550] , s , t;
int fst[550000] , nex[1100000] , v[1100000] , val[1100000] , tot = 1;
int dis[550000] , cur[550000] , mf;
queue< int > q;
int id( int x , int y )
{
	return (x - 1) * m + y;
}
void add( int a , int b , int c )
{
	nex[++tot] = fst[a]; fst[a] = tot;
	v[tot] = b; val[tot] = c;
	nex[++tot] = fst[b]; fst[b] = tot;
	v[tot] = a; val[tot] = 0;
}
void add2( int a , int b , int c )
{
	nex[++tot] = fst[a]; fst[a] = tot;
	v[tot] = b; val[tot] = c;
	nex[++tot] = fst[b]; fst[b] = tot;
	v[tot] = a; val[tot] = c;
}
bool bfs()
{
	for(int i = 0 ; i <= t ; i++ ) dis[i] = 0;
	q.push(s); dis[s] = 1;
	while(!q.empty())
	{
		int u = q.front(); q.pop();
		for(int i = fst[u] ; i ; i = nex[i] )
		{
			if(!dis[v[i]] && val[i])
			{
				dis[v[i]] = dis[u] + 1;
				q.push(v[i]);
			}
		}
	}
	return (dis[t] != 0);
}
int dfs( int u , int flow )
{
	if(u == t)
	{
		mf += flow;
		return flow;
	}
	int sum = 0;
	for( ; cur[u] ; cur[u] = nex[cur[u]] )
//	for(int i = fst[u] ; i ; i = nex[i] )
	{
		int i = cur[u];
		if(dis[v[i]] != dis[u] + 1 || !val[i]) continue;
		long long qwq = dfs(v[i] , min(flow , val[i]));
		sum += qwq; flow -= qwq;
		val[i] -= qwq; val[i ^ 1] += qwq;
	}
	return sum;
}
void dinic()
{
	mf = 0;
	while(bfs())
	{
		for(int i = s ; i <= t ; i++ ) cur[i] = fst[i];
		dfs(s , 1e9);
	}
}
int main()
{
	freopen("traffic.in" , "r" , stdin);
	freopen("traffic.out" , "w" , stdout);
	scanf("%d%d%d" , &n , &m , &T);
	for(int i = 1 ; i < n ; i++ )
		for(int j = 1 ; j <= m ; j++ ) scanf("%d" , &x1[i][j]);
	for(int i = 1 ; i <= n ; i++ )
		for(int j = 1 ; j < m ; j++ ) scanf("%d" , &x2[i][j]);
	s = 0 , t = n * m + 1;
	while(T--)
	{
		scanf("%d" , &k);
		for(int i = s ; i <= t ; i++ ) fst[i] = 0; tot = 1;
		for(int i = 1 ; i <= k ; i++ )
		{
			scanf("%d%d%d" , &x , &p , &c);
			if(p <= m)
			{
				if(c) add(id(1 , p) , t , x);
				else add(s , id(1 , p) , x);
			}
			if(m < p && p <= n + m)
			{
				if(c) add(id(p - m , m) , t , x);
				else add(s , id(p - m , m) , x);
			}
			if(m + n < p && p <= n + m + m)
			{
				if(c) add(id(n , m + 1 - p + n + m) , t , x);
				else add(s , id(n , m + 1 - p + n + m) , x);
			}
			if(m + n + m < p && p <= n + m + m + n)
			{
				if(c) add(id(n + 1 - p + m + n + m , 1) , t , x);
				else add(s , id(n + 1 - p + m + n + m , 1) , x);
			}
		}
		for(int i = 1 ; i < n ; i++ )
			for(int j = 1 ; j <= m ; j++ ) 
				add2(id(i , j) , id(i + 1 , j) , x1[i][j]);
		for(int i = 1 ; i <= n ; i++ )
			for(int j = 1 ; j < m ; j++ ) 
				add2(id(i , j) , id(i , j + 1) , x2[i][j]);
//		for(int i = fst[s] ; i ; i = nex[i]) cerr << v[i] << endl;
		dinic();
		printf("%d\n" , mf);
	}
	return 0;
}

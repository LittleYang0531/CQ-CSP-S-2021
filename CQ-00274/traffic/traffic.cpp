#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std ;

const int N = 2780065 ;

int rd()
{
	int x = 0 , f = 1 ;
	char ch = getchar() ;
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1 ; ch = getchar() ;}
	while(ch >= '0' && ch <= '9'){x = (x << 1) + (x << 3) + (ch ^ 48) ; ch = getchar() ;}
	return x * f ;
}

struct Edge
{
	int from , to , w ;
	bool operator < (Edge a) const
	{
		return w > a.w ;
	}
}edge[N] ,e[N] ;
int siz , Tsiz ;
void add(int from , int to , int w)
{
	edge[++siz] = (Edge){from , to , w} ;
}

void add2(int from , int to , int w)
{
	e[++Tsiz] = (Edge){from , to , w} ;
}

int f[N] , cal[N] ;
int find(int x)
{
	if(f[x] == x) return x ;
	f[x] = find(f[x]) ;
	if(cal[x]) cal[f[x]] = cal[x] ;
	if(cal[f[x]]) cal[x] = cal[f[x]] ;
	return f[x] ;
}

int n , m , T , MX ;

int Get(int i , int j)
{
	return (i - 1) * m + j ;
}

int main()
{
	freopen("traffic.in","r",stdin) ;
	freopen("traffic.out","w",stdout) ;
	
	n = rd() ; m = rd() ; T = rd() ;
	MX = n * m + 500 ;
	for(int i = 1 ; i < n ; i++)
		for(int j = 1 ; j <= m ; j++)
			add(Get(i , j) , Get(i + 1 , j) , rd( ) ) ;
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j < m ; j++)
			add(Get(i , j) , Get(i , j + 1) , rd( ) ) ;
			
	while(T--)
	{
		int k = rd() , mn = 0 ;
		Tsiz = siz ;
		memset(cal , 0 , sizeof cal) ;
		memset(e , 0 , sizeof e) ;
		for(int i = 1 ; i <= siz ; i++)
			e[i] = edge[i] ;
		for(int i = 1 ; i <= k ; i++)
		{
			int a = rd() , b = rd() , c = (rd() == 0 ? 1 : 2) ;
			cal[MX + b] = c ;
			mn = max(mn , b + MX) ;
			if(b <= m)
				add2(MX + b , Get(1 , b) , a) ;
			else if(b <= m + n)
				add2(MX + b , Get(b - m , m) , a) ;
			else if(b <= 2 * m + n)
				add2(MX + b , Get(n , m - (b - m - n) + 1) , a) ;
			else
				add2(MX + b , Get(n - (b - 2 * m - n) + 1 , 1) , a) ;
		}
		
		sort(e + 1 , e + Tsiz + 1) ;
		
		for(int i = 1 ; i <= mn ; i++)
			f[i] = i ;
		
		long long ans = 0 ;
		for(int i = 1 ; i <= Tsiz ; i++)
		{
			int u = e[i].from , v = e[i].to , w = e[i].w ;
			int a = find(u) , b = find(v) ;
			if(a == b) continue ;
			if(cal[u]) cal[a] = cal[u] ;
			if(cal[v]) cal[b] = cal[v] ;
			
			if(cal[a] == 0 && cal[b] == 0) f[b] = a ;
			else if(cal[a] && cal[b] == 0) cal[b] = cal[a] , f[b] = a ;
			else if(cal[a] == 0 && cal[b]) cal[a] = cal[b] , f[a] = b ;
			else if(cal[a] == cal[b]) f[a] = b ;
			else ans += w ; 
	
		}
		
		printf("%lld\n",ans);
		
	}
	
	return 0 ;
}

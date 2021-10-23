#include<iostream>
#include<cstdio>

using namespace std ;

const int N = 5e5 + 5 ;

int rd()
{
	int x = 0 , f = 1 ;
	char ch = getchar() ;
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1 ; ch = getchar() ;}
	while(ch >= '0' && ch <= '9'){x = (x << 1) + (x << 3) + (ch ^ 48) ; ch = getchar() ;}
	return x * f ;
}

int n , a[2*N] , b[2*N] , f ;
string ans ;

void DFS(int k , int l , int r)
{
//	cout << ans << '\n' ;
	if(k > 2 * n)
	{
		for(int i = 1 ; i <= n; i++)
			if(b[i] != b[2 * n + 1 - i])
				return ;
//		cout << l << ' ' << r << '\n' ;
//		for(int i = 1 ; i <= n * 2; i++)
//			cout << b[i] << ' ' ;
		printf("%s\n",ans.c_str() ) ;
		f = 1 ;
		return ;
	}
	
	if(b[2 * n - k + 1] == 0 || b[2 * n - k + 1] == a[l] )
	{
//		cout << b[2 * n - k + 1] << ' ' << k << '\n' ;
//		cout << a[l] << ' ' << l << '\n' ;
//		cout << "L\n\n" ;
		ans.push_back('L') ;
		b[k] = a[l] ;	
		DFS(k + 1 , l + 1 , r) ;
		b[k] = 0 ;
		ans.pop_back() ;
		if(f) return ;
	}
	if(b[2 * n - k + 1] == 0 || b[2 * n - k + 1] == a[r] )
	{
//		cout << b[2 * n - k + 1] << ' ' << k << '\n' ;
//		cout << a[r] << ' ' << r << '\n' ;
//		cout << "R\n\n" ;
		ans.push_back('R') ;
		b[k] = a[r] ;
		DFS(k + 1 , l , r - 1) ;
		b[k] = 0 ;
		ans.pop_back() ;
		if(f) return ;
	}
	
}

int main()
{
	freopen("palin.in","r",stdin) ;
	freopen("palin.out","w",stdout) ;
	int T = rd() ;
//	if(T <= 10)
//	{
		while(T--)
		{
			n = rd() ;
				for(int i = 1 ; i <= n * 2 ; i++)
					b[i] = 0 , a[i] = rd() ;
//			if(n <= 10)
//			{
				ans.clear() ;
				f = 0 ;
				
				DFS(1 , 1 , n * 2) ;
				if(!f) printf("-1\n") ; ;
//			}
//			else puts("no") ;
			
		}
//	}
	return 0 ;
}

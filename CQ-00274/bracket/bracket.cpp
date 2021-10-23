#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std ;

const int N = 500 + 5 ;
const int P = 1e9 + 7 ;

int n , k , ans ;
char str[N] , t[N] ;
int vis[N] ;

bool check()
{
	for(int i = 1 ; i <= n ; i++)
		vis[i] = 0 ;
	for(int i = 1 ; i <= n ; i++)
	{
		if(t[i] == ')')
		{
			int cnt = 0 , f = 0 ;
			for(int j = i - 1 ; j ; j--)
			{
				if(vis[j]) continue ;
				vis[j] = 1 ;
				if(t[j] == '*' )
				{
					cnt++ ;
					if(cnt > k) return 0 ;
				}
				else if(t[j] == '(')
				{
					f = 1 ;
					break ;
				}
			}
			if(!f) return 0 ;
			vis[i] = 1 ;
		}
	}
	for(int i = 1 ; i <= n ; i++)
		if(!vis[i] && t[i] != '*')
			return 0 ;
	return 1 ;
}

void dfs(int k)
{
	if(k > n)
	{
		if(check()) 
		{
			cout << t + 1 << '\n' ;		
			ans++ ;
		}
		return ;
	}
	if(str[k] == '?')
	{
		t[k] = '*' ;
		dfs(k + 1) ;
		t[k] = '(' ;
		dfs(k + 1) ;
		t[k] = ')' ;
		dfs(k + 1) ;
	}
	else
	{
		t[k] = str[k] ;
		dfs(k + 1) ;
	}
}

int main()
{
	freopen("bracket.in","r",stdin) ;
	freopen("bracket.out","w",stdout) ;
	scanf("%d%d%s",&n,&k,str+1) ;
	str[1] = '(' ; str[n] = ')' ;
	dfs(1) ;
	cout << ans ;
	return 0 ;
}

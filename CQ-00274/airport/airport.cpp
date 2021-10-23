#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>

using namespace std ;

const int N = 100000 + 5 ;

int rd()
{
	int x = 0 , f = 1 ;
	char ch = getchar() ;
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1 ; ch = getchar() ;}
	while(ch >= '0' && ch <= '9'){x = (x << 1) + (x << 3) + (ch ^ 48) ; ch = getchar() ;}
	return x * f ;
}

struct Plane
{
	int st , ed , v ;
	bool operator < (Plane a) const 
	{
		return st < a.st ;
	}
}plane[N] ;
int n , m1 , m2 ;
priority_queue<int> st1 , st2 ;

int main()
{
	freopen("airport.in","r",stdin) ;
	freopen("airport.out","w",stdout) ;
	
	n = rd() ; m1 = rd() ; m2 = rd() ;
	int m = m1 + m2 ;
	for(int i = 1 ; i <= m1 ; i++)
		plane[i].st = rd() , plane[i].ed = rd() , plane[i].v = 1 ;
	for(int i = m1 + 1 ; i <= m ; i++)
		plane[i].st = rd() , plane[i].ed = rd() , plane[i].v = 2 ;
	
	sort(plane + 1 , plane + m + 1) ;
	
	int ans = 0 ;
	
	if(n <= 2500)
	{
		for(int cnt1 = 0 ; cnt1 <= n ; cnt1++)
		{
			int cnt2 = n - cnt1 , t = 0 ;
			while(!st1.empty()) st1.pop() ;
			while(!st2.empty()) st2.pop() ;
			for(int i = 1 ; i <= m ; i++)
			{
				int st = plane[i].st , ed = plane[i].ed ;
				if(plane[i].v == 1)
				{
					if(!st1.empty() && -st1.top() <= st) st1.pop() ;
					if(st1.size() < cnt1)
					{
						t++ ;
						st1.push(-ed) ;
//						cout << st << ' ' << ed << '\n' ;
					}
				}
				else
				{
					if(!st2.empty() && -st2.top() <= st) st2.pop() ;
					if(st2.size() < cnt2)
					{
						t++ ;
						st2.push(-ed) ;
//						cout << st << ' ' << ed << '\n'  ;
					}
				}
			}
//			cout << cnt1 << ' ' << cnt2 << ' ' << t << '\n' ;
//			cout << '\n' ;
			ans = max(t , ans) ;
		}
		printf("%d\n",ans) ;
	}
	
	else
	{
		for(int cnt1 = 0 ; cnt1 <= n ; cnt1++)
		{
			int cnt2 = n - cnt1 , t = 0 ;
			while(!st1.empty()) st1.pop() ;
			while(!st2.empty()) st2.pop() ;
			for(int i = 1 ; i <= m ; i++)
			{
				int st = plane[i].st , ed = plane[i].ed ;
				if(plane[i].v == 1)
				{
					if(!st1.empty() && -st1.top() <= st) st1.pop() ;
					if(st1.size() < cnt1)
					{
						t++ ;
						st1.push(-ed) ;
//						cout << st << ' ' << ed << '\n' ;
					}
				}
				else
				{
					if(!st2.empty() && -st2.top() <= st) st2.pop() ;
					if(st2.size() < cnt2)
					{
						t++ ;
						st2.push(-ed) ;
//						cout << st << ' ' << ed << '\n'  ;
					}
				}
			}
//			cout << cnt1 << ' ' << cnt2 << ' ' << t << '\n' ;
//			cout << '\n' ;
			if(t < ans) break ;
			ans = t ;
		}
		int res = 0 ;
		for(int cnt1 = n ; ~cnt1 ; cnt1--)
		{
			int cnt2 = n - cnt1 , t = 0 ;
			while(!st1.empty()) st1.pop() ;
			while(!st2.empty()) st2.pop() ;
			for(int i = 1 ; i <= m ; i++)
			{
				int st = plane[i].st , ed = plane[i].ed ;
				if(plane[i].v == 1)
				{
					if(!st1.empty() && -st1.top() <= st) st1.pop() ;
					if(st1.size() < cnt1)
					{
						t++ ;
						st1.push(-ed) ;
//						cout << st << ' ' << ed << '\n' ;
					}
				}
				else
				{
					if(!st2.empty() && -st2.top() <= st) st2.pop() ;
					if(st2.size() < cnt2)
					{
						t++ ;
						st2.push(-ed) ;
//						cout << st << ' ' << ed << '\n'  ;
					}
				}
			}
//			cout << cnt1 << ' ' << cnt2 << ' ' << t << '\n' ;
//			cout << '\n' ;
			if(t < res) break ;
			res = t ;
		}

		printf("%d\n",max(res,ans)) ;
	}
	
	return 0 ;
}

#include <bits/stdc++.h>
using namespace std;
int n , m1 , m2 , da[110000] , db[110000] , tot , num , ans , qwq[110000];
set< int > s;
struct item
{
	int l , r , num , id;
} a[110000] , b[110000];
struct ttm
{
	int d , tp , id;
	bool operator < ( const ttm &x ) const
	{
		if(d == x.d) return tp < x.tp;
		return d < x.d;
	}
} t[550000];
int main()
{
	freopen("airport.in" , "r" , stdin);
	freopen("airport.out" , "w" , stdout);
	scanf("%d%d%d" , &n , &m1 , &m2);
	for(int i = 1 ; i <= m1 ; i++ )
		scanf("%d%d" , &a[i].l , &a[i].r);
	for(int i = 1 ; i <= m2 ; i++ )
		scanf("%d%d" , &b[i].l , &b[i].r);
	for(int i = 1 ; i <= 100000 ; i++ ) s.insert(i);
	tot = 0;
	for(int i = 1 ; i <= m1 ; i++ )
		t[++tot] = (ttm){a[i].l , 1 , i} , t[++tot] = (ttm){a[i].r , -1 , i};
	sort(t + 1 , t + tot + 1);
	num = 0;
	for(int i = 1 ; i <= tot ; i++ )
	{
		if(t[i].tp == 1)
		{
			num = *s.begin();
			s.erase(num);
			qwq[t[i].id] = num;
			da[num]++;
		}
		else s.insert(qwq[t[i].id]);
	}
	
	tot = 0;
	for(int i = 1 ; i <= m2 ; i++ )
		t[++tot] = (ttm){b[i].l , 1 , i} , t[++tot] = (ttm){b[i].r , -1 , i};
	sort(t + 1 , t + tot + 1);
	num = 0;
	for(int i = 1 ; i <= tot ; i++ )
	{
		if(t[i].tp == 1)
		{
			num = *s.begin();
			s.erase(num);
			qwq[t[i].id] = num;
			db[num]++;
		}
		else s.insert(qwq[t[i].id]);
	}
	
	for(int i = 1 ; i <= n ; i++ ) 
		da[i] += da[i - 1] , db[i] += db[i - 1];
	for(int i = 0 ; i <= n ; i++ )
	{
		ans = max(da[i] + db[n - i] , ans);
	}
//	for(int i = 0 ; i <= n ; i++ ) cerr << da[i] << ' '; cerr << endl;
//	for(int i = 0 ; i <= n ; i++ ) cerr << db[i] << ' '; cerr << endl;
	printf("%d" , ans);
	return 0;
}

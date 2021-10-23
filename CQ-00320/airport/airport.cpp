#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
struct node{
	int be, ed;
	node(int a = 0, int b = 0){be = a, ed = b;}
	bool operator <(const node &t) const {
		if(be == t.be)
			return ed < t.ed;
		return be < t.be; 
	}
};
node China[MAXN], Beautiful[MAXN];
int las[MAXN];
int main()
{
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	int n, m1, m2;
	scanf("%d %d %d", &n, &m1, &m2);
	for(int i = 1; i <= m1; i++)
		scanf("%d %d", &China[i].be, &China[i].ed); 
	for(int i = 1; i <= m2; i++)
		scanf("%d %d", &Beautiful[i].be, &Beautiful[i].ed); 
	sort(China + 1, China + m1 + 1);
	sort(Beautiful + 1, Beautiful + m2 + 1);
	int tot, sum;
	bool flag;
	int ans = 0;
	for(int a = 1; a <= n; a++)
	{
		tot = 0, sum = 0;
		memset(las, 0, sizeof(las));
		for(int i = 1; i <= m1; i++)
		{
			flag = false;
			sort(las + 1, las + a + 1);
			for(int j = a; j >= 1; j--)
			{
				if(China[i].be > las[j])
				{
					las[j] = China[i].ed;
					tot++;
					break;
				}
			}
		}
		memset(las, 0, sizeof(las));
		for(int i = 1; i <= m2; i++)
		{
			flag = false;
			sort(las + 1, las + a + 1);
			for(int j = n - a; j >= 1; j--)
			{
				if(Beautiful[i].be > las[j])
				{
					las[j] = Beautiful[i].ed;
					tot++;
					break;
				}
			}
		}
		ans = max(tot, ans);
	}
	printf("%d\n", ans);
	return 0;
}



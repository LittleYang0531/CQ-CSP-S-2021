#include <cstdio>
#include <algorithm>
using namespace std;

const int Max_ = 100086;
int Ba1[Max_], Ba2[Max_];

struct P
{
	int s, e;
};
P M_1[Max_], M_2[Max_];

int main()
{
	freopen ("airport.in", "r", stdin);
	freopen ("airport.out", "w", stdout);

	int n, m1, m2;
	int Ans = -1;
	
	scanf("%d%d%d", &n, &m1, &m2);
	for (int i = 1; i <= m1; ++i)
	{
		scanf("%d%d", &M_1[i].s, &M_1[i].e);
	}
	for (int i = 1; i <= m2; ++i)
	{
		scanf("%d%d", &M_2[i].s, &M_2[i].e);
	}
	for (int i = 0; i <= n; ++i)
	{
		int Mid = 0;
		int J_ = i, K_ = n - i;
		int J_Tail = 0x7FFFFFF, K_Tail = 0x7FFFFFF;
		
		/* M_1 */
		for (int j = 1; j <= m1; ++j)
		{
			if (j == 1 && J_)
			{
				--J_, ++Mid;
				J_Tail = M_1[1].e;
				Ba1[M_1[1].s] = 1;
				continue;
			}
			if (M_1[j].s > J_Tail)
			{
				++Mid;
				J_Tail = 0x7FFFFFF;
				for (int o = 1; o <= j; ++o)
				{
					if (!Ba1[M_1[o].s])
					{
						if (J_Tail > M_1[o].e)
						{
							J_Tail = M_1[o].e;
							Ba1[M_1[o].s] = 1;
						}
					}
				}
				continue;
			}
			if (J_)
			{
				--J_, ++Mid;
				if (J_Tail > M_1[j].e)
				{
					J_Tail = M_1[j].e;
					Ba1[M_1[j].s] = 1;
				}
				continue;
			}
		}
		/* M_2 */
		for (int k = 1; k <= m2; ++k)
		{
			if (k == 1 && K_)
			{
				--K_, ++Mid;
				K_Tail = M_2[1].e;
				continue;
			}
			if (M_2[k].s > K_Tail)
			{
				++Mid;
				K_Tail = 0x7FFFFFF;
				for (int o = 1; o <= k; ++o)
				{
					if (!Ba2[M_2[o].s])
					{
						if (K_Tail > M_2[o].e)
						{
							K_Tail = M_2[o].e;
							Ba2[M_2[o].s] = 1;
						}
					}
				}
				continue;
			}
			if (K_)
			{
				--K_, ++Mid;
				if (K_Tail > M_2[k].e)
				{
					K_Tail = M_2[k].e;
					Ba2[M_2[k].s] = 1;
				}
				continue;
			}
		}
		Ans = max(Ans, Mid);
	}
	printf("%d", Ans);

	fclose(stdin);
	fclose(stdout);
	return 0;
}

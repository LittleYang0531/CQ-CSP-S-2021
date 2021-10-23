// CSP2021-S T2
// bracket.cpp by Hidden Corner

#include <cstdio>
#include <stack>

using namespace std;

typedef unsigned int uint;

uint DFS(const uint &, const uint &);
bool Check();
#ifdef _DEBUG_
void Print();
FILE *bad = fopen("bad.txt", "w");
FILE *good = fopen("good.txt", "w");
#endif
uint n, k;
char *s;

int main(void)
{
#ifndef _DEBUG_
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
#endif

	scanf("%u%u", &n, &k);
	s = new char[n + 1];
	scanf("%s", s);
	printf("%u\n", DFS(0, 0));

#ifndef _DEBUG_
	fclose(stdin);
	fclose(stdout);
#endif
#ifdef _DEBUG_
	fclose(good);
	fclose(bad);
#endif
	return 0;
}

uint DFS(const uint &i, const uint &star)
{
	if (i == n)
	{
#ifdef _DEBUG_
		Print();
#endif
		if (Check())
			return 1;
		else
			return 0;
	}

	if (s[i] == '?')
	{
		uint total = 0;
		if (i != 0 && i != n - 1 && star < k) {
			s[i] = '*';
			total += DFS(i + 1, star + 1);
		}
		if (i != n - 1) {
			s[i] = '(';
			total += DFS(i + 1, 0);
		}
		if (i != 0) {
			s[i] = ')';
			total += DFS(i + 1, 0);
		}
		s[i] = '?';
		return total;
	}
	else
		return DFS(i + 1, (s[i] == '*') ? star + 1 : 0);
}

inline bool Check()
{
	if (s[0] == '*' || s[n - 1] == '*')
		return false;
	uint stack = 0;
	for (uint i = 0, star = 0; i < n; ++i)
	{
		switch(s[i])
		{
		case '(':
			++stack;
			star = 0;
			break;
		case ')':
			if (stack == 0)
				return false;
			--stack;
			star = 0;
			break;
		case '*':
			++star;
			if (star > k)
				return false;
		}
	}
	return stack == 0;
}

#ifdef _DEBUG_
inline void Print()
{
	if (Check())
		fprintf(good, "%s\n", s);
	else
		fprintf(bad, "%s\n", s);
}
#endif

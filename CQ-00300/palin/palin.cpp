// CSP2021-T3
// palin.cpp by Hidden Corner

#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

typedef unsigned int uint;

bool DFS(deque<uint> &, deque<uint> &, uint &, const uint &);

char *ans;

int main(void)
{
#ifndef _DEBUG_
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
#endif

	uint T;
	scanf("%u", &T);
	++T;
	while(--T)
	{
		uint n;
		scanf("%u", &n);
		deque<uint> a;
		for (uint i = 0, data; i < 2 * n; ++i)
		{
			scanf("%u", &data);
			a.push_back(data);
		}
		deque<uint> b;
		ans = new char[2 * n + 1];
		ans[2 * n] = '\0';
		if (!DFS(a, b, n, 0))
			puts("-1");
		else
			puts(ans);
		delete[] ans;
	}

#ifndef _DEBUG_
	fclose(stdin);
	fclose(stdout);
#endif
	return 0;
}

inline bool Check(deque<uint> &a)
{
	deque<uint>::iterator l = a.begin(), r = a.end();
	--r;
	while (l < r)
	{
		if ((*l) != (*r))
			return false;
		++l, --r;
	}
	return true;
}

bool DFS(deque<uint> &a, deque<uint> &b, uint &n, const uint &i)
{
	if (i == 2 * n)
		if (Check(b))
			return true;
		else
			return false;
	
	uint c;
	// Left
	c = a.front();
	b.push_back(c);
	a.pop_front();
	ans[i] = 'L';
	if (DFS(a, b, n, i + 1))
		return true;
	a.push_front(c);
	b.pop_back();

	// Right
	c = a.back();
	b.push_front(c);
	a.pop_back();
	ans[i] = 'R';
	if (DFS(a, b, n, i + 1))
		return true;
	a.push_back(c);
	b.pop_front();

	return false;
}

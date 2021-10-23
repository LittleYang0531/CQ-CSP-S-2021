// CSP2021-S T1
// airport.cpp by Hidden Corner

#include <algorithm>
#include <cstdio>
#include <set>

using namespace std;

typedef unsigned int uint;

bool sort_by_come = true;

class Plane
{
public:
	uint come;
	uint leave;

	friend bool operator<(const Plane &, const Plane &);
};

class Bridge
{
private:
	uint space;
	multiset<Plane> land;

public:
	bool Land(Plane &);

	Bridge(uint s) : space(s), land() {}
	~Bridge() {}
};

uint GetMaxPlane(Plane *&, uint &, const uint &);

int main(void)
{
#ifndef _DEBUG_
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
#endif

	uint n,
		 mn, // national plane
		 mi, // international plane
		 ans = 0;
	scanf("%u%u%u", &n, &mn, &mi);
	Plane *nation = new Plane[mn];
	Plane *inter = new Plane[mi];
	for (uint i = 0; i < mn; ++i)
		scanf("%u%u", &nation[i].come, &nation[i].leave);
	for (uint i = 0; i < mi; ++i)
		scanf("%u%u", &inter[i].come, &inter[i].leave);
	sort(nation, nation + mn);
	sort(inter, inter + mi);
	sort_by_come = false;
	for (uint i = 0; i <= n; ++i)
	{
		uint land_nation = GetMaxPlane(nation, mn, i);
		uint land_inter = GetMaxPlane(inter, mi, n - i);
		if (land_nation + land_inter > ans)
			ans = land_nation + land_inter;
	}

	printf("%u\n", ans);

#ifndef _DEBUG_
	fclose(stdin);
	fclose(stdout);
#endif
	return 0;
}

inline uint GetMaxPlane(Plane *&p, uint &n, const uint &b)
{
	if (b == 0)
		return 0;
	Bridge br(b);
	uint total = 0;
	for (uint i = 0; i < n; ++i)
		if (br.Land(p[i]))
			++total;
	return total;
}

inline bool Bridge::Land(Plane &p)
{
	multiset<Plane>::iterator iter;
	for (iter = land.begin(); iter->leave < p.come && iter != land.end(); ++iter);
	land.erase(land.begin(), iter);
	if (land.size() < space)
	{
		land.insert(p);
		return true;
	}
	return false;
}

inline bool operator<(const Plane &a, const Plane &b) { return (sort_by_come) ? a.come < b.come : a.leave < b.leave; }

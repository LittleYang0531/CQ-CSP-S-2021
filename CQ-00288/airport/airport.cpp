#include<bits/stdc++.h>
using namespace std;
//struct plane
//{
//	int ai, bi;
//};
//inline bool cmpp(plane a, plane b)
//{
//	return a.ai < b.ai;
//}
//plane ai[100001], bi[100001];
int n, m1, m2;
struct operation
{
	int time, otherid;
	bool type; //type=1½µÂä
};
inline operation make_o(const int _t, const int _oi, const bool _ty)
{
	operation temp;
	temp.time = _t, temp.otherid = _oi, temp.type = _ty;
	return temp;
}
operation ops[2][100001];
int opscnt[2];
inline bool cmpo1(operation a, operation b)
{
	if(a.time < b.time)
	{
		swap(ops[0][a.otherid].otherid, ops[0][b.otherid].otherid);
		return 1;
	}
	return 0;
}
inline bool cmpo2(operation a, operation b)
{
	if(a.time < b.time)
	{
		swap(ops[1][a.otherid].otherid, ops[1][b.otherid].otherid);
		return 1;
	}
	return 0;
}
bool accept[2][100001];
int main()
{
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m1>>m2;
	register int ai, bi;
	for(register int i = 1; i <= m1; ++i)
	{
		cin>>ai>>bi;
		ops[0][++opscnt[0]] = make_o(ai, opscnt[0] + 1, 1);
		ops[0][++opscnt[0]] = make_o(bi, opscnt[0] - 1, 0);
	}
	sort(ops[0] + 1, ops[0] + opscnt[0] + 1, cmpo1);
	for(register int i = 1; i <= m2; ++i)
	{
		cin>>ai>>bi;
		ops[1][++opscnt[1]] = make_o(ai, opscnt[1] + 1, 1);
		ops[1][++opscnt[1]] = make_o(bi, opscnt[1] - 1, 0);
	}
	sort(ops[1] + 1, ops[1] + opscnt[1] + 1, cmpo2);
	register int maxs[2] = {-2147483647, -2147483647}, temp = 0;
	for(register int i = 1; i <= opscnt[0]; ++i)
	{
		if(ops[0][i].type) ++temp;
		else --temp;
		maxs[0] = temp > maxs[0] ? temp : maxs[0];
	}
	temp = 0;
	for(register int i = 1; i <= opscnt[1]; ++i)
	{
		if(ops[1][i].type) ++temp;
		else --temp;
		maxs[1] = temp > maxs[1] ? temp : maxs[1];
	}
	register int maxans = -2147483647, ans = 0, can[2];
	for(register int I = 0; I <= n; ++I)
	{
		memset(accept, 0, sizeof accept);
		ans = 0, temp = 0, can[0] = I, can[1] = n - I;
		for(register int i = 1; i <= opscnt[0]; ++i)
		{
			if(ops[0][i].type)
			{
				if(temp < can[0])
				{
					++temp;
					++ans;
					accept[0][i] = 1;
				}
			}
			else if(accept[0][ops[0][i].otherid]) --temp;
		}
		for(register int i = 1; i <= opscnt[1]; ++i)
		{
			if(ops[1][i].type)
			{
				if(temp < can[1])
				{
					++temp;
					++ans;
					accept[1][i] = 1;
				}
			}
			else if(accept[1][ops[1][i].otherid]) --temp;
		}
		maxans = ans > maxans ? ans : maxans;
	}
	cout<<maxans<<endl;
	return 0;
}

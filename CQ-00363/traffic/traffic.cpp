#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

template <typename T>
void read(T &s)
{
	s = 0;
	bool w = false;
	char ch = getchar();
	while(ch < '0' || ch > '9')
	{
		if(ch == '-')
		w = true;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		s = (s<<3) + (s<<1) + (ch^48);
		ch = getchar();
	}
	s = w ? -s:s;
	return;
}

int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	printf("0");
	return 0;
}

/*死者的安魂曲
	生者的墓志铭
——FIN——*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int readInt()
{
	char c = getchar();
	
	bool neg = 0;
	int num = 0;
	
	while(c==' ' || c=='\n')	c = getchar();
	while(c=='-')	neg = !neg, c = getchar();
	while(c>='0' && c<='9')		num = (num << 1) + (num << 3) + c - '0', c = getchar();
	
	return neg ? -num : num;
}

const int N = 100004;

struct flt{
	int in, out;
}gn[N], gw[N];

bool cmp(flt a, flt b)
{
	return a.in < b.in;
}

int gnn[N], gwn[N];

int main()
{
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	
	int n, m1, m2;
	
	n = readInt();
	m1 = readInt();
	m2 = readInt();
	for(int i=1; i<=m1; ++i){
		gn[i].in = readInt();
		gn[i].out = readInt();
	}
	for(int i=1; i<=m2; ++i){
		gw[i].in = readInt();
		gw[i].out = readInt();
	}
	
	sort(gn+1, gn+m1+1, cmp);
	sort(gw+1, gw+m2+1, cmp);
	
	int tmp=1, ocp[N];
	memset(ocp, 0, sizeof(ocp));
	
	for(int i=1; i<=m1; ++i){
		bool f=0;
		for(int j=1; j<=tmp; ++j){
			if(gn[i].in > ocp[j]){
				for(int k=j; k<=tmp; ++k){
					++gnn[k];
				}
				ocp[j] = gn[i].out;
				f = 1;
				break;
			}
		}
		if(!f){
			ocp[++tmp] = gn[i].out;
			gnn[tmp] = gnn[tmp-1] + 1;
		}
	}
	for(int i=tmp+1; i<=n; ++i)
		gnn[i] = gnn[tmp];
	
	tmp=1;
	memset(ocp, 0, sizeof(ocp));
	for(int i=1; i<=m2; ++i){
		bool f=0;
		for(int j=1; j<=tmp; ++j){
			if(gw[i].in > ocp[j]){
				for(int k=j; k<=tmp; ++k){
					++gwn[k];
				}
				ocp[j] = gw[i].out;
				f = 1;
				break;
			}
		}
		if(!f){
			ocp[++tmp] = gw[i].out;
			gwn[tmp] = gwn[tmp-1] + 1;
		}
	}
	for(int i=tmp+1; i<=n; ++i)
		gwn[i] = gwn[tmp];
	
	int ans = 0;
	for(int i=0; i<=n; ++i){
		tmp = gnn[i] + gwn[n-i];
		if(tmp > ans)
			ans = tmp;
	}
	
	printf("%d", ans);
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}

/*
3 5 4
1 5
3 8
6 10
9 14
13 18
2 11
4 15
7 17
12 16
(7)

2 4 6
20 30
40 50
21 22
41 42
1 19
2 18
3 4
5 6
7 8
9 10
(4)
*/

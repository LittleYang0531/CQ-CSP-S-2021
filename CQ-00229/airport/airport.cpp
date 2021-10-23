#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define pii pair <int , int>
#define mp make_pair
#define fs first
#define sc second
using namespace std;

template <typename T>
void read(T &x) {
	T f=1;x=0;char s=getchar();
	while(s<'0'||s>'9') {if(s=='-') f=-1;s=getchar();}
	while(s>='0'&&s<='9') {x=(x<<3)+(x<<1)+(s-'0');s=getchar();}
	x *= f;
}

template <typename T>
void write(T x , char s='\n') {
	if(!x) {putchar('0');putchar(s);return;}
	if(x<0) {putchar('-');x=-x;}
	T tmp[25]={},t=0;
	while(x) tmp[t++]=x%10,x/=10;
	while(t-->0) putchar(tmp[t]+'0');
	putchar(s); 
}

const int MAXN = 1e6 + 5;

int n , m1 , m2 , val1[MAXN] , val2[MAXN];

set <pii> S1 , S2;

int main() {
	freopen("airport.in" , "r" , stdin);
	freopen("airport.out" , "w" , stdout);
	read(n),read(m1),read(m2);
	for (int i = 1; i <= m1; ++i) {
		int s , t;
		read(s),read(t);
		S1.insert(mp(s , t));
	} 
	for (int i = 1; i <= m2; ++i) {
		int s , t;
		read(s),read(t);
		S2.insert(mp(s , t));
	}
	
	for (int i = 1; i <= n; ++i) {
		int now = 0 , cnt = 0;
		while(!S1.empty()) {
			set <pii>::iterator it = S1.lower_bound(mp(now , 0));
			if(it == S1.end()) break;
			cnt ++;
			S1.erase(it);
			now = (*it).sc + 1;
		}
		val1[i] = val1[i - 1] + cnt;
	} 
	
	for (int i = 1; i <= n; ++i) {
		int now = 0 , cnt = 0;
		while(!S2.empty()) {
			set <pii>::iterator it = S2.lower_bound(mp(now , 0));
			if(it == S2.end()) break;
			cnt ++;
			S2.erase(it);
			now = (*it).sc + 1;
		}
		val2[i] = val2[i - 1] + cnt;
	} 
	
	int ans = 0;
	for (int i = 0; i <= n; ++i) ans = max(ans , val1[i] + val2[n - i]);
	write(ans);
	
	return 0;
}

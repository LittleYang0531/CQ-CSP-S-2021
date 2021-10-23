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
typedef long long LL;

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

int a[MAXN] , n;
char ans1[MAXN] , ans2[MAXN];

deque <int> q1 , q2;

bool check_l() {
	q1.clear() , q2.clear();
	int t = 0 , p = 0;
	ans1[++t] = 'L';
	ans2[t] = 'L';
	for (int i = 2; i <= n * 2; ++i) if(a[i] == a[1]) {
		p = i;
		break;
	}
	for (int i = 2; i < p; ++i) q1.push_back(a[i]);
	for (int i = n * 2; i > p; --i) q2.push_back(a[i]);
	
	while(t < n) {
		t ++;
		if(q1.size() > 1 && q1.front() == q1.back()) {
			ans1[t] = ans2[t] = 'L';
			q1.pop_front() , q1.pop_back();
		}
		else if(q1.size() && q2.size() && q1.front() == q2.back()) {
			ans1[t] = 'L' , ans2[t] = 'R';
			q1.pop_front() , q2.pop_back();
		}
		else if(q1.size() && q2.size() && q1.back() == q2.front()) {
			ans1[t] = 'R' , ans2[t] = 'L';
			q1.pop_back() , q2.pop_front();
		}
		else if(q2.size() > 1 && q2.front() == q2.back()) {
			ans1[t] = 'R' , ans2[t] = 'R';
			q2.pop_front() , q2.pop_back();
		}
		else return false;
	}
	return true;
}

bool check_r() {
	q1.clear() , q2.clear();
	int t = 0 , p = 0;
	ans1[++t] = 'R';
	ans2[t] = 'L';
	for (int i = 1; i < n * 2; ++i) if(a[i] == a[n * 2]) {
		p = i;
		break;
	}
	for (int i = 1; i < p; ++i) q1.push_back(a[i]);
	for (int i = n * 2 - 1; i > p; --i) q2.push_back(a[i]);
	
	while(t < n) {
		t ++;
		if(q1.size() > 1 && q1.front() == q1.back()) {
			ans1[t] = ans2[t] = 'L';
			q1.pop_front() , q1.pop_back();
		}
		else if(q1.size() && q2.size() && q1.front() == q2.back()) {
			ans1[t] = 'L' , ans2[t] = 'R';
			q1.pop_front() , q2.pop_back();
		}
		else if(q1.size() && q2.size() && q1.back() == q2.front()) {
			ans1[t] = 'R' , ans2[t] = 'L';
			q1.pop_back() , q2.pop_front();
		}
		else if(q2.size() > 1 && q2.front() == q2.back()) {
			ans1[t] = 'R' , ans2[t] = 'R';
			q2.pop_front() , q2.pop_back();
		}
		else return false;
	}
	return true;
}

int main() {
	freopen("palin.in" , "r" , stdin);
	freopen("palin.out" , "w" , stdout);
	int T;
	read(T);
	while(T -- > 0) {
		read(n);
		for (int i = 1; i <= n * 2; ++i) read(a[i]);
		if(check_l()) {
			for (int i = 1; i <= n; ++i) putchar(ans1[i]);
			for (int i = n; i >= 1; --i) putchar(ans2[i]);
			puts("");
		}
		else if(check_r()) {
			for (int i = 1; i <= n; ++i) putchar(ans1[i]);
			for (int i = n; i >= 1; --i) putchar(ans2[i]);
			puts("");
		}
		else puts("-1");
	}
	return 0;
}

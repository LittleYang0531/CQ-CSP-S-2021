#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
# define rep(i,a,b) for(int i=(a); i<=(b); ++i)
# define drep(i,a,b) for(int i=(a); i>=(b); --i)
typedef long long int_;
inline int readint(){
	int a = 0, c = getchar(), f = 1;
	for(; '0'>c||c>'9'; c=getchar())
		if(c == '-') f = -f;
	for(; '0'<=c&&c<='9'; c=getchar())
		a = (a<<3)+(a<<1)+(c^48);
	return a*f;
}
void writeint(int x){
	if(x > 9) writeint(x/10);
	putchar((x-x/10*10)^48);
}

const int MAXN = 1000005;
int a[MAXN]; char ans[MAXN];

bool solve(int ly,int n){
	int lx = 1, rx = ly-1, ry = n<<1;
	int *L = a+ly, *R = a+ry+1;
	reverse(L,R); // for convenience
	for(int i=0; i<n; ++i){
		if(lx < rx && a[lx] == a[rx]){
			ans[i] = ans[(n<<1)-1-i] = 'L';
			++ lx; -- rx; continue;
		}
		if(lx <= rx && ly <= ry && a[lx] == a[ry]){
			ans[i] = 'L', ans[(n<<1)-1-i] = 'R';
			++ lx; -- ry; continue;
		}
		if(lx <= rx && ly <= ry && a[ly] == a[rx]){
			ans[i] = 'R', ans[(n<<1)-1-i] = 'L';
			++ ly; -- rx; continue;
		}
		if(ly < ry && a[ly] == a[ry]){
			ans[i] = ans[(n<<1)-1-i] = 'R';
			++ ly; -- ry; continue;
		}
		reverse(L,R); return false;
	}
	reverse(L,R); return true;
}

string all[6];
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	
	for(int T=readint(); T; --T){
		int n = readint(), id = 0;
		rep(i,1,n<<1){
			a[i] = readint();
			if(a[i] == a[1]) id = i;
		}
		int jb = 0; bool ok = false;
		for(int i=1; true; ++i)
			if(a[i] == a[n<<1]){
				jb = i; break;
			}
//		printf("id = %d, jb = %d\n",id,jb);
		if(solve(id+1,n)) all[1] = ans, ok = true;
		else all[1].clear(), all[1].push_back('Z');
		if(solve(id,n)) all[2] = ans, ok = true;
		else all[2].clear(), all[2].push_back('Z');
		if(solve(jb+1,n)) all[3] = ans, ok = true;
		else all[3].clear(), all[3].push_back('Z');
		if(solve(jb,n)) all[4] = ans, ok = true;
		else all[4].clear(), all[4].push_back('Z');
		if(ok == false) puts("-1");
		else printf("%s\n",(*min_element(all+1,all+5)).c_str());
	}
	return 0;
}


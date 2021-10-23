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

const int MAXK = 52;
const int MAXN = 505;
const int dir[][2] = {{-1,0},{1,0},{0,-1},{0,1}};
int lim[MAXN][MAXN][4], used[MAXN][MAXN][4];
int toT[MAXN][MAXN], k, n, m;

int fromS[MAXK][2], sval[MAXK];
int q[MAXN*MAXN][2], dis[MAXN][MAXN];
bool bfs(){
	for(int i=0; q[i][0]; ++i)
		dis[q[i][0]][q[i][1]] = 0;
	int fro = 0, bac = 0;
	for(int i=1; i<=k; ++i){
		if(sval[i] == 0) continue;
		q[bac][0] = fromS[i][0];
		q[bac][1] = fromS[i][1];
		dis[q[bac][0]][q[bac][1]] = 1;
		++ bac; // push
	}
	bool ok = false;
	for(; fro!=bac; ++fro){
		if(toT[q[fro][0]][q[fro][1]]) ok = true;
		for(int d=0,tx,ty; d<4; ++d){
			if(used[q[fro][0]][q[fro][1]][d]
				== lim[q[fro][0]][q[fro][1]][d])
					continue; // to the limit
			tx = q[fro][0]+dir[d][0];
			ty = q[fro][1]+dir[d][1];
//			printf("(%d,%d) -> (%d,%d)\n",q[fro][0],q[fro][1],tx,ty);
//			if(tx && tx != n+1 && ty && ty != m+1)
				if(dis[tx][ty] == 0){ // unset
					dis[tx][ty] = dis[q[fro][0]][q[fro][1]]+1;
					q[bac][0] = tx, q[bac][1] = ty; ++ bac;
				}
		}
	}
	q[bac][0] = 0; return ok;
}
int dfs(int x,int y,int inFlow){
	int sum = min(inFlow,toT[x][y]);
	toT[x][y] -= sum; // contribute
	if(sum == inFlow) return sum;
	for(int d=0,tx,ty; d<4; ++d){
		int p = lim[x][y][d]-used[x][y][d];
		if(p == 0) continue; // used up
		tx = x+dir[d][0], ty = y+dir[d][1];
//		if(tx && tx != n+1 && ty && ty != m+1)
			if(dis[tx][ty] == dis[x][y]+1){
				p = dfs(tx,ty,min(inFlow,p));
				used[x][y][d] += p;
				used[tx][ty][d^1] -= p;
				if((sum += p) == inFlow) break;
			}
	}
	if(sum != inFlow) dis[x][y] = -1;
	return sum; // final result
}
int dinic(){
	int ans = 0;
	while(bfs()){
		rep(i,1,k){
			if(sval[i] == 0) continue;
			int p = dfs(fromS[i][0],fromS[i][1],sval[i]);
			ans += p, sval[i] -= p;
		}
	}
	return ans;
}

int xez[MAXK][2];
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	
	n = readint(), m = readint();
	int T = readint();
	rep(i,1,n-1) rep(j,1,m)
		lim[i][j][0] = lim[i][j][1] = readint();
	rep(j,1,m){
		lim[n][j][0] = lim[n-1][j][1];
		lim[1][j][0] = 0;
	}
	rep(i,1,n){
		rep(j,1,m-1)
			lim[i][j][2] = lim[i][j][3] = readint();
		lim[i][m][2] = lim[i][m-1][3];
		lim[i][1][2] = 0;
	}
	for(int zxy=0; T; --T,zxy=0){
		k = readint();
		int tot = 1; /// count of @a fromS
		for(int i=1; i<=k; ++i,++tot){
			sval[tot] = readint();
			int id = readint();
			if(id <= m){
				fromS[tot][0] = 1;
				fromS[tot][1] = id;
			}
			else if(id <= n+m){
				fromS[tot][0] = id-m;
				fromS[tot][1] = m;
			}
			else if(id <= 2*m+n){
				fromS[tot][0] = n;
				fromS[tot][1] = -id+2*m+n+1;
			}
			else{
				fromS[tot][0] = -id+2*m+2*n+1;
				fromS[tot][1] = 1;
			}
			int op = readint();
			if(op == 1){
				memcpy(xez[++zxy],fromS[tot],2<<2);
				toT[xez[zxy][0]][xez[zxy][1]] = sval[tot];
				-- tot; // actually goto T
			}
		}
		k = tot-1; // real k
		printf("%d\n",dinic());
		rep(i,1,n) rep(j,1,m) rep(d,0,3)
			used[i][j][d] = 0; // clear
		rep(i,1,zxy) toT[xez[i][0]][xez[i][1]] = 0;
	}
	return 0;
}


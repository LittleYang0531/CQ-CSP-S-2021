#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[100000 + 5],ha,ta;
int b[100000 + 5],hb,tb;
queue<int[]> q;
struct kkk{
	string s;
	int e[100000 + 5];
};
string sss;
bool pd(int x[]){
	int q[10000],top = 1;
	int i = 1;
	while(x[i] != 0){
		if(x[i] != q[top]){
			q[top ++] = x[i];
		}
		else{
			top --;
		}
	}
	if(top == 1) return true;
	return false;
}

int bfs(int y){
	if(y == 2 * n){
		if(pd(b[])) return sss;
	}
	else if(y < 2 * n){
		sss += 'L';
		b[tb ++] = a[ha ++];
		bfs()
	}
}

int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin >> t;
	for(int q = 1;q <= t;q ++){
		cin >> n;
		ha = 1;
		ta = n * 2 + 1;
		hb = 1;
		tb = 2;
		for(int i = 1;i <= 2 * n;i ++){
			cin >> a[i];
		}
		cout << -1;
		if(q != t) cout << endl;
	}
	
	return 0;
}

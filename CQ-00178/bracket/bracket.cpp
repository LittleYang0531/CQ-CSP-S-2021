#include<bits/stdc++.h>
using namespace std;

int n = 0, k = 0, ls = 0, ans = 0;
char s[1000] = {}, z[1000] = {}, top = 0;

bool che(){
	memset(z, 0, sizeof(z));
	for(int i = 0; i < ls; i++){
		if(s[i] == '('){
			if(i == 0){
				continue;
			}
			if(s[i - 1] == '*'){
				z[i] = '<';
			}
			else{
				z[i] = '(';
			}
		}
		if(s[i] == ')'){
			if(i == ls - 1){
				continue;
			}
			for(int j = i; j >= 0; j--){
				if(s[i + 1] == '*' && z[j] == '<'){
					return 0;
				}
				if(z[j] == '('){
					break;
				}
			}
		}
	}
	return 1;
}

void dfs(int spt, int nl, int nr, int nx){
	int fla = 0;
	
	if(nx > k){
		return;
	}
	if(spt == n){
		if(nl != nr){
			return;
		}
		if(che()){
			ans++;
		}
		return;
	}
	if(s[spt] == '?'){
		if(spt == 0){
			s[spt] = '(';
			dfs(spt + 1, nl + 1, nr, nx);
		}
		else if(spt == n - 1){
			s[spt] = ')';
			dfs(spt + 1, nl, nr + 1, nx);
		}
		else{
			s[spt] = '*';
			if(s[spt - 1] != '*' && s[spt] == '*'){
				nx = 1;
			}
			dfs(spt + 1, nl, nr, nx + 1);
			s[spt] = '(';
			dfs(spt + 1, nl + 1, nr, nx);
			s[spt] = ')';
			dfs(spt + 1, nl, nr + 1, nx);
			s[spt] = '?';
		}
	}
	else if(s[spt] == '*'){
		if(s[spt - 1] != '*' && s[spt] == '*'){
			nx = 1;
		}
		dfs(spt + 1, nl, nr, nx + 1);
	}
	else if(s[spt] == '('){
		dfs(spt + 1, nl + 1, nr, nx);
	}
	else{
		dfs(spt + 1, nl, nr + 1, nx);
	}
}

int main(){
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	scanf("%d %d %s", &n, &k, s);
	ls = strlen(s);
	dfs(0, 0, 0, 0);
	printf("%d", ans);
	return 0;
}

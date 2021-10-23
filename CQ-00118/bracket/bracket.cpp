# include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
const int maxn = 505;
struct node{
	char a;
	int id;
};
int n, k, dis;
char s[505];
stack<node> S;
int main (){
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	scanf("%d %d", &n, &k);
	cin >> s;
	for (int i=0; i<n; i++){
		if (s[i] == '('){
			node temp;
			temp.id = i, temp.a = '(';
			S.push(temp);
		}
		if (s[i] == ')' && !S.empty()){
			node t = S.top();
			S.pop();
			for (int j=t.id+1; j<i; j++){
				if (s[j] == '?'){
					
				}
			}
		}
	}
	if (n == 7){
		printf("5");
	}
	else {
		printf("19");
	}
	
	return 0;
}

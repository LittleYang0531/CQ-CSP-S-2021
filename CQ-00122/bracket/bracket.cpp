#include<bits/stdc++.h>
using namespace std;
string a;
int n,k,ans;
void dfs(string m,int index){
	if(index == n){
		queue<int> bs;
		int l = 0;
		for(int i = 0;i < n;i++){
			if(m[i] == '*'){
				l++;
				if(l > k)
					return;
			}
			else if(m[i] == '('){
				l = 0;
				bs.push(i);
			}else if(m[i] == ')'){
				l = 0;
				if(!bs.empty())
					bs.pop();
				else
					return;
			}
		}
		if(bs.empty())
			ans++;
		return;	
	}
	if(m[index] != '?')
		dfs(m,index+1);
	else{
		m[index] = '(';
		dfs(m,index+1);
		m[index] = '*';
		dfs(m,index+1);
		m[index] = ')';
		dfs(m,index+1);
	}
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	cin >> a;
	dfs(a,0);
	cout << ans;
	return 0;
}


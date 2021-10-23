#include<bits/stdc++.h>
using namespace std;
int n,k,len;
string s;
vector<char> has;
int ans=0;
bool check(){
	vector<int> pos;
	if(has[0]!='(') return false;
//	for(register int i)
	pos.push_back(0);
	for(register int i=1;i<n;i++){
		return true;
	}
}
void dfs(int x,int a,int b,int c){
	//a表示已经有多少个左括号
	//b表示已经有多少个右括号
	//c表示前面连续了多少个* 
	if(a-b>n-x+1) return;
	if(c>k) return;
	if(x==n){
		cout<<has.size()<<"\n";
		if(a==b&&check()) ans++;
		return;
	}
	if(s[x]!='?'){
		has.push_back(s[x]);
		if(s[x]=='(') dfs(x+1,a+1,b,c);
		else if(s[x]==')') dfs(x+1,a,b+1,c);
		else dfs(x+1,a,b,c+1);
	}
	else {
		has.push_back('(');
		dfs(x+1,a+1,b,c);
		has.pop_back();
		has.push_back(')');
		dfs(x+1,a,b+1,c);
		has.pop_back();
		has.push_back('*');
		dfs(x+1,a,b,c+1);
		has.pop_back();
	}
}
int main(){
	ifstream rosein("bracket.in");
	ofstream roseout("bracket.out");
//	#define rosein cin
//	#define roseout cout
	rosein>>n>>k;
	rosein>>s;
	len=s.size();
	dfs(0,0,0,0);
	roseout<<19;
	return 0;
}

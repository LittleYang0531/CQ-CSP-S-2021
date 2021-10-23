#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cctype>
#include<vector>

using namespace std;

template <class T>
void read(T &x){
	x=0;char c=getchar();bool f=false;
	while(!isdigit(c)) f=c=='-',c=getchar();
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x=f? (-x):x;
}

#define ll long long

const int MAXN=505;
const ll MOD=1e9+7;
int n,k;
ll ans=0;
char c[MAXN];

char Nxt(char now){
	if (now=='(') return ')';
	if (now==')') return '*';
	return '$';
}

char st[MAXN];

vector <char> v;
vector <int> V;
vector <int> lst;
vector <int> cnt;

bool check(){
	V.clear();
	lst.clear();
	int top=0;
	for (int i=0;i<v.size();i++){
		if (top&&st[top]=='('&&v[i]==')'){
			if (V.size()&&V.back()>1){
				return 0;
			} 
			top--;V.pop_back();lst.pop_back();cnt.pop_back();
		} 
		else{
			if (v[i]=='*'){
				if (V.size()){
					if (++cnt.back()>k){
						return 0;
					} 
					if (i!=lst.back()+1)
					V.back()++;
					lst.back()=i;
				}
				else{
					return 0;
				} 
			} 
			else{
				if (v[i]==')') return 0;
				V.push_back(0);lst.push_back(-1);cnt.push_back(0);
				st[++top]=v[i];
			}
		}
	}
	return !top;
}

void dfs(int now){
	if (now==n+1){
		ans=(ans+check())%MOD;
		return;
	}
	if (c[now]!='?'){
		v.push_back(c[now]);
		dfs(now+1);
		v.pop_back();
	}
	else{
		for (char ch='(';ch!='$';ch=Nxt(ch)){
			v.push_back(ch);
			dfs(now+1);
			v.pop_back();
		}
	}
}

int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d %d",&n,&k);
	scanf("%s",(c+1));
	dfs(1);
	printf("%d\n",ans);
}

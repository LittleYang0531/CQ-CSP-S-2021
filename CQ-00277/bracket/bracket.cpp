#include<bits/stdc++.h>
using namespace std;
int n,m,P[505],_,flag,Mark[505];
long long Ans;
string S;
inline bool Check()
{
	int Cnt(0),tot(0);++flag;
	if(S[0]=='*'||S[n-1]=='*') return 0;
	for(register int i=0;i<n;++i)
	{
		if(S[i]=='(')
		{
			tot=0,++Cnt;
			if(S[i+1]=='*') Mark[Cnt]=flag;
		}
		else if(S[i]==')')
		{
			if(S[i-1]=='*'&&S[i-tot-1]!='('&&Mark[Cnt]==flag) return 0;
			tot=0,Mark[Cnt]=0,--Cnt;
			if(Cnt<0) return 0;
		}
		else {++tot;if(tot>m) return 0;}
	}
	if(Cnt) return 0;
	return 1;
}
inline void DFS(int x)
{
	if(x>_) {if(Check()) ++Ans;return;}
	S[P[x]]='(',DFS(x+1);
	S[P[x]]=')',DFS(x+1);
	S[P[x]]='*',DFS(x+1);
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>m>>S;
	for(register int i=0;i<n;++i) if(S[i]=='?') P[++_]=i;
	if(_>17) {cout<<"0";return 0;}
	DFS(1),cout<<Ans;
	return 0;
}

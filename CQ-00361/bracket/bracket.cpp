#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

const LL mod = 1e9 + 7;

string s;
int len,k;
vector<int> pos;
int t;
LL ans;
char c[4] = {' ','*','(',')'};

bool check(string a)
{
	int front;
	int count1;
	if(a[0] == '*' || a[a.length()-1] == '*')
	{
		return 0;
	}
	int last_left;
	for(int i = 0;i < a.length();i++)
	{
		if(a[i] == '(')
		{
			front--;
			last_left = i;
			count1 = 0;
		}
		if(a[i] == '*')
		{
			count1++;
			if(count1 > k)
			{
				return 0;
			}
		}
		if(a[i] == ')')
		{
			if(front == 0)
			{
				return 0;
			}
			if(last_left-1 >=0 && a[last_left-1]=='*'
			&& i<=a.length()-2 && a[i+1]=='*' && a[i-1]=='('
			){
				return 0;
			}
			else{
				front++;
				count1 = 0;
			}
		}
	}
	return (front == 0)?1:0;
}

void fun(int node)
{
	if(node == t)
	{
		if(check(s))
		{
			ans++;
			ans %= mod;
		}
		return ;
	}
	
	if(s[pos[node]] == '?')
	{
		for(int i = 1;i <= 3;i++)
		{
			s[pos[node]] = c[i];
			fun(node+1);
			s[pos[node]] = '?';
		}
	}
	else
	{
		fun(node+1);
	}
}

int cnt;

int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	
	scanf("%d %d",&len,&k);
	cin >> s;
	
	for(int i = 0;i<s.length();i++)
	{
		if(s[i] == '?')
		{
			t++;
			pos.push_back(i);
		}
	}
	fun(0);
	printf("%lld",ans);
	cin.get();
	cin.get();
	return 0;
}

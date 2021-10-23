#include<bits/stdc++.h>
using namespace std;
stack<int> choose;
int ans,cnt,n,k;
int nex[120001];
bool is_jim(string a)
{
	for(int i = 0;i < a.length();i++)
	{
		if(a[i]!='*')
		{
			return 0;
		}
	}
	return 1;
}
//bool more(string ou)
//{
//	
//	string fw;
//	for(int i = 1;i <= k;i++)
//	{
//		fw += '*';
//		if(ou == '('+fw+')')
//		{
//			return 1;
//		}
//	}
//	if(ou=="")
//	{
//		return 0;
//	}
//	if(ou[0]=='('&&ou[ou.length()-1]==')')
//	{
//		if(more(ou.substr(1,n-2)))
//		{
//			return 1;
//		}
//		else
//		{
//			for(int i = 1;i < ou.length();i++)
//			{
//				if(is_jim(ou.substr(1,i))&&more(ou.substr(i+1,ou.length()-2-i)))
//				{
//					return 1;
//				}
//			}
//		}
//	}
//	for(int k = 1;k < ou.length()-1;k++)
//	{
//		if(more(ou.substr(0,k))&&more(ou.substr(k,ou.length()-k)))
//		{
//			return 1;
//		}
//	}
//	for(int i = 1;i < ou.length()-1;i++)
//	{
//		for(int j = i+1;j < ou.length()-1;j++)
//		{
//			if(more(ou.substr(0,i))&&more(ou.substr(j,ou.length()-j)))
//			{
//				if(is_jim(ou.substr(i,j-i)))
//				{
//					return 1;
//				}
//			}
//		}
//	}
//}
bool check(string ou)
{
	if(ou[ou.length()-1]=='*')
	{
		return 0;
	}
	while(!choose.empty())
	{
		choose.pop();
	}
	int ans = 0;
	for(int i = 0;i < ou.length();i++)
	{
		if(ans > k)
		{
			return 0;
		}
		if(ou[i]=='*')
		{
			ans++;
		}
		if(ou[i]=='(')
		{
			ans = 0;
			choose.push(1);
		}
		else if(ou[i]==')')
		{
			if(choose.empty())
			{
				return 0;
			}
			ans = 0;
			choose.pop();
		}
	}
	if(!choose.empty())
	{
		return 0;
	}
	return 1;
}
void dfs(int num,string ou)
{
//	cout << nex[num] << ",";
	if(num == cnt+1)
	{
//		cout << ou << endl;
		if(check(ou))
		{
			cout << ou << endl;
//			cout << "YES" << endl;
			ans++;
		}
		return;
	}
	ou[nex[num]] = '(';
	dfs(num+1,ou);
	ou[nex[num]] = ')';
	dfs(num+1,ou);
	ou[nex[num]] = '*';
	dfs(num+1,ou);
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin >> n >> k;
	string eg;
	cin >> eg;
	for(int i = 0;i < n;i++)
	{
		if(eg[i] == '?')
		{
			nex[++cnt] = i;
		}
	}
	dfs(1,eg);
	cout << ans;
	return 0;
}

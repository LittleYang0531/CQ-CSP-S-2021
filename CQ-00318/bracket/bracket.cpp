#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;
int n,k,len,ans1,ans3;
string s,ans,ans2;

int get_ch(char ch)
{
	if(ch == '(') return 1;
	else if(ch == ')') return 2;
	else return 3;
}

void dfs(int now,int zhiqian,int cnt,char ch)
{
	if(now > n || n - now < zhiqian || cnt > k || zhiqian < 0) return ;
	if(now == n && zhiqian == 0 && ch == ')') 
	{
//		for(int i = 1;i <= len;i++) printf("%c",ans2[i]);
//		puts("");
//		printf("!");
		ans3++;
	}
	if(s[now] != '?' && (now != 0))
	{
		if(ch != s[now]) return ;
	} 
	if(ch == '(') zhiqian++;
	len++;
	ans2[len] = '(';
//	printf("!");
	dfs(now + 1,zhiqian,0,'(');
	int flag = 0;
//	if(ans2[4]=='('&&ans2[5]=='*' &&ans2[6]==')') printf("%d %d %d\n",zhiqian,len,f[6][0][2][2]);
	ans2[len] = ')';
	flag = ans[zhiqian],ans[zhiqian] = 0;
	dfs(now + 1,zhiqian - 1,0,')');
	if(flag) ans[zhiqian] = flag;
	if((!ans[zhiqian] || (ch == '*'))) 
	{
		int fff = 0;
		if(ch != '*') ans[zhiqian]++,fff = 1;
		ans2[len] = '*';
		dfs(now + 1,zhiqian,cnt + 1,'*');
		if(fff) ans[zhiqian]--;
	}
	len--;
}

int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d %d",&n,&k);
	cin >> s;
	for(int i = s.length();i >= 1;i--) s[i] = s[i - 1];
	dfs(0,0,0,0);
	printf("%d",ans3);
	return 0;
}

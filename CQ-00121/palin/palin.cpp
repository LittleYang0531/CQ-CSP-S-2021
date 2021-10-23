#include<bits/stdc++.h>
using namespace std;
int head,tail;
int c[10001];
bool check(int b[],int n)
{
	for(int i = 1;i <= n;i++)
	{
		if(b[i]!=b[2*n-i+1])
		{
			return 0;
		}
	}
	return 1;
}
char ou2[10001];
void choose(int b[],char ou[],int n)
{
	for(int i = 1;i <= 2*n;i++)
	{
		if(b[i] > c[i])
		{
			memcpy(c,b,sizeof(b));
			memcpy(ou2,ou,sizeof(ou));
			return;
		}
	}
}
void dfs(int a[],int num,int b[],int n,char ou[])
{
	if(num == 2*n)
	{
		if(check(b,n))
		{
			choose(b,ou,n);
		}
		return;
	}
	b[num+1]=a[head];
	head++;
	ou[num+1] = 'L';
	dfs(a,num+1,b,n,ou);
	head--;
	b[num+1]=a[tail];
	tail--;
	ou[num+1] = 'R';
	dfs(a,num+1,b,n,ou);
	tail++;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		int a[10001];
		cin >> n;
		for(int i = 1;i <= 2*n;i++)
		{
			cin >> a[i];
		}
		head = 1;
		tail = 2*n;
		memset(c,0,sizeof(c));
		int b[10001];
		char ou[10001];
		dfs(a,0,b,n,ou);
		for(int i = 1;i <= 2*n;i++)
		{
			cout << ou2[i];
		} 
		cout << endl;
	}
	return 0;
}

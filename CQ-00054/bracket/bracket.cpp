#include<bits/stdc++.h>
using namespace std;
const int N=505,P=1e9+7;
char s[N];
int arr[N][N],len,n,K;
bool pre_dp[N][N];
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d %d %s",&n,&K,s+1);
	int len =n;
	for(int i=1;i<=len;i++)
		pre_dp[i][0] = true;
	for(int i=1;i<=len;i++)
	{
		if(s[i] == '*' || s[i] == '?')
			pre_dp[i][1] = true;
	}
	for(int k=2;k<=K;k++)//���� 
		for(int i=1;i + k - 1<=len;i++)
			pre_dp[i][k] = pre_dp[i][k-1] && pre_dp[i+k-1][1];
	for(int i=1;i<=n-1;i++)
		arr[i+1][i] = 1;//�մ� 
	for(int Length=2;Length<=len;Length++)
	{
		for(int l=1;l+Length-1<=len;l++)
		{
			int r = l + Length - 1;
			if(s[l] == '*' || s[r] == '*' || s[l] == ')' || s[r] == '(')	continue;
			if(pre_dp[l+1][r-1-l])
				arr[l][r] = 1;
			//�м�ֿ�
			for(int p=0;p<=r-l-1;p++)//���� 
			{
				for(int pos = l+2;pos+p-1<=r-2;pos++)
				{
					if(pre_dp[pos][p])
						arr[l][r] = (arr[l][r] + arr[l][pos-1] * arr[pos + p][r] % P) % P;
				}
			 } 
			//ȥ����
			for(int p=0;p<=K && p <= r-l-3;p++)
			{
				if(pre_dp[l+1][p] == false)	break;
				arr[l][r] = (arr[l][r] + arr[l+p+1][r-1]) % P;
			}
			for(int p=0;p<=K && p <= r-l-3;p++)
			{
				if(pre_dp[r-p][p] == false)	break;
				arr[l][r] = (arr[l][r] + arr[l+1][r-p-1]) % P;
			}
		}
	}
	cout<<arr[1][len]<<endl;
	return 0;
}
/*
	ʮ��OIһ���գ�ͼ��DP�߾���
	������迴�壬һ��������մ��
*/ 
//magic������ 

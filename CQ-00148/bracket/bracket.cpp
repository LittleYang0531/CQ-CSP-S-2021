/*
�Ǹ�gmon.out�Ǹ�ʲô������
Ϊʲôÿ�γ������������һ��

������һ�����������ſ�ƥ��ġ�
Ȼ�����ǿ�����
����ƥ��������м�û�б�����ţ��������м�ֻ����<=k��*��
�����������м俿һ���ַ�������*��
��
���ڸ���
��dp[i][j][k][l]��ʾ��ǰ�ַ���[i,j]���ҷֱ�Ϊk,lʱ�ĺϷ���������
������
�ò��ź�����ά�˰ɡ�
ֻ��k='(',l='('ʱ�ſ��ܺϷ���
Ȼ�����ǿ�ʼ������
1.ģ��������м�û�л�ȫ��*�����ǿ�����һ��������
2.��ģ���������ö���ı����ıߣ�Ȼ��ֱ��dp[i][j]+=dp[i][k]*dp[k+1][j]������ƥ������Ŷ���һ���������϶���һ����
3.��ģ��������ǿ�dp[i+1][j-1]�Ƿ���У�Ȼ��dp[i][j]+=dp[k][j-1],dp[i][j]+=dp[i+1][k]��k!=i+1,k!=j-1,��Ҫi+1~k-1/k+1~j-1ȫ������*����������ε�����ƥ��λ�ò�һ�����ǲ�һ���ķ����� 
���ǵõ���n^3������������ 
125000000����������̫���ܵù������ӡ� 
��û�취��
7 3
(*??*??

������ƴ������ʱ��©��һ��������������������м����һ��*���� 
��Ҫ�Ǳ�������ôƴ������ܲ����ˡ�
for(long long k=i;k<j;++k)
{
	long long bas=dp[i][k],ano=dp[k+1][j];
	for(long long l=k+2;l<=j&&l-k-1<=K;++l)
	{
		if(!canbestar(l-1))	break;
		ano+=dp[l][j];
	}
	dp[i][j]=(dp[i][j]+bas*ano)%mod;
}
�õı��������ء�

10 2
???(*??(?) 
��������û�ԡ� 
���������������˵����ӡ� 
()*()*()
()*()+*+()
()+*+()*()
�������Ρ��� 
dp[i][j][0/1]��ʾ[i,j]�Ƿ�Ϊi,jƥ��ĺϷ���������

�����ڶ��ˣ������Ż�һ�����n^4. 
Ŀ����Ҫ�ҵ�һ���ο���*�ġ���* ���ʻ���������~�� 

мм�㣬�����ˡ�
��Ҫ�����ǰɡ�

���Ƿ��򿨳����񣡣��� 
O2Ҳ�Ȳ����ҡ��� 

500���ʺ���3s���� 

������ѡ������CCF�Ļ��ӿ�O2=_= 
*/
#include<cstdio>
const long long mod=1e9+7;
long long n,K,dp[510][510][3],hb[510],tmp[510];
bool cbl[510],cbr[510],cbs[510];
char str[510];
bool canbeleft(long long x)
{
	return str[x]=='('||str[x]=='?';
}
bool canberight(long long x)
{
	return str[x]==')'||str[x]=='?';
}
bool canbestar(long long x)
{
	return str[x]=='*'||str[x]=='?';
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%lld %lld %s",&n,&K,str+1);
	hb[n+1]=n;
	for(long long i=n;i>=1;--i)
	{
		cbl[i]=canbeleft(i);
		cbr[i]=canberight(i);
		cbs[i]=canbestar(i);
		if(cbs[i])
		{
			if(hb[i+1]!=i)	hb[i]=hb[i+1];
			else	hb[i]=i;
		}
		else	hb[i]=i-1;
	}
	for(long long len=2;len<=n;++len)
	{
		for(long long i=1;i+len-1<=n;++i)
		{
			long long j=i+len-1;
			if(!cbl[i]||!cbr[j])	continue;
			bool flag=(i==j-1);
			if(!flag&&(len-2<=K))
			{
				flag=1;
				for(long long k=i+1;k<j;++k)
				{
					if(!cbs[k])
					{
						flag=0;
						break;
					}
				}
			}
			if(flag)	dp[i][j][1]=1;
			
			tmp[i]=0;
			for(long long k=i+1;k<=j;++k)	tmp[k]=(tmp[k-1]+dp[k][j][1])%mod;
			for(long long k=i;k<j;++k)
			{
				long long bas=dp[i][k][2];
				long long l=k+1,r=hb[k+1]+1;
				if(r>j)	r=j;
				if(r-k-1>K)	r=K+k+1;
				long long ano=(tmp[r]-tmp[l-1]+mod)%mod;
				dp[i][j][0]=(dp[i][j][0]+bas*ano)%mod;
			}
			
			dp[i][j][1]=(dp[i][j][1]+dp[i+1][j-1][2])%mod;
			for(long long k=i+2;k<j-1;++k)
			{
				if(k-i-1>K||!canbestar(k-1))	break;
				dp[i][j][1]=(dp[i][j][1]+dp[k][j-1][2])%mod;
			}
			for(long long k=j-2;k>i+1;--k)
			{
				if(j-1-k>K||!canbestar(k+1))	break;
				dp[i][j][1]=(dp[i][j][1]+dp[i+1][k][2])%mod;
			}
			dp[i][j][2]=(dp[i][j][1]+dp[i][j][0])%mod; 
		}
	}
	printf("%lld\n",dp[1][n][2]);
	return 0;
}
